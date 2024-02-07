#include <bits/stdc++.h>
using namespace std;

int n, k;
int b[14][14];
int p[14][14][4];

pair<int, int> coord[12];
int d[12], fl[12];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_ended = 0;

bool isblocked(int x, int y) { return (x < 1 || x > n || y < 1 || y > n || b[x][y] == 2); }

int changedir(int dir) {
  if (dir == 0) return 1;
  if (dir == 1) return 0;
  if (dir == 2) return 3;
  return 2;
}

int findvct(int x, int y) {
  for (int i = 0; i < 3; i++)
    if (!p[x][y][i]) return i;
  return 3;
}

void move(int cur) {
  auto [cx, cy] = coord[cur];
  int &dir = d[cur];

  int nx = cx + dx[dir];
  int ny = cy + dy[dir];
  if (isblocked(nx, ny)) {
    dir = changedir(dir);
    nx = cx + dx[dir];
    ny = cy + dy[dir];
    if (isblocked(nx, ny)) return;
  }

  int idx = fl[cur];
  int nvctidx = findvct(nx, ny);
  int cvctidx = findvct(cx, cy);

  if (b[nx][ny] == 1) {
    for (int i = cvctidx - 1; i >= idx; i--, nvctidx++) {
      if (nvctidx == 3) { is_ended = 1; return; }
      int id = p[cx][cy][i];
      p[nx][ny][nvctidx] = id;
      p[cx][cy][i] = 0;
      coord[id] = {nx, ny};
      fl[id] = nvctidx;
    }
  } else {
    for (int i = idx; i < cvctidx; i++, nvctidx++) {
      if (nvctidx == 3) { is_ended = 1; return; }
      int id = p[cx][cy][i];
      p[nx][ny][nvctidx] = id;
      p[cx][cy][i] = 0;
      coord[id] = {nx, ny};
      fl[id] = nvctidx;
    }
  }
}

int play() {
  for (int t = 1; t <= 1000; t++) {
    for (int id = 1; id <= k; id++) {
      move(id);
      if (is_ended) return t;
    }
  }
  return -1;
}

void setup() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> b[i][j];

  for (int id = 1; id <= k; id++) {
    int x, y, dir;
    cin >> x >> y >> dir;
    coord[id] = {x, y};
    d[id] = dir - 1;
    p[x][y][0] = id;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup();
  cout << play();
}


/*
isblocked(int, int)
- 행과 열의 인덱스는 1이상 n이하의 값을 갖는다.
- 그러므로, 1보다 작거나 n보다 큰 값은 체스판을 벗어나는 경우다
- 이는 이동할 칸이 파란색일 때와 동일하다.
- 따라서, b[x][y]가 2인 경우도 참을 반환한다.
*/

/*
changedir(int)
- 방향을 반대로 바꿔야 하는 경우를 구현.
- dir이 0인 경우 반대 방향은 dir이 1인 경우이다. 반대로 dir이 1이면 반대 방향은 dir이 0이다.
- dir이 2인 경우 반대 방향은 dir이 3이다. 반대로 dir이 3인 경우면 반대 방향은 dir이 2이다.
*/

/*
findvct(int, int)
- 빈칸을 찾는다.
- p의 인덱스는 0부터 쌓인다. 빈칸 인덱스는 0부터 3까지 유효하다.
- 배열의 크기가 4여서 0-3까지만 가지는 것이기도 하지만, 인덱스 3이 빈 칸이 아니게 되는 경우
  4개의 원소가 쌓이는 것이기 때문에 게임을 마쳐야 한다.
- x, y 값을 받아서 p[x][y][i]가 0이면 해당 인덱스를 리턴한다.
- 0부터 2까지 빈 값을 찾지 못했다면, 반드시 비어있는 값인 3을 리턴한다.
*/


/*
move(int): 문제가 있는 부분으로 예상되는 함수
- 입력 인수는 cur, 현재 옮기는 말의 id이다.
- coord에서 현위치인 cx, cy를 추출한다.
- dir는 d[cur]의 별칭(alias)으로 설정해 움직이려는 말의 진행 방향을 받는다.
- 현 방향에서 nx, ny
*/
/*
setup()
- n과 k를 받는다. 1부터 n까지 돌아보면서 보드(b배열)를 채워넣는다.
- 1부터 k까지 돌면서 현위치를 행, 열, 방향 순서대로 받는다.
- 방향은 1부터 4까지 값이며, 1-4는 우좌상하를 의미한다.
- 행번호는 아래로 갈수록 커지기 때문에, '하'는 (1, 0) 방향이다.
- d 배열에는 말의 id로 인덱싱되는 방향 값이 할당된다.
- p[x][y][0]로, 0번 인덱스에 배치되며, id값을 할당한다.
*/
/*
play()
- k개의 말을 차례차례 움직이다. 모든 말이 움직일 때마다 턴이 하나씩 증가한다.
- 중간에 말이 4개 이상 쌓여서 is_ended가 1이 되면 턴을 반환한다.
- 1부터 1000까지 천 번의 턴을 진행하며, 1001번째 턴을 진행해야 할 때는 깨고 나와서 -1을 반환한다.
*/

/*
main()
- setup() 함수를 실행한 뒤 play() 함수를 실행시킨 뒤 반환 값을 출력한다.
*/

/*
piece placement, pp[x][y][h]
piece info: x, y, idx, dir
42번째 줄: 결정된 방향 갱신
47번째 줄: 4개 이상 쌓인다는 조건 구현
setup()의 이중 for문 내부 fill(pp[i][j], pp[i][j] + 4, -1);은
memset(pp, -1, sizeof(pp));로 대체 가능하다.
*/