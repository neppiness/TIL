[TIL on June 16th, 2022](../../TIL/2022/06/06-16-2022.md)
# **How Browsers Work 03: Parsing**

### Introduction
- Parsing: the step the browser takes to turn the data into the *DOM* and *CSSOM*

- [The DOM is the internal representation of the markup for the browser](./dom-06-15-2022.md)
- The DOM can be manipulated through various APIs in JavaScript.

- The browser will begin parsing and attempting to render an experience based on the data it has
- This is why it's important for web performance optimization to include everything the browser needs to start rendering a page, or at least a template of the page - the CSS and HTML needed for the first render -- in the first 14 kilobytes. But before anything is rendered to the screen, the HTML, CSS, and JavaScript have to be parsed

<br>

### Building the DOM tree

First, processing the HTML markup and building the DOM tree

- HTML parsing involves tokenization and tree construction
  * HTML tokens include start and end tags, as well as attribute names and values
  * The parser parses tokenized input into the document, building up the document tree

- *The DOM tree* describes the content of the document.
  * The `<html>` element is the first tag and root node of the document tree
  * The tree reflects the relationships and hierarchies between different tags
  * Tags nested within other tags are child nodes. The greater the number of DOM nodes, the longer it takes to construct the DOM tree

- Blocking/non-blocking resources
  * When the parser finds non-blocking resources, such as an image, the browser will request those resources and continue parsing
  * Parsing can continue when a CSS file is encountered
  * `<script>` tags—particularly those without an async or defer attribute—block rendering, and pause the parsing of HTML
  * Though the browser's preload scanner hastens this process, excessive scripts can still be a significant bottleneck

#### *Preload scanner*
- While the browser builds the DOM tree, this process occupies the main thread
- As this happens, the preload scanner will parse through the content available and request high priority resources like CSS, JavaScript, and web fonts
- Thanks to the preload scanner, we don't have to wait until the parser finds a reference to an external resource to request it
- It will retrieve resources in the background so that by the time the main HTML parser reaches requested assets, they may possibly already be in flight, or have been downloaded.
- The optimizations the preload scanner provides reduce blockages.

```html
<link rel="stylesheet" src="styles.css"/>
<script src="myscript.js" async></script>
<img src="myimage.jpg" alt="image description"/>
<script src="anotherscript.js" async></script>
```

- In this example, while the main thread is parsing the HTML and CSS, the preload scanner will find the scripts and image, and start downloading them as well
- To ensure the script doesn't block the process, add the async attribute, or the defer attribute if JavaScript parsing and execution order is important
- Waiting to obtain CSS doesn't block HTML parsing or downloading, but it does block JavaScript, because JavaScript is often used to query CSS properties' impact on elements

<br>

### Building the CSSOM tree
The second step is processing CSS and building the CSSOM tree
- The CSS object model is independent data structures similar to the DOM
- CSSOM is a tree: the browser converts the CSS rules into a map of styles it can understand and work with
- The browser goes through each rule set in the CSS, creating a tree of nodes with parent, child, and sibling relationships based on the CSS selectors
- Cascading: the browser begins with the most general rule applicable to a node and recursively refines the computed styles by applying more specific rules 

#### DOM vs. CSSOM
- Like HTML, the browser needs to convert the received CSS rules into something it can work with. Hence, it repeats the HTML-to-object process, but for the CSS

#### Relationship between the CSSOM and web-performance
- Building the CSSOM is fast and is not displayed in a unique color in current developer tools
- The total time to create the CSSOM is generally less than the time it takes for one DNS lookup

<br>

### Other Processes
#### JavaScript Compilation
- JavaScript is interpreted, compiled, parsed and executed. The scripts are parsed into *abstract syntax trees*
- Some browser engines take the *Abstract Syntax Tree* and pass it into an interpreter, outputting bytecode which is executed on the main thread. This is known as JavaScript compilation.

#### Building the Accessibility Tree
- The accessibility object model (AOM) is like a semantic version of the DOM
- The browser also builds an accessibility tree that assistive devices use to parse and interpret content
- The browser updates the accessibility tree when the DOM is updated
- The accessibility tree is not modifiable by assistive technologies themselves.
- Until the AOM is built, the content is not accessible to screen readers.

___

### References
- [Populating the page: how browsers work-Parsing](https://developer.mozilla.org/en-US/docs/Web/Performance/How_browsers_work#parsing)