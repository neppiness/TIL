#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000'002;
const int INF = 0x7f7f7f7f;

vector<int> mem, co; // memory and cost of apps
vector<int> mem_to_chk;

int cost[MX]; // cost indexed by obtained memory 
int n, req;

void solve(int lv) { // (lv + 1)번째 앱에 대해 냅색 알고리즘으로 확인하는 함수
  if(lv == n) return;

  int ilim = mem_to_chk.size();
  for(int i = 0; i < ilim; i++) {
    int &m = mem_to_chk[i];
    int nxtm = m + mem[lv];
    int nxtc = cost[m] + co[lv];
    if(nxtm >= req) {
      cost[req] = min(cost[req], nxtc);
      continue;
    }
    if(cost[nxtm] == INF)
      mem_to_chk.push_back(nxtm);
    cost[nxtm] = min(cost[nxtm], nxtc);
  }
  sort(mem_to_chk.rbegin(), mem_to_chk.rend());
  solve(lv + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(cost, cost + MX, INF);

  cin >> n >> req;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    mem.push_back(x);
  }
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    co.push_back(x);
  }

  cost[0] = 0;
  mem_to_chk.push_back(0);

  solve(0);
  cout << cost[req];
}