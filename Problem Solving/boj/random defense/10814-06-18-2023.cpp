#include <bits/stdc++.h>
using namespace std;

struct mem {
  int age, seq;
  string name;

  mem(int age_, string name_, int seq_):
      age(age_), name(name_), seq(seq_) {}

  bool operator < (const mem &rt) const {
    if (age == rt.age) return seq < rt.seq;
    return age < rt.age;
  }
};

int n;
multiset<mem> ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int a; string s;
    cin >> a >> s;
    ans.insert(mem(a, s, i));
  }

  for (mem m : ans)
    cout << m.age << ' ' << m.name << '\n';
}