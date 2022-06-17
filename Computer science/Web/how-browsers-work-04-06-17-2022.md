[TIL on June 17th, 2022](../../TIL/2022/06/06-17-2022.md)
# **How Browsers Work 04: Render**

### Render
Rendering steps include:
- style
- layout
- paint; and
- compositing (in some cases)

#### Render tree
- The CSSOM and DOM trees are combined into a render tree
- A render tree is then used to compute the layout of every visible element
- Then, visible elements are then painted to the screen
- In some cases, GPU can be utilized for painting to free up the main thread

### Style
- Combining the DOM and CSSOM into a render tree: the third step in the critical rendering path
- The render tree (or computed style tree) construction starts with the root of the DOM tree, traversing each visible node
  * Match up all the relevant styles to every visible node in the DOM tree
  * Determine what the computed styles are for each node based on the CSS cascade rule
- Tags that aren't going to be displayed are not included in the render tree as they will not appear in the rendered output such as:
  * `<head>` and its children; or
  * any nodes with `display: none`
- Meanwhile, nodes with `visibility: hidden` applied are included in the render tree, as they do take up space

___

### References
- [Populating the page: how browsers work-Render](https://developer.mozilla.org/en-US/docs/Web/Performance/How_browsers_work#render)