#include <bits/stdc++.h>
using namespace std;

const int MX = 500;

int ind[MX + 2], cost[MX + 2], tot[MX + 2];
vector<int> adj[MX + 2];

priority_queue< pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>> > pq; // pq = {cost, id}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 셋업
  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> cost[i];
    int pr; cin >> pr;
    while(pr != -1) {
      ind[i]++;
      adj[pr].push_back(i);
      cin >> pr;
    }
  }
  
  // indegree가 없는 노드로 시작
  for(int i = 1; i <= n; i++) {
    if(ind[i]) continue;
    tot[i] = cost[i];
    pq.push({cost[i], i});
  }

  while(!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    for(int nxt : adj[cur]) {
      ind[nxt]--;
      if(ind[nxt] != 0) continue;
      int dco = co + cost[nxt];
      tot[nxt] = dco;
      pq.push({dco, nxt});
    }
  }

  // 정답 출력
  for(int i = 1; i <= n; i++)
    cout << tot[i] << '\n';
}