#include <bits/stdc++.h>
using namespace std;

bool hs[1002];

void chk(int x) {
  int tmp = x;
  vector<int> dig; 
  while(tmp != 0) {
    dig.push_back(tmp % 10);
    tmp /= 10;
  }
  int d = dig[1] - dig[0];
  for(int i = 1; i < dig.size(); i++)
    if(d != dig[i] - dig[i - 1]) return;
  hs[x] = 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cnt = 0;

  for(int i = 1; i <= 1000; i++) chk(i);

  int n; cin >> n;
  for(int i = 1; i <= n; i++) cnt += hs[i];
  cout << cnt;
}