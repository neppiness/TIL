#include <bits/stdc++.h>
using namespace std;

int record[6][3];

bool solve() {
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 3; j++)
      cin >> record[i][j];
  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 4;
  while (t--) {
    cout << solve() << ' ';
  }
}
