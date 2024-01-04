#include "Func.h"
#include "TKB.h" 

void SinhVien::themLophp_SV(const string namefilelhp_sv, const string namefilelhp,
	char  malophocphan[16], LopHocPhan* dslophocphan, unsigned int size_dslhp, HocPhan* dshp,
	unsigned int size_dshp) {
	int l;
	for (unsigned int i = 1; i <= size_dslhp; i++) {
		if (strcmp(dslophocphan[i].getmalophocphan(), malophocphan) == 0) {
			l = i; break;
		}
	}
	LopHocPhan lhp = dslophocphan[l];

	int soldadk = lhp.getsoluongdk() + 1;
	double k = getHocPhan(lhp.getmahocphan(), dshp, size_dshp).gettchi();
	if (sotcdadk + k < sotcmax && soldadk < lhp.getsoluongmo()) {
		dslophocphan[l].setsoluongdk(dslophocphan[l].getsoluongdk() + 1);
		ofstream o1;
		o1.open(namefilelhp_sv, ios::app);
		o1 << malophocphan << endl;
		o1 << MSSV << endl;
		sohpdadk++;
		size_dslhp_sv++;
		sotcdadk += k;
		o1.close();
	}
	setfilelhp(namefilelhp, dslophocphan);
}
void SinhVien::xoaLophp_SV(const string namefilelhp_sv, const string namefilelhp,
	char  malophocphan[16],
	HocPhan* dshp, LopHocPhan* dslophocphan, ThoiKhoaBieu*& ds_TKB, LopHocPhan*& dslhpsv_dadk) {
	if (sotcdadk > 0) {
		int l;
		for (unsigned int i = 1; i <= size_dslhp; i++) {
			if (strcmp(dslophocphan[i].getmalophocphan(), malophocphan) == 0) {
				l = i; break;
			}
		}
		LopHocPhan lhp = dslophocphan[l];
		ofstream o1;
		o1.open(namefilelhp_sv, ios::app);
		sotcdadk -= getHocPhan(lhp.getmahocphan(), dshp, size_dshp).gettchi();
		Lophp_SV* dslhp_sv = getfromfileLophp_SV(namefilelhp_sv);
		for (int i = 1; i <= sohpdadk; i++) {
			if (strcmp(dslhp_sv[i].getmalophocphan(), malophocphan) == 0
				&& strcmp(dslhp_sv[i].getMSSV(), MSSV) == 0)
			{
				dslophocphan[l].setsoluongdk(dslophocphan[l].getsoluongdk() - 1);
				Lophp_SV* t = new Lophp_SV[sohpdadk + 3];
				for (int j = 0; j <= i - 1; j++)
					t[j] = dslhp_sv[j];
				for (int j = i + 1; j <= sohpdadk; j++)
					t[j - 1] = dslhp_sv[j];
				delete[] dslhp_sv;
				dslhp_sv = t;
				sohpdadk--; size_dslhp_sv--;
				lhp.setsoluongdk(lhp.getsoluongdk() - 1);
				break;
			}
		}
		setfileLophp_sv(namefilelhp_sv, dslhp_sv);
		setfilelhp(namefilelhp, dslophocphan);
		dslhpsv_dadk = getfromfilelhpdadk(namefilelhp_sv, dslophocphan, size_dslhp, dshp, size_dshp);
		ds_TKB = getTKB_SVdadk(dslhpsv_dadk);
		o1.close();
	}
}
LopHocPhan* SinhVien::getfromfilelhpdadk(const string namefile,
	LopHocPhan* dslophocphan, unsigned int size_dslhp, HocPhan* dshp, unsigned int size_dshp) {
	size_dslhp_sv = 0;
	sotcdadk = 0;
	sohpdadk = 0;
	ifstream in;
	in.open(namefile);
	char malophocphan[16];
	char mssv[10];

	while (!in.eof()) {
		in.getline(malophocphan, 16);
		if (in.eof()) break;
		in.getline(mssv, 10);
		if (strcmp(mssv, MSSV) == 0)
			sohpdadk++;
		size_dslhp_sv++;
	}

	in.close();
	in.open(namefile);
	LopHocPhan* ds_lhp_dadk = new LopHocPhan[sohpdadk + 1];
	ds_lhp_dadk[0] = LopHocPhan("0");
	int j = 1;
	for (int i = 1; i <= size_dslhp_sv; i++) {
		in.getline(malophocphan, 16);
		in.getline(mssv, 10);

		if (strcmp(mssv, MSSV) == 0)
		{
			ds_lhp_dadk[j] = getLHP(malophocphan, dslophocphan, size_dslhp);
			// cout<< ds_lhp_dadk[j].getmahocphan() <<endl;
			double k = getHocPhan(ds_lhp_dadk[j].getmahocphan(), dshp, size_dshp).gettchi();
			sotcdadk += k;
			j++;
		}
	}

	in.close();
	return ds_lhp_dadk;
}
ThoiKhoaBieu* SinhVien::getTKB_SVdadk(LopHocPhan* ds_lhp_dadk) {
	ThoiKhoaBieu* dsTKB_dadk = new ThoiKhoaBieu[sohpdadk + 1];
	for (int i = 1; i <= sohpdadk; i++) {
		dsTKB_dadk[i] = ds_lhp_dadk[i].gettkb();

	}
	// cout << ds_lhp_dadk[i].gettkb();
	return  dsTKB_dadk;
}
HocPhan* SinhVien::gethp_svchuadk(const string namefile_hp, LopHocPhan* ds_lhp_dadk) {
	HocPhan* dshp = getfromfileHocPhan(namefile_hp);
	HocPhan* dshp_svchuadk = new HocPhan[1000];
	int index = 1;
	int ex = 0;
	for (int i = 1; i <= size_dshp; i++) {
		for (int j = 1; j <= sohpdadk; j++) {
			if (strcmp(dshp[i].getmahocphan(), ds_lhp_dadk[j].getmahocphan()) == 0) {
				ex = 1;
				break;
			}
		}
		if (ex == 1) {
			ex = 0;
			continue;
		}
		dshp_svchuadk[index] = dshp[i];
		index++;
	}
	return dshp_svchuadk;
}
ofstream& operator <<(ofstream& o, SinhVien& sv) {

	o << sv.gethoten() << endl;
	o << sv.getemail() << endl;
	o << sv.getsdt() << endl;
	o << sv.getgioitinh() << endl;
	o << sv.getMSSV() << endl;
	o << sv.getlopsh() << endl;
	o << sv.getsotcmax() << endl;
	return o;
}