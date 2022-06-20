[TIL on May 20th, 2022](../../TIL/2022/06/06-20-2022.md)
# **Document.querySelector()**

### Syntax
- `querySelector(selectors)`

#### Parameters
`selectors`:
- A string containing one or more selectors to match
- This string must be a valid CSS selector string; if it isn't, a SyntaxError exception is thrown

Note: Characters that are no
#### Return value
  * 'The first Element' within the document that matches the specified selector, or group of selectors
  * `null` returns if there are no matches found
  * If you need a list of all elements matching the specified selectors, you should use querySelectorAll() instead

### Escaping special characters
- To match against an ID or selectors that do not follow standard CSS syntax (by using a colon or space inappropriately, for example), you must escape the character with a backslash ("\")
- As the backslash is also an escape character in JavaScript, if you are entering a literal string, you must escape it twice (once for the JavaScript string, and another time for querySelector()):
```html
<div id="foo\bar"></div>
<div id="foo:bar"></div>

<script>
  console.log('#foo\bar');               // "#fooar" (\b is the backspace control character)
  document.querySelector('#foo\bar');    // Does not match anything

  console.log('#foo\\bar');              // "#foo\bar"
  console.log('#foo\\\\bar');            // "#foo\\bar"
  document.querySelector('#foo\\\\bar'); // Match the first div

  document.querySelector('#foo:bar');    // Does not match anything
  document.querySelector('#foo\\:bar');  // Match the second div
</script>
```

### *Examples*
#### Finding the first element matching a class
- In this example, the first element in the document with the class "myclass" is returned:

```js
var el = document.querySelector(".myclass");
```

#### Complex selectors
- In the example given below, the first `<input>` element with the name "login" (`<input name="login"/>`) located inside a `<div>` whose class is "user-panel main" (`<div class="user-panel main">`) in the document is returned:

```js
var el = document.querySelector("div.user-panel.main input[name='login']");
```

#### Negation
- As all CSS selector strings are valid, you can also negate selectors:

```js
var el = document.querySelector("div.user-panel:not(.main) input[name='login']");
```

- This will select an input with a parent div with the `user-panel` class but not the `main` class.

___

### References
- [Document.querySelector()](https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelector)