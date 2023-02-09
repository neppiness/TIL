#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
const int MX = 1'000'000;

int unused = 2;
int nxt[MX][26]; // 
bool term[MX];

int toInt(char c) { return (int)(c - 'A'); }

void ins(string& s) {
  int cur = ROOT;
  for(char c : s) {
    if(nxt[cur][toInt(c)] == -1)
      nxt[cur][toInt(c)] = unused++;
    cur = nxt[cur][toInt(c)];
  }
  term[cur] = 1;
}

int find(string& s) {
  int cur = ROOT;
  cout << cur << ' ';
  for(char c : s) {
    int nx = nxt[cur][toInt(c)];
    if(nx == -1) return -1;
    cur = nx;
    cout << cur << ' ';
  }
  cout << '\n';
  if(term[cur]) return cur;
  else return -1;
}

void del(string& s) {
  int tar = find(s);
  if(tar != -1) term[tar] = 0;
}

void test() {
  string obj[] = {"APPLE", "APPLY", "BANANA", "BLACK", "BAN"};
  for(int i = 0; i < 5; i++)
    ins(obj[i]);

  for(int i = 0; i < 5; i++)
    find(obj[i]);
    
  for(int i = ROOT; i < 18; i++)
    cout << term[i] << ' ';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(nxt, -1, sizeof(nxt));

  test();
}