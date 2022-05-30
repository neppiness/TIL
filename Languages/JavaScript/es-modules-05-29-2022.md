[TIL on May 29th, 2022](../../TIL/2022/05/05-29-2022.md)
# **What is an ES module and how to import it?**

### List of contents
- [The error to solve](#the-error-to-solve)
- [What is an ES module?](#what-is-an-es-module)
- [Import sources](#import-sources)
- [Local modules](#local-modules)
- [Conclusion](#con)
- [References](#references-br)

### The error to solve
```js
const mongoose = require('mongoose');
```
```log
>>> ReferenceError: require is not defined in ES module scope, you can use import instead
```
The contents shown below are the answers to solve the error above.

### What is an ES module?
- ES modules or ECMAScript Modules is a native module format supported by JavaScript as of ES6 (ES2015).
- This approach **uses the export and import keywords,** instead of **the older CommonJS syntax of module.exports and require.**

### Import sources
#### Import local JS module

Import from a local module.
```js
import { foo, bar } from './foo';
import { buzz } from '../bazz/bizz';
```
Often the extension is omitted - like .js, .ts or .jsx. You might have to include if .vue.

#### Import a 3rd-party package
- From Node modules: Import from a package installed with NPM.

```js
import * as vscode from "vscode";
import * as assert from "assert";
import React from 'react';
```
Or if you’ve aliased a package name to a URL with import maps or a deps.ts file (Deno).

#### From a URL
Import from a URL of a package - such as on GH, NPM or a CDN.

```js
import React from "https://dev.jspm.io/react";
```

The browser will download that script for you. No NPM needed.
This is also the default approach for Deno.


### Local modules
*In an NPM project, you can configure your project to use ES Modules as follows.*

package.json
```js
  {
    "type": "module"
  }
```

#### Named exports
Some ways to export with a name.

foo.js
```js
  function foo() {
    console.log("Hello");
  }

  export { foo };
```

foo.js alternative.
```js
  export function foo() {
    console.log("Hello");
  }
```

Usage:
```js
import { foo } from './foo';

// Multiple
import { foo, fuzz } from './foo';

// Rename
import { foo as fizz } from './foo';
```
Or, exporting a module (without importing it first).

foo.js
```js
  export { foo } from './foo';
```
Import multiple objects and put them under a namespace.
```js
import * as foo from "./foo";
foo.bar()
foo.buzz()
```

#### Default exports
foo.js
```js
  function foo() {
    console.log("Hello");
  }

  export default foo;
```
Usage:
```
import foo from './foo';
```

#### Combine multiple defaults
Normally you could export another module as default, but this will be invalid for two modules.

```js
export React from "https://dev.jspm.io/react";
export ReactDOMServer from "https://dev.jspm.io/react-dom/server";

// Equivalent to:
import React from "https://dev.jspm.io/react";
import ReactDOMServer from "https://dev.jspm.io/react-dom/server";
export default React
export default ReactDOMServer
```

Here is an alternative. So instead of assigning a name directly, import as unpacking the default object and then assign it a name.
```js
export { default as React } from "https://dev.jspm.io/react";
export { default as ReactDOMServer } from "https://dev.jspm.io/react-dom/server";

// Equivalent to:
import React from "https://dev.jspm.io/react";
import ReactDOMServer from "https://dev.jspm.io/react-dom/server";
export {
  React
  ReactDOMServer
}
```
Now you can import one or both modules from your module.

```js
import { React, ReactDOMServer } from "./deps.ts";
```
#### Mixing named and default imports

Intended:
```js
// Default.
import React from "./deps.ts"

// Named.
import { Application } from "./deps.ts";
```
Combined:
```js
import React, { Application } from "./deps.ts";
```

### Conclusion
```js
const mongoose = require('mongoose');
```
- This code above should be modified as the code below:
```js
import Mongoose from 'mongoose';
```
- The code above imports a module from local 3rd-party package and gives a name of 'Mongoose' to utilize functions.
- For example: `Mongoose.connect(config.mongodb.host);`

___

### References: <br>
1. [ES Modules: Dev Cheatsheets](https://michaelcurrin.github.io/dev-cheatsheets/cheatsheets/javascript/general/modules/es-modules.html#:~:text=As%20of%20ES6%20(ES2015)%2C,exports%20and%20require%20.)