#include <bits/stdc++.h>
using namespace std;

int h, m;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> h >> m;
  m -= 45;
  if(m < 0){h--; m += 60;}
  if(h < 0) h += 24;
  cout << h << ' ' << m;
}