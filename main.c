#include <stdio.h>
#include <stdlib.h>

#include "employee.h"

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
            Employee temp;
            puts("姓名: ");
            scanf("%s", &temp.name);
            fprintf("%s\n", temp.name);
            puts("電話: ");
            scanf("%s", &temp.phone);
            fprintf("%s\n", temp.phone);
            puts("Email: ");
            scanf("%s", &temp.email);
            fprintf("%s\n", temp.email);
            break;
        case 'l':
            break;
        case 's':
            break;
        case 'o':
            break;
        case 'q':
            break;
        }
        system("clear");
    }

    return 0;
}
