#include "../inc/head.h"

/**
 * @brief 打印库存/借出/出库汇总报表
 */
void print_report(item_p head, borrow_p borrow, outbound_p outbound)
{
    printf("\n========== 仓库管理系统报表 ==========\n");

    // 1. 库存汇总
    int total_kind = 0;
    int total_num = 0;
    printf("\n【当前库存】\n");
    item_p ip = head->next;
    while (ip != NULL)
    {
        printf("  %-10s  分类：%-10s  库存：%d\n", ip->name, ip->kind, ip->num);
        total_kind++;
        total_num += ip->num;
        ip = ip->next;
    }
    printf("  共 %d 种物品，总库存 %d 件\n", total_kind, total_num);

    // 2. 借出记录汇总
    int borrow_cnt = 0;
    int borrow_num = 0;
    printf("\n【当前未归还借出记录】\n");
    borrow_p bp = borrow->next;
    while (bp != NULL)
    {
        printf("  借用人：%-8s  物品：%-10s  数量：%d  借出时间：%s\n",
               bp->people, bp->name, bp->num, bp->time);
        borrow_cnt++;
        borrow_num += bp->num;
        bp = bp->next;
    }
    printf("  共 %d 条未归还记录，借出总数 %d 件\n", borrow_cnt, borrow_num);

    // 3. 出库流水汇总
    int out_cnt = 0;
    int out_num = 0;
    printf("\n【历史出库流水】\n");
    outbound_p op = outbound->next;
    while (op != NULL)
    {
        out_cnt++;
        out_num += op->num;
        op = op->next;
    }
    printf("  共 %d 条出库记录，累计出库 %d 件\n", out_cnt, out_num);

    printf("======================================\n\n");
}
