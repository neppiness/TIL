#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000 + 2;

vector<int> ans;
int memo[MX], sz;

int solve(int x) {
  int &ret = memo[x];
  if(ret != -1) return ret;

  bool win = 0;
  for(int i = 0; i < sz; i++) {
    int j = i;
    int y = 1;
    while(j--) { y *= 10; }
    if(solve())
  }
}

bool a(vector<vector<int>> &q, int i) {
  int x = 0;
  sz = q[i].size();
  for(int j = 0; j < sz; j++) {
    x *= 10;
    x += q[i][j];
  }
  return solve(x, sz);
}

vector<int> solution(vector<vector<int>> q) {
  int n = q.size();
  for(int i = 0; i < n; i++)
    ans.push_back(a(q, i));
  return ans;
}