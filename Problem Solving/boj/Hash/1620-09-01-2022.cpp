#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> notoname;
unordered_map<string, int> nametono;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> N >> M;
  notoname.push_back("Null");
  for(int i = 1; i <= N; i++){
    string name; cin >> name;
    nametono[name] = i;
    notoname.push_back(name);
  }

  while(M--) {
    string input; cin >> input;
    int n = 0;
    if(input[0] >= '0' && input[0] <= '9')
      for(auto no : input) {
        n *= 10;
        n += no - '0';
      }

    if(!n) cout << nametono[input] << '\n';
    else cout << notoname[n] << '\n';
  }
}