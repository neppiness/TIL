[TIL on April 20th, 2023](../../TIL/2023/04/04-20-2023.md)
# **스프링 핵심 원리 - 기본편**

### 섹션 7. 의존관계 자동 주입
* 조회한 빈이 모두 필요할 때:
  - 생성자 주입을 활용하여 Map 형태로 discountPolicy 빈을 모두 받는다.

* 자동, 수동의 올바른 실무 운영 기준
  - 편리한 자동 기능은 기본으로 사용하자
  - 기술 지원 로직은 수동 빈 등록을 통해 명확히 드러내자: AppConfig에 구현된 내용을 통해 직접 확인할 수 있다.
  - 또한, 한 인터페이스에 대해서 여러 클래스가 구현됐고, 이 클래스들이 빈으로 등록된 경우. 추상화 상황을 명확히 드러내기 위해서 활용한다.
  - 만약 한 인터페이스의 구현체들이 다른 패키지에 나눠져있으면 굉장히 고통스럽다고 함. 충분히 그럴 수 있을 듯함.

<br>

### 섹션 8. 빈 생명주기 콜백
* 개요
  - 어플리케이션이 구동되기 전에 해야하는 조치를 하고, 어플리케이션이 종료될 때 해야하는 작업을 할 수 있게 스프링이 기능을 제공한다.
  - 가장 상위 인터페이스가 ApplicationContext이고, 여기서부터 파생된 ConfigurableApplicationContext를 통해 getBean 후 close를 활용할 수 있음.
  - 스프링 빈은 객체를 생성하고 의존관계를 주입한다; 생성자 주입은 예외.
  - 스프링은 의존 관계 주입이 완료되면, 빈에게 콜백 메서드를 통해 다양한 방법으로 초기화 시점을 알려준다.
  - '싱글톤' 스프링 빈의 이벤트 라이프사이클: 스프링 컨테이너 생성 -> 스프링 빈 생성 -> 의존관계 주입 -> 초기화 콜백 -> 사용 -> 소멸 전 콜백 -> 스프링 종료
  
  - 메모: 최대한 생성자 호출 시에 주입시켜버리는 게 낫지 않나 생각할 순 있지만, '초기화'가 시간이 오래 걸리는 작업을 해버리기 때문에, 이를 구분하는 게 좋다고 함.

* 스프링은 크게 3가지 방법으로 빈 생명주기 콜백을 지원한다.
  1. 인터페이스(InitializingBean, DisposableBean)
  2. 설정 정보에 초기화 메서드, 종료 메서드 지정
  3. @PostConstruct, @PreDestroy 애노테이션 지원

#### 인터페이스(InitializingBean, DisposableBean)
* InitializingBean: afterPropertiesSet 메소드를 오버라이드하여, 의존관계 주입이 끝난 직후 동작을 설정할 수 있다.
* DisposableBean: destroy 메소드를 오버라이드하여, 빈이 소멸될 때 동작을 설정할 수 있다.

* 주입할 대상이 있어야 의존관계를 주입할 수 있는 건 자명함. 따라서, 객체를 먼저 빈 깡통으로 준비해놓고 안에 내용물을 채우는 방식이라 생각하면 이해가 수월할 듯함.

* 스프링 전용 인터페이스기 때문에, 순수 자바 코드로 테스팅을 할 수 없다는 단점이 있을 듯함.
  - 프레임워크의 제약을 크게 받는다는 게 전체적인 단점임.

* 이 방법은 초기에 나온 방법으로, 지금은 거의 사용하지 않는다고 함.

#### 설정 정보에 초기화 메서드, 종료 메서드 지정
* 빈을 등록할 때, `@Bean(initMethod = "init", destroyMethod = "close")`로 어노테이션을 설정한다.
  - 스프링 빈이 스프링 코드에 의존하지 않는다.
  - 코드가 아니라 설정 정보를 사용하기 때문에 코드를 고칠 수 없는 외부 라이브러리에도 초기화, 종료 메서드를 적용할 수 있다.
* destroyMethod는 기본값이 (inferred)이며, 대부분의 외부 라이브러리의 종료 메서드 이름이 shutdown이나 close이기 때문에, 이를 자동으로 추론해서 닫아준다.

#### 애노테이션 @PostConstruct, @PreDestroy
* 이 방법을 추천한다.
  - 어노테이션 이름의 의미도 매우 직관적임: '생성자 호출 뒤'와 '소멸 전'

```java
import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;
```
* javax인 경우, 자바 표준으로 활용되는 것이므로, 스프링이 아닌 다른 컨테이너에서도 잘 동작한다.
* 유일한 단점은 외부 라이브러리에 적용하지 못한다는 것이다. 외부 라이브러리를 초기화, 종료해야 하는 경우 @Bean의 initMethod와 destoryMethod를 활용하자.

<br>

### 섹션 9. 빈 스코프
* 싱글톤: 기본 스코프, 스프링 컨테이너의 시작과 종료까지 유지되는 가장 넓은 범위의 스코프이다.
* 프로토타입: 스프링 컨테이너는 프로토타입의 빈의 생성과 의존관계 주입까지만 관여하고 더는 관리하지 않는 매우 짧은 범위의 스코프

* 웹 관련 스코프: request, session, application
  - 스프링의 웹 관련 기능이 있어야 활용할 수 있는 스코프

* 메인은 싱글톤, 프로토타입, 리퀘스트 정도.

<br>

#### 프로토타입
* 요청 받은 시점에 의존관계 주입 및 초기화 후 요청한 곳에 반환. 이후 관리 안 함.
  - 다시 요청을 받아도 새로운 것을 다시 만들고 다시 건내줌.
  - 종료 메서드를 호출하는 것도 스프링이 아니라 건내 받은 클라이언트에서 해야하는 것.
  - 사실 종료 메서드가 자동으로 호출되지 않는 것이지, 호출하면 호출된다(당연한 것).

* ApplicationContext ac를 생성하면 @PostConstruct는 자동으로 호출됨.
  - ac.close()를 통해서 닫을 때 빈이 소멸되고, 이때는 @PreDestroy로 설정한 메소드가 작동된다.

#### 프로토타입 스코프 - 싱글톤 빈과 함께 사용 시 주의사항
* 항상 새로운 객체를 반환하지 않을 수도 있게 된다.
* SingletonBean 내에 PrototypeBean을 가지고 있는 경우는 구분해서 써야한다는 내용인 듯함.
  - 새롭게 생성하고 넘겨줬기 때문에 스프링 컨테이너가 관리를 안 할 뿐이지, 싱글톤 내에서 관리되는 프로토타입 빈이 된 것이고, 호출할 때마다도 동일한 객체를 불러오게 되며, 필드는 이전 값을 유지하며 갱신되게 된다.
  - 그리고 이런 동작은 PrototypeBean을 쓴 목적에 부합하지 않을 것이다.
* 어떨 때 이런 로직을 활용할 수 있을지도 생각해볼 필요가 있을 듯 - 강사님도 이런 기능을 활용할 일은 없었다고 함.

#### 프로토타입 스코프 - 싱글톤 빈과 함께 사용 시 Provider로 문제 해결
* 의존관계를 외부에서 주입 받는 게 아니라 직접 필요한 의존관계를 찾는 것은 의존관계 조회(탐색, Dependency Lookup DL)이라 한다.

1. ObjectFactory, ObjectProvider
  - 프로토타입이 아래와 같이 두 개 생성되는 것을 확인할 수 있음.
```
PrototypeBean.init hello.core.scope.SingletonWithPrototypeTest1$PrototypeBean@2a640157
PrototypeBean.init hello.core.scope.SingletonWithPrototypeTest1$PrototypeBean@584f54e6
```

* 이 Provider는 우리가 원했던 DL만큼 기능을 제공한다.
* ObjectFactory는 getObject 메소드 딱 하나만 제공해주는 상위 인터페이스임.

2. JSR-330 Provider
  - 자바 표준으로 제공해주는 Provider.
  - 별도의 라이브러리를 추가해야 함: `implementation 'javax.inject:javax.inject:1'`

* **프로토타입 빈을 직접적으로 활용할 일은 거의 없다.**

* 코드를 스프링이 아닌 다른 데서 써야하는 경우 표준을 활용해야 한다.

#### 웹 스코프
* 웹 환경에서만 동작한다.
  - 스프링이 종료 시점까지 관리를 해서 PreDestroy가 동작한다.

* request: HTTP 요청 하나가 들어오고 나갈 때까지 유지됨. **실제 고객의 요청이 왔을 때만 정상 동작한다.**
* session: HTTP Session과 동일한 생명주기를 가짐.

* AnnotationConfigApplicationContext가 웹이 구동되면 AnnotationConfigServletWebServerApplication을 기반으로 어플리케이션을 구동한다.

* 로그를 아래와 같이 남기는 것도 실무적 관점에서 필요한 것인 듯함.

```
[6c5bf055-8564-4614-9d2f-869eb06b85d6] request scope bean created: hello.core.common.MyLogger@4e076548
[6c5bf055-8564-4614-9d2f-869eb06b85d6][http://localhost:8080/log-demo] Controller test
[6c5bf055-8564-4614-9d2f-869eb06b85d6][http://localhost:8080/log-demo] service id = testId
[6c5bf055-8564-4614-9d2f-869eb06b85d6] request scope bean closed: hello.core.common.MyLogger@4e076548
```

* ObjectProvider를 활용해서 호출하는 시점까지 요청을 지연시켰다.

#### 스코프와 프록시
* ObjectProvider를 사용하지 않아도, `@Scope(value = "request", proxyMode = ScopedProxyMode.TARGET_CLASS)`를 통해서 이전에 오류났던 코드와 동일하게 설정하고도 문제 없이 동작시킬 수 있다.

* 적용 대상이 클래스면 TARGET_CLASS, 인터페이스면 INTERFACE라 하면 된다.

* 스프링이 조작해서 만들어낸 클래스인 프록시(대리 클래스)가 동작한다: 바이트코드 조작

* 어느 쪽이든 핵심은, 필요한 시점에만 진짜 객체를 찾도록 지연처리한다는 것.
  - **단지 어노테이션 설정 변경만으로 원본 객체를 프록시 객체로 대체할 수 있다는 것. 다형성과 DI 컨테이너가 가진 큰 강점이다.**

<br>

### 섹션 10. 다음으로
* 스프링 전반에 깔려있는 원리에 대한 내용을 익혔다.
  - 이것을 기반으로 스프링 기술들을 배우는 데 있어 깊이있는 이해를 할 수 있을 것이다.