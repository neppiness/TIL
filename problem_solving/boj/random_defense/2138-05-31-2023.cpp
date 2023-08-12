#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;
const int INF = 0x7f7f7f7f;

int n;
bool A[MX + 2], B[MX + 2], tmp[MX + 2];

int PushSwitch() {
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (tmp[i - 1] == B[i - 1]) continue;
    cnt++;
    for (int j : {i - 1, i, i + 1}) {
      if (j == n) continue;
      tmp[j] = !tmp[j];
    }
  }
  return cnt;
}

bool IsSame() {
  for (int i = 0; i < n; i++)
    if (tmp[i] != B[i]) return 0;
  return 1;
}

int solve(bool code) {
  for (int i = 0; i < n; i++)
    tmp[i] = A[i];

  int cnt = 0;
  if (code) {
    cnt++;
    tmp[0] = !tmp[0];
    tmp[1] = !tmp[1];
  }

  cnt += PushSwitch();
  if (IsSame()) return cnt;
  return INF;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    A[i] = (c == '1');
  }
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    B[i] = (c == '1');
  }
  int ans = min(solve(0), solve(1));
  if (ans == INF) ans = -1;
  cout << ans;
}