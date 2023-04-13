#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <fstream>

using namespace std;

const double doubleNull = 999;

//avoid open and close each time write()
ofstream outfile;

//avoid created each time doubleToString()
std::stringstream stringTem;

//open file at begining
void openFile(string filePath) {
	outfile.open(filePath, ios::app);
	if (!outfile)
	{
		cout << "打开文件失败" << endl;
		exit(1);
	}
}

//write text into filePath.txt
void write(string text) {
	outfile << text << endl;
}

//close file at the end
void closeFile() {
	outfile.close();
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
	text += appendIfNotNull(" F1=", f1);
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
	string text = "G87";
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

void G88(double x, double y, double z, double r, double p, double f, double k) {
	string text = "G88";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" K", k);
	write(text);
}

void G89(double x, double y, double z, double r, double p, double f, double k) {
	string text = "G89";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" K", k);
	write(text);
}

void G90() {
	string text = "G90";
	write(text);
}

void G91() {
	string text = "G91";
	write(text);
}

void G92(double x, double y, double z) {
	string text = "G92";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	write(text);
}

void G92_1(double x, double y, double z, double i, double j, double k, double r) {
	string text = "G89";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" I", i);
	text += appendIfNotNull(" J", j);
	text += appendIfNotNull(" K", k);
	text += appendIfNotNull(" R", r);
	write(text);
}

void G93() {
	string text = "G93";
	write(text);
}

void G94(double f) {
	string text = "G94";
	text += appendIfNotNull(" F", f);
	write(text);
}

void G95(double f) {
	string text = "G95";
	text += appendIfNotNull(" F", f);
	write(text);
}

void G96(double s) {
	string text = "G96";
	text += appendIfNotNull(" S", s);
	write(text);
}

void G97(double s) {
	string text = "G97";
	text += appendIfNotNull(" S", s);
	write(text);
}

void G120_1(double p, double q) {
	string text = "G120.1";
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" Q", q);
	write(text);
}

void G134(double x, double y, double i, double j, double k) {
	string text = "G134";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" I", i);
	text += appendIfNotNull(" J", j);
	text += appendIfNotNull(" K", k);
	write(text);
}

void G135(double x, double y, double i, double j, double k) {
	string text = "G135";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" I", i);
	text += appendIfNotNull(" J", j);
	text += appendIfNotNull(" K", k);
	write(text);
}
void G136(double x, double y, double i, double j, double p, double k) {
	string text = "G136";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" I", i);
	text += appendIfNotNull(" J", j);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" K", k);
	write(text);
}

void G137_1(double x, double y, double i, double p, double j, double k) {
	string text = "G136";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" I", i);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" J", j);
	text += appendIfNotNull(" K", k);
	write(text);
}

// test
int main() {
	string filePath = "GCode.txt";
	openFile(filePath);
	G00(1, 2, 3, 1000);
	closeFile();
}