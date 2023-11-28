#include "TKB.h"
ostream& operator<<(ostream& o, ThoiKhoaBieu const& tkb) {
	o << tkb.thu << endl;
	o << tkb.tietbatdau << endl;
	o << tkb.tietketthuc << endl;
	o << tkb.phonghoc << endl;
	return o;
}
