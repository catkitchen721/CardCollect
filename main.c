/*額外副程式
#include "fight.h"
v #include "gallery.h"
v #include "gatcha.h"
v #include "menu.h"
#include "playground.h"
#include "save.h"
v #include "main.h"
v #include "statusData.h"
v #include "initialGame.h"
v #include "load.h"
v #include "end.h"
v #include "cardPackage.h"
v #include "numberCount.h"
*/

#include "menu.h"
#include "main.h"
#include "statusData.h"
#include "gatcha.h"
#include "initialGame.h"
#include "load.h"
#include "end.h"
#include "gallery.h"
#include "cardPackage.h"
#include "numberCount.h"

void nl()
{
    printf("\n");
}

void fenge()
{
    nl();
    printf("====================");
    nl();
}

void cls()
{
    system("CLS");
}

void pause()
{
    printf("按任意鍵繼續旅程~~");
    nl();
    getchar();
    getchar();
}

void askGoldfinger()
{
    if(hasAskGoldfinger == 0)
    {
        printf("<注意!這個問題只能回答一次...>");
        nl();
        printf("金手指密碼是?(僅有數字12位數)(不知道的話輸入0繼續)");
        nl();

        long long int password = 0;

        scanf("%lld",&password);

        if(password == PASSWORD)
        {
            goldfinger = 1;
            printf("[一生一世姆咪姆咪愛你愛你]");
            nl();
            printf("##GoldFinger##");
            nl();
            pause();
        }
        else
        {
            printf("密碼錯誤，以一般模式進行...");
            nl();
            pause();
        }

        hasAskGoldfinger = 1;
    }
}

int ask(char instru[50])
{
    printf("%s",instru);
    nl();
    int theAnswer = 0;
    scanf("%d",&theAnswer);
    return theAnswer;
}

int askNoText()
{
    int theAnswer = 0;
    scanf("%d",&theAnswer);
    return theAnswer;
}



int main()
{
    system("@echo off");
    system("title CardCollect--by Mumi Egg Soup");
    srand(time(NULL) + getpid());
    askGoldfinger();
    initialAll();
    loadData();
    while(1)
    {
        loadMenu();
    }

    printf("不正常退出...");
    nl();
    return 0;
}
