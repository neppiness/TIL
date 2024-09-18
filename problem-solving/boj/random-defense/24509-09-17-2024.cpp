#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> received;
vector<pair<int, int>> sc[4]; // -sc, no

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int no; cin >> no;
    for (int j = 0; j < 4; j++) {
      int s; cin >> s;
      sc[j].push_back({-s, no});
    }
  }
  for (int j = 0; j < 4; j++)
    sort(sc[j].begin(), sc[j].end());

  for (int j = 0; j < 4; j++) {
    for (auto [s, no] : sc[j]) {
      if (received[no]) continue;
      cout << no << ' ';
      received[no] = 1;
      break;
    }
  }
}
