#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 1'100'000;

int n;
bool is_pr[MX + 1];
vector<int> pr;

bool is_pal(int p) {
  vector<int> d;

  while(p) {
    d.push_back(p % 10);
    p /= 10;
  }

  auto i = d.begin();
  auto j = d.rbegin();
  while(i != d.end()) {
    if(*i != *j) return 0;
    i++; j++;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(is_pr, is_pr + MX + 1, 1);
  cin >> n;

  is_pr[0] = is_pr[1] = 0;
  for(int i = 2; i <= MX; i++) {
    if(!is_pr[i]) continue;
    pr.push_back(i);
    for(ll j = i; (ll)i * j <= MX; j++)
      is_pr[i * j] = 0;
  }

  for(int p : pr) {
    if(p < n || !is_pal(p)) continue;
    cout << p;
    return 0;
  }
}