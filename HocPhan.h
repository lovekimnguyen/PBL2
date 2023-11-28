#include<string>
#include <fstream>
using namespace std;
#pragma once
class HocPhan
{
	char mahocphan[8];
	char tenhocphan[50];
	double tchi;
public:
	HocPhan() {};
	HocPhan(const char* mahp) {
		strcpy_s(mahocphan, strlen(mahp) + 1, mahp);
	}
	HocPhan(char* mahp, char tenhp[50], double tinchi ) {
		strcpy_s(mahocphan, strlen(mahp) + 1, mahp);
		strcpy_s(tenhocphan, strlen(tenhp) + 1, tenhp);
		tchi = tinchi;
	}
	char* getmahocphan() {
		return mahocphan;
	}
	void setmahocphan(char mahp[7]) {
		
		strcpy_s(mahocphan, strlen(mahp) + 1, mahp);
	}
	char* gettenhocphan() {
		return tenhocphan;
	}
	void settenhocphan(char tenhp[50]) {
		
		strcpy_s(tenhocphan, strlen(tenhp) + 1, tenhp);
	}
	double gettchi() {
		return tchi;
	 }
	void settchi(double tinchi) {
		tchi = tinchi;
	}
	friend ofstream& operator <<(ofstream& o, HocPhan& hp);
};

