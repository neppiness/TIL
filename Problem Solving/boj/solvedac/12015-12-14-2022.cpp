#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'002;

vector<int> a;
int mx;

void pick(int idx, int len) {
  mx = max(mx, len);
  for(int i = idx + 1; i < a.size(); i++)
    if(a[idx] < a[i]) pick(i, len + 1);
}

void solve() {
  for(int i = 0; i < a.size(); i++)
    pick(i, 1); // idx가 i인 항을 첫 항으로 두고 고름
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while(n--) {
    int x; cin >> x;
    a.push_back(x);
  }
  solve();

  cout << mx;
}