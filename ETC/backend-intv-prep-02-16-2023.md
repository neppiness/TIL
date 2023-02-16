[TIL on February 16th, 2023](../TIL/2023/02/02-16-2023.md)
### Node.js에 대해서
#### Node.js란?
* Node.js는 자바스크립트 런타임 환경임. 아래 특징들을 가짐.
  1. 크롬의 V8 엔진으로 구동됨
  2. 오픈소스, 크로스 플랫폼 
  3. 웹 브라우저 밖에서도 자바스크립트를 쓸 수 있도록 만들어주는 환경
* 브라우저에서 웹 사이트와 웹 어플리케이션을 실행
* 컴퓨터에서 nodejs를 통해 백엔드 및 서버, 프론트 엔드, 스크립팅과 자동화까지 수행 가능함.

#### 노드를 배우면 좋은 점
* 브라우저, 서버 모두에 자바스크립트를 활용할 수 있음.
* switch context 작업을 안 해도 되는 것이 굉장한 장점
* 서버 사이드 렌더링 결과와 브라우저 렌더링 결과를 일치시키기 위해서 node.js로 통합하는 게 굉장히 효과적이었을 것.
* 생산성과 성능이 좋음.
* npm을 활용해 라이브러리를 폭넓게 활용할 수 있음.

#### 노드의 특징
1. Javascript Runtime Env., using V8 engine (C++ based)
2. Single Thread
  - 프로세스에는 여러 스레드가 있다. 이를 통해 여러가지 일을 할 수 있다.
  - CPU 연산이 빠르기 때문에 여러 일들을 매우 짧은 간격으로 하기 때문에 동시에 하는 것처럼 보이는 것이다.
  - 이렇게 놓고 보면 스레드가 많을수록 좋은 것 같지만, 당연히 리소스가 많이 듦.
  - 자바는 멀티스레딩을 할 수 있게 언어 차원에서 허용한다.

* 자바스크립트는 멀티스레딩을 할 수 없다. 그래서 한 번에 한 작업을 처리할 수 있다. 이를 효율적으로 처리하기 위한 자바스크립트의 도구들이 아래와 같다.
3. Non-blocking IO: blocking은 동기적인 처리 방식이고, Non-blocking은 비동기적인 처리 방식이다. callback을 통해 다음 일을 처리할 수 있다.
4. Event-Driven: callback을 던져두고 놀다가 완료되면 event를 발생시키고, 이를 트리거로 작업을 수행할 수 있다.

#### 노드 내부
* Task queue가 있어서, 발생된 이벤트를 갖고 있다가 call stack에 전달해줌.

* 이벤트 루프: call stack이 빌 때까지 기다렸다가 call stack에 옮긴다. (중간에 쌓는 게 아니라? 메인 함수는 기본적으로 call stack에 있는 것 아닌가?)
* Node.js의 API들은 멀티스레딩이 가능하다. 따라서 싱글스레드 환경이지만, 어떤 일을 할지 전달만 잘해주면 문제 없이 멀티스레딩 하듯 활용할 수 있다.

* Libuv는 라이브러리로, 운영체제와 무관하게 non-blocking IO를 수행함.
* 메인 스레드는 가벼운 연산만 수행하게 만드는 것이 좋다(가볍다는 것의 기준?). 이미지 연산, 비디오 인코딩 같은 작업을 메인 스레드가 직접하면 안 된다.

#### 노드 서버와 기존 서버의 차이
* 스레드 풀이 있음.
* 클라이언트의 요청이 있으면 이를 처리하기 위해 스레드를 할당함. 한 클라이언트에 한 스레드가 붙어서 전담하며 모든 작업을 도맡아하는 방식
* node.js 서버는 메인스레드가 요청을 받고, 처리해야 하는 곳으로 넘기는 방식.
<br>

### 웹 기초
#### HTTP/HTTPS
* HTTP는 Hypertext Transfer Protocol의 약자, request-response protocol. 
  - HTTP는 클라이언트와 서버 간에 주고 받는 데이터를 가로채 확인하기 쉽다.
* HTTPS: Hypertext Transfer Protocol Secure.
  - TLS/SSL과 같은 암호화된 방식으로 데이터를 주고받기 때문에 안전하다.

* HTTP v1(1997): 텍스트 기반, 비압축성 헤더들, 한 파일을 한 번만 주고받을 수 있음
* HTTP v2(2015): raw 데이터 형태로 주고받음. 압축된 헤더. 여러 파일을 동시에 주고받을 수 있음.
* HTTP v3(2019): UDP 베이스.

* client와 server, 두 개의 컴퓨터가 통신을 한다.
  1. TCP 연결 수행
  2. 클라이언트가 request method와 url과 헤더를 가지고 서버에 요청함.
  3. 서버는 이에 대한 response를 함. status를 표시하는 코드를 포함해서 보내줌.

#### Status codes
1. 100단위: 정보
  - 100 Continue / 102 Processing
2. 200단위: 성공
  - 200 OK / 201 Created / 204 No Content
3. 300단위: 리디렉션
  - 301 Moved Permanently / 302 Found / 303 See Other / 307 Temporary Redirect / 308 Permanent Redirect
4. 400단위: 클라이언트 에러
  - 400 Bad Request / 401 Unauthorized / 403 Forbidden / 404 Not Found / 405 Method Not Allowed / 409 Confilct
5. 500단위: 서버 에러
  - 500 Internet Server Error / 502 Bad Gateway / 503 Service Unavailable
* 그외 상태 코드는 [다음에서 확인 가능하다.](https://developer.mozilla.org/ko/docs/Web/HTTP/Status)

#### Request
* URL: Uniform Resource Locator
  - GET: 200 OK / 401 Unauthorized / 403 Forbidden / 404 Not Found / 405 Method Not Allowed
  - POST: 201 Created / 401 Unauthorized / 403 Forbidden / 404 Not Found / 409 Conflict
  - PUT, DELETE, PATCH: 200 OK / 204 No Content / 403 Forbidden / 404 Not Found / 405 Method Not Allowed
  - HEAD, OPTIONS, TRACE: 200 OK / 401 Unauthorized / 403 Forbidden / 404 Not Found / 405 Metehod Not Allowed
* 서버에 있는 데이터를 바꾸지 않는 메소드: GET, HEAD (GET without body), OPTIONS, TRACE
* 서버에 있는 데이터를 변경하는 메소드: POST, PUT, DELETE, PATCH

* Safe: 읽기만 하는 operation은 안전하다.
* Idempotent: 멱등성, 동일한 요청을 반복했을 때 서버의 상태가 유지되는가-
* Cacheable: 캐싱 가능 여부

* PUT은 url 전체를 업데이트 하는 것이기 때문에 무엇인가 추가되는 게 아니라 멱등성을 갖는다.
* PATCH는 url의 일부 정보를 '추가'할 때 멱등성을 갖지 않는다.

#### HTTP Headers
* Stateless Protocol
  - 요청의 순서같은 게 있지 않음. 선후관계가 존재하거나 그런 게 아님. 
* Sessions & Cookies
  - 클라이언트가 GET 명령으로 로그인 정보를 보내면, 서버에서는 header를 통해 쿠키를 세팅한다. 쿠키는 브라우저가 잠시 보관하는 파일로, 권한 토큰과 같은 것들이 해당된다.
* Headers
  - 표준화가 된 Authorization을 활용하는 게 좋다.
<br>

### RESTful APIs
#### REST가 무엇인가?
* RESTful API (application Programming Interface)
  - REST는 무엇인가: Representational State Transfer, 대표하는 상태를 전송하는 것.
  - 서버에 다양한 데이터가 존재. 이를 분류해서 URL 형태로 접근할 수 있게 열어줌.
  - Software Architectural Style로, 웹 서비스의 가이드라인임.

* RESTful System의 6가지 조건
  1. Client-server architecture: 서버는 클라이언트 종류에 무관하게 데이터를 제공할 수 있어야 한다.
  2. Statelessness: 하나의 요청이 독립성을 가져야 한다.
  3. Cacheability: 캐시가 가능할 때 캐싱할 수 있도록 설계해야 한다.
  4. Layered System: 클라이언트가 서버 구조와 무관하게 API를 활용할 수 있어야 한다.
  5. Code on demand: 클라이언트가 원한다면 클라이언트에서 서버에 직접 요청하는 코드를 보내줄 수 있다.
  6. Uniform interface: RESTful system인지 아닌지 결정을 하는 데 가장 중요한 요소.

* Uniform interface의 4가지 특징
  1. Resource Identification in requests: 클라이언트 요청에서 서버에 어떤 데이터를 요청하는지 식별해야 한다. 서버에서 데이터를 어떻게 관리하든 클라이언트가 이해할 수 있는 형태로 보내줘야 한다. 
  2. Resource manipulation through representations: 서버로부터 받은 데이터를 어떻게 더 처리할 수 있는지 알 수 있어야 한다.
  3. Self-descriptive messages: 서버에서 response할 때 헤더에 전송하는 데이터 타입을 정확히 알려줘야 한다.
  4. Hypermedia as the engine of application state (HATEOAS): 어떤 url을 활용해야 하는지 서버에 쿼리를 할 수 있어야 한다.

* 웹 API 디자인
  - CRUD: create, read, update and delete를 할 수 있어야 한다.
  - Create-POST, Read-GET, Update-PUT, Delete-DELETE
  - 이전에 `GET, HEAD (GET without body), OPTIONS, TRACE, POST, PUT, DELETE, PATCH`와 같이 다양한 Request가 있었는데, 이를 4가지로 압축한다는 걸 보게 됨. 그러나, 특별히 이게 Restful APIs의 원칙에는 포함되지 않았던 듯함.
  
* 좋은 API 설계
  - GET: `/posts`
  - POST: `/posts`
  - GET: `/posts/1`
  - PUT: `/posts/1`
  - DELETE: `/posts/1`
  - GET: `/tags/?postId=1`: 의미가 명확해짐. 태그를 가져오고 싶은데, 그 대상은 postId가 1인 것.
  - GET: `/tags/?query=cool`: 태그를 가져오고 싶은데, cool 태그가 달린 것을 가져오겠다.

* 이같이 Request로써 무엇을 할지 표현해주고, 무엇을 대상으로 할지를 url로 표시해주면 깔끔한 Web API가 됨.