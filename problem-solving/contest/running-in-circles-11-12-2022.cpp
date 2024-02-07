#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T, n, d;
char c;
ll len;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  ll cnt, dist;
  for(int t = 1; t <= T; t++) {
    cnt = 0, dist = 0;
    cin >> len >> n;
    for(int i = 0; i < n; i++) {
      cin >> d >> c;
      if(c == 'C') {
        dist += d;
        cnt += dist/len;
        dist %= len;
      } else {
        if(dist > d) {
          dist -= d;
        } else {
          dist = -dist;
          dist += d;
          cnt += dist/len;
          dist %= len;
          dist = -dist;
        }
      }
    }
    cout << "Case #" << t << ": " << cnt << '\n';
  }
}