#pragma once
#include<vector>

class Matrix3D {

public:
	std::vector<std::vector<int>> a;
	//���캯��������ά����res��ʼ��Ϊһ��4*4�ĵ�λ����
	Matrix3D();

	//��res����λ��
	void makeIdentical();

	//һ�����������һ������,nums�������ڽ��ܴ���ľ���
	Matrix3D multiplied(Matrix3D& nums);

	//����ƽ�ƾ���
	Matrix3D creatTranslateMatrix(int dx, int dy, int dz);

	//�������ž���
	Matrix3D creatScalMatrix(int sx, int sy, int sz);

	//������ת������δ����


	//�������
	void add(Matrix3D& m);


	//�������
	void sub(Matrix3D& m);

};