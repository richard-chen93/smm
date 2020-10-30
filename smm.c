/*
此程序实现以下功能：
1)  初始化输入:N-参赛学校总数
M-男子竞赛项目数，W-女子竞赛项目数
各项目名次取法有如下几种： ① 取前6名：第1名得分 7，第2名得分 5，第3名得分4，第4名得分3，第5名得分2，第6名得分1；② 取前3名：第1名得分 5，第2名得分 3，第3名得分2； ③ 用户自定义：各名次权值由用户指定；
2)  由程序提醒用户填写比赛结果
输入各项目获奖运动员的信息
3)  所有信息记录完毕后，用户可以查询各个学校的比赛成绩,
查看参赛学校信息和比赛项目信息等。
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<windows.h>
#include<stdio.h>
#include<string.h>
int n = 0;
int m = 1;  /*主函数循环控制，等于0时退出。*/
struct athlete           /*定义结构体变量*/
{
    char num[10];
    char sch[33];
    char name[20];
    char sex[20];
    char xiangmu_1[20];
    int mingci_1;
    int score_1;
    char xiangmu_2[20];
    int mingci_2;
    int score_2;
    char xiangmu_3[20];
    int mingci_3;
    int score_3;
    int score;
    int zongfen;
}x, a[30];
void init();
void luru(struct athlete a[]);             /*函数说明*/
void jisuan(struct athlete a[]);
void print(struct athlete a[]);
void chaxun(struct athlete a[]);
void numchaxun(struct athlete a[]);
void namechaxun(struct athlete a[]);
void itemchaxun(struct athlete a[]);
void paixu(struct athlete a[]);
void numdesc(struct athlete a[]);
void scoredesc(struct athlete a[]);
void total(struct athlete a[]);
void nameasc(struct athlete a[]);
void zongfen(struct athlete a[]);
void fanhui();
void tuichu();
//void save();
main()
{
    system("cls");
    while (m != 0)
    {
        init(a);
        scanf("%d", &m);
        system("cls");
        /*zongfen(a);*/
        switch (m)
        {
        case 1: luru(a); fanhui(); break;     /*主函数：选择结构，可让用户自己选择功能*/
        case 2: jisuan(a); print(a); fanhui(); break;
        case 3: chaxun(a); break;
        case 4: paixu(a); break;
        /*case 5: save(); fanhui(); break;*/
        case 0: tuichu();
        default:break;
        }
    }
}
void init()
{
    printf("\n");
    printf(">>>>>>>>>>>运动员信息管理系统<<<<<<<<<<<<<\n");      /*初始化界面*/
    printf("--------------------------\n");
    printf("1:录入\t\t3:查询\n2:浏览\t\t4:排序\n\t0:退出\n");
    printf("--------------------------\n");
    printf(">>>>>>>>>>>制作人:<<<<<<<<<<<<<\n\t\t  陈振纲\n\t\t  ");
    printf("\n   输入您的选择(0~5): ");
}
void luru(struct athlete a[])          /*输入运动员信息*/
{
    int i, j = 0, W, M, U;
    printf("请输入参赛学校数: ");
    scanf("%d", &U);
    //printf("请输入男子项目: ");
    //scanf("%d", &M);
    //printf("请输入女子项目: ");
    //scanf("%d", &W);
    printf("\n\n参赛学校数目：%d\n", U);
    //printf("男子项目数:   %d\n", M);
    //printf("女子项目数:   %d\n\n\n", W);
    printf("输入运动员人数：");
    scanf("%d", &n);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("\n请输入第%d个运动员信息:（windows系统下请用英文输入）\n", i + 1);
        printf("编号: ");
        scanf("%s", a[i].num);
        printf("学校: ");
        scanf("%s", a[i].sch);
        printf("姓名: ");
        scanf("%s", a[i].name);
        printf("性别: ");
        scanf("%s", a[i].sex);
        printf("1项目 : ");
        scanf("%s", a[i].xiangmu_1);
        printf("1名次 : ");
        scanf("%d", &a[i].mingci_1);
        printf("2项目 : ");
        scanf("%s", a[i].xiangmu_2);
        printf("2名次 : ");
        scanf("%d", &a[i].mingci_2);
        printf("3项目 : ");
        scanf("%s", a[i].xiangmu_3);
        printf("3名次 : ");
        scanf("%d", &a[i].mingci_3);
    }
}
void jisuan(struct athlete a[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        a[i].score = 0;
        if (a[i].mingci_1 == 1) a[i].score_1 = 5;
        else
            if (a[i].mingci_1 == 2) a[i].score_1 = 3;
            else
                if (a[i].mingci_1 == 3) a[i].score_1 = 2;
                else a[i].score_1 = 0;
        a[i].score += a[i].score_1;
    }
    for (i = 0; i < n; i++)
    {
        if (a[i].mingci_2 == 1) a[i].score_2 = 5;
        else
            if (a[i].mingci_2 == 2) a[i].score_2 = 3;
            else
                if (a[i].mingci_2 == 3) a[i].score_2 = 2;
                else a[i].score_2 = 0;
        a[i].score += a[i].score_2;
    }
    for (i = 0; i < n; i++)
    {
        if (a[i].mingci_3 == 1) a[i].score_3 = 5;
        else
            if (a[i].mingci_3 == 2) a[i].score_3 = 3;
            else
                if (a[i].mingci_3 == 3) a[i].score_3 = 2;
                else a[i].score_3 = 0;
        a[i].score += a[i].score_3;
    }
}
void print(struct athlete a[])        /*输出函数：同时计算各运动员所在名次的分值*/
{
    int i;
    printf("编号\t 学校\t   姓名\t   性别\t 1项目\t 1名次\t 2项目\t 2名次\t 3项目\t 3名次\t 成绩\n");
    for (i = 0; i < n; i++)
    printf("%s\t%s\t%s\t%s\t%s\t%d*\t%s\t%d*\t%s\t%d*\t%d\n",
        a[i].num, a[i].sch, a[i].name, a[i].sex, a[i].xiangmu_1, a[i].mingci_1,
        a[i].xiangmu_2, a[i].mingci_2, a[i].xiangmu_3, a[i].mingci_3, a[i].score/*a[i].zongfen*/);
}
void chaxun(struct athlete a[])            /*查询函数：可以按运动员的编号、姓名、参加的项目选择查询*/
{
    int p = 1;
    system("cls");
    while (p != 0)
    {
        printf("请选择查询依据:\n");
        printf("1:编号\n2:姓名\n3:项目\n4:所在学校总成绩\n0:返回主菜单\n");
        scanf("%d", &p);
        switch (p)
        {
        case 1: numchaxun(a); fanhui(); break;
        case 2: namechaxun(a); fanhui(); break;
        case 3: itemchaxun(a); fanhui(); break;
        case 4: print(a); total(a); fanhui(); break;
        case 0: fanhui();
        default:break;

        }
    }
}
void numchaxun(struct athlete a[])          /*按编号查询*/
{
    int i;
    char num[10];
    printf("请输入编号:");
    scanf("%s", num);
    printf("编号\t 学校\t   姓名\t   性别\t 1项目\t 1名次\t 2项目\t 2名次\t 3项目\t 3名次\t 成绩\t学校总成绩\n");
    for (i = 0; i < n; i++)
    {
        if (strcmp(num, a[i].num) == 0)
            printf("%3s%10s%10s%8s%7s%8d*%8s%7d*%8s%8d*%8d\n", a[i].num, a[i].sch, a[i].name, a[i].sex, a[i].xiangmu_1, a[i].mingci_1, a[i].xiangmu_2, a[i].mingci_2, a[i].xiangmu_3, a[i].mingci_3, a[i].score/*a[i].zongfen*/);
    }
}
void namechaxun(struct athlete a[])          /*按姓名查询*/
{
    int i;
    char name1[20];
    printf("请输入姓名:");
    scanf("%s", name1);
    printf("编号\t 学校\t   姓名\t   性别\t 1项目\t 1名次\t 2项目\t 2名次\t 3项目\t 3名次\t 成绩\t学校总成绩\n");
    for (i = 0; i < n; i++)
    {
        if (strcmp(name1, a[i].name) == 0)
            printf("%3s%10s%10s%8s%7s%8d*%8s%7d*%8s%8d*%8d\n", a[i].num, a[i].sch, a[i].name, a[i].sex, a[i].xiangmu_1, a[i].mingci_1, a[i].xiangmu_2, a[i].mingci_2, a[i].xiangmu_3, a[i].mingci_3, a[i].score/*a[i].zongfen*/);
    }
}
void itemchaxun(struct athlete a[])                /*按项目查询*/
{
    int i;
    char xiangmu[10];
    printf("请输入项目:");
    scanf("%s", xiangmu);
    printf("编号\t 学校\t   姓名\t   性别\t 1项目\t 1名次\t 2项目\t 2名次\t 3项目\t 3名次\t 成绩\t学校总成绩\n");
    for (i = 0; i < n; i++)
    {
        if (strcmp(xiangmu, a[i].xiangmu_1) == 0 || strcmp(xiangmu, a[i].xiangmu_2) == 0 || strcmp(xiangmu, a[i].xiangmu_3) == 0)
            printf("%3s%10s%10s%8s%7s%8d*%8s%7d*%8s%8d*%8d\n", a[i].num, a[i].sch, a[i].name, a[i].sex, a[i].xiangmu_1, a[i].mingci_1, a[i].xiangmu_2, a[i].mingci_2, a[i].xiangmu_3, a[i].mingci_3, a[i].score/*a[i].zongfen*/);
    }
}
void total(struct athlete a[])     /*计算团体总分*/
{
    char c[20];
    int i, s = 0;
    printf("\n请输入您要查询的学校名字:  ");
    scanf("%s", c);
    jisuan(a);
    printf("\n%3s学校总成绩\n", c);
    for (i = 0; i < n; i++)
    {
        if (strcmp(a[i].sch, c) == 0)   /*用户需要查询的学校名与每个运动员的学校对比，如果相同，运动员的成绩加入这个学校的团体总分*/
            s += a[i].score;
    }
    printf("%9d\n", s);
}
void paixu(struct athlete a[])            /*排序函数：可按编号升序、姓名升序、成绩降序、学校总成绩降序选择查询*/
{
    int p = 1;
    system("cls");
    while (p != 0)
    {
        printf("请选择排序依据:\n");
        printf("1:编号升序\n2:姓名升序\n3:成绩降序\n0:返回主菜单\n");
        scanf("%d", &p);
        switch (p)
        {
        case 1: numdesc(a); jisuan(a); print(a); fanhui(); break;
        case 2: nameasc(a); jisuan(a); print(a); fanhui(); break;
        case 3: scoredesc(a); jisuan(a); print(a); fanhui(); break;
        case 0: fanhui();
        default:break;
        }
    }
}
void numdesc(struct athlete a[])
{
    int i, b, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (b = i + 1; b < n; b++)
            if (strcmp(a[b].num, a[k].num) < 0)  k = b;
        x = a[k];
        a[k] = a[i];
        a[i] = x;
    }
}
void scoredesc(struct athlete a[])
{
    int i, b, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (b = i + 1; b < n; b++)
            if (a[b].score > a[k].score)  k = b;
        x = a[k];
        a[k] = a[i];
        a[i] = x;
    }
}
void nameasc(struct athlete a[])
{
    int i, b, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (b = i + 1; b < n; b++)
            if (strcmp(a[b].name, a[k].name) < 0)  k = b;
        x = a[k];
        a[k] = a[i];
        a[i] = x;
    }
}
//void zongfen(struct athlete a[])
//{
//    int i, s, j;
//    jisuan(a);
//    for (i = 0; i < n; i++)
//    {
//        /*a[i].zongfen*/ = 0;
//        for (j != i; j < n; j++)
//        {
//            if (strcmp(a[i].sch, a[j].sch) == 0)   /*用户需要查询的学校名与每个运动员的学校对比，如果相同，运动员的成绩加入这个学校的团体总分*/
//                s += a[j].score;
//        }
//        /*a[i].zongfen*/ = s;
//    }
//}

void fanhui()
{
    printf("\n\n按Enter键返回!\n");   /*返回菜单*/
    getchar();
    getchar();
    system("cls");
}
void tuichu()           /*退出程序*/
{
    char c;
    printf("您确认退出吗？按Y或y将退出\n");
    getchar();
    c = getchar();
    if (c == 'Y' || c == 'y')
        system("cls");
    else
    {
        m = 1;
        system("cls");
    }
}
//void save()
//{
//    FILE* fp;
//    int i;
//    fp = fopen("C:\\运动员成绩表.xls", "w+");
//    fputs("    编号\t    学校\t     姓名\t    性别\t   1项目\t   1*名次\t   2项目\t   2*名次\t   3项目\t   3*名次\t    成绩\t学校总成绩\n", fp);
//    for (i = 0; i < n; i++)
//        fprintf(fp, "%s  \t%s  \t%s  \t%s  \t%s  \t%d  \t%s  \t%d  \t%s  \t%d  \t%d  \t%d  \n", a[i].num, a[i].sch, a[i].name, a[i].sex, a[i].xiangmu_1, a[i].mingci_1, a[i].xiangmu_2, a[i].mingci_2, a[i].xiangmu_3, a[i].mingci_3, a[i].score
//            /*a[i].zongfen*/
//        );
//    fclose(fp);
//    printf("\n保存成功!!\n\n");
//}