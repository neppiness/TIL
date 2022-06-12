[TIL on June 12th, 2022](../../TIL/2022/06/06-12-2022.md)
# **Time Complexity Analysis**

### The speed of the program depends on many factors
- Loops dominate a running time of a program
- Running cycles of a loop is expressed by a size of an array, N

### Linear time algorithm
- An algorithm is said to take linear time, or O(n) time, if its time complexity is O(n)
- The running time increases at most linearly with the size of the input
- Linear time is the best possible time complexity in situations where the algorithm has to sequentially read its entire input

### Sublinear time algorithm
- An algorithm is said to run in sub-linear time if T(n)=o(n) such as O(logn)
- As such an algorithm must provide an answer without reading the entire input, its particulars heavily depend on the access allowed to the input

### Polynomial time algorithm
- An algorithm is said to be of polynomial time if its running time is upper bounded by a polynomial expression in the size of the input for the algorithm, that is, T(n) = O(nk) for some positive constant k
- Some examples of polynomial time algorithms:
1) The selection sort sorting algorithm on n integers performs An^{2} operations for some constant A, thus, it runs in time O(n^{2})
2) All the basic arithmetic operations (addition, subtraction, multiplication, division, and comparison)
3) Maximum matchings in graphs

### Computationally easy and hard problem
- If a problem has a solution based on a polynomial time algorithm, it is regarded as a computationally easy problem
- If not, it is regared as a computationally hard problem

### Exponential time algorithm
- An algorithm is said to be exponential time, if T(n) is upper bounded by 2^poly(n), where poly(n) is some polynomial in n
- More formally, an algorithm is exponential time if T(n) is bounded by O(2^n^k) for some constant k
___

### Reference
- [알고리즘 문제 해결 전략 세트(프로그래밍 대회에서 배우는), Volumes 1](https://books.google.co.kr/books?id=koK5NAEACAAJ&dq=%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D+%EB%8C%80%ED%9A%8C%EC%97%90%EC%84%9C+%EB%B0%B0%EC%9A%B0%EB%8A%94+%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98+%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%EC%A0%84%EB%9E%B5&hl=en&sa=X&redir_esc=y)
- [Time complexity: wikipedia](https://en.wikipedia.org/wiki/Time_complexity)