<div align="center">

# CPP01 · Memory, references and control flow

**Lifetimes, pointers, references and member functions**

<img src="https://img.shields.io/badge/42-C%2B%2B_Module_01-0F766E?style=flat-square" alt="C++ module 01" />
<img src="https://img.shields.io/badge/Standard-C%2B%2B98-334155?style=flat-square" alt="C++98" />

[← All modules](../README.md)

</div>

---

## 🔎 Overview

**Memory & ownership** — lifetimes, pointers, references and member functions. This module contains **7 exercises** in separate directories, each with its own Makefile.

## ✨ Exercises

| Directory | Exercise | What the implementation demonstrates |
| :--- | :--- | :--- |
| [`ex00`](ex00/) | **BraiiiiiiinnnzzzZ** | Compare stack-allocated and heap-allocated `Zombie` instances (`newZombie` and `randomChump`). |
| [`ex01`](ex01/) | **Moar brainz!** | Allocate a `Zombie` horde and manage the lifetime of an array. |
| [`ex02`](ex02/) | **HI THIS IS BRAIN** | Inspect the value and addresses of a string, pointer and reference. |
| [`ex03`](ex03/) | **Unnecessary violence** | Contrast reference-based (`HumanA`) and pointer-based (`HumanB`) associations with a `Weapon`. |
| [`ex04`](ex04/) | **Sed is for losers** | Replace occurrences of a string in a text file and write a `.replace` output. |
| [`ex05`](ex05/) | **Harl 2.0** | Select member functions through a table of pointers to methods. |
| [`ex06`](ex06/) | **Harl filter** | Route complaint levels with a switch and intentional fallthrough. |

## 🧠 Implementation notes

The module covers ownership and references, but also small practical applications: file input/output, pointers to member functions and `switch` dispatch. The two Harl exercises are separate implementations.

## 🚀 Build & try it

Run from the **root of the combined repository**:

```bash
cd CPP01/ex04
make
./replace input.txt foo bar
# Creates input.txt.replace
```

You need to supply your own readable `input.txt` file first.

The modules follow the 42 C++98 toolchain. Each exercise is built separately with its own Makefile; run `make fclean` in the exercise directory to remove build outputs.

## ⚠️ Notes

The file replacement exercise requires an input text file. Heap allocation examples require correct destruction by the caller.

These summaries describe files inspected in the original private repositories. They do **not** claim that all exercises have passed fresh automated tests on this combined repository.

---

<sub>Previous: [`CPP00`](../CPP00/README.md) · Next: [`CPP02`](../CPP02/README.md) · [GitHub profile](https://github.com/doooriian)</sub>
