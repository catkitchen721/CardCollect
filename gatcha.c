#include "menu.h"
#include "main.h"
#include "statusData.h"
#include "gatcha.h"
#include "initialGame.h"

void showGatchaInterface()
{
    cls();
    nl();
    nl();
    printf("### 抽卡機 ###");
    fenge();
    nl();

    printf("<0>    一般卡池    [ $100 / 回 ]");
    nl();
    printf("<1> 一般卡池十連抽 [ $1000 / 10回 ] (第十抽必定為4★以上)");
    nl();
    printf("<2>    限定卡池    [ 1 限定卡池券 / 回 ]");
    nl();
    printf("<99>   回到選單");
    nl();

    fenge();
    nl();
    printf("剩餘金幣: %d", money);
    nl();
    nl();
    printf("剩餘限定卡池券: %d", gatchaticket);
    nl();
    nl();
    printf("請輸入接下來的操作(請輸入數字):");
    nl();
    printf(">");
    gatchaSelector(askNoText());
    return;
}

void gatchaSelector(int theAnswer)
{
    if(theAnswer == 99) return;
    else if(theAnswer == 0)
    {
        showGatchaIng(0);
        showGatchaInterface();
    }
    else if(theAnswer == 1)
    {

        showGatchaInterface();
    }
    else if(theAnswer == 2)
    {

        showGatchaInterface();
    }
    else showGatchaInterface();
}

double GatchaProp()
{
    double result = 0.99;

    result = RandomRangeNumber(0, 1);

    return result;
}

double tenthGatchaProp()
{
    double result = 0.99;

    result = RandomRangeNumber(0, four+five);

    return result;
}

double coinGatcha(int times)
{
    int i = 0;
    double result = 0.99;
    int *CardsIGet = malloc(sizeof(int)*times);

    for(i=0; i<times; i++)
    {
        if((i+1)%10 == 0)
        {
            result = tenthGatchaProp();

            if(result <= five)
            {
                printf("★★★★★\n");
                fiveget++;
            }
            else if(result > five && result <= five + four)
            {
                printf("★★★★\n");
                fourget++;
            }
            else
            {
                printf("★★★以下\n");
                threeget++;
            }
        }
        else
        {
            result = GatchaProp();

            if(result <= five)
            {
                printf("★★★★★\n");
                fiveget++;
            }
            else if(result > five && result <= five + four)
            {
                printf("★★★★\n");
                fourget++;
            }
            else
            {
                printf("★★★以下\n");
                threeget++;
            }
        }
    }

    fiveget = 0;
    fourget = 0;
    threeget = 0;
}

double freeGatcha(int times)
{
    //
}

void showGatchaIng(int mode)
{
    switch(mode)
    {
    case 0:
    case 1:
    {
        cls();
        nl();
        nl();
        printf("---------------    [請不斷按Enter直到抽完卡:)]");
        getchar();
        getchar();
        printf("||     ?     ||");
        getchar();
        printf("||    ???    ||");
        getchar();
        printf("||   ?????   ||");
        getchar();
        printf("||   ?????   ||");
        getchar();
        printf("||   ?????   ||");
        getchar();
        printf("||   ?????   ||");
        getchar();
        printf("||    ???    ||");
        getchar();
        printf("||     ?     ||");
        getchar();
        printf("---------------");
        getchar();

        cls();
        nl();
        nl();
        printf("---------------");
        nl();
        printf("||     ?     ||");
        nl();
        printf("||    ???    ||");
        nl();
        printf("||   ?????   ||");
        nl();
        printf("||   xxxxx   ||");
        nl();
        printf("||   ?????   ||");
        nl();
        printf("||   ?????   ||");
        nl();
        printf("||    ???    ||");
        nl();
        printf("||     ?     ||");
        nl();
        printf("---------------");
        nl();
        printf("xxx!");
        nl();
        nl();
        getchar();

        return;
    }
    break;
    case 2:
    {
        //


        return;
    }
    break;
    default:
    {
        printf("Parameter error!");
        nl();
        system("pause");
        return;
    }
    }
}


