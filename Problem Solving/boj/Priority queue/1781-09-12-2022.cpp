#include <bits/stdc++.h>
using namespace std;

int n;
int c, d;
priority_queue<int> pq[200002], pool;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> d >> c;
    pq[d].push(c);
  }

  int ans = 0;
  for(int i = n - 1; i >= 0; i--) {
    if(!pq[i].empty() || !pool.empty()) continue;
    while(!pq[i].empty()) {
      pool.push(pq[i].top());
      pq[i].pop();
    }
    ans += pool.top();
    pool.pop();
  }
  cout << ans;
}