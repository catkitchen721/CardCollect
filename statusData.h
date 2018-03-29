#ifndef __STATUSDATA_H__
#define __STATUSDATA_H__

#define PASSWORD 131463632020
#define USERPACKAGESIZE 50
#define USERPACKAGECOUNTSIZE 200
#define TOTALPACKAGESIZE 50
#define CURRENTALLCARD 6
#define CARDPOOLSIZE 50

typedef struct card
{
    int id;
    int hp;
    int atk;
    int def;
    int type;
    int rare;
    char name[20];
}Card;

typedef struct pack
{
    Card *cardInPack;
    int countInPack;
    int isFavorite;
}Package;

typedef struct gall
{
    int id;
    char textNO[20];
    char textName[50];
    char textLore[100];
    char textHp[20];
    char textATK[20];
    char textDEF[20];
    char textType[20];
}Gallery;

int hasAskGoldfinger;
int goldfinger;
char username[20];
int money;
double five;
int fiveget;
double four;
int fourget;
double three;
int threeget;
int gatchaticket;
int hasMeetCard[TOTALPACKAGESIZE];
Package *userPack[USERPACKAGESIZE];
Card *totalPool[TOTALPACKAGESIZE];
Gallery *allGallery[TOTALPACKAGESIZE];

#endif // __STATUSDATA_H__
