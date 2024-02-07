#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> seq;
bool is_checked[1002];
int a[1002], ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    seq[s] = i;
  }

  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    a[i] = seq[s];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= 1; j--) {
      if (is_checked[j]) continue;
      if (a[i] > a[j]) continue;
      is_checked[j] = 1;
      ans++;
    }
  }
  cout << ans;
}