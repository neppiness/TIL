[TIL on June 21st, 2022](../../TIL/2022/06/06-21-2022.md)
# **append vs. insertBefore**

### Element.append()
- The `Element.append()` method inserts a set of Node objects or string objects after the last child of the `Element`
- String objects are inserted as equivalent Text nodes.

#### Differences from Node.appendChild():
- Element.append() allows you to also append string objects, whereas Node.appendChild() only accepts Node objects.
- Element.append() has no return value, whereas Node.appendChild() returns the appended Node object
- Element.append() can append several nodes and strings, whereas Node.appendChild() can only append one node

#### Example: appending an element and text
```js
let div = document.createElement("div")
let p = document.createElement("p")
div.append("Some text", p)

console.log(div.childNodes) // NodeList [ #text "Some text", <p> ]
```

<br>

### Node.insertBefore()
- The `insertBefore()` method of the Node interface inserts `a new node` before `a reference node` as a child of a specified parent node

#### Syntax
`insertBefore(newNode, referenceNode);`

#### Additional function
- If the given node already exists in the document, insertBefore() moves it from its current position to the new position:
  * e.g. That is, it will automatically be removed from its existing parent before appending it to the specified new parent.)
  * This means that a node cannot be in two locations of the document simultaneously.

- Note: The Node.cloneNode() can be used to make a copy of the node before appending it under the new parent. Note that the copies made with cloneNode() will not be automatically kept in sync.

- If the given child is a DocumentFragment, the entire contents of the DocumentFragment are moved into the child list of the specified parent node.

<br>

### Differences between two methods
|Methods       |Target        |Function                                                                             |
|--------------|--------------|-------------------------------------------------------------------------------------|
|append()      |Node or string|Inserts a set of Node objects or string objects after the last child of the `Element`|
|insertBefore()|Node          |Inserts `a new node` before `a reference node` as a child of a specified parent node |

___

### References
- [Element.append()](https://developer.mozilla.org/en-US/docs/Web/API/Element/append#appending_text)
- [Node.insertBefore()](https://developer.mozilla.org/en-US/docs/Web/API/Node/insertBefore)