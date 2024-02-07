#include <bits/stdc++.h>
using namespace std;

int n, x, y;
pair<int, int> p[52];
int r[52];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x >> y;
    p[i] = {x, y};
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(p[i].first < p[j].first && p[i].second < p[j].second)
        r[i]++;

  for(int i = 0; i < n; i++)
    cout << r[i] + 1 << ' ';
}