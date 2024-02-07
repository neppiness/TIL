#include <bits/stdc++.h>
using namespace std;

const int LIM = 99999;
int cnt[100'002];

int button_a(int cur) {
  return cur + 1 > LIM ? -1 : cur + 1;
}

int button_b(int cur) {
  int nxt = cur * 2;
  if (nxt > LIM) return -1;

  for (int no = 10'000; no; no /= 10) {
    if (nxt / no == 0) continue;
    nxt -= no;
    break;
  }
  return nxt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cnt, -1, sizeof(cnt));

  int n, t, g;
  cin >> n >> t >> g;

  queue<int> q;
  q.push(n);
  cnt[n] = 0;

  while (!q.empty()) {
    int cur = q.front(); q.pop();
    if (cnt[cur] > t) continue;
    if (cur == g) {
      cout << cnt[cur];
      return 0;
    }
    int nxta = button_a(cur);
    int nxtb = button_b(cur);
    for (int nxt : {nxta, nxtb}) {
      if (nxt == -1 || cnt[nxt] != -1) continue;
      cnt[nxt] = cnt[cur] + 1;
      q.push(nxt);
    }
  }
  cout << "ANG";
}
