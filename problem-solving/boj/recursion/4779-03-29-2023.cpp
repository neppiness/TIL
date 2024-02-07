#include <bits/stdc++.h>
using namespace std;

string str;

void solve(int st, int en) {
  if(st + 1 == en) return;
  int d = (en - st) / 3;
  for(int i = st + d; i < st + 2*d; i++)
    str[i] = ' ';
  solve(st, st + d);
  solve(st + 2*d, en);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while(cin >> n) {
    int x = 1;
    while(n--) x *= 3;

    str = string(x, '-');
    solve(0, x);
    cout << str << '\n';
  }
}