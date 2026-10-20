#ifndef _head_h_
#define _head_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>




typedef struct item{
    char name[20];
    char kind[20];
    int num;
    struct item *next;
}item, *item_p;

typedef struct borrow{
    char people[20];
    char name[20];
    char kind[20];
    int num;
    char time[30];
    struct borrow *next;
}borrow, *borrow_p;

typedef struct outbound{
    char name[20];
    char kind[20];
    int num;
    char time[30];
    struct outbound *next;
}outbound, *outbound_p;




item_p item_init(void);

borrow_p borrow_init(void);

void itemInquiry_name(item_p head, char *name);

void itemInquiry_kind(item_p head, char *kind);

void itemInquiry_num(item_p head, int num);

//尾插入库
int weicha_item(item_p head, char *name, char *kind, int num);

item_p find_item(item_p head, char *name);

int del_item(item_p head, char *name);

int weicha_borrow(borrow_p borrow, char *people, char *name, char *kind, int num, char *time);

void printf_borrow(borrow_p borrow);

outbound_p outbound_init(void);

int weicha_outbound(outbound_p outbound, char *name, char *kind, int num, char *time);

void printf_outbound(outbound_p outbound);

// 归还物品
int return_item(item_p head, borrow_p borrow, char *people, char *name, int num);

// 生成报表
void print_report(item_p head, borrow_p borrow, outbound_p outbound);

// 文件保存与加载
void save_data(item_p head, borrow_p borrow, outbound_p outbound);
void load_data(item_p head, borrow_p borrow, outbound_p outbound);


#endif
