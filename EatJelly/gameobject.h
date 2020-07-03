#include <iostream>
#include <cstdlib> // for rand() srand()
#include <ctime> // for random srand seed

using namespace std;

class GameObject {
protected:
	int distance; // Distance the current object can move
	int x, y; // x : row, y : column
public:
	GameObject(int startX, int startY, int distance) : x(startX), y(startY) {
		this->distance = distance;
		srand(time(0));
		rand();
	}
	virtual ~GameObject() {}; // virtual destructor
	virtual void move() = 0; // Set x, y after moving
	virtual char getShape() = 0; // return current object's shape, Human : 'P', Monster : 'M', Food : '@'

	int getX() { return x; } // return current object's x ( map's row )
	int getY() { return y; } // return current object's y ( map's column )
	bool collide(GameObject* p) { // return bool if this* bumped into parameter.
		if (this->x == p->getX() && this->y == p->getY())
			return true;
		else
			return false;
	}
};

class Human : public GameObject {
	char shape;
	Human(int x, int y, int distance) : GameObject(x, y, distance) {
		this->shape = 'P';
	}
	virtual ~Human() {};
	virtual void move() { // player move one block by w a s d
		char direction;

		cout << "Up(w), Left(a), Down(s), Right(d) >> ";
		cin >> direction;

		if (direction == 'w') {
			this->x -= this->distance;
			if (this->getX() < 0) this->x = 9;
		}
		else if (direction == 'a') {
			this->y -= this->distance;
			if (this->getY() < 0) this->y = 19;
		}
		else if (direction == 's') {
			this->x += this->distance;
			if (this->getX() > 9) this->x = 0;
		}
		else if (direction == 'd') {
			this->y += this->distance;
			if (this->getY() > 19) this->y = 0;
		}
		else {}
	}
	virtual char getShape() { return this->shape; } // return this* shape for map drawing
};

enum DIR { UP, LEFT, DOWN, RIGHT };

class Monster : public GameObject {
	char shape;
public:
	Monster(int x, int y, int distance) : GameObject(x, y, distance) {
		this->shape = 'M';
	}
	virtual ~Monster() {};
	virtual void move() {
		int n = rand() / RAND_MAX * 3; // (0 ~ 1) * 3, up(0) left(1) down(2) right(3)

		switch (n) {
		case UP:
			this->x -= this->distance;
			if (this->getX() < 0) this->x = 9;
			break;
		case LEFT:
			this->y -= this->distance;
			if (this->getY() < 0) this->y = 19;
			break;
		case DOWN:
			this->x += this->distance;
			if (this->getX() > 9) this->x = 0;
			break;
		case RIGHT:
			this->y += this->distance;
			if (this->getY() > 19) this->y = 0;
			break;
		}
	}
	virtual char getShape() { return this->shape; }
};

class Food : public GameObject {
	char shape;
public:
	Food(int x, int y, int distance) : GameObject(x, y, distance) {
		this->shape = '@';
	}
	virtual ~Food() {};
	virtual void move() {
		int n = rand() / RAND_MAX * 3; // (0 ~ 1) * 3, up(0) left(1) down(2) right(3)

		switch (n) {
		case UP:
			this->x -= this->distance;
			if (this->getX() < 0) this->x = 9;
			break;
		case LEFT:
			this->y -= this->distance;
			if (this->getY() < 0) this->y = 19;
			break;
		case DOWN:
			this->x += this->distance;
			if (this->getX() > 9) this->x = 0;
			break;
		case RIGHT:
			this->y += this->distance;
			if (this->getY() > 19) this->y = 0;
			break;
		}
	}
	virtual char getShape() { return this->shape; }
};