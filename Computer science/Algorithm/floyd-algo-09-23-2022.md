[TIL on September 23rd, 2022](../../TIL/2022/09/09-23-2022.md)
# **Floyd Algorithm**
### Introduction
- Floyd algorithm is an algorithm to find the optimal paths 
- To fill the optimal path table containing a cost to reach node *j* from node *i*
- This algorithm follows the dynamic programming approach to find the shortest paths

### Steps
1. Fill the table with the cost of edges from node *i* to node *j*
2. Compare the cost of the two paths:
  * The directly connected edge and;
  * The path from node *i* to node *j* through the first node
3. Update the cost by comparing the costs of the paths through all given nodes

### Time complexity
- Assume that the number of given vertices is V
- Then, the time complexity of this algorithm becomes O(V^3)
  * Check total V^2 paths to pass through total V vertices to calculate the minimum cost

### Implementation
- [boj.kr/11404](../../Problem%20Solving/boj/Floyd%20algorithm/11404-09-23-2022.cpp)
- [Path restoration](./floyd-path-restore-09-23-2022.cpp)
- [boj.kr/11780](../../Problem%20Solving/boj/Floyd%20algorithm/11780-09-23-2022.cpp)
___

### References
1. [[실전 알고리즘] 0x1C강 - 플로이드 알고리즘](https://blog.encrypted.gg/1035)