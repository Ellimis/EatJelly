class GameManager {
	char map[10][20] = { '-' }; // x : 0~9, y : 0~19
public:
	GameManager() {
		for (int x = 0; x < 10; x++)
			for (int y = 0; y < 20; y++)
				map[x][y] = '-';
	};
	void drawMap();
	void moveAll();
	bool isCollide();
};
