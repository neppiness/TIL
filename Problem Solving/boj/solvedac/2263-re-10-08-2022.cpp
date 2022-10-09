#include <bits/stdc++.h>
using namespace std;

const int MX = 100'002;

int n;
int in[MX], po[MX]; // 1-indexed
int inidx[MX];

void solve(int st, int en) {
  int par = po[en - 1];
  int idx = inidx[par];
  cout << par << ' ' << idx;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> in[i];
    inidx[in[i]] = i; // input: node no. return: index value
  }
  for(int i = 1; i <= n; i++)
    cin >> po[i];

  solve(1, n);
}

/*
test cases
3
1 2 3
1 3 2

7
3 2 1 5 4 6 7
3 2 5 7 6 4 1
*/