#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cfloat>
#include <fstream>
#include "File.h"

namespace nsp {

	class GCode {

	private:

		const double doubleNull = DBL_MAX;

		//avoid open and close each time write()
		File *outfile;

		//avoid created each time doubleToString()
		std::stringstream stringTem;

		//write text into filePath.txt
		void write(std::string text);

		std::string doubleToString(double number, int precision) {
			stringTem.str("");
			stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << number;
			return stringTem.str();
		}

		std::string doubleToString(double number) {
			return doubleToString(number, 1);
		}

		std::string doubleToString(int number) {
			stringTem.str("");
			//        stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << number;
			stringTem << std::setiosflags(std::ios::fixed) << number;
			return stringTem.str();
		}

		std::string appendIfNotNull(std::string attribute, double value) {
			if (value != doubleNull) {
				return attribute + doubleToString(value);
			}
			else return "";
		}

		std::string appendIfNotNull(std::string attribute, int value) {
			if (value != doubleNull) {
				return attribute + doubleToString(value);
			}
			else return "";
		}

		std::string appendIfNotNull(std::string attribute, std::string str) {
			if (str != "") {
				return attribute + str;
			}
			else return "";
		}

	public:

		GCode(std::string filePath);

		void G00(double x, double y, double z, double f1);

		void G01(double x, double y, double z, double f);

		void G02_4(double x1, double y1, double z1, double axial1, double axial2, double f, double x2, double y2, double z2, double axial3, double axial4);

		void G03_4(double x1, double y1, double z1, double axial1, double axial2, double f, double x2, double y2, double z2, double axial3, double axial4);

		void G02(int model, double x, double y, double r, double z, double f);

		void G02(int model, double x, double y, double i, double j, double z, double f);

		void G03(int model, double x, double y, double r, double z, double f);

		void G03(int model, double x, double y, double i, double j, double z, double f);

		void G02_G03(int model, double x, double y, double z, double ijk1, double ijk2, double l, double f);

		void G04_1(int p, int q);

		void G04(double xp);

		void G05_1(int q, int e);

		void G05(int p, int e);

		void G05(int p, int x, int y, int z, std::string α, std::string β);

		void G06_2(int model, int p, double k, double x, double y, double z, double r, double f);

		void G61();

		void G09(double x, double y, double z);

		void G10(int l, double p, double r);

		void G10_9(int x, int y, int z);

		void G12_1(double x, double c);

		void G13_1();

		void G16();

		void G15();

		void G17();

		void G18();

		void G19();

		void G22(double x, double y, double z, double i, double j, double k);

		void G23();

		void G28(double x, double y, double z);

		void G29(double x, double y, double z);

		void G30(int p, double x, double y, double z);

		void G31(double x, double y, double z, double f, double q, double p);

		void G33(double z, double f);

		void G37_2(int k, double z, double r, double f, double p, double q);

		void G50();

		void G51(double x, double y, double z, double p);

		void G52(double x, double y, double z);

		void G53(double x, double y, double z);

		void G54(double x, double y, double z);

		void G55(double x, double y, double z);

		void G56(double x, double y, double z);

		void G57(double x, double y, double z);

		void G58(double x, double y, double z);

		void G59(double x, double y, double z);

		void G59_1(double x, double y, double z);

		void G59_2(double x, double y, double z);

		void G59_3(double x, double y, double z);

		void G59_4(double x, double y, double z);

		void G59_5(double x, double y, double z);

		void G59_6(double x, double y, double z);

		void G59_7(double x, double y, double z);

		void G59_8(double x, double y, double z);

		void G59_9(double x, double y, double z);

		void G68(double x, double y, double r);

		void G69();

		void G74(double x, double y, double z, double r, double p, double q, double f, double e, double k);

		void G76(double x, double y, double z, double r, double q, double p, double f, double k);

		void G80();

		void G81(double x, double y, double z, double r, double f, double f2, double k, double q, double d);

		void G81_1(double z, double q, double r, double f);

		void G82(double x, double y, double z, double r, double p, double f, double k);

		void G83(double x, double y, double z, double r, double q, double f, double k);

		void G84(double x, double y, double z, double r, double p, double q, double f, double e, double k);

		void G85(double x, double y, double z, double r, double f, double k);

		void G86(double x, double y, double z, double r, double f, double k);

		void G87(double x, double y, double z, double r, double q, double p, double f, double e, double k);

		void G88(double x, double y, double z, double r, double p, double f, double k);

		void G89(double x, double y, double z, double r, double p, double f, double k);

		void G90();

		void G91();

		void G92(double x, double y, double z);

		void G92_1(double x, double y, double z, double i, double j, double k, double r);

		void G93();

		void G94(double f);

		void G95(double f);

		void G96(double s);

		void G97(double s);

		void G120_1(double p, double q);

		void G134(double x, double y, double i, double j, double k);

		void G135(double x, double y, double i, double j, double k);

		void G136(double x, double y, double i, double j, double p, double k);

		void G137_1(double x, double y, double i, double p, double j, double k);
	};
}