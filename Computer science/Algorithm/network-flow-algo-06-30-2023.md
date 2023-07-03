[TIL on June 30th, 2022](/TIL/2023/06/06-30-2023.md)
# **Network Flow Algorithm**
### 개요
* 네트워크 유량 문제를 해결하는 가장 기초적인 방법
* 유량 네트워크의 모든 간선의 유량을 0으로 두고 시작해, 소스에서 싱크로 유량을 더 보낼 수 있는 경로를 찾아 유량을 보내기를 반복함.

### 용어 정리
* 유량을 보내는 경로를 증가 경로(augmenting path)라고 함.
* 간선의 용량과 유량의 차이를 잔여 용량(residual capacity)이라고 함.
* 증가 경로를 통해 흘려보낼 수 있는 최대 유량은 포함된 간선의 잔여 용량 중 최솟값으로 결정됨.
* 최대 유량을 계산할 때 유량의 대칭성을 활용함.

### 코드: 에드몬드-카프 알고리즘의 구현
```cpp
const int kInf = 0x7f7f7f7f;
const int kVmax = 700 + 2;

// flow는 흐름 현황을 기록함.
// cap에는 수용 가능한 유량을 기록.
// 값이 -kInf면 절대로 이 통로로 물이 흐르지 않으니 초기화 값을 -kInf로 설정
// 1-indexed인 경우를 생각하자.
int v, flow[kVmax][kVmax], cap[kVmax][kVmax];
queue<int> q;

int networkFlow(int source, int sink) {
  memset(flow, 0, sizeof(flow));
  int totFlow = 0;
  while(1) {
    q = queue<int>(); // 큐를 중간에 비우지 않고 나오는 경우가 발생하기 때문에 시작할 떄는 비워줘야 함.
    int prv[kVmax];
    memset(prv, 0, sizeof(prv));
    // 이 과정을 vector<int> p(kVmax, -1);로 간단히 씀
    // 이 부분은 배워야 하지 않을까.
    // 어차피 배열이나 똑같이 쓸 건데 굳이 memset이나 fill을 쓸 이유도 없음.
    prv[source] = -1; q.push(source);
    // BFS 스패닝 트리 만들기
    // q가 비지 않고, sink의 부모가 결정되지 않은 동안 아래와 같이 동작
    // sink에 도달했을 때 자르는 게 중요.
    while (!q.empty() && !prv[sink]) { 
      int cur = q.front(); q.pop();
      for (int nxt = 1; nxt <= v; nxt++) {
        if (prv[nxt]) continue;
        if (cap[cur][nxt] - flow[cur][nxt] <= 0) continue;
        q.push(nxt); prv[nxt] = cur;
      }
    }
    if (!prv[sink]) break;
    int amount = kInf;
    for (int cur = sink; cur != source; cur = prv[cur])
      amount = min(cap[prv[cur]][cur] - flow[prv[cur]][cur], amount);

    for (int cur = sink; cur != source; cur = p[cur]) {
      flow[p[cur]][p] += amount;
      flow[p][p[cur]] -= amount;
    }
    totFlow += amount;
  }
  return totFlow;
}
```

* BFS 트리를 만들고, 부모 노드를 기록한 다음에 역추적하면서 flow를 기록.
  - cap은 2차원 배열로, -kInf로 초기화한 다음, 값을 부여.
  - u -> v인 cap과 v -> u인 cap을 같게 둠.