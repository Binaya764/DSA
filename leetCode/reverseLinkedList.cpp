#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

// Function to reverse a LL
Node* reverseLL(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev forward
        current = next;       // Move current forward
    }
    
    return prev; //prev becomes the new head
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original: ";
    printList(head);
    head = reverseLL(head);

    cout << "Reversed: ";
    printList(head);

    return 0;
}