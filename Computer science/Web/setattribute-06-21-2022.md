[TIL on June 21st, 2022](../../TIL/2022/06/06-21-2022.md)
# **Element.setAttribute()**
Sets the value of an attribute on the specified element

If the attribute already exists, the value is updated; otherwise a new attribute is added with the specified name and value

### Syntax
`setAttribute(name, value)`

#### Parameters
`name`
- A string specifying the name of the attribute whose value is to be set
- The attribute name is automatically converted to all lower-case when setAttribute() is called on an HTML element in an HTML document

`value`
- A string containing the value to assign to the attribute
- Any non-string value specified is converted automatically into a string

Boolean attributes are considered to be true if they're present on the element at all. You should set `value` to the empty string ("") or the attribute's name, with no leading or trailing whitespace. See the example below for a practical demonstration.


#### Return value
None (undefined).


### Example

HTML
```html
<button>Hello World</button>
```
JavaScript
```js
var b = document.querySelector("button");

b.setAttribute("name", "helloButton");
b.setAttribute("disabled", "");
```
Result
```html
<button name="helloButton" disabled="">Hello World</button>
```
- The element helloButton is disabled

#### Comments
- Use an empty string (`""`) or the name of the attribute are recommended to set the value of a Boolean attribute
- Regardless of its actual value, a value of a Boolean attribute is considered to be true
- The absence of the attribute means its value is false

### FYI
- Use getAttribute() to get the current value of an attribute
- Call removeAttribute() to remove an attribute

___

### References
- [Element.setAttribute()](https://developer.mozilla.org/en-US/docs/Web/API/Element/setAttribute)