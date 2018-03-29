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

int hasMallocCardCollect = 0;
char tempName[20] = "\0";
int tempRare = 1;

void showPackage()
{
    cls();
    nl();
    nl();
    printf("### 卡片背包 ###");
    fenge();
    nl();

    viewPackageCard();

    fenge();
    nl();
    printf("背包卡片總數: %d / %d",countPackageCard(),USERPACKAGECOUNTSIZE);
    nl();
    nl();
    printf("<0> 將卡片 加入/取消 最愛");
    nl();
    printf("<1> 販賣卡片");
    nl();
    printf("<99> 回到選單");
    nl();
    nl();
    printf("請輸入接下來的操作(請輸入數字):");
    nl();
    printf(">");
    PackageSelector(askNoText());
    return;
}

void deleteCard(int theId)
{
    if(theId < 0)
    {
        return;
    }
    else
    {
        int i = 0;
        for(i=0; i<USERPACKAGESIZE; i++)
        {
            if(userPack[i] != NULL)
            {
                if(userPack[i]->cardInPack->id == theId)
                {
                    if(userPack[i]->isFavorite == 1)
                    {
                        printf("<%s>已經被加入最愛，無法販售!",userPack[i]->cardInPack->name);
                        nl();
                        printf("%s鬆了一口氣...",userPack[i]->cardInPack->name);
                        nl();
                        pause();
                        return;
                    }
                    else if(userPack[i]->isFavorite == 2)
                    {
                        printf("蜜蜜與老師已經永遠無法分開了...");
                        nl();
                        printf("蜜蜜愛你哦<3");
                        nl();
                        pause();
                        return;
                    }
                    else if(userPack[i]->cardInPack->id == 49 && userPack[i]->cardInPack->id != 2)
                    {
                        printf("<%s>很傷心...",userPack[i]->cardInPack->name);
                        nl();
                        getchar();
                        getchar();
                        printf("%s想要X了老師...",userPack[i]->cardInPack->name);
                        nl();
                        getchar();
                        getchar();
                        printf("[%s黑化了]",userPack[i]->cardInPack->name);
                        nl();

                        strcpy(totalPool[49]->name, "完美的蜜蜜");
                        totalPool[49]->hp = 63;
                        totalPool[49]->atk = 6333;
                        totalPool[49]->def = 6333;

                        strcpy(allGallery[49]->textName, "完美的蜜蜜");
                        strcpy(allGallery[49]->textLore, "--姆咪~老師很想成為蜜蜜的布偶呢~(愛心眼");
                        strcpy(allGallery[49]->textHp, "HP:63");
                        strcpy(allGallery[49]->textATK, "ATK:6333");
                        strcpy(allGallery[49]->textDEF, "DEF:6333");

                        strcpy(userPack[49]->cardInPack->name, "完美的蜜蜜");
                        userPack[49]->cardInPack->hp = 63;
                        userPack[49]->cardInPack->atk = 6333;
                        userPack[49]->cardInPack->def = 6333;
                        userPack[49]->isFavorite = 2;
                        pause();
                        return;
                    }
                    else
                    {
                        if(userPack[i]->countInPack > 1)
                        {
                            tempRare = userPack[i]->cardInPack->rare;
                            strcpy(tempName, userPack[i]->cardInPack->name);
                            (userPack[i]->countInPack)--;
                        }
                        else if(userPack[i]->countInPack == 1)
                        {
                            tempRare = userPack[i]->cardInPack->rare;
                            strcpy(tempName, userPack[i]->cardInPack->name);
                            free(userPack[i]->cardInPack);
                            userPack[i]->cardInPack = NULL;
                            free(userPack[i]);
                            userPack[i] = NULL;
                        }
                        else
                        {
                            printf("販賣發生錯誤...操作失敗");
                            nl();
                            pause();
                            return;
                        }
                        printf("賣掉<%s> * 1，幫%sQQ",tempName,tempName);
                        nl();
                        int addMoney = sellGetMoney(tempRare);
                        money += addMoney;
                        printf("<%s>被賣掉後給%s的撫恤金: %5d元",tempName,username,addMoney);
                        nl();
                        pause();
                        return;
                    }
                }
            }
        }
        printf("背包沒有這張卡QAQ");
        nl();
        pause();
        return;
    }
}

void addFavorite(int theId)
{
    if(theId < 0)
    {
        return;
    }
    else
    {
        int i = 0;
        for(i=0; i<USERPACKAGESIZE; i++)
        {
            if(userPack[i] != NULL)
            {
                if(userPack[i]->cardInPack->id == theId)
                {
                    if(userPack[i]->isFavorite == 1)
                    {
                        userPack[i]->isFavorite = 0;
                        printf("<%s>不再是%s最愛!",userPack[i]->cardInPack->name,username);
                        nl();
                        pause();
                        return;
                    }
                    else if(userPack[i]->isFavorite == 0)
                    {
                        userPack[i]->isFavorite = 1;
                        printf("將<%s>加入最愛!",userPack[i]->cardInPack->name);
                        nl();
                        pause();
                        return;
                    }
                    else
                    {
                        printf("無法改變狀態!");
                        nl();
                        pause();
                        return;
                    }
                }
            }
        }
        printf("背包沒有這張卡QAQ");
        nl();
        pause();
        return;
    }
}

int countPackageCard()
{
    int result = 0;
    int i = 0;

    for(i=0; i<USERPACKAGESIZE; i++)
    {
        if(userPack[i] != NULL)
        {
            result += userPack[i]->countInPack;
        }
    }

    return result;
}

void viewPackageCard()
{
    int i = 0;
    int j = 0;

    printf("數量    稀有度     編號       名稱        血量    攻擊     防禦   ");
    nl();

    for(i=0; i<USERPACKAGESIZE; i++)
    {
        if(userPack[i] != NULL)
        {
            printf("[%02d] ",
                   userPack[i]->countInPack);

            if(userPack[i]->cardInPack->rare > 0)
            {
                for(j=0; j<(userPack[i]->cardInPack->rare); j++)
                {
                    printf("★");
                }
                for(j=0; j<(6-(userPack[i]->cardInPack->rare)); j++)
                {
                    printf("  ");
                }
            }
            else if(userPack[i]->cardInPack->rare <= 0)
            {
                printf("★★限定★★");
            }

            printf(" <NO.%2d> %-12s  HP:%4d ATK:%4d DEF:%4d",
                   userPack[i]->cardInPack->id,
                   userPack[i]->cardInPack->name,
                   userPack[i]->cardInPack->hp,
                   userPack[i]->cardInPack->atk,
                   userPack[i]->cardInPack->def);
            if(userPack[i]->isFavorite == 1)
            {
                printf(" [最愛]");
            }
            else if(userPack[i]->isFavorite == 2)
            {
                printf(" [永遠在一起]");
            }
            nl();
        }
    }
}

void PackageSelector(int theAnswer)
{
    if(theAnswer == 99) return;
    else if(theAnswer == 0)
    {
        addFavorite(ask("要將哪張卡片 加入/取消 最愛呢?(請輸入卡片標號，輸入-1取消)"));
        showPackage();
    }
    else if(theAnswer == 1)
    {
        deleteCard(ask("要販售哪張卡片呢?(請輸入卡片標號，輸入-1取消)"));
        showPackage();
    }
    else showPackage();
}

void cardCollect(int theId)
{
    int i = 0;

    for(i=0; i<USERPACKAGESIZE; i++)
    {
        if(userPack[i] != NULL)
        {
            if(userPack[i]->cardInPack->id == theId)
            {
                (userPack[i]->countInPack)++;
                return;
            }
        }
    }

    userPack[theId] = malloc(sizeof(Package));
    userPack[theId]->cardInPack = malloc(sizeof(Card));
    hasMallocCardCollect++;

    userPack[theId]->cardInPack->id = totalPool[theId]->id;
    strcpy(userPack[theId]->cardInPack->name, totalPool[theId]->name);
    userPack[theId]->cardInPack->hp = intFlow(totalPool[theId]->hp, 0.1);
    userPack[theId]->cardInPack->atk = intFlow(totalPool[theId]->atk, 0.1);
    userPack[theId]->cardInPack->def = intFlow(totalPool[theId]->def, 0.1);
    userPack[theId]->cardInPack->type = totalPool[theId]->type;
    userPack[theId]->cardInPack->rare = totalPool[theId]->rare;
    userPack[theId]->countInPack = 1;
    userPack[theId]->isFavorite = 0;
}

int sellGetMoney(int rare)
{
    switch(rare)
    {
    case 1:
        {
            return intFlow(10, 0.5);
        }break;
    case 2:
        {
            return intFlow(20, 0.5);
        }break;
    case 3:
        {
            return intFlow(50, 0.5);
        }break;
    case 4:
        {
            return intFlow(100, 0.5);
        }break;
    case 5:
        {
            return intFlow(200, 0.5);
        }break;
    case 0:
        {
            return 0;
        }break;
    }
}
