#include <bits/stdc++.h>
using namespace std;

int t; string s;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--){
    cin >> s;
    int cnt = 0, ans = 0;
    for(char a : s) {
      if(a == 'O'){
        cnt++;
        ans += cnt;
      } else cnt = 0;
    }
    cout << ans << '\n';
  }
}