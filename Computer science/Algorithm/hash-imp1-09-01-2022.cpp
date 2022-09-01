#include <bits/stdc++.h>
using namespace std;

int M = 6;
int cur = 0;

int hf(string str) {
  int n = 0; 
  for(auto c : str) {
    n *= 1000;
    n += c;
  }
  return (n % M)/M;
}

void hashIns(vector<pair<string, int>>& hs, string str, int value) {
  hs.push_back({str, value});
  cur++;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int N; cin >> N; // the amount of input data
  int pre[N], nxt[N];
  fill(pre, pre + N, -1);
  fill(nxt, nxt + N, -1);

  vector<pair<string, int>> hash;
  
  string str;
  int value;
  hashIns(hash, str, value);
}