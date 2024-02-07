#include <bits/stdc++.h>
using namespace std;

const int MMX = 200'000;
const int NLMX = 20;

int m;
int tab[MMX + 2][NLMX + 2];

int val(int x, int n) {
  int cur = x;
  for(int i = 0; i < NLMX; i++) {
    int chk = (1 << i);
    if(n & chk) cur = tab[cur][i];
  }
  return cur;
}

void setup() {
  for(int b = 1; b < NLMX; b++)
    for(int i = 1; i <= m; i++) {
      int prv = tab[i][b - 1];
      tab[i][b] = tab[prv][b - 1];
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m;
  for(int i = 1; i <= m; i++)
    cin >> tab[i][0];
  
  setup();

  int q; cin >> q;
  while(q--) {
    int n, x; cin >> n >> x;
    cout << val(x, n) << '\n';
  }
}