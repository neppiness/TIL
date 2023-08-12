#include <bits/stdc++.h>
using namespace std;

bool x[22];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m; cin >> m;
  while(m--) {
    string cmd; int a;
    cin >> cmd;
    if(cmd == "add") {
      cin >> a;
      x[a] = 1;
    } else if(cmd == "check") {
      cin >> a;
      cout << x[a] << '\n';
    } else if(cmd == "remove") {
      cin >> a;
      x[a] = 0;
    } else if(cmd == "all") {
      for(int i = 1; i <= 20; i++)
        x[i] = 1;
    } else if(cmd == "toggle") {
      cin >> a;
      x[a] = !x[a];
    } else {
      for(int i = 1; i <= 20; i++)
        x[i] = 0;
    }
  }
}