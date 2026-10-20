#include "../inc/head.h"

/**
 * @brief 把所有链表数据保存到本地文件
 */
void save_data(item_p head, borrow_p borrow, outbound_p outbound)
{
    FILE *fp = fopen("warehouse_data.txt", "w");
    if (fp == NULL)
    {
        printf("打开文件失败，数据未保存\n");
        return;
    }

    // 1. 写库存链表
    fprintf(fp, "# ITEM\n");
    item_p ip = head->next;
    while (ip != NULL)
    {
        fprintf(fp, "%s %s %d\n", ip->name, ip->kind, ip->num);
        ip = ip->next;
    }

    // 2. 写借出记录
    fprintf(fp, "# BORROW\n");
    borrow_p bp = borrow->next;
    while (bp != NULL)
    {
        fprintf(fp, "%s %s %s %d %s\n", bp->people, bp->name, bp->kind, bp->num, bp->time);
        bp = bp->next;
    }

    // 3. 写出库流水
    fprintf(fp, "# OUTBOUND\n");
    outbound_p op = outbound->next;
    while (op != NULL)
    {
        fprintf(fp, "%s %s %d %s\n", op->name, op->kind, op->num, op->time);
        op = op->next;
    }

    fclose(fp);
    printf("数据已保存到 warehouse_data.txt\n");
}

/**
 * @brief 从本地文件加载数据
 */
void load_data(item_p head, borrow_p borrow, outbound_p outbound)
{
    FILE *fp = fopen("warehouse_data.txt", "r");
    if (fp == NULL)
    {
        printf("未找到历史数据文件，使用空仓库启动\n");
        return;
    }

    char line[256];
    int section = 0;  // 0=item 1=borrow 2=outbound

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (line[0] == '#')
        {
            if (strstr(line, "BORROW")) section = 1;
            else if (strstr(line, "OUTBOUND")) section = 2;
            else section = 0;
            continue;
        }

        if (section == 0)
        {
            char name[20], kind[20];
            int num;
            if (sscanf(line, "%19s %19s %d", name, kind, &num) == 3)
            {
                weicha_item(head, name, kind, num);
            }
        }
        else if (section == 1)
        {
            char people[20], name[20], kind[20], time[30];
            int num;
            if (sscanf(line, "%19s %19s %19s %d %29[^\n]", people, name, kind, &num, time) == 5)
            {
                weicha_borrow(borrow, people, name, kind, num, time);
            }
        }
        else if (section == 2)
        {
            char name[20], kind[20], time[30];
            int num;
            if (sscanf(line, "%19s %19s %d %29[^\n]", name, kind, &num, time) == 4)
            {
                weicha_outbound(outbound, name, kind, num, time);
            }
        }
    }

    fclose(fp);
    printf("历史数据加载完成\n");
}
