#pragma once
#include<string>
class Lophp_SV
{
	char malophocphan[16];
	char MSSV[10];
public:
	Lophp_SV() {

	}
	Lophp_SV(const char malhp[16]) {
		strcpy_s(malophocphan, strlen(malhp) + 1, malhp);

	}
	Lophp_SV(char malhp[16], char mssv[10]) {
		strcpy_s(malophocphan, strlen(malhp) + 1, malhp);
		strcpy_s(MSSV, strlen(mssv) + 1, mssv);

	}

	char* getmalophocphan() {
		return malophocphan;
	}
	void setmalophocphan(char malhp[16]) {
		strcpy_s(malophocphan, strlen(malhp) + 1, malhp);
	}
	char* getMSSV() { return MSSV; }
	void setMSSV(char mssv[10]) {
		strcpy_s(MSSV, strlen(mssv) + 1, mssv);
	}
};

