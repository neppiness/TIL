[TIL on September 26th, 2022](../../TIL/2022/09/09-26-2022.md)
# **Dijkstra's algorithm**
### Introduction
- An algorithm for finding the shortest paths between nodes in a graph
- Dijkstra's original algorithm found the shortest path between two given nodes
- But a more common variant fixes a single node as the "source" node and finds shortest paths from the source to all other nodes in the graph, producing a shortest-path tree
- In here, the common variant of algoritm will be introduced

### Note
- A path costs minus value should not be included to apply this algorithm (Bellman-Ford Algorithm could be applied)
- A* algorithm is an apporximate solution to apply when the vertices are too many to be calculated, thus, we don't need to study about that algorithm

### Procedures
- Select the start node and end node of the path to find the shortest distance
- Update an array to save a distance temporarily
- Find the shortest way in the temp array, and determine the path as the shortest edge
- Find the shortest way between vertices on the determined path and the others until all the paths are determined

### Implementation
#### Naive implementation
- [My Dijkstra's algo. imp. #1](./dijkstra-imp-09-26-2022.cpp)
- Given *naive* Dijkstra's alg. imp.
```cpp
vector<pair<int,int>> adj[20005];
const inf INF = 0x3f3f3f3f;
bool fix[20005];
int d[20005];
int V = 10;
void dijkstra_naive(int st) {
  fill(d, d+V+1, INF);
  d[st] = 0;
  while(true) {
    // index of the node to be fixed
    // This logic could be improved by using priority queue
    int idx = -1;
    for(int i = 1; i <= V; i++){
      if(fix[i]) continue;
      if(idx == -1) idx = i;
      else if(d[i] < d[idx]) idx = i;
    }
    // Check if there are no candidate nodes to be fixed
    if(idx == -1 || d[idx] == INF) break;
    fix[idx] = 1;
    // Assign the minimum value to d[nxt.Y]
    for(auto nxt : adj[idx])
      d[nxt.Y] = min(d[nxt.Y], d[idx] + nxt.X);
  }
}
```
- Time complexity: O(V^2+E)

#### Using priority_queue
- [My Dijkstra's algo. imp. #2](./dijkstra-imp-2-09-26-2022.cpp)
- Time complexity: O(ElgE)
- If E is too many so the E is about V^2, using priority queue is not efficient

- Procedure
  1. Add the start node in priority queue
  2. Pick the minimum value on priority queue and check if that value is same as the value on the array; if not, pop the next value on the priority queue 
  3. If the picked minimum value is smaller than 

```cpp

```

___

### References
1. [Dijkstra's algorithm from Wikipedia](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
2. [[실전 알고리즘] 0x1D강 - 다익스트라 알고리즘](https://blog.encrypted.gg/1037)
