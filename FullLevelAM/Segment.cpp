#include"Segment.h"
namespace nsp {

//��ʼ��
    Segment::Segment(Point3D a, Point3D b) {
        this->A = a.clone();
        this->B = b.clone();
    }

	std::string Segment::toString() {
		std::string res = "Segment:";
		return res + A.toString() + B.toString();
	}

//�����߶γ���
    double Segment::length() {
        return A.distance(B);
    }

//�����߶η���
    Vector3D Segment::direction() {
        return A.pointTo(B);
    }


//�����߶������˵�
    void Segment::swap() {
        Point3D temp;
        temp = A;
        A = B;
        B = temp;
    }

	bool Segment::operator==(Segment segment) {
		return (A == segment.A && B == segment.A) || (B == segment.A && A == segment.B);
	}

	bool Segment::operator!=(Segment segment) {
		return !this->operator==(segment);
	}
}