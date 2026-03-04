/*
 * =============================================
 *  HASHING - Part 2: Separate Chaining
 * =============================================
 *
 * COLLISION HANDLING METHOD 1: Chaining
 *
 * Idea: Each slot in the hash table holds a
 *       Linked List. If multiple keys hash to
 *       the same index, they are chained together.
 *
 * Visual:
 *  Index 0: NULL
 *  Index 1: [22] -> NULL
 *  Index 2: NULL
 *  Index 3: [17] -> [10] -> NULL   <- both map to 3
 *  ...
 *
 * Time Complexity:
 *   Average: O(1) for insert/search/delete
 *   Worst:   O(n) if all keys hash to same slot
 * =============================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 7

// ---- Node for Linked List ----
struct Node {
    int data;
    struct Node* next;
};

// Hash Table: array of linked list head pointers
struct Node* hashTable[TABLE_SIZE];

// ---- Hash Function ----
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// ---- Initialize Table ----
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// ---- Insert ----
void insert(int key) {
    int index = hashFunction(key);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
        printf("Inserted %d at index %d\n", key, index);
    } else {
        // Insert at the beginning of the chain (O(1))
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
        printf("Inserted %d at index %d (chained)\n", key, index);
    }
}

// ---- Search ----
int search(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Found %d at hash index %d\n", key, index);
            return 1;
        }
        temp = temp->next;
    }

    printf("%d NOT found in the table\n", key);
    return 0;
}

// ---- Delete ----
void delete(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL)
                hashTable[index] = temp->next; // Remove head node
            else
                prev->next = temp->next;       // Bypass the node
            free(temp);
            printf("Deleted %d from index %d\n", key, index);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("%d not found. Cannot delete.\n", key);
}

// ---- Display Hash Table ----
void display() {
    printf("\n======= Hash Table (Chaining) =======\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index [%d]: ", i);
        struct Node* temp = hashTable[i];
        if (temp == NULL) {
            printf("NULL\n");
            continue;
        }
        while (temp != NULL) {
            printf("[%d]", temp->data);
            if (temp->next != NULL) printf(" -> ");
            temp = temp->next;
        }
        printf(" -> NULL\n");
    }
    printf("=====================================\n");
}

// ---- Free All Memory ----
void freeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
        hashTable[i] = NULL;
    }
}

int main() {
    initTable();

    printf("=== Separate Chaining Demo ===\n\n");

    printf("--- Inserting Elements ---\n");
    insert(10);   // index = 10 % 7 = 3
    insert(17);   // index = 17 % 7 = 3 -> CHAIN with 10
    insert(22);   // index = 22 % 7 = 1
    insert(44);   // index = 44 % 7 = 2
    insert(3);    // index = 3  % 7 = 3 -> CHAIN with 10, 17
    insert(15);   // index = 15 % 7 = 1 -> CHAIN with 22
    insert(0);    // index = 0  % 7 = 0

    display();

    printf("\n--- Searching Elements ---\n");
    search(17);
    search(44);
    search(99);   // Not present

    printf("\n--- Deleting Elements ---\n");
    delete(17);   // Delete middle of chain
    delete(99);   // Not in table

    display();    // Show table after deletion

    freeTable();
    return 0;
}

/*
 * HOW CHAINING WORKS AT INDEX 3:
 *
 *  After inserting 10, 17, 3:
 *  Index [3]: [3] -> [17] -> [10] -> NULL
 *
 *  Search for 17:
 *   1. hash(17) = 3 -> go to index 3
 *   2. Walk chain: [3] != 17 -> [17] == 17 -> FOUND!
 *
 *  KEY ADVANTAGE:  No entry limit, handles many collisions
 *  KEY DISADVANTAGE: Extra memory for next pointers
 */
