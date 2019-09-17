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
