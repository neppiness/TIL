[TIL on May 16th, 2022](../../TIL/2022/06/06-14-2022.md)
# **Page and Client Coordinates**

### pageX or (pageY)
MouseEvent.pageX
- is a read-only property of the MouseEvent interface
- returns the X, horizontal coordinate (or Y, vertical coordinate) in pixels, at which the mouse was clicked, relative to the left edge of the entire document
- This includes any portion of the document not currently visible

#### Example
```js
var box = document.querySelector(".box");
var pageX = document.getElementById("x");
var pageY = document.getElementById("y");

function updateDisplay(event) {
  pageX.innerText = event.pageX;
  pageY.innerText = event.pageY;
}

box.addEventListener("mousemove", updateDisplay, false);
box.addEventListener("mouseenter", updateDisplay, false);
box.addEventListener("mouseleave", updateDisplay, false);
```

### clientX (or clientY)
MouseEvent.clientX
- is a read-only property of the MouseEvent interface
- provides the horizontal (or vertical) coordinate within the application's viewport at which the event occurred (as opposed to the coordinate within the page)

___

### Reference
- [MouseEvent.pageX](https://developer.mozilla.org/en-US/docs/Web/API/MouseEvent/pageX)
- [MouseEvent.clientX](https://developer.mozilla.org/en-US/docs/Web/API/MouseEvent/pageX)