[TIL on June 9th, 2022](../TIL/2022/06/06-09-2022.md)
# **Memory Structure**

### Simple memory structure
Low address (ex. 0x0000)
|machine code                            |
|:--------------------------------------:|
|Globals                                 |
|Heap   ↓<br><br><br><br><br><br>Stack  ↑|
High address (ex. 0xFFFF)


### Function of each section
- machine code section has a compiled binaries of an excuted program
- Globals section stores global variables of an excuted program
- Heap is a section managed by user: dynamically assigned variables are stored in this section
  * `new` operator or class and reference variables occupy Heap section
  * Heap section is assigned low address to high address
- Stack is a section where the local variables or arguments are saved
  * After the function is excuted, the allocated variables used in the function freed from memory
  * Stack section is assigned from high address to lower address
- Heap and Stack share their section

### Stack/Heap overflow
- In software, Stack overflow occurs if the call stack pointer exceeds the stack bound.
- When a recursive function goes too deep, Stack overflow occurs
  * It happens when Stack section excessively allocated and should be assigned over the area already assigned
- Heap overflow (heap overrun, or heap smashing) is a type of buffer overflow that occurs in the heap data area

___

### References
1. [메모리 구조 [Memory Structure]](https://st-lab.tistory.com/198)
2. [모두를 위한 컴퓨터 과학 (CS50 2019) 8) 파일 쓰기](https://www.boostcourse.org/cs112/lecture/119034)
3. [Stack overflow](https://en.wikipedia.org/wiki/Stack_overflow)
4. [Heap overflow](https://en.wikipedia.org/wiki/Heap_overflow)