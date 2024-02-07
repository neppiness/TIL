#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> name[202];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; int a;
  cin >> n;
  while(n--) {
    cin >> a >> s;
    name[a].push_back(s);
  }
  for(int i = 1; i <= 200; i++)
    for(auto str : name[i])
      cout << i << ' ' << str << '\n';
}