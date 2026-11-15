<div align="center">

# CPP04 · Subtype polymorphism

**Virtual functions, abstract classes and deep copying**

<img src="https://img.shields.io/badge/42-C%2B%2B_Module_04-DB2777?style=flat-square" alt="C++ module 04" />
<img src="https://img.shields.io/badge/Standard-C%2B%2B98-334155?style=flat-square" alt="C++98" />

[← All modules](../README.md)

</div>

---

## 🔎 Overview

**Polymorphism** — virtual functions, abstract classes and deep copying. This module contains **3 exercises** in separate directories, each with its own Makefile.

## ✨ Exercises

| Directory | Exercise | What the implementation demonstrates |
| :--- | :--- | :--- |
| [`ex00`](ex00/) | **Polymorphism** | Compare virtual dispatch in `Animal` with non-virtual dispatch in `WrongAnimal`; `Dog` and `Cat` override sounds. |
| [`ex01`](ex01/) | **I don’t want to set the world on fire** | Add `Brain` ownership to derived animals and exercise deep copy semantics. |
| [`ex02`](ex02/) | **Abstract class** | Make `Animal` abstract with a pure virtual `makeSound()` method. |

## 🧠 Implementation notes

The `Brain` class stores an array of 100 ideas. Later versions of the `Animal` hierarchy illustrate why virtual destructors, copying owned state and abstract interfaces matter.

## 🚀 Build & try it

Run from the **root of the combined repository**:

```bash
cd CPP04/ex02
make
# Run the executable named by ex02/Makefile
```

The modules follow the 42 C++98 toolchain. Each exercise is built separately with its own Makefile; run `make fclean` in the exercise directory to remove build outputs.

## ⚠️ Notes

`ex00`, `ex01` and `ex02` intentionally repeat and evolve class implementations; this is the structure of the exercises, not accidental duplication.

These summaries describe files inspected in the original private repositories. They do **not** claim that all exercises have passed fresh automated tests on this combined repository.

---

<sub>Previous: [`CPP03`](../CPP03/README.md) · Next: [`CPP05`](../CPP05/README.md) · [GitHub profile](https://github.com/doooriian)</sub>
