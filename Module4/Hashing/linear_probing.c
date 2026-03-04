/*
 * =============================================
 *  HASHING - Part 3: Open Addressing
 *              (Linear Probing)
 * =============================================
 *
 * COLLISION HANDLING METHOD 2: Open Addressing
 *
 * Idea: All keys stored INSIDE the hash table itself.
 *       If a slot is taken, PROBE (look at) next slot.
 *
 * Linear Probing Formula:
 *   index = (hash(key) + i) % tableSize
 *   where i = 0, 1, 2, 3, ... (probe step)
 *
 * Example (tableSize = 7):
 *   Insert 10 -> 10 % 7 = 3 (empty, store here)
 *   Insert 17 -> 17 % 7 = 3 (TAKEN! try 4) -> store at 4
 *   Insert 24 -> 24 % 7 = 3 (TAKEN! try 4, TAKEN! try 5)
 *
 * Problem: CLUSTERING - consecutive filled slots slow down probing
 * =============================================
 */

#include <stdio.h>
#define TABLE_SIZE 7

#define EMPTY   -1
#define DELETED -2    // Tombstone marker for deleted slots

int hashTable[TABLE_SIZE];

// ---- Hash Function ----
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// ---- Initialize Table ----
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// ---- Insert (Linear Probing) ----
void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;
    int probeCount = 0;

    // Probe until we find an empty or deleted slot
    while (hashTable[index] != EMPTY && hashTable[index] != DELETED) {
        printf("  Collision at index %d! Probing next...\n", index);
        index = (index + 1) % TABLE_SIZE;
        probeCount++;

        if (index == startIndex) {
            printf("Hash table is FULL! Cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d", key, index);
    if (probeCount > 0)
        printf(" (after %d probe(s))", probeCount);
    printf("\n");
}

// ---- Search (Linear Probing) ----
int search(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            printf("Found %d at index %d\n", key, index);
            return index;
        }
        // DELETED tombstone slots must be skipped, not treated as EMPTY
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) break;
    }

    printf("%d NOT found in the table\n", key);
    return -1;
}

// ---- Delete (Lazy Deletion using Tombstone) ----
void delete(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            hashTable[index] = DELETED;  // Mark as tombstone
            printf("Deleted %d from index %d (marked as DELETED tombstone)\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) break;
    }

    printf("%d not found. Cannot delete.\n", key);
}

// ---- Display Table ----
void display() {
    printf("\n====== Hash Table (Linear Probing) ======\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("Index [%d]: EMPTY\n", i);
        else if (hashTable[i] == DELETED)
            printf("Index [%d]: DELETED (tombstone)\n", i);
        else
            printf("Index [%d]: %d\n", i, hashTable[i]);
    }
    printf("=========================================\n");
}

// ---- Load Factor ----
void loadFactor() {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != EMPTY && hashTable[i] != DELETED)
            count++;
    }
    printf("\nLoad Factor = %d / %d = %.2f\n", count, TABLE_SIZE,
           (float)count / TABLE_SIZE);
    if ((float)count / TABLE_SIZE > 0.7)
        printf("WARNING: Load factor > 0.7, consider resizing the table!\n");
    else
        printf("Load factor is healthy (below 0.7)\n");
}

int main() {
    initTable();

    printf("=== Linear Probing Demo ===\n\n");

    printf("--- Inserting Elements ---\n");
    insert(10);   // 10 % 7 = 3
    insert(17);   // 17 % 7 = 3 -> COLLISION -> probes -> index 4
    insert(22);   // 22 % 7 = 1
    insert(24);   // 24 % 7 = 3 -> COLLISION -> 4 taken -> index 5
    insert(43);   // 43 % 7 = 1 -> COLLISION -> probes -> index 2

    display();
    loadFactor();

    printf("\n--- Searching Elements ---\n");
    search(17);   // Found at index 4
    search(24);   // Found at index 5
    search(99);   // Not present

    printf("\n--- Deleting Elements ---\n");
    delete(17);   // Marks index 4 as tombstone (DELETED)

    display();

    printf("\n--- Search after Deletion ---\n");
    search(24);   // Still found (DELETED tombstone is skipped)
    search(17);   // Correctly says NOT found

    return 0;
}

/*
 * WHY TOMBSTONES (DELETED markers) ARE NECESSARY:
 * -------------------------------------------------
 * If we mark deleted slots as EMPTY:
 *
 *   Insert 10 -> index 3
 *   Insert 17 -> index 4 (probed from 3)
 *   Delete 10 -> index 3 = EMPTY
 *   Search 17 -> hash=3, slot[3]=EMPTY -> STOPS -> "Not found"! WRONG!
 *
 * Fix: use DELETED tombstone so search skips it and continues probing.
 * A tombstone says: "something was here, keep looking further."
 */
