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


## 화요일 진도
### 섹션 4. MVC 프레임워크 만들기
* 8강 ∙ 2시간 33분

#### 프론트 컨트롤러 패턴 소개 06 : 41
#### 프론트 컨트롤러 도입 - v1 24 : 24
#### View 분리 - v2 16 : 41
#### Model 추가 - v3 28 : 51
#### 단순하고 실용적인 컨트롤러 - v4 16 : 04
#### 유연한 컨트롤러1 - v5 34 : 06
#### 유연한 컨트롤러2 - v5 15 : 41
#### 정리 10 : 35


## 수요일 진도
### 섹션 5. 스프링 MVC - 구조 이해
* 7강 ∙ 1시간 22분

#### 스프링 MVC 전체 구조 16 : 14
#### 핸들러 매핑과 핸들러 어댑터 14 : 32
#### 뷰 리졸버 09 : 36
#### 스프링 MVC - 시작하기 16 : 54
#### 스프링 MVC - 컨트롤러 통합 06 : 48
#### 스프링 MVC - 실용적인 방식 12 : 38
#### 정리 05 : 45

### 섹션 6. 스프링 MVC - 기본 기능
#### 15강 ∙ 3시간 36분
#### 프로젝트 생성 07 : 43
#### 로깅 간단히 알아보기 23 : 17
#### 요청 매핑 21 : 13
#### 요청 매핑 - API 예시 09 : 04


## 목요일 진도
### 섹션 6. 스프링 MVC - 기본 기능
#### HTTP 요청 - 기본, 헤더 조회 12 : 41
#### HTTP 요청 파라미터 - 쿼리 파라미터, HTML Form 07 : 22
#### HTTP 요청 파라미터 - @RequestParam 17 : 09
#### HTTP 요청 파라미터 - @ModelAttribute 10 : 10
#### HTTP 요청 메시지 - 단순 텍스트 15 : 04
#### HTTP 요청 메시지 - JSON 14 : 36
#### 응답 - 정적 리소스, 뷰 템플릿 14 : 46
#### HTTP 응답 - HTTP API, 메시지 바디에 직접 입력 10 : 10
#### HTTP 메시지 컨버터 17 : 17
#### 요청 매핑 헨들러 어뎁터 구조 22 : 27
#### 정리 13 : 28


## 금요일 진도
### 섹션 7. 스프링 MVC - 웹 페이지 만들기
* 12강 ∙ 2시간 11분

#### 프로젝트 생성 03 : 45
#### 요구사항 분석 07 : 37
#### 상품 도메인 개발 16 : 17
#### 상품 서비스 HTML 08 : 43
#### 상품 목록 - 타임리프 31 : 00
#### 상품 상세 07 : 50
#### 상품 등록 폼 07 : 04
#### 상품 등록 처리 - @ModelAttribute 12 : 52
#### 상품 수정 11 : 48
#### PRG Post/Redirect/Get 10 : 13
#### RedirectAttributes 07 : 20
#### 정리 07 : 19

## 금요일 또는 주말 중 마무리
### 섹션 8. 다음으로
* 1강 ∙ 40분

#### 다음으로 40 : 59