#include "Nhom.h"
void Nhom::addlhp(char malophp[16]) {
	if (sllophocphan == 0) {
		sllophocphan++;
		ds_malophp = new char* [sllophocphan + 1];
		ds_malophp[0] = new char[16];
		strcpy_s(ds_malophp[0], strlen(malophp) + 1, malophp);
	}
	else {
		//sllophocphan++;
		char** t = new char* [sllophocphan + 2];
		for (int i = 0; i <= sllophocphan; i++)
			t[i] = new char[16];
		for (int i = 0; i < sllophocphan; i++)
			strcpy_s(t[i], strlen(ds_malophp[i]) + 1, ds_malophp[i]);

		strcpy_s(t[sllophocphan], strlen(malophp) + 1, malophp);
		
		for (int i = 0; i < sllophocphan; i++)
			delete[] ds_malophp[i];
		delete[] ds_malophp;
		ds_malophp = t;
		sllophocphan++;
	}
}
Nhom::~Nhom() {
	
	if (sllophocphan != 0)  {
		for (int i = 0; i < sllophocphan; i++)
			delete[] ds_malophp[i];
		delete ds_malophp;
	}
	
}
