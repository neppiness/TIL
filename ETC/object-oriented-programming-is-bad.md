**Object-Oriented Programming is Bad**

## 문제로써 다루지 않는 것
* 클래스
* 추상화
* 코드 미학

## 프로그래밍 패러다임
* 절차적(procedural) & 필수적(imperative)
* 절차적(procedural) & 기능적(functional)
* 객체지향(object-oriented) & 필수적(imperative)
* 객체지향(object-oriented) & 기능적(functional)

* 상속은 무관하다.
* 다형성도 무관하다.

* 캡슐화는 아무런 효과도 없다.
    - encapsulation does not work (at fine-grained levels of code)

## Why does OOP dominate the industry
* 자바가 C보다 간단해보였기 때문.
    - C의 네이밍이 굉장히 제약적이었기 때문이라 생각됨.
    - LPCTSTR, ioctl, FileInputStream
* 자바는 C와 유사한 문법을 가졌음.
* 헤더파일 없는 코딩을 할 수 있게 됨.
    - 또한, 가비지 컬렉션을 수행해줌.
* 예외를 던져준다는 게 굉장히 매력적이었다.
* subject.verb(object)라는 방식이 영어와 유사했기 때문.
    - 그리고 frame.getContentpane()와 같은 메소드 호출이 가능했기 때문.
* 각각에게 속성을 주고, 동작을 하도록 만드는 게 이치에 맞게 보였기 때문.

## Why does OOP not work?
* 객체가 뭔가?
    - 상태 자체를 보내는 게 아니라, 상태를 복사한 것을 보낸다.
    - 
* OOP: 객체가 객체에게 메시지를 보내는 방식
    - 오브젝트는 상태(state)이다.
* 계층적으로 정보를 보내는 수밖에 없음.
    - 직접적으로 관계 없는 객체들은 서로를 활용할 수 없다.
* 결국 생각하게 되는 건:
    - 메시지가 send() 해야 하나?
    - 아니면 전송자(sender)가 있어서 이를 send()해야 하나?
    - 그것도 아니면 수신자(receiver)가 이를 receive()해야 하나?
    - 아니면 연결(Connection)이 transmit() 해야하나?

## Analysis Paralysis
* abstarct = simplified complexity
* abstract = hard to understand
* 이로 인해서 자꾸 다른 곳을 찾아서 참조하게 됨.

## 절차적 코드
1. When in doubt, parameterize
2. Bundle globals into structs/records/classes
3. Favor pure functions
    - 효율을 따지면 쓰면 안 되지만, 그렇지 않다면 명료해짐.
    - forEach나 filter, map과 같은 함수들을 생각하면 좋을 듯함.
4. Encapsulate (loosely) at the level of namespaces/packages/modules
5. Don't be afraid of long functions. (Do be afraid of needlessly shared state)

* 아래와 같은 코드가 있다고 하자
```
function myFunc() {
    doStuff();
    doMoreStuff();
    thenThis();
    thenThat();
}
```

* 이보다는 놀랍게도 아래와 같은 코드를 추천함.
```
function myFunc() {
    // do stuff
    ...
    // do more stuff
    ...
    // then this
    ...
    // then that
    ...
}
```

* 이같이 작성하면 하나의 함수를 들여다보면서 어떤 일을 처리하는지 알 수 있다고 함.
    - 이름을 잘 짓는 것도 어렵다고 함.

* 절차지향적으로 작성해보라.
