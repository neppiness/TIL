[TIL on June 22nd, 2022](../../TIL/2022/06/06-22-2022.md)
# **Compilation Steps in C**

After following compilation steps are properly done, a excutable file is obtained as a result

### I. Precompile
- A precompile process is done by precompiler
- A C source code starts with # indicates some processes before compile
  * ex) `#include <stdio.h>` informs precompiler to include the codes in the other files
- Precompiler creates a new file in the format of C source code include context of file `stdio.h` in `#include` section

<br>

### II. Compile
- After a file is precompiled, a compile process begins
- A program called as a 'compiler' compiles C code into assembly language more like machinery language
- Although assembly language has less operators, by combining them, it could do all operations of C
- A compile represents all these steps, but, specifically, it means that the step transfers precompiled source code into assembly code

<br>

### III. Assemble
- Once an assembly code is get, assembly code is transferred as a object code in assemble step
- A object code is the commands in format of consecutive 0s and 1s
- A program Assembler do this step
- The whole compile process will be done if only one file is compiled through this compilation

<br>

### IV. Link
- 'Link' step is needed if the program to compile consists of multiple files including libraries
- Linker connects some object code files into a single excutable file

___

### References
- [모두를 위한 컴퓨터 과학 (CS50 2019)](https://www.boostcourse.org/cs112)