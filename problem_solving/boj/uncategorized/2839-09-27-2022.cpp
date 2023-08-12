#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);

  int n; cin >> n;
  int no = n / 5;
  int ans = 0x3f3f3f3f;

  for(int i = 0; i <= 1000; i++) {
    for(int j = 0; j <= 5000 / 3; j++) {
      int a = i*5 + j*3;
      if(a == n) ans = min(ans, i + j);
    }
  }
  if(ans == 0x3f3f3f3f) ans = -1;
  cout << ans;
}