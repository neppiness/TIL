#include <bits/stdc++.h>
using namespace std;

int len[1002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  cin >> a >> b;

  int tmp;
  for(int i = 0; i < a.length(); i++) {
    for(int j = 0; j < b.length(); j++) {
      if(b[j] == a[i]) {
        len[j] = max(1, len[j]);
        tmp = j;
        tmp--;
        while(tmp >= 0 && b[tmp] != a[i]) {
          len[j] = max(len[tmp] + 1, len[j]);
          tmp--;
        }
      }
    }
  }
  int midx = max_element(len, len + 1002) - len;
  cout << len[midx];
}