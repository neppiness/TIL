#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  int h, w, n;
  int fl, no;
  string ans, nostr;
  while(t--){
    cin >> h >> w >> n;
    fl = (n - 1) % h + 1; no = (n - 1) / h + 1;
    
    nostr = to_string(no);
    if(nostr.size() == 1) nostr = '0' + nostr;

    ans = to_string(fl) + nostr;
    cout << ans << '\n';
  }
}