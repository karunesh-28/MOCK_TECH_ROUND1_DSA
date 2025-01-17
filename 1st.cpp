// write a function reverses a singly linked list in placxe and returns the reverse list additionaly implement a function to detect if linked list has a loop and remove loop if present you must handle the both reversal and cycle detection in 0(n) in time complexity constraints:o not use any additional data structure like arrays or hash sets 

#include <iostream>
using namespace std;

// Define a structure for a Node in the linked list
struct Node {
    int data;    // Data part of the Node
    Node* next;  // Pointer to the next Node
};

Node* reverseList(Node* head) {
    Node *prev = NULL, *current = head, *next = NULL;

    
    while (current) {
        next = current->next;   
        current->next = prev;   
        prev = current;         
        current = next;        
    }
    return prev;  

bool detectLoop(Node* head) {
    Node *slow = head, *fast = head;

    
    while (fast && fast->next) {
        slow = slow->next;       
        fast = fast->next->next;  

        if (slow == fast) {       
            return true;
        }
    }
    return false;
}


void removeLoop(Node* head) {
    Node *slow = head, *fast = head;

   
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {  
            slow = head;  

           
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }

            fast->next = NULL;
            return;
        }
    }
}


void printList(Node* head) {
    while (head) {  
        cout << head->data << " ";
        head = head->next;        
    }
    cout << endl; 
}

int main() {

    Node* head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->next = new Node();
    head->next->next->next->data = 4;
    head->next->next->next->next = NULL;


    head->next->next->next->next = head->next;


    if (detectLoop(head)) {
        cout << "Loop detected. Removing loop...\n";
        removeLoop(head);
    }

    cout << "List after loop removal: ";
    printList(head);


    head = reverseList(head);
    cout << "Reversed List: ";
    printList(head);

    return 0;
}
