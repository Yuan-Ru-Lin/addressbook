#include <vector>
#include <fstream>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Employee {
    std::string name;
    std::string phone;
    std::string email;
};

class Addressbook {
   private:
    std::vector<Employee> list;

   public:
    Addressbook() = default ;
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
        // cout << endl;
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
    }

    return 0;
}

void Addressbook::insert() {
    Employee peopleToInsert;
    cout << "姓名: ";
    cin >> peopleToInsert.name;
    cin >> peopleToInsert.phone;
    cin >> peopleToInsert.email;
    list.push_back(peopleToInsert);
}

void Addressbook::show() {
    for (Employee & employee : list) {
        cout << "姓名: " << employee.name << endl;
        cout << "電話: " << employee.phone << endl;
        cout << "Email: " << employee.email << endl;
    }
}

void Addressbook::save() {
    std::string savefile;
    std::cin >> savefile;
    std::fstream in{savefile, std::ios::out};
    for (Employee & employee : list) {
        in << employee.name << "\n"
           << employee.phone << "\n"
           << employee.email << "\n";
    }
}

void Addressbook::read() {
    std::string restorefile;
    cin >> restorefile;
    std::fstream in{restorefile, std::ios::in};
    list.clear();

    Employee new_employee;
    while (in >> new_employee.name >> new_employee.phone >> new_employee.email) {
        list.push_back(new_employee);
    }
}

void Addressbook::clear() {
    list.clear();
}
