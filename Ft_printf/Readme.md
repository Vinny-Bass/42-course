<h1 align="center">
	✏️ ft_printf
</h1>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/Vinny-bass/42-course/tree/main/Ft_printf?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/Vinny-bass/42-course/tree/main/Ft_printf?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/Vinny-bass/42-course/tree/main/Ft_printf?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/Vinny-bass/42-course/tree/main/Ft_printf?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/Vinny-bass/42-course/tree/main/Ft_printf?color=green" />
</p>

---

## 💡 About the project

> _Recoded version of printf._

	This project consists of coding a library that contains a simplified version of the printf function.

---

## ⚠️ Requirements

The function is written in C language and thus needs the **`cc` compiler** and some standard **C libraries** to run.

* Don’t implement the buffer management of the original printf().
* Your function has to handle the following conversions: `cspdiuxX%`
* Your function will be compared against the original printf().
* You must use the command ar to create your library.
Using the libtool command is forbidden.
* Your libftprintf.a has to be created at the root of your repository

### Bonus

* Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
* Manage all the following flags: ’# +’ (Yes, one of them is a space)

### Limitations

* Max 25 lines per function
* Max 5 functions per file
* Max 5 vars per function
* Max 4 arguments

---
## 🛠️ Usage

### Instructions

**1. Compiling the library**

To compile, go to the library path and run:

```shell
$ make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "ft_printf.h"
```

## 📋 Testing

You can use this third party tester to fully test the project:

* [Tripouille/printfTester](https://github.com/Tripouille/printfTester)
* [paulo-santana/ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester)