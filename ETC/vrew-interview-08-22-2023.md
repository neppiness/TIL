## Vrew 데스크탑 앱 개발자 자격 조건 질문들
### Virtual Memory란?
* 가상 메모리로, 운영체제에서 메모리를 관리하기 위한 기술(기술이라고 해야할지도 좀 생각해봐야 할 듯)
* 실제 메모리 주소와 가상의 메모리 주소를 매핑한 후에 프로그램은 연속된 메모리를 활용하는 것처럼 쓸 수 있도록 하는 것

### Semaphore란?
* 임계영역 문제(critical-section problem)
  - N개의 프로세서가 실행 중인 시스템을 생각하자.
    + 각 프로세스는 코드 영역이 있으며.
    + 이중 프로세스가 접근되고 갱신되고 데이터가 적어도 하나 이상의 다른 프로세스와 공유되는 영역을 임계영역이라 한다.
  - 임계영역에 동시에 들어갈 수 없도록 해 동시성 문제가 발생하지 않도록 제어
  - 임계영역에 들어가기 위해선 승인이 필요하다.
* 선점식 커널과 비선점식 커널
  - 일단 커널이 무엇인지 알아야 할 듯.
  - 비선점식에서는 한 번에 하나만 처리하기 때문에 임계영역 문제도 발생하지 않음.
  - 그러나, 선점식은 완전히 점유하고 사용하지 못하기 때문에 긴 시간이 걸리는 작업 때문에 그 작업만 처리하느라 다른 것들을 하나도 처리하지 못하는 상황이 발생하지 않는다.

* 임계영역 문제에 대한 해결법
  - 물리적 장치: 메모리 배리어, 하드웨어 연산자(hardware instructions), 아토믹 변수
  - 뮤텍스 락: 6.5절 270페이지. 이에 대해 공부해볼 것.
  - 세마포어: 6.6절 272페이지. 이에 대해서 공부해볼 것.

* 뮤텍스 락
  - 임계영역에 진입하면 락이 걸리고, release가 일어나 락이 사용가능해지면 acquire 명령이 락을 걺
  - 이는 busy waiting 특성에 의해 CPU 싸이클을 낭비한다는 게 가장 큰 단점
  - 이를 보완하기 위한 spin lock을 사용하기도 함

* 세마포어
  - S라는 정수 변수를 놓고, atomic function인 wait()과 signal()로만 해당 변수 값을 변경할 수 있게 구현하자.
  - 시그널을 발생시켜서 현재 가용한 자원의 수를 늘리면 wait()에서 대기 중이던 프로세스 중에서 가장 빠르게 처리된 곳에서 S--;를 호출하여 나머지는 대기 상태에 머물도록 만든다.
  - binary와 counting 세마포어가 구분된다.
    + binary 세마포어의 경우 뮤텍스 락에 가까움.
  - 이 세마포어를 통해서 순차적으로 끝나는 서로 다른 프로세스를 동기화시킬 수도 있다.
  - 그러나 여전히 상태를 확인하며 busy waiting 한다.
  - 대기 상태를 주고, 큐에 넣어서 스케쥴링 전략에 따라 프로세스를 처리하게 하면 된다.
    + 그러나, 중간에 인터럽트가 발생하면 문제가 생긴다고 하는 듯.
    + 싱글 코어 프로세서에선 문제 없지만, 멀티 코어 프로세서에선 인터럽트 자체를 막아야 한다고 함.
  - wait()과 signal()이 여전히 busy waiting이지만, 이를 critical section으로 가져왔다는 게 중요
    + 그리고, 이 섹션이 짧다면 짧은 시간 내로 처리해서 busy waiting의 비효율성이 덜 드러남
    + 그러나, 이 섹션이 길다면 굉장히 비효율적으로 시스템이 동작하게 됨.

### Cache란?
* 캐시는 기본적으로 바로 가져다가 쓸 수 있도록 임시로 저장해두는 메모장과 같은 것.
* CPU 측면에서는 계산에 필요한 데이터들을 임시 공간에 저장해서 바로 꺼내다가 쓸 수 있도록 하는 것이며, 연산 성능에 직결된다.
* 웹 캐시: 웹 페이지에서도 이전 요청에 대한 데이터를 저장해서 다시 호출됐을 때 네트워크를 통하지 않고 빠르게 로컬 저장소를 통해 해당 자료를 불러올 수 있다. 이를 웹 캐시라 한다.
* 메모이제이션: DP 기법을 활용할 때, 이전 계산 결과를 저장해서 배열 상에서 O(1)로 호출이 가능하다. 이 또한 캐시 기법이다.

### Garbage Collection이란?
* 메모리 4영역 중 힙 영역에서는 데이터의 동적 할당이 일어남.
  - 해당 메모리가 해제되거나 더이상 참조당하지 않는 상태가 되면 이를 정리해서 가용한 공간으로 만드는 과정이 필요. 이를 가비지 컬렉션이라 한다.
  - 가비지 컬렉션은 가비지 컬렉터에 의해서 수행된다.
  - C++과 같은 경우엔 직접 할당을 해제해야 함. C++ 11부터 GC에 대한 말이 나오지만 실제로 이를 구현한 컴파일러는 없다고 함.
* 이를 통해 자동으로 메모리 관리를 수행할 수 있음. 이 경우, 몇 가지 문제를 해결해줌.
  - 매달린 포인터(dangling pointers): 포인터를 없애기 전에 해당 데이터의 할당을 해제하는 경우, 가리키는 게 없는 상태로 포인터는 잔류하게 된다. 그 공간에 변수가 할당되면 버그가 발생할 수 있다.
  - 이중 할당 해제 버그(double free bugs): 이미 할당 해제된 변수를 또 할당하는 버그를 막는다.
  - 몇몇 종류의 메모리 누수: 자동으로 참조되지 않는 데이터를 자동으로 해제해주기 때문에 이런 문제도 막을 수 있다.
* 작동 방식에 따른 분류
  1. 추적 기반 가비지 컬렉션(Tracing Garbage Collection)
    + 점진적 쓰레기 수집(Incremental Garbage Collection)
    + 세대별 쓰레기 수집(Generational Garbagae Collection)
  2. 참조 횟수 기반 가비지 컬렉션(Referencing Counting Based Garbage Collection)

* [Java Garbage Collection Basics](https://www.oracle.com/webfolder/technetwork/tutorials/obe/java/gc01/index.html)


### Database Index 추가의 장단점은?
* 그냥 새롭게 공부가 필요한 부분.

### NoSQL의 장단점은?
* 스키마 없이 사용할 수 있어서 자유도가 높다.(이게 특징이지 장점이나 단점이라고 할 수 있는진 모르겠음)

### 공유기의 원리는?
* 사설 네트워크의 게이트웨이 역할을 수행함
* 어떤 것들을 통해 구성되는지는 공부해야 함.
:
### HTTP/2의 특성은?
* HTTP/2는 TCP/IP 기반이며, 1.1보다 개선되었음.
> 어떤 점이 개선되었는지 확인해보자.

### 비대칭 암호화란?
* 뭘 뜻하는지 모름.

### Node.js의 특징은?
* 컴파일 어쩌구 V8 엔진을 사용 어쩌구.
* 

### HDD, SSD, DRAM 각각의 성능은?
* HDD, SSD, DRAM 순으로 읽기 쓰기 속도가 빨라짐.
* 모든 저장장치가 공통적으로 세대가 지날수록 빨라지고 있긴 함.
* 현재는 어느정도의 속도인지 공부해서 비교해야 함.
* SSD의 경우 SATA 형식과 nvme 형식으로 구분됨. 인터페이스에 따라 속도가 다름.
  - MLC, TLC, QLC 형식에 따라서 또 다름. 이는 쓰기 수명과 관련이 있던 걸로 기억함

### Memory Leak 디버깅은?
* 아는 바 없음.

### GIT의 장점은?
* 특징부터 언급을 해야함.
* 또, 장점을 말하려면 다른 버전 컨트롤 시스템과의 비교를 수행할 수밖에 없음.

### UTF-8 이란?
* 텍스트 인코딩 방식. 좀 더 자세하게 공부하기.

### React 란?
* 자바스크립트 기반 프론트엔드 개발에 주력하는 언어라고만 알고 있음.

### Web Browser 의 프로세싱 중 Reflow 란?
* 모름


### 함수형 프로그래밍 패러다임이란?
* 순수함수를 정의하고 들어감.
* 그래서 이 순수함수를 활용하는 게 함수형 프로그래밍인가? 이에 대해선 정리를 해야하고,
* 이터러블에 고차함수를 적용해서 순회하며 작업하는 방식이 함수형 프로그래밍 패러다임을 적용한 것이라 얘기할 수는 있을 텐데, 그것으로 끝나면 안 될 듯.


### Callback hell 이란?
* 자바스크립트의 경우, 비동기처리 시 다른 워커에 일을 할당하고 진행하게 됨.
* 이 워커가 일을 끝내면 호출할 콜백함수를 설정할 수 있음.
* 그 콜백함수를 비동기처리로 하면 또 비동기처리를 마친 뒤에 수행할 콜백함수가 들어가게됨.
* 이와 같은 콜백함수가 꼬리에 꼬리를 물고 연결되어 가독성도 떨어지고, 무슨 일이 일어나는지 파악하기 어려운 상태가 되면 이를 callBack 지옥이라함.

### async I/O 란?
* 시스템 상 입출력을 비동기적으로 처리한다는 의미.

### 프로세스 간 통신(IPC) 이란?
* 프로세스들이 

### C++ 에서 다형성이란?
* [씹어먹는 C++ - <6 - 2. 가상(virtual) 함수와 다형성>](https://modoocode.com/210)
* 다형성이 뭔가?
  - 같은 이름의 메소드가 여러가지 다른 작업들을 하는 것
  - '나비'가 애벌레, 번데기, 성충에 이르기까지 모든 과정을 '나비'라는 이름으로 묶듯, 하나의 인터페이스로 여러 타입을 나타내는 것을 뜻함.

* C++에서 이를 어떻게 활용하나?
  - 가상 함수와 상속을 활용해서 구현함

```cpp
#include <bits/stdc++.h>
using namespace std;

class Base {

 public:
  Base () {
    cout << "Base Class instance constructed\n";
  }

  virtual void what() {
    cout << "what() method of Base Class\n";
  }
};

class Derived : public Base {

 public:
  Derived() : Base() {
    cout << "Derived Class instance constructed\n";
  }

  void what() {
    cout << "what() method of Derived Class\n";
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  Base parent;
  Derived child;

  Base* pt_par = &parent;
  Base* pt_ch = &child;

  pt_par->what();
  pt_ch ->what();
}
```

* 위와 같이 하면 아래 결과가 출력됨

```
Base Class instance constructed
Base Class instance constructed
Derived Class instance constructed
what() method of Base Class
what() method of Derived Class
```

* Base의 포인터로 Derived 객체를 가리킬 수가 있고, 여기서 호출된 메소드는 런타임에 Derived의 what을 가져오게 됨.
  - 먼저 Base의 포인터니 Base의 what()을 실행하고자 함
  - 여기서 what() 메소드가 virtual 메소드인 것을 확인
  - 이후 실제로 Base 타입인지 확인함. 이후 Derived 클래스 객체임을 확인
  - Derived의 what() 메소드가 실행됨.
* 클래스 레벨에서 override 키워드를 사용하면 해당 메소드가 가상 함수를 오버라이드했음을 명시적으로 표현 가능함.

```cpp
class Base {
 public:
  Base() { cout << "Base Constructor\n"; }

  virtual void what() { cout << "WHAT? of Base\n"; }
};

class Derived : public Base {
 public:
  Derived() : Base() { cout << "Derived Constructor\n"; }

  void what() override { cout << "WHAT? of Derived\n"; }
};
```


### 그래픽카드를 이용한 하드웨어 가속이란?
* 그래픽카드의 빠른 연산을 활용해 기능을 돕는다- 정도 밖에 모르겠음. 검색해야 할 듯.
