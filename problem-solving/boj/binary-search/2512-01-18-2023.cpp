#include <bits/stdc++.h>
using namespace std;

int n, budget;
int a[100'002];

bool solve(int uplim) {
  int sum = 0;
  for(int i = 0; i < n; i++)
    sum += min(a[i], uplim);
  return budget >= sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int st = 1, en = 1;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    en = max(a[i], en);
  }
  cin >> budget;

  while(st < en) {
    int mid = (st + en) / 2 + 1;
    if(solve(mid)) st = mid;
    else en = mid - 1;
  }
  cout << st;
}