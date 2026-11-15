<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/cppm.png" width="115" alt="CPP09 bonus badge" /></a>

# CPP09 · STL and algorithms

**Maps, stacks, sorting algorithms and performance comparison**

<img src="https://img.shields.io/badge/42-C%2B%2B_Module_09-D97706?style=flat-square" alt="C++ module 09" />
<img src="https://img.shields.io/badge/Standard-C%2B%2B98-334155?style=flat-square" alt="C++98" />

[← All modules](../README.md)

</div>

---

## 🔎 Overview

**Algorithms & STL** — maps, stacks, sorting algorithms and performance comparison. This module contains **3 exercises** in separate directories, each with its own Makefile.

## ✨ Exercises

| Directory | Exercise | What the implementation demonstrates |
| :--- | :--- | :--- |
| [`ex00`](ex00/) | **Bitcoin Exchange** | Load date-to-exchange-rate pairs into a map and calculate values using the closest preceding date. |
| [`ex01`](ex01/) | **Reverse Polish Notation** | Evaluate postfix arithmetic using a stack and guard against invalid expressions and arithmetic overflow. |
| [`ex02`](ex02/) | **PmergeMe** | Implement a Ford–Johnson-inspired merge-insertion sort on both `std::vector` and `std::deque`, using Jacobsthal insertion order. |

## 🧠 Implementation notes

This is the most algorithm-heavy module. `BitcoinExchange.cpp` validates calendar dates and performs ordered lookups with `std::map`; `RPN.cpp` processes operators on a stack and explicitly checks overflow; `PmergeMe.cpp` contains separate vector and deque insertion/sorting paths.

## 🚀 Build & try it

Run from the **root of the combined repository**:

```bash
cd CPP09/ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

cd ../ex02
make
./PmergeMe 9 3 7 5 1 8
```

The modules follow the 42 C++98 toolchain. Each exercise is built separately with its own Makefile; run `make fclean` in the exercise directory to remove build outputs.

## ⚠️ Notes

**Important:** `CPP09/ex00/BitcoinExchange.cpp` expects a local `data.csv` file with the header `date,exchange_rate`. That file is **not present** in the checked source repository, so `btc` cannot process exchanges until suitable reference data is supplied. Do not assume the database or example data is included.

These summaries describe files inspected in the original private repositories. They do **not** claim that all exercises have passed fresh automated tests on this combined repository.

---

<sub>Previous: [`CPP08`](../CPP08/README.md) · Next: — · [GitHub profile](https://github.com/doooriian)</sub>
