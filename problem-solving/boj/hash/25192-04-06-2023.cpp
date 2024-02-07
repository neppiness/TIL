#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> gg_emo;
int cnt, ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int n; cin >> n;
  while(n--) {
    cin >> s;
    if(s == "ENTER") { cnt++; continue; }
    if(gg_emo[s] == cnt) continue;
    gg_emo[s] = cnt;
    ans++; 
  }
  cout << ans;
}