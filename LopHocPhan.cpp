#include "LopHocPhan.h"
#include<fstream>
void LopHocPhan::setT_after(ThoiKhoaBieu* tkb_sv, unsigned int size_dstkb_sv) {
	for (int i = 1; i <= size_dstkb_sv; i++)
		if (tkb_sv[i] == tkb) {
			T = true;
			return;
		}
	T = false;
	return;
}
ofstream& operator <<(ofstream& o, LopHocPhan& lhp) {
	// o << lhp.getmalophocphan() << endl;
	o << lhp.getmahocphan() << endl;
	o << lhp.getmagv() << endl;
	o << lhp.getsoluongdk() << endl;
	o << lhp.getsoluongmo() << endl;
	o << lhp.getmanhom() << endl;
	pair<unsigned short, unsigned short> tuanhoc;
	tuanhoc = lhp.gettuanhoc();
	o << tuanhoc.first << endl;
	o << tuanhoc.second << endl;
	ThoiKhoaBieu tkb = lhp.gettkb();
	o << tkb.getthu() << endl;
	o << tkb.gettietbatdau() << endl;
	o << tkb.gettietketthuc() << endl;
	o << tkb.getphonghoc() << endl;
	o << lhp.getK() << endl;
	o << lhp.getT() << endl;
	o << lhp.getG() << endl;
	o << lhp.getCLC() << endl;
	return o;
}