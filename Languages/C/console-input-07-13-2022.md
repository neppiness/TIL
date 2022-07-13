[TIL on July 13th, 2022](../../TIL/2022/07/07-13-2022.md)
# **Console input**

### To get the string with some spaces
- You cannot simply use `scanf` or `cin`
- Basically both of them get the data separated by spaces

### Three methods to resolve this problem
#### `scanf` with negated scanset `[^characters]`
- Any number of characters none of them specified as characters between the brackets
```cpp
char a1[10];
scanf("%[^\n]", a1); // get characters until '\n' comes
```
#### `gets` function
- C++ below version 14 could use this
```cpp
char a2[10];
gets(a2);
puts(a2);
```

#### `getline`
- Type should be C++ string
- Seems simple
```cpp
string s;
getline(cin, s);
cout << s;
```

<br>

### Note for using cin/cout
- Two commands to use to avoid timeout
```cpp
std::ios:: sync_with_stdio(0);
std::cin.tie(0);
```
- If you use std as a namespace, then the source codes are shortened as below:
```cpp
ios:: sync_with_stdio(0);
cin.tie(0);
```

#### std::ios::sync_with_stdio(0);
- C stream used in scanf/printf and C++ stream used in cin/cout are separated
- Thus, cin/cout and scanf/printf could not be synchronized
- C++ basically synchronizes C++ stream and C stream, and it takes some time: if we don't use both of them, it's just a waste of time
- Therefore, if we only use C++ stream, we can remove the synchronization between C stream and C++ stream with this command: `std::ios::sync_with_stdio(false);`
- If we use inactivate this synchronization, cout and printf should not be used together

#### std::cin.tie(0);
- Output buffer temporarily stores characters; buffer removed when those characters are printed on screen
- Input also has buffer, so the input data is stored there
- The input and output sequences could be messed up when input and output are mixed
- `std::cin.tie(nullptr);` command makes `cout` buffer remain before `cin` command is used
- Strictly the argument should be nullptr, but 0 could be used

### TL;DR
- Use cin/cout only with the commands below:
```cpp
std::ios::sync_with_stdio(0);
std::cin.tie(0);
```

### Don't use `endl`
- `endl` prints '\n' and clears output buffer
- We don't have to clear buffer when we solve problems

___

### References
1. [[실전 알고리즘] 0x02강 - 기초 코드 작성 요령 II](https://blog.encrypted.gg/923?category=773649)