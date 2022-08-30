// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/ee3fe4e19404458aad9183caf81e8306
#include <bits/stdc++.h>
using namespace std;

int n, c;
int x[200002];

bool solve(int len){
  for(int idx = 0; idx <= n - c; idx++) {
    int cnt = 0;
    while(idx != n) {
      idx = lower_bound(x + idx, x + n, x[idx] + len) - x;
      cnt++;
    }
    if(cnt >= c) return true;
  }
  return false;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> c;
  for(int i = 0; i < n; i++) cin >> x[i];
  sort(x, x + n);

  int st = 1, en = 1111111111;
  int mid;
  while(st < en) {
    mid = (st + en + 1)/2;
    if(solve(mid)) st = mid;
    else en = mid - 1;
  }
  cout << st;
}