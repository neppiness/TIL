#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--) {
    cin >> n;
    multiset<int> ms;
    while(n--) {
      char cmd;
      int x;
      cin >> cmd >> x;
      if(cmd == 'I') ms.insert(x);
      else {
        if(ms.empty()) continue;
        else if(x == -1) ms.erase(ms.begin());
        else ms.erase(prev(ms.end()));
      }
    }
    if(ms.empty()) cout << "EMPTY\n";
    else cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
  }
}