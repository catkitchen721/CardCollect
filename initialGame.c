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

void initialCardPoolZero()
{
    int i = 0;
    for(i=0; i<USERPACKAGESIZE; i++)
    {
        userPack[i] = NULL;
    }

    i = 0;
    for(i=0; i<TOTALPACKAGESIZE; i++)
    {
        totalPool[i] = NULL;
    }
}

void initialTotalPackage()
{
    if(loadTotalCard = fopen("card.datafile","r"))
    {
        int i = 0;

        for(i=0; i<TOTALPACKAGESIZE; i++)
        {
            totalPool[i] = malloc(sizeof(Card));
        }

        i = 0;

        while(fscanf(loadTotalCard,"%d%s%d%d%d%d%d",
                     &totalPool[i]->id,
                     &totalPool[i]->name,
                     &totalPool[i]->hp,
                     &totalPool[i]->atk,
                     &totalPool[i]->def,
                     &totalPool[i]->type,
                     &totalPool[i]->rare) != EOF)
        {
            i++;
        }

        fclose(loadTotalCard);
    }
    else
    {
        printf("卡片資料檔案損毀!!");
        nl();
        pause();
        return;
    }
}

void loadGalleryInFile()
{
    if(loadGallery = fopen("gallery.datafile","r"))
    {
        int i = 0;

        for(i=0; i<TOTALPACKAGESIZE; i++)
        {
            allGallery[i] = malloc(sizeof(Gallery));
        }

        i = 0;

        while(fscanf(loadGallery,"%d%s%s%s%s%s%s%s",
                     &allGallery[i]->id,
                     &allGallery[i]->textNO,
                     &allGallery[i]->textName,
                     &allGallery[i]->textLore,
                     &allGallery[i]->textHp,
                     &allGallery[i]->textATK,
                     &allGallery[i]->textDEF,
                     &allGallery[i]->textType) != EOF)
        {
            i++;
        }

        fclose(loadGallery);
    }
    else
    {
        printf("圖鑑檔案損毀!!");
        nl();
        pause();
        return;
    }
}

void initialAll()
{
    initialCardPoolZero();
    initialTotalPackage();
    loadGalleryInFile();
    money += 200;
}
