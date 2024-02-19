#include <bits/stdc++.h>
using namespace std;

string pt; 
vector<string> pattern;

string ans[] = {"NE", "DA"};

bool solve() {
  string s; cin >> s;
  int pos1 = s.find(pattern[0]);
  if (s.size() - pattern[1].size() < pattern[0].size()) return 0;
  int pos2 = s.find(pattern[1], s.size() - pattern[1].size());
  return pos1 == 0 && pos2 != -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cin >> pt;
  
  int pos = pt.find("*");
  pattern.push_back(pt.substr(0, pos));
  pattern.push_back(pt.substr(pos + 1));

  while (n--)
    cout << ans[solve()] << '\n';
}
