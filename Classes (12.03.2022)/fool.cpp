#include <iostream>
#include <list>
#include <string>

using namespace std;

class Dice {
public:
	list <Card> dice;
};

class hangUP {
public:
	list <Card> hangUP;
};

class Card {
public:
	int number; //Номер карты от 6 до 14 (11 - 14 это валет, дама, король, туз)
	string trump; //Масть карты
	string suit; //Козырь
};

class Player {
public:
	list <Card> cards;
	void addCard(Card card){}
	void deleteCard(Card card) {}
	void putCardOnBoard(Card card){}
};

class Game {
public:
	bool whoLosePreviousRound(Player player1, Player player2) {} // Возвращает true если проиграл 2 игрок. False если проиграл 1 игрок
	bool whoWinRound(Player player1, Player player2) {} // По аналогии с предыдущей функцией (в плане возвращаемых значений)
	void step(Player player1, Player player2, Card card1, Card card2) {
		if (whoLosePreviousRound) {
			Player firstStep = player1;
			Player secondStep = player2;
		}
		else {
			Player firstStep = player2;
			Player secondStep = player1;
		}
		if (whoWinRound) {
			player2.addCard(card1);
			player2.deleteCard(card1);
		}
	}
};

int main()
{
	return 0;
}
