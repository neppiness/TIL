#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'002;

int mx, n, a[MX];

void solve(int st, int curlen) {
  mx = max(mx, curlen);
  for(int i = st + 1; i < n; i++)
    if(a[st] < a[i]) solve(i, curlen + 1);
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  for(int i = 0; i < n; i++)
    solve(i, 1);

  cout << mx;
}