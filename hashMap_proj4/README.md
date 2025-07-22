# HashMap Project 4 — DNA Hash Table Implementation

## Overview
This project implements a **custom hash table-based DNA database** in modern C++.  
It focuses on efficient storage, retrieval, and deletion of DNA records using open addressing and dynamic resizing strategies.  
Designed with performance and reliability in mind, it models real-world data handling scenarios where collisions and memory constraints are critical factors.

---

## Key Features
- **Custom `DNA` Class** with unique sequence and location tracking.
- **Hash Table with Linear Probing** for collision resolution.
- **Automatic Rehashing** when load factor exceeds 0.7 or deletion ratio grows.
- **Prime-Based Capacity Sizing** to optimize hash distribution.
- **Pluggable Hash Function** using function injection.
- **Comprehensive Test Harness** with randomized data generation and operation validation.
- **Detailed Dump Utility** to inspect internal hash table states.

---

## Technical Highlights
- Written in **modern C++** leveraging `std::vector`, `std::function`, and random distributions.
- Implements **open addressing** with deleted marker handling to maintain probe chains.
- **Prime number utility** ensures efficient resizing during rehashes.
- Includes a custom **random number generator (RNG) class** for controlled testing.
- Simulates real-world usage with randomized DNA entries and rigorous validity checks.

---

## Project Structure
```
hashMap_proj4/
├── dnadb.cpp    // Hash table implementation
├── dnadb.h      // Class declarations and configuration constants
├── mytest.cpp   // Test harness with randomized input and full operation tests
├── README.md    // (You're reading this)
```

---

## How to Run
1. **Compile:**
   ```bash
   g++ -std=c++11 dnadb.cpp mytest.cpp -o dnadb_test
   ```

2. **Run:**
   ```bash
   ./dnadb_test
   ```

3. **Expected Output:**
   - Initial empty table dump
   - DNA insertions with success/fail status
   - Post-insertion table state
   - Validation of inserted DNA records
   - Removals of records and final table state

---

## Example Use Case
This project can serve as:
- A learning tool for understanding **hash table mechanics**.
- A performance benchmark for **collision resolution strategies**.
- A foundation for extending into **DNA sequence analysis applications**.

---

## What's Next?
- Implement quadratic probing or double hashing.
- Integrate with persistent storage for larger datasets.
- Explore mutation simulation and pattern matching within stored DNA sequences.
- Add performance benchmarks against STL's `unordered_map`.

---

## Author
**Aminkeng Nkeng**  
📍 Maryland, USA  
💬 Open to software engineering roles in systems design, data structures, and performance optimization.  

---

## License
This project is open for learning and demonstration purposes.  
Feel free to fork, modify, and explore.


