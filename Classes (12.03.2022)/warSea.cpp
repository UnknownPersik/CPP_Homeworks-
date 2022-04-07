#include <iostream>
#include <list>

using namespace std;

class Board {
public:
	Cell board[8][8];
	void addShip(Ship x) {
	}
};

class Cell {
public:
	int x;
	int y;
	bool isEmptyCell;
};

class Ship {
public:
	int length;
	list <Cell> position;
	bool isDead() {
		return 0;
	}
};

class Game {
public:
	bool Shoot(Cell c) {
		return 0;
	}

};

int main()
{
	return 0;
}
