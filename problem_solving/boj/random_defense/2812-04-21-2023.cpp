#include <bits/stdc++.h>
using namespace std;

int n, k, cnt[10];
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> s;
  for(char c : s) cnt[c - '0']++;
  for(int i = 0; i < 10; i++) {
    cnt[i] = min(k, cnt[i]);
    k -= cnt[i];
  }

  for(int i = 0; i < 10; i++)
    cout << cnt[i] << ' ';
  cout << '\n';

  for(char c : s) {
    if(cnt[c - '0']) {
      cnt[c - '0']--;
      continue;
    }
    cout << c;
  }
}