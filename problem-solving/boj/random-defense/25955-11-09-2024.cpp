#include <bits/stdc++.h>
using namespace std;

string input[1002];
string sorted[1002];
string ans[2];

int cnt;

int getGrade(char gr) {
  if (gr == 'B') return 0;
  if (gr == 'S') return 1;
  if (gr == 'G') return 2;
  if (gr == 'P') return 3;
  return 4;
}

bool cmp(string &s1, string &s2) {
  if (s1[0] == s2[0]) {
    int level1 = stoi(s1.substr(1));
    int level2 = stoi(s2.substr(1));
    return level1 > level2;
  }
  return getGrade(s1[0]) < getGrade(s2[0]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input[i];
    sorted[i] = input[i];
  }
  sort(sorted, sorted + n, cmp);

  for (int i = 0; i < n; i++) {
    if (input[i] == sorted[i]) continue;
    ans[cnt++] = input[i];
  }

  if (cnt) {
    sort(ans, ans + 2, cmp);
    cout << "KO\n";
    cout << ans[0] << ' ' << ans[1];
  } else {
    cout << "OK";
  }
}
