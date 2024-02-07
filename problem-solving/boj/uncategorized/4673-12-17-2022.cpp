#include <bits/stdc++.h>
using namespace std;

bool sn[15000];

void cons(int x) {
  int d = x;
  while(x != 0) {
    d += x % 10;
    x /= 10;
  }
  sn[d] = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(sn, sn + 10002, 1);
  for(int i = 1; i <= 10000; i++) {
    cons(i);
    if(!sn[i]) continue;
    cout << i << '\n';
  }
}