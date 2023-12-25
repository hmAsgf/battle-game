#include <iostream>
#include "utils.h"
using namespace std;

main()
{
  int opsi;

  do{
    cout<<"=== BATTLE GAME ===\n";
    cout<<"[1] CREATE CHARACTER\n";
    cout<<"[2] VIEW CHARACTER\n";
    cout<<"[3] FARMING\n";
    cout<<"[4] BATTLE\n";
    cout<<"-------------------\n";
    cout<<"MENU: ";
    cin>>opsi;
    cin.ignore();
    switch(opsi)
    {
      case 1:
        createCharacter();
        break;
      case 2:
        viewCharacter();
        break;
      case 4:
        battle();
        break;
    }
  }while(opsi>0 && opsi<5);
}
