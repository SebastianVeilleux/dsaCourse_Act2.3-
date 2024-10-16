/*#include <iostream>
using namespace std;
// Codigo para nada hecho por GPT

// g++ -std=c++17 merge_sort.cpp && ./a.out

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};


Node* split(Node* head) {
    Node* fast = head;
    Node* slow = head;

    
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        if (fast != nullptr) {
            slow = slow->next;
        }
    }

    // desconecta la lista
    Node* temp = slow->next;
    slow->next = nullptr;
    return temp;
}

// Function to merge two sorted singly linked lists
Node* merge(Node* first, Node* second) {
    // If either list is empty, return the other list
    if (first == nullptr) return second;
    if (second == nullptr) return first;

    // Pick the smaller value between first and second nodes
    if (first->data < second->data) {
        // Recursively merge the rest of the lists and link the result to the current node
        first->next = merge(first->next, second);
        return first;
    } else {
        // Recursively merge the rest of the lists and link the result to the current node
        second->next = merge(first, second->next);
        return second;
    }
}

// Function to perform merge sort on a singly linked list
Node* MergeSort(Node* head) {
    // Base case: if the list is empty or has only one node, it's already sorted
    if (head == nullptr || head->next == nullptr)
        return head;

    // Split the list into two halves
    Node* second = split(head);

    // Recursively sort each half
    head = MergeSort(head);
    second = MergeSort(second);

    // Merge the two sorted halves
    return merge(head, second);
}

<<<<<<< HEAD
int main() {
    LinkedList list;

    // Insert nodes into the linked list
    list.insert_last(9999);
    list.insert_last(1000);
    list.insert_last(1000);
    list.insert_last(2000);

    cout << "Original List:" << endl;
    list.printList();

    // Sort the list using MergeSort
    list.head = MergeSort(list.head);

    cout << "Sorted List:" << endl;
    list.printList();

    return 0;
}*/