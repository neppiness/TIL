#include <bits/stdc++.h>
using namespace std;

int pieces[] = {1, 1, 2, 2, 2, 8};

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n, cnt = 6;
  for(int i = 0; i < cnt; i++) {
    cin >> n;
    cout << pieces[i] - n << ' ';
  }
}