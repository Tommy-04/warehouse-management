#include "../inc/head.h"

/**
 * @brief 删除
 * @param head:整条链表的头节点
 * @param data：要删除的数据节点
 * @return 成功0，失败返回-1
 */
int del_item(item_p head, char *name)
{
    // 1. 通过查找函数实现寻找节点
    item_p p = find_item(head, name);
    if (p == NULL)
    {
        printf("not found\n");
        return -1;
    }

    // 2. 找到指定节点的前一个节点
    item_p q = NULL;
    for(q=head; q->next!=p; q=q->next);
    // 循环终止： q->next == p  q是p的前一个节点


    // 3. 删除节点
    q->next = p->next;
    free(p);

    return 0;
}