#include <bits/stdc++.h>
using namespace std;

int len[1002][1002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b; cin >> a >> b;
  for(int i = 0; i < a.length(); i++) {
    for(int j = 0; j < b.length(); j++) {
      if(a[i] == b[j]) len[i + 1][j + 1] = len[i][j] + 1;
      else len[i + 1][j + 1] = max(len[i][j + 1], len[i + 1][j]);
    }
  }
  cout << len[a.length()][b.length()];
}