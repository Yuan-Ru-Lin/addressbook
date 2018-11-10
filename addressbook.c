#include <stdio.h>
#include <stdlib.h>

typedef struct _Employee {
    char name[20];
    char phone[11];
    char email[80];
} Employee;

void insert();
void list();
void save();
void read();
void quit();

int main() {
    FILE* in = fopen("address_book.txt", "a");
    char op = 0;

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
                insert();
                break;
            case 'l':
                list();
                break;
            case 's':
                save();
                break;
            case 'o':
                read();
                break;
            case 'q':
                quit();
                break;
        }
        system("clear");
    }

    return 0;
}

void insert() {
    Employee temp;
    puts("姓名: ");
    scanf("%s", &temp.name);
    fprintf(in, "%s\n", temp.name);
    puts("電話: ");
    scanf("%s", &temp.phone);
    fprintf(in, "%s\n", temp.phone);
    puts("Email: ");
    scanf("%s", &temp.email);
    fprintf(in, "%s\n", temp.email);
}