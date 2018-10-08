#include <stdio.h>
#include <stdlib.h>

#include "employee.h"

int main() {
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
