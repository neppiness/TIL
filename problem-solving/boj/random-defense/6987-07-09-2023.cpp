#include <bits/stdc++.h>
using namespace std;

const int SRC = 24, SINK = 25;

int prv[28], drawcnt, wincnt, losecnt;
int cap[28][28], flow[28][28];
vector<int> adj[28];

void init() {
  for (int i = 0; i < 6; i++) {
    int win_node_i = i * 4;
    int lose_node_i = i * 4 + 1;
    int draw_node_i1 = i * 4 + 2;
    int draw_node_i2 = i * 4 + 3;

    // now를 입력 받고 설정해야 하는 값.
    adj[SRC].push_back(win_node_i);
    adj[win_node_i].push_back(SRC);
    
    // nod를 입력 받고 설정해야 하는 값.
    adj[SRC].push_back(draw_node_i1);
    adj[draw_node_i1].push_back(SRC);

    // nol을 입력 받고 설정해야 하는 값.
    adj[lose_node_i].push_back(SINK);
    adj[SINK].push_back(lose_node_i);


    // nod를 입력 받고 설정해야 하는 값.
    adj[draw_node_i2].push_back(SINK);
    adj[SINK].push_back(draw_node_i2);

    for (int j = 0; j < 6; j++) {
      if (i == j) continue;
      int lose_node_j = j * 4 + 1;
      int draw_node_j2 = j * 4 + 3;

      adj[win_node_i].push_back(lose_node_j);
      cap[win_node_i][lose_node_j] = 1;
      adj[lose_node_j].push_back(win_node_i);

      adj[draw_node_i1].push_back(draw_node_j2);
      cap[draw_node_i1][draw_node_j2] = 1;
      adj[draw_node_j2].push_back(draw_node_i1);
    }
  }
}

void setup() {
  drawcnt = wincnt = losecnt = 0;
  memset(flow, 0, sizeof(flow));
  for (int i = 0; i < 6; i++) {
    int now, nod, nol; // no of wins, draws and loses 
    cin >> now >> nod >> nol;
    wincnt += now;
    drawcnt += nod;
    losecnt += nol;

    int win_node = i * 4;
    int lose_node = i * 4 + 1;
    int draw_node_1 = i * 4 + 2;
    int draw_node_2 = i * 4 + 3;

    cap[SRC][win_node] = now;
    cap[lose_node][SINK] = nol;

    cap[SRC][draw_node_1] = nod;
    cap[draw_node_2][SINK] = nod;
  }
}

bool solve() {
  int tot = 0;
  while (1) {
    memset(prv, -1, sizeof(prv));
    queue<int> q;
    q.push(SRC);
    while (!q.empty() && prv[SINK] == -1) {
      int cur = q.front(); q.pop();
      for (int nxt : adj[cur]) {
        if (prv[nxt] != -1) continue;
        if (cap[cur][nxt] - flow[cur][nxt] <= 0) continue;
        prv[nxt] = cur;
        q.push(nxt);
      }
    }
    if (prv[SINK] == -1) break;
    int df = 0x7f7f7f7f;
    for (int cur = SINK; cur != SRC; cur = prv[cur])
      df = min(df, cap[prv[cur]][cur] - flow[prv[cur]][cur]);
    for (int cur = SINK; cur != SRC; cur = prv[cur]) {
      flow[prv[cur]][cur] += df;
      flow[cur][prv[cur]] -= df;
    }
    tot += df;
  }
  for (int i = 0; i < 6; i++) {
    int win_node = i * 4;
    int lose_node = i * 4 + 1;
    int draw_node_1 = i * 4 + 2;
    int draw_node_2 = i * 4 + 3;
    if (cap[SRC][win_node] - flow[SRC][win_node]) return 0;
    if (cap[lose_node][SINK] - flow[lose_node][SINK]) return 0;
    if (cap[SRC][draw_node_1] - flow[SRC][draw_node_1]) return 0;
    if (cap[draw_node_2][SINK] - flow[SRC][draw_node_1]) return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  init();

  int t = 4;
  while (t--) {
    setup();
    cout << solve() << ' ';
  }
}