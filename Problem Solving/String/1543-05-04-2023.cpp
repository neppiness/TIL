#include <bits/stdc++.h>
using namespace std;

string h, p;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  getline(cin, h);
  getline(cin, p);
  
  int idx = h.find(p);
  int cnt = 0;
  while(idx != -1) {
    cnt++;
    h.replace(idx, p.size(), "1");
    idx = h.find(p);
  }
  cout << cnt;
}