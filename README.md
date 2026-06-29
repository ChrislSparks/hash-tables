# hash-tables

Implementation of a hash table using separate chaining for collision handling. This project demonstrates efficient key-value storage, retrieval, and deletion while maintaining average-case constant-time performance.

## Features

- Custom hash function
- Separate chaining using linked lists
- Insert key-value pairs
- Search for existing keys
- Remove key-value pairs
- Bucket visualization
- Load factor calculation

## Technologies

- C++
- Standard Template Library (STL)
- Vectors
- Lists
- Hashing

## Algorithms

| Operation | Average Case | Worst Case |
|-----------|:------------:|:----------:|
| Insert | O(1) | O(n) |
| Search | O(1) | O(n) |
| Delete | O(1) | O(n) |
| Hash Function | O(k) | O(k) |

*Where **k** is the length of the key.*

## Collision Handling

This implementation uses **Separate Chaining** to resolve hash collisions. Each bucket contains a linked list that stores all key-value pairs that hash to the same index. When multiple keys produce the same hash value, they are stored within the same bucket instead of overwriting one another.

## Example Output

```text
Hash Table

Bucket 0:
  (Apple, 15)

Bucket 1:
  Empty

Bucket 2:
  (Orange, 24)
  (Pear, 18)

Bucket 3:
  (Banana, 12)

Load Factor: 0.75

Searching for "Pear"...
Key Found

Removing "Orange"...

Updated Bucket 2:
  (Pear, 18)
```

## What I Learned

- Implemented a custom hash table using C++
- Applied hashing techniques for efficient key-value storage
- Resolved collisions using separate chaining
- Calculated and analyzed load factor
- Evaluated average- and worst-case time complexity
- Used STL vectors and linked lists to build efficient data structures
