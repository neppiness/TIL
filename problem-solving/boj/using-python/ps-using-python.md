**PS Using Python**

## sys.stdin.readline
* `import sys`를 수행한 뒤, input이라는 함수를 sys.stdin.readline으로 설정.
  - 이후 줄을 읽는 과정은 input()을 통해서 수행

<br>

## .rstrip()
* 인자로 전달되는 문자열 요소들을 제거하는 메소드
```py
txt = "banana,,,,ssqqqwww......"
x = txt.rstrip(",.qsw")
print(x) # banana
```

<br>

## map(fun, iter)
* 아래와 같은 예시를 통해 숫자 a, b를 파싱할 수 있음.
  - `a, b = map(int, input().split(' '))`;

```py
import sys
input = sys.stdin.readline

n, x = map(int, input().split())
a = map(int, input().split())

ans = ""
for i in a:
    if (i < x):
        ans += str(i) + ' '
print(ans)
```

<br>

## BOJ#10871: X보다 작은 수
* 풀이는 아래와 같음.
  - str() 함수를 통해서 문자열로 만듦.
  - ' '를 더해서 공백으로 문자열을 연결하도록 만듦.

* 확인한 코드 중에 간단하게 짠 코드는 아래와 같음.
```py
n, x = map(int, input().split())
answer = ' '.join([i for i in input().split() if int(i) < x])
print(answer, end='')
```

* 여기서 배울 수 있는 건:
  - 리스트를 구성하면서 filter를 이와 같이 설정할 수 있다.
  - print()에서 끝나는 문자열을 개행문자가 아닌 다른 문자로 바꿀 수 있다.
    + print() 메소드를 통해서 separtor와 end, file, flush 등을 설정할 수 있다.
    + end = ' '로 설정하여 문제를 해결할 수도 있음.

<br>

## raw string
### BOJ#10171: 고양이
* '''에 r을 붙여서 완벽하게 raw string을 출력할 수 있음.
```py
print(
r'''\    /\
 )  ( ')
(  /  )
 \(__)|'''
, end = '')
```
