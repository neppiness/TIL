#include <bits/stdc++.h>
using namespace std;

int cnt[26];
string a, b;

string solve() {
  fill(cnt, cnt + 26, 0);
  cin >> a >> b;
  for(char c : a) cnt[c - 'a']++;
  for(char c : b) cnt[c - 'a']--;
  for(int i = 0; i < 26; i++)
    if(cnt[i] != 0) return "Impossible";
  return "Possible";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while(n--) cout << solve() << '\n';
}