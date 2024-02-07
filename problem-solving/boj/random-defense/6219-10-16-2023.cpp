#include <bits/stdc++.h>
using namespace std;

bool is_prime[4'000'002];
vector<int> pr;
int cnt, a, b, d;

bool hasD(int p) {
  for (; p != 0; p /= 10)
    if (p % 10 == d) return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(is_prime, is_prime + 4'000'002, 1);

  for (int i = 2; i <= 4'000'000; i++) {
    if (!is_prime[i]) continue;
    pr.push_back(i);
    for (long long j = i; j * i <= 4'000'000; j++)
      is_prime[j * i] = 0;
  }

  cin >> a >> b >> d;

  for (auto p : pr) {
    if (p < a || p > b) continue;
    cnt += hasD(p);
  }
  cout << cnt;
}
