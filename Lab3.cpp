/*
 * Lab3.cpp
 *
 *  Created on: Sep 12, 2019
 *      Author: tisoc
 */

#include<iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

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
		cout<<"You got "<<answerRight<<" out of "<<QuestionTotal;
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
	void FilterArr(int* arr, int length);
	void Graph(bool x);
};
#include<iostream>
using namespace std;

int main(){
	MathQuiz Test(3);
	for(int i=0;i<10;i++){
		Test.Question();
	}
	Test.Grade();
	return 0;
}
HanningWindow::HanningWindow(int win,int* arr, int size, int* filtered){
	windowsize=win;
	array=arr;
	arrSize=size;
	filtArr=filtered;
}
int HanningWindow::WeightAvg(int arrIndex){
	if(arrIndex<windowsize/2 || arrIndex>(arrSize-1)/2){

	}
}
void HanningWindow::WindowSize(int x){
	if(x%2 !=0){
		windowsize=x-1;
	}
	else{
		windowsize=x;
	}
	//Not done, need to call function 2. need to fix function 2
}
void HanningWindow::FilterArr(int* arr, int length){

}
