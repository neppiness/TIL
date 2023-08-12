#include <bits/stdc++.h>
using namespace std;

const int MX = 2'000;
const int INF = 0x7f7f7f7f;
int s;
queue<pair<int, int>> q; // q = {emocnt, clipboard}
int t[MX + 2][MX + 2]; // t: time, t[emocnt][clipboard]

int solve() {
  t[1][0] = 0;
  q.push({1, 0});

  while(!q.empty()) {
    auto [cur_emo, cur_cl] = q.front(); q.pop();
    int cur_t = t[cur_emo][cur_cl];
    if(cur_emo == s) return cur_t;

    int nxt_emo = cur_emo + cur_cl;
    int nxt_cl = cur_emo;

    // case i.delete an emoticon
    if(cur_emo >= 1) {
      if(t[cur_emo - 1][cur_cl] == -1) {
        t[cur_emo - 1][cur_cl] = cur_t + 1;
        q.push({cur_emo - 1, cur_cl});
      }
    }
    // case ii.copy from clipboard
    if(nxt_emo < MX) {
      if(t[nxt_emo][cur_cl] == -1) {
        t[nxt_emo][cur_cl] = cur_t + 1;
        q.push({nxt_emo, cur_cl});
      }
    }
    // case iii. update clipboard
    if(nxt_cl < MX) {
      if(t[cur_emo][nxt_cl] == -1) {
        t[cur_emo][nxt_cl] = cur_t + 1;
        q.push({cur_emo, nxt_cl});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(t, -1, sizeof(t));
  
  cin >> s;
  cout << solve();
}