#include <bits/stdc++.h>
using namespace std;

string rec_sound, input, s;
stringstream ss;
unordered_map<string, bool> um;

void solve() {
  getline(cin, rec_sound);
  getline(cin, input);
  while(input != "what does the fox say?") {
    ss = stringstream(input);
    ss >> s >> s >> s;
    um[s] = 1;
    getline(cin, input);
  }

  ss = stringstream(rec_sound);
  while(ss >> s)
    if(!um[s]) cout << s << ' ';
  cout << '\n';
  um.clear();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  getline(cin, input);
  int t = stoi(input);

  while(t--) solve();
}