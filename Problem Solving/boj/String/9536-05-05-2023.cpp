#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> um;
vector<string> sounds, other_sounds;
string s;

vector<string> split(string &str, string sep) {
  vector<string> ret;
  int pos = 0;
  while(pos < str.size()) {
    int nxt_pos = str.find(sep, pos);
    if(nxt_pos == -1) nxt_pos = str.size();
    ret.push_back(str.substr(pos, nxt_pos - pos));
    pos = nxt_pos + sep.size();
  }
  return ret;
}

void solve() {
  getline(cin, s);
  sounds = split(s, " ");

  while(1) {
    getline(cin, s);
    if(s == "what does the fox say?") break;
    other_sounds = split(s, " ");
    um[other_sounds[2]] = 1;
  }

  for(string snd : sounds) {
    if(um[snd]) continue;
    cout << snd << ' ';
  }
  cout << '\n';
  um.clear();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  getline(cin, s);
  int t; t = stoi(s);
  while(t--) solve();
}