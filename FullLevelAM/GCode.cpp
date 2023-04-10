#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>

using namespace std;

const double doubleNull = 999;

string fileName;
std::stringstream stringTem;

//write text into fileName.txt
void write(string text) {
	cout << text << endl;
}

//accurate doubleToString
string doubleToString(double number, int precision) {
	stringTem.str("");
	stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(1) << number;
	return stringTem.str();
}

//default doubleToString
string doubleToString(double number) {
	return doubleToString(number, 1);
}

string appendIfNotNull(string text, string attribute, double value) {
	if (value != doubleNull) {
		text += attribute + doubleToString(value);
	}
	return text;
}

void G00( double x, double y, double z, double f1) {
	string text = "G00";
	if (f1!=doubleNull) {
		text += " P1";
	}
	text = appendIfNotNull(text, " X", x);
	text = appendIfNotNull(text, " Y", y);
	text = appendIfNotNull(text, " Z", z);
	text = appendIfNotNull(text, " F1", f1);
	write(text);
}

void G74(double x, double y, double z, double r, double p, double q, double f, double e, double k) {
	string text = "G74";
	text += " P1";
	text += " X" + doubleToString(x);
	text += " Y" + doubleToString(y);
	text += " Z" + doubleToString(z);
	text += " R" + doubleToString(r);
	text += " P" + doubleToString(p);
	if (f != doubleNull) {
		text += " Q" + doubleToString(q);
	}
	if (f != doubleNull) {
		text += " F" + doubleToString(x);
	}
	text += " E" + doubleToString(y);
	text += " K" + doubleToString(z);
	write(text);
}

void G76() {
	string text = "";
	write(text);
}

void G80() {
	string text = "";
	write(text);
}

void G81() {
	string text = "";
	write(text);
}

void G82() {
	string text = "";
	write(text);
}

void G83() {
	string text = "";
	write(text);
}

void G84() {
	string text = "";
	write(text);
}

void G85() {
	string text = "";
	write(text);
}

void G86() {
	string text = "";
	write(text);
}

void G87() {
	string text = "";
	write(text);
}

void G88() {
	string text = "";
	write(text);
}

void G89() {
	string text = "";
	write(text);
}

void G90() {
	string text = "";
	write(text);
}

void G91() {
	string text = "";
	write(text);
}

void G92() {
	string text = "";
	write(text);
}

void G92_1() {
	string text = "";
	write(text);
}

void G93() {
	string text = "";
	write(text);
}

void G94() {
	string text = "";
	write(text);
}

void G95() {
	string text = "";
	write(text);
}

void G96() {
	string text = "";
	write(text);
}

void G97() {
	string text = "";
	write(text);
}

void G98() {
	string text = "";
	write(text);
}

void G99() {
	string text = "";
	write(text);
}

void G120_1() {
	string text = "";
	write(text);
}

void G134() {
	string text = "";
	write(text);
}

void G135() {
	string text = "";
	write(text);
}

void G136() {
	string text = "";
	write(text);
}

void G137_1() {
	string text = "";
	write(text);
}

// test
int main() {
	G00(true, 1, 2, 3, 1000);
}