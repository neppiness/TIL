#include <bits/stdc++.h>
using namespace std;

int mxlen;
int len[502];
vector<pair<int, int>> b;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    b.push_back({x, y});
  }

  sort(b.begin(), b.end());

  fill(len, len + 502, 1);
  for(int i = 0; i < n; i++) {
    auto [idx, val] = b[i];
    for(int j = 0; j < i; j++)
      if(b[j].second < b[i].second) {
        len[i] = max(len[j] + 1, len[i]);
        mxlen = max(len[i], mxlen);
      }
  }
  cout << b.size() - mxlen;
}