#include "Func.h"
unsigned int size_dslhp_sv = 0;
unsigned int size_dslhp = 0;
unsigned int size_dshp = 0;
unsigned int size_dssv =0;
unsigned int size_dsgv=0;
unsigned int size_dsnhom = 0;
unsigned int size_user = 0;
unsigned int size_admin = 0;
 User* getfromfileUsers(const string namefile) {
	 size_user = 0;
	 ifstream in;
	 in.open(namefile);
	 User* us = new User[1000];
	 while (!in.eof())
	 {
		 char MSSV[10];
		 char mk[20];
		 in.getline(MSSV, 11);
		 in.getline(mk, 21);
		 us[size_user].setMSSV(MSSV);
		 us[size_user].setmk(mk);
		 size_user++;
	 }
	 in.close();
	 return us;
 }
 Admin* getfromfileAdmin(const string namefile) {
	 size_admin = 0;
	 ifstream in;
	 in.open(namefile);
	 Admin* ad = new Admin[1000];
	 while (!in.eof())
	 {
		 char IdAdmin[10];
		 char mk[20];
		 in.getline(IdAdmin, 11);
		 in.getline(mk, 21);
		 ad[size_admin].setIdAdmin(IdAdmin);
		 ad[size_admin].setmk(mk);
		 size_admin++;
	 }
	 in.close();
	 return ad;
 }
 Admin getad(char* idAdmin, Admin* dsAdmin, unsigned int size_admin) {
	 for (int i = 0; i <= size_admin; i++) {
		 if (strcmp(dsAdmin[i].getIdAdmin(), idAdmin) == 0) return dsAdmin[i];
	 }
	 return dsAdmin[0];
 }
SinhVien* getfromfileSinhVien(const string namefile) {
	size_dssv = 0;
	ifstream in;
	in.open(namefile);
	char hoten[50];
	char email[50];
	char sdt[15];
	bool gioitinh;
	char MSSV[10];
	char lopsh[10];
	unsigned short sotcmax;//	for (int i = 1; i <= size_dssv; i++)
	
	while(!in.eof())
 {
		in.getline(hoten, 50);
		if (in.eof()) break;
		in.getline(email, 50);
		in.getline(sdt, 15);
		in >> gioitinh;
		in.ignore();
		in.getline(MSSV, 10);
		in.getline(lopsh, 10);
		in >> sotcmax;
		in.ignore();
		SinhVien s(MSSV, lopsh, sotcmax, hoten, email, sdt, gioitinh);
		size_dssv++;
	}
	
	SinhVien* dssinhvien = new SinhVien[size_dssv + 1];
	dssinhvien[0] = SinhVien("0");
	in.close();
	in.open(namefile, ios::beg);
	for (int i = 1; i <= size_dssv; i++)
	{
		in.getline(hoten, 50);
		in.getline(email, 50);
		in.getline(sdt, 15);
		in >> gioitinh;
		in.ignore();
		in.getline(MSSV, 10);
		in.getline(lopsh, 10);
		in >> sotcmax;
		in.ignore();
		SinhVien s(MSSV, lopsh, sotcmax, hoten, email, sdt, gioitinh);
		dssinhvien[i] = s;
	}
	in.close();
	return dssinhvien;
}

HocPhan* getfromfileHocPhan(const string namefile) {
	size_dshp = 0;
	ifstream in;
	in.open(namefile);
	char mahocphan[8];
	char tenhocphan[50];
	double tchi;
	while (!in.eof()) {
		in.getline(mahocphan, 8);
		if (in.eof()) break;
		in.getline(tenhocphan, 50);
		in >> tchi;
		in.ignore();
		size_dshp++;
	}
	in.close();
	in.open(namefile);
		HocPhan* dsHP = new HocPhan[size_dshp + 1];
	dsHP[0] = HocPhan("0");
	for (int i = 1; i <= size_dshp; i++) {
		in.getline(mahocphan, 8);
		in.getline(tenhocphan, 50);
		in >> tchi;
		in.ignore();
		HocPhan hp(mahocphan, tenhocphan, tchi);
		dsHP[i] = hp;
	}
	in.close();
	return dsHP;
}
GiangVien* getfromfileGiangVien(const string namefile) {
	size_dsgv = 0;
	ifstream in;
	in.open(namefile);
	char magiangvien[7];
	char hoten[50];
	char email[50];
	char sdt[15];
	bool gioitinh;
	while (!in.eof()) {
		in.getline(magiangvien, 7);
		if (in.eof()) break;
		in.getline(hoten, 50);
		in.getline(email, 50);
		in.getline(sdt, 15);
		in >> gioitinh;
		in.ignore();
		size_dsgv++;
	}
	in.close();
	in.open(namefile);
	GiangVien* dsGV = new GiangVien[size_dsgv + 1];
	dsGV[0] = GiangVien("0");
	for (int i = 1; i <= size_dsgv; i++) {

		in.getline(magiangvien, 7);
		in.getline(hoten, 50);
		in.getline(email, 50);
		in.getline(sdt, 15);
		in >> gioitinh;
		in.ignore();
		GiangVien gv(magiangvien, hoten, email, sdt, gioitinh);
		dsGV[i] = gv;
	}
	in.close();

	return dsGV;
}
Nhom* getfromfileNhom(const string namefile) {
	size_dsnhom = 0;
	ifstream in;
	in.open(namefile);
	char manhom[6];
	while (!in.eof()) {
		in.getline(manhom, 6);
		if (in.eof()) break;
		size_dsnhom++;
	}
	size_dsnhom++;

	in.close();
	in.open(namefile);
	Nhom* dsNhom = new Nhom[size_dsnhom + 1];
	for (int i = 0; i < size_dsnhom; i++) {
		in.getline(manhom, 6);
		dsNhom[i] = Nhom(manhom);
	}
	in.close();
	return dsNhom;
}
LopHocPhan* getfromfileLopHocPhan(const string namefile) {
	size_dslhp = 0;
	ifstream in;
	in.open(namefile);
	while(!in.eof()) {
		char malophocphan[16] = ""; //= mahocphan + '.' + manhom
		char mahocphan[8];
		char magv[7];
		unsigned short soluongdk;
		unsigned short soluongmo;
		char manhom[6];//22.12
		pair<unsigned short, unsigned short> tuanhoc;
		unsigned short a, b;
		char thu[3];//2 ..7 OR CN
		unsigned short tietbatdau;
		unsigned short tietketthuc;
		char phonghoc[5];
		bool K;//lớp không được hủy
		bool T;//lớp xung đột KH/TKB
		bool G;//Cần có học tích hợp
		bool CLC;
		in.getline(mahocphan, 8);
		if (in.eof()) break;

		in.getline(magv, 7);
		in >> soluongdk;
		in >> soluongmo; in.ignore();
		in.getline(manhom, 6);
		in >> a;
		in >> b;
		in.ignore();
		tuanhoc = { a,b };
		in.getline(thu, 3);
		in >> tietbatdau;
		in >> tietketthuc;
		in.ignore();
		in.getline(phonghoc, 5);
		ThoiKhoaBieu tkb(thu, tietbatdau, tietketthuc, phonghoc);
		in >> K;
		in >> T;
		in >> G;
		in >> CLC;
		in.ignore();
		//	sprintf(malophocphan, "%s.%s", mahocphan,manhom);
		sprintf_s(malophocphan, 16, "%s.%s", mahocphan, manhom);
		LopHocPhan lhp(malophocphan, mahocphan, magv, soluongdk, soluongmo, manhom, tuanhoc, tkb, K, G, T, CLC);
		size_dslhp++;
	}
	LopHocPhan* dslhp = new LopHocPhan[size_dslhp + 1];
	dslhp[0] = LopHocPhan("0");
	in.close();
	in.open(namefile);
	for (int i = 1; i <= size_dslhp; i++) {
		char malophocphan[16] = ""; //= mahocphan + '.' + manhom
		char mahocphan[8];
		char magv[7];
		unsigned short soluongdk;
		unsigned short soluongmo;
		char manhom[6];//22.12
		pair<unsigned short, unsigned short> tuanhoc;
		unsigned short a, b;
		char thu[3];//2 ..7 OR CN
		unsigned short tietbatdau;
		unsigned short tietketthuc;
		char phonghoc[5];
		bool K;//lớp không được hủy
		bool T;//lớp xung đột KH/TKB
		bool G;//Cần có học tích hợp
		bool CLC;
		in.getline(mahocphan, 8);
		in.getline(magv, 7);
		in >> soluongdk;
		in >> soluongmo; in.ignore();
		in.getline(manhom, 6);
		in >> a;
		in >> b;
		in.ignore();
		tuanhoc = { a,b };
		in.getline(thu, 3);
		in >> tietbatdau;
		in >> tietketthuc;
		in.ignore();
		in.getline(phonghoc, 5);
		ThoiKhoaBieu tkb(thu, tietbatdau, tietketthuc, phonghoc);
		in >> K;
		in >> T;
		in >> G;
		in >> CLC;
		in.ignore();
		//	sprintf(malophocphan, "%s.%s", mahocphan,manhom);
		sprintf_s(malophocphan, 16, "%s.%s", mahocphan, manhom);
		LopHocPhan lhp(malophocphan, mahocphan, magv, soluongdk, soluongmo, manhom, tuanhoc, tkb, K, G, T, CLC);
		dslhp[i] = lhp;
	}
	in.close();
	return dslhp;
}
Lophp_SV* getfromfileLophp_SV(const string namefile) {
	size_dslhp_sv = 0;
	
	ifstream in;
	in.open(namefile);
	char malophocphan[16];
	char MSSV[10];
	while (!in.eof()) {
		in.getline(malophocphan, 16);
		if (in.eof()) break;
		in.getline(MSSV, 10);
		size_dslhp_sv++;
	}
	in.close();
	in.open(namefile);
	Lophp_SV* dslhp_sv = new Lophp_SV[size_dslhp_sv + 1];
	dslhp_sv[0] = Lophp_SV("0");
	for (int i = 1; i <= size_dslhp_sv; i++) {
		in.getline(malophocphan, 16);
		in.getline(MSSV, 10);
		dslhp_sv[i] = Lophp_SV(malophocphan,MSSV);
	}
	in.close();
	return dslhp_sv;
}


 SinhVien  getsv(char* mssv, SinhVien* dssinhvien, unsigned int size_dssv) {
	//phải tạo dssinhvien[0] ở đầu nếu trả về nó thì kh tìm thấy
	for (int i = 0; i <= size_dssv; i++) {
		if (strcmp(dssinhvien[i].getMSSV(), mssv) == 0) return dssinhvien[i];
	}
	return dssinhvien[0];
}

 LopHocPhan  getLHP(char malophocphan[16], LopHocPhan* dslophocphan, unsigned int size_dslhp) {
	//phải tạo dslophocphan[0] ở đầu nếu trả về nó thì kh tìm thấy
	for (unsigned int i = 0; i <= size_dslhp; i++) {
		if (strcmp(dslophocphan[i].getmalophocphan(), malophocphan) == 0) return dslophocphan[i];
	}
	return dslophocphan[0];
}
 HocPhan getHocPhan(char mahocphan[8], HocPhan* dshocphan, unsigned int size_hp)
 {
	 for (unsigned int i = 0; i <= size_hp; i++) {
		 if (strcmp(dshocphan[i].getmahocphan(), mahocphan) == 0) return dshocphan[i];
	 }
	 return dshocphan[0];
 }

//	if (sv.getsohpdadk() == 0) thi khong thuc hien ham []
 LopHocPhan*  getdslophocphancuasv(Lophp_SV* lhpsv, unsigned int size_lhpsv,
	SinhVien sv, LopHocPhan* dslophocphan, unsigned int size_dslhp) {
	unsigned short n = sv.getsohpdadk();
	int j = 0;
	LopHocPhan* l = new  LopHocPhan[n];
	for (int i = 0; i< size_lhpsv && n>j; i++)
		if (strcmp(lhpsv[i].getMSSV(), sv.getMSSV())) {
			l[j] = getLHP(lhpsv->getmalophocphan(), dslophocphan, size_dslhp);
			j++;
		}
	return l;
}

 LopHocPhan*  getdslophocphancuanhom(Nhom_LopHP* dsn_lhp, Nhom nhom, unsigned int size_dsn_lhp,
	LopHocPhan* dslophocphan, unsigned int size_dslhp) {
	unsigned short n = nhom.getsllophocphan();
	LopHocPhan* l = new LopHocPhan[n];
	int j = 0;
	for (int i = 0; i < size_dsn_lhp && j < n; i++) {
		if (strcmp(dsn_lhp[i].getmanhom(), nhom.getmanhom()) == 0) {
			l[j] = getLHP(dsn_lhp[i].getmalophocphan(), dslophocphan, size_dslhp);
			j++;
		}
	}
	return l;
}
 void setfileLophp_sv(const string namefile, Lophp_SV* dslhp_sv) {
	 ofstream o;
	 o.open(namefile , ios::trunc);
	 if (o.is_open()) {
		 for (int i = 1; i <= size_dslhp_sv; i++) {
			 o << dslhp_sv[i].getmalophocphan() << endl;
			 o << dslhp_sv[i].getMSSV() << endl;
		 }
		 o.close();
	 }
 }
 void setfileTKB_sv(const string namefile, Lophp_SV* dslhp_sv, LopHocPhan* dslhp)
 {
	 ofstream o;
	 o.open(namefile);
	 for (int i = 1; i < size_dslhp_sv; i++) {
		o << getLHP(dslhp_sv[i].getmalophocphan(), dslhp, size_dslhp).gettkb();
	 }
	 o.close();
 }
/* LopHocPhan* getfromfile_dslhpsvkhiketthucdk(const string namefile, SinhVien sv, LopHocPhan* dslophocphan) {
	 ifstream in;
	 in.open(namefile);
	 char MSSV[10];
	 char malophocphan[16];
	 cout <<"dssv:" << size_dssv << endl;
	 int size = sv.getsohpdadk();
	 cout <<"size:" << size << endl;
	 LopHocPhan* dslhp_svdadk = new LopHocPhan[size + 1];
	 dslhp_svdadk[0] = LopHocPhan("0");
	 int i = 1;
	 while (!in.eof() && i <= size) {
		 in.getline(malophocphan, 16);
		 if (in.eof()) break;
		 in.getline(MSSV, 10);
		 if (strcmp(MSSV, sv.getMSSV()) == 0) {
			 dslhp_svdadk[i] = getLHP(malophocphan, dslophocphan, size_dslhp);
			 i++;
			 //strcpy_s(dslhp_svdadk[i], strlen(malophocphan) + 1, malophocphan);
		 }
	 }
	 in.close();
	 return dslhp_svdadk;
 }*/
 Nhom* getdsnhom_lhp(const string namefilenhom, LopHocPhan* ds_lhp) {
	 Nhom* ds_nhom = getfromfileNhom(namefilenhom);
	 for (int i = 0; i <= size_dslhp; i++) {
		 for (int j = 0; j < size_dsnhom; j++)
			 if (strcmp(ds_nhom[j].getmanhom(), ds_lhp[i].getmanhom())==0)
			 {
				 ds_nhom[j].addlhp(ds_lhp[i].getmalophocphan());
				 break;
			 }
	 }
	 return ds_nhom;
 }
 LopHocPhan* getdslhpcuahp(char* mahp, LopHocPhan* dslhp , HocPhan* dshp) {
	 LopHocPhan* dslhpcuahp = new LopHocPhan[1000];
	 HocPhan h = getHocPhan(mahp, dshp, size_dshp);
	 int index = 1;
	 for (int i = 1; i <= size_dslhp; i++) {
		 if (strcmp(dslhp[i].getmahocphan(), mahp) == 0) {
			 dslhpcuahp[index] = dslhp[i]; 
			 index++;
		 }
	 }
	 return dslhpcuahp;
 }
 int getsllhpcuahp(char* mahp, LopHocPhan* dslhp, HocPhan* dshp) {
	 LopHocPhan* dslhpcuahp = new LopHocPhan[1000];
	 HocPhan h = getHocPhan(mahp, dshp, size_dshp);
	 int index = 0;
	 for (int i = 1; i <= size_dslhp; i++) {
		 if (strcmp(dslhp[i].getmahocphan(), mahp) == 0) {
			 dslhpcuahp[index] = dslhp[i];
			 index++;
		 }
	 }
	 return index;
 }

 string TKBinchar(ThoiKhoaBieu tkb) {
	 string tkbinchar = "";
	 if (strcmp(tkb.getthu(), "CN") != 0)
		 //cout << "Thu " << tkb.getthu() << ": " << tkb.gettietbatdau() << "-" << tkb.gettietketthuc() << "," << tkb.getphonghoc() << endl;
		 tkbinchar += "Thu " + string(tkb.getthu()) + ": " + to_string(tkb.gettietbatdau()) + "-" + to_string(tkb.gettietketthuc()) + "," + string(tkb.getphonghoc());
	 else
		 tkbinchar += string(tkb.getthu()) + ": " + to_string(tkb.gettietbatdau()) + "-" + to_string(tkb.gettietketthuc()) + "," + string(tkb.getphonghoc());

	 return tkbinchar;
 }
 string TuanHocinchar(pair<unsigned short, unsigned short> tuanhoc) {
	 string thinch = "";
	 thinch = to_string(tuanhoc.first) + " - " + to_string(tuanhoc.second);
	 return thinch;
 }
 string DKy(LopHocPhan hp) {
	 string dky = "";
	 dky = to_string(hp.getsoluongdk()) + "/" + to_string(hp.getsoluongmo());
	 return dky;
 }
 GiangVien getGV(const string namefile, char* magv) {
	 GiangVien* dsgv = getfromfileGiangVien(namefile);
	 for (int i = 1; i <= size_dsgv; i++)
		 if (strcmp(dsgv[i].getmagiangvien(), magv) == 0) return dsgv[i];
	 return dsgv[0];
 }
 const char* getGT(bool gioitinh)
 {
	 char GT[4];
	 if (gioitinh) return "NAM";
	 else return "NU"; 
	// GT[3] = '\0';
	 //return GT;
 }
 //strcpy_s(GT, 4, "//NAM"); strcpy_s(GT, 3 , "NU");