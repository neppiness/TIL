#include <bits/stdc++.h>
using namespace std;

int n, m, l;
vector<int> road;

bool solve(int d) {
  int cnt = 0;
  for (int i = 1; i < road.size(); i++) {
    int len = road[i] - road[i - 1];
    cnt += len / d - (len % d == 0);
  }
  return cnt <= m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> l;
  road.push_back(0);
  road.push_back(l);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    road.push_back(x);
  }
  sort(road.begin(), road.end());

  int st = 1, en = 1000;
  while (st < en) {
    int mid = (st + en) / 2;
    if (solve(mid)) en = mid;
    else st = mid + 1;
  }
  cout << st;
}
