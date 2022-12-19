#include <bits/stdc++.h>
using namespace std;

vector<int> a;

bool bs(int x) {
  int st = 0, en = a.size() - 1;
  while(st < en) {
    int mid = (st + en) / 2;
    if(a[mid] < x) st = mid + 1;
    else en = mid;
  }
  return a[st] == x;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while(n--) {
    int x; cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());

  cin >> n;
  while(n--) {
    int x; cin >> x;
    cout << bs(x) << '\n';
  }
}