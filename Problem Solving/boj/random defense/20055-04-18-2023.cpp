#include <bits/stdc++.h>
using namespace std;

const int MX = 100;

int n, k, cnt;
int a[MX*2 + 2];
bool is_bot[MX + 2];

void rot() {
  rotate(a, a + 2*n - 1, a + 2*n);
  rotate(is_bot, is_bot + n - 1, is_bot + n);
  is_bot[n - 1] = 0;
}

void move() {
  for(int cur = n - 2; cur > 0; cur--) {
    int nxt = cur + 1;
    if(!is_bot[cur] || is_bot[nxt]) continue;
    if(a[nxt] == 0) continue;
    if(--a[nxt] == 0) cnt++;
    is_bot[cur] = 0; is_bot[nxt] = 1;
  }
  is_bot[n - 1] = 0;
}

void put_bot() {
  if(a[0] == 0) return;
  if(--a[0] == 0) cnt++;
  is_bot[0] = 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i = 0; i < 2 * n; i++)
    cin >> a[i];

  int t = 0;
  while(++t) {
    rot();
    move();
    put_bot();
    if(cnt >= k) break;
  }
  cout << t;
}