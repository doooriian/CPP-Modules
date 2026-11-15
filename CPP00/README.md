<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/cppm.png" width="115" alt="CPP00 bonus badge" /></a>

# CPP00 · Introduction to C++

**Namespaces, streams, classes and encapsulation**

<img src="https://img.shields.io/badge/42-C%2B%2B_Module_00-2563EB?style=flat-square" alt="C++ module 00" />
<img src="https://img.shields.io/badge/Standard-C%2B%2B98-334155?style=flat-square" alt="C++98" />

[← All modules](../README.md)

</div>

---

## 🔎 Overview

**Object basics** — namespaces, streams, classes and encapsulation. This module contains **3 exercises** in separate directories, each with its own Makefile.

## ✨ Exercises

| Directory | Exercise | What the implementation demonstrates |
| :--- | :--- | :--- |
| [`ex00`](ex00/) | **Megaphone** | Command-line arguments and uppercasing text through the standard output stream. |
| [`ex01`](ex01/) | **PhoneBook** | An interactive phone book with `ADD`, `SEARCH` and `EXIT`, built around `Contact` and `PhoneBook` classes. |
| [`ex02`](ex02/) | **Account** | An account implementation using constructors, destructors and static counters for shared state. |

## 🧠 Implementation notes

Follow the transition from a single-file command-line program to stateful objects and static class members. In `ex01`, input handling and the phone book are separated; in `ex02`, the class tracks totals across accounts.

## 🚀 Build & try it

Run from the **root of the combined repository**:

```bash
cd CPP00/ex01
make
./PhoneBook
# Enter ADD, SEARCH or EXIT
```

The modules follow the 42 C++98 toolchain. Each exercise is built separately with its own Makefile; run `make fclean` in the exercise directory to remove build outputs.

## ⚠️ Notes

Each exercise has its own Makefile; there is no single module-wide executable.

These summaries describe files inspected in the original private repositories. They do **not** claim that all exercises have passed fresh automated tests on this combined repository.

---

<sub>Previous: — · Next: [`CPP01`](../CPP01/README.md) · [GitHub profile](https://github.com/doooriian)</sub>
