[TIL on May 16th, 2022](../../TIL/2022/06/06-14-2022.md)
# **Scroll APIs**

### Scroll by
> The Window.scrollBy() method scrolls the document in the window by the given amount
```ts
scrollBy(x-coord, y-coord)
scrollBy(options)
```

#### Parameters
- x-coord: the horizontal pixel value that you want to scroll by
- y-coord: the vertical pixel value that you want to scroll by
- options: A dictionary containing the following parameters:
  * top: Specifies the number of pixels along the Y axis to scroll the window or element
  * left: Specifies the number of pixels along the X axis to scroll the window or element
  * behavior: Specifies whether the scrolling should animate smoothly (smooth), happen instantly in a single jump (instant), or let the browser choose (auto, default)


### Scroll to
> Window.scrollTo() scrolls to a particular set of coordinates in the document
```ts
scrollTo(x-coord, y-coord)
scrollTo(options)
```

#### Parameters
- x-coord: the pixel along the horizontal axis of the document that you want displayed in the upper left.
- y-coord: the pixel along the vertical axis of the document that you want displayed in the upper left.
- options: Is identical as listed above


### Scroll into view
> The Element interface's scrollIntoView() method scrolls the element's parent container such that the element on which scrollIntoView() is called is visible to the user

```ts
scrollIntoView()
scrollIntoView(alignToTop)
scrollIntoView(scrollIntoViewOptions)
```
Check the reference for more information

___

### References
- [Scroll by](https://developer.mozilla.org/en-US/docs/Web/API/Window/scrollBy)
- [Scroll to](https://developer.mozilla.org/ko/docs/Web/API/Window/scrollTo)
- [Scroll into view](https://developer.mozilla.org/ko/docs/Web/API/Element/scrollIntoView)