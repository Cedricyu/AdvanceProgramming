#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ContactStatus.h"

int main() {
    int32_t t = 0;
    scanf("%d", &t);

    s_ContactStatus *Header = NULL;
    s_ContactStatus *res= NULL;

    s_ContactStatus check_ans[t];

    //build RING structure
    for (int32_t i = 0 ; i < t ; i++) {
        s_ContactStatus *TEMP = (s_ContactStatus *)calloc(1, sizeof(s_ContactStatus));
        int32_t age = 0;
        char isConfirmedStr[20];
        bool isConfirmed = false;
        scanf("%d %s", &age, isConfirmedStr);

        if (strcmp(isConfirmedStr, "true") == 0) {
            isConfirmed = true;
        } else {
            isConfirmed = false;
        }

        *TEMP = (s_ContactStatus){
            .age = age,
            .isConfirmed = isConfirmed,
            .prev = res,
            .next = NULL
        };

        check_ans[i] = *TEMP;

        if (Header == NULL) {
            TEMP->prev = NULL;
            Header = TEMP;
            res = Header;
        } else {
            TEMP->prev = res;
            res->next = TEMP;
            res = TEMP;
        }
    }
    Header->prev = res;
    res->next = Header;

    //call your function to remove some element
    int32_t target = 0;
    scanf("%d", &target);
    Header = removeFromRing(target, Header);

    int32_t count = 0, reg = 0;
    bool check = true;

    //check the answer
    s_ContactStatus* pointer[2] = {Header, Header};

    do {
        printf("%d ", pointer[0]->age);
        if (pointer[0]->isConfirmed == true) {
            printf("true\n");
        } else {
            printf("false\n");
        }

        while (check_ans[count].age == target && check_ans[count].isConfirmed == true) {
            count += 1;
        }

        if (check_ans[count].age != pointer[0]->age &&
                check_ans[count].isConfirmed != pointer[0]->isConfirmed) {
            check = false;
            break;
        }
        count += 1;
        pointer[0] = pointer[0]->next;
        reg += 1;

    } while (pointer[0] != Header && reg < t);

    for (int32_t i = 0 ; i < reg ; i++) {
        pointer[1] = pointer[1]->prev;
    }

    if (check == false || pointer[1] != pointer[0]) {
        printf("Wrong Answer!\n");
    }

    return 0;
}
