
#include<string>
#include<iostream>
#pragma once
using namespace std;
class ThoiKhoaBieu
{
	char thu[3];//2 ..7 OR CN
	unsigned short tietbatdau;
	unsigned short tietketthuc;
	char phonghoc[5];
public:
	ThoiKhoaBieu() {

	}

	ThoiKhoaBieu(char thu[3], unsigned short tietbatdau, unsigned short tietketthuc, char phonghoc[5]) {
		strcpy_s(this->thu, strlen(thu) + 1, thu);
		this->tietbatdau = tietbatdau;
		this->tietketthuc = tietketthuc;
		strcpy_s(this->phonghoc, strlen(phonghoc) + 1, phonghoc);
	}
	bool operator==(const ThoiKhoaBieu& t) {//cos trung lich khong
		if (strcmp(thu, t.thu) != 0) return false;
		if (tietbatdau > t.tietketthuc || tietketthuc < t.tietbatdau) return false;
		else return true;
	}
	friend ostream& operator<<(ostream& o, ThoiKhoaBieu const& tkb);
	char* getthu() {
		return thu;
	}
	unsigned short gettietbatdau() {
		return  tietbatdau;
	}
	unsigned short gettietketthuc() {
		return  tietketthuc;
	}
	char* getphonghoc() {
		return phonghoc;
	}

};
