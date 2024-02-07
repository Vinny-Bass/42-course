<h1 align="center">
	✏️ get_next_line
</h1>

## 💡 About the project

> _Write a function that returns a line read from a file descriptor._

	This project is about programming a function that returns a line read from a file descriptor.

---

## ⚠️ Requirements

The function is written in C language and thus needs the **`cc` compiler** and some standard **C libraries** to run.

* Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
* Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
* Make sure that your function works as expected both when reading a file and when
reading from the standard input.
* Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.

### Bonus

* Develop get_next_line() using only one static variable.
* Your get_next_line() can manage multiple file descriptors at the same time.
For example, if you can read from the file descriptors 3, 4 and 5, you should be
able to read from a different fd per call without losing the reading thread of each
file descriptor or returning a line from another fd.
It means that you should be able to call get_next_line() to read from fd 3, then
fd 4, then 5, then once again 3, once again 4, and so forth.

### Limitations

* Max 25 lines per function
* Max 5 functions per file
* Max 5 vars per function
* Max 4 arguments
* Only the while loop structure is available
* No external libs or functions allowed, except for malloc and free.
