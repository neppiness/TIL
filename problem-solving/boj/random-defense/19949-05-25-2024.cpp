#include <bits/stdc++.h>
using namespace std;

int ans[10], note[10];
int cnt;

void solve(int idx) {
  if (idx == 10) {
    int score = 0, prv = -1, seq = 1;
    for (int i = 0; i < 10; i++) {
      score += (ans[i] == note[i]);
      if (prv == note[i]) {
        seq++;
      } else {
        seq = 1;
      }
      if (seq == 3) return;
      prv = note[i];
    }
    cnt += (score >= 5);
    return;
  }

  for (int i = 1; i <= 5; i++) {
    note[idx] = i;
    solve(idx + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 10; i++)
    cin >> ans[i];

  solve(0);
  cout << cnt;
}
