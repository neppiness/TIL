#include <bits/stdc++.h>
using namespace std;

set<int> C[2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 3; i++) {
    int coord;
    for(int j = 0; j < 2; j++) {
      cin >> coord;
      auto idx = C[j].find(coord);
      if(idx == C[j].end()) C[j].insert(coord);
      else C[j].erase(coord);
    }
  }
  cout << *(C[0].begin()) << ' ' << *(C[1].begin());
}