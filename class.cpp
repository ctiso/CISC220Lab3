/*
 * class.cpp
 *
 *  Created on: Sep 18, 2019
 *      Author: tisoc
 */
#include "header.hpp"
#include<iostream>
using namespace std;

TicTacToe::TicTacToe(string play1, string play2) {
	arr[3][3];
	player1 = play1;
	player2 = play2;
}

void TicTacToe::Initialize() {
	for (int row = 0; row<3;row++) {
			for (int col = 0; col<3;col++) {
				arr[row][col] = '_';
			}
	}
}

void TicTacToe::Print() {
	for (int row = 0; row<3;row++) {
				for (int col = 0; col<3;col++) {
					cout<< arr[row][col]<<"\t";
				}
				cout<<endl;
				cout<<endl;
		}
	}

bool TicTacToe::isBoardFull() {
	int count = 0;
		for (int row = 0; row<3;row++) {
			for (int col = 0; col<3;col++) {
				if (arr[row][col] == 'x' || arr[row][col]=='o') {
					count++;
				}
			}
		}
		if (count == 9) {
					return true;
				}
		else
			return false;
}
bool TicTacToe::WinCheck(char x) {
	bool check = false;
	if (x=='x'||x=='o') {
		for (int horz = 0; horz<3;horz++) {
			if (arr[horz][0] == arr[horz][1] && arr[horz][0] == arr[horz][2] && arr[horz][0] != '_') {
				check = true;
			}
		}
		for (int vert = 0; vert<3;vert++) {
			if (arr[0][vert] == arr[1][vert] && arr[0][vert] == arr[2][vert] && arr[0][vert] != '_') {
				check = true;
			}
		}
		for (int diag = 0; diag<3;diag++) {
			if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] != '_') {
				check = true;
		}
		}
	}
	else {
		cout<<"You must enter an 'x' or 'o'"<<endl;
	}
	return check;
}
void TicTacToe::Play(char x) {
	int row;
	int col;
	bool gameover = false;
	char winner = 'y';
	while (gameover == false) {
		if (WinCheck('x') == true) {
			gameover = true;
			winner = 'x';
			break;
		}
		cout<< player1<<" please input a row: "<<endl;
		cin >> row;
		cout<<player1<<" please input a column: "<<endl;
		cin >> col;
		if (arr[row][col] == '_') {
			for (int i = 0;i<3;i++) {
				for (int j = 0;j<3;j++) {
					if (arr[i][j] == arr[row][col]) {
						arr[row][col] = 'x';
						}
						}
			}
			Print();
			}
		else {
			cout<< "This place is already taken" << endl;
		}
		if (WinCheck('o') == true) {
			gameover = true;
			winner = 'o';
			break;
		}
		cout<< player2 <<" please input a row: "<<endl;
		cin >> row;
		cout<<player2<<" please input a column: "<<endl;
		cin >> col;
		if (arr[row][col] == '_') {
			for (int i = 0;i<3;i++) {
				for (int j = 0;j<3;j++) {
					if (arr[i][j] == arr[row][col]) {
				arr[row][col] = 'o';
					}
					}
				}
			Print();
			}
		else {
			cout<<"This place is already taken"<<endl;
		}
		if (isBoardFull() == true) {
			gameover = true;
			cout<<"Draw"<<endl;
			break;
		}
	}
		if (winner == 'x') {
		cout<< player2 <<" wins"<<endl;
		}
		if (winner == 'o') {
			cout<< player1 <<" wins"<<endl;
	}
}

Box::Box(double l, double b, double h) {
 length = l;
 breadth = b;
 height = h;
}
double Box::getVolume() {
 return length * breadth * height;
}
Box Box::operator+(Box b) { //Overload:add 2 Box objects.
 Box box(length,breadth,height);
 box.length = length + b.length;
 box.breadth = breadth + b.breadth;
 box.height = height + b.height;
 return box;
}
bool Box::operator==(Box a){
	Box box(length,breadth,height);
	if(box.length ==a.length && box.breadth ==a.breadth && box.height ==a.height){
		cout<<"false"<<endl;
		return false;
	}
	else{
		cout<<"true"<<endl;
		return true;
	}
}



