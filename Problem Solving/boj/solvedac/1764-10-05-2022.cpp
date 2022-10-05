#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> nlist;
vector<string> ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  string str;

  cin >> n >> m;
  while(n--){
    cin >> str;
    nlist[str] = 1;
  }
  while(m--){
    cin >> str;
    if(nlist[str]) ans.push_back(str);
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for(auto name : ans) cout << name << '\n';
}