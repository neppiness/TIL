# **TIL Conventions**

### Types of TIL files
* Two types of TIL files: a TIL list file and a TIL content file
* TIL list: a list of a TIL content
* TIL content: a note about a specific subject

### Naming
* TIL content file: 'Title'-'Date'
* TIL list file: 'Date'
* 'Title' is written in kebab case or hyphen-separated style
* 'Date' is written in MM-DD-YYYY format
* ex1) markdown-basics-05-15-2022.md (TIL content)
* ex2) 05-15-2022.md (TIL list)
* Folder: snake-case is used for folder naming
* ex) problem_solving, TIL (because it's a abbr.)

<br>

### Style for headings
* Heading 1: only for a title of a file
* Heading 2: categories to classify main items
* Heading 3: main items
* Bold font is applied only to heading 1

<br>

### Main body
* Italic font may be applied to some emphasis words
* Bold may not be applied to plain texts
* List
  - Minimize level of lists
  - List symbols for level 1, 2, and 3 are `*`, `-`, and `+`, respectively
* New line `<br>` is required between headings

<br>

### TIL content file: TIL list link and references
* TIL list link: written as a format of "TIL on MM-DD-YYYY" at the top
* References: at the bottom, separated by a line above it

<br>

### Commit message
* Format is given as below:
  - {activity}: {object} on {Month} {Day} (to {Day}), {Year}
* Here are the examples:
  1. update: TIL on April 4th to 6th, 2023
  2. update: convention.md on April 6th, 2023
