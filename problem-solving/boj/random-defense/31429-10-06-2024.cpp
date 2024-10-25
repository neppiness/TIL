#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int, int>> record;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  record[1] = {12, 1600};
  record[2] = {11, 894};
  record[3] = {11, 1327};
  record[4] = {10, 1311};
  record[5] = {9, 1004};
  record[6] = {9, 1178};
  record[7] = {9, 1357};
  record[8] = {8, 837};
  record[9] = {7, 1055};
  record[10] = {6, 556};
  record[11] = {6, 773};

  int n; cin >> n;
  cout << record[n].first << ' ' << record[n].second;
}
