#include "BattleScene.h"

BattleScene::BattleScene(Room * r, Enemy * e, Player * p) {
	room = r;
	enemy = e;
	player = p;
	isPlayerTurn = true;
}

BattleScene::~BattleScene() {
	if (player->currHP > 0) {
		battleLog << "You won." << endl;
	} else {
		battleLog << "Game Over." << endl;
	}
}




