#include <bits/stdc++.h>
using namespace std;

const int kMax = 5e5 + 2;

int n, m, st, p;
vector<int> en;
int mon[kMax], m_sum[kMax], tot_mon[kMax];
vector<int> adj[kMax], scc_adj[kMax];

int visno, grno;
int seq[kMax], gr[kMax];
bool is_done[kMax];
stack<int> stk;
priority_queue< pair<int, int> > pq;

void setup() {
  cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) 
    cin >> mon[i];
  
  cin >> st >> p;
  while (p--) {
    int e; cin >> e;
    en.push_back(e);
  }
}

int scc(int cur) {
  seq[cur] = ++visno;
  stk.push(cur);

  int ret = seq[cur];
  for (int nxt : adj[cur]) {
    if (seq[nxt] == 0) ret = min(ret, scc(nxt));
    else if (!is_done[nxt]) ret = min(ret, seq[nxt]);
  }

  if (ret == seq[cur]) {
    grno++;
    while (1) {
      int tp = stk.top(); stk.pop();
      is_done[tp] = 1;
      gr[tp] = grno;
      if (tp == cur) break;
    }
  }
  return ret;
}

void scc() {
  for (int i = 1; i <= n; i++)
    if (seq[i] == 0) scc(i);
}

void sum() {
  for (int i = 1; i <= n; i++)
    m_sum[gr[i]] += mon[i];
}

void genDAG() {
  for (int cur = 1; cur <= n; cur++) {
    for (int nxt : adj[cur]) {
      if (gr[nxt] == gr[cur]) continue;
      scc_adj[gr[cur]].push_back(gr[nxt]);
    }
  }
}

void calc() {
  int stgr = gr[st];
  tot_mon[stgr] = m_sum[stgr];
  pq.push({m_sum[stgr], stgr});
  while (!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if (tot_mon[cur] != co) continue;
    for (int nxt : scc_adj[cur]) {
      int dco = co + m_sum[nxt];
      if (dco <= tot_mon[nxt]) continue;
      tot_mon[nxt] = dco;
      pq.push({dco, nxt});
    }
  }
}

void check() {
  int ans = 0;
  for (int e : en) {
    int engr = gr[e];
    ans = max(ans, tot_mon[engr]);
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup();
  scc();
  sum();
  genDAG();
  calc();
  check();
}