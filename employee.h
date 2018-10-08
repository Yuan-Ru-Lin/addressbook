#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct _Employee {
    char name[20];
    char phone[11];
    char email[80];
};

typedef struct _Employee Employee;

#endif
