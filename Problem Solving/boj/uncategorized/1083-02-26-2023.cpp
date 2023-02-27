#include <bits/stdc++.h>
using namespace std;

int n, s, a[52];
bool is_sorted[52];

void try_sort() {

}

void greedy_sort() {
  for(int i = 1; i < n; i++) {
    if(a[i] < a[i - 1]) continue;
    swap(a[i], a[i - 1]);
    return;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  cin >> s;

  try_sort();
  while(s--) greedy_sort();

  for(int i = 0; i < n; i++)
    cout << a[i] << ' ';
}