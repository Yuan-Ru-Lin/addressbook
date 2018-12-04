#include <cstdio>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef struct _Employee {
    char name[20];
    char phone[11];
    char email[20];
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
        if (op != 'l') system("clear");
    }

    return 0;
}

Addressbook::Addressbook() { int idToFill = 0; }

void Addressbook::insert() {
    Employee& peopleToInsert = list[idToFill];
    cout << "姓名: ";
    cin >> peopleToInsert.name;
    cout << "電話: ";
    cin >> peopleToInsert.phone;
    cout << "Email: ";
    cin >> peopleToInsert.email;
    idToFill++;
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
    FILE* in = fopen(storage.c_str(), "w");
    for (int i = 0; i < idToFill; i++) {
        char nameToRead[20];
        char phoneToRead[20];
        char emailToRead[100];
        strcpy(nameToRead, list[i].name);
        strcpy(phoneToRead, list[i].phone);
        strcpy(emailToRead, list[i].email);
        fprintf(in, "%s\n%s\n%s\n", nameToRead, phoneToRead, emailToRead);
    }
    fclose(in);
}

void Addressbook::read() {
    cin >> storage;
    FILE* in = fopen(storage.c_str(), "r");
    idToFill = 0;
    char nameToAdd[20];
    char phoneToAdd[20];
    char emailToAdd[100];
    while (fscanf(in, "%s%s%s", nameToAdd, phoneToAdd, emailToAdd) == 3) {
        strcpy(list[idToFill].name, nameToAdd);
        strcpy(list[idToFill].phone, phoneToAdd);
        strcpy(list[idToFill].email, emailToAdd);
        idToFill++;
    }
    fclose(in);
}

void Addressbook::clear() {
    for (int i = 0; i < idToFill; i++) {
        list[i].name[0] = '\0';
        list[i].phone[0] = '\0';
        list[i].email[0] = '\0';
    }
    storage = "";
    idToFill = 0;
}