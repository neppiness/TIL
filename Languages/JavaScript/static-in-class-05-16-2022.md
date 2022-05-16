[TIL on May 16th, 2022](../../TIL/2022/05-16-2022.md)
# **Static in JavaScript**

### 💡 Static in Class of JavaScript
> The static keyword defines a static method or property for a class. <br>

> Static members (properties and methods) are called without instantiating their class and **cannot** be called through a class instance. <br>

> Static methods are often used to create utility functions for an application, whereas static properties are useful for caches, fixed-configuration, or any other data you don't need to be replicated across instances.

```js
class Point {
  constructor(x, y) {
    this.x = x;
    this.y = y;
  }

  static displayName = "Point";
  static distance(a, b) {
    const dx = a.x - b.x;
    const dy = a.y - b.y;

    return Math.hypot(dx, dy);
  }
}

const p1 = new Point(5, 5);
const p2 = new Point(10, 10);
p1.displayName; // undefined
p1.distance;    // undefined
p2.displayName; // undefined
p2.distance;    // undefined

console.log(Point.displayName);      // "Point"
console.log(Point.distance(p1, p2)); // 7.0710678118654755
```

<br>

```js
class Test {
  constructor(a) {
    this.a = a;
  }

  static plus(b, c) {
    this.b = b;
    this.c = c;
    console.log(this.b + this.c);
  }
}
```

A static method plus just ignores construtor <br>
plus could be called with b, c values

<br>

___

### Reference
- [mdn web docs](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes#static_methods_and_properties)