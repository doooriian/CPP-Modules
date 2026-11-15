<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/cppm.png" width="115" alt="CPP03 bonus badge" /></a>

# CPP03 · Inheritance

**Base classes, derived classes and multiple inheritance**

<img src="https://img.shields.io/badge/42-C%2B%2B_Module_03-D97706?style=flat-square" alt="C++ module 03" />
<img src="https://img.shields.io/badge/Standard-C%2B%2B98-334155?style=flat-square" alt="C++98" />

[← All modules](../README.md)

</div>

---

## 🔎 Overview

**Inheritance** — base classes, derived classes and multiple inheritance. This module contains **4 exercises** in separate directories, each with its own Makefile.

## ✨ Exercises

| Directory | Exercise | What the implementation demonstrates |
| :--- | :--- | :--- |
| [`ex00`](ex00/) | **Aaaaand… OPEN!** | Define `ClapTrap` with attack, damage, repair and status behaviour. |
| [`ex01`](ex01/) | **Serena, my love!** | Derive `ScavTrap` from `ClapTrap` and introduce specialized behaviour. |
| [`ex02`](ex02/) | **Repetitive work** | Add `FragTrap`, another derived class with its own features. |
| [`ex03`](ex03/) | **Now it’s weird!** | Combine `ScavTrap` and `FragTrap` in `DiamondTrap`, exploring multiple inheritance and identity. |

## 🧠 Implementation notes

`DiamondTrap` explicitly inherits from both `ScavTrap` and `FragTrap`. The implementation exercises constructor/destructor order, name resolution and the challenges of combining behaviour from two branches.

## 🚀 Build & try it

Run from the **root of the combined repository**:

```bash
cd CPP03/ex03
make
./DiamondTrap
```

The modules follow the 42 C++98 toolchain. Each exercise is built separately with its own Makefile; run `make fclean` in the exercise directory to remove build outputs.

## ⚠️ Notes

Examples are small class hierarchies designed to illustrate inheritance mechanics rather than reusable gameplay components.

These summaries describe files inspected in the original private repositories. They do **not** claim that all exercises have passed fresh automated tests on this combined repository.

---

<sub>Previous: [`CPP02`](../CPP02/README.md) · Next: [`CPP04`](../CPP04/README.md) · [GitHub profile](https://github.com/doooriian)</sub>
