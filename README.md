# cmdlang
A simple programming / command language

# Usage
|   Parameter   | Definition |
|---------------|------------|
| -r file       | Execute <code>file</code> with the interpreter |
| -m file out   | Compress <code>file</code> and write the result to <code>out</code> |
| -c file out   | **(Coming in the future)** Transpile <code>file</code> into C, write the result to <code>out</code> |


# Syntax
| Command | Definition |
|---------|------------|
| /       | Single-line comment										|
| +       | Increment the current cell value						|
| -       | Decrement the current cell value						|
| >       | Increment the cell pointer								|
| <       | Decrement the cell pointer								|
| ,       | Input a number into the current cell					|
| .       | Output the current cell's value as a character			|
| :       | Output the current cell's value as a number				|
| [       | Jump forward to <code>]</code> if 0, else continue		|
| ]       | Jump back to <code>[</code> if not 0, else continue		|
| !name;  | Define a jump point with the name <code>name</code>		|
| @name;  | Jump to the jump point with the name <code>name</code>	|
| =value (...) | Execute <code>...</code> if the current cell value is equal to <code>value</code> |
| {text}  | Output <code>text</code> to the console (for debugging)	|
| #       | Add a breakpoint										|
| $start,stop; | Print cell values from <code>start</code> to <code>stop</code> |
| ;       | Terminate the program									|

# Tests
To run tests, just run the exe with the parameters <code>-r tests/tests.cl</code>
