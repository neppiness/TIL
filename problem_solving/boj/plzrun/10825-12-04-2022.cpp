#include <bits/stdc++.h>
using namespace std;

struct Student {
  string name;
  int kr;
  int en;
  int ma;
};

bool cmp(Student l, Student r) {
  if(l.kr != r.kr) return l.kr > r.kr;
  if(l.en != r.en) return l.en < r.en;
  if(l.ma != r.ma) return l.ma > r.ma;
  return l.name < r.name;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<Student> students;

  int n; cin >> n;

  string s; int k, e, m;

  Student stu;
  for(int i = 0; i < n; i++) {
    cin >> s >> k >> e >> m;
    stu.name = s;
    stu.kr = k;
    stu.en = e;
    stu.ma = m;
    students.push_back(stu);
  }

  sort(students.begin(), students.end(), cmp);
  for(auto it = students.begin(); it != students.end(); it++)
    cout << (*it).name << '\n';
  }