#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll len[3];
  while(1){
    for(int i = 0; i < 3; i++) cin >> len[i];
    if(len[0] == 0) break;
    sort(len, len + 3);
    if(len[2]*len[2] == len[0]*len[0] + len[1]*len[1]) cout << "right" << '\n';
    else cout << "wrong" << '\n';
  }
}