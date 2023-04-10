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

string appendIfNotNull(string attribute, double value) {
	if (value != doubleNull) {
		return attribute + doubleToString(value);
	}
	return "";
}

void G00(double x, double y, double z, double f1) {
	string text = "G00";
	if (f1 != doubleNull) {
		text += " P1";
	}
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" F1", f1);
	write(text);
}

void G74(double x, double y, double z, double r, double p, double q, double f, double e, double k) {
	string text = "G74";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" Q", q);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" E", e);
	text += appendIfNotNull(" K", k);
	write(text);
}

void G76(double x, double y, double z, double r, double q, double p, double f, double k) {
	string text = "G76";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" Q", q);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" K", k);
	write(text);
}

void G80() {
	string text = "G80";
	write(text);
}

void G81(double x, double y, double z, double r, double f, double f2, double k, double q, double d) {
	string text = "G81";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" F2=", f);
	text += appendIfNotNull(" K", k);
	text += appendIfNotNull(" Q", q);
	text += appendIfNotNull(" D", d);
	write(text);
}

void G81_1(double z, double q, double r, double f) {
	string text = "G81.1";
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" Q", q);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" F", f);
	write(text);
}

void G82(double x, double y, double z, double r, double p, double f, double k) {
	string text = "G82";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" K", k);
	write(text);
}

void G83(double x, double y, double z, double r, double q, double f, double k) {
	string text = "G83";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" Q", q);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" K", k);
	write(text);
}

void G84(double x, double y, double z, double r, double p, double q, double f, double e, double k) {
	string text = "G84";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" Q", q);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" E", e);
	text += appendIfNotNull(" K", k);
	write(text);
}

void G85(double x, double y, double z, double r, double f, double k) {
	string text = "G85";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" K", k);
	write(text);
}

void G86(double x, double y, double z, double r, double f, double k) {
	string text = "G86";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" K", k);
	write(text);
}

void G87(double x, double y, double z, double r, double q, double p, double f, double e, double k) {
	string text = "G84";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" Q", q);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" E", e);
	text += appendIfNotNull(" K", k);
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
	G00(1, 2, 3, 1000);
}