#include "GIangVien.h"
ofstream& operator <<(ofstream& o, GiangVien& gv) {
	o << gv.magiangvien << endl;
	o << gv.gethoten() << endl;
	o << gv.getemail() << endl;
	o << gv.getsdt() << endl;
	o << gv.getgioitinh() << endl;
	return o;
}
