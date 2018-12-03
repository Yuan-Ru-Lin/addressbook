#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct _Employee {
    char name[20];
    char phone[11];
    char email[80];
} Employee;

class Addressbook {
   private:
    Employee list[50];
    FILE* storage;
    int idToFill;

   public:
    Addressbook();
    void insert();
    void list();
    void save();
    void read();
    void quit();
}

int main() {
    FILE* in = fopen("address_book.txt", "a");
    char op = 0;
    Addressbook myAddressbook(in);

    while (1) {
        puts("i: 插入");
        puts("l: 列出");
        puts("s: 存檔");
        puts("o: 讀檔");
        puts("q: 結束");
        printf("> ");
        scanf("%s", &op);

        switch (op) {
            case 'i':
                myAddressbook.insert();
                break;
            case 'l':
                myAddressbook.list();
                break;
            case 's':
                myAddressbook.save();
                break;
            case 'o':
                myAddressbook.read();
                break;
            case 'q':
                myAddressbook.quit();
                break;
        }
        system("clear");
    }

    return 0;
}

Addressbook::Addressbook(FILE* in) {
    storage = in;
    int idToFill = 0;
}

void Addressbook::insert() {
    Employee peopleToInsert = list[idToFill];
    cout << "姓名: ";
    cin >> peopleToInsert.name;
    cout << "電話: ";
    cin >> peopleToInsert.phone;
    cout << "Email: ";
    cin >> peopleToInsert.email;
}

void Addressbook::list() {
    for (int i=0; i<idToFill;i++) {
        cout << "姓名: " << list[i].name << endl;
        cout << "電話: " << list[i].phone << endl;
        cout << "Email: " << list[i].email << endl;
    }
}