[TIL on May 16th, 2022](../../TIL/2022/05-16-2022.md)
# **MongoDB Document Collection**

> The Collection class is an internal class that embodies a MongoDB collection allowing for insert/update/remove/find and other command operation on that MongoDB collection. <br> 
> **COLLECTION Cannot directly be instantiated**

```js
const MongoClient = require('mongodb').MongoClient;
const test = require('assert');
// Connection url
const url = 'mongodb://localhost:27017';
// Database Name
const dbName = 'test';
// Connect using MongoClient
MongoClient.connect(url, function(err, client) {
  // Create a collection we want to drop later
  const col = client.db(dbName).collection('createIndexExample1');
  // Show that duplicate records got dropped
  col.find({}).toArray(function(err, items) {
    expect(err).to.not.exist;
    test.equal(4, items.length);
    client.close();
  });
});
```

___

### Reference
- [MongoDB Class Collection](https://mongodb.github.io/node-mongodb-native/4.5/classes/Collection.html)