#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int pos, son[N][26], num[N];
void Insert(char s[]) {
    int t = 1, tmp;
    for (int i = 0; s[i]; i++) {
        tmp = s[i] - 97;
        if (!son[t][tmp])
            son[t][tmp] = ++pos;
        t = son[t][tmp];
    }
    num[t]++;
}
int Find(char s[]) {
    int t = 1, tmp;
    for (int i = 0; s[i]; i++) {
        tmp = s[i] - 97;
        if (!son[t][tmp])
            return 0;
        t = son[t][tmp];
    }
    return num[t];
}
int main() {
    pos = 1;
    return 0;
}
