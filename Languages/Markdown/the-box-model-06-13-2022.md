[TIL on June 13th, 2022](../../TIL/2022/06/06-13-2022.md) <br>

# **The box model**

### Introduction
- Everything in CSS has a box around it
- Understanding these boxes is key to being able to create layouts with CSS, or to align items with other items

### Outer display type: block and inline boxes

#### Two types of boxes: block boxes and inline boxes
- These characteristics refer to how the box behaves in terms of page flow and in relation to other boxes on the page

#### A block box of an outer display type
- Added boxes will break onto new lines, i.e., one block box occupies one line
- will extend in the inline direction to fill the space available in its container. In most cases this means that the box will become as wide as its container, filling up 100% of the space available
- The width and height properties are respected
- Padding, margin and border will cause other elements to be pushed away from the box
- Some HTML elements (such as `<h1> and <p>`), use block as their outer display type by default

#### A inline box of an outer display type
- Added boxes will not break onto new lines, i.e., one inline box shares one line with the other boxes
- The width and height properties will not apply
- Vertical padding, margins, and borders will apply but will not cause other inline boxes to move away from the box
- Horizontal padding, margins, and borders will apply and will cause other inline boxes to move away from the box
- Some HTML elements (such as `<a>, <span>, <em> and <strong>`), use inline as their outer display type by default

#### Aside: Inner and outer display types
- Boxes also have an inner display type, however, which dictates how elements inside that box are laid out
- By default, the elements inside a box are laid out in normal flow, which means that they behave just like any other block and inline elements (as explained above)
- We can change the inner display type by using display values like flex:
  * If we set `display: flex;` on an element, the outer display type is block, but the inner display type is changed to flex
- Any direct children of this box will become flex items and will be laid out according to the rules set out in the Flexbox spec

___

### References
- [The box model: mdn web docs](https://developer.mozilla.org/en-US/docs/Learn/CSS/Building_blocks/The_box_model)

### Test
- [The box model.html](./the-box-model-06-13-2022.html)