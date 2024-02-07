#include <bits/stdc++.h>
using namespace std;

int n, m;
int dist[502][502];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> dist[i][j];

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  while (m--) {
    int st, en, lim;
    cin >> st >> en >> lim;
    st--; en--;
    if (dist[st][en] > lim) {
      cout << "Stay here\n";
    } else {
      cout << "Enjoy other party\n";
    }
  }
}
