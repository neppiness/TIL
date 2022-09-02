#include <bits/stdc++.h>
using namespace std;

int K, L;
vector<string> v;
string str;
unordered_map<string, int> us;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> K >> L;

  int cur = 0;
  while(L--) {
    cin >> str;

    auto it = us.find(str);
    if(it != us.end()) v[us[str]] = "dummy";
    v.push_back(str);
    us[str] = cur++;
  }

  int cnt = 0;
  auto it = v.begin();
  while(cnt < K && it != v.end()) {
    if(*it != "dummy"){
      cout << *it << '\n';
      cnt++;
    }
    it++;
  }
}