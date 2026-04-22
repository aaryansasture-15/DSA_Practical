#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Inserted at beginning: " << value << endl;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
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
        delete temp;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == NULL) {
            cout << "Deleted: " << head->data << endl;
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        cout << "Deleted: " << temp->next->data << endl;
        delete temp->next;
        temp->next = NULL;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "List elements: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList sll;
    int choice, value;

    do {
        cout << "\n--- Singly Linked List Menu ---";
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
                sll.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                sll.insertAtEnd(value);
                break;

            case 3:
                sll.deleteAtBeginning();
                break;

            case 4:
                sll.deleteAtEnd();
                break;

            case 5:
                sll.display();
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