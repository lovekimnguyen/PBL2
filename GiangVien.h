#pragma once
#include "person.h"
#include <fstream>
using namespace std;
class GiangVien:public person
{
	char magiangvien[7];
public:
	GiangVien() {};
	GiangVien(char magv[7], char ht[50], char em[50], char st[15], bool gt) : person(ht, em, st, gt) {
		strcpy_s(magiangvien, strlen(magv) + 1, magv);
	}
	GiangVien(const char* magv) {
		strcpy_s(magiangvien, strlen(magv) + 1, magv);
	}
	char* getmagiangvien() {
		return magiangvien;
	}
	void setmagiangvien(char magv[7]) {
		strcpy_s(magiangvien, strlen(magv) + 1, magv);
	}
	friend ofstream& operator <<(ofstream& o, GiangVien& gv);
};

