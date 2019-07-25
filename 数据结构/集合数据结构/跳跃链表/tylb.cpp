#include <bits/stdc++.h>
using namespace std;
const int N = 100001, SIZE = 30;
int top, pos, key[N * SIZE], s[N * SIZE], Head[SIZE], Next[N * SIZE], Link[N * SIZE];
int Q, opt, x;
int Rand() {
    for (int i = 1; ; i++)
        if (rand() % 2)
            return i;
}
void Insert(int x) {
    int tmp = Rand();
    for (int i = top + 1; i <= tmp; i++) {
        Head[i] = ++pos;
        Link[pos] = Head[i - 1];
        key[pos] = INT_MIN;
    }
    top = max(top, tmp);
    int node[SIZE], rank[SIZE];
    rank[top] = 0;
    for (int i = top, p = Head[top]; i; i--) {
        for (; Next[p] > 0 && key[Next[p]] < x; p = Next[p])
            rank[i] += s[p];
        node[i] = p;
        rank[i - 1] = rank[i];
        p = Link[p];
    }
    for (int i = 1; i <= top; i++)
        if (i <= tmp) {
            key[++pos] = x;
            Next[pos] = Next[node[i]];
            if (i > 1)
                Link[pos] = pos - 1;
            s[pos] = Next[pos] ? s[node[i]] + rank[i] - rank[1] : 0;
            Next[node[i]] = pos;
            s[node[i]] = rank[1] - rank[i] + 1;
        } else
            s[node[i]]++;
}
void Delete(int x) {
    int node[SIZE], rank[SIZE];
    rank[top] = 0;
    for (int i = top, p = Head[top]; i; i--) {
        for (; Next[p] > 0 && key[Next[p]] < x; p = Next[p])
            rank[i] += s[p];
        node[i] = p;
        rank[i - 1] = rank[i];
        p = Link[p];
    }
    for (int i = 1; i <= top; i++)
        if (Next[node[i]] > 0 && key[Next[node[i]]] == x) {
            s[node[i]] += s[Next[node[i]]] - 1;
            Next[node[i]] = Next[Next[node[i]]];
        } else
            s[node[i]]--;
}
int Rank(int p, int x) {
    int ans = 0;
    for (; Next[p] > 0 && key[Next[p]] < x; p = Next[p])
        ans += s[p];
    return ans + (Link[p] ? Rank(Link[p], x) : 1);
}
int Select(int p, int x) {
    for (; Next[p] > 0 && s[p] < x; p = Next[p])
        x -= s[p];
    return Link[p] ? Select(Link[p], x) : key[Next[p]];
}
int Pred(int p, int x) {
    for (; Next[p] > 0 && key[Next[p]] < x; p = Next[p]);
    return Link[p] ? Pred(Link[p], x) : key[p];
}
int Succ(int p, int x) {
    for (; Next[p] > 0 && key[Next[p]] <= x; p = Next[p]);
    return Link[p] ? Succ(Link[p], x) : key[Next[p]];
}
int main() {
    srand(time(NULL));
    return 0;
}
