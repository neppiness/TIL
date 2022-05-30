[TIL on May 30th, 2022](../TIL/2022/05/05-30-2022.md)
# **Clean Code Chapter 2: meaningful names**

### Contents
- Intro
- Inform what is intended
- Avoid wrong information
- Meaningful identification
- Use name to be easily speaked
- Use name to be easily searched
- Avoid encoding
- Class name and method name
- Don't use a brilliant name
- Use a word for one concept
- Don't make a wordplay
- Use a name brought from a solution domain
- Use a name brought from a problem domain
- Add meaningful context
- Remove useless context


### Intro
- Good name makes easy to program

### Inform what is intended
- Code example:
```java
public List<int[]> getFlaggedCelss() {
  List<int[]>flaggedCells = new ArrayList<int[]>();
  for (int[] cell : gameBoard)
    if (cell[STATUS_VALUE] == FLAGGED)
      flaggedCells.add(cell);
  return flaggedCells;
}
```

### Avoid wrong information
- `XYZControllerForEfficientHandlingOfStrings` vs. `XYZControllerForEfficientStorageOfStrings`
- Code Example:
```java
int a = l;
if ( 0 == l)
a = O1; else l = 01;
```

### Meaningful identification
- An example of code to avoid:
```java
getActiveAccount();
getActiveAccounts();
getActiveAccountInfo();
```

### Use name to be easily speaked
- `genymdhms` (generate date, year, month, day, hour, minute, second)
- vs. `generationTimestamp;`

### Use name to be easily searched
- Don't use a letter for a name of constants or variables
- Good exmaple: `WORK_DAYS_PER_WEEK`

### Avoid encoding
- `private String m_dsc = name;`
- vs. `String description;`

### Class name and method name
- Class name: use a noun or a noun phrase
- Method name: use a verb or a verb phrase


### Don't use a brilliant name
- `HolyHandGrenade`: a virtual weapon from [Monty Python]

### Use a word for one concept
- `DeviceManager` and `ProtocolController`: why don't you use a word 'Manager' or 'Controller' for both of them?

### Don't make a wordplay
- `add` vs.`insert` or `append`
- Consider which one is more important; consistency or accuracy

### Use a name brought from a solution domain
- Readers also totally understand about the programming concept

### Use a name brought from a problem domain
- If there is no such a proper name in soltuion domain, get a name from a problem domain

### Add meaningful context
- Class, function, and name space make contexts

### Remove useless context
- A long name is better than a short name unless it is clear and there is no duplicated meanings

### Conclusion
- Apply this conventions to your projects

___

### References
- [Martin, R. C. (2013). 클린 코드: 애자일 소프트웨어 장인 정신. 인사이트.](https://books.google.co.kr/books?id=MKsYngEACAAJ)