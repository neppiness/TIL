#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int INF = 0x3f3f3f3f;
int v, e;
int d[20002];
vector<pair<int, int>> adj[20002];
priority_queue< pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>> > pq;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> v >> e;
  fill(d, d + v + 1, INF);

  int st; cin >> st;
  d[st] = 0;
  pq.push({0, st});

  int a, b, w;
  while(e--) {
    cin >> a >> b >> w;
    adj[a].push_back({w, b});
  }
  while(!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    if(cur.X != d[cur.Y]) continue;
    for(auto nxt : adj[cur.Y]) {
      int nxtd = d[cur.Y] + nxt.X;
      if(d[nxt.Y] > nxtd) {
        pq.push({nxtd, nxt.Y});
        d[nxt.Y] = nxtd;
      }
    }
  }
  for(int i = 1; i <= v; i++) {
    if(d[i] == INF) cout << "INF\n";
    else cout << d[i] << '\n';
  }
}