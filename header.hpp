/*
 * header.hpp
 *
 *  Created on: Sep 18, 2019
 *      Author: tisoc
 */

#ifndef HEADER_HPP_
#define HEADER_HPP_

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
