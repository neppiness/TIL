#include <bits/stdc++.h>
using namespace std;

string full = "1 2 3 4 5 6 7 8 9";

int n, lim;
string s, eq;

int FindOp(int st) {
  int pos1 = eq.find('+', st);
  if (pos1 == -1) pos1 = lim;
  int pos2 = eq.find('-', st);
  if (pos2 == -1) pos2 = lim;
  return min(pos1, pos2);
}

bool is_zero() {
  stringstream ss(s);
  eq = "";

  string tmp;
  while (ss >> tmp) eq += tmp;
  lim = eq.size();

  vector<int> nos;
  vector<char> ops;
  int pos = 0;
  while (pos < lim) {
    int nxt = FindOp(pos);
    string no = eq.substr(pos, nxt - pos);
    nos.push_back(stoi(no));
    ops.push_back(eq[nxt]);
    pos = nxt + 1;
  }

  int tot = 0;
  for (int i = 1; i < nos.size(); i++) {
    int f = 1;
    if (ops[i - 1] == '-') f = -1;
    tot += f * nos[i];
  }
  tot += nos[0];
  return (tot == 0);
}

void solve(int lv) {
  if (lv == n - 1) {
    if (is_zero()) cout << s << '\n';
    return;
  }
  for (char c : {' ', '+', '-'}) {
    s[lv*2 + 1] = c;
    solve(lv + 1);
  }
}

void solve() {
  cin >> n;
  s = full.substr(0, 2*n - 1);
  solve(0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
    if (t) cout << '\n';
  }
}