[TIL on March 22nd, 2023](../../TIL/2023/03/03-22-2023.md)
### TIP: mac keys to win keys
* mac의 키 중에 win와 위치가 일치하는 곳과 기능적으로 활용되는 의미를 짝지어 둔 표

|key| mac   | win (location)   | win (function) |
|---|-------|------------------|----------------|
|⌘ | Cmd   | alt              | ctrl           |
|⇧  | Shift | Shift            | shift          |
|⌥ | Option | win             | alt            |
|⌃  | Ctrl  | Ctrl             |                |
|⇪  | Caps  | Caps             | Caps           |
|Fn | Fn    | Fn               | Fn             |
* NOTE: command가 ctrl이고, option이 alt인 듯함. 사실 맥에서는 윈도우와 같은 위치에 컨트롤 키가 있음. 대신 윈도우 키에 커맨드 키가 있고, 알트 키 위치에 옵션 키가 있음.
<br>

### 단축키 목록
* Alt + Shift + Enter: select methods to implement
* Alt + Shift + Click: multi cursor selection
* Alt + Enter:
  1. 처리할 수 있는 방법 목록 창 띄우기
  2. 인터페이스를 implement할 때에도 쓸 수 있음
  3. `Assertions.assertThat(memberService).isInstanceOf(MemberServiceImpl.class);`와 같은 구문이 있으면, static method를 도입해서 간단하게 만들어줄 수도 있음: `assertThat(memberService).isInstanceOf(MemberServiceImpl.class);`
* Ctrl + Alt + V: Introduce variable
* Ctrl + Alt + B: 선택한 인터페이스의 구현체를 바로 탐색할 수 있음.
* Ctrl + Alt + I: 똑똑한 들여쓰기.
  - `memberRepository.findByName(member.getName());`에다 적용하는 경우, `Optional<Member> byName = memberRepository.findByName(member.getName());`로 바꿔줌
  - 즉, 관용적으로 사용하는 적당한 이름으로 바꾸면서 이를 받아주는 변수를 도입하는 것
* Ctrl + Alt + Shift + T (⌃ + ⌥ + ⇧ + T): refactor
* Ctrl + Alt + N: inline refactoring
* Ctrl + Alt + M (⌥⌘M): Extract method
  - 메서드를 아래와 같이 간편하게 분리할 수 있음.

```java
    public Long join(Member member) {
        // 같은 이름이 있는 중복 회원은 안 된다.
        validateDuplicateMember(member);
        memberRepository.save(member);
        return member.getId();
    }

    private void validateDuplicateMember(Member member) {
        memberRepository.findByName(member.getName())
                        .ifPresent(m -> {
                            throw new IllegalStateException("이미 존재하는 회원입니다.");
                        });
    }
```

* Ctrl + N: go to class
* Ctrl + P: 전달해야 하는 인자를 확인하는 단축키, `check parameter` 
* Ctrl + E: 최근 확인한 파일 목록
* Ctrl + F2: 프로그램 셧다운
* Ctrl + F12: File Structure, 파일 내 메소드 목록을 싹 확인할 수 있음.
* Ctrl + F5: Re-run
* Ctrl + O: 오버라이드 또는 구현할 메소드 선택.

* Shift + F6: 이름 다시 짓기
* Shift + F10: 이전에 돌렸던 프로그램 재실행

* Alt + F12: 터미널 창 띄우기
* Alt + Shift + Arrow: 줄 이동
* Alt + Insert: Generate
  - 이를 통해 constructor를 바로 생성하는 것도 가능함.
  - getter and setter도 바로 만들 수 있음.
  - toString를 활용해서 toString 메소드에 오버라이딩하는 구문도 자동으로 만들 수 있음.

* Ctrl + Shift + F10
  - 메소드 위에서 작동시키는 경우, 해당 메소드에 대한 테스트 수행
  - 메소드 외부에서 작동시키는 경우, 해당 클래스 내 메소드들에 대한 테스트 수행
* Ctrl + Shift + T: 테스트 케이스 틀 생성하기
  - 대략적으로 의도하는 위치에 현재까지 생성된 메서드 기반으로 테스트 할 수 있는 틀을 만들어줌.
* Ctrl + Shift + Enter: 현재 위치와 상관 없이 다음 줄로 줄바꿈 삽입. 또한, 자동으로 찾아진 클래스나 메소드를 불러왔을 때, 단순 엔터키만으로는 세미콜론 전까지만 나와서, 이 단축키를 통해 세미콜론까지 완결지을 수 있음.

* 타이핑 - psvm: `public static void main(String[] args) {}`를 자동으로 작성해줌.
* 타이핑 - sout: `System.out.println();`를 자동으로 작성해줌. soutv: `System.out.println("order = " + order);
* 타이핑 - soutm: `System.out.println("클래스명.메소드명");` 형식으로 자동 작성됨
`를 자동으로 작성해줌.
* 타이핑 - iter: 배열이나 리스트와 같은 목록이 있을 때, 이를 돌아보는 for 문의 틀을 자동으로 작성해줌.

* F2: 하이라이트된 항목으로 자동 이동.

