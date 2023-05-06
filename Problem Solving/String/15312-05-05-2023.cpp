#include <bits/stdc++.h>
using namespace std;

string s[2];
int p[4002][2];
int cnt[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2,
             2, 1, 2, 2, 1, 2, 2, 2, 1, 2,
             1, 1, 1, 2, 2, 1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s[0] >> s[1];

  int cur_idx = 0;
  int sz = s[0].size();
  for(int i = 0; i < sz; i++) {
    p[cur_idx++][0] = cnt[s[0][i] - 'A'];
    p[cur_idx++][0] = cnt[s[1][i] - 'A'];
  }

  int cycle = sz*2 - 2; // 사이클은 총 sz*2 - 2번 돌아야 배열 원소가 2개 남는다.
  int len = sz*2; // 현재 배열 길이를 기록.
  int cur = 0, nxt = 1;
  while(cycle--) {
    len--; // 연산 한 번 할 때마다 갱신할 총 길이가 줄어듦.
    for(int i = 0; i < len; i++)
      p[i][nxt] = (p[i][cur] + p[i + 1][cur]) % 10;
    swap(cur, nxt);
  }
  cout << p[0][cur] << p[1][cur];
}