#include <bits/stdc++.h>
using namespace std;

const int LIM = 100'000;

int mn[1002];
queue<tuple<int, int, int>> q; // q = {dist, emo_cnt, clipboard}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  q.push({0, 0});
  mn[0] = 0;

  while(!q.empty()) {
    auto [d, cur, clip] = q.front(); q.pop();
    if(clip < LIM) {
      q.push({d + 1, cur, cur});
    }
    if(cur >= 1 && mn[cur - 1] != -1) {
      mn[cur - 1] = d + 1;
    }

  }

  cout << mn[s];
}