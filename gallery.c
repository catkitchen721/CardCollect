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

void showGallery()
{
    cls();
    nl();
    nl();
    printf("### 圖鑑 ###");
    fenge();
    nl();

    cardsCanView();

    fenge();
    printf("[圖鑑中的三圍數值均為基準值，實際得到卡片可能有些微浮動]");
    nl();
    nl();
    printf("圖鑑蒐集進度: %d / %d",countTotalMeetCard(),CURRENTALLCARD);
    nl();
    nl();
    printf("<99> 回到選單");
    nl();
    nl();
    printf("請輸入接下來的操作(請輸入數字):");
    nl();
    printf(">");
    if(askNoText() == 99) return; else showGallery();
}

int countTotalMeetCard()
{
    int result = 0;
    int i = 0;

    for(i=0;i<TOTALPACKAGESIZE;i++)
    {
        if(hasMeetCard[i] == 1)
        {
            result += 1;
        }
    }

    return result;
}

void cardsCanView()
{
    int i = 0;

    for(i=0;i<TOTALPACKAGESIZE;i++)
    {
        if(hasMeetCard[i] == 1)
        {
            printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
                   allGallery[i]->textNO,
                   allGallery[i]->textName,
                   allGallery[i]->textLore,
                   allGallery[i]->textHp,
                   allGallery[i]->textATK,
                   allGallery[i]->textDEF,
                   allGallery[i]->textType);
            nl();
        }
    }
}
