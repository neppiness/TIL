#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    string name, hj, wn;
    cin >> name >> hj >> wn;
    int top, apc;
    cin >> top >> apc;
    
    if (hj == "hewhak") continue;
    if (wn == "winner") continue;
    if (top <= 3 && top != -1) continue;
    ans.push_back({apc, name});
  }
  sort(ans.begin(), ans.end());

  int m = min(10, (int) ans.size());
  cout << m << '\n';

  set<string> ans_name;
  for (int i = 0; i < m; i++)
    ans_name.insert(ans[i].second);
  for (string an : ans_name)
    cout << an << '\n';
}
