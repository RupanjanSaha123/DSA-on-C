/*
 * ===========================================================================
 *                      MODULE 4 - HASHING : CONCEPTS SUMMARY
 * ===========================================================================
 *
 *  WHAT IS HASHING?
 *  ----------------
 *  A technique to map a KEY to an INDEX in an array (called Hash Table)
 *  using a HASH FUNCTION, allowing near O(1) insert, search, and delete.
 *
 *  Formula:   index = hashFunction(key)
 *  Common:    index = key % tableSize
 *
 * ===========================================================================
 *  1. HASH FUNCTION
 * ===========================================================================
 *
 *  Property         Description
 *  ---------------  ---------------------------------------------------------
 *  Deterministic    Same key always gives same index
 *  Fast             O(1) computation
 *  Uniform          Distributes keys evenly across the table
 *  Minimize         Produces as few collisions as possible
 *
 *  Types:
 *  ------
 *  a) Modulo Division   : h(k) = k % m              (most common)
 *  b) Multiplication    : h(k) = floor(m * (k*A%1)) (A ~ 0.618)
 *  c) djb2 (strings)   : hash = hash*33 + char      (good for strings)
 *
 * ===========================================================================
 *  2. COLLISION
 * ===========================================================================
 *
 *  A COLLISION occurs when two different keys produce the same hash index.
 *
 *  Example:   h(10) = 10 % 7 = 3
 *             h(17) = 17 % 7 = 3   <- COLLISION!
 *
 * ===========================================================================
 *  3. COLLISION RESOLUTION METHODS
 * ===========================================================================
 *
 *  +--------------------+-------------------------------+--------------------+
 *  | Method             | How It Works                  | Data Structure     |
 *  +--------------------+-------------------------------+--------------------+
 *  | Separate Chaining  | Each slot holds a linked list | Linked List        |
 *  | Linear Probing     | Probe: (h+i) % m              | Array              |
 *  | Quadratic Probing  | Probe: (h+i^2) % m            | Array              |
 *  | Double Hashing     | Probe: (h + i*h2(k)) % m      | Array              |
 *  +--------------------+-------------------------------+--------------------+
 *
 *  3a. SEPARATE CHAINING
 *  ----------------------
 *  - Each index stores the HEAD of a linked list
 *  - Colliding keys are appended to that list
 *  - Pros: Simple, no table size limit
 *  - Cons: Extra memory for pointers
 *  - File: Hashing/02_chaining.c
 *
 *  Visual:
 *    Index [3]: [17] -> [10] -> NULL
 *    Index [1]: [22] -> NULL
 *
 *  3b. LINEAR PROBING (Open Addressing)
 *  --------------------------------------
 *  - All keys stored inside the array itself
 *  - On collision, check the NEXT slot: (h + i) % m
 *  - Uses a TOMBSTONE (DELETED marker) for safe deletion
 *  - Pros: Cache-friendly, no extra pointers
 *  - Cons: Clustering (long chains of filled slots)
 *  - File: Hashing/03_linear_probing.c
 *
 *  Visual after inserting 10, 17 (both hash to index 3):
 *    Index [3]: 10
 *    Index [4]: 17   <- probed from 3.
 *
 * ===========================================================================
 *  4. LOAD FACTOR
 * ===========================================================================
 *
 *  Load Factor (lambda) = (Number of elements) / (Table size)
 *
 *  +--------------------+-------------------+
 *  | Load Factor        | Performance        |
 *  +--------------------+-------------------+
 *  | lambda < 0.5       | Excellent          |
 *  | 0.5 <= lambda < 0.7| Good               |
 *  | lambda >= 0.7      | Rehashing needed!  |
 *  +--------------------+-------------------+
 *
 *  REHASHING: When load factor is too high, create a new (larger) table
 *             and re-insert all existing keys.
 *
 * ===========================================================================
 *  5. TIME & SPACE COMPLEXITY
 * ===========================================================================
 *
 *  +-------------------+-----------+-----------+
 *  | Operation         | Average   | Worst     |
 *  +-------------------+-----------+-----------+
 *  | Insert            | O(1)      | O(n)      |
 *  | Search            | O(1)      | O(n)      |
 *  | Delete            | O(1)      | O(n)      |
 *  +-------------------+-----------+-----------+
 *  | Space (table)     | O(n)      | O(n)      |
 *  +-------------------+-----------+-----------+
 *
 *  Worst case O(n) occurs when ALL keys hash to the same index.
 *
 * ===========================================================================
 *  6. CHAINING vs LINEAR PROBING COMPARISON
 * ===========================================================================
 *
 *  +----------------------+----------------------+----------------------+
 *  | Feature              | Chaining             | Linear Probing       |
 *  +----------------------+----------------------+----------------------+
 *  | Storage              | Outside (linked list)| Inside (array)       |
 *  | Load Factor Limit    | Can exceed 1.0       | Must stay < 1.0      |
 *  | Memory               | Extra for pointers   | No extra memory      |
 *  | Cache Performance    | Poor (pointer chase) | Good (array access)  |
 *  | Deletion             | Simple (unlink node) | Tombstone needed     |
 *  | Clustering           | Not an issue         | Can occur            |
 *  | Best for             | Many collisions      | Low to mid load      |
 *  +----------------------+----------------------+----------------------+
 *
 * ===========================================================================
 *  7. STRING HASHING
 * ===========================================================================
 *
 *  For string keys, use djb2 algorithm:
 *
 *    hash = 5381;
 *    for each character c:
 *        hash = hash * 33 + c;
 *    return hash % tableSize;
 *
 *  Why NOT use simple ASCII sum?
 *    "abc" and "bca" -> same sum -> same hash  (BAD!)
 *    djb2 is position-sensitive -> different hashes (GOOD!)
 *
 *  File: Hashing/04_string_hashing.c
 *
 * ===========================================================================
 *  8. REAL-WORLD USE CASES
 * ===========================================================================
 *
 *  +---------------------------+-------------------------------------------+
 *  | Use Case                  | Example                                   |
 *  +---------------------------+-------------------------------------------+
 *  | Phone Directory           | Name -> Phone Number                      |
 *  | Password Storage          | Store hashed passwords (SHA-256 etc.)     |
 *  | Database Indexing         | Fast record lookup by key                 |
 *  | Caching                   | URL -> Cached response                    |
 *  | Frequency Count           | Word -> Count in a document               |
 *  | Compiler Symbol Tables    | Variable name -> Memory address           |
 *  | Spell Checkers            | Dictionary word lookup                    |
 *  | Cryptography              | MD5, SHA-256 (one-way hash functions)     |
 *  +---------------------------+-------------------------------------------+
 *
 * ===========================================================================
 *  9. FILES IN THIS MODULE
 * ===========================================================================
 *
 *  Hashing/01_hash_function_basics.c  -> Hash function + collision intro
 *  Hashing/02_chaining.c              -> Separate chaining (linked list)
 *  Hashing/03_linear_probing.c        -> Open addressing (linear probing)
 *  Hashing/04_string_hashing.c        -> djb2 string hashing + phone book
 *
 * ===========================================================================
 */
