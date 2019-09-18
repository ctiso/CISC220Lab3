/*
 * class.cpp
 *
 *  Created on: Sep 18, 2019
 *      Author: tisoc
 */
#include "header.hpp"
#include<iostream>
using namespace std;

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



