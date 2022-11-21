[TIL on November 21st, 2022](../../TIL/2022/11/11-21-2022.md)
# **Vol. 1: Issue #1 to #4**
This article is written in English, so I'm going to translate and write down in Korean

## Issue #1: How to read problem statements
### 기본 규칙
- 일반적으로 지문을 이해한 후 남는 것은 순수한 수학 모델이다.
- 서술된 이야기가 이해를 돕는다면 계속 읽어도 되지만, 불필요한 세부 내용은 버리는 게 좋다.
- 다른 사람에게 설명할 때 어떤 부분을 얘기할지 상상해보자(도움 안 될 수 있음).
- 짧고 단순할수록 좋다.
- 제한 사항은 지문의 일부다. 특히 작은 데이터의 경우엔 모든 가능성을 테스트할 수 있다.
- 예제는 문제의 일부로, 수학 모델을 만든 뒤 그 모델이 올바르게 동작하는지 확인하라. 특별히 작은 예제의 경우, 해당 모델이 어떻게 동작하는지 확인할 수 있어 효율적이다.
- 메모 역시 문제의 일부이다.
- 이미 네가 알고 있을 법한 익숙한 패턴을 찾고자 해라.
  * 예로, *모든 정점 쌍이 하나의 단순한 경로를 갖는 어떤 연결 그래프*를 **트리**라 한다.
- 예상치 못한 뭔가를 찾으려 해라. 그 문제의 초석이 될 수 있다.
- 네가 지문의 어떤 부분이 맘에 들지 않았다면 맘에 들게 바꾸려 해봐라. 대상을 이해하고 단순화해라. 이를 통해 완전히 해결 가능한 문제들도 있다.
- 만약 지문을 해석하고 얻은 모델이 너무 크다면(간단히 구현할 수 없다면), 작은 문제로 쪼개라. 만약 문제들이 독립적이라면 더 좋다.
- 초기에는 종이에 손으로 새로운 지문을 작성해보는 것도 유용할 수 있다.
- 출제자는 지문에 쓸데없는 것을 두지 않는다.

### 저자가 새로 작성해본 지문 예시
- Given undirected graph, find its spanning tree with minimal diameter.
- Given a tree, each vertex has some subset of universe of size m. Find such a path that disjoint union of subsets of vertices on this path is universe.
- Given an undirected graph with at most 14 (small=important) vertices. Build a bipartite graph: left part is vertices, right part — all simple cycles. Find the minimal number of matchings to cover all the edges.
- 문제를 읽으면서 어떤 모델로 접근할지 자문자답하며 풀어감


## Issue #2: How to come up with the solutions: techniques
- 문제를 읽었는데 풀이가 떠오르지 않는다면 아래 방법들을 살펴보라.

### 기술 1: Total Recall
- 풀었던 문제 중 비슷한 문제가 있었나 돌아봐라

### 기술 2: 지엽적인 것에서 일반적인 것으로
- 풀이를 찾았다고 하자. 먼저 일부 입력에 대해 풀리는지 확인한다.
- 간단한 풀이부터 접근한다 생각하면 됨.
- 특수한 경우로 접근하는 게 쉬울 거란 보장은 없으니 주의

### 기술 3: Bold Hypothesis (대담히 가정하라)
- 대담하게 직관을 따라 가설을 세워봐라.
- 구현하기 전에 다양한 경우에 대해 가설을 검증해봐라. 

### 기술 4: 문제를 풀기 위해서 문제처럼 생각해라
- 지문 내 인물이 되어봐라. 이를 어떻게 해결할 수 있을지 고민해봐라. 이미지를 떠올리고 풀이를 상상하라.

### 기술 5: 같이 생각해봐라
- 팀으로 문제를 풀 때는 함께 자명한 사실들을 나열해봐라.

### 기술 6: 방법을 골라라
- 문제에 적용될 만한 방법을 골라라. 그리고 그 문제로 접근해봐라.

### 기술 7: 출력하고 확인하라.
- 풀이 답을 음미하고 의미하는 바를 찾아라.

### 기술 8: 구글링
- 풀이를 볼 수 있는 대회라면 검색을 동원하라.


## Issue #3: Characteristics of the optimal solution, a technique for finding observations in a problem

### 도입부
- 문제를 잘 푸는 사람들과의 차이는 생각하는 법에서 나온다.
- 저자는 이 방법을 적용해서 정리된 생각으로 풀어낸 문제들이 있다고 함.

### 기술: 최적해의 특징
- 내가 풀이를 찾았다고 가정하면, 어떻게 생겼을까? 어떤 특징이 있을까? 우리가 조건을 바꾸더라도 여전히 최적일까? 생각해보는 것

해당 글의 예시도 어려워서 아직 어떤 얘긴지 잘 모르겠음. 좀 더 공부한 뒤 보도록 할 것.


## Issue #4: On "is this greedy or DP", forcing and rubber bands

### 도입부
- 보통 문제 풀이 기법이라 하면 3가지로 나뉜다.
1. 확실한 알고리즘(크루스칼, 리-차오, FFT)
2. 일반적 패턴(동적 프로그래밍, 그리디, 제곱근 분해)
3. 메타 전략("이 문제를 어떻게 풀 수 있을까?")

- 일반적으론 이 분류가 유효하다.
- 카탈로그의 많은 튜토리얼이 1이나 2로 나뉜다. 그러나 3번째 분류에 대한 정보는 적다.
- 두 가지 이유가 있을 텐데
  * 문제 잘 푸는 사람들은 그런 거 크게 신경 안 쓴다. 이미 훈련이 되어 있어서 그냥 푸는 것이다. DP나 FFT의 경우는 그걸 썼단 사실을 모를 수가 없는 데 반해 3번째 분류 문제들은 어떻게 풀었는지 남지 않는다.
  * 알고리즘에 대해 쓸 때는 내가 옳단 걸 알기 쉽다. 이를 증명할 수 있다. 그러나, 뭐가 옳고 그른지, 뭐가 유용한지조차 판단하기 어려운 문제가 있다.

### The forcing fallacy: 잘못된 생각을 밀어부치는 경우
- DP나 그리디가 아닌데, 떠오른 풀이를 그냥 강제하는 경우가 있다. 이 경우 오답으로 가기 쉽다.


___

### References
1. [How to read problem statements](https://codeforces.com/blog/entry/62730)
2. [How to come up with the solutions: techniques](https://codeforces.com/blog/entry/20548)
3. [Characteristics of the optimal solution, a technique for finding observations in a problem](https://codeforces.com/blog/entry/99291)