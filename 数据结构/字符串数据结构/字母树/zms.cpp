#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int pos, son[N][26], num[N];
void Insert(char s[]) {
    int p = 1, t;
    for (int i = 0; s[i]; i++) {
        t = s[i] - 97;
        if (!son[p][t])
            son[p][t] = ++pos;
        p = son[p][t];
    }
    num[p]++;
}
int Find(char s[]) {
    int p = 1, t;
    for (int i = 0; s[i]; i++) {
        t = s[i] - 97;
        if (!son[p][t])
            return 0;
        p = son[p][t];
    }
    return num[p];
}
int main() {
    pos = 1;
    return 0;
}
