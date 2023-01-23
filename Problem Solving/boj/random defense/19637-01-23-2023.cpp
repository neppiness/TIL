#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;

string s[MX + 2];
int lim[MX + 2];

int n, m;

void solve() {
  int x; cin >> x;
  int st = 0, en = n - 1;
  while(st < en) {
    int mid = (st + en) / 2;
    if(x > lim[mid]) st = mid + 1;
    else en = mid;
  }
  cout << s[st] << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> s[i] >> lim[i];
  while(m--) solve();
}