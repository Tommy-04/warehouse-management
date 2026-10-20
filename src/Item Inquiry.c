#include "../inc/head.h"

void itemInquiry_name(item_p head, char *name)
{
    int found = 0;

    if (head == NULL || head->next == NULL)
    {
        printf("No items in warehouse.\n");
        return;
    }

    for (item_p p = head->next; p != NULL; p = p->next)
    {
        if (strcmp(p->name, name) == 0)
        {
            printf("name: %s\n", p->name);
            printf("kind: %s\n", p->kind);
            printf("num: %d\n", p->num);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Item not found.\n");
    }
}

void itemInquiry_kind(item_p head, char *kind)
{
    int found = 0;

    if (head == NULL || head->next == NULL)
    {
        printf("No items in warehouse.\n");
        return;
    }

    for (item_p p = head->next; p != NULL; p = p->next)
    {
        if (strcmp(p->kind, kind) == 0)
        {
            printf("name: %s\n", p->name);
            printf("kind: %s\n", p->kind);
            printf("num: %d\n", p->num);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Item not found.\n");
    }
}

void itemInquiry_num(item_p head, int num)
{
    int found = 0;

    if (head == NULL || head->next == NULL)
    {
        printf("No items in warehouse.\n");
        return;
    }

    for (item_p p = head->next; p != NULL; p = p->next)
    {
        if (p->num == num)
        {
            printf("name: %s\n", p->name);
            printf("kind: %s\n", p->kind);
            printf("num: %d\n", p->num);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Item not found.\n");
    }
}
