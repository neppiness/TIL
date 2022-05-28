[TIL on May 28th, 2022](../../TIL/2022/05-28-2022.md)
# **Brute-force search**

### Brute-force search in computer science
Called as brute-force search, exhaustive search or 'generate and test'
- very general problem-solving technique and algorithmic paradigm
- consists of systematically enumerating all possible candidates for the solution and checking whether each candidate satisfies the problem's statement.

#### Strength
- Simple to implement
- Always find a solution if it exists,

#### Weakness
- Implementation costs are proportional to the number of candidate solutions:
- In many practical problems tends to grow very quickly as the size of the problem increases

#### Typical usage
- When the problem size is limited,
- When there are problem-specific heuristics that can be used to reduce the set of candidate solutions to a manageable size.
- When the simplicity of implementation is more important than speed.


### Application
The algorithm is easily modified to stop:
- after finding the first solution; or
- a specified number of solutions; or
- after testing a specified number of candidates; or
- after spending a given amount of CPU time

### Speeding up brute-force searches
- Reduce the search space, the set of candidate solutions
  - by using heuristics specific to the problem class.
  - by the analysis: may yield an algorithm not to waste a time and generate invalid candidates

___

### Reference
- [Brute-force search](https://en.wikipedia.org/wiki/Brute-force_search)