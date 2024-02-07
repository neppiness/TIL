#include <bits/stdc++.h>
using namespace std;

stack<pair<int, char>> note;
int n, k; 
string ans = "";
int cnt[30];

bool solve() {
  int idx = 0;
  while (!note.empty()) {
    auto [x, c] = note.top(); note.pop();
    if (ans[idx] == '?') {
      ans[idx] = c;
      if (cnt[c - 'A'] != 0) {
        return 0;
      }
      cnt[c - 'A']++;
    } else if (ans[idx] != c) {
      return 0;
    }
    idx = (idx + x) % n;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  while (k--) {
    int x; char c;
    cin >> x >> c;
    note.push({x, c});
  }

  for (int i = 0; i < n; i++)
    ans += "?";

  if (solve()) {
    cout << ans;
  } else {
    cout << "!";
  }
}
