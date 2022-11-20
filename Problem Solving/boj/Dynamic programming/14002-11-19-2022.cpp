#include <bits/stdc++.h>
using namespace std;

const int MX = 1002;

int n;
int b[MX], rnk[MX];

void solve() {

}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> b[i];

  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++) {
      if(b[j] > b[i]) rnk[j]++;
    }

  for(int i = 0; i < n; i++)
    cout << rnk[i] << '\n';
}
