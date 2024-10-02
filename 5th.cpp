#include <iostream>
using namespace std;

class Node {
public:
    string route;
    Node* next;

    Node(string r) {
        route = r;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head = nullptr;

    void addRoute() {
        string routeName;
        cout << "Enter the route name: ";
        cin >> routeName;
        Node* newNode = new Node(routeName);
        
        if (head == nullptr) {
            head = newNode;
            head->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Route added: " << routeName << endl;
    }

    void removeRoute() {
        if (head == nullptr) {
            cout << "No routes to remove." << endl;
            return;
        }

        string routeName;
        cout << "Enter the route name to remove: ";
        cin >> routeName;

        Node* current = head;
        Node* previous = nullptr;

        do {
            if (current->route == routeName) {
                if (previous) {
                    previous->next = current->next;
                    if (current == head) {
                        head = current->next; 
                    }
                } else { 
                    if (current->next == head) {
                        head = nullptr; 
                    } else {
                        Node* temp = head;
                        while (temp->next != head) {
                            temp = temp->next;
                        }
                        temp->next = current->next;
                        head = current->next;
                    }
                }
                delete current;
                cout << "Route removed: " << routeName << endl;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);

        cout << "Route not found: " << routeName << endl;
    }

    void displayRoutes() const {
        if (!head) {
            cout << "No routes available." << endl;
            return;
        }

        Node* temp = head;
        cout << "Routes: ";
        do {
            cout << temp->route << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    
};

int main() {
    CircularLinkedList routes;
    int choice;

    do {
        cout << "What would you like to do?" << endl;
        cout << "1. Add Route\n2. Remove Route\n3. Display Routes\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                routes.addRoute();
                break;
            case 2:
                routes.removeRoute();
                break;
            case 3:
                routes.displayRoutes();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        cout << "Press 1 to continue or 0 to exit: ";
        cin >> choice;
    } while (choice == 1);

    return 0;
}
