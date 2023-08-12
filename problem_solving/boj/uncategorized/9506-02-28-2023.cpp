#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while(n != -1) {
    ans.clear();
    int sum = 0;
    for(int i = 1; i < n; i++) {
      if(n % i != 0) continue;
      sum += i;
      ans.push_back(i);
    }
    if(n != sum) cout << n << " is NOT perfect." << '\n';
    else {
      cout << n << " = " << ans[0];
      for(int i = 1; i < ans.size(); i++)
        cout << " + " << ans[i];
      cout << '\n';
    }
    cin >> n;
  }
}