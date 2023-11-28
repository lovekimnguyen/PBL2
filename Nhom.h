#pragma once
//hỏi thầy , có con trỏ là phải overide lại hàm hủy,xóa con trỏ char**
//#include"Func.h"
#include<string.h>
class Nhom
{
	char manhom[6];//
	unsigned short sllophocphan;
	char** ds_malophp;
public:

	unsigned short getsllophocphan() {
		return sllophocphan;
	}
	Nhom() {
		sllophocphan = 0;
	}
	Nhom(const char mn[6]) {
		strcpy_s(manhom, strlen(mn)+1 , mn);
		sllophocphan = 0;
	}
	char* getmanhom() {
		return manhom;
	}
	void setmanhom(char mn[6]) {
		strcpy_s(manhom, strlen(mn) + 1, mn);
	}
	char** getds_malophp() {
		return ds_malophp;
	}
	void addlhp(char malophp[16]);
	~Nhom();
	/*void addlophocphan( char malhp[14]) {
		if (sllophocphan == 0) {
			malophocphan = new char* [1];
			malophocphan[0] = malhp;
			
		}
		else {
			char** malhphan = new char* [sllophocphan+1];
			for (int i = 0; i < sllophocphan+1; i++) {
				malhphan[i] = new char[14];

			}
			for (int i = 0; i < sllophocphan ; i++)
				malhphan[i] = malophocphan[i];
			malhphan[sllophocphan ] = malhp;
			//for (int i = 0; i < sllophocphan ; i++)
				//delete[] *(malophocphan+0);
			delete[] malophocphan;
			malophocphan = new char* [14];
			malophocphan = malhphan;
		}
		sllophocphan++;
	}*/
};
