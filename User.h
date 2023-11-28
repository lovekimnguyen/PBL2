#pragma once
#include<string>
class User
{
	char MSSV[10];
	char mk[20];
public:
	char* getMSSV() { return MSSV; }
	void setMSSV(char mssv[10]) {
		strcpy_s(MSSV, strlen(mssv) + 1, mssv);
	}
	char* getmk() { return mk; }
	void setmk(char mkk[25]) {
		strcpy_s(mk, strlen(mkk) + 1, mkk);
	}
};



