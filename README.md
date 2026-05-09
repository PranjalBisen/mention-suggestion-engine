# Mention Suggestion Engine (Trie based)

Built this as a simple implementation of how @mentions / username suggestions work in real platforms.

The idea is to use a Trie so that given a prefix (like "pra"), we can quickly fetch all matching usernames.

---

## How it works

We store all usernames in a Trie (prefix tree).

* While inserting, each character goes into a node level by level
* For searching a prefix, we first traverse the Trie till that prefix
* If prefix exists, we start a DFS from that node to collect all possible usernames

Also added lazy delete:

* Instead of removing nodes, we just mark a username as deleted
* While returning results, we ignore the deleted ones

This keeps the implementation simple and avoids complex memory handling.

---

## What it does

* Insert usernames
* Check if a username exists
* Get all usernames starting with a prefix
* Lazy delete (mark user as deleted instead of removing from memory, basically soft-delete)

---

## Time Complexity

* Insert: O(N)
* Search: O(N)
* Prefix search: O(N + K)

(N = length of string, K = number of results)

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

## Why I made this

Was practicing Trie but wanted something practical instead of just textbook problems.

---

## How to run

```bash
g++ c.cpp -o trie
./trie
```

---
