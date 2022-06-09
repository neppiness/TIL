[TIL on June 9th, 2022](../TIL/2022/06/06-09-2022.md)
# **Abstraction Levels and Layers**

### I. Abstraction levels in computing science

|Layers of Abstraction       |
|:--------------------------:|
|Application                 |
|Algorithm                   |
|Programming Language        |
|Assembly Language           |
|Machine Code                |
|Instruction Set Architecture|
|Micro Architecture          |
|Gates/Registers             |
|Devices (Transistors)       |
|Physics                     |

- Order of complexity increases as the row goes down
- Order of abstraction increases as the row goes up
- Instruction Set Architecture is a boundary between hardware and software

### II. Abstraction layers for programming
#### 1. What is an abstraction layer:
- **is a way of hiding the working details of a subsystem**
- is a generalization of a conceptual model or algorithm, away from any specific implementation
  * These generalizations arise from broad similarities that are best encapsulated by models that express similarities present in various specific implementations

#### 2. The characteristics of an abstraction layer:
- The simplification provided by a good abstraction layer allows for easy reuse
  * by distilling a useful concept or design pattern so that situations, where it may be accurately applied, can be quickly recognized

#### 3. Rules
- A layer is considered to be on top of another if it depends on it
- Every layer can exist without the layers above it, and requires the layers below it to function
- Frequently '*abstraction layers*' can be composed into a hierarchy of '*abstraction levels*'
___

### References
- [A Dive, Down the Levels of Abstraction](https://medium.com/@twitu/a-dive-down-the-levels-of-abstraction-227c96c7933c)
- [Wikipedia: Abstraction layer](https://en.wikipedia.org/wiki/Abstraction_layer)