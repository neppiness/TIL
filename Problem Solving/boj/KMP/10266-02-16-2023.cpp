#include <bits/stdc++.h>
using namespace std;

const int M = 360'000;
const int MX = 200'000 + 2;

int a[MX], b[MX];
int n;

vector<int> failure() {
  vector<int> f(n);
  int j = 0;
  for(int i = 1; i < n; i++) {
    while(j > 0 && a[i] != a[j]) j = f[j - 1];
    if(a[i] == a[j]) f[i] = ++j;
  }
  return f;
}

bool is_matched() {
  vector<int> fa = failure();

  int j = 0;
  for(int i = 0; i < 2*n - 1; i++) {
    int ci = i;
    if(ci >= n) ci -= n;
    while(j > 0 && b[ci] != a[j]) j = fa[j - 1];
    if(b[ci] == a[j]) j++;
    if(j == n) return 1;
  }
  return 0;
}

void setup() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];

  sort(a, a + n);
  sort(b, b + n);

  a[n] = a[0] + M;
  b[n] = b[0] + M;

  for(int i = 0; i < n; i++) {
    a[i] = a[i + 1] - a[i];
    b[i] = b[i + 1] - b[i];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup();
  
  if(is_matched()) cout << "possible";
  else cout << "impossible";
}