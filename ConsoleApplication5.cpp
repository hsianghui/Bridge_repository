#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <corecrt_malloc.h>
enum mon {
    Jan=1,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec
};

struct person {
    char name[32];
    double capital;
    double interests;
    char* date1;
    char* date2;
};

int Add(struct person* set,int num) {                                                 //Add(perset,sizeof(perset)/sizeof(perset[0]));参数：结构体指针，结构体成员多少
    struct person* temp;
    temp = (struct person*)malloc( (num+1)*sizeof(struct person));
    if (temp == NULL) {
        perror("realloc of Add function");
        free(set);
        return 1;
    }
    set = temp;
    scanf("%s,%lf,%lf,%s,%s", set->name, &(set->capital), &(set->interests),set->date1,set->date2);
    return 0;
}

int Ser(struct person* set,char name0[32],int num) {
    int t = 0;
    for (t; t < num; t++) {
        if (strcmp( name0 , (set + t)->name)==0) {
            return t + 1;
        }
    }
    return 0;
}

int Del(struct person* set, char name0[32], int num) {

    return 0;
}

int Cha(struct person* set, char name0[32], int num) {

    return 0;
}

void DATE() {
    int month = 0, day = 0, year = 0;
    char mon[4];
    char date[] = __DATE__;
    sscanf(date, "%3s %d %d", mon, &day, &year);

    if (strcmp(mon, "Jan") == 0) month = (int)1;
    else if (strcmp(mon, "Feb") == 0) month = 2;
    else if (strcmp(mon, "Mar") == 0) month = 3;
    else if (strcmp(mon, "Apr") == 0) month = 4;
    else if (strcmp(mon, "May") == 0) month = 5;
    else if (strcmp(mon, "Jun") == 0) month = 6;
    else if (strcmp(mon, "Jul") == 0) month = 7;
    else if (strcmp(mon, "Aug") == 0) month = 8;
    else if (strcmp(mon, "Sep") == 0) month = 9;
    else if (strcmp(mon, "Oct") == 0) month = 10;
    else if (strcmp(mon, "Nov") == 0) month = 11;
    else if (strcmp(mon, "Dec") == 0) month = 12;
    {
        printf("%d %d %d\n", month, day, year);
    }
}
void menu() {
    printf("************************************************\n"
           "*******       1.Add         2.Del        *******\n"
           "*******       3.Ser         4.Cha        *******\n"
           "*******             0.Exit               *******\n"
           "************************************************\n");
}

int main()
{
    menu();
    int opr;
    DATE();
    struct person perset[1] = { {"name",1000,0.1,(char*)__DATE__,(char*)__DATE__}};
    printf("请输入要进行的操作：");
    scanf("%d", &opr);
    switch (opr) {
        case 1:
            Add(perset,sizeof(perset)/sizeof(perset[0]));
            break;
        case 2:
            char peo[32];
            scanf("%s", peo);
            Del(perset, peo, sizeof(perset) / sizeof(perset[0]));
            break;
        case 3:
            scanf("%s", peo);
            Ser(perset,peo, sizeof(perset) / sizeof(perset[0]));
            break;
        case 4:
            scanf("%s", peo);
            Cha(perset, peo, sizeof(perset) / sizeof(perset[0]));
            break;
        case 0:
            printf("已退出编辑。");
            break;
    }
    FILE* pf = fopen( "info.txt","a" );
    if (pf == NULL) {
        perror("fopen of file");
        return 1;
    }
    fprintf(pf, "%s,%lf,%lf", perset[0].name, perset[0].capital, perset[0].interests);

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
