[TIL on June 12th, 2022](../../TIL/2022/06/06-12-2022.md)
# **Divide and Conquer**

### What is divide and conquer algorithm
- A strategy of solving a large problem by
1) breaking the problem into smaller sub-problems
2) solving the base case level sub-problems, and
3) combining them to get the desired output.
- Breaking method and combining method should be intuition and efficient

### How Divide and Conquer Algorithms Work?
Here are the steps involved:
- Divide: Divide the given problem into sub-problems using recursion
- Conquer: Solve the smaller sub-problems recursively. If the subproblem is small enough, then solve it directly
- Combine: Combine the solutions of the sub-problems that are part of the recursive process to solve the actual problem

### EX 1. fast sum for a sequence
```python
def fastSum(num):
    if(num == 1):
        return 1
    if(num % 2 == 1):
        return fastSum(num-1) + num
    return 2 * fastSum(num/2) + (num/2)**2
```

### EX 2. sorting an array using the divide and conquer approach (i.e. merge sort)

1) Let the given array be: `[7, 6, 1, 5, 4, 3]`
2) Divide the array into two halves: `[7, 6, 1], [5, 4, 3]`
3) Again, divide each subpart recursively into two halves until you get individual elements: `[7, 6], [1], [5, 4], [3]` -> `[7], [6], [1], [5], [4], [3]`
4) Combine the individual elements in a sorted manner
```shell
[7], [6], [1], [5], [4], [3]
-> [6, 7], [1], [4, 5], [3]
-> [1, 6, 7], [3, 4, 5]
-> [1, 3, 4, 5, 6, 7]
```

### Advantages of Divide and Conquer Algorithm
- The complexity for the multiplication of two matrices using the naive method is O(n^3)
- Whereas using the divide and conquer approach (i.e. Strassen's matrix multiplication) is O(n^2.8074)
- This approach also simplifies other problems, such as the Tower of Hanoi
- This approach is suitable for multiprocessing systems
- It makes efficient use of memory caches

___

### Reference
- [Divide and Conquer Algorithm](https://www.programiz.com/dsa/divide-and-conquer#:~:text=A%20divide%20and%20conquer%20algorithm,to%20get%20the%20desired%20output.)
- [알고리즘 문제 해결 전략 세트(프로그래밍 대회에서 배우는), Volumes 1](https://books.google.co.kr/books?id=koK5NAEACAAJ&dq=%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D+%EB%8C%80%ED%9A%8C%EC%97%90%EC%84%9C+%EB%B0%B0%EC%9A%B0%EB%8A%94+%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98+%EB%AC%B8%EC%A0%9C%ED%95%B4%EA%B2%B0%EC%A0%84%EB%9E%B5&hl=en&sa=X&redir_esc=y)