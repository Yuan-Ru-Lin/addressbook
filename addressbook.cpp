#include <cstdio>
#include <iostream>

using namespace std;

typedef struct _Employee {
    string name;
    string phone;
    string email;
} Employee;

class Addressbook {
   private:
    Employee list[50];
    string storage;
    int idToFill;

   public:
    Addressbook();
    void insert();
    void show();
    void save();
    void read();
    void clear();
};

int main() {
    char op = 0;
    Addressbook myAddressbook;

    while (op != 'q') {
        cout << "i: 插入" << endl;
        cout << "l: 列出" << endl;
        cout << "s: 存檔" << endl;
        cout << "o: 讀檔" << endl;
        cout << "q: 結束" << endl;
        cout << "> ";
        cin >> op;

        switch (op) {
            case 'i':
                myAddressbook.insert();
                break;
            case 'l':
                myAddressbook.show();
                break;
            case 's':
                myAddressbook.save();
                break;
            case 'o':
                myAddressbook.read();
                break;
            case 'c':
                myAddressbook.clear();
                break;
        }
        system("clear");
    }

    return 0;
}

Addressbook::Addressbook() { int idToFill = 0; }

void Addressbook::insert() {
    Employee peopleToInsert = list[idToFill];
    cout << "姓名: ";
    cin >> peopleToInsert.name;
    cout << "電話: ";
    cin >> peopleToInsert.phone;
    cout << "Email: ";
    cin >> peopleToInsert.email;
}

void Addressbook::show() {
    for (int i = 0; i < idToFill; i++) {
        cout << "姓名: " << list[i].name << endl;
        cout << "電話: " << list[i].phone << endl;
        cout << "Email: " << list[i].email << endl;
    }
}

void Addressbook::save() {
    cin >> storage;
    FILE* in = fopen(storage, "a");
    for (int i = 0; i < idToFill; i++) {
        fprintf(in, "%d\n%s\n%s\n%s\n", i + 1, list[i].name, list[i].phone,
                list[i].email);
    }
    fflush();
}

void Addressbook::read() {
    cin >> storage;
    FILE* in = fopen(storage, "r");
    string nameToAdd;
    string phoneToAdd;
    string emailToAdd;
    while (fscanf(in, "%d%s%s%s", idToFill, nameToAdd, phoneToAdd,
                  emailToAdd) == 4) {
        list[idToFill].name = nameToAdd;
        list[idToFill].phone = phoneToAdd;
        list[idToFill].email = emailToAdd;
    }
}

void Addressbook::clear() { idToFill = 0; }