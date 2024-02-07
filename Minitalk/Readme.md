<h1 align="center">
	✏️ Minitalk
</h1>

## 💡 About the project

> _Client server communication with UNIX signals._

	The purpose of this project is to code a small data exchange program using UNIX signals.

---

## ⚠️ Requirements

The function is written in C language and thus needs the **`cc` compiler** and some standard **C libraries** to run.

* The server must be started first. After its launch, it has to print its PID.
* The client takes two parameters:
    * The server PID.
    * The string to send.
* The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.
*The server has to display the string pretty quickly. Quickly means that if you think
it takes too long, then it is probably too long.
* Your server should be able to receive strings from several clients in a row without
needing to restart.
* The communication between your client and your server has to be done only using
UNIX signals.
* You can only use these two signals: SIGUSR1 and SIGUSR2

### Bonus

* The server acknowledges every message received by sending back a signal to the
client.
* Unicode characters support!

### Limitations

* Max 25 lines per function
* Max 5 functions per file
* Max 5 vars per function
* Max 4 arguments
* Only the while loop structure is available
* No external libs or functions allowed, except for malloc and free.

---
## 🛠️ Usage

### Instructions

**1. Compiling the program**

To compile, go to the library path and run:

```shell
$ make
```

**2. Starting the server**

```shell
$ ./server
```

Copy the PID printed in the terminal.

**3. Send a message to the server**

```shell
$ ./client <PID> <message>
```
