# **읽기 쉬운 코드가 좋은 코드다(The Art of Readable Code)**

## Part 0 Introduction
### 1 코드는 이해하기 쉬워야 한다
* 무엇이 코드를 '더 좋게' 만드는가?
  - 아래 코드를 좋은 코드로 소개하고 있다.
```cpp
for (Node* node = list->head; node != NULL; node = node->next)
    print(node->data);
```
* 가독성의 기본 정리
  - 코드는 다른 사람이 그 코드를 이해하는 데 걸리는 시간을 최소화하는 방법으로 작성해야 한다.
  - 여기서 이해의 기준은 높다.
    + 그 사람이 작성된 코드를 자유롭게 수정하고, 버그를 짚어낼 수 있어야 한다.
    + 작성된 내용의 동작 원리를 알 수 있어야 한다.
* 분량이 적으면 항상 더 좋은가?
  - 일반적으론 그러하다
  - 그러나 내용을 너무 압축해놓으면 이를 분석하는 데 걸리는 시간이 더 들 수 있다.
* 이해를 위한 시간은 다른 목표와 충돌하는가?
  - 이해하는 코드를 작성하더라도 코드의 효율성, 아키텍처, 또는 테스트 용이성과 같은 부분과 충돌하는 일이 거의 없었다고 함.
* 이해하기 좋은 코드를 작성할 때 발생하는 어려움
  - 누군가가 읽었을 때 이를 이해하기 쉬울지 판단하는 게 어렵다.
* 정리: 좋은 코드는 이해하기 좋은 코드며, 이는 대체로 짧은 코드다. 이해하기 좋은 코드는 나쁠 게 없다.

<br>

## Part 1 표면적 수준에서의 개선
* 표면적 수준에 해당하는 개선 행위
  - 좋은 이름을 짓기
  - 좋은 설명 달기
  - 코드를 보기 좋게 하기

### 2 이름에 정보 담기
* 특정한 단어 고르기
  - get은 별 의미가 없다.
  - size는 너무 다양하게 쓰일 수 있다.
  - stop은 재개 가능 여부를 나타내질 못한다.
* 보편적인 이름 피하기
  - tmp, retval 등은 '임시 값', '반환 값'이라는 의미만 포함한다.
  - 더 좋은 이름을 사용하면 함수 내에서 어떤 데이터가 이 값들에 영향을 끼치는지 나타낼 수 있다.
  - tmp는 짧게 잠깐 거쳐가는 경우에만 사용하는 게 좋다. 그 경우엔 tmp라는 뜻에 완벽히 부합하는 변수기 때문이다.
  - for 문의 인덱스의 경우 누구에 대응되는 인덱스인지 명시하는 편이 좋다. 본인도 헷갈려서 잘못 입력하는 경우가 발생하기 때문이다.
* 추상적인 이름 대신 구체적 이름 사용하기
  - `--run_locally`라는 플래그를 통해서 추가 로깅을 수행했다고 한다.
  - 이 경우, 팀에 늦게 합류한 사람은 이 플래그가 어떤 역할을 하는지 짐작할 수조차 없다.
* 접두사 혹은 접미사로 이름에 추가 정보 덧붙이기
  - 16진수 변수에 hex라는 접두사를 붙인다. 예: hex_id
  - 단위가 필요한 경우 변수명에 단위를 명시한다. 예: start_ms
  - 이름에 추가적인 정보를 써서 더 명확히 한다. 예: data_urlenc, html_utf8
* 이름 길이 제한
  - 좁은 범위에서는 짧은 이름도 괜찮다.
  - 긴 이름 입력하기: 이제 입력이 어렵지 않으니 변수명은 길어도 큰 상관 없다.
  - 약어와 축약형: 약어는 해석이 어렵다. 보편적으로 많이 쓰이는 약어는 상관 없다(HTML, str, docs)
  - 불필요한 단어 제거: convertToString이나 toString으로 바꿔도 의미를 잃어버리지 않는다.
* 추가 정보를 담을 수 있게 이름 구성
  - `kMaxOpenFiles`와 같이 상수앞에 k를 붙이자는 약속을 하는 등의 것.
    + 이게 헝가리언 표기법 같은 느낌인데, 여전히 좋은 생각인지는 잘 모르겠음.
    + 그렇지만 C++에서 매크로를 SCREAMING_SNAKE_CASE로 쓰기 때문에 어쩔 수 없는 부분일지도.
  - 클래스 필드의 이름은 언더스코어를 마지막에 붙여 쓴다.(예: int no_of_days_)
* 정리: 의미 있는 단어들을 적절한 접두사/접미사로 부연하고, 컨벤션에 따라 포맷팅하며, 축약하지 않고 쓴다.

<br>

### 3 오해할 수 없는 이름들
* "내가 지은 이름을 본 사람이 다른 의미로 해석할 수 있지 않을까?"라는 질문을 던져보자
* Filter()
  - 이 조건에 부합하는 걸 고르는 건지, 아니면 부합하지 않는 걸 거르는 건지 알 수가 없음.
  - 문제는 이 이름을 고차함수에 쓰고 있다는 것. 이 경우, 부합하는 것들을 고른다.
* Clip()
  - 내용을 어떤 조건으로 오려낸다는 건지 알 수가 없다.
* 경계를 포함하는 한계값을 다룰 때는 min, max를 사용하라
  - max와 min은 각각 해당 값 초과, 미만인 경우에 에러를 발생시켜야 하도록 설계한다.
  - 위와 같이 설정 시 조건문을 `if (shopping_cart.num_items > MAX_ITEMS_IN_CART)`와 같이 쓸 수 있다.
* 경계에 포함되는 범위는 first와 last를 써라.
* 경계의 포함/배제하는 범위명은 begin, end를 써라.
  - C++ iterator들이 이같이 표현됨.
  - 이를 따르면 내가 이분탐색을 구현하는 방식에선 두 인덱스 명이 fisrt, last여야 함.
* 불리언 변수 이름 붙이기
  - 어떤 상태를 의미하는지 명확한 이름을 쓰자.
  - 부정의 의미를 포함하지 않는 게 좋다. 그 변수가 false면 이중 부정을 고려해야 하기 때문이다.
* 사용자의 기대에 부응하기
  - getMean()이라고 했는데 단순하게 mean 변수값을 가져오는 게 아니라 계산이 이루어진다면 문제가 된다.
  - 위 경우, calculateMean이나 computeMean과 같은 함수명을 활용하자.
* 변수명에 대한 후보군을 두고 적절성을 평가해보자.
* 정리: 개발자들의 통상적 관념에 맞게 이름을 짓자. 

<br>

### 4 미학
* 개요
  - 미학적이란 말은 시각적으로 보기 편하다는 의미다. 이를 위해서:
  - 코드를 읽는 사람이 이미 친숙한, 일관된 레이아웃을 사용하라.
  - 비슷한 코드는 서로 비슷해 보이게 만들어라.
  - 서로 연관된 코드는 하나의 블록으로 묶어라.
* 심미성 vs. 설계
  - 둘은 양립 가능하다고 주장함.
* 주석을 굉장히 지저분하게 작성하면 코드를 읽기가 힘들어진다. 예시에서 딱 그 사실을 인지시킴.
* 일관성과 간결성을 위해 줄바꿈을 재정렬하기
  - 동일한 코드가 동일하게 보이지 않으면 우리는 그것이 어떤 차이 때문인지 더 들여다보게 된다.
  - 따라서, 동일한 코드는 동일하게 보이도록 하는 게 좋다.
* 메소드를 활용하여 불규칙성을 정리하라
  - 공통 로직을 밖으로 빼면서 발생하는 이점임.
  - 이런 형태로 수정을 진행해야 하는 건지 생각해보자.
* 필요하다면 열을 정렬하라.
  - 아래와 같은 오타를 바로 잡아낼 수 있다.

```java
// POST 파라미터를 지역변수에 저장한다.
details  = request.POST.get('details');
location = request.POST.get('location');
phone    = equest.POST.get('phone');
email    = request.POST.get('email');
url      = request.POST.get('url');
```

* 나열이 필요할 때는 정렬 기준을 수립하고 이를 따르라.
  - 중요도가 있는 경우엔 중요한 것부터 덜 중요한 순으로 정렬하라.
  - 가중치가 없는 경우엔 알파벳 순서로 정렬하라.
* 선언문은 역할에 따라 블록으로 구분하자.
  - 이 경우 주석을 쓰게 된다.
  - 그렇다 하더라도, 어떤 메소드의 집합인지, 어떤 필드의 집합인지 명확히 나타내주면 좋은 듯하다.
* 코드를 '문단'으로 쪼개라.
  - 우리가 단순한 글을 쓸 때도 문단을 구분하는 건 그 문단 단위에 있는 주제를 구분하기 위해서다.
  - 또한, 이를 통해 시각적으로 단계를 구분지을 수 있다.
  - 그러므로, 코드 역시 의미에 따라 문단을 구분해주면 좋다.
* K&R 방식과 GNU 방식은 중괄호 스타일이 다르다.
  - 이 둘에는 가독성 우열 관계가 없지만, 이 둘을 섞어 쓰면 문제가 발생한다.
  - 이 경우 프로젝트 내에서 공유하는 방식으로 중괄호를 사용해주자.
* 정리: 시각적으로 코드를 보기 좋게 하는 위 테크닉들을 잘 활용하자.

<br>

### 5 주석에 담아야 하는 대상
* 개요
  - 설명하지 말아야 하는 것.
  - 코딩을 수행하면서 머릿속에 있는 정보를 기록하기.
  - 코드를 읽는 사람의 입장에서 필요한 정보가 무엇인지 유추하기.
* 설명하지 말아야 하는 것
  - 문법적으로 자명한 것들
    + 생성자를 굳이 생성자라고 표기하는 경우.
* 설명 자체를 위한 설명을 달지 말라
  - 함수 선언 내용과 같은 내용을 주석으로 다는 예시를 보여줌.
* 나쁜 이름에 주석을 달지 말라 - 대신 이름을 고쳐라.
* 생각을 기록해라
  - 감독의 커멘터리 같이 작성해라
  - 코드에 있는 결함을 설명해라
  - 상수에 대해 설명하라
* 코드를 읽는 사람의 입장이 되어라

> 하지만 코드는 유지보수되지만 주석은 그러지 못하단 점에서 이런 식으로 주석을 활용하는 게 썩 바람직해 보이진 않음.
> TODO를 통해 어떤 것을 진행해야 하는지 기록하는 것 정도는 괜찮은 듯함. 해당 내용을 처리한 뒤 지우게 될 것이니 바람직함.

* 큰 흐름을 알려주는 주석은 필요하다고 함.
> 그렇지만, 이 역시 함수명이나 변수명으로 표현해야 하는 것이라 생각되긴 함.
> 클린코드 주석 부분을 다시 읽고 내용을 비교해보자.
* 클린코드에서 필요한 주석과 필요하지 않은 주석을 구분해서 설명함.

<br>

### 6 명확하고 간결한 주석 달기
* 주석을 간결하게 하라
  - 한 줄로 축약해서 달 수 있는 예시
* 모호한 대명사는 피하라
  - 대명사 대신 그에 대응되는 명사를 명시적으로 표현하라
* 문장의 의미를 명확하게 하라
* 함수의 동작을 명확하게 설명하라
* 구체적인 용법을 설명해주는 입출력 예를 사용하라
* 코드의 의도를 명시하라
  - 역순으로 순회한다고만 적지 말고 애초에 정렬 기준이 무엇이었는지 정확히 표현하라
* 이름을 가진 함수 파라미터 주석
  - 파이썬에서는 아래와 같은 함수 인수 매핑이 가능하다

```py
def Connect(timeout, use_encryption): # and following statements

Connect(timeout = 10, use_encryption = false)
```

* C++에선 코드 내부에 주석 블록을 둬서 이와 같이 할 수 있다.
```cpp
Connect(/* timeout_ms */ 10, /* use_encryption */ false);
```
  - 실무에서 이같이 쓰는지는 잘 모르겠음

* 정보 축약형 단어를 사용하라
  - 장황한 주석을 쓰지 말고, 통용되는 개념 상 단어를 써주면 명확해진다.
* 정리: 짧은 주석만 읽어도 많은 부분을 이해할 수 있도록 작성하라.

> 그렇지만, 여전히 이런 주석이 유지보수가 잘 될지 모르겠음.

<br>

## Part 2 루프와 논리 단순화하기
* 흐름제어, 논리식, 변수를 어떻게 이해하기 쉽게 작성할 수 있나 알아보자.

### 7 읽기 쉽게 흐름제어 만들기
* 조건문 인수 순서
  - `if (length >= 10)`, `if (10 <= length)`라고 두자.
  - 이 경우, 첫 번째 조건문이 읽기 더 쉽다
  - 이는 'length가 10보다 크거나 같다'라고 해석할 수 있으니, 비교대상인 주어 length가 앞에 오는 게 자연스럽다.
* if-else 문을 작성할 때, 비슷한 비중의 분기라면 긍정을 처리한 뒤 else로 부정을 처리하는 게 조건문을 읽기 좋다.
  - 그러나 배제하는 경우를 확인하는 거라든지 아니면 이어지는 내용이 훨씬 짧다면 그 분기가 먼저 오는 것이 좋다고 생각한다.
* 간단한 삼항연산자는 오히려 좋다.
  - `time_str += (hour >= 12) ? "pm" : "am";`
  - 이를 조건문으로 풀어쓰면 훨씬 길어지고 이해도 어려워진다.
* do-while 보다는 while 문을 쓰는 편이 조건을 먼저 확인할 수 있어 좋다.
* goto문은 대안이 없을 때만 사용하자.
* if문 안에 if문은 지양하자.
* 중첩 최소화하기
  - 함수 중간에서 조건을 확인하고 빠르게 분기에 대한 반환을 수행해버리는 것도 방법.
* 실행 흐름을 따라올 수 있는가?
  - 스레딩, 예외처리, 가상 메소드 등은 적절히 쓰면 유용하지만, 코드의 흐름을 따라가기 어렵게 만들기도 한다.
  - 이를 적절히 쓰는 게 중요하다.
> switch-case 문에 대한 얘기는 안 함. 안 좋을 게 있던가?
> 클린코드: switch 문은 기본적으로 N가지 일을 처리하기 때문에 다형성을 가지고 분기를 만드는 경우를 제외하면 코드도 길어지고 좋지 않다.

* 정리: 제어문의 흐름이 명료해지도록 코드를 작성하자.

<br>

### 8 거대한 표현을 잘게 쪼개기
* 거대한 표현을 소화하기 쉬운 여러 조각으로 나눈다.
* 설명 변수
  - 하위표현을 담을 '추가 변수'를 만듦으로 설명할 수 있다.
  - `if line.split(':')[0].strip() == "root": # and so on`
  - 위 코드는 아래와 같이 나눠질 수 있다.

```python
username = line.split(':')[0].strip()
if username == "root": # and so on
```

* 요약 변수
```java
if (request.user.id == document.owner_id) {
    // 사용자가 이 문서를 수정할 수 있다.
}
// ...
if (request.user.id != document.owner_id) {
    // 문서는 읽기 전용이다.
}
```

  - 이 경우, `request.user.id == document.owner_id`를 다른 변수로 설정하면 된다.
  - `final boolean user_owns_document = (request.user.id == document.owner_id);`
* 드모르간의 법칙 사용하기
  - 불리언 변수에 대해 드모르간 법칙을 적용해 이해하기 쉽게 수정한다.
* 쇼트 서킷 논리 오용하지 않기
  - 논리 연산자 `||`를 사용하게 되면 앞에 있는 것부터 먼저 확인되고, 그것이 만족되면 나머지를 확인하지 않는다.
  - 이를 활용하고나 억지로 논리 연산에 특정 구문을 넣는 코드를 예시함.
  - 짧은 트릭을 활용한 코드는 읽는 사람이 한 번에 이해하기 어려울 수 있다.

> 얼마 전에 풀었던 문제 중에서 문제를 풀 수 있을 때와 불가능할 때를 문자열로 구분하는 문제가 있었음.
> 이를 `const string OUT[] = {"실패 시 문자열", "성공 시 문자열"};`로 둔 다음에
> `cout << OUT[solve()];`라는 구문으로 처리했는데, 나름 재밌었지만 가독성은 굉장히 좋지 않은 코드라 생각됨.

* 복잡한 논리식을 세운 경우
  - 접근 방법을 완전히 바꿔서 다른 방식으로 풀이해보는 게 좋다...
* 거대한 구문 나누기
  - 반복되는 부분은 공통으로 활용할 수 있는 다른 변수명과 같은 것으로 두면 전체적으로 이해하기 쉬워진다.
* 표현을 단순화하는 다른 창의적인 방법들
  - C++의 경우 매크로를 활용하는 방법이 있다. 이는 정말 정말 필요할 때만 쓰도록 하자
* 정리
  - 설명 변수, 또는 설명 함수를 따로 빼면 코드 이해가 쉬워진다.
  - outOfBound 함수를 따로 빼는 것도 이와 같은 맥락이라 생각한다.

<br>

### 9 변수와 가독성
* 변수를 잘못 사용하는 경우 발생하는 단점
  1. 변수의 수가 많을수록 기억하고 다루기 어려워진다.
  2. 변수의 범위가 넓어질수록 기억하고 다루는 시간이 더 길어진다.
  3. 변수값이 자주 바뀔수록 현재값을 기억하고 다루기가 더 어려워진다.
* 변수 제거하기
  - 불필요한 임시 변수를 쓰지 않는다. 바로 할당할 변수같은 건 큰 의미 없다.
  - 흐름 제어 변수를 제거한다. 현재 상태를 불리언으로 두고 이를 통해 while 문 지속 여부를 결정하는 식
    + 이 경우, 조건이 만족되면 빠져나오도록 제어문을 고치면 된다.
* 변수 사용 범위를 좁혀라
  - 전역 변수 사용을 지양하라
  - 커다란 클래스의 필드 역시 전역변수나 다름 없다.
    + 이는 지역 변수로 만드는 게 더 좋다.
    > 사실 이런 경우 함수 인수를 줄이라는 조언과 상충되긴 함.
  - 정적 메소드를 활용하라: 지역변수와 무관하다는 것을 알리기 좋다.
  - C++에서 if문의 범위: 앞의 코드는 뒤의 코드로 대체될 수 있다.
    ```cpp
    PaymentInfo* info = database.ReadPaymentInfo();
    if (info) {
        cout << "User paid: " << info->amount() << endl;
    }
    ```
    ```cpp
    if (PaymentInfo* info = database.ReadPaymentInfo()) {
        cout << "User paid: " << info->amount() << endl;
    }
    ```
    > 이건 반드시 써먹어보자.
    + 공식 문서에 따르면 if 문의 괄호 안에는 선택적으로 초기화 구문이 들어갈 수 있다.
    + 초기화 구문과 조건문은 세미콜론으로 구분된다.
  - 변수를 상단에 두텁게 선언할 필요는 없다. 그러니, 필요한 위치에서 선언하자.
    + 습관적으로 모든 변수를 전역 변수로 때려넣는 PS를 해왔는데, 이에 대해서 좀 더 고민해볼 필요가 있을 듯함.
    + 물론, PS는 개발이 아니니 그렇게까지 심각하게 생각해볼 필요는 없을지 모름.
* 값을 한 번만 할당하는 변수를 선호하라
  - const/final의 사용을 권장.
* 정리: 쓸모없는 변수 제거. 변수 범위를 최대한 축소. 상수 사용 권장

<br>

## Part 3 코드 재작성하기
* 프로그램의 주된 목적과 부합하지 않는 '상관없는 하위문제'를 추출
* 코드를 재배열하여 한 번에 한 가지 일만 수행하게 하라
* 코드를 우선 단어로 묘사한 뒤 이를 활용해 깔끔히 풀어봐라.

### 10 상관없는 하위문제 추출하기
* 엔지니어링은 커다란 문제를 작은 문제들로 나누고, 각각에 대해 해결한 뒤 조합하는 방식으로 진행된다.
  - 이와 같은 원리를 코드에 적용하면 좋다.
* 일반적 목적의 코드를 프로젝트의 특정 코드에서 분리하라.
* 지나치게 메소드를 분리하면 오히려 가독성을 해친다.
  - 아래 두 코드를 보자
```py
user_info = { "username": "...", "password": "..." }
url = "http://example.com/?user_info=" + url_safe_encrypt(user_info)

def url_safe_encrypt(obj):
    obj_stsr = json.dumps(ob);
    cipher = Cipher("aes_128_cbc", key=PRIVATE_KEY, init_vector=INIT_VECTOR, op=ENCODE)
    encrypted_bytes = cipher.update(obj_str)
    encrypted_bytes += cipher.final()
    return base64.urlsafe_b64encode(encrypted_bytes)
```

```py
user_info = { "username": "...", "password": "..." }
url = "http://example.com/?user_info=" + url_safe_encrypt_obj(user_info)

def url_safe_encrypt_obj(obj):
    obj_str = json.dumps(obj)
    return url_safe_encrypt(obj_str)

def url_safe_encrypt_str(data):
    encrypted_bytes = encrypt(data)
    return base64.urlsafe_b64encode(encrypted_bytes)

def encrypt(data):
    cipher = make_cipher()
    encrypted_bytes = cipher.update(data)
    encrypted_bytes += cipher.final()
    return encrypted_bytes

def make_cipher():
    return Cipher("aes_128_cbc", key=PRIVATE_KEY, init_vector=INIT_VECTOR, op=ENCODE)
```
  
  > 클린코드적인 관점에선 분명 아래 코드를 권장할 것 같다.
  - 이 책에선 두 코드를 비교하며 아래와 같이 말한다.
  - 이렇게 자잘한 함수를 사용하면 오히려 가독성을 해친다. 사용자가 신경써야 하는 내용이 늘어나고, 실행경로를 추적하기 위해 정의를 찾아다녀야 한다.
  - 코드에 새로운 함수를 추가하는 건 가독성을 대가로 지불해야 한다. 이를 상회하는 이득이 없다면 추출할 필요가 없다.
    + 이득 중 하나는 추출된 함수를 다른 데서도 활용하는 경우다.

<br>

### 11 한 번에 하나씩
* 코드는 한 번에 하나의 작업만 수행하도록 구성되어야 한다.
  - 함수 안에서도 처리하는 작업들이 있을 텐데 이들을 구분해서 진행할 필요가 있다.
* 작업 단위는 작을 수 있다.

```js
var vote_value = function (vote) {
    if (vote === 'Up') return 1;
    if (vote === 'Down') return -1;
    return 0;
}

var vote_changed = function (old_vote, new_vote) {
    var score = get_score();

    score -= vote_value(old_vote);
    score += vote_value(new_vote);
    set_score(score);
}
```

* 이정도 단위로 쪼개놔도 충분히 이해하기 좋은 코드가 나올 수 있음.
  - vote_value를 그대로 vote_change 코드 안에 둔 경우엔 굉장히 지저분한 분기처리가 이루어져야 했음.
* 객체에서 값 추출하기
  - 다음 요구사항을 만족하게 코딩한다고 생각하자.
    1. '도시'를 선택할 때 값이 있으면 "LocalityName(도시/마을)"을 사용한다.
    2. 만약 값이 없으면 'SubAdministrativeAreaName(도시권/자치주)'를 사용한다.
    3. 그조차 없으면 'AdministrativeAreaName(주/영역)'을 사용한다.
    4. 만약 위 세 가지에 해당하지 않으면, "Middle-of_Nowhere"라는 기본값을 준다.
    5. 만약 'CountryName'이 없으면, 기본값으로 'Planet Earth'라는 값을 준다.
  - 지저분한 분기를 아래와 같이 간략화할 수 있다.

    ```js
    var first_half, second_half;

    if (country === "USA") {
        first_half = town || city || "Middle-of-Nowhere";
        second_half = state || "USA";
    } else {
        first_half = town || city || state || "Middle-of-Nowhere";
        second_half = country || "Planet Earth";
    }

    return first_half + ", " + second_half;
    ```
  - 사실상 하나의 PS 문제나 다름 없어서 리팩토링 하는 과정을 잘 쫓아가야 할 듯.
* 더 복잡한 예제는 내용을 확인하고 직접 간략화하는 과정을 거치면 더 좋은 통찰을 얻을 수 있을 거라 생각됨.

<br>

### 12 생각을 코드로 만들기
* 논리를 명확하게 설명하기
  - if에 if로 들어가는 방식보다 한 if로 분기처리하는 편이 이해하기가 쉽다는 것.
* 논리를 쉬운 말로 표현
  - 그리고 이를 따라 구현
* 요약: 구현할 내용을 간단히 서술하고, 이 서술에 부합하는 자연스러운 코드를 작성하자.
  - 굉장히 유용한 팁인 듯. 앞으로 코드를 작성하면서 의식적으로 생각해봐야겠음.

<br>

### 13 코드 분량 줄이기
* 그 기능을 구현하려고 애쓰지 마라 - 그럴 필요가 없다
  - 정말 필요한 기능만 구현하자.
* 요구사항에 질문을 던지고 질문을 잘게 나누어 분석하라
  - 일단은 간단히 동작하는 프로그램을 만든 후에 이를 확장하는 방식으로 접근
  > 이같이 풀어볼 만한 문제가 있었던가?
* 코드베이스 작게 유지하기
  - 불필요한 코드는 제거하며 정말 필요한 코드만 존재하도록 관리
  - 이를 통해서 어떤 파일이 어느 곳에 있는지, 이를 어떻게 활용하고 있는지 파악하는 등의 일을 처리할 때 걸리는 시간이 줄어듦
* 자기 주변에 있는 라이브러리에 친숙해질 것
  - 15분씩 라이브러리를 열어보라 권장
  - 이제는 이런 부분이 검색을 통해 충분히 커버가 가능하다 생각함.
* 요약: 코드베이스를 가볍게 하라. 이는 요구사항 자체에 대해 고민하고, 가급적 표준 라이브러리를 활용하는 것으로 수행할 수 있다.

<br>

## Part 4 선택된 주제들
### 14 테스트와 가독성
* 읽거나 유지보수하기 쉽게 테스트를 만들어라
  - 다른 프로그래머가 수정하거나 새로운 테스트를 더하는 걸 쉽게 느낄 수 있도록 테스트 코드는 읽기 쉬워야 한다.
    + 지나치게 큰 테스트 코드는 코드를 작성하는 데 걸림돌이 된다.
    + 코드를 변경할 '용기'가 필요하게 된다.
* 이 테스트는 어떤 점이 잘못되었을까?
* 테스트를 더 읽기 쉽게 만들기
  - 헬퍼 함수를 둬서 동일한 로직을 간단히 처리할 수 있도록 변경
> 그 외에는 크게 공감되는 내용은 없는 듯
* `BOOST_REQUIRE_EQUAL`: C++ 테스트 작성할 때 어떻게 쓸 수 있나 확인해보기.
* BOOST_REQUIRE_EQUAL로 부족하다 느낀다면 직접 에러메시지를 작성할 것.
* 테스트 함수에 이름 붙이기
  - 단순히 Test1, Test2와 같은 식이면 좋지 않다.
  - 테스트 함수 명은 호출될 일이 전혀 없기 때문에 그냥 어떤 걸 테스트하는지 최대한 자세하게 적어도 상관 없다.
* 테스트하기 좋은 코드 작성하기
  - 전역변수 지양
  - 적은 양의 외부 컴포넌트를 사용하도록 설계
  - 결정적으로 동작하게 설계
  - 클래스 필드가 거의 없으면 좋다.
  - 클래스 또는 함수가 한 번에 한 가지 일만 하면 좋다.
  - 클래스 간 의존도가 낮다.
  - 함수들이 간단하고 인터페이스가 잘 정의되어 있다.
* 지나친 테스트
  - 테스트를 위해 실제 코드의 가독성을 희생해야 하는 경우: 뭔가 잘못된 것
  - 코드는 완벽히 테스트될 수 없다.
  - 테스트 코드가 실제 제품 개발에 차질을 빚는 경우.

<br>

### 15 '분/시간 카운터'를 설계하고 구현하기
* 위의 원칙을 지키며 문제 풀이를 접근하는 장
* 눈여겨 볼 것
  - 나이브한 풀이를 포함, 3번에 걸쳐 문제를 풀었다.
  - 매 풀이마다 문제점을 확인한 뒤 이를 순차적으로 보완했다.
