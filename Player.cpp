#include "Player.h"

#include <vector>
 
using namespace std;

class Player {
  Player() {
   this._health = 10;
   this._stat1 = 2;
   this._stat2 = 3;
   this._statt3 = 1;
   this._items = *(new vector<string>);
   this._equipped = *(new vector<string>);

  }
  ~Player() {}

  int getHealth() {return this._health; }
  int getStat1() { return this._stat1; }
  int getStat2() {return this._stat2;}
  int getStat3() {return this._stat3;}
  vector<string> getAllItems() {return this._items;}
  vector<string> getEquipped() {return this._equipped;}
  
  void takeDamage(int a) {this._health -= a; }
//stat functions?  

  void addItemToBag(string item) {this._items.push_back(item); }
  void equipItem(string item) { 
           //logic for unequipping if it conflicts 
      }
}
