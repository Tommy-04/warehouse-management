#include "../inc/head.h"
void main_menu(void);

void Item_Query_2menu(void);

void Warehouse_In_2menu(void);

void Update_Item_2menu(void);

void borrow_item_2menu(void);



int main(void)
{
    item_p head = item_init();
    borrow_p borrow = borrow_init();
    outbound_p outbound = outbound_init();
    load_data(head, borrow, outbound);
    printf("欢迎使用物品管理系统\n");
    printf("请选择操作\n");
    while (1)
    {
        main_menu();
        int choice;
        scanf("%d", &choice);
        if (choice ==1)
        {
            printf("请选择查询方式(输入数字)\n");
            while(1)
            {
                Item_Query_2menu();
                int x;
                scanf("%d", &x);
                if (x == 1)
                {
                    //物品名称查询
                    char name[20];
                    printf("请输入物品名称\n");
                    scanf("%19s", name);
                    itemInquiry_name( head, name);
                }
                else if (x == 2)
                {
                    //物品种类查询
                    char kind[20];
                    printf("请输入物品种类\n");
                    scanf("%19s", kind);
                    itemInquiry_kind(head, kind);
                }
                else if (x == 3)
                {
                    //物品数量查询
                    int num;
                    printf("请输入物品数量\n");
                    scanf("%d", &num);
                    itemInquiry_num(head, num);
                }
                else if (x == 4)
                {
                    //返回主菜单
                    break;
                }
                else
                {
                    printf("输入错误，请重新输入\n");
                }


            }
            
            
        }
        else if (choice == 2)
        {
            //物品信息更新
            while(1)
            {
                Update_Item_2menu();
                int x;
                scanf("%d", &x);
                
            
                char kind[20];
                int num;
           
                if (x == 1)
                {
                    printf("请输入要更新的物品名称\n");
                char name[20];
                scanf("%19s", name);
                item_p p=find_item(head, name);
                if(p == NULL)
                {
                    printf("没有找到该物品,请重新选择\n");
                    continue;

                }
                    printf("请输入新的物品种类\n");
                    scanf("%19s", kind);
                    if(strlen(kind) < 20)
                    {
                    strcpy(p->kind, kind);
                    }
                    else
                    {
                    printf("物品种类更新失败\n");
                    }
                }
                else if (x == 2)
                {
                     printf("请输入要更新的物品名称\n");
                char name[20];
                scanf("%19s", name);
                item_p p=find_item(head, name);
                if(p == NULL)
                {
                    printf("没有找到该物品,请重新选择\n");
                    continue;
                }
                    printf("请输入新的物品数量\n");
                    scanf("%d", &num);
                    if(num >= 0)
                    {
                        p->num = num;
                        printf("物品数量更新成功\n");
                    }
                    else
                    {
                        printf("物品数量更新失败\n");
                    }
                }
                else if (x == 3)
                {
                    //返回主菜单
                    break;
                }
                else
                {
                    printf("输入错误，请重新输入\n");
                }
            }
            


        }
        else if (choice == 3)
        {
            //借用申请
            while(1)
            {
                borrow_item_2menu();
                int x;
                scanf("%d", &x);
                if (x == 1)
                {
                    char people[20];
                    scanf("%19s", people);
                    printf("借用人：%s",people);
                    int m = 0;
                    do
                    {
                    printf("请输入借用物品的名称\n");
                    char name[20];
                    int num;
                    scanf("%19s",name);
                    item_p p = find_item(head, name);
                    if(p != NULL)
                    {
                        printf("请选择借用的数量：");
                        scanf("%d", &num);
                        if(num <= p->num && num > 0)
                        {
                           p->num -= num;
                            printf("借用成功\n");
                            char time_buf[64]; // 存放格式化后的时间字符串
                            time_t now = time(NULL);
                            struct tm *t = localtime(&now);
                            struct tm fallback_time = {0};
                            if (t == NULL)
                            {
                                t = &fallback_time;
                            }

                            // 关键：判断localtime返回值，防止NULL传入strftime引发段错误
                            if (t == NULL)
                                {
                                    printf("获取系统时间失败！\n");
                                    
                                }
                                    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", t);

                                    printf("借用人：%s 借用物品：%s 借用数量：%d 借用日期：%s\n",people, name, num, time_buf);
                                        weicha_borrow(borrow, people, name, p->kind, num, time_buf);
                                    printf("1.继续借用\n输入其他返回\n");                         
                            scanf("%d", &m);
                            if(m == 1)
                            {
                                continue;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else if(num > p->num)
                        {
                            printf("借用失败，库存不足\n");
                            break;
                        }
                        else
                        {
                            printf("借用失败，数量不能为负数\n");
                            break;
                        }
                    }
                    else
                    {
                        printf("没有找到该物品");
                        break;
                    }
                    } while (m);
                    
                    
                }
                else if (x == 2)
                {
                    break;//返回主菜单
                }
                else
                {
                    printf("输入错误，请重新输入\n");
                }
            }
        }
        else if (choice == 4)
        {
            //删除物品
            while (1)
            {
                printf("请输入要删除的物品名称\n");
                char name[20];
                scanf("%19s", name);
                if (del_item(head, name)==0)
                {
                    printf("删除成功\n");
                }
                else
                {
                    printf("删除失败\n");
                }
                int x;
                printf("1.继续删除\n输入其他返回\n");
                scanf("%d", &x);
                if (x == 1)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            
        }
        else if (choice == 5)
        {
            //物品入库
            while(1)
            {
                int x;
            Warehouse_In_2menu();
            scanf("%d", &x);
            if (x == 1)
            {
                printf("请输入入库商品的名称、种类、数量\n");
                char name[20];
                 char kind[20];
                int num=0;
                scanf("%19s",name);
                scanf("%19s",kind);
                scanf("%d",&num);
                if(strlen(name) < 20 && strlen(kind) < 20 && num > 0)
                {
                    weicha_item(head, name, kind, num);
                    printf("物品入库成功\n");
                    char time_buf[64];
                    time_t now = time(NULL);
                    struct tm *t = localtime(&now);
                    struct tm fallback_time = {0};
                    if (t == NULL)
                    {
                        t = &fallback_time;
                    }

                    // 关键判空！防止空指针传入strftime
                    if (t == NULL)
                    {
                     printf("获取时间失败!\n");
                     
                    }
                    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", t);
                    weicha_outbound(outbound, name, kind, num, time_buf);
                    

                }
                    
                else
                {
                    printf("物品入库失败\n");
                }
            }
            else if (x == 2)
            {
                break;//返回主菜单
            }
            else
            {
                printf("输入错误，请重新输入\n");
            }
            
            }
            
        }
        else if (choice == 6)
        {
            //物品出库
            while(1)
            {
                printf("1.请输入要出库的物品名称\n");
                printf("2.返回主菜单\n");
                int x;
                scanf("%d", &x);
                if (x == 1)
                {
                    char name[20];
                scanf("%19s", name);
                item_p p = find_item(head, name);
                if (p != NULL)
                {
                    printf("请选择出库的数量：");
                    int num;
                    scanf("%d", &num);
                    if (num <= p->num && num > 0)
                    {
                        p->num -= num;
                        printf("出库成功\n");
                        char time_buf[64];
                        time_t now = time(NULL);
                        struct tm *t = localtime(&now);
                        strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", t);
                        weicha_outbound(outbound, p->name, p->kind, num, time_buf);
                    }
                    else if (num > p->num)
                    {
                        printf("出库失败，库存不足\n");
                    }
                    else
                    {
                        printf("出库失败，数量不能为负数\n");
                    }
                }
                else
                {
                    printf("没有找到该物品\n");
                }
                }
                else if (x == 2)
                {
                    break;//返回主菜单
                }
                else
                {
                    printf("输入错误，请重新输入\n");
                }
                
            }
        }
        else if (choice == 7)
        {
            //归还物品
            while (1)
            {
                char people[20], name[20];
                int num;
                printf("请输入借用人姓名：");
                scanf("%19s", people);
                printf("请输入要归还的物品名称：");
                scanf("%19s", name);
                printf("请输入归还数量：");
                scanf("%d", &num);
                return_item(head, borrow, people, name, num);

                int x;
                printf("1.继续归还\n输入其他返回\n");
                scanf("%d", &x);
                if (x != 1) break;
            }
        }
        else if (choice == 8)
        {
            //报表生成
            print_report(head, borrow, outbound);
        }
        else if (choice == 9)
        {
            //借用记录查询
            printf_borrow(borrow);

        }
        else if (choice == 10)
        {
            //入库记录查询
            printf_outbound(outbound);

        }
        else if (choice == 11)
        {
            save_data(head, borrow, outbound);
            return 0;
        }
        else
        {
            printf("输入错误，请重新输入\n");
        }
    }
}

void main_menu(void)
{
    printf("1.物品查询\n");
    printf("2.物品信息更新\n");
    printf("3.借用申请\n");
    printf("4.删除物品\n");
    printf("5.物品入库\n");
    printf("6.物品出库\n");
    printf("7.归还物品\n");
    printf("8.报表生成\n");
    printf("9.借用记录查询\n");
    printf("10.入库记录查询\n");
    printf("11.退出\n");
}

void Item_Query_2menu(void)
{
    printf("1.物品名称查询\n");
    printf("2.物品种类查询\n");
    printf("3.物品数量查询\n");
    printf("4.返回主菜单\n");
}

void Warehouse_In_2menu(void)
{
    printf("1.入库\n");
    printf("2.返回主菜单\n");
}

void Update_Item_2menu(void)
{
    printf("1.物品种类更新\n");
    printf("2.物品数量更新\n");
    printf("3.返回主菜单\n");
}

void borrow_item_2menu(void)
{
    printf("1.请填写借用人信息\n");
    printf("2.返回主菜单\n");
}

  
