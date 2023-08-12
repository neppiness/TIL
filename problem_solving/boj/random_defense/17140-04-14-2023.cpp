#include <bits/stdc++.h>
using namespace std;

const int MX = 100;

int r, c, k;
int cur_r = 3, cur_c = 3;
int b[102][102];

unordered_map<int, int> fr;
set<int> key;
vector<pair<int, int>> v;

void r_op() {
  for(int i = 0; i < cur_r; i++) {
    fr.clear(); key.clear(); v.clear();
    for(int j = 0; j < cur_c; j++) {
      if(b[i][j] == 0) continue;
      key.insert(b[i][j]);
      fr[b[i][j]]++;
    }
    for(int k : key) v.push_back({fr[k], k});
    sort(v.begin(), v.end());
    cur_c = min(max(cur_c, (int)v.size() * 2), MX);
    for(int j = 0; j < cur_c; j++) {
      if(j >= v.size()) {
        b[i][j*2] = 0;
        b[i][j*2 + 1] = 0;
        continue;
      }
      b[i][j*2] = v[j].second;
      b[i][j*2 + 1] = v[j].first;
    }
  }
}

void c_op() {
  for(int j = 0; j < cur_c; j++) {
    fr.clear(); key.clear(); v.clear();
    for(int i = 0; i < cur_r; i++) {
      if(b[i][j] == 0) continue;
      key.insert(b[i][j]);
      fr[b[i][j]]++;
    }
    for(int k : key) v.push_back({fr[k], k});
    sort(v.begin(), v.end());
    cur_r = min(max(cur_r, (int)v.size() * 2), MX);
    for(int i = 0; i < cur_r; i++) {
      if(i >= v.size()) {
        b[i*2][j] = 0;
        b[i*2 + 1][j] = 0;
        continue;
      }
      b[i*2][j] = v[i].second;
      b[i*2 + 1][j] = v[i].first;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c >> k;
  for(int i = 0; i < cur_r; i++)
    for(int j = 0; j < cur_c; j++)
      cin >> b[i][j];
      
  if(b[r - 1][c - 1] == k) { cout << 0; return 0; }
  for(int t = 1; t <= 100; t++) {
    if(cur_r >= cur_c) r_op();
    else c_op();
    if(b[r - 1][c - 1] == k) { cout << t; return 0; }
  }
  cout << -1;
}