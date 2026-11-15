<div align="center">

# CPP07 · Templates

**Generic functions and a dynamically allocated template array**

<img src="https://img.shields.io/badge/42-C%2B%2B_Module_07-7C3AED?style=flat-square" alt="C++ module 07" />
<img src="https://img.shields.io/badge/Standard-C%2B%2B98-334155?style=flat-square" alt="C++98" />

[← All modules](../README.md)

</div>

---

## 🔎 Overview

**Templates** — generic functions and a dynamically allocated template array. This module contains **3 exercises** in separate directories, each with its own Makefile.

## ✨ Exercises

| Directory | Exercise | What the implementation demonstrates |
| :--- | :--- | :--- |
| [`ex00`](ex00/) | **Start with a few functions** | Implement function templates `swap`, `min` and `max`. |
| [`ex01`](ex01/) | **Iter** | Write overloads of `iter` for mutable and const arrays and apply a callback to elements. |
| [`ex02`](ex02/) | **Array** | Implement `Array<T>` with dynamic storage, copy operations, size queries and checked indexing. |

## 🧠 Implementation notes

The template code lives in headers and `.tpp` files, so definitions can be instantiated at compile time. `Array<T>` implements a deep copy and throws for out-of-bounds access.

## 🚀 Build & try it

Run from the **root of the combined repository**:

```bash
cd CPP07/ex02
make
./Array
```

The modules follow the 42 C++98 toolchain. Each exercise is built separately with its own Makefile; run `make fclean` in the exercise directory to remove build outputs.

## ⚠️ Notes

`Array<T>` is a learning-oriented container. It is not intended to replace the standard library `std::vector`.

These summaries describe files inspected in the original private repositories. They do **not** claim that all exercises have passed fresh automated tests on this combined repository.

---

<sub>Previous: [`CPP06`](../CPP06/README.md) · Next: [`CPP08`](../CPP08/README.md) · [GitHub profile](https://github.com/doooriian)</sub>
