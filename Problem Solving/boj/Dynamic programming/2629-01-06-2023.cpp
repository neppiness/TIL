#include <bits/stdc++.h>
using namespace std;

const int MX = 55'002;
const int CF = 15'000; // correction factor to indicate array
const int MXNW = 32; // Maximum number of weights

bool ispossible[MXNW][MX];
int n, w[MXNW];

void solve() {
  // initialize
  int val[] = {-w[0], w[0], 0};
  for(int i = 0; i < 3; i++) {
    int idx = val[i] + CF;
    ispossible[0][idx] = 1;
  }
  // calc.
  for(int i = 1; i < n; i++) {
    val[0] = -w[i];
    val[1] = w[i];
    for(int j = 0; j < MX; j++) {
      if(!ispossible[i - 1][j]) continue;
      for(int k = 0; k < 3; k++) {
        int idx = j + val[k];
        ispossible[i][idx] = 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> w[i];
  
  solve();

  int t; cin >> t;
  while(t--) {
    int x; cin >> x;
    if(ispossible[n - 1][x + CF]) cout << "Y ";
    else cout << "N ";
  }
}