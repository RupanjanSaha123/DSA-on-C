1.*Code to Create a Node (Using malloc)*

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *newNode;

    // Allocate memory for one node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation is successful
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Assign data and initialize next pointer
    newNode->data = 10;
    newNode->next = NULL;

    printf("Node created successfully\n");
    printf("Data = %d\n", newNode->data);

    return 0;
}

OUTPUT:
Node created successfully
Data = 10

🔹 Creating a Singly Linked List in C

✅ What this program does:
Creates multiple nodes
Links them using next
Displays the list

#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        // Create a new node
        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        // Linking nodes
        if (head == NULL) {
            head = newNode;   // first node
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Display the linked list
    printf("\nSingly Linked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

OUTPUT:
Enter number of nodes: 3
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30

Singly Linked List: 10 -> 20 -> 30 -> NULL
