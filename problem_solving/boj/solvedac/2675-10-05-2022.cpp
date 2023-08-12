#include <bits/stdc++.h>
using namespace std;

int t;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r;
  string s, ans;
  cin >> t;
  while(t--){
    ans = "";
    cin >> r >> s;
    for(char c : s)
      for(int i = 0; i < r; i++)
        ans += c;
    cout << ans << '\n';
  }
}