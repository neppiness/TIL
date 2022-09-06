// #include <iostream>
// #include <set>
// #include <vector>
// #include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int n, k;
int m, v, c;
multiset<int> bags;
pair<int, int> jewel[300003];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> m >> v;
    jewel[i] = {v, m};
  }

  for(int i = 0; i < k; i++) {
    cin >> c;
    bags.insert(c);
  }

  sort(jewel, jewel + n);
  long long ans = 0;

  for(int i = n - 1; i >= 0; i--) {
    int wei, val;
    tie(val, wei) = jewel[i];
    auto bagsit = bags.lower_bound(wei);
    if(bagsit == bags.end()) continue;
    ans += val;
    bags.erase(bagsit);
  }
  cout << ans;
}