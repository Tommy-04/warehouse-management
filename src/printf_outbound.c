#include "../inc/head.h"


void printf_outbound(outbound_p outbound)
{
    outbound_p p = NULL;
    if (outbound == NULL)
    {
        return;
    }

    for(p=outbound->next; p != NULL; p=p->next)
    {
        printf(" 入库物品：%s ,种类：%s, 数量：%d, 时间：%s\n", p->name, p->kind, p->num, p->time);
    }
    return;
}
