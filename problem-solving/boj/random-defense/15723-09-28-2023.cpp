#include <bits/stdc++.h>
using namespace std;

bool reachable[28][28];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;
  for (int i = 0; i < 26; i++)
    reachable[i][i] = 1;

  while (n--) {
    vector<string> s(3);
    for (int i = 0; i < 3; i++)
      cin >> s[i];
    int u = s[0][0] - 'a';
    int v = s[2][0] - 'a';
    reachable[u][v] = 1;
  }

  for (int k = 0; k < 26; k++)
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++)
        reachable[i][j] |= (reachable[i][k] && reachable[k][j]);
  
  cin >> n;
  while (n--) {
    vector<string> s(3);
    for (int i = 0; i < 3; i++)
      cin >> s[i];
    int u = s[0][0] - 'a';
    int v = s[2][0] - 'a';
    cout << "FT"[reachable[u][v]] << '\n';
  }
}
