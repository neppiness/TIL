#include <bits/stdc++.h>
using namespace std;

set<int> att; // 1-indexed

int n, q;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    int a; cin >> a;
    if(a) att.insert(i);
  }

  int cur = 1;
  while(q--) {
    int a; cin >> a;
    if(a == 1) {
      int no; cin >> no;
      auto it = att.find(no);
      if(it == att.end()) att.insert(no);
      else att.erase(no);
    } else if(a == 2) {
      int no; cin >> no;
      cur = (cur - 1 + no)%n + 1;
    } else {
      if(att.empty()) cout << -1 << '\n';
      else {
        auto it = att.lower_bound(cur);
        if(it == att.end()) {
          auto it2 = att.lower_bound(0);
          cout << (n + *it2 - cur) << '\n';
        } else cout << (*it - cur) << '\n';
      }
    }
  }
}