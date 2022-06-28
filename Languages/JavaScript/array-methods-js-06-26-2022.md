[TIL on June 26th, 2022](../../TIL/2022/06/06-26-2022.md)
# **Array**

### Description
In JavaScript, arrays aren't primitives but are instead Array objects with the following core characteristics:
1) JS Arrays are resizable and can contain a mix of different data types
2) JS Arrays are not associative arrays and so, array elements cannot be accessed using arbitrary strings as indexes, but must be accessed using nonnegative integers (or their respective string form) as indexes
3) JS Arrays are zero-indexed: the first element of an array is at index 0, the second is at index 1, and so on — and the last element is at the value of the array's 'length property' minus 1
4) JS Arrays copy operations create shallow copies. (All standard built-in copy operations with any JavaScript objects create shallow copies, rather than deep copies).
*When the first characteristics are undesirable, use 'typed arrays' instead
**Shallow copy is defined as the section below

#### Shallow copy
- A shallow copy of an object is a copy whose properties share the same references (point to the same underlying values) as those of the source object from which the copy was made
- As a result, when you change either the source or the copy, you may also cause the other object to change too — and so, you may end up unintentionally causing changes to the source or copy that you don't expect
- That behavior contrasts with the behavior of a deep copy, in which the source and copy are completely independent.
- In JavaScript, all standard built-in object-copy operations (spread syntax, Array.prototype.concat(), Array.prototype.slice(), Array.from(), Object.assign(), and Object.create()) create shallow copies rather than deep copies.

#### Selective copy
- For shallow copies, it's important to understand that selectively changing the value of a shared property of an existing element in an object is different from assigning a completely new value to an existing element.
- For example, if in a shallow copy named 'copy' of an array object, the value of the copy[0] element is {"list":["butter","flour"]}, and you do copy[0].list = ["oil","flour"], then the corresponding element in the source object will change, too — because you selectively changed a property of an object shared by both the source object and the shallow copy
- However, if instead you do copy[0] = {"list":["oil","flour"]}, then the corresponding element in the source object will not change — because in that case, you're not just selectively changing a property of an existing array element that the shallow copy shares with the source object; instead you're actually assigning a completely new value to that copy[0] array element, just in the shallow copy.


### Constructor
`Array()`: Creates a new Array object

### Links for methods
- [Static methods](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array#static_methods)
- [Instance properties](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array#instance_properties)
- [Instance methods](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array#instance_methods)


___

### Reference
- [Array](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array)