#include <bits/stdc++.h>
using namespace std;

vector<int> f_fun;
string a, w, s;

vector<int> failure(){
  vector<int> f(w.size());

  return f;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    cin >> a >> w >> s;
    f_fun = failure();
    vector<int> ().swap(f_fun);
  }
}