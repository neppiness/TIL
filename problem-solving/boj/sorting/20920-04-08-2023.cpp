#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> wordFr;

struct dict {
  string word;

  bool operator < (dict& r) {
    if(wordFr[word] == wordFr[r.word]) {
      if(word.size() == r.word.size())
        return word < r.word;
      return word.size() > r.word.size();
    }
    return wordFr[word] > wordFr[r.word];
  }
};

vector<dict> dicts;
int n, lim;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> lim;
  string s;
  for(int i = 0; i < n; i++) {
    cin >> s;
    if(s.size() < lim) continue;
    int &fr = wordFr[s]; fr++;
    if(fr == 1) {
      dict d;
      d.word = s;
      dicts.push_back(d);
    }
  }
  
  sort(dicts.begin(), dicts.end());
  for(auto d : dicts)
    cout << d.word << '\n';
}