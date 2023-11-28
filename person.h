#pragma once
#include<string>
class person // cho thằng giangvien hs, adimin kế thừa,
{
	char hoten[50];
	char email[50];
	char sdt[15];
	bool gioitinh;
public:
	person() {};
	person(char ht[50], char em[50], char st[15], bool gt) {
		strcpy_s(hoten, strlen(ht) + 1, ht);
		strcpy_s(email, strlen(em) + 1, em);
		strcpy_s(sdt, strlen(st) + 1, st);
		gioitinh = gt;
	}
	char* gethoten() {
		return hoten;
	}
	void sethoten(char ht[50]) {
		strcpy_s(hoten, strlen(ht) + 1, ht);
	}
	char* getemail() {
		return email;
	}
	void setemail(char em[50]) {
		strcpy_s(email, strlen(em) + 1, em);
	}
	char* getsdt() {
		return sdt;
	}
	void setsdt(char st[15]) {
		strcpy_s(sdt, strlen(st) + 1, st);
	}
	bool getgioitinh() {
		return gioitinh;
	}
	void setgioitinh(bool gt) {
		gioitinh = gt;
	}
};

