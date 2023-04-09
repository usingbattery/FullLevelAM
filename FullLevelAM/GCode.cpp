#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>

using namespace std;

string fileName;

//½«textÐ´ÈëfileName.txt
void write(string text) {
	//cout << text<<endl;
}

void G00(bool isValueAbsolute, bool isAssignSpeed, double values[], int num, double speed) {
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
	string axises[] = { "X","Y","Z" };
	std::stringstream ss;
	for (int i = 0; i < num; i++) {
		text += " ";
		ss << std::setiosflags(std::ios::fixed) << std::setprecision(1) << values[i];
		text += axises[i] + ss.str();
		ss.str("");
		cout << text << endl;
	}
	if (isAssignSpeed) {
		ss << std::setiosflags(std::ios::fixed) << std::setprecision(1) << speed;
		text += " F1=" + ss.str();
	}
	write(text);
}

int main() {
	double values[] = { 1.0 , 2.0 , 3.0 };
	G00(true, true, values, 3, 1000);
}