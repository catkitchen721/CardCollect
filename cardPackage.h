#ifndef __CARDPACKAGE_H__
#define __CARDPACKAGE_H__

int hasMallocCardCollect;
char tempName[20];
int tempRare;

void showPackage();
void deleteCard(int theId);
void addFavorite(int theId);
int countPackageCard();
void viewPackageCard();
void PackageSelector(int theAnswer);
void cardCollect(int theId);
int sellGetMoney(int rare);

#endif // __CARDPACKAGE_H__
