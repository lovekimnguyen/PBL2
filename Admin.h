#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"HocPhan.h"
#include "GiangVien.h"
#include "Nhom.h"
#include"SinhVien.h"
#include "TKB.h"
#include "Nhom_LopHP.h"
#include"Lophp_SV.h"
#include <fstream>
#include <ctime>
class Admin : public person
{
	char IdAdmin[10];
	char mk[20];
public:
	void nhapHocPhan(const string, char[], char[], double);
	void nhapGiangVien(const string, char[], char[], char[], char[], bool);
	void nhapnhom(const string, char[]);
	void nhapLopHocPhan(const string, char[], char[], char[], unsigned short, unsigned short, unsigned short, unsigned short, char[], unsigned short, unsigned short, char[], bool, bool, bool, bool);
	void nhapSinhVien(const string, const string, char[], char[], char[], bool, char[], char[], unsigned short);
	void updateSinhVien(const string, char[], char[], char[], char[], bool, char[], unsigned short);
	void updatehocphan(const string, char[], char[], double);
	void updategiangvien(const string, char[], char[], char[], char[], bool);
	void updatelophocphan(const string, char[], char[], char[], char[], unsigned short, unsigned short, unsigned short, unsigned short, char[], unsigned short, unsigned short, char[], bool, bool, bool, bool);
	void nhapNhom_LopHP(const string, char[], char[]);
	void updateNhom_LopHP(Nhom_LopHP&);
	Admin(char id[10],
		char m[20], char ht[50], char em[50], char st[15], bool gt) :person(ht, em, st, gt)
	{
		strcpy_s(IdAdmin, strlen(id) + 1, id);
		strcpy_s(mk, strlen(m) + 1, m);
	}
	Admin() {
	}

	char* getIdAdmin() {
		return IdAdmin;
	}
	void setIdAdmin(char* id) {
		strcpy_s(IdAdmin, strlen(id) + 1, id);
	}
	char* getmk() {
		return mk;
	}
	void setmk(char* m) {
		strcpy_s(mk, strlen(m) + 1, m);
	}
	void xoaSV(const string namefileSV, const string namefileLhp_Sv, char* mssv);
	void xoasvBy_mssv_InfileSV(const string filename, char* mssv);
	void xoafilelhpBy_mlhp(const string filename, char* malhp);
	void xoaLhpSv_Bixoa_Dadk_Bymssv_infilelhpsv(const string namefile, const string namefileSinhVien, char* mssv);
	void XoaGv_FromFileGV_ByMaGv(const string namefileGv, char* magv);
	void xoaLhp_InfileLhp_ByMaGv(const string namefileLhp, char* magv);
	void XoaGV(const string namefileGV, const string namefileLhp, const string namefileLhpsv, char* magv);
	void XoaLhp_SvDadk_ByMaLhp(const string namefilelhpsv, char* malhp);
	void XoaLhp(const string namefilelhp, const string namefilelhpsv, char* malhp);
	void xoaLhp_ByMaHp(const string namefileLhp, const string namefilelhpsv, char* mahp);
	void xoafileHpBy_mahp(const string namefilehp, char* mahp);
	void XoaHp(const string namefilehp, const string namefilelhp, const string namefilelhp_sv, char* mahp);
};