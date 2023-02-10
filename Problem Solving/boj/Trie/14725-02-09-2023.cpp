#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
const int MX = 1000*15 + 2;

int n, unused = 2;
map<string, int> nxt[MX];

void print(int cur, int lv) {
  for(auto it = nxt[cur].begin(); it != nxt[cur].end(); it++) {
    for(int i = 0; i < lv; i++)
      cout << "--";
    cout << (*it).first << '\n';
    print((*it).second, lv + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    int m; cin >> m;
    int cur = ROOT;
    for(int j = 0; j < m; j++) {
      string s; cin >> s;
      auto it = nxt[cur].find(s);
      if(it == nxt[cur].end())
        nxt[cur][s] = unused++;
      cur = nxt[cur][s];
    }
  }
  print(ROOT, 0);
}