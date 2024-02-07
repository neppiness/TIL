#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cur, nxt;
  bool isascending = 1;
  bool isdescending = 1;

  cin >> cur;
  for(int i = 0; i < 7; i++){
    cin >> nxt;
    if(cur < nxt) isdescending = 0;
    if(cur > nxt) isascending = 0;
    swap(cur, nxt);
  }
  if(isascending) cout << "ascending";
  else if(isdescending) cout << "descending";
  else cout << "mixed";
}