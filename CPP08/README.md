<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/cppm.png" width="115" alt="CPP08 bonus badge" /></a>

# CPP08 · Templated containers and iterators

**STL algorithms, iterator ranges and container adapters**

<img src="https://img.shields.io/badge/42-C%2B%2B_Module_08-0F766E?style=flat-square" alt="C++ module 08" />
<img src="https://img.shields.io/badge/Standard-C%2B%2B98-334155?style=flat-square" alt="C++98" />

[← All modules](../README.md)

</div>

---

## 🔎 Overview

**STL & iterators** — sTL algorithms, iterator ranges and container adapters. This module contains **3 exercises** in separate directories, each with its own Makefile.

## ✨ Exercises

| Directory | Exercise | What the implementation demonstrates |
| :--- | :--- | :--- |
| [`ex00`](ex00/) | **Easy find** | Search for an integer in a container using `std::find` and iterator types. |
| [`ex01`](ex01/) | **Span** | Store integers and calculate shortest/longest distances; add entire iterator ranges. |
| [`ex02`](ex02/) | **Mutated abomination** | Extend `std::stack` with iterator access to its underlying container, including const and reverse iterators. |

## 🧠 Implementation notes

`Span` uses `std::vector`, sorting and min/max algorithms; `MutantStack` exposes iterators from the underlying container of the stack adapter. These examples cover both generic algorithms and container interfaces.

## 🚀 Build & try it

Run from the **root of the combined repository**:

```bash
cd CPP08/ex01
make
./span
```

The modules follow the 42 C++98 toolchain. Each exercise is built separately with its own Makefile; run `make fclean` in the exercise directory to remove build outputs.

## ⚠️ Notes

The exercises intentionally build small utilities around STL components rather than a complete general-purpose container library.

These summaries describe files inspected in the original private repositories. They do **not** claim that all exercises have passed fresh automated tests on this combined repository.

---

<sub>Previous: [`CPP07`](../CPP07/README.md) · Next: [`CPP09`](../CPP09/README.md) · [GitHub profile](https://github.com/doooriian)</sub>
