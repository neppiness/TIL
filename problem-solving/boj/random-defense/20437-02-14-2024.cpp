#include <bits/stdc++.h>
using namespace std;

const int INF = 11'111;

int mn, mx;

bool solve() {
  bool is_solved = 0;
  int k; string s;
  cin >> s >> k;

  for (char c = 'a'; c <= 'z'; c++) {
    int cnt = 0;
    int en = 0;
    for (int st = 0; st < s.size(); st++) {
      while (en < s.size() && cnt < k) {
        cnt += (s[en] == c);
        en++;
      }
      if (cnt == k && s[st] == c && s[en - 1] == c) {
        mn = min(mn, en - st);
        mx = max(mx, en - st);
      }
      cnt -= (s[st] == c);
    }
  }
  return (mx != 0 && mn != INF);
}

void reset() {
  mx = 0;
  mn = INF;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    reset();
    if (solve()) {
      cout << mn << ' ' << mx << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}
