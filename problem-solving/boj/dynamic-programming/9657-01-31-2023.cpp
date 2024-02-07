#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;

vector<int> dx = {-1, -3, -4};
string cache[MX + 2];

string solve(int cur) {
  if(cur == 0) return "CY";
  string &ret = cache[cur];
  if(ret.length() != 0) return ret;

  bool all_sk = 1;
  for(auto d : dx) {
    int prv = cur + d;
    if(prv < 0) continue;
    if(solve(prv) == "SK") continue;
    all_sk = 0;
  }
  if(all_sk) return ret = "CY";
  return ret = "SK";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cout << solve(n);
}