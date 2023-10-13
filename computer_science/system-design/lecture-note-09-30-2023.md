# **Grokking Modern System Design Interview for Engineers & Managers**

# Week #1: 10.01.2023.
## Introduction
* 시스템 설계 컨셉의 구성
  - 분산 시스템(distributed systems)
  - 컴퓨터 네트워킹(computer networking)
  - 병렬 연산(parallel computing)
* 시스템 설계를 통해 목표하는 것
  - Reliable
  - Effective
  - MaintainableByzantine

<br>

## System Design Interviews
* 어떤 컴포넌트를 도입할 때의 트레이드 오프에 대해 말할 것.
  - ex) SQL & noSQL
* 좋은 질문을 해야함(ask refining questions)
* 해결 과정
  - 문제를 정제(refine)함
  - 면접관과 토의(discuss)할 것

<br>

## Abstractions
* 추상화를 통해서 디테일은 감춤.
  - 어떤 일을 하는지만 드러냄
  - 데이터베이스의 트랜잭션
  - 분산 시스템의 추상화
* RPC
  - IPC와 유사. Inter-Process Communication
  - 단지 local에서 일어나는 게 아니라 인터넷을 통해 일어난다는 게 다름
  - 이를 통해 개발자는 내부적으로 어떤 일이 일어나는지 몰라도 분산 시스템을 활용해 프로그램을 개발할 수 있다.
* Spectrum of Consistency Models
  - CAP 이론에 따르면, consistency와 accessibility, parition tolerance는 동시에 높은 수준을 달성할 수 없다고 함.
  - Eventual consistency에서부터 linearizable consistency에 이르기까지 많은 단계의 항상성 레벨이 있음.
  - 어떤 정보를 처리하는가에 따라 이 항상성 수준은 달라진다.
    + 패스워드의 경우, 새롭게 설정하면 곧장 모든 분산 DB에 대해서 갱신이 되어야 한다.
    + 그렇지 않으면, 유저가 장애를 겪을 수도 있고, 이미 알려진 이전 비밀번호로 계정에 접근하는 경우가 발생할 수 있음.
* Spectrum of Failure Models
  - Fail-stop: 노드 하나가 멈춤. 감지 가능.
  - Crash: 노드 하나가 조용히 멈춤. 감지 불가.
  - Omission failures: 메시지를 주거나 받을 때 누락이 발생하는 경우
  - Temporal failures: 계산해서 넘겨주지만 이 정보가 더이상 쓸모 없는 경우
  - Byzantine failures: 에러 등으로 인한 복잡한 실패

<br>

## Non-functional System Characteristics
* Availability: 활용성
  - ((Total time) - (Amount of time service was down)) / (Total time)
  - 산정 방법이 다를 수 있음.
  - 9가 몇 개인지로 표현함: 90%, 99%, 99.9%, ...
* Reliability: 신뢰성
  - 서비스 다운 시 이를 얼마나 신속히 복구하는지-에 대한 지표
  - 높은 신뢰성을 목표로 함
* 활용성과 신뢰성: 둘 다 높은 서비스를 목표로 함.
* Scalability
  - 3가지 확장성
    + Size: 유저나 데이터 수의 증가에 대한 확장성
    + Administrative: 하나의 분산된 시스템을 통해 여러 기관이나 유저가 접근 가능한지에 대한 확장성
    + Geographic: 지리적으로 넓은 영역에 대한 확장 가능성
  - 확장성의 다른 접근
    + 수직적 확장성: 하나의 서버의 성능을 높이는 것
    + 수평적 확장성: 여러 서버를 활용하는 것. 다만, 이들이 하나의 서버처럼 동작해야 함.
* Maintainability
  - 유지보수성의 3가지 속성
    + 동작성: 일반적인 상황에서 잘 동작해야 함. 추가적인 유지보수 필요가 발생하지 않도록 해주는 것.
    + 명료성: 코드가 단순해야 유지보수를 빠르게 수행할 수 있음.
    + 변경용이성: 유지보수를 수행할 때 빠르게 변경이 가능해야 함.
  - 유지보수성 측정
    + 한 건의 유지보수 당 고치는 시간으로 산정
* Fault Tolerance
  - 문제에 대한 내성
  - 사본을 만듦으로 오류에 대응
  - 체크포인팅을 통해 계산을 수행한 내용을 순차적으로 저장하는 등을 수행Put Back-of-the-envelope Numbers in Perspective
    + 이 경우, 관찰하는 시간 간격에 따라서 값이 꾸준히 갱신이 될 수도, 그대로 유지될 수도 있음.
    + 이에 대한 내용은 그림으로 나옴.

<br>

## Back-of-the-envelope Calculations
### Put Back-of-the-envelope Numbers in Perspective
* 대략적으로 서버가 얼마의 일을 처리할 수 있는지 계산하는 과정 설명
* 서버를 웹 서버와 어플리케이션 서버, 스토리지 서버로 나눔.
  - 각각에 필요한 기능에 따라서 메모리 및 CPU 코어 수가 다르게 활용될 수 있음을 설명.

### Example of Resource Estimation
* Twitter의 예로 Outgoing bandwidth와 Incoming bandwidth, 그리고 1년에 증설해야 하는 데이터 사이즈를 가늠함.

<br>

## Building Blocks
### Introduction to Building Blocks for Modern System Design
* 16개 빌딩 블록에 대한 정의

<br>

* 이후로 이어지는 DNS에 대한 내용.

<br>

# Week #2: 10.08.2023.
## Databases
### Introduction to Databases
* DB를 활용하지 않으면 발생하는 문제
  - 파일을 통해 정보를 관리한다고 하면 발생하는 문제들.
    + 직접 생각해보면서 나열된 항목을 떠올려보자.
* DB는 아래와 같은 특성이 있다.
  - 큰 데이터의 저장
  - 데이터 조작이 용이
  - 권한이 있는 사용자만 접근 가능
  - 확장성: 샤딩 등의 기술에 의해서 서버를 늘리는
  - 가용성(availability)이 좋다.

### Types of Databases
* 관계형 데이터베이스
  - ACID 특성.
  - 트랜잭션을 통해서 해당 변화를 커밋할 것인지, 아니면 롤백할 것인지 결정
    + 버전 컨트롤 시스템과 유사하다 생각함.
    + 단, 전후관계를 기록한다고 이해함.
  - 데이터 중복 방지
    + join과 같은 기능을 통해 여러 테이블을 엮을 수 있음.
    + 합친 테이블을 따로 저장하지 않아도 되니 중복도 방지됨.
    + 또한, 합친 테이블의 내용과 그 전 테이블의 내용의 불일치가 발생할 걱정이 없음.
  - 내용을 싹 기록하고 있어서, 문제가 생겨도 이전 내용을 import 하거나 export 하는 게 가능함.
  - 다만, 데이터베이스에 기록할 수 있는 자료형이 한정되기 때문에, 우리가 사용하는 언어의 자료형들보다 형태가 제약된다.

### Data Replication
* 데이터 사본을 만드는 데에는 몇 가지 전략이 있음.
1. Single leader/primary-secondary replication
  - read-heavy한 경우 유효
2. Multi-leader
3. Peer-to-peer
  - All-to-all 전략을 통해 데이터 항상성 유지
  - Quorums를 통해서 최신 데이터를 구할 수 있음.
  - DynamoDB에서는 여러 노드의 데이터를 가져오고, 그 안에서 최소 하나 이상의 최신 데이터를 얻는 식으로 접근
* 각 데이터 레플레이케이션 방법이 갖는 특징이 있음.

### Data Partitioning
* 샤딩 유형
  - 수직 샤딩(Vertical Sharding)
  - 수평 샤딩(Horizontal Sharding)
* 샤딩 방식
  - 수동
  - 자동
* Primary key에 의한 샤딩
* Secondary indice에 의한 샤딩
  - 모든 노드에 Secondary indice에 대한 쿼리를 수행하면 굉장히 비효율적으로 동작함
  - 따라서, 중간에 매핑 역할을 해줄 별도의 노드가 필요함.
* 노드 재분배에 대한 요청 경로 찾는 방법
* 주키퍼

### Trade-offs in DataBases
* 중앙화시스템
  - 장점
    + 관리가 쉬움
  - 단점
    + 1개 노드가 고장나면 시스템 붕괴
    + 데이터량이 많아지면 성능 저하
* 분산시스템
  - 장점
    + 데이터량이 많아도 부하 분산 가능
    + 한 개 노드에 문제가 발생해도 시스템은 유지됨
  - 단점
    + 데이터 항상성 유의
* 분산 투명성 수준
  - Location Transparency: 데이터를 여러 노드에서 받아왔다는 걸 몰라도 됨
  - Parition Transparency: 데이터가 여러 개의 표에 나뉘어 있단 걸 몰라도 됨
  - Replication Transparency: 데이터가 여러 개 있단 걸 몰라도 됨
  - 위와 같은 것을 왜 '투명성'이라 하는지 모르겠음. 추상성이라는 단어가 더 어울릴 듯함.

<br>

## Key-value Store
### System Design: The Key-value Store
* 단순 해싱에 대한 이야기 아닐까?

### Design of a Key-value Store

### Ensure Scalability and Replication
* Consistent hashing에서 virtual node의 활용까지
  - 이를 통해 서버의 연산력에 부합하는 부하를 줄 수 있게 됨
* Data replication
  - Primary-secondary approach
  - Peer-to-peer approach
    + peer-to-peer를 활용하여 총 5개 노드가 있다면 3개 노드에 대해서 쓰기를 수행.
    + (이를 통해 데이터를 확인하려 할 때는 3개 노드에서만 뽑아도 됨)

### Versioning Data and Achieving Configurability
* Vector clock과 Quorums를 활용하여 Configurability 확보
  - 정확하게 이해하진 못함. Configurability라는 게 뭔지도 애매함.

### Enable Fault Tolerance and Failure Detection 
* Handle temporary failures
  - Quorum-based approach를 통해 시스템 실패(failure)를 관리함
* Handle permanent failure
  - Merkle tree
    + 리프의 값이 바뀌면 부모 노드를 찾아 올라가면서 해쉬값을 갱신.
    + 이를 통해 값이 바뀌었는지 판별할 수 있음.
    + 관리할 노드의 범위가 바뀌었다면 Merkel tree에서 확인하여 갱신할 수 있음.
  - Virtual node를 통한 실패(failure) 확인
    + gossip protocol을 잘 설계해서 노드를 배정.
    + 이를 통해서 본인의 failure 여부를 확인하는 상황이 발생하지 않도록 제어

* Key-value Store
  - 유저 정보나 세션 정보를 활용해 key-value store를 사용한다면, 실시간 추천 등의 로직을 구현할 수 있다.

<br>

## Content Delivery Network (CDN)
### System Design: The CDN
* 큰 데이터를 하나의 노드를 통해서 전달하는 서비스는:
  - 큰 지연시간(latency)에 직면하게 된다.
  - 또한, 노드 하나가 다운되면 서비스가 먹통이 된다.
* Netflix, Amazon Prime 등, 매우 큰 데이터를 전달하는 CDN은 굉장히 큰 인터넷 트래픽을 발생시킴.
  - 이를 효율적으로 다루는 것은 서비스 품질 측면에서 중요.

### Introduction to a CDN
* Proxy 서버를 활용하여 레이턴시 감소
  - 캐싱해둔 데이터를 유저들에게 짧은 레이턴시로 전송해줌.
  - 넷플릭스 같은 경우 90% 수준의 영상을 캐싱할 수 있지만, 유튜브는 그럴 수가 없다.
  - CDN이 갖춰야 할 요소들
    + ...
    + Availability
    + Scalability
    + Security and 

### Design of a CDN
* CDN 구성요소
  - Clients, Routing System, Scrubber servers, Proxy servers, Distribution system, Origin servers and Management system.
* Workflow
  - Setup
    + 본 서버에서 루팅 시스템에 모든 URI 정보 제공
    + 본 서버가 각 컨텐츠를 프록시 서버에 뿌림
    + 분산 현황을 요청 루팅 시스템에 전달
  - 클라이언트 요청 시작
    + URI에 대해 루팅 시스템에 요청. 가장 가까운 프록시 서버를 안내 받음
    + scrubber 서버를 통해 걸러짐
    + 프록시 서버에 도달. 관련 통계를 관리 시스템에 전달.
    + 만약 프록시 서버에 컨텐츠가 없다면 본 서버로 이동.
* API Design
  - Retrieve: 프록시 서버에 컨텐츠에 대한 탐색을 요청은 경우
  - Deliver: 본 서버가 프록시 서버에 요청
  - Request: 클라이언트가 프록시 서버에 수행
  - Search: 프록시 서버가 동료 프록시 서버에게 해당 컨텐츠가 있는지 확인
  - Update: 프록시 서버가 동료 프록시 서버에 이미지 크기 변경, 영상 해상도 변환 등을 요청

### In-depth Investigation of CDN: Part 1
* Content caching strategies in CDN
  - Push CDN: 원 서버에서 프록시 서버로 컨텐츠를 넣어줌
  - Pull CDN: 프록시 서버가 유저의 요청에 따라 원 서버에서 필요한 자료를 찾아 끌고옴
  - Push CDN은 가용성이 높다. / Pull CDN은 저장공간이 적게 든다. / 보통 이 둘을 같이 쓴다.
* Dynamic content caching optimization
  - 동적 컨텐츠는 프록시 서버에서 활용하는 게 효과적이다.
  - ESI와 같은 것으로 압축하여 원형 템플릿을 공유할 수 있다.
* Multi-tier CDN architecture
  - Tree 형태로 프록시 서버를 둠
  - 원 서버는 루트: 이 원 서버는 여러 대의 서버로 되어 있음.
  - 2계층이라고 하면 원 서버를 부모 노드로 갖는 상위 프록시 서버가 있음
  - 하위 프록시 서버는 상위 프록시 서버의 자녀 노드
* Find the nearest proxy server to fetch the data
  - 그래서 어떻게 전세계적인 요청을 가장 가까운 프록시 서버가 받을 수 있게 할 것인가-
  - Important factors that affect the proximity of the proxy server
    + 거리 개념을 정립: 네트워크 거리(network distance), 요청 부하(request load)
  - DNS redirection
    + 부하가 적은 곳으로 유저를 보냄
    + 서비스가 다운되지 않은 상태로 각각의 서버를 보수할 수 있게 해줌.
  - Anycast
    + 서로 다른 위치의 서버가 동일한 IP를 활용하는 Anycast라는 방법이 있음.
    + 이를 일반적인 IP에 따라 동작하게 하려면 Border Gateway Protocol이 필요하다.
  - Client multiplexing
    + 활용할 수 있는 여러 서버 목록을 넘겨줌. 그리고 클라이언트가 고르게 함.
    + 클라이언트가 최적의 결정을 하기 힘들기 때문에 좋지 않은 결과로 이어질 수 있다.
  - HTTP redirection
    + 원 서버에 요청을 하면 클라이언트를 적절한 곳으로 리디렉션하는 방식

### In-depth Investigation of CDN: Part 2
* Content consistency in CDN: 
  - Periodic polling: 주기적으로 원 서버에서 컨텐츠를 가져옴
  - Time-to-live (TTL): 원 서버에서 컨텐츠마다 TTL을 설정해서 보내줌. 만료 시 프록시 서버는 업데이트 여부를 확인해야 함.
  - Leases: 임대하는 식으로 사용. TTL 개념과 크게 다른 점은 모르겠음.
* Deployment: 프록시 서버 배치
  - Placement of CDN proxy servers
    + 구글과 같이 TCP를 활용한 새로운 인프라를 활용할 수도 있음.
    + ISP 내부에 서버를 위치시켜서 이점을 가져가기도 함.
    + IXP 근처에 서버를 위치시켜서 지연시간을 단축시키기도 함.
    + ProxyTeller와 같은 툴을 활용해 어디에 프록시 서버를 두는 게 좋은지 판단함.
* CDN as a service
  - CDN 서비스를 제공하는 회사들이 있음.
  - 이들을 활용해서 CDN을 쓸 수도 있지만, 이들의 상황에 따라 제약이 발생할 수 있음.
* Specialized CDN: Open Connect Appliance (OCA)를 통해서 캐싱한 데이터 제공
  - Why Netflix built its CDN
    + 데이터 집중적(data-intensive)인 넷플릭스의 요구를 공적 CDN이 따라갈 수가 없었음.
    + 본인들의 목적에 상충했기 때문에 새롭게 CDN을 구축했고, 더 빠르게 TCP 연결을 맺고, 높은 캐시 적중률을 얻었음.

### Evaluation of CDN's Design
* 위와 같은 설계를 통해서 짧은 지연시간에 많은 트래픽을 처리할 수 있게 됨.
* 수평적 확장성도 확보할 수 있음.
* 하나의 실패가 시스템 다운으로 이어지지 않음.
* 컨텐츠가 자산이므로, 이것이 다른 곳에 유출되지 않도록 막을 수 있음.

<br>

## Sequencer
### System Design: Sequencer
* Motivation
  - 이벤트 추적을 위해 고유 식별자(unique ID)를 활용하고자 함.
  - 그러나, 분산 시스템에서 이를 활용하는 것은 어렵다.
  - 이에 대한 방법을 소개하고자 함.

### Design of a Unique ID Generator
* Requirements for unique identifiers
  - 유일성, 확장성, 가용성, 64-bit 숫자 ID
* First solution: UUID
  - Cons: 유일하지 않음(중복 가능성이 거의 없지만), 64비트 숫자가 아님.
* Second solution: using a database
  - 중복 가능성이 있고 확장성도 없음. 가용성은 확보. 64비트 숫자임
* Third solution: using a range handler
  - Range Handler를 두고, 할당 받은 영역의 ID가 채워졌을 시 다음 영역을 안내 받는 방식으로 동작
  - 모든 조건을 만족함

### Uniqe IDs with Causality
* Causality
  - 이벤트들의 연관성을 추적하는 방법에 대한 챕터
* Use UNIX time stamps
  - 로드밸런서를 통해서 time stamp 서버와 의사소통하며 ID를 받아옴
  - 시간만으로는 인과성을 기록하기 쉽지 않고, 확장성이 약함
* Twitter Snowflake
  - 부호 비트: 항상 0으로 둬서 어떤 시스템이든 전체 값을 양수로 인식하게 함
  - 타임스탬프: 70년을 기록할 수 있는 41-bit 타임스탬프
  - 워커 ID, 시퀀스 
* Using logical clocks
  - Lamport clocks: 카운터를 통해서 어느 워커의 몇 번째 작업이었나 파악
  - Vector clocks: Lamport clock을 각 워커에 대해서 조합하여 활용.
* TrueTime API
  - 이를 활용해서 Snokflake와 유사한 Unique ID를 고안함
  - 이를 통해 ID 하나로 필요한 정보를 다 담을 수 있다고 함.
* 사실 이게 중앙 시스템에선 전혀 문제가 안 되는 작업이었는데, 분산 시스템으로 처리하려다 보니 고안할 수밖에 없던 것.
  - 항상 trade-off가 있다.

<br>

## Distributed Monitoring
### System Design: Distributed Monitoring
### Introduction to Distributed Monitoring
* 분산 모니터링을 수행함으로 실패 지점을 찾기가 수월해지고 비용도 줄어든다.
* 실제로 실패 사례에 의해 얼마나 많은 돈을 잃었는지 알려줌.
* 서비스의 장애 상황에서 대해서 아래 두 유형으로 구분할 수 있다.
  - 클라이언트 사이드 에러
  - 서버 사이드 에러

### Prerequisites of a Monitoring System
* 어떤 지표에 대해 어떤 단위로 측정할 것인지가 중요하다.
* Push / Pull monitoring System
  - 주체는 모니터링 시스템
    + 모니터링 시스템이 필요한 속성들을 어떻게 구하느냐의 관점으로 보면 됨.
* Time-series database
  - 이벤트에 시간이 기록되지 않으면 대부분 쓸모없는 정보가 됨.
  - 따라서 시간을 기록하고 시간순으로 정보를 기록.
* 경고: 어떤 지표가 수용할 수 있는 범위를 벗어나면 알림을 발생

<br>

## Monitor Server-side Errors
### Design of a Monitoring System
* 시스템의 성능 관련된 지표들을 선정
  - CPU, 메모리, 디스크, 네트워크 사용량 지표
  - 전원 관련 이슈
  - 전력 소모량 지표
* AWS, Azure, Google에서 제공하는 모니터링 툴들도 있음.
* Blob storage를 통해 정보를 기록할 것.
  - High-level 디자인 구성
    + 모니터링 데이터를 기록할 저장소
    + 데이터 수집 서비스
    + 쿼리 서비스

### Detailed Design of a Monitoring System
* Storage
  - Time-series DB: 각 시간 마다 이벤트 기록
  - Rules and action DB: 경고 등에 대한 기준을 저장
* Data collector
  - 어플리케이션, 서비스, 서버 등에 데이터를 요청하고 데이터를 수집함.
* Service discoverer
  - 어떤 서비스를 확인해야 하는지 알려줌
* Querying service
  - 어디서 문제가 생겼는지 파악하는 서비스
  - 구성 요소는 아래와 같음
    + Alert manager: 설정한 규칙에 따라 알림이 필요한 경우를 인지하고 해당 메시지를 전송
    + Dashboard: 필요 정보를 수집하는 대쉬보드 활용
* 장단점
  - 장점
    + 가용성이 높음
    + 네트워크 트래픽 등으로 인한 오버헤드를 방지
  - 단점
    + 확장성(scalability)이 좋지 않음.
    + 모니터링 서비스가 Single Point Failure을 일으킬 수 있음
    + 이를 관리하기 위해서 failover 서버를 두게 되면 동기화를 처리해야 함.
    + 항상 이와 같은 모니터링 시스템을 활용하는 것은 방대한 데이터를 기록해야 함.
    + 따라서 이를 잘 처리하기 위한 규칙이 필요.
* 설계 개선하기
  - 확장성을 확보하기 위해서, 모니터링 서버를 여러 대 두는 방식을 채용
  - 그리고, '모니터링 서버를 모니터링하는 서버'를 둠
  - 이를 통해 모니터링 서버들이 '모니터링 서버를 모니터링 하는 서버'에 데이터를 전송
* 이와 같이 데이터를 모으게 되면, 굉장히 많은 양의 데이터가 저장됨.
  - 이를 어떻게 사람이 관리할 수 있는 형태로 바꿀 수 있을지 다음 절에서 알아보고자 함.


### Visualize Data in a Monitoring System
* Using heat maps to troubleshoot
  - heat map을 그려서 각 클러스터의 상태를 표현하도록 만듦.
  - 1: 동작 중인 서버, 0: 동작하지 않는 서버
  - 이를 통해 굉장히 효율적이고 시각적으로 서버 상태를 표현할 수 있다.

<br>

## Monitor Client-side Errors
### Focus on Client-side Errors in a Monitoring System
* 서버는 클라이언트 사이드 에러에 대해서 거의 정보가 없다.
  - 서버 부하를 본다고 해도, false positive나 false negative가 많다.
* 예시: 구글의 BGP Leak. ISP에서 의도하지 않은 곳으로 연결을 시켜 사용자가 서비스 주소에 도달하지 못함.

### Design of a Client-side Monitoring System
* Prober
  - 직접 사용자 입장에서 서버에 접근 시도.
  - 완전히 모든 사용자 입장에서 접근을 시도할 수도 없고, 완벽히 사용자 입장을 표현하기도 힘들다.
* Agent and Collector
  - Agent: 사용자의 브라우저에 심어두고 접속 문제 발생 시 Collector에게 정보 전송
* 발생한 문제에 대해 다른 우회 루트를 찾아서 장애 상황을 컬렉터에 보고하는 식으로 agent를 운용
* 보고되는 정보에는 traceroute hops나, DNS resolver, RTT 등을 제외한다.
  - 이는 사용자의 위치정보를 드러낼 수 있다.
  - 또한, 어떤 사용자 정보도 능동적으로 수집해선 안 된다.

<br>

## Distributed Cache
### System Design: The Distributed Cache
* 서로 다른 계층의 캐싱을 통해 비용을 절약하고 유저의 지연시간을 줄임
* Web, Application, Database 레벨에서 활용됨.

### Background of Distributed Cache
* 분산 캐시에서 고려할 주요 사항
  - Writing policies
  - eviction policies
  - cache invalidation
  - storage mechanism
  - cache client
* Writing policies
  - write-through cache
    + 캐시에 기록하면서 DB에도 기록
    + 소요시간이 길어짐
  - write-back cache
    + 캐시에 먼저 쓰여지고 DB에 비동기적으로 갱신됨
    + 소요시간 짧음
  - write-around cache
    + DB에 먼저 쓰고, 캐시 미스가 나는 경우에 캐시를 작성
    + 최근에 업데이트된 내용이 캐시에는 반영되지 않았다면, 캐시를 불러왔을 때는 만료된 정보가 기록되어 있을 듯.
* Eviction policies
  - Least recently used (LRU)
  - Most recently used (MRU)
  - Least frequently used (LFU)
  - Most frequently used (MFU)
* Cache invalidation
  - TTL을 설정하는 것으로 해결
  - 능동적 만료(active expiration): 직접 TTL이 만료된 것들을 찾음
  - 수동적 만료(passive expiration): 접근하는 시점에 TTL을 확인
* Storage mechanism
  - 두 가지 문제를 해결하고자 함.
    1. 어떤 데이터를 어느 캐시 서버에 저장할 것인가
    2. 데이터를 저장할 때 어떤 자료구조를 활용할 것인가
  - Hash function
    + Consistent hashing을 통해서 어떤 데이터를 어떤 서버에 저장할지 결정할 수 있음.
    + 캐시 엔트리를 결정할 수는 있음. 그러나, 어떤 자료구조를 활용할지는 따로 결정해야함.
  - 연결 리스트
    + 데이터를 쓰고 지우는 데 상수시간이 걸리므로 활용한다고 함
    + 그러나, 필요한 데이터를 탐색한다고 하면 O(N)의 시간이 걸릴 텐데 어떡하겠다는 건지...
  - Sharding in cache clusters
    + 캐시를 샤딩해서 나눠둠. 그리고 각 서버만의 단독 캐시를 둘 수도 있고, 공유할 수도 있음.
  - Cache client
    + 캐시 계산을 해주는 클라이언트

### High-level Design of a Distributed Cache
* 기능적, 비기능적 요구사항
  - 기능적
    + 데이터 삽입 및 호출
  - 비기능적
    + 높은 성능, 확장성, 높은 가용성, 항상성, 경제성
* API: 해시와 동일함
  - 삽입(put): key와 value를 인자로 활용
  - 호출(get): key를 인자로 활용
* 설계 고려사항
  - Storage hardware: 저장을 위한 하드웨어. 보조기억장치를 활용할 수도 있음.
  - Data structures: 적절한 자료구조를 활용해서 데이터에 접근할 수 있도록 활용.
  - Cache client: 클라이언트에 캐시 클라이언트를 두고, 접근하려는 정보를 얻기 위한 캐시 서버를 안내 받음
  - Writing policy: 캐시와 영속적 데이터는 기본적으로 항상 같아야 하지만, 필요에 따라 여러 방법을 둘 수 있음.
  - Eviction policy: 만료된 캐시는 어플리케이션 종류에 따라 더 효율적인 방법으로 처리
* High-level design, 고급 설계란...
  - Service와 cache client의 병용
  - Cache server를 둬서 persistence layer에 있는 자료에 접근하도록 계층적 설계.

### Detailed Design of a Distributed Cache
* Find and remove limitations
  - Configuration service를 둬서 캐시 서버 상태를 파악하고, 필요에 따라서 캐싱 상태를 갱신하는 방식으로 활용
* Improve availability
  - 레플리카 노드를 둔다. 이를 통해서 캐시 서버의 다운이 시스템 실패로 이어지게 하지 않는다.
  - 또한, hot-key에 대해 더 많은 연결을 수용할 수 있도록 확장할 수도 있다.
* 캐시 서버 내부
  - Hash map을 두고, 양방향 연결리스트를 둠. Eviction policy는 LRU로 설정했다고 해보자.
  - key가 있는데 각 노드를 굳이 연결리스트로 잇는 이유는 정말 모르겠음.

### Evaluation of a Distributed Cache's Design
* High performance
  - 다른 건 다 준비됐고, 어플리케이션에 따른 적절한 eviction policy만 잘 선택해주면 성능을 좋게 유지할 수 있다.
* Scalability
  - 복제 노드를 활용하여 hot shard에 대한 부하를 덜어줌
* High availability
  - leader-follower algorithm을 통해서 한 노드가 망가져도 다른 노드가 대신할 수 있도록 설정
* Consistency
  - 필요에 따라서, consistency를 줄이고, 더 높은 availability를 가져갈 수 있음.
  - consistency를 택하는 경우 어느 정도의 성능 저하는 감수해야 함.
* Affordability
  - 이와 같은 분산 캐시 시스템은 경제성도 충분하다.

### Memcached versus Redis
* Memcached
  - 동일한 데이터 구조만 다룬다.
  - 페이스북에서 활용함. RAM이 굉장히 많이 필요.
* Redis
  - 다양한 자료구조를 다룰 수 있음.
  - 자체 데이터베이스가 있음.
  - 자체 failover 솔루션이 있음.
  - 적절한 레플리카를 만들어서 제공. 이로 인해 강한 항상성 유지가 안 될 수 있음.
* Memcached vs. Redis
  - 단순성: Memcached가 단순함
  - 영속성: Redis가 제공. Memcached는 외부 프로그램이 필요
  - 자료형: Memcached는 객체. Redis는 다양한 자료형을 제공
  - 메모리 사용: 둘 다 설정 가능
  - Multithreading: Redis는 기본적으로 싱글코어. 
  - Repliaction: Redis는 클러스터링을 해야하는데 이는 꽤 복잡함.

<br>

## Distributed Messaging Queue
### System Design: The Distributed Messaging Queue
* 메시지 큐는 일을 할당해놓고 순차적으로 처리되도록 함.
  - 우선순위에 따라 일을 처리하도록 설정할 수도 있음.
  - 실생활에서도 많이 쓰임(이메일 시스템, 추천 시스템, 시스템 업데이트 등)

### Requirements of a Distributed Messaging Queue’s Design
* 기능적 요구사항
  - 큐 생성, 메시지 전송, 메시지 수신, 메시지 삭제, 큐 삭제
* 비기능적 요구사항
  - 안정성, 확장성, 가용성, 성능
* 단일 서버 메시징 큐
  - 큐가 임계영역(critical section)이 됨.
    + race condition이 발생하지 않도록 lock을 잡아야 하며, 이는 성능 저하로 이어짐
    + 단일 서버로 활용하면 네트워크나 하드웨어 실패로 인해서 접근하지 못하게 될 때 둘 다 쓰지 못해서 안 됨.
* 이를 극복하기 위해서 분산 시스템을 설계하고자 함.
  - 데이터베이스, 캐시, 로드 밸런서를 활용

### Considerations of a Distributed Messaging Queue’s Design
* Ordering of messages
  - 주어진 순서대로 받아서 전달하는 경우
  - 정렬 기준을 따라 큐에서 정렬 후 순서를 맞추는 경우
    + 필요에 따라서 메시지의 순서가 온전해야 할 수 있음.
* Effect on performance
  - sender와 reciever 패턴 자체가 온전한 순서를 보장하지 않으니 큐에서 정렬이 이뤄져야 함.
* Managing concurrency
  - locking: 성능이 좋지도 않고 확장도 불가능함
  - serialize requests using the system's buffer: 시스템의 버퍼를 활용해 입출력 하듯 주고받는 것으로 이해됨
    + 그러나 정확히 어떻게 버퍼를 활용할 수 있는 건지는 잘 모르겠음.
  - using multiple queues: 다수의 큐를 활용하면 어플리케이션 로직이 복잡해짐.

### Design of a Distributed Messaging Queue: Part 1
* 확장성, 가용성, 내구성(durability) 이슈에 대해서 다룰 것.
* High-level design
  - 큐를 primary-secondary 또는 quorum-like 시스템으로 클러스터 내부에 둠
* 프론트엔드 서버
  - 요청에 대한 유효성을 판단, 권한 확인을 수행, 캐싱, 리퀘스트를 백엔드로 보냄, 중복된 요청 제거, 사용 데이터 모음
* 메타데이터 서비스
  - 큐 자체를 관리
* 클러스터 활용
  - 메타 데이터를 프론트엔드 서버가 가지고 있는 경우
  - 메타 데이터를 각 호스트가 가지고 있는 경우
    + 메타 데이터를 확인한 뒤, 다른 호스트에게 보내야 한다면 조치를 취해줌.

### Design of a Distributed Messaging Queue: Part 2
* 큐와 메시지가 저장되는 백엔드에 대해서 알아보자.
* 클러스터 매니저는 아래 두 가지로 나뉨.
  - Internal cluster manager
    + 큐와 클러스터 내 호스트 간 정보를 매핑하고 있음.
    + 클러스터를 관리
  - External cluster manager
    + 큐와 클러스터 간 정보를 매핑하고 있음.
    + 메타데이터 서비스를 관리
* 이에 따라 특정 큐에 요청이 들어왔을 때 메시지를 전달할 수 있다.

### Evaluation of a Distributed Messaging Queue’s Design
* 기능적 요구사항
  - 큐 생성 및 삭제
  - 메시지 전송 및 반환
  - 메시지 삭제(잘 이해 안 됨)
* 비기능적 요구사항
  - 내구성, 확장성, 가용성, 성능
  - 분산 시스템의 특성을 활용하여 가용성을 향상하고, 내구성을 가짐. 성능 역시 향상됨.

  <br>

## Pub-sub
### System Design: The Pub-sub Abstraction
* Publish-subscribe messaging
  - 비동기적으로 서비스에서 서비스로 의사소통하는 방법.
  - 메시지를 만드는 사람이 있고, 이들의 메시지를 구독자들에게 전달
  - 비동기적으로 처리하기도 쉽고, 확장성이 매우 좋은 방식.

### Introduction to Pub-sub
* Use cases of pub-sub
  - Handling ingestion
  - Real-time monitoring
  - Replicating data
* API
  - 생성된 특정 topic에 대해 메시지를 작성하거나, 읽고, 구독하거나 취소하는 등의 동작을 수행하는 API를 설계
* Building blocks for pub-sub
  - DB, Distributed messaging queue, Key-value store

### Design of a Pub-sub System
* 초기 디자인은 메시지 디렉터와 서브스크라이버를 두고, 각 주제에 대한 consumer의 큐에 메시지를 전달
  - 이는 토픽이 많아지면 큐가 많아진다는 단점이 있음.
* 이를 해결하기 위해 다음 디자인을 제안
  - Broker를 통해 메시지를 전달
  - Broker들을 관리하는 Cluster manager가 있음.
  - Consumer들을 관리하는 Consumer manager가 있음.
    + 이 매니저는 DB를 통해서 Consumer 정보를 관리 및 저장
* Broker
  - 많은 큐를 사용하지 않아도 되게 만들어줌
  - 하나의 토픽에 대해서 서로 다른 브로커가 파티션을 들고 있도록 함.
    + 이를 통해 한 브로커가 망가져도 전체 토픽에 문제가 되지 않도록 함.
* Cluster manager
  - 브로커 및 토픽 관리, 데이터 레플리케이션 관리
* Consumer manager
  - Consumer 유효성 판단
  - 데이터 유지 시간 관리
  - 메시지 수신 옵션 관리
  - 여러 번 데이터를 읽어올 수 있도록 허용
