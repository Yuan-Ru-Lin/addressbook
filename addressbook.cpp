#include <array>
#include <fstream>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef struct _Employee {
    std::string name;
    std::string phone;
    std::string email;
} Employee;

class Addressbook {
   private:
    std::array<Employee, 50> list;
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
    std::fstream in(storage, std::ios::out);
    for (int i = 0; i < idToFill; i++) {
        in << list[i].name << "\n" << list[i].phone << "\n" << list[i].email << "\n";
    }
}

void Addressbook::read() {
    cin >> storage;
    std::fstream in(storage, std::ios::in);
    idToFill = 0;
    while (in >> list[idToFill].name >> list[idToFill].phone >> list[idToFill].email) {
        idToFill++;
    }
}

void Addressbook::clear() {
    for (int i = 0; i < idToFill; i++) {
        list[i].name = "";
        list[i].phone = "";
        list[i].email = "";
    }
    storage = "";
    idToFill = 0;
}
