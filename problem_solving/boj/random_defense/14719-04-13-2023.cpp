#include <bits/stdc++.h>
using namespace std;

const int MX = 502;

int h, w, ans;
bool b[MX][MX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> h >> w;

  int x;
  for(int j = 0; j < w; j++) {
    cin >> x;
    for(int i = 0; i < x; i++)
      b[i][j] = 1;
  }

  for(int i = 0; i < h; i++) {
    int cnt = 0;
    bool is_one_found = 0;
    for(int j = 0; j < w; j++) {
      if(!b[i][j]) { cnt++ ;continue; }
      if(is_one_found) { ans += cnt;}
      cnt = 0;
      is_one_found = 1;
    }
  }
  cout << ans;
}