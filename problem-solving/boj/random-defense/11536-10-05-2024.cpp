#include <bits/stdc++.h>
using namespace std;

int n; 
string org[22], asc[22], desc[22];

bool is_asc() {
  for (int i = 0; i < n; i++)
    if (org[i] != asc[i])
      return 0;
  return 1;
}

bool is_desc() {
  for (int i = 0; i < n; i++)
    if (org[i] != desc[i])
      return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    org[i] = s;
    asc[i] = s;
    desc[i] = s;
  }
  sort(asc, asc + n);
  sort(desc, desc + n, greater<string>());

  if (is_asc()) {
    cout << "INCREASING";
  } else if (is_desc()) {
    cout << "DECREASING";
  } else {
    cout << "NEITHER";
  }
}
