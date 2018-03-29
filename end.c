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

void endGame(char instru[50])
{
    printf("%s",instru);
    nl();
    int theAnswer = 0;
    scanf("%d",&theAnswer);
    if(theAnswer == 1)
    {
        freeMemory();
        cls();
        printf("結束遊戲... <任意鍵結束遊戲>");
        exit(1);
    }
    else
    {
        return;
    }
}

void freeMemory()
{
    int i = 0;

    for(i=0;i<TOTALPACKAGESIZE;i++)
    {
        free(totalPool[i]);
    }

    i = 0;

    for(i=0;i<TOTALPACKAGESIZE;i++)
    {
        free(allGallery[i]);
    }

    if(hasMallocCardCollect != 0)
    {
        i = 0;

        for(i=0;i<USERPACKAGESIZE;i++)
        {
            if(userPack[i] != NULL)
            {
                free(userPack[i]->cardInPack);
                free(userPack[i]);
            }
        }
    }
}
