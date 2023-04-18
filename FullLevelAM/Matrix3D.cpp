#include"Matrix3D.h"


Matrix3D::Matrix3D() {
	a = { {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1} };
}

//将res矩阵单位化
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


//一个矩阵乘以另一个矩阵,nums矩阵用于接受传入的矩阵
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


//生成平移矩阵
Matrix3D Matrix3D::creatTranslateMatrix(int dx, int dy, int dz) {
	Matrix3D m;
	m.a[3][0] = dx;
	m.a[3][1] = dy;
	m.a[3][2] = dz;
	return m;
}


//生成缩放矩阵
Matrix3D Matrix3D::creatScalMatrix(int sx, int sy, int sz) {
	Matrix3D m;
	m.a[0][0] = sx;
	m.a[1][1] = sy;
	m.a[2][2] = sz;
	return m;
}

//生成旋转矩阵，暂未开发

//矩阵相加
void Matrix3D::add(Matrix3D& m) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] += m.a[i][j];
		}
	}
}

//矩阵相减
void Matrix3D::sub(Matrix3D& m) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] -= m.a[i][j];
		}
	}
}