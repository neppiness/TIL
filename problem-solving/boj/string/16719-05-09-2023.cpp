#include <bits/stdc++.h>
using namespace std;

int no = 1;
string s;

int is_selected[102];

void solve(int cur) {
  for (char c = 'A'; c <= 'Z'; c++) {
    int idx = s.find(c, cur);
    if (idx == -1 || is_selected[idx]) continue;
    is_selected[idx] = no++;
    solve(idx + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  solve(0);

  for (int len = 1; len <= s.size(); len++) {
    for (int i = 0; i < s.size(); i++)
      if (is_selected[i] <= len) cout << s[i];
    cout << '\n';
  }

}