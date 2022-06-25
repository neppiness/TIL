[TIL on June 24th, 2022](../../TIL/2022/06/06-24-2022.md)
# **Starting JavaScript**

### JavaScript is dynamic
- HTML is 'static': It doesn't do anything like calculate
- JavaScript is 'dynamic': We can manage our web site even though it is completely loaded

<br>

### Variable and constant
- A variable varies its value during runtime
- A constant could not be changed

<br>

### HTML and JavaScript
- HTML is not a programming language:
  * It does not run in sequences or change after constructed
- JavaScript interacts with users and consecutively runs functions

<br>

### Purpose of function
Functions do
- enable re-use
- Aid design by logically dividing your application into smaller pieces
- Aid implementation by allowing you to write one function at a time, rather than 1000s of lines of code in one go
- Aid testing: by allowing you to test and prove small parts of your code, and then put them to bed so to speak
- Aid debugging: no need to step into a function in your debugger if you know that the output is right, given the inputs

#### Caution
- There is a trade off if in your chosen language there is a large performance penalty for calling functions - but the benefits during the development phase are often far more important

<br>

### Function's input and output
- A function consists of input and output
- Inputs are a parameter and argument
- Output is Return

<br>

### `for` and `in`
- Iteration using `for` and `in` could be applied to array or object

<br>

### Object
- Tool to write a simple code: relative function (method) and variable (property) are grouped as a object

<br>

#### How to use object?
- Declaration of object
```js
let a = {
    key: "value",
}
```
```js
var Body = {
  setColor: function (color) {
    document.querySelector('body').style.color = color;
  },
  setBackgroundColor: function (color) {
    document.querySelector('body').style.backgroundColor = color;
  }
}
```
- Call
`a["key"]`
`Body.setColor(color)`

- Delete 
```js
delete a.key;
```

### Library and framework
- Library is a software building block to construct a program
- Framework is a software with pre-built essential parts to create a similar program 
- jQuery is a library to a loop statement simpler as an example shown below:

```html
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
```
```js
$('a').css("color","powderblue");
```

### this
- `this` is a reserved word to indicate itself

```js
var kim = {
    name: 'kim',
    first: 10, 
    second: 20
    sum: function(){
        return this.first+this.second;
    }
}
console.log("kim.sum()",kim.sum());
```
- So, in the code above, `this` indicates the object, `kim`


### Prototype
- JavaScript is a Prototype based language
- In memory perspective, it is not efficient if all the instances save their all methods in memory
- We can use prototype to avoid this inefficiency
```js
function Person(name,first,second,third) {
    this.name = name;
    this.first = first;
    this.second = second;
    this.third = third;
    
}
Person.prototype.sum = function(){ 
    return this.first+this.second+this.third;
}

var kim = new Person('kim',10,20,30);
var lee = new Person('lee',10,10,10);
console.log("kim.sum()",kim.sum());
console.log("lee.sum()",lee.sum());
```

#### Basic rule
- Properties are placed inside of a constructor function
- Object methods should be added in a prototype of constructor

<br>

### Constructor
- `constructor` is a word reserved in JavaScript
- Users should type `constructor` as is
```js
class Person{
    constructor(name, first, second){
        this.name = name;
        this.first = first;
        this.second = second;
        console.log('constructor');
    }
}
var kim = new Person('kim',10,20);
console.log('kim',kim);
```

To declare a method in class, a reserved word `function`doesn't require:
- ex) `sum() {return this.first + this.second;}`

### Inheritance of class
#### `extends`
Example:
```js
class PersonPlus extends Person{
    avg(){
        return (this.first+this.second)/2;
    }
} 

var kim = new PersonPlus('kim',10,20); 
console.log("kim.sum()",kim.sum()); 
console.log("kim.sum()",kim.avg()); 
```
- PersonPlus inherits Person through `extends`
- It removes duplicates and add methods and properties in PersonPlus indepent to class Person

#### `super`
Syntax:
`super()`: calls the parent class' constructor
`super.sum()`: in this command, `super` means the parent class

```js
class Person{
    constructor(name, first, second){
        this.name = name;
        this.first = first;
        this.second = second;
    }
    sum(){
        return this.first+this.second;
    }
}
class PersonPlus extends Person{
    constructor(name, first, second, third){
        super(name, first, second);
        this.third = third;
    }
    sum(){
        return super.sum()+this.third;
    }
    avg(){
        return (this.first+this.second+this.third)/3;
    }
}
 
var kim = new PersonPlus('kim', 10, 20, 30);
console.log("kim.sum()", kim.sum());
console.log("kim.avg()", kim.avg());
```

To use constructor of `Person` class, `super(name, first, second);` is included in the constructor of `PersonPlus`


### Inheritance of object
#### prototype link
`__proto__` makes a prototype link to inherit an object

```js
var superObj = {superVal:'super'}
var subObj = {subVal:'sub'}
subObj.__proto__ = superObj;
console.log('subObj.subVal => ',subObj.subVal);
console.log('subObj.superVal => ',subObj.superVal);
```

#### Object.create
- Object.create could be applied to create a sub-object that inherits super-object
- Parent object, superObj is given to `Object.create`: `var subObj = Object.create(superObj);`

```js
var superObj = {superVal:'super'} 
var subObj = Object.create(superObj);
subObj.subVal = 'sub';

console.log('subObj.subVal => ',subObj.subVal);
console.log('subObj.superVal => ',subObj.superVal);

subObj.superVal = 'sub';
console.log('superObj.superVal => ', superObj.superVal);
```

### Uses of function
A function could be used:
- indepently;
- as a constructor for an object if `new` is in front of `function`; or
- with call and bind 

### `call` for a function
- All functions in JavaScript have `call` method
- An argument of `call` method becomes `this` of the function (shown in the example below)

```js
var kim = {name:'kim',first:10,second:20}
var lee = {name:'lee',first:10,second:10}

function sum(){ 
    return this.first + this.second;
}

console.log("sum.call(kim)",sum.call(kim)); //sum.call(kim) 30
console.log("sum.call(lee)",sum.call(lee)); //sum.call(lee) 20 
```

- `call` method also gets the other arguments used as arguments for a function:
```js
var kim = {name:'kim',first:10,second:20}
var lee = {name:'lee',first:10,second:10}
lee.__proto__ = kim

function sum(prefix){ 
    return prefix+ (this.first + this.second);
}

//sum();
console.log("sum.call(kim)",sum.call(kim,'=> ')); //sum.call(kim) => 30
console.log("sum.call(lee)",sum.call(lee,': ')); //sum.call(lee) : 20
```

### `bind` for a function
- `bind` method binds a `this` for a function internally
- And the arguments could also be binded
```js
var kim = {name:'kim',first:10,second:20}

function sum(prefix){ 
    return prefix + (this.first + this.second);
}

var kimSum = sum.bind(kim, '-> ');
console.log('kimSum()', kimSum()); // kimSum() -> 30
```

### Difference between `prototype` and `__proto__`
- `__proto__` is a property of a sub-object inherited from parent object
- `prototype` is an inclusive object that every object has

> Every object in JavaScript has a built-in property, which is called its prototype. The prototype is itself an object (from the [link](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Objects/Object_prototypes))

___

### Reference
- [자바스크립트의 시작](https://www.boostcourse.org/cs124)