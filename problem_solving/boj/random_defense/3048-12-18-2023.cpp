#include <bits/stdc++.h>
using namespace std;

bool gr[30];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  string s0, s1;
  cin >> s0 >> s1;
  
  string s = "";

  for (int i = n - 1; i >= 0; i--)
    s += s0[i];
  for (int i = 0; i < m; i++) {
    s += s1[i];
    gr[s1[i] - 'A'] = 1;
  }

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    if (i % 2) { // 1번 그룹 이동, 왼쪽부터 확인
      for (int j = 0; j < n + m - 1; j++) {
        if (gr[s[j] - 'A']) continue;
        if (!gr[s[j + 1] - 'A']) continue;
        swap(s[j], s[j + 1]);
        j++;
      }
    } else { // 2번 그룹 이동, 오른쪽부터 확인
      for (int j = n + m - 1; j >= 1; j--) {
        if (!gr[s[j] - 'A']) continue;
        if (gr[s[j - 1] - 'A']) continue;
        swap(s[j], s[j - 1]);
        j--;
      }
    }
  }
  cout << s;
}
