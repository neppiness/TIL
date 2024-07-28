#include <bits/stdc++.h>
using namespace std;

bool is_valid[12];

int game() {
  fill(is_valid, is_valid + 11, 1);
  int x; cin >> x;
  if (x == 0) return -1;
  string s;
  while (1) {
    cin >> s >> s;
    if (s == "high") {
      for (int i = x; i <= 10; i++)
        is_valid[i] = 0;
    } else if (s == "low") {
      for (int i = x; i > 0; i--)
        is_valid[i] = 0;
    } else {
      return is_valid[x];
    }
    cin >> x;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    int res = game();
    if (res == 1) {
      cout << "Stan may be honest\n";
    } else if (res == 0) {
      cout << "Stan is dishonest\n";
    } else {
      return 0;
    }
  }
}
