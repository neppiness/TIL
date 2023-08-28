[TIL on August 9th, 2023](/TIL/2023/08/08-09-2023.md)
# **Vim As Your Editor**
## Introduction
* [원본 영상](https://youtu.be/X6AR2RMB5tE)
* w나 b는 숫자와 조합해서 쓰기 어렵다. 사실 그 수를 누가 언제 세고 있겠나
  - 그래도 db, dw는 충분히 쓸 만한 명령인 듯함.
* 일단 중요한 건, 모드가 총 4가지라는 점
  1. 노말 모드(Normal mode): 네비게이트 하면서 필요한 
  2. 입력 모드(Insert mode): i, a, I, A, o, O를 눌러서 진입함.
  3. 명령 모드(Command mode): 콜론(`:`) 키를 눌러서 진입함.
  4. 비쥬얼 모드(Visual mode): shift + v를 통해서 visual line 모드로 이동 가능.

* `ctrl` + `[`나 `ctrl` + `c`를 통해서도 esc가 가능함. 굳이 esc키까지 손을 뻗을 이유가 없는 듯함.
* i와 a는 굉장히 빈번히 쓰이는 명령이기 때문에 잘 활용할 수 있어야 함.
* 아이러니하게도 `ctrl` + `[`가 가장 비직관적인데 쓰기 가장 편한 듯함

* visual 모드에서 커서를 이동하며 블록을 만들 수 있고, 이를 y로 복사, p로 붙여넣기 할 수 있음.
* shift + v를 통해서 비쥬얼 라인 모드를 켤 수 있음.

* 일단 이런 내용들을 가지고 일주일을 작업해보라고 권함.


## Horizontal
* [원본 영상](https://youtu.be/5JGVtttuDQA)

* 줄 전체에 대한 이동 명령
  * `_`: 현재 줄의 가장 앞으로 이동할 수 있음.
  * `$`: 줄의 가장 뒤로 이동할 수 있음.
  * `0`: 줄의 가장 앞으로 이동할 수 있음. 

* f와 t, 그리고 이를 반복하는 ,와 ;
  * `f`: 내가 지정한 문자로 이동(문자를 포함함) / `t`: 내가 지정한 문자 앞으로 이동(문자를 포함하지 않음)
  * `F`: 내가 지정한 문자를 찾아 왼쪽으로 이동(문자를 포함함) / `T`: 내가 지정한 문자를 찾아 왼쪽으로 이동(문자를 포함하지 않음)
  * `,`: 뒤로 이동 / `;`: 앞으로 이동
    * 예) `fe`를 누른 후에 세미콜론을 누르게 되면 `e`라는 문자 앞으로 이동하는 작업을 반복한다.
  * 현 커서를 기점으로 괄호와 같은 특수한 문자 앞으로 이동하고자 할 때 적절히 활용하면 될 듯함. 그런데 그럴 정도의 일이 있던가?
* `O`: 새 줄을 현재 커서가 있는 위치의 위쪽에 만들어줌.


## 독학
* `%`: 가까운 괄호로 이동. 굉장히 강력하니 어떻게 활용할 수 있나 알아보자.
* `r`: 한 단어를 수정할 수 있음
* `VGD`: 비쥬얼 라인모드로 글의 최하단까지 내려가서 내용을 지움.


## 내게 인상 깊었던 점들. 즉, VIM에 완전히 정착할 이유가 될 것들.
* `ci(`를 통해서 괄호 안에 있는 내용을 싹 밀고 입력 모드로 진입할 수 있는 점
* 필요하다면 상대적인 줄 위치를 파악하고 바로 이동할 수 있는 점(그마저도 사실 화면 내에 내용이 보일 때는 마우스로 찍는 편이 빠르지 않나 싶음)
* `Vd`를 통해서 빠르게 한 줄을 지울 수 있음.


## Vertical Movements
* ctrl + d, ctrl + u: 반 페이지를 내려가고 반 페이지를 올라가는 단축키. 내용을 확인할 때 괜찮을 것 같음.
* zz를 통해 내 커서가 화면 정가운데에 위치하도록 만들 수 있음.
* Ctrl + Home을 누르지 않고 gg를 통해 위로 올라갈 수 있다는 걸 좋다고 봐야할지.
* /를 통해서 searching을 할 수 있음(사실 이 부분은 ctrl + f를 통한 찾기랑 뭐가 다른지 잘 모르겠음).
* `*`을 통해서 현재 커서가 위치한 단어를 포함한 패턴을 빠르게 탐색할 수 있음. 이는 매우 편리하게 쓸 수 있을 듯함.


## Advanced Motions p1
* Jumping forward to text object commands
* `vi(`를 통해서 괄호 안에 있는 것들을 블록처리할 수 있다.
* `va{`를 통해서 중괄호와 그 안에 있는 모든 내용을 블록처리할 수 있다.
* 진작부터 선택한 뒤 복사할 생각이었다면 `ya{`를 통해서 중괄호와 그 안에 있는 모든 내용을 복사할 수 있다.
* `viw`: 내 커서가 단어의 어디에 있건 해당 단어를 블록처리할 수 있다.
* ` p`: <Leader>p를 통해서 온전한 붙여넣기를 수행한다는 의미로 해석됨. 어떤 기능인지는 좀 더 공부해봐야 할 것.
* `yy` 대신 `VY`쓰기: 한 글자를 반복해서 입력하는 것보다 두 손가락으로 두 문자를 입력하는 게 빠르기 때문에 VY를 쓰라고 권함. 마찬가지 이유에서 `VD`를 쓰라고 권함.


## Advanced Motions P2
* `f{`는 내 커서가 위치한 줄에서 중괄호로 이동하는 것
* `v%`를 통해 괄호 안에 있는 내용을 모두 선택할 수 있다.
* `=ap` 기본 설정한 스타일에 따라 한 문단(ap, a paragraph)을 자동 맞춤한다.
* `o`를 통해서 visual 모드에서 커서 위치를 최상단과 최하단으로 전환할 수 있음.
* `>`를 통해서 들여쓰기를 수행할 수 있으며, `4j`, `8k`와 같은 숫자 + 모션 조합으로 각각 아래로 4줄, 위로 8줄을 들여쓰기 할 수 있다. 현재 커서가 가리키고 있는 위치부터 시작해서 relative 라인 상에 나타난 위치까지 올라가는 것이니 이를 인지하고 활용할 수 있다.
* 원래 Vim이 허용하는 ctrl + 방향키 조합이 얼마나 되는지 모르겠지만, 따옴표로 감싸고자 할 때, 앞의 큰따옴의 큰따옴표 입력한 뒤 입력 모드에서 빠져나와 `A`를 통해 맨 뒤로 가서 큰따옴표를 붙임.
* `ctrl` + `v`: 비쥬얼 블럭 모드로 진입
* `g`: ctrl + a와 더해져서 하나씩 값을 증가시켜야 하는 것을 찾아 순차적으로 늘려줌. 

```cpp
data[1] = "cpp";
data[2] = "java";
data[3] = "javascript";
```