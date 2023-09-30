# **Grokking Modern System Design Interview for Engineers & Managers**

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

### Example of Resource Estimation
* Twitter의 예로 Outgoing bandwidth와 Incoming bandwidth, 그리고 1년에 증설해야 하는 데이터 사이즈를 가늠함.
