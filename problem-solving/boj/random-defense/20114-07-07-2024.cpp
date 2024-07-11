#include <bits/stdc++.h>
using namespace std;

int n, h, w;
string s[1002];

char solve(int cur) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][cur + j] == '?') continue;
      return s[i][cur + j];
    }
  }
  return '?';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> h >> w;
  
  for (int i = 0; i < h; i++)
    cin >> s[i];

  for (int j = 0; j < n; j++) {
    int cur = w * j;
    cout << (char)solve(cur);
  }
}
