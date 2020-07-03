#include <iostream>
#include "game.h"
#include "gameobject.h"

using namespace std;

Human player(0, 0, 1); // player  initial x : 0, y : 0, | can move 1 block & user input direction
Monster mob(5, 5, 2);  // monster initial x : 5, y : 5  | can move 2 block & random direction
Food jelly(9, 9, 1);   // food    initial x : 9, y : 9	| can move 1 block & random direction

void GameManager::drawMap() { // set object's shape into each location
	map[jelly.getX()][jelly.getY()] = jelly.getShape();
	map[player.getX()][player.getY()] = player.getShape();
	map[mob.getX()][mob.getY()] = mob.getShape();

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++)
			cout << map[i][j];
		cout << endl;
	}
}

void GameManager::moveAll() { // move all object & set prior location shape '-'
	map[jelly.getX()][jelly.getY()] = '-';
	map[player.getX()][player.getY()] = '-';
	map[mob.getX()][mob.getY()] = '-';

	// change all coordinate here
	player.move();
	mob.move();
	jelly.move();
}

bool GameManager::isCollide() { // determine which object win or continue the game
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