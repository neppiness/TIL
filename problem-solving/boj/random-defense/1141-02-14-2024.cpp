#include <bits/stdc++.h>
using namespace std;

string s[52];
bool is_prefix[52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];

  sort(s, s + n);
  
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int pos = s[j].find(s[i]);
      if (pos == 0) is_prefix[i] = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += !is_prefix[i];
  cout << ans;
}
