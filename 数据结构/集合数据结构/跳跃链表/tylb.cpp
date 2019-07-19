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
        key[pos] = INT_MIN;
        Link[pos] = Head[i - 1];
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
            s[pos] = rank[1] - rank[node[i]] - s[node[i]];
            Next[node[i]] = pos;
            s[node[i]] = rank[1] - rank[node[i]] + 1;
        } else
            s[node[i]]++;
}
void Delete(int x) {
    int node[SIZE], rank[SIZE];
    rank[top] = 0;
    for (int i = top, p = Head[top]; i; i--) {
        for (; key[Next[p]] < x; p = Next[p]);
        node[i] = p;
        rank[i - 1] = rank[i];
        p = Link[p];
    }
    for (int i = 1; i <= top; i++)
        if (key[Next[node[i]]] == x) {
            Next[node[i]] = Next[Next[node[i]]];
            s[node[i]] -= s[Next[node[i]]];
        } else
            s[node[i]]--;
}
int Rank(int p, int x) {
    int ans = 0;
    for (; key[Next[p]] < x; p = Next[p])
        ans += s[p];
    return ans + (Link[p] ? Rank(Link[p], x) : 1);
}
int Select(int p, int x) {
    for (; s[p] < x; p = Next[p])
        x -= s[p];
    return Link[p] ? Select(Link[p], x) : key[Next[p]];
}
int Pred(int p, int x) {
    for (; key[Next[p]] < x; p = Next[p]);
    return Link[p] ? Pred(Link[p], x) : key[p];
}
int Succ(int p, int x) {
    for (; key[Next[p]] <= x; p = Next[p]);
    return Link[p] ? Succ(Link[p], x) : key[Next[p]];
}
int main() {
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d", &opt, &x);
        if (opt == 1)
            Insert(x);
        else if (opt == 2)
            Delete(x);
        else if (opt == 3)
            printf("%d\n", Rank(Head[top], x));
        else if (opt == 4)
            printf("%d\n", Select(Head[top], x));
        else if (opt == 5)
            printf("%d\n", Pred(Head[top], x));
        else
            printf("%d\n", Succ(Head[top], x));
    }
    return 0;
}
