#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<int> a;

bool solve(int lim) {
  int sum = 0, cnt = 1;
  for(int i = 0; i < n; i++) {
    if(a[i] > lim) return 0;
    if(sum + a[i] > lim) { sum = 0; cnt++; }
    sum += a[i];
  }
  return cnt <= m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  a.resize(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];

  int st = 1, en = 1e+9;
  while(st < en) {
    int mid = (st + en)/2;
    if(solve(mid)) en = mid;
    else st = mid + 1;
  }
  cout << st;
}