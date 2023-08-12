[TIL on July 9th, 2022](../../TIL/2022/07/07-09-2022.md)
# **Statements and flow control: 'if and else', while, and do-while**

### Selection statements: if and else
- The `if` keyword is used to execute a statement or block, if, and only if, a condition is fulfilled

#### Syntax
```cpp
if (condition) statement
```
- `condition` is the expression that is being evaluated
- If this `condition` is true, `statement` is executed
- If it is false, `statement` is not executed (it is simply ignored), and the program continues right after the entire selection statement

Selection statements with if can also specify what happens when the condition is not fulfilled, by using the else keyword to introduce an alternative statement with `if` and `else`


#### Syntax for `if` and `else`
```cpp
if (condition) statement1 else statement2
```
- where `statement1` is executed in case condition is true, and in case it is not, `statement2` is executed
- Several if + else structures can be concatenated with the intention of checking a range of values

- It would have also been possible to execute more than a single statement per case by grouping them into blocks enclosed in braces: {}

<br>

### Iteration statements (loops)
- Loops repeat a statement a certain number of times, or while a condition is fulfilled
- They are introduced by the keywords while, do, and for

#### The while loop
The simplest kind of loop is the while-loop
```cpp
while (expression) statement
```
- The while-loop simply repeats statement while expression is true
- If, after any execution of statement, expression is no longer true, the loop ends, and the program continues right after the loop
- `condition` is excuted if it consists of command such as `a++`
- Function like `scanf` could also be used for the condition

```cpp
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int g = 3;
    while(g--) cout << g;
}
```
```shell
2 1 0
```

- Once g--; is done, while(g) is checked: if the condition `g` is not satisfied (g == 0), then the while loop breaks

#### The do-while loop

Syntax:
```cpp
do statement while (condition);
```
- It behaves like a while-loop, except that condition is evaluated after the execution of statement instead of before, guaranteeing at least one execution of statement, even if condition is never fulfilled
- The do-while loop is usually preferred over a while-loop when the statement needs to be executed at least once, such as when the condition that is checked to end of the loop is determined within the loop statement itself

___

### References
1. [Statements and flow control: 'if and else', while, and do-while](https://cplusplus.com/doc/tutorial/control/)