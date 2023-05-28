#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<pair<int, int>> pq, npq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int d, m; cin >> d >> m;
    pq.push({d, m});
  }
  
  int tot = 0, day = 10000;
  while (!pq.empty()) {
    auto [due, mon] = pq.top(); pq.pop();
    if (due < day) npq.push({due, mon});
    while(due > day) day--;
    tot += mon; day--;
  }
  cout << tot;
}