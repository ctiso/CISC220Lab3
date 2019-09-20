/*
 * header.hpp
 *
 *  Created on: Sep 18, 2019
 *      Author: tisoc
 */

#ifndef HEADER_HPP_
#define HEADER_HPP_
#include <string>

class TicTacToe {
	char** board;
	std::string player1;
	std::string player2;
public:
	TicTacToe(std::string p, std::string p2);
	void Initialize();
	void Print();
	bool isBoardFull();
	bool WinCheck(char x);
	void Person(char x);
	void Play(char x);
	~TicTacToe();
};


class Box {
 double length;
 double breadth;
 double height;
 public:
 	 Box (double l, double b, double h);
 	 double getVolume();
 	 Box operator+(Box b);
 	 bool operator==(Box a);
};




#endif /* HEADER_HPP_ */
