[TIL on May 16th, 2022](../../TIL/2022/06/06-16-2022.md)
# **Node and EventTarget**

### Node
- The DOM Node interface is an abstract base class
- Many other DOM API objects are based upon this interface
- Makes those object types to be used similarly and often interchangeably

#### Node as an abstract class
  * There is no such thing as a plain Node object
  * All objects that implement Node functionality are based on one of its subclasses
  * Most notable are Document, Element, and DocumentFragment.

> In addition, every kind of DOM node is represented by an interface based on Node. These include Attr, CharacterData (which Text, Comment, CDATASection and ProcessingInstruction are all based on), and DocumentType

> In some cases, a particular feature of the base Node interface may not apply to one of its child interfaces; in that case, the inheriting node may return null or throw an exception, depending on circumstances. For example, attempting to add children to a node type that cannot have children will throw an exception

#### Properties
- mdn web docs: [reference](https://developer.mozilla.org/en-US/docs/Web/API/Node#properties)

#### Methods
- mdn web docs: [reference](https://developer.mozilla.org/en-US/docs/Web/API/Node#methods)

### EventTarget
- The `EventTarget` interface is implemented by objects that can receive events and may have listeners for them. In other words, any target of events implements the three methods associated with this interface.

#### Event targets 
- Commonly, Element, and its children, Document and Window
- Also, XMLHttpRequest, AudioNode, and AudioContext

#### `onevent`
- Many event targets (including elements, documents, and windows) also support setting event handlers via `onevent` properties and attributes.
- For more information: [link](https://developer.mozilla.org/en-US/docs/Web/API/EventTarget)