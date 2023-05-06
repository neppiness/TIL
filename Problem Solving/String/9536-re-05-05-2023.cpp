#include <bits/stdc++.h>
using namespace std;

string input, sound;
stringstream ss;
vector<string> rec_sound, other_animal_sound;

void setup() {
  rec_sound.clear();
  other_animal_sound.clear();
  
  getline(cin, input);
  ss = stringstream(input);
  while(ss >> sound) rec_sound.push_back(sound);

  getline(cin, input);
  while(input != "what does the fox say?") {
    ss = stringstream(input);
    ss >> sound >> sound >> sound;
    other_animal_sound.push_back(sound);
    getline(cin, input);
  }
}

void print() {
  for(auto rs : rec_sound) {
    bool is_others_sound = 0;
    for(auto os : other_animal_sound)
      if(rs == os) is_others_sound = 1;
    if(is_others_sound) continue;
    cout << rs << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  cin.ignore();

  while(t--) {
    setup();
    print();
  }
}