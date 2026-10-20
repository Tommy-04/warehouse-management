#include "../inc/head.h"

item_p find_item(item_p head, char *name)
{
    if (head == NULL)
    {
        return NULL;
    }

    item_p current = head->next;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            printf("物品名称：%s 物品种类：%s 物品数量：%d\n", current->name, current->kind, current->num);
            return current;
        }
        current = current->next;
    }
    return NULL;
}

