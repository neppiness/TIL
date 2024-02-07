#include <bits/stdc++.h>
using namespace std;

string s;
vector<vector<string>> strs;
int dcidx;

vector<vector<string>> split(string& s, string sep) {
  vector<vector<string>> ret;
  ret.resize(2);

  int pos = 0;

  while(pos < s.size()) {
    int nxt_pos = s.find(sep, pos);
    if(nxt_pos == -1) nxt_pos = s.size();
    if(nxt_pos - pos > 0)
      ret[dcidx < pos].push_back(s.substr(pos, nxt_pos - pos));
    pos = nxt_pos + sep.size();
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  dcidx = s.find("::");
  strs = split(s, ":");

  int cnt = 1;
  for(int lv = 0; lv < 2; lv++) {
    for(int i = 0; i < strs[lv].size(); i++) {
      string& ss = strs[lv][i];
      int no = 4 - ss.size();
      while(no--) cout << 0;
      cout << ss;
      if(cnt != 8) cout << ':';
      cnt++;
    }
    if(lv == 0) {
      int no = 8 - strs[0].size() - strs[1].size();
      while(no--) {
        cout << "0000";
        if(cnt != 8) cout << ':';
        cnt++;
      }
    }
  }
}