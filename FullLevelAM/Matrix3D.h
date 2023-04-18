#pragma once
#include<vector>

class Matrix3D {

public:
	std::vector<std::vector<int, int>> a;
	//构造函数，将二维数组res初始化为一个4*4的单位矩阵
	Matrix3D();

	//将res矩阵单位化
	void makeIdentical();

	//一个矩阵乘以另一个矩阵,nums矩阵用于接受传入的矩阵
	Matrix3D multiplied(Matrix3D& nums);

	//生成平移矩阵
	Matrix3D creatTranslateMatrix(int dx, int dy, int dz);

	//生成缩放矩阵
	Matrix3D creatScalMatrix(int sx, int sy, int sz);

	//生成旋转矩阵，暂未开发


	//矩阵相加
	void add(Matrix3D& m);


	//矩阵相减
	void sub(Matrix3D& m);

};