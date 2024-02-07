#include <bits/stdc++.h>
using namespace std;

const string SEP = "\\";
const string ROOT = "ROOT";

int seq = 1; // 0 for ROOT
vector<int> adj[20002];
string file_name[20002];

vector<string> split(string &s) {
  vector<string> ret;

  int pos = 0;
  while (pos < s.size()) {
    int nxt = s.find(SEP, pos);
    if (nxt == -1) nxt = s.size();
    if (nxt - pos > 0)
      ret.push_back(s.substr(pos, nxt - pos));
    pos = nxt + SEP.size();
  }
  return ret;
}

void dfs(int cur, int d) {
  for (int i = 0; i < d; i++)
    cout << ' ';
  cout << file_name[cur] << '\n';
  
  set<pair<string, int>> nxt_info;
  for (auto nxt : adj[cur])
    nxt_info.insert({file_name[nxt], nxt});

  for (auto [file_name, nxt] : nxt_info)
    dfs(nxt, d + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    string s; cin >> s;
    vector<string> split_s = split(s);
    int prv = 0;
    for (auto ss : split_s) {
      int tmp = -1;
      for (int cur : adj[prv])
        if (ss == file_name[cur]) tmp = cur;
      if (tmp == -1) {
        tmp = seq++;
        file_name[tmp] = ss;
        adj[prv].push_back(tmp);
      }
      prv = tmp;
    }
  }

  set<pair<string, int>> nxt_info;
  for (auto nxt : adj[0])
    nxt_info.insert({file_name[nxt], nxt});

  for (auto [file_name, nxt] : nxt_info)
    dfs(nxt, 0);
}
