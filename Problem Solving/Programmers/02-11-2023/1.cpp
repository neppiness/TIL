#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> lot) {
  int n = lot.size();
  vector<tuple<double, int, int>> v;
  for(int i = 0; i < n; i++) {
    int a = lot[i][1]; // 구매자 수
    a = max((a + 1), lot[i][0]);
    cout << a << ' ';
    double b = (double)lot[i][0] / (double)a;
    v.push_back({b, lot[i][2], i + 1});
  }
  sort(v.rbegin(), v.rend());
  int ans;
  tie(ignore, ignore, ans) = v[0];
  return ans;
}