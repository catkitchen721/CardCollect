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

extern void loadMenu()
{
    cls();
    printf("%s，你好~~",username);
    nl();
    nl();
    printf("### 選單 ###");
    fenge();
    nl();
    printf("<1> 卡片圖鑑");
    nl();
    printf("<2> 抽卡機");
    nl();
    printf("<3> 卡片背包");
    nl();
    printf("<4> 儲存");
    nl();
    printf("<0> 離開遊戲");
    nl();
    fenge();
    nl();
    printf("$$$ : %d 個金幣",money);
    nl();
    nl();
    nl();
    printf("請輸入接下來的操作(請輸入數字):");
    nl();
    printf(">");
    selector(askNoText());
}

extern int selector(int inputSelection)
{
    int i = 0;

    switch(inputSelection)
    {
    case 1:
        {
            showGallery();
        }break;
    case 2:
        {
            showGatchaInterface();
        }break;
    case 3:
        {
            showPackage();
        }break;
    case 4:
        {
            return 0;
        }break;
    case 0:
        {
            endGame("確定離開遊戲?記得存檔喔~(離開:1 留下:0)");
        }break;
    default:
        return 0;
        break;
    }

    return 0;
}

/*extern void backMenu(int inputSelection, void (*OriginalPlace)())
{
    if(inputSelection == 99)
    {
        loadMenu();
    }
    else
    {
        printf("無效操作...");
        nl();
        pause();
        OriginalPlace();
    }
}*/


