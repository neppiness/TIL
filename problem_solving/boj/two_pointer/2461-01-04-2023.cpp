#include <bits/stdc++.h>
using namespace std;

const int MX = 1'002;
const int INF = 0x7f7f7f7f;
int mx, ans = INF;

priority_queue< pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>> > pq; // {value, class}

int idx[MX]; // index for ith student (0-indexed)
int ab[MX][MX]; // abilities of students, ab[class][index]

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; // n: class, m: index
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
      cin >> ab[i][j];
    sort(ab[i], ab[i] + m);
    pq.push({ab[i][0], i});
    mx = max(ab[i][0], mx);
  }
  while(1) {
    auto [mn, cur] = pq.top(); pq.pop();
    ans = min(ans, (mx - mn));
    idx[cur]++;
    if(idx[cur] == m) break;
    mx = max(mx, ab[cur][idx[cur]]);
    pq.push({ab[cur][idx[cur]], cur});
  }
  cout << ans;
}