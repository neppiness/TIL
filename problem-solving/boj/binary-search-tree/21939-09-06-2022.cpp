#include <bits/stdc++.h>
using namespace std;

int n, m;
multiset<int> diff;
set<int> difftono[102];
int notodiff[100'002];

void add() {
  int no, d;
  cin >> no >> d;
  difftono[d].insert(no);
  diff.insert(d);
  notodiff[no] = d;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) add();

  cin >> m;
  for(int i = 0; i < m; i++) {
    string cmd; cin >> cmd;
    if(cmd == "recommend") {
      int x; cin >> x;
      if(x == 1) {
        auto it1 = prev(diff.end());
        auto it2 = prev(difftono[*it1].end());
        cout << *it2 << '\n';
      } else {
        auto it1 = diff.begin();
        auto it2 = difftono[*it1].begin();
        cout << *it2 << '\n';
      }
    } else if(cmd == "solved") {
      int no; cin >> no;
      int d = notodiff[no];
      auto it = diff.lower_bound(d);
      diff.erase(it);
      difftono[d].erase(no);
    } else add();
  }
}