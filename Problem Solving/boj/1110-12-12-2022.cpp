#include <bits/stdc++.h>
using namespace std;

int n, m;

bool issolved() {
  int ld = m % 10;
  int rd = (ld + m / 10) % 10;
  m = ld * 10 + rd;
  return (n == m);
}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  m = n;

  int cnt = 1;
  while(!issolved()) cnt++;
  cout << cnt;
}