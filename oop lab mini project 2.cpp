#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;
class Student {
public:
    string name;
    string address;
    string contact;
    int id;
    Student() {
        name = "";
        address = "";
        contact = "";
        id = -1;
    }
    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << contact << endl;
    }
};
Student directory[MAX];
int count = 0;
bool checkIdExists(int id) {
    for (int i = 0; i < count; i++) {
        if (directory[i].id == id) {
            return true;
        }
    }
    return false;
}
void insertStudent() {
    while (true) {
        int id;
        string name, address, contact;
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        if (checkIdExists(id)) {
            cout << "The ID already exists. Cannot insert.\n";
        } else {
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Address: ";
            getline(cin, address);
            cout << "Enter Phone Number: ";
            getline(cin, contact);
            int press;
            cout << "Press 1 if you want to save, 0 to not save: ";
            cin >> press;
            cin.ignore();
            if (press == 1) {
                directory[count].id = id;
                directory[count].name = name;
                directory[count].address = address;
                directory[count].contact = contact;
                count++;
                cout << "Record is saved successfully.\n";
            } else {
                cout << "Record is not saved.\n";
            }
        }
        char choice;
        cout << "Do you Want to insert any other record or something? : ";
        cin >> choice;
        cin.ignore();
        if (choice == 'n' || choice == 'N') break;
    }
}
void updateStudent() {
    while (true) {
        cout << "Search by:\n1. ID\n2. Name\nSelect option (1 or 2): ";
        int option;
        cin >> option;
        cin.ignore();
        int idSearch = -1;
        string nameSearch;
        bool found = false;
        int index = -1;
        if (option == 1) {
            cout << "Enter ID: ";
            cin >> idSearch;
            cin.ignore();
            for (int i = 0; i < count; i++) {
                if (directory[i].id == idSearch) {
                    found = true;
                    index = i;
                    break;
                }
            }
        } else if (option == 2) {
            cout << "Enter Name: ";
            getline(cin, nameSearch);
            for (int i = 0; i < count; i++) {
                if (directory[i].name == nameSearch) {
                    found = true;
                    index = i;
                    break;
                }
            }
        }
        if (!found) {
            cout << "Record is not found.\n";
        } else {
            cout << "Current Information:\n";
            directory[index].display();
            char confirm;
            cout << "Do you want to update this? [y/n]: ";
            cin >> confirm;
            cin.ignore();
            if (confirm == 'y' || confirm == 'Y') {
                int newId;
                string newName, newAddress, newContact;
                cout << "Enter the New ID: ";
                cin >> newId;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, newName);
                cout << "Enter Address: ";
                getline(cin, newAddress);
                cout << "Enter Phone Number: ";
                getline(cin, newContact);

                directory[index].id = newId;
                directory[index].name = newName;
                directory[index].address = newAddress;
                directory[index].contact = newContact;
                cout << "Record updated successfully.\n";
            }
        }
        char again;
        cout << "Do you want to update the another record? : ";
        cin >> again;
        cin.ignore();
        if (again == 'n' || again == 'N') break;
    }
}
void deleteStudent() {
    while (true) {
        int id;
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        bool found = false;
        int index = -1;
        for (int i = 0; i < count; i++) {
            if (directory[i].id == id) {
                found = true;
                index = i;
                break;
            }
        }
        if (!found) {
            cout << "Record not found.\n";
        } else {
            cout << "Current Information:\n";
            directory[index].display();
            char confirm;
            cout << "Do you want to delete this record? [y/n]: ";
            cin >> confirm;
            cin.ignore();
            if (confirm == 'y' || confirm == 'Y') {
                for (int i = index; i < count - 1; i++) {
                    directory[i] = directory[i + 1];
                }
                count--;
                cout << "Record deleted successfully.\n";
            }
        }
        char again;
        cout << "Do you want to delete another record? : ";
        cin >> again;
        cin.ignore();
        if (again == 'n' || again == 'N') break;
    }
}
void searchStudent() {
    while (true) {
        cout << "Search by:\n1. ID\n2. Name\nSelect option (1 or 2): ";
        int option;
        cin >> option;
        cin.ignore();
        bool found = false;
        int index = -1;
        if (option == 1) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            for (int i = 0; i < count; i++) {
                if (directory[i].id == id) {
                    found = true;
                    index = i;
                    break;
                }
            }
        } else if (option == 2) {
            string name;
            cout << "Enter Name: ";
            getline(cin, name);
            for (int i = 0; i < count; i++) {
                if (directory[i].name == name) {
                    found = true;
                    index = i;
                    break;
                }
            }
        }
        if (!found) {
            cout << "Record not found.\n";
        } else {
            cout << "Record Found:\n";
            directory[index].display();
        }
        char again;
        cout << "Do you want to search another record? : ";
        cin >> again;
        cin.ignore();
        if (again == 'n' || again == 'N') break;
    }
}
void listDirectory() {
    cout << "\n*************************************\n";
    cout << "Telephone Directory Members\n";
    cout << "*************************************\n";
    for (int i = 0; i < count; i++) {
        cout << "Record " << i + 1 << ":\n";
        directory[i].display();
        cout << endl;
    }
    cout << "Total " << count << " records shown successfully.\n";
    cout << "Press any key to return to Main Menu: ";
    string temp;
    getline(cin, temp);
}
int main() {
    int choice;
    while (true) {
        cout << "\n*************************************\n";
        cout << "Telephone Directory: Main Menu\n";
        cout << "*************************************\n";
        cout << "1. Insert a new student\n";
        cout << "2. Update an existing student\n";
        cout << "3. Delete a record\n";
        cout << "4. Search for a student\n";
        cout << "5. List directory\n";
        cout << "6. Exit\n";
        cout << "Select Option [1-6]: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            insertStudent();
            break;
        case 2:
            updateStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            searchStudent();
            break;
        case 5:
            listDirectory();
            break;
        case 6:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }
}

