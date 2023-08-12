[TIL on May 16th, 2022](../../TIL/2022/05/05-16-2022.md)
# **MongoDB Database Connection**

```js
connectDB()
    .then((client) => {
        const server = app.listen(config.host.port);
        initSocket(server);
        initUsersDB(client);
    })
    .catch(console.error)
```

```js
import MongoDb from 'mongodb';
import {config} from '../config.js';

export async function connectDB() {
    MongoDb.MongoClient.connect(config.db.host)
        .then((client) => {
            return client;
        })
}
```
```ts
    /**
    * Connect to MongoDB using a url
    *
    * @remarks
    * The programmatically provided options take precedent over the RI options.
    *
    * @see https://docs.mongodb.org/manual/reference/connection-string/
    */
    static connect(url: string): Promise<MongoClient>;
    static connect(url: string, callback: Callback<MongoClient>): void;
    static connect(url: string, options: MongoClientOptions): Promise<MongoClient>;
    static connect(url: string, options: MongoClientOptions, callback: Callback<MongoClient>): void;
```

Because connect is a static method, constructor of the MongClient class is ignored <br>
Only string type url is required and options could be given for **connect** method  <br>
<br>

If only url is given to connect method, connect method returns **Promise&lt;MongoClient&gt;**

<br>

___

### References
- [About promise](../../Languages/JavaScript/promise-05-16-2022.md)
- [About keyword static in class](../../Languages/JavaScript/static-in-class-05-16-2022.md)