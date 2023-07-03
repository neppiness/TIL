#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int kMax = 1e9;

vector<string> com;
stack<int> st;
string s;

bool err = 0;

void cominput() {
  while (1) {
    getline(cin, s);
    if (s == "END") return;
    com.push_back(s);
  }
}

void Pop() {
  if (st.empty()) { err = 1; return; }
  st.pop();
}

void Inv() {
  if (st.empty()) { err = 1; return; }
  st.top() = -st.top();
}

void Dup() {
  if (st.empty()) { err = 1; return; }
  st.push(st.top());
}

void Swp() {
  if (st.size() < 2) { err = 1; return; }
  int fir = st.top(); st.pop();
  int sec = st.top(); st.pop();
  st.push(fir); st.push(sec);
}

void Add() {
  if (st.size() < 2) { err = 1; return; }
  int fir = st.top(); st.pop();
  int sec = st.top(); st.pop();
  if (abs(sec + fir) > kMax) { err = 1; return; }
  st.push(sec + fir);
}

void Sub() {
  if (st.size() < 2) { err = 1; return; }
  int fir = st.top(); st.pop();
  int sec = st.top(); st.pop();
  if (abs(sec - fir) > kMax) { err = 1; return; }
  st.push(sec - fir);
}

void Mul() {
  if (st.size() < 2) { err = 1; return; }
  int fir = st.top(); st.pop();
  int sec = st.top(); st.pop();
  ll val = (ll)sec * fir;
  if (abs(val) > kMax) { err = 1; return; }
  st.push((int)val);
}

void Div() {
  if (st.size() < 2) { err = 1; return; }
  int fir = st.top(); st.pop();
  int sec = st.top(); st.pop();
  if (fir == 0) { err = 1; return; }
  st.push(sec / fir);
}

void Mod() {
  if (st.size() < 2) { err = 1; return; }
  int fir = st.top(); st.pop();
  int sec = st.top(); st.pop();
  if (fir == 0) { err = 1; return; }
  st.push(sec % fir);
}

void solve() {
  err = 0;

  int x; cin >> x;
  st = stack<int>(); st.push(x);

  for (string c : com) {
    stringstream ss(c);
    string command;
    ss >> command;
    if (command == "NUM") { int no; ss >> no; st.push(no); }
    else if (command == "POP") Pop();
    else if (command == "INV") Inv();
    else if (command == "DUP") Dup();
    else if (command == "SWP") Swp();
    else if (command == "ADD") Add();
    else if (command == "SUB") Sub();
    else if (command == "MUL") Mul();
    else if (command == "DIV") Div();
    else Mod();
    if (err) break;
  }
  if (st.size() != 1) err = 1;
  if (err) { cout << "ERROR" << '\n'; return; }
  cout << st.top() << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    com.clear();
    getline(cin, s);
    if (s == "QUIT") return 0;
    if (s != "END") {
      com.push_back(s);
      cominput();
    }

    int t; cin >> t;
    while (t--) solve();
    cin.ignore();
    getline(cin, s);
    cout << '\n';
  }
}