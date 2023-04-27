#include "GCode.h"
#include "File.h"

GCode::GCode(std::string filePath) {
	this->outfile = File(filePath);
}

//write text into filePath.txt
void GCode::write(std::string text) {
	outfile.write(text+'\n');
}

//close file at the end
void GCode::closeFile() {
	outfile.closeFile();
}

void GCode::G00(double x, double y, double z, double f1) {
	std::string text = "G00";
	if (f1 != doubleNull) {
		text += " P1";
	}
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" F1", f1);
	write(text);
}

void GCode::G01(double x, double y, double z, double f) {
	std::string text = "G01";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" F", f);
	write(text);
}

void GCode::G02_4(double x1, double y1, double z1, double axial1, double axial2, double f, double x2, double y2, double z2, double axial3, double axial4) {
	std::string text1 = "G02.4";
	text1 += appendIfNotNull(" X", x1);
	text1 += appendIfNotNull(" Y", y1);
	text1 += appendIfNotNull(" Z", z1);
	text1 += appendIfNotNull(" ¦Á", axial1);
	text1 += appendIfNotNull(" ¦Â", axial2);
	text1 += appendIfNotNull(" F", f);
	write(text1);

	std::string text2 = "";
	text2 += appendIfNotNull("X", x2);
	text2 += appendIfNotNull(" Y", y2);
	text2 += appendIfNotNull(" Z", z2);
	text2 += appendIfNotNull(" ¦Á", axial3);
	text2 += appendIfNotNull(" ¦Â", axial4);
	write(text2);
}

void GCode::G03_4(double x1, double y1, double z1, double axial1, double axial2, double f, double x2, double y2, double z2, double axial3, double axial4) {
	std::string text1 = "G03.4";
	text1 += appendIfNotNull(" X", x1);
	text1 += appendIfNotNull(" Y", y1);
	text1 += appendIfNotNull(" Z", z1);
	text1 += appendIfNotNull(" ¦Á", axial1);
	text1 += appendIfNotNull(" ¦Â", axial2);
	text1 += appendIfNotNull(" F", f);
	write(text1);

	std::string text2 = "";
	text2 += appendIfNotNull("X", x2);
	text2 += appendIfNotNull(" Y", y2);
	text2 += appendIfNotNull(" Z", z2);
	text2 += appendIfNotNull(" ¦Á", axial3);
	text2 += appendIfNotNull(" ¦Â", axial4);
	write(text2);
}

void GCode::G02(int model, double x, double y, double r, double z, double f) {
	std::string text = "";
	text += appendIfNotNull("G", model);
	text += " G02";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" F", f);
	write(text);
}

void GCode::G02(int model, double x, double y, double i, double j, double z, double f) {
	std::string text = "";
	text += appendIfNotNull("G", model);
	text += "G02";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" I", i);
	text += appendIfNotNull(" J", j);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" F", f);
	write(text);
}

void GCode::G03(int model, double x, double y, double r, double z, double f) {
	std::string text = "";
	text += appendIfNotNull("G", model);
	text += "G03";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" F", f);
	write(text);
}

void GCode::G03(int model, double x, double y, double i, double j, double z, double f) {
	std::string text = "";
	text += appendIfNotNull("G", model);
	text += "G03";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" I", i);
	text += appendIfNotNull(" J", j);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" F", f);
	write(text);
}

void GCode::G02_G03(int model, double x, double y, double z, double ijk1, double ijk2, double l, double f) {
	std::string text = "";
	text += appendIfNotNull("G", model);
	text += "G02/G03";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	if (x == doubleNull) {
		text += appendIfNotNull(" J", ijk1);
		text += appendIfNotNull(" K", ijk2);
	}
	else if (y == doubleNull) {
		text += appendIfNotNull(" I", ijk1);
		text += appendIfNotNull(" K", ijk2);
	}
	else {
		text += appendIfNotNull(" I", ijk1);
		text += appendIfNotNull(" J", ijk2);
	}
	text += appendIfNotNull(" L", l);
	text += appendIfNotNull(" F", f);
	write(text);
}

void GCode::G04_1(int p, int q) {
	std::string text = "";
	text += "G04.1";
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" Q", q);
	write(text);
}

void GCode::G04(double xp) {
	std::string text = "";
	text += "G04";
	if (xp == (int)xp) {
		text += appendIfNotNull(" P", xp);
	}
	else {
		text += appendIfNotNull(" X", xp);
	}
	write(text);
}

void GCode::G05_1(int q, int e) {
	std::string text = "";
	text += "G05.1";
	text += appendIfNotNull(" Q", q);
	text += appendIfNotNull(" E", e);
	write(text);
}

void GCode::G05(int p, int e) {
	std::string text = "";
	text += "G05";
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" E", e);
	write(text);
}

void GCode::G05(int p, int x, int y, int z, std::string ¦Á, std::string ¦Â) {
	std::string text = "";
	text += "G05";
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" ¦Á", ¦Á);
	text += appendIfNotNull(" ¦Â", ¦Â);
	write(text);
}

void GCode::G06_2(int model, int p, double k, double x, double y, double z, double r, double f) {
	std::string text = "";
	text += "G06.2";
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" K", k);
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" F", f);
	write(text);
}

void GCode::G61() {
	std::string text1 = "G61";
	write(text1);
}

void GCode::G09(double x, double y, double z) {
	std::string text = "";
	text += "G09";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	write(text);
}

void GCode::G10(int l, double p, double r) {
	std::string text = "";
	text += "G10";
	text += appendIfNotNull(" L", l);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" R", r);
	write(text);
}

void GCode::G10_9(int x, int y, int z) {
	std::string text = "";
	text += "G10.9";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	write(text);
}

void GCode::G12_1(double x, double c) {
	std::string text = "";
	text += "G12.1";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" C", c);
	write(text);
}

void GCode::G13_1() {
	write("G13.1");
}

void GCode::G16() {
	write("G16");
}

void GCode::G15() {
	write("G15");
}

void GCode::G17() {
	write("G17");
}

void GCode::G18() {
	write("G18");
}

void GCode::G19() {
	write("G19");
}

void GCode::G22(double x, double y, double z, double i, double j, double k) {
	std::string text = "";
	text += "G22";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" I", i);
	text += appendIfNotNull(" J", j);
	text += appendIfNotNull(" K", k);
	write(text);
}

void GCode::G23() {
	write("G23");
}

void GCode::G28(double x, double y, double z) {
	std::string text = "";
	text += "G28";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	write(text);
}

void GCode::G29(double x, double y, double z) {
	std::string text = "";
	text += "G29";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	write(text);
}

void GCode::G30(int p, double x, double y, double z) {
	std::string text = "";
	text += "G30";
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	write(text);
}

void GCode::G31(double x, double y, double z, double f, double q, double p) {
	std::string text = "";
	text += "G31";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" Q", q);
	text += appendIfNotNull(" P", p);
	write(text);
}

void GCode::G33(double z, double f) {
	std::string text = "";
	text += "G33";
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" F", f);
	write(text);
}

void GCode::G37_2(int k, double z, double r, double f, double p, double q) {
	std::string text = "";
	text += "G37.2";
	text += appendIfNotNull(" K", k);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" Q", q);
	write(text);
}

void GCode::G50() {
	std::string text = "G50";
	text += ";";
	write(text);
}

void GCode::G51(double x, double y, double z, double p) {
	std::string text = "G51";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" P", p);
	text += ";";
	write(text);
}

void GCode::G52(double x, double y, double z) {
	std::string text = "G52";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}

void GCode::G53(double x, double y, double z) {
	std::string text = "G53";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}

void GCode::G54(double x, double y, double z) {
	std::string text = "G54";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}
void GCode::G55(double x, double y, double z) {
	std::string text = "G55";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}

void GCode::G56(double x, double y, double z) {
	std::string text = "G56";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}

void GCode::G57(double x, double y, double z) {
	std::string text = "G57";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}
void GCode::G58(double x, double y, double z) {
	std::string text = "G58";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}
void GCode::G59(double x, double y, double z) {
	std::string text = "G59";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}
void GCode::G59_1(double x, double y, double z) {
	std::string text = "G59.1";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}
void GCode::G59_2(double x, double y, double z) {
	std::string text = "G59.2";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}
void GCode::G59_3(double x, double y, double z) {
	std::string text = "G59.3";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}
void GCode::G59_4(double x, double y, double z) {
	std::string text = "G59.4";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}
void GCode::G59_5(double x, double y, double z) {
	std::string text = "G59.5";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}
void GCode::G59_6(double x, double y, double z) {
	std::string text = "G59.6";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}
void GCode::G59_7(double x, double y, double z) {
	std::string text = "G59.7";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}
void GCode::G59_8(double x, double y, double z) {
	std::string text = "G59.8";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}
void GCode::G59_9(double x, double y, double z) {
	std::string text = "G59.9";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += ";";
	write(text);
}
void GCode::G68(double x, double y, double r) {
	std::string text = "G68";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" R", r);
	text += ";";
	write(text);
}
void GCode::G69() {
	std::string text = "G69";
	text += ";";
	write(text);
}

void GCode::G74(double x, double y, double z, double r, double p, double q, double f, double e, double k) {
	std::string text = "G74";
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

void GCode::G76(double x, double y, double z, double r, double q, double p, double f, double k) {
	std::string text = "G76";
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

void GCode::G80() {
	std::string text = "G80";
	write(text);
}

void GCode::G81(double x, double y, double z, double r, double f, double f2, double k, double q, double d) {
	std::string text = "G81";
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

void GCode::G81_1(double z, double q, double r, double f) {
	std::string text = "G81.1";
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" Q", q);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" F", f);
	write(text);
}

void GCode::G82(double x, double y, double z, double r, double p, double f, double k) {
	std::string text = "G82";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" K", k);
	write(text);
}

void GCode::G83(double x, double y, double z, double r, double q, double f, double k) {
	std::string text = "G83";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" Q", q);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" K", k);
	write(text);
}

void GCode::G84(double x, double y, double z, double r, double p, double q, double f, double e, double k) {
	std::string text = "G84";
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

void GCode::G85(double x, double y, double z, double r, double f, double k) {
	std::string text = "G85";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" K", k);
	write(text);
}

void GCode::G86(double x, double y, double z, double r, double f, double k) {
	std::string text = "G86";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" K", k);
	write(text);
}

void GCode::G87(double x, double y, double z, double r, double q, double p, double f, double e, double k) {
	std::string text = "G87";
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

void GCode::G88(double x, double y, double z, double r, double p, double f, double k) {
	std::string text = "G88";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" K", k);
	write(text);
}

void GCode::G89(double x, double y, double z, double r, double p, double f, double k) {
	std::string text = "G89";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" R", r);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" F", f);
	text += appendIfNotNull(" K", k);
	write(text);
}

void GCode::G90() {
	std::string text = "G90";
	write(text);
}

void GCode::G91() {
	std::string text = "G91";
	write(text);
}

void GCode::G92(double x, double y, double z) {
	std::string text = "G92";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	write(text);
}

void GCode::G92_1(double x, double y, double z, double i, double j, double k, double r) {
	std::string text = "G89";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" Z", z);
	text += appendIfNotNull(" I", i);
	text += appendIfNotNull(" J", j);
	text += appendIfNotNull(" K", k);
	text += appendIfNotNull(" R", r);
	write(text);
}

void GCode::G93() {
	std::string text = "G93";
	write(text);
}

void GCode::G94(double f) {
	std::string text = "G94";
	text += appendIfNotNull(" F", f);
	write(text);
}

void GCode::G95(double f) {
	std::string text = "G95";
	text += appendIfNotNull(" F", f);
	write(text);
}

void GCode::G96(double s) {
	std::string text = "G96";
	text += appendIfNotNull(" S", s);
	write(text);
}

void GCode::G97(double s) {
	std::string text = "G97";
	text += appendIfNotNull(" S", s);
	write(text);
}

void GCode::G120_1(double p, double q) {
	std::string text = "G120.1";
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" Q", q);
	write(text);
}

void GCode::G134(double x, double y, double i, double j, double k) {
	std::string text = "G134";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" I", i);
	text += appendIfNotNull(" J", j);
	text += appendIfNotNull(" K", k);
	write(text);
}

void GCode::G135(double x, double y, double i, double j, double k) {
	std::string text = "G135";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" I", i);
	text += appendIfNotNull(" J", j);
	text += appendIfNotNull(" K", k);
	write(text);
}
void GCode::G136(double x, double y, double i, double j, double p, double k) {
	std::string text = "G136";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" I", i);
	text += appendIfNotNull(" J", j);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" K", k);
	write(text);
}

void GCode::G137_1(double x, double y, double i, double p, double j, double k) {
	std::string text = "G136";
	text += appendIfNotNull(" X", x);
	text += appendIfNotNull(" Y", y);
	text += appendIfNotNull(" I", i);
	text += appendIfNotNull(" P", p);
	text += appendIfNotNull(" J", j);
	text += appendIfNotNull(" K", k);
	write(text);
}