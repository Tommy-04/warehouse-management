#include "../inc/head.h"

/**
 * @brief 归还物品：恢复库存，从借出记录里删除对应条目
 * @param head 物品链表头
 * @param borrow 借出记录链表头
 * @param people 借用人姓名
 * @param name 物品名称
 * @param num 归还数量
 * @return 0成功，-1失败
 */
int return_item(item_p head, borrow_p borrow, char *people, char *name, int num)
{
    // 1. 先在库存里找到对应物品
    item_p ip = head->next;
    while (ip != NULL)
    {
        if (strcmp(ip->name, name) == 0)
        {
            break;
        }
        ip = ip->next;
    }
    if (ip == NULL)
    {
        printf("仓库里没有该物品，归还失败\n");
        return -1;
    }

    // 2. 在借出记录里找到对应条目（按借用人+物品名匹配）
    borrow_p pre = borrow;
    borrow_p cur = borrow->next;
    while (cur != NULL)
    {
        if (strcmp(cur->people, people) == 0 && strcmp(cur->name, name) == 0)
        {
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    if (cur == NULL)
    {
        printf("没有找到该借用人对应的借出记录\n");
        return -1;
    }

    // 3. 恢复库存
    if (num <= 0 || num > cur->num)
    {
        printf("归还数量无效，最多归还%d件\n", cur->num);
        return -1;
    }
    ip->num += num;

    // 4. 从借出链表删除对应节点
    pre->next = cur->next;
    free(cur);

    printf("归还成功！已归还 %s %d 件\n", name, num);
    return 0;
}
