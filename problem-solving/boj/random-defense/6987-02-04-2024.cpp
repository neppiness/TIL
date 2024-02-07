#include <bits/stdc++.h>
using namespace std;

int record[6][3]; // record[i][j], i: 팀 인덱스, j: 0-승, 1-무, 2-패
int note[6][3];

bool is_valid() {
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 3; j++)
      if (record[i][j] != note[i][j]) return 0;
  return 1;
}

pair<int, int> get_ij(int no) {
  int cnt = 0;
  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      cnt++;
      if (cnt == no) return {i, j};
    }
  }
  return {-1, -1};
}

bool solve(int no) {
  if (no == 16) {
    return is_valid();
  }

  auto [i, j] = get_ij(no);

  note[i][0]++;
  note[j][2]++;
  if (solve(no + 1)) return 1;
  note[i][0]--;
  note[j][2]--;

  note[i][2]++;
  note[j][0]++;
  if (solve(no + 1)) return 1;
  note[i][2]--;
  note[j][0]--;

  note[i][1]++;
  note[j][1]++;
  if (solve(no + 1)) return 1;
  note[i][1]--;
  note[j][1]--;

  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 4;
  while (t--) {
    memset(note, 0, sizeof(note));
    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 3; j++)
        cin >> record[i][j];
    cout << solve(1) << ' ';
  }
}
