#include <bits/stdc++.h>
using namespace std;

const int MX = 2'000;

int s;
queue<pair<int, int>> q; // q = {emocnt, clipboard}
int t[MX + 2][MX + 2]; // t: time, t[emocnt][clipboard]

int solve() {
  t[1][0] = 0;
  q.push({1, 0});

  while(!q.empty()) {
    auto [cnt, clip] = q.front(); q.pop();
    int cur_t = t[cnt][clip];
    // 1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장
    if(cnt <= MX && t[cnt][cnt] == -1) {
      t[cnt][cnt] = cur_t + 1;
      q.push({cnt, cnt});
    }
    // 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기
    int ncnt = cnt + clip;
    if(ncnt <= MX) {
      if(ncnt == s) return cur_t + 1;
      if(t[ncnt][clip] != -1) {
        t[ncnt][clip] = cur_t + 1;
        q.push({ncnt, clip});
      }
    }
    // 3. 화면에 있는 이모티콘 하나 삭제
    if(cnt >= 1) {
      if(cnt - 1 == s) return cur_t + 1;
      if(t[cnt - 1][clip] != -1) {
        t[cnt - 1][clip] = cur_t + 1;
        q.push({cnt - 1, clip});
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