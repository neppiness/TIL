[TIL on June 21st, 2022](../../TIL/2022/06/06-21-2022.md)
# **Node.textContent**
The textContent property of the Node interface represents the text content of the node and its descendants

### Value
- A string, or null. Its value depends on the situation:
  * If the node is a document or a doctype, textContent returns null.
  * If the node is a CDATA section, a comment, a processing instruction, or a text node, textContent returns, or sets, the text inside the node, i.e., the Node.nodeValue.
  * For other node types, textContent returns the concatenation of the textContent of every child node, excluding comments and processing instructions. (This is an empty string if the node has no children.)
- Note: To get all of the text and CDATA data for the whole document, use document.documentElement.textContent.


<br>

### Differences from innerText
- `textContent` gets the content of all elements, including `<script>` and `<style>` elements
- In contrast, innerText only shows "human-readable" elements
- Since `innerText` takes CSS styles into account, reading the value of innerText triggers a reflow to ensure up-to-date computed styles
  * Reflows can be computationally expensive, and thus should be avoided when possible

<br>

### Differences from innerHTML
- `Element.innerHTML` returns HTML, as its name indicates
- `textContent` has better performance because its value is not parsed as HTML
  * Moreover, using `textContent` can prevent XSS attacks

<br>

### TL;DR
- In performance perspective, `textContent` method is better than `innerText` and `innerHTML`
- Because `innerText` occurs reflow and `innerHTML` occurs parsing process

<br>

### Examples
Given this HTML fragment:

```html
<div id="divA">This is <span>some</span> text!</div>
```
You can use textContent to get the element's text content:

```js
let text = document.getElementById('divA').textContent;
// The text variable is now: 'This is some text!'
```

or set the element's text content:
```js
document.getElementById('divA').textContent = 'This text is different!';
// The HTML for divA is now:
// <div id="divA">This text is different!</div>
```
___

### References
- [Node.textContent](https://developer.mozilla.org/en-US/docs/Web/API/Node/textContent)