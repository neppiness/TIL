#include <bits/stdc++.h>
using namespace std;

vector<int> v, h;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  h.push_back(0);
  h.push_back(n);
  v.push_back(0);
  v.push_back(m);

  int q; cin >> q;
  while (q--) {
    bool code; int x;
    cin >> code >> x;
    if (code) {
      h.push_back(x);
    } else {
      v.push_back(x);
    }
  }

  sort(v.begin(), v.end());
  sort(h.begin(), h.end());

  vector<int> vl, hl;
  for (int i = 1; i < v.size(); i++) {
    vl.push_back(v[i] - v[i - 1]);
  }
  for (int i = 1; i < h.size(); i++) {
    hl.push_back(h[i] - h[i - 1]);
  }

  int mx = 0;
  for (int i = 0; i < vl.size(); i++)
    for (int j = 0; j < hl.size(); j++)
      mx = max(mx, vl[i] * hl[j]);
  cout << mx;
}
