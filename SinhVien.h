#include<iostream>
#include "person.h"
#include "LopHocPhan.h"
#include"Lophp_SV.h"
#include<string>
#include "HocPhan.h"
#pragma once
using namespace std;
class SinhVien :public person
{
	char MSSV[10];
	char lopsh[10];
	unsigned short sotcmax;
	double sotcdadk = 0.0;
	unsigned short sohpdadk = 0;
public:
	SinhVien() {

	}
	SinhVien(const char mssv[10]) {
		strcpy_s(MSSV, strlen(mssv) + 1, mssv);
	}

	SinhVien(char mssv[10], char lsh[10], unsigned short stcm, char ht[50], char em[50], char st[15], bool gt) :sotcmax(stcm), person(ht, em, st, gt)
	{
		strcpy_s(MSSV, strlen(mssv) + 1, mssv);
		strcpy_s(lopsh, strlen(lsh) + 1, lsh);

	}
	SinhVien(char mssv[10], char lsh[10], unsigned short stcm,
		char ht[50], char em[50], char st[15], bool gt, double stcddk, unsigned short shpddk) :sotcmax(stcm), person(ht, em, st, gt)
	{
		strcpy_s(MSSV, strlen(mssv) + 1, mssv);
		strcpy_s(lopsh, strlen(lsh) + 1, lsh);
		sotcdadk = stcddk;
		sohpdadk = shpddk;
	}
	void themLophp_SV(const string namefilelhp_sv, const string namefilelhp,
		char  malophocphan[16], LopHocPhan* dslophocphan, unsigned int size_dslhp, HocPhan* dshp,
		unsigned int size_dshp);
	void xoaLophp_SV(const string namefilelhp_sv, const string namefilelhp, char  malophocphan[16],
		HocPhan* dshp, LopHocPhan* dslophocphan, ThoiKhoaBieu*& ds_TKB, LopHocPhan*& dslhpsv_dadk);
	LopHocPhan* getfromfilelhpdadk(const string namefile,
		LopHocPhan* dslophocphan, unsigned int size_dslhp, HocPhan* dshp, unsigned int size_dshp);
	ThoiKhoaBieu* getTKB_SVdadk(LopHocPhan* ds_lhp_dadk);
	HocPhan* gethp_svchuadk(const string namefile_hp, LopHocPhan* ds_lhp_dadk);
	char* getMSSV() { return MSSV; }
	void setMSSV(char mssv[10]) {
		strcpy_s(MSSV, strlen(mssv) + 1, mssv);
	}
	char* getlopsh() {
		return lopsh;
	}
	void setlopsh(char* lsh) {
		strcpy_s(lopsh, strlen(lsh) + 1, lsh);
	}
	unsigned short getsotcmax() {
		return sotcmax;
	}
	void setsotcmax(unsigned short stcm) {
		sotcmax = stcm;
	}
	double getsotcdadk() {
		return sotcdadk;
	}
	void setsotcdadk(double stcddk) {
		sotcdadk = stcddk;
	}
	unsigned short getsohpdadk() {
		return sohpdadk;
	}
	void setsohpdadk(unsigned short stcm) {
		sohpdadk = stcm;
	}
	friend ofstream& operator <<(ofstream& o, SinhVien& sv);
};

