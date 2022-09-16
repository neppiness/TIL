#include <bits/stdc++.h>
using namespace std;

char lc[30], rc[30];
int n;

void traverse(char cur, int order) {
  int idx = cur - 'A';
  if(order == 0) cout << cur;
  if(lc[idx] != '.') traverse(lc[idx], order);
  if(order == 1) cout << cur;
  if(rc[idx] != '.') traverse(rc[idx], order);
  if(order == 2) cout << cur;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while(n--) {
    char p, l, r;
    cin >> p >> l >> r;
    lc[p - 'A'] = l;
    rc[p - 'A'] = r;
  }

  for(int i = 0; i < 3; i++) {
    traverse('A', i);
    cout << '\n';
  }
}