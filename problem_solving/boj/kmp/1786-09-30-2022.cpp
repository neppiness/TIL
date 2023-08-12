#include <bits/stdc++.h>
using namespace std;

string t, p;
vector<int> f_func, ans;

vector<int> failure(){
  vector<int> f(p.size());
  for(int i = 1; i < (int)p.size(); i++){
    int j = f[i-1];
    while(j > 0 && p[i] != p[j]) j = f[j-1];
    if(p[i] == p[j]) f[i] = ++j;
  }
  return f;
}

void solve(){
  int j = 0;
  for(int i = 0; i < (int)t.size(); i++){
    while(j > 0 && t[i] != p[j]) j = f_func[j-1];
    if(t[i] == p[j]) j++;
    if(j == (int)p.size())
      ans.push_back(i + 1 - j);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  getline(cin, t);
  getline(cin, p);
  
  f_func = failure();
  solve();
  
  cout << ans.size() << '\n';
  for(int a : ans) cout << (a + 1) << ' ';
}