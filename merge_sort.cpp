#include <iostream>
#include <vector>
// codigo por su puesto no gpeteado

using namespace std;

struct Node {
    int data;
    Node* next; 

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    
    LinkedList() : head(nullptr) {}  // Initialize empty list

    // Insert a node at the end of the list
    void insert_last(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void printList() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Static function to get the middle of the list
    static Node* getMiddle(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* fast = head; // ->next->next
        Node* slow = head; // ->next

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

Node* merge(Node* left, Node* right) {
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }

    Node* result = nullptr;

    // Compare the data to decide the merge order
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

<<<<<<< HEAD
Node* mergeSort(){
    
=======
Node* mergeSort(Node* head) {
    // Base case: If head is NULL or only one element in the list
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Find the middle of the list
    Node* middle = LinkedList::getMiddle(head);
    
    // Split the list into two halves
    Node* secondHalf = middle->next;
    middle->next = nullptr; // Break the list into two halves

    // Recursively sort both halves
    Node* left = mergeSort(head);
    Node* right = mergeSort(secondHalf);

    // Merge the sorted halves
    return merge(left, right);
>>>>>>> 6b7b3345e7da0b88025e8ebf68190c661d9881db
}

int main() {
    LinkedList list;

    // Insert elements into the linked list
    list.insert_last(21);
    list.insert_last(11);
    list.insert_last(13);
    list.insert_last(5);
    list.insert_last(6);
    list.insert_last(7);

    // Print original list
    cout << "Original List:" << endl;
    list.printList();

    // Sort the list using mergeSort
    list.head = mergeSort(list.head);

    // Print sorted list
    cout << "Sorted List:" << endl;
    list.printList();

    return 0;
}
