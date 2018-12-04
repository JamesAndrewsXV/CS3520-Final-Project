#include "BattleScene.h"

BattleScene::BattleScene(Room * room, Player * player) {
	this->room = room;
	if (room->bossRoom) {
		this->enemy = buildBoss();
	}
	else {
		this->enemy = buildEnemy();
	}

	this->player = player;
	this->isPlayerTurn = true;
	battleLog = "A wild " + enemy->getName() + " has appeared!\n";
	updateStats();
}

BattleScene::~BattleScene() {
	if (player->getHealth() > 0) {
		battleLog = "You won.\n";

		int itemDrop = rand() % 5;

		if (itemDrop > 2) {
			player->addItemToBag(buildItem().get());
		}
	}
	else {
		battleLog = "Game Over.\n";
	}
}

string BattleScene::promptAttack() {
	return "\nPhysical Attack(z)\nMagic Attack(x)\nOpen Inventory(sorry no)\n";
}

string BattleScene::attack(string attackType) {
	if (this->isPlayerTurn) {
		if (attackType == "phys") {
			Attack playerAttack = player->physAttack();
			enemy->takeDamage(playerAttack);
		}
		else if (attackType == "mag") {
			Attack playerAttack = player->magAttack();
			enemy->takeDamage(playerAttack);
		}


		battleLog = player->getLog() + enemy->getLog();

		if (enemy->getHealth() == 0) {
			battleLog = battleLog  + enemy->getName() + " has perished!";
			this->room->over = true;
			updateStats();
			return battleLog;
		}


		updateStats();
		isPlayerTurn = false;
		attack("");
	}

	else {
		Attack enemyAttack = enemy->attackDecision();
		player->takeDamage(enemyAttack);
		battleLog += enemy->getLog() + player->getLog();
		isPlayerTurn = true;
		if (player->getHealth() == 0) {
			battleLog += "\n You died!";
			this->room->over = true;
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




