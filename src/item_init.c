#include "../inc/head.h"

/**
 * @brief 初始化链表头节点
 * @return 返回头节点的指针，如果分配内存失败则返回NULL
 */
item_p item_init(void)
{
    // 1. 给头节点分配内存
    item_p head = (item_p)malloc(sizeof(item));
    if (head == NULL)
    {
        printf("malloc error\n");
        return NULL;
    }

    // 2. 给头节点的数据域赋值
    // 不放数据，跳过

    // 3. 给头节点的指针域赋值
    head->next = NULL;

    return head;
}