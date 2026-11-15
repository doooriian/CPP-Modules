<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/cppe.png" alt="42 C++ badge (standard edition)" width="135" /></a>

# C++ Modules

### From object-oriented fundamentals to algorithms and the STL

A collection of exercises from the **42 curriculum**, written in **C++98**.

<img src="https://img.shields.io/badge/C%2B%2B-98-2563EB?style=flat-square&logo=cplusplus&logoColor=white" alt="C++98" />
<img src="https://img.shields.io/badge/42-10_Modules-0F766E?style=flat-square" alt="10 modules" />
<img src="https://img.shields.io/badge/Focus-Systems_%26_Software_Engineering-7C3AED?style=flat-square" alt="Software engineering" />

[**Explore modules**](#-module-overview) · [**Build examples**](#-getting-started) · [**GitHub profile**](https://github.com/doooriian)

</div>

---

## 👋 About this repository

This repository groups the work originally developed across **CPP00 to CPP09** at 42. It demonstrates the progressive move from basic classes and object lifetimes to inheritance, polymorphism, exceptions, templates, STL containers and sorting algorithms.

The goal is to make the actual code **easy to explore**. Each module keeps its original exercise organization and includes a dedicated README describing what its source implements.

## 🧭 Module overview

| Module | Main topic | Concepts | Exercises |
| :--- | :--- | :--- | :---: |
| [CPP00](CPP00/README.md) | **Introduction to C++** | Namespaces, streams, classes and encapsulation | 3 |
| [CPP01](CPP01/README.md) | **Memory, references and control flow** | Lifetimes, pointers, references and member functions | 7 |
| [CPP02](CPP02/README.md) | **Ad-hoc polymorphism** | Canonical form, fixed-point numbers and operator overloads | 4 |
| [CPP03](CPP03/README.md) | **Inheritance** | Base classes, derived classes and multiple inheritance | 4 |
| [CPP04](CPP04/README.md) | **Subtype polymorphism** | Virtual functions, abstract classes and deep copying | 3 |
| [CPP05](CPP05/README.md) | **Exceptions** | Exception safety, constrained objects and abstract form execution | 4 |
| [CPP06](CPP06/README.md) | **C++ casts** | Scalar conversion, pointer serialization and RTTI | 3 |
| [CPP07](CPP07/README.md) | **Templates** | Generic functions and a dynamically allocated template array | 3 |
| [CPP08](CPP08/README.md) | **Templated containers and iterators** | STL algorithms, iterator ranges and container adapters | 3 |
| [CPP09](CPP09/README.md) | **STL and algorithms** | Maps, stacks, sorting algorithms and performance comparison | 3 |

## 🧱 Repository layout

```text
CPP-Modules/
├── README.md
├── CPP00/
│   ├── README.md
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
├── CPP01/
│   ├── README.md
│   └── ex00/ ... ex06/
├── ...
├── CPP09/
│   ├── README.md
│   └── ex00/ ... ex02/
└── scripts/
    ├── import-sources.sh
    └── check-builds.sh
```

Exercises are **independent programs**: repeated class files between exercises are intentional as the 42 modules evolve progressively.

## 🚀 Getting started

### Requirements

- A C++ compiler with **C++98** support (for example `c++` / GCC / Clang)
- `make` and a Unix-like terminal
- Access to the original private module repositories if you are preparing this combined repository from the accompanying template

### Build an exercise

```bash
cd CPP00/ex01
make
./PhoneBook
# ADD / SEARCH / EXIT
```

A second example:

```bash
cd CPP09/ex01
make
./RPN "3 4 +"
```

The individual exercise Makefiles generally compile with `-Wall -Wextra -Werror -std=c++98`. There is no single root executable.

### Build verification

```bash
./scripts/check-builds.sh
```

This helper attempts to compile each tracked exercise with a Makefile and reports failures. It is a **local check**, not a guarantee of runtime correctness or 42 evaluation results.

## 🧠 What these modules showcase

- **C++ fundamentals:** encapsulation, const-correctness, canonical class lifecycle and object ownership
- **Object-oriented design:** inheritance, virtual dispatch, abstract interfaces and exceptions
- **Generic programming:** operator overloads, casts, templates and container abstractions
- **STL & algorithms:** maps, vectors, deques, stacks, iterators and sorting strategies

## ⚠️ Important notes

- **C++98 only** by design: these are 42 school exercises, not a modern C++ application framework.
- `CPP09/ex00` requires a `data.csv` reference file that was **not present in the source repository inspected**. See [CPP09 notes](CPP09/README.md).
- Exercise implementations have been documented from their actual tracked source structure, but have **not been executed or regression-tested as part of this packaging step**.
- No score, certification, bonus completion or automated test success is claimed by the project badge displayed above.

---

<div align="center">

<sub>42 curriculum · C++98 · <a href="https://github.com/doooriian">More projects</a></sub>

</div>
