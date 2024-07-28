#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cnt = 1;
  string input;
  getline(cin, input);
  int n = stoi(input);
  string songs[202];
  while (n) {
    cout << cnt++ << '\n';
    for (int i = 0; i < n; i++)
      getline(cin, songs[i]);
    sort(songs, songs + n);
    for (int i = 0; i < n; i++)
      cout << songs[i] << '\n';
    getline(cin, input);
    n = stoi(input);
  }
}
