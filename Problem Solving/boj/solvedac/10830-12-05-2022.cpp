#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> m;

int cmult(vector<vector<int>> &ma, vector<vector<int>> &mb, int row, int col) {
  int res = 0;
  for(int i = 0; i < n; i++)
    res += (ma[row][i] % 1000) * (mb[i][col] % 1000);
  return res % 1000;
}

vector<vector<int>> mmult(vector<vector<int>> &ma, vector<vector<int>> &mb) {
  vector<vector<int>> mc;
  for(int i = 0; i < n; i++) {
    vector<int> row;
    for(int j = 0; j < n; j++)
      row.push_back(cmult(ma, mb, i, j));
    mc.push_back(row);
  }
  return mc;
}

vector<vector<int>> mpow(long long p) {
  if(p == 1) {
    vector<vector<int>> mprime;
    for(int i = 0; i < n; i++) {
      vector<int> row;
      for(int j = 0; j < n; j++)
        row.push_back(m[i][j] % 1000);
      mprime.push_back(row);
    }
    return mprime;
  }
  vector<vector<int>> mphalf = mpow(p / 2);
  vector<vector<int>> mphalfsqr = mmult(mphalf, mphalf);

  if(p % 2 == 0) return mphalfsqr;
  return mmult(mphalfsqr, m);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long b;
  cin >> n >> b;

  for(int i = 0; i < n; i++) {
    vector<int> row;
    for(int j = 0; j < n; j++) {
      int x; cin >> x;
      row.push_back(x);
    }
    m.push_back(row);
  }

  vector<vector<int>> res = mpow(b);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cout << res[i][j] << " \n"[j == n - 1];
}