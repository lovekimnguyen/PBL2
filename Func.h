#pragma once
#include "Lophp_SV.h"
#include "SinhVien.h"
#include"Admin.h"
#include"TKB_SV.h"
#include "Nhom_LopHP.h"
#include "TKB.h"
#include "User.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
extern unsigned int size_dslhp_sv ; // so lop hp da dki
extern unsigned int size_dslhp; // so lop hp tat ca
extern unsigned int size_dshp; // so cac hoc phan
extern unsigned int size_dssv; // so sv
extern unsigned int size_dsgv; // so gv
extern unsigned int size_dsnhom; // so nhom
extern unsigned int size_user; // so u
extern unsigned int size_admin; // so a
SinhVien* getfromfileSinhVien(const string namefile);

User* getfromfileUsers(const string namefile);

Admin* getfromfileAdmin(const string namefile);

Admin getad(char* idAdmin, Admin* dsAdmin, unsigned int size_admin);

HocPhan* getfromfileHocPhan(const string namefile);

GiangVien* getfromfileGiangVien(const string namefile);

Nhom* getfromfileNhom(const string namefile);

LopHocPhan* getfromfileLopHocPhan(const string namefile);

Lophp_SV* getfromfileLophp_SV(const string namefile); // ma hp , ma sv 

SinhVien getsv(char* mssv, SinhVien* dssinhvien, unsigned int size_dssv);

LopHocPhan getLHP(char malophocphan[16], LopHocPhan* dslophocphan, unsigned int size_dslhp);

LopHocPhan* getdslophocphancuasv(Lophp_SV* lhpsv, unsigned int size_lhpsv,
SinhVien sv, LopHocPhan* dslophocphan, unsigned int size_dslhp); // lap ds lhp sv da dki

HocPhan getHocPhan(char mahocphan[8], HocPhan* dshocphan, unsigned int size_hp);

LopHocPhan* getdslophocphancuanhom(Nhom_LopHP* dsn_lhp, Nhom nhom, unsigned int size_dsn_lhp,LopHocPhan* dslophocphan,
unsigned int size_dslhp); // ds lop hp cua nhom (mang )  co the khong sai

void setfileLophp_sv(const string namefile, Lophp_SV* dslhp_sv);

void setfileTKB_sv(const string namefile, Lophp_SV* dslhp_sv, LopHocPhan* dslhp);//ghi lai toan bo file TKB_SinhVien bang danh sach lop hoc phan da dk

//LopHocPhan* getfromfile_dslhpsvkhiketthucdk(const string namefile, SinhVien sv, LopHocPhan* dslophocphan);
Nhom* getdsnhom_lhp(const string namefilenhom, LopHocPhan* ds_lhp);

string TKBinchar(ThoiKhoaBieu tkb);
string TuanHocinchar(pair<unsigned short, unsigned short> tuanhoc);
string DKy(LopHocPhan hp);
LopHocPhan* getdslhpcuahp(char* mahp, LopHocPhan* dslhp, ThoiKhoaBieu* tkb_sv, unsigned int size_dstkb_sv);
int getsllhpcuahp(char* mahp, LopHocPhan* dslhp);
GiangVien getGV(const string namefile, char* magv);

const char* getGT(bool );
void setfilelhp(const string namefile, LopHocPhan* dslhp);
User getUR(const string namefile, char* mssv);
