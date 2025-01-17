// write a function reverses a singly linked list in placxe and returns the reverse list additionaly implement a function to detect if linked list has a loop and remove loop if present you must handle the both reversal and cycle detection in 0(n) in time complexity constraints:o not use any additional data structure like arrays or hash sets 

#include <iostream>
using namespace std;

// Define a structure for a Node in the linked list
struct Node {
    int data;    // Data part of the Node
    Node* next;  // Pointer to the next Node
};

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node *prev = NULL, *current = head, *next = NULL;

    // Traverse the list and reverse the links between nodes
    while (current) {
        next = current->next;   // Save the next node
        current->next = prev;   // Reverse the current node's link
        prev = current;         // Move the prev pointer forward
        current = next;         // Move the current pointer forward
    }
    return prev;  // The prev pointer will now be the new head
}

// Function to detect if a linked list contains a loop
bool detectLoop(Node* head) {
    Node *slow = head, *fast = head;

    // Use two pointers: slow moves one step, fast moves two steps
    while (fast && fast->next) {
        slow = slow->next;          // Move slow pointer one step
        fast = fast->next->next;    // Move fast pointer two steps

        if (slow == fast) {         // If they meet, there's a loop
            return true;
        }
    }
    return false;  // No loop found
}

// Function to remove a loop in the linked list
void removeLoop(Node* head) {
    Node *slow = head, *fast = head;

    // Detect the loop using two pointers
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {  // Loop detected
            slow = head;  // Move one pointer to the head

            // Find the starting point of the loop
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }

            fast->next = NULL;  // Break the loop by setting the link to NULL
            return;
        }
    }
}

// Function to print the elements of a linked list
void printList(Node* head) {
    while (head) {  // Traverse the list until the end (NULL)
        cout << head->data << " ";  // Print each node's data
        head = head->next;          // Move to the next node
    }
    cout << endl;  // End the line after printing the list
}

// Main function to demonstrate the linked list operations
int main() {
    // Create nodes manually
    Node* head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->next = new Node();
    head->next->next->next->data = 4;
    head->next->next->next->next = NULL;

    // Create a loop (4 -> 2)
    head->next->next->next->next = head->next;

    // Detect and remove loop if present
    if (detectLoop(head)) {
        cout << "Loop detected. Removing loop...\n";
        removeLoop(head);
    }

    // Print the list after removing the loop
    cout << "List after loop removal: ";
    printList(head);

    // Reverse the list
    head = reverseList(head);
    cout << "Reversed List: ";
    printList(head);

    return 0;
}