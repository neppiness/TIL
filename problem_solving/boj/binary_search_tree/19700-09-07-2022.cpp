#include <bits/stdc++.h>
using namespace std;

int n;

set<int> groups;
set<int> students[500'002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  while(n--) {
    int h, r;
    cin >> h >> r;

    groups.insert(r);
    students[r].insert(h);
  }

  int cnt = 0;
  while(!groups.empty())  {
    int sz = 0, MIN = 500'002;
    cnt++;
    set<int> delgr;

    for(auto r : groups) {
      while(sz < r) {
        if(students[r].empty()) {
          delgr.insert(r);
          break;
        }
        auto it = students[r].begin();
        if((*it) < MIN) {
          MIN = *it;
          students[r].erase(it);
          sz++;
        } else break;
      }
    }
    for(auto r : delgr) groups.erase(r);
  }
  cout << cnt;
}