[TIL on May 17th, 2022](../../TIL/2022/05/05-17-2022.md)
# **Python Basics**

### Use of a colon
- Conditional statements
- For loops
- Definition of functions

<br>

### Use of parentheses (()), brackets ([]), and braces ({})
**1. Array**
- Brackets are used to declare or initialize an array. Also, to access a element of an array

```python
arr = [] # For declaration
arr = [1,2,3,4] # For declaration
arr[3] # For indexing an array
```

<br>

**2. tuple**
- Parentheses are used to declare or initialize a tuple
- Brackets are used to access a element of a tuple

```python
empty_tuple = ()          # Create empty tuple
numbers_tuple = (1,2,3,4) # Declare a tuple

numbers_tuple[3]          # Access to tuple element
```

- A tuple could not remove or update the elements already created meanwhile array could
- python recommends to use a tuple to collect elements in same datatype
- If the statement above is not satisfied, python doesn't raise an error

<br>

**3. Dictionary**
- A dictionary is a typical data type using braces 
- Braces are used to declare or initialize a dictionary.
- Brackets ([]) are used to assign value correspond to key or to access a value

```python
my_dictionary = {} # Create empty dictionary
my_dictionary = {"mouse":3, "penguin":5}

my_dictionary["mouse"]   # To access value (3) correspond to key "mouse"
my_dictionary["cat"] = 1 # Assign value (1) corresponse to key "cat"
```

<br>

### Naming styles
| Type     | Naming Convention                                                                                               | Examples                                |
| -------- | --------------------------------------------------------------------------------------------------------------- | --------------------------------------- |
| Function | Use a lowercase word or words. Separate words by underscores to improve readability.                            | function, my_function                   |
| Variable | Use a lowercase single letter, word, or words. Separate words with underscores to improve readability.          | x, var, my_variable                     |
| Class    | Start each word with a capital letter. Do not separate words with underscores. This style is called camel case. | Model, MyClass                          |
| Method   | Use a lowercase word or words. Separate words with underscores to improve readability.	                         | class_method, method                    |
| Constant | Use an uppercase single letter, word, or words. Separate words with underscores to improve readability.         | CONSTANT, MY_CONSTANT, MY_LONG_CONSTANT |
| Module   | Use a short, lowercase word or words. Separate words with underscores to improve readability.                   | module.py, my_module.py                 |
| Package  | Use a short, lowercase word or words. Do not separate words with underscores.                                   | package, mypackage                      |

___

### Reference
- [() [] {}의 차이와 사용해야 할 곳](https://hashcode.co.kr/questions/4118/%EC%9D%98-%EC%B0%A8%EC%9D%B4%EC%99%80-%EC%82%AC%EC%9A%A9%ED%95%B4%EC%95%BC-%ED%95%A0-%EA%B3%B3)
- [parentheses, brackets, and braces](https://practicaltypography.com/parentheses-brackets-and-braces.html#:~:text=Parentheses%20are%20for%20separating%20citations,in%20technical%20and%20mathematical%20writing.)
- [How to Write Beautiful Python Code With PEP 8](https://realpython.com/python-pep8/)