#include <bits/stdc++.h>
using namespace std;

bool has_card[4][14];

int shape_to_idx(char c) {
  switch (c) {
    case 'P': return 0;
    case 'K': return 1;
    case 'H': return 2;
    default: return 3;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  for (int i = 0; i < s.size(); i += 3) {
    char shape = s.substr(i, 1)[0];
    string num_as_string = s.substr(i + 1, 2);

    int num = stoi(num_as_string);
    int idx = shape_to_idx(shape);
    if (has_card[idx][num]) {
      cout << "GRESKA";
      return 0;
    }
    has_card[idx][num] = 1;
  }

  for (int i = 0; i < 4; i++) {
    int cnt = 0;
    for (int j = 1; j <= 13; j++)
      cnt += !has_card[i][j];
    cout << cnt << ' ';
  }
}
