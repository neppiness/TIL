#include <bits/stdc++.h>
using namespace std;

string s; 

int solve(int st) {
  int idx = 0;
  while (idx < s.size()) {
    stack<int> stk;
    int tmp = st;
    while (tmp) {
      stk.push(tmp % 10);
      tmp /= 10;
    }
    if (idx + stk.size() > s.size()) return -1;
    while (!stk.empty()) {
      int cur = stk.top(); stk.pop();
      if (s[idx] - '0' != cur) return -1;
      idx++;
    }
    st++;
  }
  return st - 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  for (int st = 1; st <= 999; st++) {
    int en = solve(st);
    if (en == -1) continue;
    cout << st << ' ' << en;
    return 0;
  }
}
