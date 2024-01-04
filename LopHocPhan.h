#pragma once
#include<iostream>
#include<Windows.h>
#include "TKB.h"
//#include"SinhVien.h"
using namespace std;

class LopHocPhan
{
	char malophocphan[16]; //= mahocphan + '.' + manhom
	char mahocphan[8];
	char magv[7];
	unsigned short soluongdk = 0;
	unsigned short soluongmo;
	char manhom[6];//22.12
	pair<unsigned short, unsigned short> tuanhoc;
	ThoiKhoaBieu tkb;
	SYSTEMTIME dkluc;//kho thi bo qua
	bool K;//lớp không được hủy
	bool T;//lớp xung đột KH/TKB
	bool G;//Cần có học tích hợp
	bool CLC;
public:
	
	LopHocPhan(){}
	LopHocPhan(const char* malhp) {
		strcpy_s(malophocphan, strlen(malhp) + 1, malhp);
	}
	LopHocPhan(char* malhp , char mahp[8], char mgv[7], unsigned sldk, unsigned slm, char mn[6], pair<unsigned short, unsigned short>th, ThoiKhoaBieu t, bool k, bool g, bool tt, bool clc) {
		strcpy_s(mahocphan, strlen(mahp) + 1, mahp);
		strcpy_s(magv, strlen(mgv) + 1, mgv);
		soluongdk = sldk;
		soluongmo = slm;
		strcpy_s(manhom, strlen(mn) + 1, mn);
		tuanhoc = th;
		tkb = t;
		K = k;
		G = g;
		T = tt;
		CLC = clc;
        sprintf_s(malophocphan, 16, "%s.%s", mahocphan, manhom);
	}
	void setT_after(ThoiKhoaBieu* tkb_sv, unsigned int size_dstkb_sv); //sau khi dki
	char* getmalophocphan() {
		return malophocphan;
	}
	void setmalophocphan(char malhp[16]) {
		strcpy_s(malophocphan, strlen(malhp) + 1, malhp);
	}
	char* getmahocphan() {
		return mahocphan;
	}
	void setmahocphan(char mahp[8]) {
		strcpy_s(mahocphan, strlen(mahp) + 1, mahp);
	}
	char* getmagv() {
		return magv;
	}
	void setmagv(char mgv[7]) {
		strcpy_s(magv, strlen(mgv) + 1, mgv);
	}
	unsigned short getsoluongdk() {
		return soluongdk;
	}

	void setsoluongdk(unsigned sldk ) {
		soluongdk = sldk;
	}
	unsigned short getsoluongmo() {
		return soluongmo;
	}
	void setsoluongmo(unsigned slm) {
		soluongmo = slm;
	}
	char* getmanhom() {
		return manhom;
	}
	void setmanhom(char mn[6]) {
		strcpy_s(manhom, strlen(mn) + 1, mn);
	}
	pair<unsigned short, unsigned short> gettuanhoc() {
		return tuanhoc;
	}
	void settuanhoc(pair<unsigned short, unsigned short>th) {
		tuanhoc = th;
	}
	ThoiKhoaBieu gettkb() {
		return tkb;
	}
	void settkb(ThoiKhoaBieu t) {
		tkb = t;
	}
	SYSTEMTIME getdkluc() {
		return dkluc;
	}
	void setdkluc(SYSTEMTIME dkl) {
		dkluc = dkl;
	}
	bool getK() {
		return K;
	}
	void setK(bool k) {
		K = k;
	}
	bool getG() {
		return G;
	}
	void setG(bool g) {
		G = g;
	}
	void setT(bool tt) {
		T = tt;
	}
	bool getT() {
		return T;
	}
	bool getCLC() {
		return CLC;
	}
	void setCLC(bool clc) {
		CLC = clc;
	}
	friend ofstream& operator << (ofstream& o, LopHocPhan& lhp);
};

