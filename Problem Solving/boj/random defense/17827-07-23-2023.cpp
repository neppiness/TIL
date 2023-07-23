#include <bits/stdc++.h>
using namespace std;

const int EMX = 30; // (1 << 30) = 1,073,741,824로 이 값을 넘어갈 일은 없음.
int n, m, v;
int nxt[200'002][EMX + 2], val[200'002];

void stSetup() {
  for (int ex = 1; ex < EMX; ex++)
    for (int i = 1; i <= n; i++)
      nxt[i][ex] = nxt[nxt[i][ex - 1]][ex - 1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> v;
  for (int i = 1; i < n; i++)
    nxt[i][0] = i + 1;
  nxt[n][0] = v;

  for (int i = 1; i <= n; i++)
    cin >> val[i];
  
  stSetup();

  while (m--) {
    int st = 1;
    int k; cin >> k;
    int ex = 0;
    while (k) {
      if (k % 2) st = nxt[st][ex];
      k /= 2; ex++;
    }
    cout << val[st] << '\n';
  }
}