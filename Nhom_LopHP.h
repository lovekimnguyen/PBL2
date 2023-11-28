#pragma once
#include<string.h>
class Nhom_LopHP
{
	char manhom[6];
	char malophocphan[16];
public:
	Nhom_LopHP() {	}
	Nhom_LopHP(char mn[6], char malhp[16]) {
		strcpy_s(manhom, strlen(mn) + 1, mn);
		strcpy_s(malophocphan, strlen(malhp) + 1, malhp);
	}
	char* getmanhom() {
		return manhom;
	}
	void setmanhom(char mn[6]) {
		strcpy_s(manhom, strlen(mn) + 1, mn);
	}
	char* getmalophocphan() {
		return malophocphan;
	}
	void setmalophocphan(char malhp[16]) {
		strcpy_s(malophocphan, strlen(malhp) + 1, malhp);
	}
};

