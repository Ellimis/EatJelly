#include <iostream>
#include "game.h"

using namespace std;

int main() {
	GameManager Director;

	cout << "Human's Eat Food(Jelly) Game Start!" << endl;
	Director.drawMap();

	while (true) {
		Director.moveAll();
		Director.drawMap();

		if (Director.isCollide()) break;
	}

	return 0;
}