#include "Admin.h"
#include "Func.h"
 void Admin::nhapSinhVien(const string namefile , const string namefile_user , char hoten[] , char email[] , char sdt[] , bool gioitinh ,  char MSSV[] , char lopsh[] , unsigned short sotcmax) {
	ofstream o , o1 , o2;
	time_t now = time(0);
	char* dt = ctime(&now);
	o2.open("LichSuThayDoi.txt", ios::app);
	o.open(namefile, ios::app);
	o << hoten << endl;
	o << email << endl;
	o << sdt << endl;
	o << gioitinh << endl;
	o << MSSV << endl;
	o << lopsh << endl;
	o << sotcmax << endl;
	o.close();
	o1.open(namefile_user, ios::app);
	o1 << MSSV << endl;
	o1 << sdt << endl; // sdt của sinh viên là mật khẩu mặt định
	o2 << "Them sinh vien " << MSSV << " | " << "thoi gian: " << dt;
	o1.close();
	o2.close();
}
 void Admin::updateSinhVien(const string namefile, char MSSV[], char hoten[], char email[], char sdt[], bool gioitinh, char lopsh[], unsigned short sotcmax) {
	SinhVien s(MSSV, lopsh, sotcmax, hoten, email, sdt, gioitinh);
	ofstream o, o1;
	time_t now = time(0);
	SinhVien* dssv = getfromfileSinhVien(namefile);
	char* dt = ctime(&now);
	o1.open("LichSuThayDoi.txt", ios::app);
	o.open(namefile, ios::trunc);
	for (int i = 1; i <= size_dssv; i++) {
		if (strcmp(dssv[i].getMSSV(), MSSV) == 0) {
			dssv[i] = s;
			o1 << "Update sinh vien " << MSSV << " | " << "thoi gian: " << dt;
			break;
		}
	}
	if (o.is_open()) {
		for (int i = 1; i <= size_dssv; i++) {
			o << dssv[i].gethoten() << endl;
			o << dssv[i].getemail() << endl;
			o << dssv[i].getsdt() << endl;
			o << dssv[i].getgioitinh() << endl;
			o << dssv[i].getMSSV() << endl;
			o << dssv[i].getlopsh() << endl;
			o << dssv[i].getsotcmax() << endl;
		}
		o.close();
	}
	o1.close();
}
 void Admin::nhapHocPhan(const string namefile, char mahocphan[], char tenhocphan[], double tchi) {
	 ofstream o, o1;
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 o1.open("LichSuThayDoi.txt", ios::app);
	 o.open(namefile, ios::app);
	 o << mahocphan << endl;
	 o << tenhocphan << endl;
	 o << tchi << endl;
	 o1 << "Them 1 hoc phan " << mahocphan << " | " << "thoi gian: " << dt;
	 o.close();
	 o1.close();
 }
 void Admin::updatehocphan(const string namefile, char mahocphan[], char tenhocphan[], double tchi) {
	 HocPhan hp(mahocphan, tenhocphan, tchi);
	 HocPhan* dshp = getfromfileHocPhan(namefile);
	 ofstream o, o1;
	 o.open(namefile, ios::trunc);
	 o1.open("LichSuThayDoi.txt", ios::app);
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 for (int i = 1; i <= size_dshp; i++) {
		 if (strcmp(dshp[i].getmahocphan(),mahocphan) == 0) {
			 dshp[i] = hp;
			 o1 << "Update hoc phan " << mahocphan << " | " << "thoi gian: " << dt;
			 break;
		 }
	 }
	 if (o.is_open()) {
		 for (int i = 1; i <= size_dshp; i++) {
			 o << dshp[i].getmahocphan() << endl;
			 o << dshp[i].gettenhocphan() << endl;
			 o << dshp[i].gettchi() << endl;
		 }
		 o.close();
	 }
	 o1.close();
}
 void Admin::nhapGiangVien(const string namefile, char magiangvien[], char hoten[], char email[], char sdt[], bool gioitinh) {
	 ofstream o, o1;
	 o.open(namefile, ios::app);
	 o1.open("LichSuThayDoi.txt", ios::app);
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 o << magiangvien << endl;
	 o << hoten << endl;
	 o << email << endl;
	 o << sdt << endl;
	 o << gioitinh << endl;
	 o1 << "Nhap giang vien " << magiangvien << " | " << "thoi gian: " << dt;
	 o.close();
	 o1.close();
 }
 void Admin::updategiangvien(const string namefile, char magiangvien[], char hoten[], char email[], char sdt[], bool gioitinh) {
	 GiangVien gv(magiangvien, hoten, email, sdt, gioitinh);
	 ofstream o, o1;
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 o1.open("LichSuThayDoi.txt", ios::app);
	 GiangVien* dsgv = getfromfileGiangVien(namefile);
	 for (int i = 1; i <= size_dsgv; i++) {
		 if (strcmp(dsgv[i].getmagiangvien(), magiangvien) == 0) {
			 dsgv[i] = gv;
			 o1 << "Update Giang Vien " << magiangvien << " | " << "thoi gian: " << dt;
			 break;
		 }
	 }
	 o1.close();
	 o.open(namefile, ios::trunc);
	 if (o.is_open()) {
		 for (int i = 1; i <= size_dsgv; i++) {
			 o << dsgv[i].getmagiangvien() << endl;
			 o << dsgv[i].gethoten() << endl;
			 o << dsgv[i].getemail() << endl;
			 o << dsgv[i].getsdt() << endl;
			 o << dsgv[i].getgioitinh() << endl;
		 }
		 o.close();
	 }
}
 void Admin::nhapnhom(const string namefile , char manhom[]) {
	ofstream o;
	o.open(namefile, ios::app);
	o << manhom << endl;
	o.close();
}

 void Admin::nhapLopHocPhan(const string namefile, char mahocphan[], char manhom[], char magv[], unsigned short soluongdk, unsigned short soluongmo, unsigned short a, unsigned short b, char thu[], unsigned short tietbatdau, unsigned short tietketthuc, char phonghoc[], bool K, bool T, bool G, bool CLC) {
	 ofstream o, o1;
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 o1.open("LichSuThayDoi.txt", ios::app);
	 o.open(namefile, ios::app);
	 o << mahocphan << endl;
	 o << magv << endl;
	 o << soluongdk << endl;
	 o << soluongmo << endl;
	 o << manhom << endl;
	 o << a << endl;
	 o << b << endl;
	 o << thu << endl;
	 o << tietbatdau << endl;
	 o << tietketthuc << endl;
	 o << phonghoc << endl;
	 o << K << endl;
	 o << T << endl;
	 o << G << endl;
	 o << CLC << endl;
	 o1 << "Nhap Lop hoc phan " << mahocphan << manhom <<  " | " << "thoi gian: " << dt;
	 o.close();
	 o1.close();
 }
 void Admin::updatelophocphan(const string namefile , char mahocphan[] ,char malophocphan[] , char manhom[] , char magv[] , unsigned short soluongdk , unsigned short soluongmo ,unsigned short a  , unsigned short b , char thu[] ,  unsigned short tietbatdau , unsigned short tietketthuc , char phonghoc[] , bool K , bool T , bool G , bool CLC) {
	pair<unsigned short, unsigned short> tuanhoc;
	tuanhoc = { a,b };
	ofstream o, o1;
	time_t now = time(0);
	char* dt = ctime(&now);
	o1.open("LichSuThayDoi.txt", ios::app);
	ThoiKhoaBieu tkb = ThoiKhoaBieu(thu, tietbatdau, tietketthuc, phonghoc);
	LopHocPhan lhp(0 , mahocphan, magv, soluongdk, soluongmo, manhom, tuanhoc, tkb, K, G, T, CLC);
	LopHocPhan* dslhp = getfromfileLopHocPhan(namefile);
	for (int i = 1; i <= size_dslhp; i++) {
		if (strcmp(dslhp[i].getmalophocphan(), malophocphan) == 0) {
			dslhp[i] = lhp;
			o1 << "Update Lop hoc phan " << mahocphan << manhom << " | " << "thoi gian: " << dt;
			break;
		}
	}
	o1.close();
	o.open(namefile, ios::trunc);
	if (o.is_open()) {
		for (int i = 1; i <= size_dslhp; i++) {
			o << dslhp[i].getmahocphan() << endl;
			o << dslhp[i].getmagv() << endl;
			o << dslhp[i].getsoluongdk() << endl;
			o << dslhp[i].getsoluongmo() << endl;
			o << dslhp[i].getmanhom() << endl;
			o << dslhp[i].gettuanhoc().first << endl;
			o << dslhp[i].gettuanhoc().second << endl;
			o << dslhp[i].gettkb().getthu() << endl;
			o << dslhp[i].gettkb().gettietbatdau() << endl;
			o << dslhp[i].gettkb().gettietketthuc() << endl;
			o << dslhp[i].gettkb().getphonghoc() << endl;
			o << dslhp[i].getK() << endl;
			o << dslhp[i].getT() << endl;
			o << dslhp[i].getG() << endl;
			o << dslhp[i].getCLC() << endl;
		}
		o.close();
	}
}
 // hết 
 void Admin::nhapNhom_LopHP(const string namefile , char manhom[] , char malophocphan[]) {
	ofstream o;
	o.open(namefile, ios::app);
	o << manhom << endl;
	o << malophocphan << endl;
	o.close();
}
 void Admin::updateNhom_LopHP(Nhom_LopHP& s) {
	char manhom[6];
	char malophocphan[16];
	cin.getline(manhom, 6);
	cin.getline(malophocphan, 16);
	s = Nhom_LopHP(manhom, malophocphan);
}
 void Admin::xoafilelhpBy_mlhp(const string filename, char* malhp) {
	 LopHocPhan* dslhp = getfromfileLopHocPhan(filename);
	 ofstream o, o1;
	 o1.open("LichSuThayDoi.txt", ios::app);
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 for (int i = 1; i <= size_dslhp; i++) {
		 if (strcmp(dslhp[i].getmalophocphan(), malhp) == 0)
		 {
			 o.open(filename, ios::trunc);
			 for (int j = 1; j < i; j++)
			 {
				 o << dslhp[j];

			 }
			 for (int j = i + 1; j <= size_dslhp; j++)
			 {
				 o << dslhp[j];
			 }
			 o1 << "Xoa Lop Hoc Phan " << dslhp[i].getmalophocphan() << " | " << "thoi gian: " << dt;

			 size_dslhp--;
			 break;
		 }
	 }
	 o.close();
 }
 void Admin::xoasvBy_mssv_InfileSV(const string filename, char* mssv) {
	 SinhVien* dssv = getfromfileSinhVien(filename);
	 ofstream o, o1;
	 o1.open("LichSuThayDoi.txt", ios::app);
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 for (int i = 1; i <= size_dssv; i++) {
		 if (strcmp(dssv[i].getMSSV(), mssv) == 0)
		 {
			 o.open(filename, ios::trunc);
			 for (int j = 1; j < i; j++)
			 {
				 o << dssv[j];
			 }
			 for (int j = i + 1; j <= size_dssv; j++)
			 {
				 o << dssv[j];
			 }
			 size_dssv--;
			 o1 << "Xoa Sinh Vien " << mssv << " | " << "thoi gian: " << dt;
			 break;
		 }
	 }
	 o.close();
	 o1.close();

 }
 void Admin::xoaLhpSv_Bixoa_Dadk_Bymssv_infilelhpsv(const string namefilelhpsv, const string namefileSinhVien, char* mssv, const string namefilelhp) {
	 Lophp_SV* dsLophp_Sv = getfromfileLophp_SV(namefilelhpsv);
	 SinhVien* dssv = getfromfileSinhVien(namefileSinhVien);
	 LopHocPhan* dslhp = getfromfileLopHocPhan(namefilelhp);
	 int d = getsv(mssv, dssv, size_dssv).getsohpdadk();
	 Lophp_SV* t = new  Lophp_SV[size_dslhp_sv - d + 1];
	 ofstream o;
	 t[0] = Lophp_SV("0");
	 o.open(namefilelhpsv, ios::trunc);
	 int j = 0;
	 for (int i = 1; i <= size_dslhp_sv; i++) {
		 if (strcmp(dsLophp_Sv[i].getMSSV(), mssv) == 0) {
			 d--;
			 for (int k = 1; k <= size_dslhp; k++) {
				 if (strcmp(dslhp[k].getmalophocphan(), dsLophp_Sv[i].getmalophocphan()) == 0)
					 dslhp[k].setsoluongdk(dslhp[k].getsoluongdk() - 1);
			 }
			 if (d == 0) break;
		 }
		 else t[++j] = dsLophp_Sv[i];
	 }
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 size_dslhp_sv = j;
	 delete[] dsLophp_Sv;
	 delete[] dssv;
	 setfilelhp(namefilelhp, dslhp);
	 setfileLophp_sv(namefilelhpsv, t);
	 o.close();


 }
 void Admin::xoaSV(const string namefileSV, const string namefileLhp_Sv, const string namefilelhp, char* mssv) {
	 xoaLhpSv_Bixoa_Dadk_Bymssv_infilelhpsv(namefileLhp_Sv, namefileSV, mssv, namefilelhp);//xóa lhp sv đã đk
	 XoaUser_ByMSSV("Users.txt", mssv);//xoa tk mk cua sv do
	 xoasvBy_mssv_InfileSV(namefileSV, mssv);//xóa sv đó ra khỏi file sv
 }
 void Admin::XoaUser_ByMSSV(const string namefile, char* mssv) {
	 User* dsuser = getfromfileUsers(namefile);
	 ofstream o, o1;
	 o1.open("LichSuThayDoi.txt", ios::app);
	 for (int i = 1; i <= size_dssv; i++) {
		 if (strcmp(dsuser[i].getMSSV(), mssv) == 0)
		 {
			 o.open(namefile, ios::trunc);
			 for (int j = 1; j < i; j++)
			 {
				 o << dsuser[j].getMSSV() << endl;
				 o << dsuser[j].getmk() << endl;

			 }
			 for (int j = i + 1; j <= size_dssv; j++)
			 {
				 o << dsuser[j].getMSSV() << endl;
				 o << dsuser[j].getmk() << endl;
			 }

			 break;
		 }
	 }
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 o1 << "Xoa User " << mssv << " | " << "thoi gian: " << dt;
	 o.close();
	 o1.close();
 }
 void Admin::XoaGv_FromFileGV_ByMaGv(const string namefileGv, char* magv) {
	 GiangVien* dsgv = getfromfileGiangVien(namefileGv);
	 ofstream o, o1;
	 o1.open("LichSuThayDoi.txt", ios::app);
	 for (int i = 1; i <= size_dsgv; i++) {
		 if (strcmp(dsgv[i].getmagiangvien(), magv) == 0)
		 {
			 o.open(namefileGv, ios::trunc);
			 for (int j = 1; j < i; j++)
			 {
				 o << dsgv[j];
			 }
			 for (int j = i + 1; j <= size_dsgv; j++)
			 {
				 o << dsgv[j];
			 }
			 size_dsgv--;
			 break;
		 }
	 }
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 o1 << "Xoa Giao Vien " << magv << " | " << "thoi gian: " << dt;
	 o.close();
	 o1.close();

 }
 void Admin::xoaLhp_InfileLhp_ByMaGv(const string namefileLhp, char* magv) {
	 LopHocPhan* dslhp = getfromfileLopHocPhan(namefileLhp);
	 ofstream o1, o2;
	 int kt[1000];
	 for (int i = 1; i <= size_dslhp; i++)
		 kt[i] = 1;
	 o2.open("LichSuThayDoi.txt", ios::app);
	 o1.open(namefileLhp, ios::trunc);
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 for (int i = 1; i <= size_dslhp; i++)
		 if (strcmp(dslhp[i].getmagv(), magv) == 0) {
			 kt[i] = 0;
		 }
	 for (int i = 1; i <= size_dslhp; i++) {
		 if (kt[i]) { o1 << dslhp[i]; }
		 else {
			 o2 << "Xoa Lop Hoc Phan " << dslhp[i].getmalophocphan() << " | " << "thoi gian: " << dt;
		 }
	 }
	 o1.close();
	 o2.close();
 }
 void Admin::XoaGV(const string namefileGV, const string namefileLhp, const string namefileLhpsv, char* magv) {
	 XoaGv_FromFileGV_ByMaGv(namefileGV, magv);//xóa gv đó		 
	 xoaLhp_InfileLhp_ByMaGv(namefileLhp, magv);//xóa lớp học phần có gv đó
	 LopHocPhan* dslhp = getfromfileLopHocPhan(namefileLhp);
	 int size = size_dslhp;
	 for (int i = 1; i <= size; i++) {
		 if (strcmp(dslhp[i].getmagv(), magv) == 0)
			 XoaLhp(namefileLhp, namefileLhpsv, dslhp[i].getmalophocphan());//xóa lớp học phần có gv đó
	 }
 }
 void Admin::XoaLhp_SvDadk_ByMaLhp(const string namefilelhpsv, char* malhp) {
	 Lophp_SV* dslhp_sv = getfromfileLophp_SV(namefilelhpsv);
	 ofstream o;
	 int j = 0;
	 o.open(namefilelhpsv, ios::trunc);
	 for (int i = 1; i <= size_dslhp_sv; i++) {
		 if (strcmp(dslhp_sv[i].getmalophocphan(), malhp) != 0)
		 {
			 o << dslhp_sv[i].getmalophocphan() << endl;
			 o << dslhp_sv[i].getMSSV() << endl;
			 j++;
		 }
	 }
	 size_dslhp_sv -= j;
 }
 void Admin::XoaLhp(const string namefilelhp, const string namefilelhpsv, char* malhp) {
	 XoaLhp_SvDadk_ByMaLhp(namefilelhpsv, malhp);//xoa lhp ma sv da dk
	 xoafilelhpBy_mlhp(namefilelhp, malhp);
 }
 void Admin::xoaLhp_ByMaHp(const string namefileLhp, const string namefilelhpsv, char* mahp) {
	 LopHocPhan* dslhp = getfromfileLopHocPhan(namefileLhp);
	 ofstream o1;
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 int size = size_dslhp;

	 for (int i = 1; i <= size; i++)
		 if (strcmp(dslhp[i].getmahocphan(), mahp) == 0) {

			 XoaLhp(namefileLhp, namefilelhpsv, dslhp[i].getmalophocphan());
		 }
 }
 void Admin::xoafileHpBy_mahp(const string namefilehp, char* mahp) {
	 HocPhan* dshp = getfromfileHocPhan(namefilehp);
	 ofstream o1, o;
	 o1.open("LichSuThayDoi.txt", ios::app);
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 for (int i = 1; i <= size_dshp; i++)
	 {
		 if (strcmp(dshp[i].getmahocphan(), mahp) == 0) {
			 o.open(namefilehp, ios::trunc);

			 for (int j = 1; j < i; j++)
				 o << dshp[j];
			 for (int j = i + 1; j <= size_dshp; j++)
				 o << dshp[j];
			 size_dshp--;
			 o1 << "Xoa hoc phan " << mahp << " | " << "thoi gian: " << dt;
			 break;
		 }
	 }
	 o1.close();
	 o.close();

 }
 void Admin::XoaHp(const string namefilehp, const string namefilelhp, const string namefilelhp_sv, char* mahp) {
	 xoaLhp_ByMaHp(namefilelhp, namefilelhp_sv, mahp);
	 xoafileHpBy_mahp(namefilehp, mahp);
 }
 void Admin::reset_mk(const string namefileUser, const string namefilesv, char* mssv) {
	 SinhVien* dssv = getfromfileSinhVien(namefilesv);
	 User* dsur = getfromfileUsers(namefileUser);
	 ofstream o, o1;
	 o.open(namefileUser, ios::trunc);
	 o1.open("LichSuThayDoi.txt", ios::app);
	 for (int i = 1; i <= size_dssv; i++) {
		 if (strcmp(dssv[i].getMSSV() , mssv) == 0 ) {
			 o << dssv[i].getMSSV() << endl;
			 o << dssv[i].getsdt() << endl;
		 }
		 else {
			 o << dsur[i].getMSSV() << endl;
			 o << dsur[i].getmk() << endl;
		 }
	 }
	 time_t now = time(0);
	 char* dt = ctime(&now);
	 o1 << "Reset mat khau cua User co MSSV " << mssv << " | " << "thoi gian: " << dt;
	 o.close();
	 o1.close();
 }