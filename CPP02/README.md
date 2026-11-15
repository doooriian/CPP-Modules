<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/cppm.png" width="115" alt="CPP02 bonus badge" /></a>

# CPP02 · Ad-hoc polymorphism

**Canonical form, fixed-point numbers and operator overloads**

<img src="https://img.shields.io/badge/42-C%2B%2B_Module_02-7C3AED?style=flat-square" alt="C++ module 02" />
<img src="https://img.shields.io/badge/Standard-C%2B%2B98-334155?style=flat-square" alt="C++98" />

[← All modules](../README.md)

</div>

---

## 🔎 Overview

**Operators & numerics** — canonical form, fixed-point numbers and operator overloads. This module contains **4 exercises** in separate directories, each with its own Makefile.

## ✨ Exercises

| Directory | Exercise | What the implementation demonstrates |
| :--- | :--- | :--- |
| [`ex00`](ex00/) | **My First Class in Orthodox Canonical Form** | Implement the basic lifecycle for a `Fixed` class. |
| [`ex01`](ex01/) | **Towards a more useful fixed-point number class** | Add conversions between `Fixed`, integer and floating-point representations. |
| [`ex02`](ex02/) | **Now we’re talking** | Overload arithmetic, comparison and increment/decrement operators; implement `min`/`max`. |
| [`ex03`](ex03/) | **BSP** | Use `Point`, `Fixed` and a sign-of-cross-products test to determine whether a point lies inside a triangle. |

## 🧠 Implementation notes

The `Fixed` representation uses eight fractional bits. The later exercises expose operators and const-correct overloads; `ex03/bsp.cpp` uses three determinant signs to perform a point-in-triangle check.

## 🚀 Build & try it

Run from the **root of the combined repository**:

```bash
cd CPP02/ex03
make
./bsp
```

The modules follow the 42 C++98 toolchain. Each exercise is built separately with its own Makefile; run `make fclean` in the exercise directory to remove build outputs.

## ⚠️ Notes

This is an educational fixed-point implementation. Triangle-boundary behaviour follows the sign tests in `bsp.cpp` (points exactly on an edge are not classified as strictly inside).

These summaries describe files inspected in the original private repositories. They do **not** claim that all exercises have passed fresh automated tests on this combined repository.

---

<sub>Previous: [`CPP01`](../CPP01/README.md) · Next: [`CPP03`](../CPP03/README.md) · [GitHub profile](https://github.com/doooriian)</sub>
