#ifndef PLAYER_H
#define PLAYER_H

// #include "Items.h"

#include <vector>

class Player {

public:
  Player();
  ~Player();

  int getHealth();
  int getStat1();
  int getStat2();
  int getStat3();
  vector<string> getAllItems();
  vector<string> getEquipped();
  
  void takeDamage(int a);
//stat functions?  

  void addItemToBag(string item);
  void equipItem(string item);


private:
  int _health;
  int _stat1;
  int _stat2;
  int _stat3;
  vector<string> _items;
  vector<string> _equipped;

};


#endif
