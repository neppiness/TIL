[TIL on February 2nd, 2023](../../TIL/2023/02/02-02-2023.md)
# **[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)**
### [Conditionals](https://google.github.io/styleguide/cppguide.html#Conditionals)
* In an `if` statement, including its optional `else if` and `else` clauses, put one space between the `if` and the opening parenthesis, and between the closing parenthesis and the curly brace (if any), but no spaces between the parentheses and the condition or initializer. If the optional initializer is present, put a space or newline after the semicolon, but not before.
  - `if`문과 그 조건을 담을 괄호 사이엔 띄어쓰기가 있어야 한다.
  - 조건 괄호와 실행할 명령을 담을 중괄호 사이엔 띄어쓰기를 해야한다.
  - 조건 괄호는 조건과 붙어 있어야 한다.
  - 만약 `if`문의 조건 안에서 선언이 이루어지는 경우(if optional initializer is present) 세미콜론 이후에 띄어쓰기나 줄바꿈을 넣어야 한다.

  ```cpp
  if (int idx = findidx(); idx != 0) {
    a[n  - idx] = 1;
    continue;
  }
  ```

* Use curly braces for the controlled statements following `if`, `else if` and `else`. Break the line immediately after the opening brace, and immediately before the closing brace. A subsequent `else`, if any, appears on the same line as the preceding closing brace, separated by a space.
  - `else if`나 `else를` 넣는 경우 실행문이 길든 짧든 중괄호를 쓰라고 권함.
```cpp
if (condition) {                   // no spaces inside parentheses, space before brace
  DoOneThing();                    // two space indent
  DoAnotherThing();
} else if (int a = f(); a != 3) {  // closing brace on new line, else on same line
  DoAThirdThing(a);
} else {
  DoNothing();
}
```

* 단, `if`만 쓰는 경우 들여쓰기나 중괄호 없이 작성을 허용함.

```cpp
if (x == kFoo) return new Foo();

if (x == kBar)
  return new Bar(arg1, arg2, arg3);

if (x == kQuz) { return new Quz(1, 2, 3); }
```


### [Horizontal Whitespace](https://google.github.io/styleguide/cppguide.html#Horizontal_Whitespace)
* Operators
```cpp
// Assignment operators always have spaces around them.
x = 0;

// Other binary operators usually have spaces around them, but it's
// OK to remove spaces around factors.  Parentheses should have no
// internal padding.
v = w * x + y / z;
v = w*x + y/z;
v = w * (x + z);

// No spaces separating unary operators and their arguments.
x = -5;
++x;
if (x && !y)
  ...
```


### [Type Names](https://google.github.io/styleguide/cppguide.html#Type_Names)
* Type names start with a capital letter and have a capital letter for each new word, with no underscores: MyExcitingClass, MyExcitingEnum.
  - 타입명은 대문자로 시작해서 새 단어 마다 대문자를 붙여준다(upper camel case)

* The names of all types — classes, structs, type aliases, enums, and type template parameters — have the same naming convention. Type names should start with a capital letter and have a capital letter for each new word. No underscores. For example:
  - 클래스, 구조체, 타입 별칭, 이넘, 타입에 활용되는 매개변수들은 동일한 명명 규칙을 따른다.

```cpp
// classes and structs
class UrlTable { ...
class UrlTableTester { ...
struct UrlTableProperties { ...

// typedefs
typedef hash_map<UrlTableProperties *, std::string> PropertiesMap;

// using aliases
using PropertiesMap = hash_map<UrlTableProperties *, std::string>;

// enums
enum class UrlTableError { ...
```


### [Variable Names](https://google.github.io/styleguide/cppguide.html#Variable_Names)
* The names of variables (including function parameters) and data members are all lowercase, with underscores between words.
  - 변수명은 모두 소문자를 활용하되, 단어 사이에는 언더스코어(_)를 사용한다.

* Data members of classes (but not structs) additionally have trailing underscores. For instance: a_local_variable, a_struct_data_member, a_class_data_member_.
  - 클래스의 로컬 변수들은 끝에 언더스코어(_)를 추가한다.


### [Constant Names](https://google.github.io/styleguide/cppguide.html#Constant_Names)
* Variables declared constexpr or const, and whose value is fixed for the duration of the program, are named with a leading "k" followed by mixed case. Underscores can be used as separators in the rare cases where capitalization cannot be used for separation
  - 상수명 첫번째 글자는 k를 붙인다.

* For example:
```cpp
const int kDaysInAWeek = 7;
const int kAndroid8_0_0 = 24;  // Android 8.0.0
```

* All such variables with static storage duration (i.e., statics and globals, see [Storage Duration](https://en.cppreference.com/w/cpp/language/storage_duration#Storage_duration) for details) should be named this way. This convention is optional for variables of other storage classes, e.g., automatic variables, otherwise the usual variable naming rules apply.
  - static storage duration 상의 변수들에 대해 이와 같이 명명한다. 그외 storage classes의 변수들은 일반적 변수명 규약에 따른다.
  - static stroage duration: 프로그램이 시작될 때 생성돼서 끝날 때 소멸되는 지속 시간을 의미함.


### [Function Names](https://google.github.io/styleguide/cppguide.html#Function_Names)
* Regular functions have mixed case. Ordinarily, functions should start with a capital letter and have a capital letter for each new word.
  - 함수는 Upper camel case를 사용한다.

```cpp
AddTableEntry()
DeleteUrl()
OpenFileOrDie()
```

* (The same naming rule applies to class- and namespace-scope constants that are exposed as part of an API and that are intended to look like functions, because the fact that they're objects rather than functions is an unimportant implementation detail.)
  - API 일부로써 드러났고, 함수처럼 보이게 의도된 클래스 또는 네임스페이스 범위 상수들에도 적용된다.

Accessors and mutators (get and set functions) may be named like variables. These often correspond to actual member variables, but this is not required. For example, `int count()` and `void set_count(int count)`.
  - setter, getter는 일반 변수명처럼 선언한다.
  - `int count()` 또는 `void set_count(int count)`와 같이 써서 실질적 동작을 하는 함수와 구분함.