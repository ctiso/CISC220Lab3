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
	board=new char*[3];
		for(int i=0;i<3;i++){
			board[i]=new char[3];
		}
	player1 = play1;
	player2 = play2;
	this->Initialize();

}

void TicTacToe::Initialize() {
	for (int row = 0; row<3;row++) {
			for (int col = 0; col<3;col++) {
				this ->board[row][col] = '_';
			}
	}
}
TicTacToe::~TicTacToe(){
	delete board;
	cout<<"Game has been Destroyed"<<endl;
}
void TicTacToe::Print() {
	for (int row = 0; row<3;row++) {
				for (int col = 0; col<3;col++) {
					cout<< board[row][col]<<"\t";
				}
				cout<<endl;
				cout<<endl;
		}
	}

bool TicTacToe::isBoardFull() {
	int count = 0;
		for (int row = 0; row<3;row++) {
			for (int col = 0; col<3;col++) {
				if (board[row][col] == 'x' || board[row][col]=='o') {
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
			if (board[horz][0] == board[horz][1] && board[horz][0] == board[horz][2] && board[horz][0] != '_') {
				check = true;
			}
		}
		for (int vert = 0; vert<3;vert++) {
			if (board[0][vert] == board[1][vert] && board[0][vert] == board[2][vert] && board[0][vert] != '_') {
				check = true;
			}
		}

		if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != '_') {
			check = true;
		}
		if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != '_') {
			check = true;
	}
	else {
		cout<<"You must enter an 'x' or 'o'"<<endl;
	}
	return check;
	}
}
void TicTacToe::Play(char x) {
	int row;
	int col;
	bool gameover = false;
	char winner = 'a';
	while (gameover == false) {
		if (isBoardFull() == true) {
					gameover = true;
					cout<<"Draw"<<endl;
					break;
				}
		if (WinCheck('x') == true) {
			gameover = true;
			winner = 'x';
			break;
		}
		cout<< player1<<" please input a row: "<<endl;
		cin >> row;
		cout<<player1<<" please input a column: "<<endl;
		cin >> col;
		if (board[row][col] == '_') {
			for (int i = 0;i<3;i++) {
				for (int j = 0;j<3;j++) {
					if (board[i][j] == board[row][col]) {
						board[row][col] = 'x';
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
		if (board[row][col] == '_') {
			for (int i = 0;i<3;i++) {
				for (int j = 0;j<3;j++) {
					if (board[i][j] == board[row][col]) {
						board[row][col] = 'o';
					}
					}
				}
			Print();
			}
		else {
			cout<<"This place is already taken"<<endl;
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



