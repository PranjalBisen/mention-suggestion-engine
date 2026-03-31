# Mention Suggestion Engine (Trie based)

Built this as a simple implementation of how @mentions / username suggestions work in real platforms.

The idea is to use a Trie so that given a prefix (like "pra"), we can quickly fetch all matching usernames.

---

## What it does

* Insert usernames
* Check if a username exists
* Get all usernames starting with a prefix
* Lazy delete (mark user as deleted instead of removing from memory, basically soft-delete)

---

## Example

Input usernames:

```
pranjal, pranju, pranjalayyaaaa, pranjjjuuuu, bisen
```

Query:

```
prefix = "pra"
```

Output:

```
pranjal pranjalayyaaaa pranjjjuuuu pranju
```

After deleting "pranju":

```
pranjal pranjalayyaaaa pranjjjuuuu
```

---

## Core Idea

Using Trie:

* Each character is a node
* Prefix traversal is fast → O(length)
* DFS gives all matching usernames

---

## Time Complexity

* Insert: O(L)
* Search: O(L)
* Prefix search: O(L + K)

(L = length of string, K = number of results)

---

## Why I made this

Was practicing Trie but wanted something practical instead of just textbook problems.

---

## How to run

```bash
g++ c.cpp -o trie
./trie
```

---
