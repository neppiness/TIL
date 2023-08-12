#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 7'500'000;

vector<int> pr;
bool ispr[MX];

void prset() {
  fill(ispr, ispr + MX, 1);
  for(ll p = 2; p < MX; p++) {
    if(!ispr[p]) continue;
    pr.push_back(p);
    for(ll m = p; m * p < MX; m++)
      ispr[m * p] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k; cin >> k;
  prset();
  cout << pr[k - 1];
}