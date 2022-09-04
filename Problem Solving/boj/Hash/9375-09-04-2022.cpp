#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    unordered_map<string, int> m;
    for(int i = 0; i < n; i++) {
      string item, ctgr;
      cin >> item >> ctgr;
      if(m.find(ctgr) != m.end()) m[ctgr]++;
      else m[ctgr] = 1;
    }

    int ans = 1;
    for(auto ctgr : m)
      ans *= (ctgr.second + 1);
    cout << ans - 1 << '\n';
  }
}