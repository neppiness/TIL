#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ispr[100'000'002];
set<int> pr;

void setup() {
  fill(ispr + 2, ispr + 100'000'001, 1);
  for (ll i = 2; i * i <= 100'000'000; i++) {
    if (!ispr[i]) continue;
    pr.insert(i);
    for (ll j = i; j * i <= 100'000'000; j++)
      ispr[j * i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup();
  int a, b; cin >> a >> b;
  
}