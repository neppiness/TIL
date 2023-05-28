#include <bits/stdc++.h>
using namespace std;

class cmp {
  public:
    bool operator () (pair<int, int> &lh, pair<int, int> &rh) {
      if (lh.first == rh.first)
        return lh.second > rh.second;
      return lh.first < rh.first;
    }
};

int n;
priority_queue< pair<int, int>,
    vector<pair<int, int>>, cmp > pq; // {mon, due} : pq
vector<int> lec[10002]; // lec[due] = mon

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while (n--) {
    int mon, due; cin >> mon >> due;
    lec[due].push_back(mon);
  }

  int tot = 0;
  for (int day = 10000; day > 0; day--) {
    vector<int> &v = lec[day];
    for (int mon : v) pq.push({mon, day});
    if (pq.empty()) continue;
    auto [mon, due] = pq.top(); pq.pop();
    tot += mon;
  }
  cout << tot;
}