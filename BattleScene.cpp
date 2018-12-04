#include "BattleScene.h"

BattleScene::BattleScene(Room * room, Player * player) {
	this->room = room;
	this->enemy = buildEnemy().get();
	this->player = player;
	this->isPlayerTurn = true;
	battleLog = "A wild " + enemy->getName() + " has appeared!\n";
	updateStats();
}

BattleScene::~BattleScene() {
	if (player->getHealth() > 0) {
		battleLog = "You won.\n";
		delete enemy;

		int itemDrop = rand() % 5;

		if (itemDrop > 2) {
			player->addItemToBag(buildItem().get());
		}
	} else {
		battleLog = "Game Over.\n";
	}
}

string BattleScene::promptAttack() {
	return "Physical Attack\nMagic Attack\nOpen Inventory";
}

string BattleScene::attack(string attackType) {
	if (isPlayerTurn) {
		if (attackType == "phys") {
			player->physAttack();
			enemy->takeDamage(player->physAttack());
		}
		else if (attackType == "mag") {
			player->magAttack();
			enemy->takeDamage(player->magAttack());
		}

		battleLog = player->getLog() + enemy->getLog();
		updateStats();
		isPlayerTurn = false;
	}

	else {
		enemy->attackDecision();
		player->takeDamage(enemy->attackDecision());
		battleLog = player->getLog() + enemy->getLog();
		isPlayerTurn = true;

		if (enemy->getHealth() > 0) {
			battleLog += promptAttack();
		}
		updateStats();
	}

	return battleLog;
}

void BattleScene::updateStats() {
	statsLog = "Player HP: " + player->getHealth() + string(" ") + enemy->getName() + string("\n HP: ");
	statsLog += enemy->getHealth() + "\n";
}

string BattleScene::displayStats() {
	return statsLog;
}

string BattleScene::displayBattleLog() {
	return battleLog;
}

vector<Item> BattleScene::openInventory() {
	return player->getAllItems(); //change!!!
}




