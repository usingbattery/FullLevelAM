#include"Matrix3D.h"

namespace nsp {
	Matrix3D::Matrix3D() {
		a = { {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1} };
	}

	//Unitize the res matrix
	void Matrix3D::makeIdentical() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == j) {
					a[i][j] = 1;
				}
				else {
					a[i][j] = 0;
				}
			}
		}
	}


	//Multiply one matrix by another, nums matrix is used to accept incoming matrices
	Matrix3D Matrix3D::multiplied(Matrix3D& nums) {
		Matrix3D m;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m.a[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					m.a[i][j] += a[i][k] * nums.a[k][j];
				}
			}
		}
		return m;
	}


	//Generate translation matrix
	Matrix3D Matrix3D::creatTranslateMatrix(int dx, int dy, int dz) {
		Matrix3D m;
		m.a[3][0] = dx;
		m.a[3][1] = dy;
		m.a[3][2] = dz;
		return m;
	}


	//Generate scaling matrix
	Matrix3D Matrix3D::creatScalMatrix(int sx, int sy, int sz) {
		Matrix3D m;
		m.a[0][0] = sx;
		m.a[1][1] = sy;
		m.a[2][2] = sz;
		return m;
	}

	//Generate rotation matrix, not yet developed

	//matrix addition
	void Matrix3D::add(Matrix3D& m) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				a[i][j] += m.a[i][j];
			}
		}
	}

	//Matrix subtraction
	void Matrix3D::sub(Matrix3D& m) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				a[i][j] -= m.a[i][j];
			}
		}
	}

    bool Matrix3D::operator==(Matrix3D matrix3D) {
        return a == matrix3D.a;
    }

    bool Matrix3D::operator!=(Matrix3D matrix3D) {
        return this->operator==(matrix3D);
    }
}