class GameManager {
	char map[10][20] = { '-' }; // x : 0~9, y : 0~19
public:
	GameManager() { // initial map draw
		for (int x = 0; x < 10; x++)
			for (int y = 0; y < 20; y++)
				map[x][y] = '-';
	};
	void drawMap(); // draw a map with object's location
	void moveAll(); // move 4 directions(Up, Left, Down, Right) all object
	bool isCollide(); // return true false if this* has collided other object
};
