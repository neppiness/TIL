#include <bits/stdc++.h>
using namespace std;

int cnt[28];
int n, ans;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> s;
  int en = 0, c = 0;
  for (int st = 0; st < s.size(); st++) {
    while (en < s.size() && c < n) {
      int cidx = s[en] - 'a';
      if (cnt[cidx]++ == 0) c++;
      en++;
    }
    ans = max(ans, en - st);
    int cidx = s[st] - 'a';
    if (--cnt[cidx] == 0) c--;
  }
  cout << ans;
}