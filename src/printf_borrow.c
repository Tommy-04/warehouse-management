#include "../inc/head.h"


void printf_borrow(borrow_p borrow)
{
    borrow_p p = NULL;
    if (borrow == NULL)
    {
        return;
    }

    for(p=borrow->next; p != NULL; p=p->next)
    {
        printf("借用人姓名：%s, 借用物品：%s ,借用种类：%s, 借用数量：%d, 借用时间：%s\n", p->people, p->name, p->kind, p->num, p->time);
    }
    
}
