/*
 * Lab3.cpp
 *
 *  Created on: Sep 12, 2019
 *      Author: tisoc and Bobby Stahl
 */

#include<iostream>
using namespace std;
#include "header.hpp"
#include <stdlib.h>
#include <time.h>
#include <cmath>


class MathQuiz{
	int testNum;
	int answerRight;
	int QuestionTotal;

public:
	MathQuiz(int x){
		testNum=x;
		answerRight=0;
		QuestionTotal=0;
	}
	void Question(){
		int test=rand()%12+1;
		cout<<"What is "<<testNum<<" multiplied by "<<test<<endl;
		int answer;
		cin >> answer;
		if(answer==test*testNum){
			cout<<"Correct!"<<endl;
			answerRight++;
			QuestionTotal++;
		}
		else{
			cout<<"Wrong :("<<endl;
			QuestionTotal++;
		}
	}
	void Grade(){
		cout<<"You got "<<answerRight<<" out of "<<QuestionTotal<<endl;
	}
};
class HanningWindow{
	int windowsize;
	int* array;
	int arrSize;
	int* filtArr;

public:
	HanningWindow(int win,int* arr,int size,int* filtered);
	int WeightAvg(int arrIndex);
	void PrintArray(bool x);
	void WindowSize(int x);
	void FilterArr();
	void Graph(bool x);
};
#include<iostream>
using namespace std;
void Stars();
int main(){
	srand(time(NULL));
	MathQuiz Test(3);//sets the number to be quized om
	for(int i=0;i<10;i++){	//Runs a multiplication test with the number given and goes through 10 times
		Test.Question();
	}
	Test.Grade();//prints out score of quiz


	int normal[7]={1,4,5,6,3,7,8};
	int other[7];
	HanningWindow HanArr(3,normal,7,other);//initializes a hanning window object
	HanArr.WeightAvg(3);//gives the weighted average of the window at the index put into it
	HanArr.FilterArr();//makes the array of weighted averages for the whole array
	Stars();
	HanArr.PrintArray(true);//Prints filtered array when true
	Stars();
	HanArr.PrintArray(false);//Prints original array when false
	Stars();
	HanArr.Graph(true);//graphs filtered array when true
	Stars();
	HanArr.Graph(false);//graphs original array when true
	Stars();
	HanArr.WindowSize(5);//This changes the window size to whatever number put in
	HanArr.PrintArray(true);//Dont need to recall filter arr because WindowSize does it already
	Stars();
	HanArr.PrintArray(false);
	Stars();
	HanArr.Graph(true);
	Stars();
	HanArr.Graph(false);

	TicTacToe Game("Bobby","Chris");
	Game.Initialize();//Initializes the game board to have underscores
	Game.Print();//Prints out the gameboard
	Game.Play('x');//The game starts
	Stars();
	Box Box1(3.3, 1.2, 1.5);//Initializes the boxes
	Box Box2(8.5, 6.0, 2.0);
	Box Box3 = Box1 + Box2;//this comes from the lab sheet
	double volume = Box3.getVolume();
	cout << "Vol. 2of Box3 : " << volume<<endl;
	Box1==Box2;//Shows that == does the opposite of what it normally does

	return 0;
}
HanningWindow::HanningWindow(int win,int* arr, int size, int* filtered){
	windowsize=win;
	array=arr;
	arrSize=size;
	filtArr=filtered;
}
int HanningWindow::WeightAvg(int arrIndex){
	int avg=0;
	if(arrIndex<(windowsize/2) || arrIndex>((arrSize-1)-(windowsize/2))){
		return 0;
	}
	else{
		int step=2;
		int IndexWeight=(windowsize/2)+1;
		avg+=array[arrIndex]*IndexWeight;
		for(int i=arrIndex+1;i<(arrIndex+(windowsize/2));i++){
			IndexWeight--;
			avg+=IndexWeight*array[i];
			avg+=IndexWeight*array[i-step];
			step+=2;
		}
		int Weightaverage=avg/windowsize;
		return Weightaverage;
	}
}
void HanningWindow::WindowSize(int x){
	if(x%2 !=0){
		windowsize=x-1;
	}
	else{
		windowsize=x;
	}
	FilterArr();
}
void HanningWindow::FilterArr(){
	for(int i=0;i<arrSize;i++){
		filtArr[i]=WeightAvg(i);
	}
}
void HanningWindow::Graph(bool x){
	int* graphArray;
	if(x==true){
		graphArray=filtArr;
	}
	else{
		graphArray=array;
	}
	int high=graphArray[0];
	for(int i=0;i<arrSize;i++){
		if(high<graphArray[i]){
			high=graphArray[i];
		}
	}
	int low=graphArray[0];
	for(int i=0;i<arrSize;i++){
		if(low>graphArray[i]){
				low=graphArray[i];
			}
		}

	int distance=high-low;
	for(int i=0;i<=distance;i++){
			cout<<high-i<<":";
			int number=high-i;
			for(int j=0;j<arrSize;j++){
				if(graphArray[j]==number){
					cout<<"*";
				}
				else{
					cout<<" ";
				}
			}
			cout<<endl;
		}
}
void HanningWindow::PrintArray(bool x){
	if(x==true){
		for(int i=0;i<arrSize;i++){
			cout<<filtArr[i]<<",";
		}
		cout<<endl;
	}
	else{
	for(int i=0;i<arrSize;i++){
				cout<<array[i]<<",";
			}
			cout<<endl;
	}
}
void Stars(){
	cout<<"********"<<endl;
}
