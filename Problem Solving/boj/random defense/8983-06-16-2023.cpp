#include <bits/stdc++.h>
using namespace std;

int n, m, lim, ans;
int s[100'002];
pair<int, int> a[100'002];

int find(int x) {
  int st = 0; int en = n - 1;
  while (st < en) {
    int mid = (st + en) / 2;
    if (s[mid] < x) st = mid + 1;
    else en = mid;
  }
  return st;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> lim;
  for (int i = 0; i < n; i++) // n: 사대 개수
    cin >> s[i];
  for (int i = 0; i < m; i++) { // m: 동물 수
    int x, y; cin >> x >> y;
    a[i] = {x, y};
  }
  sort(s, s + n);
  sort(a, a + m);

  for (int i = 0; i < m; i++) {
    auto [x, y] = a[i];
    int sidx = find(x);
    for (int j : {sidx - 1, sidx}) {
      if (j < 0) continue;
      if (abs(s[j] - x) + y <= lim) {
        ans++; break;
      }
    }
  }
  cout << ans;
}