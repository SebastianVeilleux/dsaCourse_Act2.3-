#include <iostream>
#include <vector>

//g++ -std=c++17 merge_sort.cpp && ./a.out

using namespace std;

struct Node{
    int data;
    Node* next; 

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedList{
    public: 

    Node* head; // Deberia ser privado pero para fines de la tarea lo dejaremos publico
    LinkedList() : head(nullptr){} // inicialilzar lista vacia

    // Insertar al final de la lista
    void insert_last(int data){
        Node* newNode = new Node(data);

        if(head == nullptr){ // si la lista esta vacia asignar a head el nuevo nodo
            head = newNode;
        }else{
            // Recorrer lista para encontrar el ultimo nodo
            Node* current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }

    }

    void printList() {
        Node* current = head;

        while(current->next != nullptr){
            cout << current->data << " " << endl;
        }
    }

    // this idea was taken from https://medium.com/@arifimran5/fast-and-slow-pointer-pattern-in-linked-list-43647869ac99
    Node* getMiddle(Node* head){
        if(head == nullptr){
            return nullptr;
        }

        Node* fast = head;
        Node* slow = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

};

Node* merge(){

}

Node* mergeSort(){

}

int main(){

    return 0;
}
