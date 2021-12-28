
#include <stdio.h>
#include <stdlib.h>
#include "ContactStatus.h"

s_ContactStatus* removeFromRing(int32_t target, s_ContactStatus* Header) {

    s_ContactStatus *end = Header;
    s_ContactStatus *head_cur = Header;
    //s_ContactStatus *ans = Header;
    s_ContactStatus *pre = NULL;
    s_ContactStatus *next = NULL;
    //int flag=0;
    bool flag1=true;
    bool flag2=true;
    int flag3=0;
    //bool flag4=false;
    //bool flag5=false;
    while (1){
        bool flag4=false;
        //bool flag5=false;
        //head = head->next;
        //printf("age =%d\n",head->age);
        if (head_cur->age==target)
            flag1=false;
            //exist the given age
        if (head_cur->isConfirmed==true)
            flag2=false;
        if ( head_cur == end && flag3 ==1){
                    if (flag1||flag2)
                        printf("System error!\n");
                    return end;
            }
        s_ContactStatus *current = head_cur;
        if ( head_cur ->age == target && head_cur->isConfirmed==true){
                    //s_ContactStatus *current = head_cur;
                    pre = head_cur->prev;
                    next = head_cur->next;
                    pre->next = next;
                    next->prev = pre;
                    if (head_cur==end)
                        end = end->next;
                    flag4 = true;
                }
        flag3=1;
        head_cur = head_cur->next;
        if ( flag4 )
            free(current);
    }
    //return ptr;
}
