#include <bits/stdc++.h>
using namespace std;

const int MX = 55'002;
const int CF = 15'000; // correction factor to indicate array

bool ispossible[MX];
int n, weight[32];

void trav(int tot, int idx) {
  if(idx == n) return;
  
  int val[] = {tot, tot + weight[idx],
      tot - weight[idx], - tot + weight[idx],
      - tot - weight[idx]};

  for(int i = 0; i < 5; i++) {
    ispossible[val[i] + CF] = 1;
    trav(val[i], idx + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> weight[i];
    ispossible[weight[i] + CF] = 1;
  }
  
  trav(0, 0);

  int t; cin >> t;
  while(t--) {
    int x; cin >> x;
    if(ispossible[x + CF]) cout << "Y ";
    else cout << "N ";
  }
}