#include <bits/stdc++.h>
using namespace std;

set<int> gms;

void genGMS(int to_pick, int tot) {
  if (!to_pick) {
    gms.insert(tot);
    return;
  }
  for (int no : {4, 7})
    genGMS(to_pick - 1, tot*10 + no);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 9; i++)
    genGMS(i, 0);
  
  int a, b; cin >> a >> b;
  int cnt = 0;
  for (auto it = gms.begin(); it != gms.end(); it++)
    if (*it >= a && *it <= b) cnt++;
  cout << cnt;
}