## 🇮🇹 ITALIANO

# 🧮 Push_swap - 42 School Project

`push_swap` è un progetto della Scuola 42 che consiste nell'ordinare una pila di numeri interi usando un set limitato di operazioni e il minor numero possibile di mosse. L'output è una sequenza di istruzioni che, se eseguite da un programma checker, portano allo stack ordinato.

---

## 📦 Obiettivo

Scrivere un programma che, dato uno stack `A` con numeri interi disordinati, ordini i numeri usando unicamente stack `A` e `B`, e le seguenti operazioni:

- `sa`, `sb`, `ss` – swap
- `pa`, `pb` – push
- `ra`, `rb`, `rr` – rotate
- `rra`, `rrb`, `rrr` – reverse rotate

---

## ⚙️ Implementazione

La mia strategia di ordinamento si basa su due fasi principali:

### 1. 📈 Longest Increasing Subsequence (LIS)
- Identifico la **sottosequenza crescente più lunga** nello stack A.
- I numeri appartenenti alla LIS vengono **mantenuti nello stack A**.
- Gli altri elementi vengono **spostati nello stack B**, in modo da ridurre il numero di elementi da reinserire.

### 2. 🔁 Calcolo dei costi dinamici
- Per ogni elemento nello stack B, calcolo dinamicamente il **costo minimo** necessario per reinserirlo nella posizione corretta nello stack A.
- I costi sono calcolati considerando:
  - le rotazioni necessarie per allineare `A` e `B`
  - l'ottimizzazione di `rr` / `rrr` quando possibile
- L’elemento con il **costo più basso** viene reinserito per primo.
- Lo stack A viene aggiornato ad ogni inserimento, e i costi vengono **ricalcolati in tempo reale**.

---

## 🛠️ Compilazione
- $ `make`
- $ `./push_swap 3 2 1 6 5 8 7 4`
- $ `make fclean`

## 🇬🇧 English

# 🧮 Push_swap - 42 School Project

`push_swap` is a project from 42 School that consists of sorting a stack of integers using a limited set of operations and the fewest possible moves. The output is a sequence of instructions that, if executed by a checker program, result in a sorted stack.

---

## 📦 Goal

Write a program that, given a stack `A` with unsorted integers, sorts the numbers using only stack `A` and `B`, and the following operations:

- `sa`, `sb`, `ss` – swap
- `pa`, `pb` – push
- `ra`, `rb`, `rr` – rotate
- `rra`, `rrb`, `rrr` – reverse rotate

---

## ⚙️ Implementation

My sorting strategy is based on two main phases:

### 1. 📈 Longest Increasing Subsequence (LIS)
- I identify the **longest increasing subsequence** in stack A.
- The numbers belonging to the LIS are **kept in stack A**.
- The other elements are **moved to stack B**, to reduce the number of elements to reinsert.

### 2. 🔁 Dynamic cost calculation
- For each element in stack B, I dynamically calculate the **minimum cost** needed to reinsert it into the correct position in stack A.
- Costs are calculated by considering:
  - the rotations needed to align `A` and `B`
  - optimization using `rr` / `rrr` when possible
- The element with the **lowest cost** is reinserted first.
- Stack A is updated after each insertion, and costs are **recalculated in real time**.

---

## 🛠️ Compilation
- $ `make`
- $ `./push_swap 3 2 1 6 5 8 7 4`
- $ `make fclean`
