[TIL on September 19th, 2022](../../TIL/2022/09/09-19-2022.md)
# **Minimum Spanning Tree**
### Definition and characteristics
- Spanning tree: a sub-graph of an undirected connected graph includes all the vertices of the graph
- Minimum spanning tree: a spanning tree with a minimum possible number of edges
  * For a weighted graph, the spanning trees with the minimum total length are the minimum spanning tree
  * More than one minimum spanning tree could exist

The edges may or may not have weights assigned to them.

### Kruskal's algorithm
- Union Find algortihm should be preceded for an efficient implementation
- It is based on greedy algorithm: pick the minimum cost edge and avoid making a cycle on tree

#### Steps
1. Sort all the edges in non-decreasing order of their weight
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it
3. Repeat step#2 until there are (V-1) edges in the spanning tree

- 'Flood fill' could be used to determine whether the vertices are in the same group or not, but then the time complexity of the algorithm is O(ElgE + VE)
- 'Union find' could done this in O(1) of time complexity, and the time complextiy of the whole steps becomes O(ElgE)

#### Implementation
```cpp
vector<int> p(10005,-1); // using constructor *check*

int find(int x) {
  if(p[x] < 0) return x; // means that x is a root (parent of root is set as -1)
  return p[x] = find(p[x]); // using recursion to find root node and automatically optimize
}

bool is_diff_group(int u, int v){
  // find roots of u and v, and assign them to u and v
  u = find(u); v = find(v);
  
  // if the roots of u and v are the same
  if(u == v) return 0;

  // u and v are roots, but not the same one.
  // This code above makes difference between roots
  if(p[u] == p[v]) p[u]--;
  
  // assign lower value
  if(p[u] < p[v]) p[v] = u;
  else p[u] = v;

  // return 1 means that u and v have different root values
  return 1;
}

int v, e;
tuple<int, int, int> edge[100005];

int main(){
  sort(edge, edge + e);
  int cnt = 0;
  for(int i = 0; i < e; i++) {
      int cost, a, b;
      tie(cost, a, b) = edge[i];
      // if a and b is in the same group, b is already included in the MST nodes
      if(!is_diff_group(a, b)) continue;
      cout << cost << ' ' << a << ' ' << b;
      cnt++;
      if(cnt == v - 1) break;
  }
}
```
- `is_diff_group()` function implies the union find algorithm's union

<br>

### Prim's algorithm
- Time complextiy: O(ElgE)
- Priority queue is applied
- To implement efficient algorithm, priority queue should be used
- [Prim's algorithm imp.](./prims-algo-09-19-2022.cpp)

#### Steps
1. Pick a random node
2. Check two things listed below:
  * the nodes adjacent to the nodes in the tree and not included in the tree, and;
  * the costs of the edges connect to them
3. Pick the edge with lowest cost and added the node on the tree
4. Repeat Step 2 and 3 until the all vertices are included in the MST

#### Implementation example
- Should compare with my solution
```cpp
#define X first
#define Y second

int v, e; // no. of vertices and edges, respectively
vector<pair<int, int>> adj[10005];
bool chk[10005];
int cnt = 0;
priority_queue< tuple<int, int, int>,
                vector<tuple<int, int, int>>
                greater<tuple<int,int,int>> > pq;

chk[1] = 1;
for(auto nxt : adj[1])
  pq.push({nxt.X, 1, nxt.Y});
while(cnt < v - 1) {
  int cost, a, b;
  tie(cost, a, b) = pq.top(); pq.pop();
  if(chk[b]) continue;
  cout << cost << ' ' << a << ' ' << b << '\n';
  chk[b] = 1;
  cnt++;
  for(auto nxt : adj[b]) {
    if(!chk[nxt.Y])
      pq.push({nxt.X, b, nxt.Y});
  }
}
```
- The while loop is much more simpler than mine

___

### References
1. [[실전 알고리즘] 0x1B강 - 최소 신장 트리](https://blog.encrypted.gg/1024)
2. [Spanning Tree and Minimum Spanning Tree: programiz](https://www.programiz.com/dsa/spanning-tree-and-minimum-spanning-tree)
3. [Kruskal’s Minimum Spanning Tree Algorithm | Greedy Algo-2](https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/)
4. [Introduction to Disjoint Set Data Structure or Union-Find Algorithm: geeksforgeeks](https://www.geeksforgeeks.org/union-find/)