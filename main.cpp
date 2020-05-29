#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>


using namespace std;
int creatRand();
int creatRand2();
void createDoors();
void openDoor(int y);
bool playStick();
bool playSwitch();

int doors[3];


int main()
{
	bool strat;
	int times;
	cout << "Welcome to the Monty Hall Game. Which strategy would you like to play with?" << endl;
	cout << "Switch(0) or Stick(1)" << endl;
	cin >> strat;
	cout << "How many times would you like to play: ";
	cin >> times;
	if (strat) {
		double wins = 0;
		double losses = 0;
		double winProb;
		for (int i = 0; i < times; i++) {
			srand(time(0));
			//srand(time(0));
			bool result = playStick();
			if (result)
				wins++;
			else
				losses++;
			cout << "Iteration: " << i << endl;
		}
		winProb = wins / times;
		cout << "For " << times << " you only won " << wins << " times." << endl;
		cout << "The win probability is " << winProb << endl;
	}
	else {
		double wins = 0;
		double losses = 0;
		double winProb;
		for (int i = 0; i < times; i++) {
			srand(time(0));
			bool result = playSwitch();
			if (result)
				wins++;
			else
				losses++;
			cout << "Iteration: " << i << endl;
		}
		winProb = wins / times;
		cout << "For " << times << " you only won " << wins << " times." << endl;
		cout << "The win probability is " << winProb << endl;
	}

	return 0;
}

int creatRand() {
	return rand() % 2;
}

int creatRand2() {
	return rand() % 3;
}

void createDoors() {
	doors[0] = creatRand();
	if (doors[0] == 1) {
		doors[1] = 0;
		doors[2] = 0;
	}
	else {
		doors[1] = creatRand();
		if (doors[1] == 1)
			doors[2] = 0;
		else
			doors[2] = 1;
	}
}

void openDoor(int usr_choice) {
	int host_choice = creatRand2();
	while (host_choice == usr_choice || doors[host_choice] == 1)	host_choice = creatRand2();

	/*int x = y % 2 + 1;
	if (doors[x] == 1)
		x = y % 2 + 1;
	*/
	doors[host_choice] = 5;
}

bool playStick() {
	bool won = false;
	int choice = creatRand2();
	createDoors();
	openDoor(choice);
	if (doors[choice] == 1)
		won = true;
	return won;
}

bool playSwitch() {
	bool won = false;
	int choice = creatRand2();
	createDoors();
	openDoor(choice);
	int newChoice = choice%2 + 1;
	if (doors[newChoice] == 5)
		int newChoice = choice % 2 + 1;

	/*while (newChoice == choice || doors[newChoice] == 5) {
		newChoice = creatRand2();
	}*/
	if (doors[newChoice] == 1)
		won = true;
	return won;
}