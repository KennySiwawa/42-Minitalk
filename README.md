<h1 align="center">
	💬 minitalk
</h1>

<p align="center">
	<b><i>The virtual machine</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/KennySiwawa/42-Minitalk?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/KennySiwawa/42-Minitalk?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/KennySiwawa/42-Minitalk?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/KennySiwawa/42-Minitalk?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/KennySiwawa/42-Minitalk?color=green" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

> _The purpose of this project is to code a small data exchange program using
UNIX signals._



## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling**

To compile, go to the project path and run:

```shell
$ make
```


## 📋 Testing

To test the program you just need to launch the "server" and the "client" in different shell tabs with the following:

```shell
$ ./server
```

This will show your PID to make the client work and will stay waiting to receive a message from the "client"

```shell
$ ./client "PID" "Your message string"
```

By launching it, this will show "Your message string" on the server window.
