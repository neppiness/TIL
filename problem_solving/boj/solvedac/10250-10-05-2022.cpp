#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  int h, w, n;
  int a, b;
  string ans, pt;
  while(t--){
    cin >> h >> w >> n;
    a = (n - 1)%h + 1; b = (n - 1)/h + 1;
    
    pt = to_string(b);
    if(pt.size() == 1) pt = '0' + pt;

    ans = to_string(a) + pt;
    cout << ans << '\n';
  }
}