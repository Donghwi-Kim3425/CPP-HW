#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player {
	string name;
public:
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
};

class GamblingGame {
	Player player[2];
public:
	void play();
	bool gameEnd = false;
	~GamblingGame();
};

void GamblingGame::play() {
	cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
	cout << "첫번째 선수 이름 >> ";
	string name1, name2;
	cin >> name1;
	player[0].setName(name1);
	cout << "두번째 선수 이름 >> ";
	cin >> name2;
	player[1].setName(name2);
	srand((unsigned)time(0));
	int randNum[3];
	while (!gameEnd) {
		for (int i = 0; i < 2; i++) {
			cout << player[i].getName() << ": <Enter>";
			cin.ignore();
			cout << endl;
			cout << "\t\t";
			for (int j = 0; j < 3; j++) {
				randNum[j] = rand() % 3;
				cout << randNum[j] << "\t";
			}

			if (randNum[0] == randNum[1] && randNum[1] == randNum[2]) {
				cout << player[i].getName() << "님 승리!!" << endl;
				gameEnd = true;
				break;
			}
			else {
				cout << "아쉽군요!" << endl;
			}
		}
	}
}


int main() {
	GamblingGame game;
	game.play();
	
	return 0;
}
