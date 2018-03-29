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

void loadData()
{
    FILE *openSave = NULL;

    if(openSave = fopen("save.dat","r") != NULL)
    {
        //
    }
    else
    {
        if(!goldfinger)
        {
            cls();
            printf("你的名字是?(10個中文字以內，20個英文字、數字以內)");
            nl();
            scanf("%s",username);
            printf("%s? 尼豪~~",username);
            nl();
            pause();
        }
    }

    fclose(openSave);

    if(goldfinger == 1)     //金手指福利
    {
        money = 999999;
        strcpy(username,"##GoldFinger##");

        totalPool[49] = malloc(sizeof(Card));

        totalPool[49]->id = 49;
        strcpy(totalPool[49]->name, "綿木同學");
        totalPool[49]->hp = 6333;
        totalPool[49]->atk = 633;
        totalPool[49]->def = 633;
        totalPool[49]->type = 0;
        totalPool[49]->rare = 0;

        allGallery[49] = malloc(sizeof(Gallery));

        allGallery[49]->id = 49;
        strcpy(allGallery[49]->textNO, "NO.49");
        strcpy(allGallery[49]->textHp, "HP:6333");
        strcpy(allGallery[49]->textName, "綿木同學");
        strcpy(allGallery[49]->textLore, "--姆咪~姆咪姆咪~老師也一起唱吧!");
        strcpy(allGallery[49]->textATK, "ATK:633");
        strcpy(allGallery[49]->textDEF, "DEF:633");
        strcpy(allGallery[49]->textType, "混沌族");

        userPack[49] = malloc(sizeof(Package));
        userPack[49]->cardInPack = malloc(sizeof(Card));
        hasMallocCardCollect++;

        userPack[49]->cardInPack->id = 49;
        strcpy(userPack[49]->cardInPack->name, "綿木同學");
        userPack[49]->cardInPack->hp = 6333;
        userPack[49]->cardInPack->atk = 633;
        userPack[49]->cardInPack->def = 633;
        userPack[49]->cardInPack->type = 0;
        userPack[49]->cardInPack->rare = 0;
        userPack[49]->countInPack = 1;
        userPack[49]->isFavorite = 1;

        hasMeetCard[49] = 1;
    }
}
