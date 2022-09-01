#include <bits/stdc++.h>
using namespace std;

int N;
unordered_map<string, bool> comp;
vector<string> names;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> N;

  for(int i = 0; i < N; i++) {
    string nm, el;
    cin >> nm >> el;
    if(el == "leave") comp.erase(nm);
    else comp[nm] = 1;
  }

  int idx = 0;
  for(auto e : comp) names.push_back(e.first);

  sort(names.begin(), names.end());
  for(auto it = names.rbegin(); it != names.rend(); it++)
    cout << *it << '\n';
}