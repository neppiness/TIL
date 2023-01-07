#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 1'000'000;

vector<int> pr;
bool ispr[MX + 2];

void prset() {
  fill(ispr, ispr + MX + 2, 1);
  for(ll i = 2; i <= MX; i++) {
    if(!ispr[i]) continue;
    pr.push_back(i);
    for(ll j = i; i * j <= MX; j++)
      ispr[i * j] = 0;
  }
}

int solve(int x) {
  int cnt = 0;
  for(int p : pr) {
    if(p > x / 2) break;
    if(ispr[x - p]) cnt++;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  prset();

  int t; cin >> t;
  while(t--) {
    int x; cin >> x;
    cout << solve(x) << '\n';
  }
}