#include <bits/stdc++.h>
using namespace std;

string cal[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
int al[34];

bool isal(char a) { return (a >= 'a' && a <= 'z'); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  for(char a : s) {
    if(!isal(a)) continue;
    al[(int)(a - 'a')]++;
  }

  for(int i = 0; i < 8; i++) {
    string tof = cal[i];
    size_t found = s.find(tof);
    while(found != string::npos) {
      al[26 + i]++;
      for(int j = found; j < found + tof.length(); j++) {
        if(!isal(s[j])) continue;
        al[(int)(s[j] - 'a')]--;
      }
      found = s.find(tof, found + 1);
    }
  }

  int cnt = 0;
  for(int i = 0; i < 34; i++)
    cnt += al[i];
  cout << cnt << '\n';
}