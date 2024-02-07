#include <bits/stdc++.h>
using namespace std;

const int kInf = 0x7f7f7f7f;
const int st = 0, en = 25;

int cap[60][60], flow[60][60];
int prv[60];

vector<int> adj[60];
queue<int> q;

// 대문자: 0부터 25, 소문자: 26부터 51
int ctoi(char c) {
  if (c >= 'a' && c <= 'z') return c - 'a' + 26;
  return c - 'A';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    char a, b; cin >> a >> b;
    int u = ctoi(a), v = ctoi(b);
    int c; cin >> c;
    cap[u][v] += c; cap[v][u] += c;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = 0;
  while (1) {
    q = queue<int>();
    memset(prv, -1, sizeof(prv));
    prv[st] = -2; q.push(st);
    while (!q.empty() && prv[en] == -1) {
      int cur = q.front(); q.pop();
      for (int nxt : adj[cur]) {
        if (prv[nxt] != -1) continue;
        if (cap[cur][nxt] - flow[cur][nxt] <= 0) continue;
        prv[nxt] = cur; q.push(nxt);
      }
    }
    if (prv[en] == -1) break;
    int df = kInf;
    for (int cur = en; cur != st; cur = prv[cur])
      df = min(cap[prv[cur]][cur] - flow[prv[cur]][cur], df);
    for (int cur = en; cur != st; cur = prv[cur]) {
      flow[prv[cur]][cur] += df;
      flow[cur][prv[cur]] -= df;
    }
    ans += df;
  }
  cout << ans;
}