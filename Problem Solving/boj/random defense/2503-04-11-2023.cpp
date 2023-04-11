#include <bits/stdc++.h>
using namespace std;

int cnt;
vector<tuple<vector<int>, int, int>> q; // {digits, st, ba}
vector<int> di_try(3);

bool valid_no() {
  for(auto [di, st, ba] : q) {
    int chk_st = 0, chk_ba = 0;
    bool is_used[10] = {};

    for(int d : di) is_used[d] = 1;
    
    for(int d : di_try)
      if(is_used[d]) chk_ba++;
    
    for(int i = 0; i < 3; i++)
      if(di[i] == di_try[i]) {
        chk_ba--; chk_st++;
      }
    
    if(st == chk_st && ba == chk_ba) continue;
    return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while(n--) {
    int no, st, ba;
    cin >> no >> st >> ba;
    vector<int> di(3);
    int idx = 2;
    while(no) {
      di[idx--] = no % 10;
      no /= 10;
    }
    q.push_back({di, st, ba});
  }

  for(int no = 123; no <= 987; no++) {
    bool is_used[10] = {}, is_valid = 1;
    int idx = 2, tmp = no;
    while(tmp) {
      int d = tmp % 10;
      if(is_used[d] || d == 0) is_valid = 0;
      is_used[d] = 1;
      di_try[idx--] = d;
      tmp /= 10;
    }
    if(!is_valid) continue;
    cnt += valid_no(); 
  }
  cout << cnt;
}