/*
 * =============================================
 *  HASHING - Part 1: Hash Function Basics
 * =============================================
 *
 * A Hash Function converts a key into an index
 * in the hash table using a mathematical formula.
 *
 * Most common: h(key) = key % tableSize
 *
 * Good hash functions should:
 *   - Be fast to compute
 *   - Minimize collisions
 *   - Distribute keys uniformly
 * =============================================
 */

#include <stdio.h>

#define TABLE_SIZE 7

// Basic modulo hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Simple hash table using array (no collision handling yet)
int hashTable[TABLE_SIZE];

// Initialize the table with -1 (meaning empty)
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Insert (only works if no collision)
void insert(int key) {
    int index = hashFunction(key);
    if (hashTable[index] == -1) {
        hashTable[index] = key;
        printf("Inserted %d at index %d\n", key, index);
    } else {
        printf("Collision! Index %d already has %d. Cannot insert %d\n",
               index, hashTable[index], key);
    }
}

// Search
void search(int key) {
    int index = hashFunction(key);
    if (hashTable[index] == key) {
        printf("Found %d at index %d\n", key, index);
    } else {
        printf("%d NOT found in hash table\n", key);
    }
}

// Display the full hash table
void display() {
    printf("\n----- Hash Table -----\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1)
            printf("Index [%d]: EMPTY\n", i);
        else
            printf("Index [%d]: %d\n", i, hashTable[i]);
    }
    printf("----------------------\n");
}

int main() {
    initTable();

    printf("=== Hash Function Basics ===\n\n");

    // Demonstrate hash index calculation first
    printf("--- Hash Index Calculation (key %% %d) ---\n", TABLE_SIZE);
    int keys[] = {10, 22, 31, 4, 15, 28, 17};
    for (int i = 0; i < 7; i++) {
        printf("hashFunction(%d) = %d %% %d = %d\n",
               keys[i], keys[i], TABLE_SIZE, hashFunction(keys[i]));
    }

    printf("\n--- Inserting Values ---\n");
    insert(10);
    insert(22);
    insert(31);
    insert(4);
    insert(15);
    insert(28);
    insert(17); // Collision: 17 % 7 = 3, same as 10

    display();

    printf("\n--- Searching Values ---\n");
    search(22);
    search(99); // Not in table

    return 0;
}

/*
 * LESSON:
 * Without collision handling, our table breaks when
 * two keys produce the same index.
 *
 * Solutions:
 *   -> See 02_chaining.c       (Separate Chaining)
 *   -> See 03_linear_probing.c (Open Addressing)
 */
