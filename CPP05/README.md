<div align="center">

# CPP05 · Exceptions

**Exception safety, constrained objects and abstract form execution**

<img src="https://img.shields.io/badge/42-C%2B%2B_Module_05-0891B2?style=flat-square" alt="C++ module 05" />
<img src="https://img.shields.io/badge/Standard-C%2B%2B98-334155?style=flat-square" alt="C++98" />

[← All modules](../README.md)

</div>

---

## 🔎 Overview

**Exceptions** — exception safety, constrained objects and abstract form execution. This module contains **4 exercises** in separate directories, each with its own Makefile.

## ✨ Exercises

| Directory | Exercise | What the implementation demonstrates |
| :--- | :--- | :--- |
| [`ex00`](ex00/) | **Mommy, when I grow up, I want to be a bureaucrat!** | Implement grade constraints and exceptions in `Bureaucrat`. |
| [`ex01`](ex01/) | **Form up, maggots!** | Model forms with signing requirements and grade validation. |
| [`ex02`](ex02/) | **No, you need form 28B, not 28C…** | Introduce abstract `AForm` and specialized shrubbery, robotomy and pardon actions. |
| [`ex03`](ex03/) | **At least this beats coffee-making** | Use `Intern` as a factory that creates specific forms from a request name. |

## 🧠 Implementation notes

`AForm` is abstract and exposes `executeAction()` as a pure virtual operation. The exercise couples permission-like grade checks with exception-based error handling, while `Intern` selects concrete forms.

## 🚀 Build & try it

Run from the **root of the combined repository**:

```bash
cd CPP05/ex03
make
./Execute
```

The modules follow the 42 C++98 toolchain. Each exercise is built separately with its own Makefile; run `make fclean` in the exercise directory to remove build outputs.

## ⚠️ Notes

The bureaucratic system is a teaching scenario for validation, exceptions and polymorphism, not a production authorization model.

These summaries describe files inspected in the original private repositories. They do **not** claim that all exercises have passed fresh automated tests on this combined repository.

---

<sub>Previous: [`CPP04`](../CPP04/README.md) · Next: [`CPP06`](../CPP06/README.md) · [GitHub profile](https://github.com/doooriian)</sub>
