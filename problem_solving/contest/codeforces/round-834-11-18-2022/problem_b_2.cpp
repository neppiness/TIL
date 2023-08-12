#include <bits/stdc++.h>
using namespace std;

int t;
bool isUsed[71];

string solve() {
  fill(isUsed, isUsed + 52, 0);
  
  int m, s;
  cin >> m >> s;

  int x;
  while(m--) {
    cin >> x;
    isUsed[x] = 1;
  }

  int chk = -1;
  for(int i = 1; i <= 70; i++) {
    if(!isUsed[i]) s -= i;
    if(s == 0) {
      for(int j = i + 1; j <= 70; j++)
        if(!isUsed[j]) {
          chk = j; break;
        }
      if(chk == -1) return "YES";
      for(int j = chk + 1; j <= 70; j++)
        if(isUsed[j]) return "NO";
      return "YES";
    }
    if(s > 0) continue;
  }
  return "NO";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--) cout << solve() << '\n';
}