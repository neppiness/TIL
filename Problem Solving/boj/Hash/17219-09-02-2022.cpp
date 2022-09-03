#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map <string, string> sitepw;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  while(N--){
    string site, pw;
    cin >> site >> pw;
    sitepw[site] = pw;
  }
  while(M--) {
    string site;
    cin >> site;
    cout << sitepw[site] << '\n';
  }
}