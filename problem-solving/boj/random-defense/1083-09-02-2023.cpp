#include <bits/stdc++.h>
using namespace std;

int n, s;
int a[52], b[52];

bool is_not_sorted() {
  for (int i = n - 1; i >= 0; i--)
    if (a[i] != b[i]) return 1;
  return 0;
}

void nxtToCur(int nxt, int cur) {
  while (nxt != cur) {
    swap(a[nxt], a[nxt - 1]);
    nxt--;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  
  sort(b, b + n, greater<int>());
  cin >> s;

  int cidx = 0;
  while (s && is_not_sorted()) {
    int max = -1, nidx = -1;
    for (int tmp = cidx + 1; tmp < n; tmp++) {
      if (a[cidx] > a[tmp]) continue;
      if (max > a[tmp]) continue;
      if (tmp - cidx > s) continue;
      nidx = tmp;
      max = a[tmp];
    } 
    if (max != -1) {
      s -= nidx - cidx;
      nxtToCur(nidx, cidx);
    }
    cidx++;
  }
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
}
