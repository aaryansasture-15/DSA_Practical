#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
        cout << "Inserted at beginning: " << value << endl;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }

        cout << "Inserted at end: " << value << endl;
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "Deleted: " << temp->data << endl;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        if (head->next == NULL) {
            cout << "Deleted: " << temp->data << endl;
            delete temp;
            head = NULL;
            return;
        }

        while (temp->next != NULL) {
            temp = temp->next;
        }

        cout << "Deleted: " << temp->data << endl;
        temp->prev->next = NULL;
        delete temp;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "List elements: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value;

    do {
        cout << "\n--- Doubly Linked List Menu ---";
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Delete at Beginning";
        cout << "\n4. Delete at End";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtEnd(value);
                break;

            case 3:
                dll.deleteAtBeginning();
                break;

            case 4:
                dll.deleteAtEnd();
                break;

            case 5:
                dll.display();
                break;

            case 6:
                cout << "Program Ended\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 6);

    return 0;
}