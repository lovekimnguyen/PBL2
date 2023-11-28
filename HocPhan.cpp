#include "HocPhan.h"
ofstream& operator <<(ofstream& o, HocPhan& hp) {
	o << hp.mahocphan << endl;
	o << hp.tenhocphan << endl;
	o << hp.tchi << endl;
	return o;
}
