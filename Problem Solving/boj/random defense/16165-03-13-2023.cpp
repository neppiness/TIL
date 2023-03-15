#include <bits/stdc++.h>
using namespace std;

const int MX = 100;

int unused = 1;
string gn[MX + 2]; // group names indexed by group id
set<string> mn[MX + 2]; // member names indexed by group id
unordered_map<string, int> gn_to_gr_id;
unordered_map<string, int> mn_to_gr_id;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while(n--) {
    string group_name;
    cin >> group_name;
    gn[unused] = group_name;
    gn_to_gr_id[group_name] = unused;

    int k; cin >> k;
    while(k--) {
      string nm; cin >> nm;
      mn[unused].insert(nm);
      mn_to_gr_id[nm] = unused;
    }
    unused++;
  }

  while(m--) {
    string name; cin >> name;
    int code; cin >> code;
    if(code == 1) {
      int gr_id = mn_to_gr_id[name];
      cout << gn[gr_id] << '\n';
    } else {
      int gr_id = gn_to_gr_id[name];
      for(auto member_name : mn[gr_id])
        cout << member_name << '\n';
    }
  }
}