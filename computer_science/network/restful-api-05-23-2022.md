[TIL on May 23rd, 2022](../../TIL/2022/05/05-23-2022.md)
# **REST APIs**

### API
- Assume we design a basic CRUD operations for client as APIs
- All the APIs will get urls and its readability gets worse
- Some standards are needed

### Rules
- #1: Drop verbs, use nouns only
  - Two nonuns are remaining: collections and unique identifier
- #2: Use four HTTP methods
The combinations of methods and collections yield to APIs

### Good examples
- /movies?min_rating=9.8
- /movies?release_date=2021
- /movies?page=5
___

### References
[5분만에 제대로 설계하는 ⭐️ REST API](https://youtu.be/4DxHX95Lq2U)