#include <iostream>
using namespace std;

class node {
public:
    string data;
    node* next;
    node* prev;

    node() {
        data = 'x';
        next = nullptr;
        prev = nullptr;
    }

    node(string d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

class link_list {
public:
    node* head = NULL;

    void insert_at_start() {
        string text;
        cout<<"enter the text: ";
        cin>>text;
        node* nn = new node(text);
        if (head == nullptr) {
            head = nn;
            return;
        } else {
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
    }

    void insert_at_end() {
        string text;
        cout<<"enter the text to add at end: ";
        cin>>text;
        node* nn = new node(text);
        if (head == nullptr) {
            head = nn;
            return;
        } else {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nn;
            nn->prev = temp;
        }
    }

    void insert_at_between() {
        string text;
        cout<<"enter the text to add at between: ";
        cin>>text;
        string key;
        cout<<"enter the key element : "<<endl;
        cin>>key;
        node* nn = new node(text);
        if (head == nullptr) {
            head = nn;
            return;
        } else {
            node* temp = head;
            while (temp != nullptr && temp->data != key) {
                temp = temp->next;
            }
            if (temp != nullptr) {  
                nn->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = nn;
                }
                temp->next = nn;
                nn->prev = temp;
            } else {
                cout << "Key not found." << endl;
            }
        }
    }

    void delete_at_start() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        } else {
            node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
        }
    }

    void delete_at_end() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        } else {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            if (temp->prev != nullptr) {
                temp->prev->next = nullptr;
            } else {
                head = nullptr;  
            }
            delete temp;
        }
    }

    void delete_at_between() {
        string key1;
        cout << "Enter the song to delete: ";
       cin>>key1;
        node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key1) {
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;  
                }
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;  
            }
            temp = temp->next;
        }
        cout << "Key not found." << endl;
    }

    void print_in_reverse() {
        node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
       
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        cout << "In reverse order: ";
        while (temp->next!= nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void print() {
        cout << "Linked list is: ";
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<temp->data<< endl;
    }

    void search() {
        string key;
    cout << "Enter the song you want to play: ";
    cin >> key;
        node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "found  the text: " << key<< endl;
                return;
            }
            temp = temp->next;
        }
        cout<< " not found in the list." << endl;
    }
};

int main() {
    link_list l;
    int choice;
    do{
        cout<<"what you want to do "<<endl;
        cout<<"1 .insert the text\n2. delete the text\n3. print in reverse text\n4. search the text\n5. print the text\n6. exit\n";
        cout<<"enter the choice: ";
        cin>>choice;
        switch(choice){
        case 1:{
            int subChoice;
            do{
                 cout << "1. At Start\n2. At End\n3. Between\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;
                    switch (subChoice){
                        case 1:
                            l.insert_at_start();
                            break;
                        case 2:
                            l.insert_at_end();
                            break;
                        case 3:
                            l.insert_at_between();
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                            break;
                    } 
                       cout << "Enter 1 to continue or 0 to return to main menu: ";
                    cin >> subChoice;
            }while (subChoice == 1);
                break;
        }
         case 2: {
                int deleteChoice;
                do {
                    cout << "1. Delete at Start\n2. Delete at End\n3. Delete at Between\n";
                    cout << "Enter your choice: ";
                    cin >> deleteChoice;

                    switch (deleteChoice) {
                        case 1:
                            l.delete_at_start();
                            break;
                        case 2:
                            l.delete_at_end();
                            break;
                        case 3:
                            l.delete_at_between();
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                            break;
                    }
                    cout << "Enter 1 to continue or 0 to return to main menu: ";
                    cin >> deleteChoice;
                } while (deleteChoice == 1);
                break;
            } 
            case 3:
            l. print_in_reverse() ;
            break;
            case 4:
            l.search();
            break;
            case 5:
            l.print();
            break;
            case 6:
             cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
         cout << "Press 1 to continue or 0 to exit: ";
        cin >> choice;
    }while (choice == 1);

    return 0;
}
