#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>;

using namespace std;

string fireballStr = "Powerful FIREBALL!";
string windkickStr = "Spinning WINDKICK!";
string blockStr = "Defensive Block.";

//char possibleAtck[] = { 'a', 'w', 's', 'x', 'd', 'x', 'q' };

void PlayGame(char &input);
void DeduceAttack(char input1, char input2, char input3, char input4, int &atckValue, int &atckPow);
void ShowAttack(int atckValue, int atckPow);

int main() {
	char repeatProgram = 'y';
	do {
		system("CLS");
		//cout << "Welcome to Fighting Game Simulator 2013" << endl;
		PlayGame(repeatProgram);
	} while(repeatProgram == 'y');

	cout << "Thanks for playing!";

	getch();
	return 0;
}

void PlayGame(char &input) {
	char letter1, letter2, letter3, letter4, programInput;
	int attackPower, attackValue;

	cout << "Enter first button" << endl;
	cin >> letter1;

	cout << "Enter second button" << endl;
	cin >> letter2;

	cout << "Enter third button" << endl;
	cin >> letter3;

	cout << "Enter fourth button" << endl;
	cin >> letter4;

	DeduceAttack(letter1, letter2, letter3, letter4, attackValue, attackPower);
	ShowAttack(attackValue, attackPower);

	cout << "Do you want to combo attack again? (y/n)" << endl;
	cin >> programInput;

	input = programInput;
}

void DeduceAttack(char input1, char input2, char input3, char input4, int &atckValue, int &atckPow) {
	int attackValue = 0;

	if (input1 == 'a' && input2 == 'w' && input3 == 's' && (input4 == 'x' || input4 == 'd')) {
		attackValue = 1;
	}
	else if(input1 == 's' && (input2 == 'x' || input2 == 'q') && input3 == 'q' && (input4 >= 97 && input4 <= 122)) {
		attackValue = 2;
	}
	else
		attackValue = 3;

	int attackPower = 0;
	if(attackValue == 1 || attackValue == 2) {
		cout << endl << "Enter attack power for selected attack (0-10)" << endl;
		cin >> attackPower;

		if(attackPower < 0 || attackPower > 10)
			attackPower = 0;
	}
	else
		attackPower = 2;

	atckValue = attackValue;
	atckPow = attackPower;
}

void ShowAttack(int atckValue, int atckPow) {

	switch(atckValue) {
	case 1:
		cout << endl << fireballStr << endl;
		break;

	case 2:
		cout << endl << windkickStr << endl;
		break;

	default:
		cout << endl << blockStr << endl;
	}

	for(int i = 0; i < atckPow + 1; i++) {
		for(int j = 0; j < i; j++) {
			cout << "+";
		}
		cout << endl;
		Sleep(80);
	}

	cout << endl << "Chosen attack value is " << atckValue << " and attack power is " << atckPow << endl;
}