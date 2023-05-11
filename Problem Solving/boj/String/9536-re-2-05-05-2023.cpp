#include <bits/stdc++.h>
using namespace std;

vector<string> sounds, other_sounds, tmp;
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
    tmp = split(s, " ");
    other_sounds.push_back(tmp[2]);
  }

  for(string snd : sounds) {
    bool is_other_sound = 0;
    for(string os : other_sounds) {
      if(os != snd) continue;
      is_other_sound = 1; break;
    }
    if(is_other_sound) continue;
    cout << snd << ' ';
  }
  cout << '\n';
  other_sounds.clear();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t; cin >> t;
  cin.ignore();
  while(t--) solve();
}