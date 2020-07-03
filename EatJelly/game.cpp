#include <iostream>
#include "game.h"
#include "gameobject.h"

using namespace std;

Human player(0, 0, 1);
Monster mob(5, 5, 2);
Food jelly(9, 9, 1);

void GameManager::drawMap() {
	map[jelly.getX()][jelly.getY()] = jelly.getShape();
	map[player.getX()][player.getY()] = player.getShape();
	map[mob.getX()][mob.getY()] = mob.getShape();

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++)
			cout << map[i][j];
		cout << endl;
	}
}

void GameManager::moveAll() {
	map[jelly.getX()][jelly.getY()] = '-';
	map[player.getX()][player.getY()] = '-';
	map[mob.getX()][mob.getY()] = '-';

	player.move();
	mob.move();
	jelly.move();
}

bool GameManager::isCollide() {
	if (player.collide(&mob)) {
		cout << "Monster is Winner!!" << endl;
		return true;
	}
	else if (player.collide(&jelly)) {
		cout << "Human is Winner!!" << endl;
		return true;
	}
	else return false;
}