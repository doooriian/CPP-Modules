<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/cppm.png" width="115" alt="CPP06 bonus badge" /></a>

# CPP06 · C++ casts

**Scalar conversion, pointer serialization and RTTI**

<img src="https://img.shields.io/badge/42-C%2B%2B_Module_06-2563EB?style=flat-square" alt="C++ module 06" />
<img src="https://img.shields.io/badge/Standard-C%2B%2B98-334155?style=flat-square" alt="C++98" />

[← All modules](../README.md)

</div>

---

## 🔎 Overview

**Casts & RTTI** — scalar conversion, pointer serialization and RTTI. This module contains **3 exercises** in separate directories, each with its own Makefile.

## ✨ Exercises

| Directory | Exercise | What the implementation demonstrates |
| :--- | :--- | :--- |
| [`ex00`](ex00/) | **Conversion of scalar types** | Parse scalar literals and format conversions to `char`, `int`, `float` and `double`. |
| [`ex01`](ex01/) | **Serialization** | Round-trip a `Data*` via `uintptr_t` using `reinterpret_cast`. |
| [`ex02`](ex02/) | **Identify real type** | Identify polymorphic instances of `A`, `B` or `C` with `dynamic_cast` on pointers and references. |

## 🧠 Implementation notes

`ScalarConverter` handles printable characters, numeric boundaries and special floating-point values. `Serializer` demonstrates the difference between storing a pointer representation and serializing object content; the RTTI exercise contrasts successful and failing casts.

## 🚀 Build & try it

Run from the **root of the combined repository**:

```bash
cd CPP06/ex00
make
./convert 42
./convert nanf
```

The modules follow the 42 C++98 toolchain. Each exercise is built separately with its own Makefile; run `make fclean` in the exercise directory to remove build outputs.

## ⚠️ Notes

The pointer conversion exercise is a pointer/integer round-trip in one process; it is not file or network serialization.

These summaries describe files inspected in the original private repositories. They do **not** claim that all exercises have passed fresh automated tests on this combined repository.

---

<sub>Previous: [`CPP05`](../CPP05/README.md) · Next: [`CPP07`](../CPP07/README.md) · [GitHub profile](https://github.com/doooriian)</sub>
