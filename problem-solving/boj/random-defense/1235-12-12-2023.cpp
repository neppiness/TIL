#include <bits/stdc++.h>
using namespace std;

int n;
string no[1'002];

bool is_solved(int idx) {
  unordered_map<string, bool> does_exist;
  for (int i = 0; i < n; i++) {
    string ss = no[i].substr(no[0].size() - idx);
    if (does_exist[ss]) return 0;
    does_exist[ss] = 1;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> no[i];

  int st = 1, en = no[0].size();
  while (st < en) {
    int mid = (st + en) / 2;
    if (is_solved(mid)) en = mid;
    else st = mid + 1;
  }
  cout << st;
}
