#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  cin >> a >> b;

  int ans = 0, len;
  for(int i = 0; i < (int)a.size(); i++) {
    len = 0;
    for(int j = 0; j < (int)b.size(); j++) {
      int tmp = 0;
      if(a[i] == b[j]) {
        while(a[i + len] == b[j + len]) len++;
        if(!tmp && (a[i + len] == b[j + len])) tmp = j + len;
        ans = max(ans, len);
      }
      if(!tmp) j += len;
      else j = tmp;
      len = 0;
    }
  }
  cout << ans;
}
/*
Test case:
ACAYKP
CAPCAK
*/