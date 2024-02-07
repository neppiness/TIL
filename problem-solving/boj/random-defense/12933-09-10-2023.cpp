#include <bits/stdc++.h>
using namespace std;

int mx = 0;
string s;
int ducks[2502];

int ctoi(char c) {
  switch (c) {
    case 'q': return 1;
    case 'u': return 2;
    case 'a': return 3;
    case 'c': return 4;
    default : return 5;
  }
}

bool solve() {
  for (char c : s) {
    int q = ctoi(c);
    bool is_set = 0;
    for (int i = 0; i < mx; i++) {
      if (ducks[i] != q - 1) continue;
      if (q == 5) q = 0;
      ducks[i] = q;
      is_set = 1;
      break;
    }
    if (is_set) continue;
    if (q != 1) return 0;
    ducks[mx++] = 1;
  }
  for (int i = 0; i < mx; i++)
    if (ducks[i] != 0) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  if (solve()) cout << mx;
  else cout << -1;
}
