#include <iostream>
#include <sstream>
using namespace std;

struct Student {
    int id;
    string name;
    string className;
    Student* next;
};

Student* head = nullptr;

void insert(int id, string name, string className) {
    Student* temp = head;
    while (temp) {
        if (temp->id == id) return; 
        temp = temp->next;
    }
    Student* newStudent = new Student{id, name, className, head};
    head = newStudent;
}

void remove(int id) {
    Student* temp = head, *prev = nullptr;
    while (temp) {
        if (temp->id == id) {
            if (prev) prev->next = temp->next;
            else head = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void infor(int id) {
    Student* temp = head;
    while (temp) {
        if (temp->id == id) {
            cout << temp->name << "," << temp->className << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "NA,NA" << endl;
}

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string command;
        ss >> command;
        
        if (command == "Insert") {
            int id;
            string name, className;
            char comma;
            ss >> id >> comma;
            getline(ss, name, ',');
            getline(ss, className);
            insert(id, name, className);
        } 
        else if (command == "Delete") {
            int id;
            ss >> id;
            remove(id);
        } 
        else if (command == "Infor") {
            int id;
            ss >> id;
            infor(id);
        }
    }
    return 0;
}
