#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>

using namespace std;

string fileName;
std::stringstream ss;

//½«textÐ´ÈëfileName.txt
void write(string text) {
	cout << text<<endl;
}

string doubleToString(double number,int precision) {
	ss.str("");
	ss << std::setiosflags(std::ios::fixed) << std::setprecision(1) << number;
	return ss.str();
}

string doubleToString(double number) {
	return doubleToString(number, 1);
}

void G00(bool isValueAbsolute, bool isAssignSpeed, double axisValues[], int num, double speed) {
	string text = "";
	if (isValueAbsolute) {
		text += "G90 ";
	}
	else {
		text += "G91 ";
	}
	text += "G00";
	if (isAssignSpeed) {
		text += " P1";
	}
	string axisNames[] = { "X","Y","Z" };
	for (int i = 0; i < num; i++) {
		text += " ";
		text += axisNames[i] + doubleToString(axisValues[i]);
	}
	if (isAssignSpeed) {
		text += " F1=" + doubleToString(speed);
	}
	write(text);
}

int main() {
	double axisValues[] = { 1.0 , 2.0 , 3.0 };
	G00(true, true, axisValues, 3, 1000);
}