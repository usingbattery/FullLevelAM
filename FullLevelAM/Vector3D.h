#ifndef VECTOR3D
#define VECTOR3D

namespace vector3d {

	class Vector3D {

	public:
		double dx ;
		double dy ;
		double dz ;
		double dw ;

		Vector3D(double dx=0, double  dy=0, double  dz=0, double  dw=0) {
			this->dx = dx;
			this->dy = dy;
			this->dz = dz;
			this->dw = dw;
		}

		std::string toString() {
			std::string res = "Vector3D:";
			std::stringstream stringTem;
			int precision = 1;
			stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(1) << dx;
			res += stringTem.str() + ",";
			stringTem.str("");
			stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << dy;
			res += stringTem.str() + ",";
			stringTem.str("");
			stringTem << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << dz;
			res += stringTem.str();
			return res;
		}

		Vector3D clone() {
			return Vector3D(this->dx, this->dy, this->dz, this->dw);
		}

		void reverse() {
			this->dx = -this->dx;
			this->dy = -this->dy;
			this->dz = -this->dz;
		}

		Vector3D reversed() {
			return Vector3D(-this->dx, -this->dy, -this->dz);
		}

		double dotProduct(Vector3D vec) {
			return this->dx * vec.dx + this->dy*vec.dy + this->dz*vec.dz;
		}

		Vector3D crossProduct(Vector3D vec) {
			return Vector3D(
				this->dy * vec.dz - this->dz * vec.dy,
				this->dz * vec.dx - this->dx * vec.dz,
				this->dx * vec.dy - this->dy * vec.dx);
		}

		double lengthSquare() {
			return pow(this->dx, 2) + pow(this->dy, 2) + pow(this->dz, 2) + pow(this->dw, 2);
		}

		double length() {
			return sqrt(this->lengthSquare());
		}
	};
};
#endif //VECTOR3D