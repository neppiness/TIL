[TIL on June 17th, 2022](../../TIL/2022/06/06-17-2022.md)
# **How Browsers Work 04: Render**

### Rendering Steps
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

### Layout
- Is 4th step in the critical rendering path
- Running layout on the render tree to compute the geometry of each node
- Layout: the process by which the width, height, and location of all the nodes in the render tree are determined, plus the determination of the size and position of each object on the page
- Reflow: any subsequent recalculation of node size and position determination

### Paint
- Is the last step in the critical rendering path
- In painting phase, the browser converts each box to actual pixels on the screen
- Painting involves drawing every visual part of an element to the screen
- Drawing objects are text, colors, borders, shadows, and replaced elements like buttons and images
- To make repainting fast, compositing is needed to break screen into several layers

Painting can break the elements in the layout tree into layers.

#### Use of GPU
- Using GPU instead of the main thread on the CPU, improves paint and repaint performance
  * `<video>` and `<canvas>`;
  * any element which has the CSS properties of opacity;
  * a 3D transform;
  * will-change and etc.
- These nodes will be painted onto their own layer

#### Use of layers
- Layers do improve performance
- But they are expensive when it comes to memory management
- Do not be overused as part of web performance optimization strategies

### Compositing
Compositing is necessary
- when sections of the document are drawn in different layers, overlapping each other:
- to ensure they are drawn to the screen in the right order and;
- the content is rendered correctly

#### Reflows can happen:
- As the page continues to load assets
- A reflow sparks a repaint and a re-composite

___

### References
- [Populating the page: how browsers work-Render](https://developer.mozilla.org/en-US/docs/Web/Performance/How_browsers_work#render)