#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int mx;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  stack <int> st;
  int x;
  while(n--) {
    cin >> x;
    st.push(x);
  }
  st.push(INF);
  
  
}
/*
1번 건물에서 2, 3, 4번 옥상을 확인할 수 있는 이유는
이들이 1번 건물보다 낮기 때문이다.
1번 건물이 12를 확인하는 순간 지금껏 쌓았던 거 다 뱉음

앞 건물이 더 높으면 st에 들어가면 됨



2번 건물의 경우, 10, 3을 쌓고 있다가
7이 오면, st의 최상위 값을 확인하고 반환.
이때 값은 

[7]번 건물 높이는 INF라고 하자

*/