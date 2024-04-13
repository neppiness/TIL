#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 0x7f7f7f7f;
vector<ll> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s; cin >> s >> s;
    ll no = 0;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'N') continue;
      ll bit = ((ll)1 << j);
      no |= bit;
    }
    v.push_back(no);
  }

  int mx_song = 0, mn_count = INF;
  // 모든 기타 조합 확인
  for (int i = 0; i < (1 << n); i++) {
    ll record = 0; // 비트마스킹 된 곡 목록
    int count = 0; // 필요한 기타 수

    // 조합을 확인하며 해당 기타가 선택되는 경운지 확인
    for (int j = 0; j < n; j++) {
      int bit = (1 << j);
      if ((i & bit) == 0) continue; // 사용하지 않는 기타로 칠 수 있는 곡은 record에 반영하지 않음
      record |= v[j];
      count++; // 사용하는 기타 수 증가
    }
    // record를 확인하여 연주할 수 있는 곡 개수 계산
    int song = 0;
    for (int j = 0; j < m; j++) {
      ll bit = ((ll)1 << j);
      song += ((bit & record) != 0);
    }
    // 정답 갱신 로직
    if (song == mx_song) {
      mn_count = min(mn_count, count);
    } else if (song > mx_song) {
      mx_song = song;
      mn_count = count;
    }
  }
  if (mx_song == 0) mn_count = -1;
  cout << mn_count;
}
