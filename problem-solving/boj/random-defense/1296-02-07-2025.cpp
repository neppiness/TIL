#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> entries;
const string LOVE = "LOVE";

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string name; cin >> name;
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int cnt[26] = {};
    string s; cin >> s;

    for (char c : name) cnt[c - 'A']++;
    for (char c : s) cnt[c - 'A']++;
    
    int mul = 1;
    for (int j = 0; j < LOVE.length(); j++) {
      for (int k = 0; k < j; k++) {
        mul *= (cnt[LOVE[j] - 'A'] + cnt[LOVE[k] - 'A']);
        mul %= 100;
      }
    }
    entries.push_back({-mul, s});
  }
  
  sort(entries.begin(), entries.end());
  cout << entries[0].second;
}
