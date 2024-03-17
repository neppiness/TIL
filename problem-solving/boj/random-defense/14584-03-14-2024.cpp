#include <bits/stdc++.h>
using namespace std;

string dic[22];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> dic[i];
  
  while (1) {
    for (char &c : s) {
      c++;
      if (c > 'z') c = 'a';
    }
    for (int i = 0; i < n; i++) {
      int pos = s.find(dic[i]);
      if (pos == -1) continue;
      cout << s;
      return 0;
    }
  }
}
