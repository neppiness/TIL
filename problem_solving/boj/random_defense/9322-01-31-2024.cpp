#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> pub_key_1;
int key_1_to_key_2[1002];
string ans[1002];

void solve() {
  pub_key_1.clear();
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    pub_key_1[s] = i;
  }
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    key_1_to_key_2[i] = pub_key_1[s];
  }
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    int idx = key_1_to_key_2[i];
    ans[idx] = s;
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}
