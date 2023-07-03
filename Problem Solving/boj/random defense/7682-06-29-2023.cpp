#include <bits/stdc++.h>
using namespace std;

string input;
unordered_map<string, bool> d;

bool isEnded(string stat) {
  bool has_vct = 0;
  for (int i = 0; i < 9; i++)
    if (stat[i] == '.') has_vct = 1;
  if (!has_vct) return 1;

  for (int i = 0; i < 3; i++) {
    if (stat[i] != stat[i + 3]) continue;
    if (stat[i + 3] != stat[i + 6]) continue;
    if (stat[i] == '.') continue;
    return 1;
  }
  for (int i = 0; i < 3; i++) {
    if (stat[3*i] != stat[3*i + 1]) continue;
    if (stat[3*i + 1] != stat[3*i + 2]) continue;
    if (stat[3*i] == '.') continue;
    return 1;
  }
  if (stat[0] == stat[4] && stat[4] == stat[8] && stat[0] != '.') return 1;
  return (stat[2] == stat[4] && stat[4] == stat[6] && stat[2] != '.');
}

void setup(string stat, int turn) {
  if (isEnded(stat)) { d[stat] = 1; return; }

  char c = 'O';
  if (turn % 2) c = 'X';

  for (int i = 0; i < 9; i++) {
    if (stat[i] != '.') continue;
    stat[i] = c;
    setup(stat, turn + 1);
    stat[i] = '.';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string init = ".........";
  setup(init, 1);

  cin >> input;
  while (input != "end") {
    if (d[input]) cout << "valid\n";
    else cout << "invalid\n";
    cin >> input;
  }
}