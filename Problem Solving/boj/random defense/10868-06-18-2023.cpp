#include <bits/stdc++.h>
using namespace std;

const int kInf = 0x3f3f3f3f;

int n, m, a, b;
int val[100'002];
int seg[400'002];

int init(int st, int en, int cur) {
  if (st == en) return seg[cur] = val[st];
  int mid = (st + en) / 2;
  return seg[cur] = min(init(st, mid, cur*2), init(mid + 1, en, cur*2 + 1));
}

int find(int st, int en, int cur) {
  if (a <= st && en <= b) return seg[cur];
  if (en < a || b < st) return kInf;
  int mid = (st + en) / 2;
  return min(find(st, mid, cur*2), find(mid + 1, en, cur*2 + 1));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> val[i];

  init(1, n, 1);

  while (m--) {
    cin >> a >> b;
    cout << find(1, n, 1) << '\n';
  }
}