#include "../inc/head.h"


int weicha_borrow(borrow_p borrow, char *people, char *name, char *kind, int num, char *time)
{
    

    // 1. 给新节点申请堆空间
    borrow_p new_node = (borrow_p)malloc(sizeof(*new_node));
    if (new_node == NULL)
    {
        printf("malloc error\n");
        return -1;
    }

    // 2. 给新节点的数据域赋值
    snprintf(new_node->people, sizeof(new_node->people), "%s", people);
    snprintf(new_node->name, sizeof(new_node->name), "%s", name);
    snprintf(new_node->kind, sizeof(new_node->kind), "%s", kind);
    new_node->num = num;
    snprintf(new_node->time, sizeof(new_node->time), "%s", time);

    // 3. 给新节点的指针域赋值
    new_node->next = NULL;     // 新的尾节点，next指向NULL

    // 4. 将新节点尾插入到链表中
    if (borrow->next == NULL)     // 如果链表为空，则新节点就是头节点
    {
        borrow->next = new_node;
    }
    else
    {
        borrow_p p = NULL;
        for (p=borrow; p->next != NULL; p=p->next);   // 直接写分号，意味着这个循环的循环体是空的
        // 循环结束以后，p指针一定指向尾节点
        p->next = new_node;
    }

    return 0;

}
