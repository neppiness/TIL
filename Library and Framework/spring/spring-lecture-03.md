[TIL on April 21st, 2023](../../TIL/2023/04/04-21-2023.md)
# **스프링 MVC 1편 - 백엔드 웹 개발 핵심 기술**

### 섹션 1. 웹 애플리케이션 이해

#### 웹 서버, 웹 애플리케이션 서버(WAS)
* 웹 어플리케이션 서버는 웹 서버와 다르게 프로그램 코드를 실행해서 어플리케이션 로직을 수행할 수 있음.
* WAS는 어플리케이션 코드를 실행화는 데 특화됨.

* 사실 WAS만 가지고 웹 시스템을 구성할 수 있지만, 그렇게 하면 WAS에 과부하가 많이 걸려 문제가 발생할 수 있음.
  - 그래서 웹 서버를 두고, 정적 리소스를 전달하는 작업 등은 웹 서버가 수행. 어플리케이션 로직이 필요할 경우 WAS에 전달.
  - 이렇게 두는 경우, WAS가 다운됐을 때, 웹 서버가 WAS의 상황을 알려줄 수도 있음.

#### 서블릿
* 실질적 비즈니스 로직 외 모든 작업을 서블릿이 해준다.

```java
@WebServlet(name = "helloServlet", urlPatterns = "/hello")
public class HelloServlet extends HttpServlet {

    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) {
        // 어플리케이션 로직
    }
}
```

* 요청 정보와 응답 정보를 서블릿을 통해 간단히 사용할 수 있다.

* 서블릿 컨테이너
  - 톰캣처럼 서블릿을 지원하는 WAS를 서블릿 컨테이너라고 함
  - 서블릿 객체는 싱글톤으로 관리
  - 같은 서버에 요청하면 같은 서블릿 컨테이너에 요청을 하는 것
  - 공유 변수를 사용할 때 조심해야 한다.
* 동시 요청을 위한 멀티 쓰레드 처리 지원
  - 개발자가 멀티 쓰레드를 크게 신경 쓰지 않아도, WAS가 처리해준다.

#### 동시 요청 - 멀티 쓰레드
* 쓰레드
  - 어플리케이션 코드를 하나 하나를 내부에서 순차적으로 실행함.
  - 프로세스와 비교. 프로세스는 프로그램을 실행하는 것. 쓰레드는 프로그램 내에서 작업을 분배하는 것.
  - 자바 메인 메서드를 처음 실행하면 main이라는 이름의 쓰레드가 실행됨.

* 요청 마다 이를 처리하는 쓰레드를 추가로 생성해주면 적절한 처리가 가능함.
  - 장점: 여러 요청을 동시에 처리할 수 있음
  - 단점: 쓰레드 생성은 비용이 크다. 코어가 쓰레드 간 전환을 수행할 때 발생하는 비용인 컨텍스트 스위칭 비용이 발생한다. 쓰레드 생성 제한이 없어 리소스 한계를 넘으면 다운된다.

* 쓰레드 풀
  - 쓰레드 풀에 운용 가능한 쓰레드를 생성해놓고, 요청이 들어오면 쓰레드를 할당해주는 방식.
  - 이 한도를 넘는 요청이 들어오면 쓰레드를 대기시키거나 거절해버린다(수강신청이나 할인 이벤트 트래픽 폭주가 떠오름).

* WAS의 멀티 쓰레드 지원: 개발자는 이 멀티 쓰레드 처리를 고민하지 않아도 된다. 그러나, 멀티 쓰레드 환경이니 싱글톤 객체 사용 시 주의해야 한다는 것이 골자.

#### HTML, HTTP API, CSR, SSR
* 정적 컨텐츠, HTML 페이지, HTTP API: 웹 서버, WAS가 주고 받는 정보들.
  - HTTP API: 브라우저-서버, 앱-서버, 서버-서버 간 데이터 교환

* SSR-서버 사이드 렌더링, CSR-클라이언트 사이드 렌더링
  - SSR: HTML 최종 결과를 서버에서 만들어서 웹 브라우저에 전달. 주로 정적인 화면에 사용함.
  - CSR: 주로 동적인 화면에 사용. 웹 환경을 마치 앱처럼 필요한 부분부분 변경할 수 있음.

* JSP(죽음), 타임리프를 활용한 서버 사이드 렌더링 기술.
  - 백엔드 개발자는 서버 사이드 렌더링 기술 학습이 필수적이다.

#### 자바 백엔드 웹 기술 역사
* 서블릿 > JSP > 서블릿, JSP 조합 MVC 패턴 사용 > MVC 프레임워크 춘추 전국 시대
  - 웹은 개발할 때 고민할 게 이미 많은데, 그 외적인 요소들은 편리하게 처리할 수 있게 프레임워크를 준비했던 모양.

* 개발자들이 불편하게 느꼈던 부분을 굉장히 편리하게 만들어준 것.
  - 서버를 '배포'하는 것도 편하게 만들어줬음.

* 스프링 웹 기술의 분화
  - Web Servlet - Spring MVC
  - Web Reactive - Spring WebFlux: 최신 기술. CPU와 쓰레드 수를 맞춰서 컨텍스트 스위칭 비용을 최소화함.

* 뷰 템플릿
  - JSP: 속도 느림, 기능 부족.
  - 프리마커, 벨로시티: 속도 문제 해결, 다양한 기능.
  - *타임리프*: 내츄럴 템플릿(HTML 모양이 유지됨). 스프링 MVC와 강력한 기능 통합.

<br>

### 섹션 2. 서블릿

#### 프로젝트 생성
* JSP 활용을 위해 War로 패키징
* Postman, lombok: annotation processing, postman 설치
* War 파일은 IntelliJ IDEA로 동작시키면 톰캣을 동작시키지 못한다(버그인 듯). 따라서, 빌드 앤 런은 Gradle로 실행하도록 한다.

#### Hello 서블릿
* 서블릿은 스프링과 무관하긴 하다.
* 스프링 서버는 톰캣을 내장하고 있기 때문에, 이전의 번거로운 과정이 필요가 없다.
* `@ServletComponentScan`

* `@WebServlet(name = "helloServlet", urlPatterns = "/hello")`를 통해서 localhost:8080/hello를 통해 해당 서블릿을 불러올 수 있게 설정할 수 있다.


* 아래와 같은 코드 실행 시 다음과 같은 로그가 출력된다.
```java
System.out.println("HelloServlet.service");
System.out.println("request = " + request);
System.out.println("response = " + response);
```
```
HelloServlet.service
request = org.apache.catalina.connector.RequestFacade@1df0f4e4
response = org.apache.catalina.connector.ResponseFacade@14b616a6
```

* `http://localhost:8080/hello?username=kim`와 같은 식으로 쿼리 파라미터를 전달할 수도 있음.
  - 이것을 서버의 request에서 꺼낼 수 있다.

* 서블릿이 Http 요청 및 응답을 제어하기 편하도록 만들어줬다.

#### HttpServletRequest - 개요
* HttpServletRequest 역할

* START LINE:  HTTP 메소드 / URL / 쿼리 스트링 / 스키마, 프로토콜
* 헤더: 헤더 조회
* 바디: form 파라미터 형식 조회 / message body 데이터 직접 조회

* HttpServletRequest 객체는 여러가지 부가기능도 함께 제공한다.

* 해당 HTTP 요청이 시작부터 끝날 때까지 유지되는 임시 저장소 기능


#### HttpServletRequest - 기본 사용법
* `request.getLocale();`: Locale 정보를 가져옴. 이를 통해 언어 설정을 할 때 활용할 수 있고, getLocale()을 통해 가져오는 Locale은 가장 선호하는 언어 정보임.

  - get의 경우 아래와 같이 나옴
```
[Content 편의 조회]
request.getContentType() = null
request.getContentLength() = -1
request.getCharacterEncoding() = UTF-8
```
  - Postman으로 post 메소드를 통해 text를 함께 첨부해서 보내면 아래와 같은 수신 결과를 반환함.

```
[Content 편의 조회]
request.getContentType() = text/plain
request.getContentLength() = 6
request.getCharacterEncoding() = UTF-8
```

#### HTTP 요청 데이터 - 개요
* HTTP 요청 메시지를 통해 클라이언트에서 서버로 데이터를 전달하는 방법
1. GET - 쿼리 파라미터
  - /url?username=hello&age=20
  - 이미 구글에서 검색할 때만 해도 넘기는 파라미터 수가 엄청남.
2. POST - HTML Form
  - username=hello&age=20
3. POST, PUT, PATCH - HTTP message body
  - HTTP API에서 주로 사용. JSON, XML, TEXT 등을 직접 전달함.


#### HTTP 요청 데이터 - GET 쿼리 파라미터
* `getParameter`와 `getParameterValues`의 사용법.
  - 중복해서 동일한 파라미터를 전송할 일은 거의 없지만, 활용해야 하는 경우엔 `getParameter`를 쓰면 안 된다.


#### HTTP 요청 데이터 - POST HTML Form
* 특징
  - content-type: `application/x-www-form-urlencoded`
  - `<form action="/request-param" method="post">`: 이전에 작성했던 `/request-param` url에 post 메서드로 해당 파라미터를 전송해줌.
  - GET 쿼리 파라미터 조회 방식과 호환됨.
  - postman을 활용해서 x-www-form-urlencoded를 post 메소드로 쏠 수도 있음. 이는 HTML Form과 동일하게 동작함.


#### HTTP 요청 데이터 - API 메시지 바디 - 단순 텍스트
* HTTP message body에 데이터를 직접 담아서 요청
  - ServletInputStream이라는 형태의 데이터를 받아서 String으로 정제해야 함. 내부적으로 어떤 식으로 주고받는지 원리를 알고 있어야 이해 가능할 것으로 생각됨.
```java
ServletInputStream inputStream = request.getInputStream();
String messageBody = StreamUtils.copyToString(inputStream, StandardCharsets.UTF_8);
```

#### HTTP 요청 데이터 - API 메시지 바디 - JSON
* json도 API 메시지 바디를 출력할 때와 동일하게 inputStream을 설정하고, StreamUtils의 copyToString을 활용해 출력할 수 있다.
* 또한, 오브젝트 맵퍼(ObjectMapper, 잭슨 라이브러리)를 활용해서 위의 StreamUtils.copyToString()을 가져나온 다음, 원하는 클래스에 request 데이터를 대입시킬 수 있다.
* 또한, json은 POST HTML Form과 GET 쿼리 파라미터와는 호환이 되지 않는다.


#### HttpServletResponse - 기본 사용법
* HTTP 응답 메시지 생성: HTTP 응답코드 지정, 헤더 생성, 바디 생성.
* 편의 기능 제공: Content-Type, 쿠키, Redirect
* `HttpServletResponse.SC_OK`과 같은 이넘을 쓰는 게 좋다.

* 아래와 같이 HTTP 기본에서 배웠던 것처럼 캐시 무효화같은 헤더를 설정할 수도 있다.
```java
@Override
protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    //[status-line]
    response.setStatus(HttpServletResponse.SC_OK);

    //[response-headers]
    response.setHeader("Content-Type", "text/plain");
    response.setHeader("Cache-Control", "no-cache, no-store, must-revalidate");
    response.setHeader("Pragma", "no-cache");
    response.setHeader("my-header", "hello");

    PrintWriter writer = response.getWriter();
    writer.write("OK");
}
```

* 쿠키를 헤더에 하드 타이핑할 수도 있지만, 객체 형식으로 Cookie를 만들고, 이를 세팅할 수 있도록 아래와 같이 구현할 수도 있다. 이는 서블릿 리스폰스 클래스가 지원하는 기능.
```java
private void cookie(HttpServletResponse response) {
    //Set-Cookie: myCookie=good; Max-Age=600;
    //response.setHeader("Set-Cookie", "myCookie=good; Max-Age=600");
    Cookie cookie = new Cookie("myCookie", "good");
    cookie.setMaxAge(600); //600초
    response.addCookie(cookie);
}
```

* Response를 해서 메시지 바디를 채워 보내면 브라우저가 자동으로 띄워주긴 함.

#### HTTP 응답 데이터 - 단순 텍스트, HTML
* `PrintWriter writer = response.getWriter();`로 writer를 따다가 직접 html을 작성해서 넘겨주면 이를 브라우저에서 출력해줌.


#### HTTP 응답 데이터 - API JSON
* 나중에는 객체만 돌려줘도 바로 response body에 전달되도록 구현할 수 있다.
* `response.getOutputStream().print(result);`를 통해서 출력하도록 설정하자. 그렇지 않은 경우엔 쓸데없이 `Content-Type: application/json;charset=utf-8`이라는 정보가 추가된다.


### 섹션 3. 서블릿, JSP, MVC 패턴

#### 회원 관리 웹 애플리케이션 요구사항
* repository와 member 클래스 형성

#### 서블릿으로 회원 관리 웹 애플리케이션 만들기
* html 만드는 게 정말 끔찍함
  - 이를 보완하기 위한 템플릿 엔진을 활용.

#### JSP로 회원 관리 웹 애플리케이션 만들기
* 주의: 실행할 때는 .jsp까지 다 적어줘야 한다.
* `<%`, `%>` 블럭을 활용해서 자바 코드를 작성할 수 있고, `<=%`, `%>` 블럭을 활용해서 변수를 출력할 수 있다.
* JSP는 비즈니스 로직과 html을 분리해주질 못한다.

* 서블릿으로 개발할 때는 뷰를 위한 HTML 작성 작업이 자바 코드와 섞여 복잡해짐
* JSP를 사용하여 뷰를 생성하는 HTML은 깔끔하게 활용. 중간에 동적으로 변경이 필요한 부분에 자바 코드 도입.
* 코드를 잘 보면, JAVA 코드, 데이터를 조회하는 리포지토리 등, 다양한 코드가 JSP에 노출되어 있음. JSP가 너무 많은 역할을 수행한다.

* 이런 문제들을 보완하고자 MVC 패턴이 등장했다.
  - Model, View, Controller의 줄임말로, 비즈니스 로직은 서블릿처럼 담당하는 객체를 따로 두고, JSP는 목적에 맞게 HTML로 화면을 그리는 일에 집중하게 만듦.
  - 지금까지 만든 서버를 리팩토링 해보자.

#### MVC 패턴 - 개요
* 너무 많은 역할
* 변경의 라이프 사이클 차이: '변경 주기가 다른 것들은 분리한다'는 개념이 중요.
  - 연관성의 차이를 말하는 것 같은데

* Controller는 HTTP 요청을 받아 파라미터를 검증하고, 비즈니스 로직을 실행. 모델을 조작
* View는 컨트롤러가 조작한 모델을 참고하여 출력함.
* Controller는 중간에서 중계하는 역할만 한다고 생각하면 됨. 비즈니스 로직은 서비스에 넘겨주는 게 좋다.

#### MVC 패턴 - 적용
* WEB-INF 디렉토리 안에 있는 파일들은 외부에서 직접적인 호출이 불가하다. 컨트롤러를 통해서만 호출된다.

> TIP. redirect와 forward의 차이: forward는 서버 내부적으로 다른 URL에 연결되는 것이기 때문에, 1번의 호출로 곧장 연결된다. 클라이언트는 URL이 바뀌었다는 걸 인지할 수 없다.

* 프로퍼티 접근법을 활용한 jsp 작성
```jsp
<ul>
    <li>id=${member.id}</li>
    <li>username=${member.username}</li>
    <li>age=${member.age}</li>
</ul>
```

#### MVC 패턴 - 한계
* MVC 패턴을 적용한 덕분에 역할이 명확하게 구분됨.
* 그러나, 컨트롤러들은 반복되는 코드가 많음.

```java
RequestDispatcher dispatcher = request.getRequestDispatcher(viewPath);
dispatcher.forward(req, res);
```

* request와 response를 일부만 쓰거나 활용하지 않음.
```java
HttpServletRequest request, HttpServletResponse response
```

* Front Controller를 둬서 공통 로직을 처리하게 하고, controller를 호출하도록 계획함.


### 섹션 4. MVC 프레임워크 만들기
* 점진적으로 개선하면서 스프링의 구조를 이해할 수 있게 된다.

#### 프론트 컨트롤러 패턴 소개
* 프론트 컨트롤러 역할을 하는 서블릿을 하나 도입하는 것으로 공통 로직을 처리.
* 프론트 컨트롤러를 제외한 나머지 서블릿은 직접 호출할 필요가 없게 됨.


#### 프론트 컨트롤러 도입 - v1
* url을 전달받으면 매핑 정보를 확인하고 해당하는 서블릿을 호출해주는 방식으로 구현됨.
* 컨트롤러를 인터페이스로 만듦
  - process라고 '처리'하는 메소드를 만듦. 전체를 포괄할 수 있는 동작의 이름으로 메소드 이름을 지음.

> 꿀팁: 구조를 개선할 때는 세부 로직을 건들지 않고 틀만 바꾸는 데 집중해야 한다. 한꺼번에 개선하려고 하면 어려움을 겪는다.

#### View 분리 - v2
* View는 후처리 로직. MyView 클래스를 만들어서 render 과정을 수행하도록 수정.

#### Model 추가 - v3
* 컨트롤러는 서블릿 기술을 몰라도 동작한다. 그러니 관련 인자들을 제거해도 된다.
* request 객체의 역할을 Model 객체를 사용해 대체할 것.
* 프론트 컨트롤러가 하나기 때문에, 총무를 맡기는 것. 관련 로직을 다듬는 등의 역할을 수행하게 설정.

#### 단순하고 실용적인 컨트롤러 - v4
* 개발자가 단순하고 편리하게 사용할 수 있어야 한다. 실용성이 좋아야 한다.
* 만드는 사람이 힘들면 사용하는 사람이 편하다.

#### 유연한 컨트롤러1, 2
* 어댑터의 도입.


## 수요일 진도
### 섹션 5. 스프링 MVC - 구조 이해

#### 스프링 MVC 전체 구조
* 디스패처 서블릿이 스프링 MVC의 핵심이다.
* 스프링 부트는 `DispatcherServlet`을 서블릿으로 자동 등록하면서 모든 경로`(urlPattern="/")`에 대해 매핑한다.

> `DispatcherServlet`의 `doDispatch` 메소드가 최종 호출된다는 게 포인트

#### 핸들러 매핑과 핸들러 어댑터
* 어노테이션 기반으로 넘어가기 전에 활용됐던 컨트롤러.
* 스프링 빈의 이름을 url 패턴으로 맞춤

#### 뷰 리졸버
* 다음과 같이 뷰 리졸버의 설정을 해줘야 물리 주소로 변환할 수 있음.
```
spring.mvc.view.prefix=/WEB-INF/views/
spring.mvc.view.suffix=.jsp
```


#### 스프링 MVC - 시작하기
* 스프링 MVC의 약한 기능이 어노테이션 컨트롤러 등장과 함께 완벽하게 보완되었다.
  - 어노테이션 기반 컨트롤러는 매우 유연하고 편리하다.

* `@RequestMapping`
  - `RequestMappingHandlerMapping`
  - `RequestMappingHandlerAdapter`

* `@Controller`: 컴포넌트 스캔 대상이 되고, 스프링 빈에 자동으로 등록된다.
  - 스프링 MVC에서 어노테이션 기반 컨트롤러로 인식한다.

* `@RequestMapping`: 요청 정보를 매핑한다. 해당 URL이 호출되면 이 메소드가 호출된다.


#### 스프링 MVC - 컨트롤러 통합
* 리퀘스트 매핑을 클래스에 적용할 수 있고, 그 클래스 내 메소드들을 각각 매핑을 할 수 있기 때문에 컨트롤러를 하나로 합칠 수 있다.

#### 스프링 MVC - 실용적인 방식
* 놀랍게도 ModelAndView를 넘겨줘도 되고, String을 넘겨줘도 된다. String을 넘겨준 경우, 이를 뷰 이름으로 인식하고 프로세스를 진행한다.
* `@RequestMapping("/save")` 같은 식으로 작성하면 메소드 구분이 아직은 안 된 상태이다. 어떤 메소드가 오든 동일 처리를 하는 것이다.
* `@RequestMapping(value = "/save", method = RequestMethod.GET)`: 매핑 경로(값)은 `/save`이며, 이에 대해 허용되는 메소드는 GET으로 지정됨.
* 이제 리퀘스트 매핑에 메소드 쓰는 게 번거로우니 GetMapping, PostMapping 등과 같은 어노테이션을 도입함.

<br>

### 섹션 6. 스프링 MVC - 기본 기능
#### 로깅 간단히 알아보기
* 로깅 라이브러리: SLF4J, Logback
  - SLF4J은 인터페이스, 이 구현체가 Logback

* application.properties에서 아래와 같이 로깅 레벨을 설정할 수 있다. 출력 여부를 설정으로 조절할 수 있다.
```
#hello.springmvc 패키지와 그 하위 로그 레벨 설정
logging.level.hello.springmvc=trace

```
  - 로깅 중요도는 `trace < debug < info < warn < error`순이다.
  - 설정한 레벨보다 중요도가 낮거나 같은 로그들만 띄워준다. 디폴트 값은 info다.
  - `logging.level.root=debug` 최상위 패키지의 로그 레벨을 debug 레벨로 설정한 것이고, 이에 따라 엄청나게 많은 동작이 로깅된다.
  - `private final Logger log = LoggerFactory.getLogger(getClass());`는 롬복의 `@Slf4j`로 대체될 수 있다.

* 반면, println을 사용한다면, 고객 요청에 따라 모든 로그를 출력하게 되고, 이로 인해 과부하가 걸리게 된다.

* `@RestController`는 반환 값으로 뷰를 찾는 것이 아니라, HTTP 메시지 바디에 바로 입력한다.

* `log.debug("data="+data)`: 문자열을 연산한 뒤에 결과를 갖고 있으면서 호출을 기다리게 된다. 쓸데없는 연산이 추가로 일어난다.


#### 요청 매핑
* 요청에 따라 어떤 컨트롤러가 호출되어야 하는지 설정하는 것.
* 원래는 "/hello-basic"과 "/hello-basic/"은 다른 url이지만, 스프링 2.0에서는 둘을 같게 처리해준다.
  - 스프링 3.0에서는 둘을 구분한다.
* `RequestMapping`에는 쿼리 파라미터(params)을 설정할 수도 있고, 헤더(headers)를 설정할 수도 있고, 필요로 하는 데이터 형태인 컨숨(consumes)을 설정할 수도 있다. 컨숨의 반대로 특정 형태의 컨텐츠를 만들어주는 경우에는 프로듀스(produces)를 설정할 수 있다.
* 프로듀스는 Accept 헤더에 명기된 형식의 파일만 처리할 수 있음. 뭐든지 받을 수 있는 상태라면 `Accept=*/*`로 설정함.


#### 요청 매핑 - API 예시
* 요즘 사용하는 URI 설계를 따라 매핑처리.


#### HTTP 요청 - 기본, 헤더 조회
* `MultiValueMap<String, String> headerMap`으로 받는 이유: 같은 key 값에 여러 값을 받을 수 있음.
  - cpp의 `unordered_multimap<string, string>`
* 인자와 반환값 모두 굉장히 폭넓게 선택할 수 있다. [공식 레퍼런스 링크](https://docs.spring.io/spring-framework/docs/current/reference/html/web.html#mvc-ann-arguments)


#### HTTP 요청 파라미터 - 쿼리 파라미터, HTML Form
* *클라이언트에서 서버로 요청 데이터를 전달할 때는 주로 다음 3가지 방법을 사용한다.*
1. GET - 쿼리 파라미터: `/url?username=hello&age=20`
2. POST - HTML Form: `content-type: application/x-www-form-urlencoded`
3. POST, PUT, PATCH - HTTP message body에 데이터를 직접 담아서 요청: `HTTP API에서 주로 사용, JSON, XML, TEXT`


#### HTTP 요청 파라미터 - @RequestParam
* 변수가 단순타입이면 간단하게 변수명만 가지고 뺴낼 수 있다.

```java
@ResponseBody
@RequestMapping("/request-param-v3")
public String requestParamV3(
        @RequestParam String username,
        @RequestParam int age) {

    log.info("username={}, age={}", username, age);
    return "ok";
}
```

* RequestParam을 생략하면 혼동을 줄 수도 있긴 하니 명기하는 편이 낫지 않나 싶음.
  - 이게 코드 내부적으로 가져오는 인자인지 뭔지 분간이 안 되니까.

* `@RequestParam(required = false) int age`와 같이 작성하면 age에 값이 안 들어가도 서버에는 문제 없이 전달된다. 그러나, int는 null일 수 없기 때문에 서버 내부 오류가 발생한다.

* *`@RequestParam(defaultValue = "guest") String username`를 설정하면 값이 없으면 `username = "guest"`가 된다. username에 빈 문자열을 넘겨줘도 guest로 설정된다.*


#### HTTP 요청 파라미터 - @ModelAttribute
* 롬복 @Data: @Getter , @Setter , @ToString , @EqualsAndHashCode , @RequiredArgsConstructor를
자동 적용.

* 스프링 MVC가 `@ModelAttribute`에 대해 setter를 호출한다.
  - 롬복을 통해 설정해뒀기 때문에 간단하게 연결이 된다.
  - 잘못된 변수가 전달되면 바인딩에 실패하고, 예외가 발생한다.

> 실무팁: 예외 처리 및 검증에 70%정도의 에너지를 써야한다.

* @ModelAttribute도, @RequestParam도 생략할 수 있어 혼동될 수 있다.
  - String, int, Integer 같은 단순 타입 = @RequestParam
  - argument resolver 로 지정해둔 타입 외에는 @ModelAttribute로 처리된다.


#### HTTP 요청 메시지 - 단순 텍스트
* 요청 파라미터가 아니면 정보를 RequestParam이나 ModelAttribute로 전달받을 수 없다.

* InputStream과 Writer를 인자로 바로 받을 수 있다. 이를 활용하면 간단하게 코드를 작성할 수 있다.
  - 그러나 스트림으로 받고 Writer로 받는 것 역시 굉장히 구체적인 로직이기 때문에 깔끔하지 못하다.

* HttpMessageConvertor를 활용해서 바디를 뽑을 수 있다.
  - HttpEntity로 헤더와 바디를 조회할 수 있다. 또한 이를 반환값으로 설정해서 응답에도 활용할 수 있다.
  - 그러나 요청 파라미터 조회 기능은 없다.
  - RequestEntity와 ResponseEntity가 HttpEntity를 상속받아 동작하며, 추가 메소드를 제공한다.


#### HTTP 요청 메시지 - JSON
* `@RequestBody HelloData helloData`: `@RequestBody`를 생략하면 `@ModelAttribute`로 동작하고, 파라미터가 전달되지 않기 때문에 값이 전달되지 않는다.
* Content-type이 정확하게 지정되어야 이를 인식하고 정확하게 바꿔준다.

* Accept 헤더에 따라서 객체를 @ResponseBody를 통해 변환되는 컨텐츠 형식이 결정된다 생각하면 될 듯.


#### 응답 - 정적 리소스, 뷰 템플릿
* `/static`, `/public`, `/resources`, `/META-INF/resources`
  - 이런 곳이 루트 경로. 이후에 생성되는 디렉토리들은 하위 디렉토리들로써 슬래쉬를 추가하며 접근됨.
* 뷰 템플릿: `/resources/templates`이 기본경로로 지정됨.

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<p th:text="${data}">empty</p>
</body>
</html>
```
* text 부분을 바꿔치기 한다는 말이고, 그때, 변수 이름은 data가 된다. 그래서, controller 코드에 addAttribute 등을 할 때, attribute(속성) 이름을 data로 설정한다.

```java
@RequestMapping("/response/hello")
public void responseViewV3(Model model) {
    model.addAttribute("data", "hello!");
}
```

* 위와 같이 호출하는 경우도 있는데, 이건 그냥 템플릿을 직접 호출하는 거고, 그때, 템플릿에서 명시된 변수들에 값을 넣어준 뒤, 그 HTML을 반환하는 것이라고 이해됨.
  - `@ResponseBody`와 `@Controller`를 합친 것이 `@RestController`이다.

#### HTTP 응답 - HTTP API, 메시지 바디에 직접 입력
* HTTP API를 제공하는 경우 HTML이 아니라 데이터를 직접 전달해야 한다.
  - `@RestController` 활용하면 다이렉트로 반환이 가능하긴 할 듯.


#### HTTP 메시지 컨버터
* `@ResponseBody`를 사용하면 viewResolver 대신 HttpMessageConverter가 동작한다.
* 스프링에선 우선 ByteArray인지, String인지, json인지 순차적으로 확인하게 된다.
* 지정된 content-type은 우선순위가 밀린다. 동작하는 컨버터는 Controller의 인자 유형에 따라서 일차적으로 결정된다(강의자료 47페이지).
  - 다만, json을 처리하려면 반드시 json을 지원한다고 표기가 되어야 한다. 안 그러면 해당 컨버팅을 시도도 안 한다.


#### 요청 매핑 헨들러 어뎁터 구조
* `RequestMappingHandlerAdapter`가 컨트롤러를 보고 준비해야 하는 인자를 확인한 뒤, 이를 넣어준다.
* `ArgumentResolver`가 인자를 준비하기 위해 날 것의 응답(HTTP 메시지)을 해석한 뒤 넘겨줘야 한다고 생각하면 될 듯.
* 핸들러 어댑터의 역할이 어디까지인지 공부할 필요가 있을 듯함.
* HTTP 메시지 컨버터: Argument Resolver가 @RequestBody 또는 HttpEntity를 전달해줘야 할 때, 또는 Return Value Handler가 @ResponseBody 또는 HttpEntity를 전달해줘야 할 때 HTTP 컨버터를 거쳐서 처리할 수 있는 형태로 만든 후에 넘겨준다.

<br>

### 섹션 7. 스프링 MVC - 웹 페이지 만들기
#### 상품 도메인 개발
* @Data는 많은 것들이 오픈되기 때문에 사용 시 주의할 것.
* DTO: Data Transfer Object로, 필요한 데이터만 전달하기 위한 임의의 오브젝트를 생성해서 대응해주는 방식.
* 간단하게 아이템을 저장하고 업데이트 하는 등의 로직을 만듦: 핵심 도메인 로직

#### 상품 서비스 HTML
* 부트스트랩을 활용해서 깔끔한 폼으로 구현 가능함
* 정적 리소스는 단순하게 운영체제 안에서도 열어볼 수 있다.
* 서비스를 운영한다면 HTML을 공개해버리면 안 된다.


#### 상품 목록 - 타임리프
* `@RequiredArgsConstructor`를 사용하면 final이 붙은 필드를 생성자로 주입할 수 있도록 스프링이 자동 설정해준다.
  - `private final ItemRepository itemRepository;`가 있을 때, 아래와 같은 생성자를 자동으로 만들어주는 것.

```java
    public BasicItemController(ItemRepository itemRepository) {
        this.itemRepository = itemRepository;
    }
```

* `<html>`이라 되어 있던 태그를 `<html xmlns:th="http://www.thymeleaf.org">`로 변경함.
  - 무조건 `xmlns:th`라고 해야 정상작동 되는 듯. th를 다른 변수로 고칠 수 있을 줄 알았는데 그렇진 않은 듯.

* `th:onclick="|location.href='@{/basic/items/add}'|"`
  - 타임리프 문법에 따라, ||를 활용해 raw string을 보내는 듯함.

* `th:href="@{/basic/items/{itemId}(itemId=${item.id})}"`로 선언해서 동적으로 경로를 제어할 수 있음.
```html
<td><a href="item.html" th:href="@{/basic/items/{itemId}(itemId=${item.id})}"
      th:text="${item.id}">상품id</a></td>
```

* 화면을 html 형태로 유지해주기 때문에 '내츄럴 템플릿'이라고 한다.

* 타임리프 핵심
  - 핵심은 th:xxx 가 붙은 부분은 서버사이드에서 렌더링 되고, 기존 것을 대체한다. th:xxx 이 없으면 기존 html의 xxx 속성이 그대로 사용된다.
  - HTML을 파일로 직접 열었을 때, th:xxx 가 있어도 웹 브라우저는 th: 속성을 알지 못하므로 무시한다
  - 따라서 HTML을 파일 보기를 유지하면서 템플릿 기능도 할 수 있다.


#### 상품 상세
* `th:onclick="|location.href='@{/basic/items}'|"`: 절대 경로로 이동
* `th:onclick="|location.href='@{basic/items}'|"`: 현 경로에서 basic/items를 더 들어감.


### 상품 등록 처리 - @ModelAttribute
* @ModelAttribute - 요청 파라미터 처리
  - @ModelAttribute 는 Item 객체를 생성하고, 요청 파라미터의 값을 프로퍼티 접근법(setXxx)으로 입력해준다.

* @ModelAttribute - Model 추가
  - @ModelAttribute 는 중요한 한가지 기능이 더 있는데, 바로 모델(Model)에 @ModelAttribute로 지정한 객체를 자동으로 넣어준다. 지금 코드를 보면 model.addAttribute("item", item) 가 주석처리 되어 있어도 잘 동작하는 것을 확인할 수 있다.

  - 모델에 데이터를 담을 때는 이름이 필요하다. 이름은 @ModelAttribute 에 지정한 name(value) 속성을 사용한다. 만약 다음과 같이 @ModelAttribute 의 이름을 다르게 지정하면 다른 이름으로 모델에 포함된다.

* 아래 둘은 같은 동작을 하는 듯한데
  - `@ModelAttribute("hello") Item item`: 
  - `model.addAttribute("hello", item);` `item` 객체를 모델에 `hello`라는 이름으로 저장함

* `@ModelAttribute Item item`: 모델에 item이라는 이름으로 담김. 이는 첫 글자를 소문자로 변경한 이름을 자동으로 활용하는 규칙에 따름.

* 아래와 같이 완전히 생략해도 된다.
  - 이 경우, 기본형 변수가 아니면 `@ModelAttribute`가 `"item"`라는 이름으로 자동 지정된다.
```java
    @PostMapping("/add")
    public String addItemSimplest(Item item) {
        itemRepository.save(item);
        return "basic/item";
    }
```

#### 상품 수정
* 리다이렉트 하는 법: `return "redirect:/basic/items/{itemId}";`

#### PRG패턴: Post/Redirect/Get
* 상품을 등록하고 난 후, 상품 상세를 받게 됨. 이를 새로고침하면 POST가 다시 제출되고, 이에 따라 상품을 계속 등록하게 됨: 새로고침은 마지막에 요청했던 데이터를 다시 서버에 전송하는 것.
* redirect는 사용자가 새롭게 요청한 것처럼 바꿔주는 역할을 하는 듯.
  - 서버에서 클라이언트에 다시 연결을 시도할 요청 데이터를 넘겨줘서 서버에서 의도한 대로 클라이언트가 재요청할 수 있게 만드는 것.


#### RedirectAttributes
```java
    @PostMapping("/add")
    public String addItemV6(Item item, RedirectAttributes redirectAttributes) {
        Item savedItem = itemRepository.save(item);
        redirectAttributes.addAttribute("itemId", savedItem.getId());
        redirectAttributes.addAttribute("updated", true);
        return "redirect:/basic/items/{itemId}";
    }
```
* RedirectAttributes를 활용해서 redirect 되었을 때 전달하고 싶은 인자들을 추가할 수 있다.
  - thymeleaf를 사용해서 넘겨받은 인자를 확인할 수 있고, 전달받은 값들에 따라서 원하는 동작을 설정할 수 있다.