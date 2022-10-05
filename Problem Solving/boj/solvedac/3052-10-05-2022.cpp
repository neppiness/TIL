#include <iostream>
using namespace std;

int rest[42];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a;
  for(int i = 0; i < 10; i++){
    cin >> a;
    rest[a%42]++;
  }
  int ans = 0;
  for(int i = 0; i < 42; i++)
    if(rest[i]) ans++;
  cout << ans;
}