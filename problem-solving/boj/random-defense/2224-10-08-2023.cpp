#include <bits/stdc++.h>
using namespace std;

const string ARROW = " => ";

bool dist[55][55];

int ctoi(char c) {
  if (c >= 'A' && c <= 'Z') return c - 'A';
  return c - 'a' + 26;
}

char itoc(int x) {
  if (x < 26) return (char)x + 'A';
  return (char)x - 26 + 'a';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cin.ignore();
  string s;
  while (getline(cin, s)) {
    int u = ctoi(s[0]);
    int v = ctoi(s[5]);
    dist[u][v] = 1;
  }

  for (int i = 0; i < 52; i++)
    dist[i][i] = 1;

  for (int k = 0; k < 52; k++)
    for (int i = 0; i < 52; i++)
      for (int j = 0; j < 52; j++)
        dist[i][j] |= (dist[i][k] & dist[k][j]); 

  int cnt = 0;
  for (int i = 0; i < 52; i++)
    for (int j = 0; j < 52; j++) {
      if (i == j) continue;
      if (dist[i][j]) cnt++;
    }

  cout << cnt << endl;
  for (int i = 0; i < 52; i++)
    for (int j = 0; j < 52; j++) {
      if (i == j) continue;
      if (dist[i][j])
        cout << itoc(i) << ARROW << itoc(j) << '\n';
    }
}
