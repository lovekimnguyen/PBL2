#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <cstring>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_thread.h>
#include <Windows.h>
#include <iostream>
#include <cmath>
#include <cstdio>
#include "Func.h"
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#undef main

bool dangky = true;
time_t time_st;
time_t time_end;
char MSSV[10] = "102220001";
char IDAdmin[10] = "11112222";
char Seo_magv[9] = "";
char Seo_masv[9] = "";
char Seo_mahp[9] = "";
char Seo_malhp[18] = "";
char Seo_magr[5] = "";
void TrangChu();
void DangNhapSV();
void DangNhapAdmin();
void Dangkitinchi();
void Huytc();
void Dangkithemtc();
void DanhsachHP(HocPhan hp_sv_chdky);
void QuanliDkytc();
void Demo_GiangVien();
void Demo_SinhVien();
void Demo_HocPhan();
void Demo_Nhom();
void Help();
void Demo_LopHocPhan();
void DoiMatKhau();
void XacNhanHuytc(LopHocPhan* lhpdk_sv, int position, SinhVien& sv);
void XacNhanDkytc(LopHocPhan* lhpdk_sv, int position, SinhVien& sv);
void ChinhSuaGV(GiangVien& v);
void XacNhanXoaGV(GiangVien v);
int DemSoChuSo(int n);
void Text(int x, int y, const char s[], SDL_Surface* screen, TTF_Font* font, SDL_Color textColor);
char* intToCharArray(int number);
int charToInt(char c) {
    return c - '0';
}
void ThongtinGV(GiangVien v , SDL_Surface* screen , int index_y);
void ThongtinLHP(LopHocPhan lhp, SDL_Surface* screen, int index_y);
void ThemGV();
void BG_HopThoai(int x, int y, int z, int t, SDL_Surface* screen);
void ThemSV();
void ThongtinSV(SinhVien v, SDL_Surface* screen, int index_y);
void ThongtinHocPhan(HocPhan p, SDL_Surface* screen, int index_y);
void XacNhanXoaSV(SinhVien v);
void XacNhanXoaLHP(LopHocPhan lhp);
void XacNhanXoaHocPhan(HocPhan p);
void ChinhSuaSV(SinhVien& v);
void ChinhSuaLHP(LopHocPhan& lhp);
void XacNhanResetPW(SinhVien v);
void DoiMatKhauSV();
void ThemLHP();

void XacNhanXoaLHP(LopHocPhan lhp) {
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    int gd = DETECT, gm;
    char ok[] = "OK";
    char cancel[] = "CANCEL";
    string title = "Xac nhan xoa Lop HP co ma " + string(lhp.getmalophocphan());
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    initwindow(800, 120, "Xac nhan xoa lop hoc phan"); // graphics.h
    setbkcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, getmaxx(), getmaxy());
    setcolor(RED);
    rectangle(150, 50, 250, 80);
    rectangle(400, 50, 520, 80);
    setcolor(BLACK);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(180, 55, ok);
    outtextxy(420, 55, cancel);
    outtextxy(50, 10, title_ctr);
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 150 && x < 250 && y > 50 && y < 80) {
                AD.XoaLhp("LopHocPhan.txt", "LopHocPhan_SinhVien.txt", lhp.getmalophocphan());
                closegraph();
                Demo_LopHocPhan();
                return;
            }
            else if (x > 400 && x < 520 && y > 50 && y < 80) {
                closegraph();
                return;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}
void ThongtinLHP(LopHocPhan lhp, SDL_Surface* screen, int index_y) {
    HocPhan* dshp = getfromfileHocPhan("HocPhan.txt");
    GiangVien* dsgv = getfromfileGiangVien("GiangVien.txt");
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Color textColor = { 0,0,0 }; // đen
    BG_HopThoai(911, 210, 330, 420, screen);
    Uint32 Color = SDL_MapRGB(screen->format, 58, 189, 72);
    SDL_Rect textBox;
    textBox.x = 911;
    textBox.y = index_y;
    textBox.w = 330;
    textBox.h = 230;
    SDL_FillRect(screen, &textBox, Color);
    char* tenhp = getHocPhan(lhp.getmahocphan(), dshp, size_dshp).gettenhocphan();
    char* malhp = lhp.getmalophocphan();
    char* tengv = getGV("GiangVien.txt", lhp.getmagv()).gethoten();
    char* sl = intToCharArray(lhp.getsoluongmo());
    string tuanhoc = TuanHocinchar(lhp.gettuanhoc());
    const char* tuanhoc_ctr = tuanhoc.c_str();
    string tkb = TKBinchar(lhp.gettkb());
    const char* tkb_ctr = tkb.c_str();
    Text(921, index_y + 10, " - Ten Hoc Phan : ", screen, font_h1, textColor);
    Text(921, index_y + 40, " - Ma Lop HP : ", screen, font_h1, textColor);
    Text(921, index_y + 70, " - GV giang day : ", screen, font_h1, textColor);
    Text(921, index_y + 100, " - So luong dang ky : ", screen, font_h1, textColor);
    Text(921, index_y + 130, " - Tuan hoc : ", screen, font_h1, textColor);
    Text(921, index_y + 160, " - Thoi khoa bieu : ", screen, font_h1, textColor);
    Text(921, index_y + 190, " - Chat luong cao: ", screen, font_h1, textColor);
    Text(1060, index_y + 10, tenhp, screen, font_h1, textColor);
    Text(1060, index_y + 40, malhp, screen, font_h1, textColor);
    Text(1060, index_y + 70, tengv, screen, font_h1, textColor);
    Text(1080, index_y + 100, sl, screen, font_h1, textColor);
    Text(1020, index_y + 130, tuanhoc_ctr, screen, font_h1, textColor);
    Text(1060, index_y + 160, tkb_ctr, screen, font_h1, textColor);
    Text(1060, index_y + 190, lhp.getCLC() ? "Co" : "Khong", screen, font_h1, textColor);
    SDL_Flip(screen);
}
void HopThoai(int x, int y, int z, int t, SDL_Surface* screen) {
    Uint32 borderColor = SDL_MapRGB(screen->format, 255, 0, 0);
    Uint32 Color = SDL_MapRGB(screen->format, 255, 255, 255);
    SDL_Rect textBox;
    textBox.x = x;
    textBox.y = y;
    textBox.w = z;
    textBox.h = t;
    SDL_FillRect(screen, &textBox, borderColor); // màu viền 
    SDL_Rect borderRect = textBox;
    borderRect.w -= 2;
    borderRect.h -= 2;
    borderRect.x += 1;
    borderRect.y += 1;
    // Vẽ màu trong hình chữ nhật
    SDL_FillRect(screen, &borderRect, Color);
}
void BG_HopThoai(int x, int y, int z, int t, SDL_Surface* screen) {
    Uint32 Color = SDL_MapRGB(screen->format, 255, 255, 255);
    SDL_Rect textBox;
    textBox.x = x;
    textBox.y = y;
    textBox.w = z;
    textBox.h = t;
    SDL_FillRect(screen, &textBox, Color);
}
int DemSoChuSo(int n) {
    int count = 0;
    // Kiểm tra từng chữ số của số nguyên n
    while (n != 0) {
        n = n / 10;
        count++;
    }
    return count;
}
char* intToCharArray(int number) {
    string str = to_string(number);
    char* charArray = new char[str.length() + 1]; 
    for (size_t i = 0; i < str.length(); ++i) {
        charArray[i] = str[i];
    }
    charArray[str.length()] = '\0';
    return charArray;
}
double charArrayToDouble(const char* arr) {
    std::istringstream iss(arr);
    double result;
    iss >> result;
    return result;
}
void doubleToCharArray(double value, char* resultArray, int bufferSize) {
    std::snprintf(resultArray, bufferSize, "%f", value);
}
void SELECT_HopThoai(int x, int y, int z, int t, SDL_Surface* screen) {
    Uint32 Color = SDL_MapRGB(screen->format, 232, 119, 53);
    SDL_Rect textBox;
    textBox.x = x;
    textBox.y = y;
    textBox.w = z;
    textBox.h = t;
    SDL_FillRect(screen, &textBox, Color);
}
void Tron_HopThoai(int x, int y, int z, int t, SDL_Surface* screen) {
    Uint32 Color = SDL_MapRGB(screen->format, 209, 216, 227);
    SDL_Rect textBox;
    textBox.x = x;
    textBox.y = y;
    textBox.w = z;
    textBox.h = t;
    int cornerRadius = 50;
    SDL_FillRect(screen, &textBox, Color);
    SDL_Rect cornerRect;
    cornerRect.x = textBox.x;
    cornerRect.y = textBox.y;
    cornerRect.w = cornerRadius;
    cornerRect.h = cornerRadius;
    SDL_FillRect(screen, &cornerRect, Color);
    cornerRect.x = textBox.x + textBox.w - cornerRadius;
    SDL_FillRect(screen, &cornerRect, Color);
    cornerRect.x = textBox.x;
    cornerRect.y = textBox.y + textBox.h - cornerRadius;
    SDL_FillRect(screen, &cornerRect, Color);
    cornerRect.x = textBox.x + textBox.w - cornerRadius;
    cornerRect.y = textBox.y + textBox.h - cornerRadius;
    SDL_FillRect(screen, &cornerRect, Color);
}
void DrawLine(SDL_Surface* surface, int x1, int y1, int x2, int y2, Uint32 color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    while (x1 != x2 || y1 != y2) {
        if (x1 >= 0 && x1 < surface->w && y1 >= 0 && y1 < surface->h) {
            Uint8* pixel = (Uint8*)surface->pixels + y1 * surface->pitch + x1 * surface->format->BytesPerPixel;
            *(Uint32*)pixel = color;
        }
        int e2 = 2 * err;
        if (e2 > -dy) {
            err = err - dy;
            x1 = x1 + sx;
        }
        if (e2 < dx) {
            err = err + dx;
            y1 = y1 + sy;
        }
    }
}
void Text(int x, int y, const char s[], SDL_Surface* screen, TTF_Font* font, SDL_Color textColor) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, s, textColor);
    SDL_Rect textRect;
    textRect.x = x;
    textRect.y = y;
    SDL_BlitSurface(textSurface, NULL, screen, &textRect);
    SDL_FreeSurface(textSurface);
}
void Image(int x, int y, SDL_Surface* image, SDL_Surface* screen) {
    SDL_Rect imageRect;
    imageRect.x = x;
    imageRect.y = y;
    SDL_BlitSurface(image, NULL, screen, &imageRect);
    SDL_FreeSurface(image);
}
void Back(SDL_Surface* screen, int x, int y) {
    Uint32 Color = SDL_MapRGB(screen->format, 0, 0, 0);
    SDL_Color textColor = { 0,0,0 }; // đen
    DrawLine(screen, x, y, x + 20, y - 20, Color);
    DrawLine(screen, x, y, x + 20, y + 20, Color);
    DrawLine(screen, x + 20, y - 20, x + 80, y - 20, Color);
    DrawLine(screen, x + 20, y + 20, x + 80, y + 20, Color);
    DrawLine(screen, x + 80, y - 20, x + 80, y + 20, Color);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 20);
    Text(x + 20, y - 10, "BACK", screen, font_h2, textColor);
}
void Alert(char n1[], char n2[], const char title[]) {
    int gd = DETECT, gm;
    char ok[] = "OK";
    initwindow(800, 120, title); // graphics.h
    setbkcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, getmaxx(), getmaxy());
    setcolor(RED);
    rectangle(250, 60, 350, 90);
    setcolor(BLACK);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(5, 5, n1);
    outtextxy(5, 30, n2);
    outtextxy(280, 65, ok);
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 250 && x < 350 && y > 60 && y < 90) {
                closegraph();
                return;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}
void XacNhanHuytc(LopHocPhan* lhpdk_sv, int position, SinhVien& sv) {
    int gd = DETECT, gm;
    char ok[] = "OK";
    char cancel[] = "CANCEL";
    string title = "Xac nhan huy lop hoc phan " + string(lhpdk_sv[position].getmalophocphan());
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    HocPhan* hp = getfromfileHocPhan("HocPhan.txt");
    LopHocPhan* lhp = getfromfileLopHocPhan("LopHocPhan.txt");
    initwindow(800, 120, "Xac nhan huy tin chi"); // graphics.h
    setbkcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, getmaxx(), getmaxy());
    setcolor(RED);
    rectangle(150, 50, 250, 80);
    rectangle(400, 50, 520, 80);
    setcolor(BLACK);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
    ThoiKhoaBieu* tkb_sv = sv.getTKB_SVdadk(lhpdk_sv);
    outtextxy(180, 55, ok);
    outtextxy(420, 55, cancel);
    outtextxy(50, 10, title_ctr);
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 150 && x < 250 && y > 50 && y < 80) {
                sv.xoaLophp_SV("LopHocPhan_SinhVien.txt", "LopHocPhan.txt", lhpdk_sv[position].getmalophocphan(), hp, lhp, tkb_sv, lhpdk_sv);
                closegraph();
                Dangkitinchi();
                return;
            }
            else if (x > 400 && x < 520 && y > 50 && y < 80) {
                closegraph();
                return;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}
void XacNhanDkytc(LopHocPhan* lhpdk_sv, int position, SinhVien& sv) {
    int gd = DETECT, gm;
    char ok[] = "OK";
    char cancel[] = "CANCEL";
    string title = "Xac nhan dang ky lop hoc phan " + string(lhpdk_sv[position].getmalophocphan());
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    HocPhan* hp = getfromfileHocPhan("HocPhan.txt");
    LopHocPhan* lhp = getfromfileLopHocPhan("LopHocPhan.txt");
    initwindow(800, 120, "Xac nhan dang ky tin chi"); // graphics.h
    setbkcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, getmaxx(), getmaxy());
    setcolor(RED);
    rectangle(150, 50, 250, 80);
    rectangle(400, 50, 520, 80);
    setcolor(BLACK);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(180, 55, ok);
    outtextxy(420, 55, cancel);
    outtextxy(50, 10, title_ctr);
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 150 && x < 250 && y > 50 && y < 80) {
                sv.themLophp_SV("LopHocPhan_SinhVien.txt", "LopHocPhan.txt", lhpdk_sv[position].getmalophocphan(), lhp, size_dslhp, hp, size_dshp);
                closegraph();
                Dangkitinchi();
                return;
            }
            else if (x > 400 && x < 520 && y > 50 && y < 80) {
                closegraph();
                return;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}
void XacNhanXoaGV(GiangVien v) {
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    int gd = DETECT, gm;
    char ok[] = "OK";
    char cancel[] = "CANCEL";
    string title = "Xac nhan xoa Giang vien co ma " + string(v.getmagiangvien());
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    initwindow(800, 120, "Xac nhan xoa giang vien"); // graphics.h
    setbkcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, getmaxx(), getmaxy());
    setcolor(RED);
    rectangle(150, 50, 250, 80);
    rectangle(400, 50, 520, 80);
    setcolor(BLACK);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(180, 55, ok);
    outtextxy(420, 55, cancel);
    outtextxy(50, 10, title_ctr);
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 150 && x < 250 && y > 50 && y < 80) {
                AD.XoaGV("GiangVien.txt", "LopHocPhan.txt", "LopHocPhan_SinhVien.txt", v.getmagiangvien());
                closegraph();
                Demo_GiangVien();
                return;
            }
            else if (x > 400 && x < 520 && y > 50 && y < 80) {
                closegraph();
                return;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}
void XacNhanXoaSV(SinhVien v) {
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    int gd = DETECT, gm;
    char ok[] = "OK";
    char cancel[] = "CANCEL";
    string title = "Xac nhan xoa Sinh vien co ma " + string(v.getMSSV());
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    initwindow(800, 120, "Xac nhan xoa sinh vien"); // graphics.h
    setbkcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, getmaxx(), getmaxy());
    setcolor(RED);
    rectangle(150, 50, 250, 80);
    rectangle(400, 50, 520, 80);
    setcolor(BLACK);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(180, 55, ok);
    outtextxy(420, 55, cancel);
    outtextxy(50, 10, title_ctr);
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 150 && x < 250 && y > 50 && y < 80) {
                AD.xoaSV("SinhVien.txt", "LopHocPhan_SinhVien.txt", "LopHocPhan.txt" , v.getMSSV());
                closegraph();
                Demo_SinhVien();
                return;
            }
            else if (x > 400 && x < 520 && y > 50 && y < 80) {
                closegraph();
                return;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}
void XacNhanXoaHocPhan(HocPhan p) {
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    int gd = DETECT, gm;
    char ok[] = "OK";
    char cancel[] = "CANCEL";
    string title = "Xac nhan xoa Hoc Phan co ma " + string(p.getmahocphan());
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    initwindow(800, 120, "Xac nhan xoa Hoc Phan"); // graphics.h
    setbkcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, getmaxx(), getmaxy());
    setcolor(RED);
    rectangle(150, 50, 250, 80);
    rectangle(400, 50, 520, 80);
    setcolor(BLACK);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(180, 55, ok);
    outtextxy(420, 55, cancel);
    outtextxy(50, 10, title_ctr);
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 150 && x < 250 && y > 50 && y < 80) {
                AD.XoaHp("HocPhan.txt", "LopHocPhan.txt", "LopHocPhan_SinhVien.txt", p.getmahocphan());
                closegraph();
                Demo_HocPhan();
                return;
            }
            else if (x > 400 && x < 520 && y > 50 && y < 80) {
                closegraph();
                return;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}
void XacNhanResetPW(SinhVien v) {
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    int gd = DETECT, gm;
    char ok[] = "OK";
    char cancel[] = "CANCEL";
    string title = "Xac nhan dat lai mat khau cho Sinh vien co ma " + string(v.getMSSV());
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    initwindow(1000, 120, "Xac nhan dat lai mat khau sinh vien"); // graphics.h
    setbkcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, getmaxx(), getmaxy());
    setcolor(RED);
    rectangle(150, 50, 250, 80);
    rectangle(400, 50, 520, 80);
    setcolor(BLACK);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(180, 55, ok);
    outtextxy(420, 55, cancel);
    outtextxy(50, 10, title_ctr);
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 150 && x < 250 && y > 50 && y < 80) {
                AD.reset_mk("Users.txt", "SinhVien.txt" , v.getMSSV());
                closegraph();
                char sucssess[] = "      Dat lai mat khau thanh cong";
                char n2[] = "";
                Alert(sucssess, n2, "Dat lai mat khau thanh cong");
                Help();
                return;
            }
            else if (x > 400 && x < 520 && y > 50 && y < 80) {
                closegraph();
                return;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}

void ThemLHP() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    //
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    SELECT_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor_W);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    BG_HopThoai(280, 160, 970, 490, screen);
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    Text(290, 170, "Them Lop Hoc Phan co ma = Ma Hoc Phan + Ma Nhom :", screen, font_h1, textColor);
    HopThoai(520, 210, 400, 50, screen);
    HopThoai(520, 265, 400, 50, screen);
    HopThoai(520, 320, 200, 50, screen);
    HopThoai(980, 320, 200, 50, screen);
    HopThoai(520, 375, 200, 50, screen);
    HopThoai(980, 375, 200, 50, screen);
    HopThoai(520, 430, 200, 50, screen);
    HopThoai(520, 485, 200, 50, screen);
    HopThoai(980, 485, 200, 50, screen);
    HopThoai(520, 540, 200, 50, screen);
    HopThoai(980, 540, 200, 50, screen);
    HopThoai(700, 595, 150, 40, screen);
    Text(720, 595, "Xac nhan", screen, font_h1, textColor_RED);
    Text(290, 220, " - Hoc Phan : ", screen, font_h1, textColor);
    Text(290, 275, " - Nhom : ", screen, font_h1, textColor);
    Text(730, 330, " - MaGV Giang day : ", screen, font_h1, textColor);
    Text(290, 330, " - So luong mo : ", screen, font_h1, textColor);
    Text(290, 385, " - Tuan bat dau : ", screen, font_h1, textColor);
    Text(730, 385, " - Tuan ket thuc: ", screen, font_h1, textColor);
    Text(290, 440, " - Thu : ", screen, font_h1, textColor);
    Text(290, 495, " - Tiet bat dau: ", screen, font_h1, textColor);
    Text(730, 495, " - Tiet ket thuc: ", screen, font_h1, textColor);
    Text(290, 550, " - Phong hoc: ", screen, font_h1, textColor);
    Text(730, 550, " - Chat luong cao: ", screen, font_h1, textColor);
    // cập nhật nội dung cửa sổ
    char mahocphan[] = "";
    char manhom[] = "";
    char magv[] = "";
    char soluongmo[] = "";
    char tuanbatdau[] = "";
    char tuanketthuc[] = "";
    char thu[] = "";
    char tietbatdau[] = "";
    char tietketthuc[] = ""; 
    char phonghoc[] = "";
    char CLC[] = "";
    SDL_Flip(screen);
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    if (x > 520 && y > 210 && x < 920 && y < 260) {
                        HopThoai(520, 210, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(mahocphan);
                                        if (length > 0) {
                                            mahocphan[length - 1] = '\0';
                                        }
                                        HopThoai(520, 210, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(mahocphan, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(mahocphan);
                                            if (length > 0) {
                                                mahocphan[length - 1] = '\0';
                                            }
                                            HopThoai(520, 210, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 215;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, mahocphan, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 520 && y > 265 && x < 920 && y < 315) {
                        HopThoai(520, 265, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(manhom);
                                        if (length > 0) {
                                            manhom[length - 1] = '\0';
                                        }
                                        HopThoai(520, 265, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(manhom, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(manhom, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(manhom);
                                            if (length > 0) {
                                                manhom[length - 1] = '\0';
                                            }
                                            HopThoai(520, 265, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 270;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, manhom, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 520 && y > 320 && x < 720 && y < 370) {
                        HopThoai(520, 320, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(soluongmo);
                                        if (length > 0) {
                                            soluongmo[length - 1] = '\0';
                                        }
                                        HopThoai(520, 320, 200, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(soluongmo, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(soluongmo);
                                            if (length > 0) {
                                                soluongmo[length - 1] = '\0';
                                            }
                                            HopThoai(520, 320, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 325;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, soluongmo, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 980 && y > 320 && x < 1180 && y < 370) {
                        HopThoai(980, 320, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(magv);
                                        if (length > 0) {
                                            magv[length - 1] = '\0';
                                        }
                                        HopThoai(980, 320, 200, 50, screen);// set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= 'a' && keyPressed <= 'z')) {
                                            strncat(magv, &keyPressed, 1);
                                        }
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(magv, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(magv);
                                            if (length > 0) {
                                                magv[length - 1] = '\0';
                                            }
                                            HopThoai(980, 320, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 990;
                                textRect.y = 325;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, magv, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 520 && y > 375 && x < 720 && y < 425) {
                        HopThoai(520, 375, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(tuanbatdau);
                                        if (length > 0) {
                                            tuanbatdau[length - 1] = '\0';
                                        }
                                        HopThoai(520, 375, 200, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(tuanbatdau, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(tuanbatdau);
                                            if (length > 0) {
                                                tuanbatdau[length - 1] = '\0';
                                            }
                                            HopThoai(520, 375, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 375;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, tuanbatdau, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 980 && y > 375 && x < 1180 && y < 425) {
                        HopThoai(980, 375, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(tuanketthuc);
                                        if (length > 0) {
                                            tuanketthuc[length - 1] = '\0';
                                        }
                                        HopThoai(980, 375, 200, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(tuanketthuc, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(tuanketthuc);
                                            if (length > 0) {
                                                tuanketthuc[length - 1] = '\0';
                                            }
                                            HopThoai(980, 375, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 990;
                                textRect.y = 375;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, tuanketthuc, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 520 && y > 430 && x < 720 && y < 480) {
                        HopThoai(520, 430, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(thu);
                                        if (length > 0) {
                                            thu[length - 1] = '\0';
                                        }
                                        HopThoai(520, 430, 200, 50, screen);// set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(thu, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= 'a' && keyPressed <= 'z')) {
                                            keyPressed = (char)event.key.keysym.sym - 32;
                                            strncat(thu, &keyPressed, 1);
                                        }
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(thu, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(thu);
                                            if (length > 0) {
                                                thu[length - 1] = '\0';
                                            }
                                            HopThoai(520, 430, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 435;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, thu, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 520 && y > 485 && x < 720 && y < 535) {
                        HopThoai(520, 485, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(tietbatdau);
                                        if (length > 0) {
                                            tietbatdau[length - 1] = '\0';
                                        }
                                        HopThoai(520, 485, 200, 50, screen);// set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(tietbatdau, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(tietbatdau);
                                            if (length > 0) {
                                                tietbatdau[length - 1] = '\0';
                                            }
                                            HopThoai(520, 485, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 490;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, tietbatdau, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 980 && y > 485 && x < 1180 && y < 535) {
                        HopThoai(980, 485, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(tietketthuc);
                                        if (length > 0) {
                                            tietketthuc[length - 1] = '\0';
                                        }
                                        HopThoai(980, 485, 200, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(tietketthuc, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(tietketthuc);
                                            if (length > 0) {
                                                tietketthuc[length - 1] = '\0';
                                            }
                                            HopThoai(980, 485, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 990;
                                textRect.y = 490;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, tietketthuc, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 520 && y > 540 && x < 720 && y < 590) {
                        HopThoai(520, 540, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(phonghoc);
                                        if (length > 0) {
                                            phonghoc[length - 1] = '\0';
                                        }
                                        HopThoai(520, 540, 200, 50, screen);// set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(phonghoc, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= 'a' && keyPressed <= 'z')) {
                                            keyPressed = (char)event.key.keysym.sym - 32;
                                            strncat(phonghoc, &keyPressed, 1);
                                        }
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(phonghoc, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(phonghoc);
                                            if (length > 0) {
                                                phonghoc[length - 1] = '\0';
                                            }
                                            HopThoai(520, 540, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 545;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, phonghoc, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 980 && y > 540 && x < 1180 && y < 590) {
                        HopThoai(980, 540, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(CLC);
                                        if (length > 0) {
                                            CLC[length - 1] = '\0';
                                        }
                                        HopThoai(980, 540, 200, 50, screen);// set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(CLC, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '1') && strlen(CLC) < 1) {
                                            strncat(CLC, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(CLC);
                                            if (length > 0) {
                                                CLC[length - 1] = '\0';
                                            }
                                            HopThoai(980, 540, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 990;
                                textRect.y = 545;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, CLC, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 700 && x < 850 && y > 595 && y < 635) {
                        HocPhan* dshp = getfromfileHocPhan("HocPhan.txt");
                        GiangVien* dsgv = getfromfileGiangVien("GiangVien.txt");
                        Nhom* dsgr = getfromfileNhom("Nhom.txt");
                        char sz[10][10] = {"2","3", "4", "5", "6", "7" , "CN"};
                        int hpt = 0;
                        int gvt = 0;
                        int grt = 0;
                        int thut = 0;
                        for (int i = 1; i <= size_dshp; i++) {
                            if (strcmp(mahocphan, dshp[i].getmahocphan()) == 0) {
                                hpt = 1;
                                break;
                            }
                        }
                        for (int i = 1; i <= size_dsgv; i++) {
                            if (strcmp(magv, dsgv[i].getmagiangvien()) == 0) {
                                gvt = 1;
                                break;
                            }
                        }
                        for (int i = 1; i <= size_dsnhom; i++) {
                            if (strcmp(manhom, dsgr[i].getmanhom()) == 0) {
                                grt = 1;
                                break;
                            }
                        }
                        for (int i = 0; i < 8; i++) {
                            if (strcmp(thu, sz[i]) == 0) {
                                thut = 1;
                                break;
                            }
                        }
                        if (strcmp(mahocphan, "") == 0 || strcmp(manhom, "") == 0 || strcmp(magv, "") == 0 || strcmp(soluongmo, "") == 0 || strcmp(tuanbatdau, "") == 0 || strcmp(tuanketthuc, "") == 0 || strcmp(thu, "") == 0 || strcmp(tietbatdau, "") == 0 || strcmp(tietketthuc, "") == 0 || strcmp(phonghoc, "") == 0 || strcmp(CLC, "") == 0) {
                            char title1[] = "Vui long nhap day du thong tin !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        }
                        else if (hpt == 0) {
                            char title1[] = "Ma hoc phan khong ton tai !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        }
                        else if (gvt == 0) {
                            char title1[] = "Ma giang vien khong ton tai !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        } 
                        else if (grt == 0) {
                            char title1[] = "Ma nhom khong ton tai !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        }
                        else if (thut == 0) {
                            char title1[] = "Thu trong tuan khong hop le !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        }
                        else if (charArrayToDouble(tuanbatdau) >= charArrayToDouble(tuanketthuc)) {
                            char title1[] = "Tuan hoc khong hop le !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        }
                        else if (charArrayToDouble(tietbatdau) >= charArrayToDouble(tietketthuc)) {
                            char title1[] = "Tiet hoc khong hop le !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        }
                        else {
                            bool chatluongcao = 0;
                            if (strcmp(CLC, "1") == 0) chatluongcao = 1;
                            char n1[] = "      Xac nhan lai thong tin co ban";
                            char* tenhp = getHocPhan(mahocphan, dshp, size_dshp).gettenhocphan();
                            string xnhp = "Ten hoc phan : " + string(tenhp);
                            char* tengiangvien = getGV("GiangVien.txt" , magv).gethoten();
                            string xngv = "Ten giang vien : " + string(tengiangvien);
                            string xngr = "Ma nhom: " + string(manhom);
                            int gd = DETECT, gm;
                            char ok[] = "OK";
                            char cancel[] = "CANCEL";
                            initwindow(800, 160, "Xac nhan lai thong tin"); // graphics.h
                            setbkcolor(WHITE);
                            setfillstyle(SOLID_FILL, WHITE);
                            bar(0, 0, getmaxx(), getmaxy());
                            setcolor(RED);
                            rectangle(150, 110, 250, 140);
                            rectangle(350, 110, 460, 140);
                            setcolor(BLACK);
                            settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
                            outtextxy(5, 5, n1);
                            outtextxy(5, 30, const_cast<char*>(xnhp.c_str()));
                            outtextxy(5, 55, const_cast<char*>(xngv.c_str()));
                            outtextxy(5, 80, const_cast<char*>(xngr.c_str()));
                            outtextxy(180, 115, ok);
                            outtextxy(360, 115, cancel);
                            while (1) {
                                if (ismouseclick(WM_LBUTTONDOWN)) {
                                    int x, y;
                                    getmouseclick(WM_LBUTTONDOWN, x, y);
                                    if (x > 150 && x < 250 && y > 110 && y < 140) {
                                        AD.nhapLopHocPhan("LopHocPhan.txt", mahocphan, manhom, magv, 0, int(charArrayToDouble(soluongmo)), int(charArrayToDouble(tuanbatdau)), int(charArrayToDouble(tuanketthuc)), thu, int(charArrayToDouble(tietbatdau)), int(charArrayToDouble(tietketthuc)), phonghoc, 0, 0, 0, chatluongcao);
                                        Demo_LopHocPhan();
                                    }
                                    else if (x > 350 && x < 450 && y > 110 && y < 140) {
                                        closegraph();
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 160 && x < 270 && y < 210) {
                        QuanliDkytc();
                    }
                    if (x > 0 && y > 210 && x < 270 && y < 260) {
                        strcpy_s(Seo_magv, "");
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 260 && x < 270 && y < 310) {
                        strcpy_s(Seo_masv, "");
                        Demo_SinhVien();
                    }
                    if (x > 0 && y > 310 && x < 270 && y < 360) {
                        strcpy_s(Seo_mahp, "");
                        Demo_HocPhan();
                    }
                    if (x > 0 && y > 360 && x < 270 && y < 410) {
                        Demo_LopHocPhan();
                    }
                    if (x > 0 && y > 410 && x < 270 && y < 460) {
                        Demo_Nhom();
                    }
                    if (x > 0 && y > 460 && x < 270 && y < 510) {
                        DoiMatKhau();
                    }
                    if (x > 0 && y > 510 && x < 270 && y < 560) {
                        Help();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void ChinhSuaLHP(LopHocPhan& lhp) {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    //
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    SELECT_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor_W);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    BG_HopThoai(280, 160, 970, 490, screen);
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    Text(290, 170, "Them Lop Hoc Phan co ma = Ma Hoc Phan + Ma Nhom :", screen, font_h1, textColor);
    HopThoai(520, 210, 400, 50, screen);
    HopThoai(520, 265, 400, 50, screen);
    HopThoai(520, 320, 200, 50, screen);
    HopThoai(980, 320, 200, 50, screen);
    HopThoai(520, 375, 200, 50, screen);
    HopThoai(980, 375, 200, 50, screen);
    HopThoai(520, 430, 200, 50, screen);
    HopThoai(520, 485, 200, 50, screen);
    HopThoai(980, 485, 200, 50, screen);
    HopThoai(520, 540, 200, 50, screen);
    HopThoai(980, 540, 200, 50, screen);
    HopThoai(700, 595, 150, 40, screen);
    Text(720, 595, "Xac nhan", screen, font_h1, textColor_RED);
    Text(290, 220, " - Hoc Phan : ", screen, font_h1, textColor);
    Text(290, 275, " - Nhom : ", screen, font_h1, textColor);
    Text(730, 330, " - MaGV Giang day : ", screen, font_h1, textColor);
    Text(290, 330, " - So luong mo : ", screen, font_h1, textColor);
    Text(290, 385, " - Tuan bat dau : ", screen, font_h1, textColor);
    Text(730, 385, " - Tuan ket thuc: ", screen, font_h1, textColor);
    Text(290, 440, " - Thu : ", screen, font_h1, textColor);
    Text(290, 495, " - Tiet bat dau: ", screen, font_h1, textColor);
    Text(730, 495, " - Tiet ket thuc: ", screen, font_h1, textColor);
    Text(290, 550, " - Phong hoc: ", screen, font_h1, textColor);
    Text(730, 550, " - Chat luong cao: ", screen, font_h1, textColor);
    // cập nhật nội dung cửa sổ
    char* mahocphan = lhp.getmahocphan();
    char* manhom = lhp.getmanhom();
    char* magv = lhp.getmagv();
    char* soluongmo = intToCharArray(lhp.getsoluongmo());
    char* tuanbatdau = intToCharArray(lhp.gettuanhoc().first);
    char* tuanketthuc = intToCharArray(lhp.gettuanhoc().second);
    char* thu = lhp.gettkb().getthu();
    char* tietbatdau = intToCharArray(lhp.gettkb().gettietbatdau());
    char* tietketthuc = intToCharArray(lhp.gettkb().gettietketthuc());
    char* phonghoc = lhp.gettkb().getphonghoc();
    char* CLC = intToCharArray(lhp.getCLC());
    Text(530, 215, mahocphan, screen, font_h1, textColor);
    Text(530, 270, manhom, screen, font_h1, textColor);
    Text(990, 325,magv, screen, font_h1, textColor);
    Text(530, 325, soluongmo, screen, font_h1, textColor);
    Text(530, 375,tuanbatdau, screen, font_h1, textColor);
    Text(990, 375, tuanketthuc, screen, font_h1, textColor);
    Text(530, 435, thu, screen, font_h1, textColor);
    Text(530, 490, tietbatdau, screen, font_h1, textColor);
    Text(990, 490, tietketthuc, screen, font_h1, textColor);
    Text(530, 545, phonghoc, screen, font_h1, textColor);
    Text(990, 545,CLC, screen, font_h1, textColor);
    SDL_Flip(screen);
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    if (x > 520 && y > 210 && x < 920 && y < 260) {
                        HopThoai(520, 210, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(mahocphan);
                                        if (length > 0) {
                                            mahocphan[length - 1] = '\0';
                                        }
                                        HopThoai(520, 210, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(mahocphan, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(mahocphan);
                                            if (length > 0) {
                                                mahocphan[length - 1] = '\0';
                                            }
                                            HopThoai(520, 210, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 215;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, mahocphan, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 520 && y > 265 && x < 920 && y < 315) {
                        HopThoai(520, 265, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(manhom);
                                        if (length > 0) {
                                            manhom[length - 1] = '\0';
                                        }
                                        HopThoai(520, 265, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(manhom, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(manhom, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(manhom);
                                            if (length > 0) {
                                                manhom[length - 1] = '\0';
                                            }
                                            HopThoai(520, 265, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 270;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, manhom, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 520 && y > 320 && x < 720 && y < 370) {
                        HopThoai(520, 320, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(soluongmo);
                                        if (length > 0) {
                                            soluongmo[length - 1] = '\0';
                                        }
                                        HopThoai(520, 320, 200, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(soluongmo, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(soluongmo);
                                            if (length > 0) {
                                                soluongmo[length - 1] = '\0';
                                            }
                                            HopThoai(520, 320, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 325;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, soluongmo, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 980 && y > 320 && x < 1180 && y < 370) {
                        HopThoai(980, 320, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(magv);
                                        if (length > 0) {
                                            magv[length - 1] = '\0';
                                        }
                                        HopThoai(980, 320, 200, 50, screen);// set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= 'a' && keyPressed <= 'z')) {
                                            strncat(magv, &keyPressed, 1);
                                        }
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(magv, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(magv);
                                            if (length > 0) {
                                                magv[length - 1] = '\0';
                                            }
                                            HopThoai(980, 320, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 990;
                                textRect.y = 325;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, magv, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 520 && y > 375 && x < 720 && y < 425) {
                        HopThoai(520, 375, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(tuanbatdau);
                                        if (length > 0) {
                                            tuanbatdau[length - 1] = '\0';
                                        }
                                        HopThoai(520, 375, 200, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(tuanbatdau, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(tuanbatdau);
                                            if (length > 0) {
                                                tuanbatdau[length - 1] = '\0';
                                            }
                                            HopThoai(520, 375, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 375;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, tuanbatdau, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 980 && y > 375 && x < 1180 && y < 425) {
                        HopThoai(980, 375, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(tuanketthuc);
                                        if (length > 0) {
                                            tuanketthuc[length - 1] = '\0';
                                        }
                                        HopThoai(980, 375, 200, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(tuanketthuc, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(tuanketthuc);
                                            if (length > 0) {
                                                tuanketthuc[length - 1] = '\0';
                                            }
                                            HopThoai(980, 375, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 990;
                                textRect.y = 375;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, tuanketthuc, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 520 && y > 430 && x < 720 && y < 480) {
                        HopThoai(520, 430, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(thu);
                                        if (length > 0) {
                                            thu[length - 1] = '\0';
                                        }
                                        HopThoai(520, 430, 200, 50, screen);// set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(thu, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= 'a' && keyPressed <= 'z')) {
                                            keyPressed = (char)event.key.keysym.sym - 32;
                                            strncat(thu, &keyPressed, 1);
                                        }
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(thu, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(thu);
                                            if (length > 0) {
                                                thu[length - 1] = '\0';
                                            }
                                            HopThoai(520, 430, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 435;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, thu, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 520 && y > 485 && x < 720 && y < 535) {
                        HopThoai(520, 485, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(tietbatdau);
                                        if (length > 0) {
                                            tietbatdau[length - 1] = '\0';
                                        }
                                        HopThoai(520, 485, 200, 50, screen);// set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(tietbatdau, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(tietbatdau);
                                            if (length > 0) {
                                                tietbatdau[length - 1] = '\0';
                                            }
                                            HopThoai(520, 485, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 490;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, tietbatdau, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 980 && y > 485 && x < 1180 && y < 535) {
                        HopThoai(980, 485, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(tietketthuc);
                                        if (length > 0) {
                                            tietketthuc[length - 1] = '\0';
                                        }
                                        HopThoai(980, 485, 200, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(tietketthuc, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(tietketthuc);
                                            if (length > 0) {
                                                tietketthuc[length - 1] = '\0';
                                            }
                                            HopThoai(980, 485, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 990;
                                textRect.y = 490;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, tietketthuc, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 520 && y > 540 && x < 720 && y < 590) {
                        HopThoai(520, 540, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(phonghoc);
                                        if (length > 0) {
                                            phonghoc[length - 1] = '\0';
                                        }
                                        HopThoai(520, 540, 200, 50, screen);// set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(phonghoc, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= 'a' && keyPressed <= 'z')) {
                                            keyPressed = (char)event.key.keysym.sym - 32;
                                            strncat(phonghoc, &keyPressed, 1);
                                        }
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(phonghoc, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(phonghoc);
                                            if (length > 0) {
                                                phonghoc[length - 1] = '\0';
                                            }
                                            HopThoai(520, 540, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 530;
                                textRect.y = 545;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, phonghoc, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 980 && y > 540 && x < 1180 && y < 590) {
                        HopThoai(980, 540, 200, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(CLC);
                                        if (length > 0) {
                                            CLC[length - 1] = '\0';
                                        }
                                        HopThoai(980, 540, 200, 50, screen);// set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(CLC, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '1') && strlen(CLC) < 1) {
                                            strncat(CLC, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(CLC);
                                            if (length > 0) {
                                                CLC[length - 1] = '\0';
                                            }
                                            HopThoai(980, 540, 200, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 990;
                                textRect.y = 545;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, CLC, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 700 && x < 850 && y > 595 && y < 635) {
                        HocPhan* dshp = getfromfileHocPhan("HocPhan.txt");
                        GiangVien* dsgv = getfromfileGiangVien("GiangVien.txt");
                        Nhom* dsgr = getfromfileNhom("Nhom.txt");
                        char sz[10][10] = { "2","3", "4", "5", "6", "7" , "CN" };
                        int hpt = 0;
                        int gvt = 0;
                        int grt = 0;
                        int thut = 0;
                        for (int i = 1; i <= size_dshp; i++) {
                            if (strcmp(mahocphan, dshp[i].getmahocphan()) == 0) {
                                hpt = 1;
                                break;
                            }
                        }
                        for (int i = 1; i <= size_dsgv; i++) {
                            if (strcmp(magv, dsgv[i].getmagiangvien()) == 0) {
                                gvt = 1;
                                break;
                            }
                        }
                        for (int i = 1; i <= size_dsnhom; i++) {
                            if (strcmp(manhom, dsgr[i].getmanhom()) == 0) {
                                grt = 1;
                                break;
                            }
                        }
                        for (int i = 0; i < 8; i++) {
                            if (strcmp(thu, sz[i]) == 0) {
                                thut = 1;
                                break;
                            }
                        }
                        if (strcmp(mahocphan, "") == 0 || strcmp(manhom, "") == 0 || strcmp(magv, "") == 0 || strcmp(soluongmo, "") == 0 || strcmp(tuanbatdau, "") == 0 || strcmp(tuanketthuc, "") == 0 || strcmp(thu, "") == 0 || strcmp(tietbatdau, "") == 0 || strcmp(tietketthuc, "") == 0 || strcmp(phonghoc, "") == 0 || strcmp(CLC, "") == 0) {
                            char title1[] = "Vui long nhap day du thong tin !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        }
                        else if (hpt == 0) {
                            char title1[] = "Ma hoc phan khong ton tai !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        }
                        else if (gvt == 0) {
                            char title1[] = "Ma giang vien khong ton tai !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        }
                        else if (grt == 0) {
                            char title1[] = "Ma nhom khong ton tai !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        }
                        else if (thut == 0) {
                            char title1[] = "Thu trong tuan khong hop le !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        }
                        else if (charArrayToDouble(tuanbatdau) >= charArrayToDouble(tuanketthuc)) {
                            char title1[] = "Tuan hoc khong hop le !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        }
                        else if (charArrayToDouble(tietbatdau) >= charArrayToDouble(tietketthuc)) {
                            char title1[] = "Tiet hoc khong hop le !";
                            char title2[] = "";
                            Alert(title1, title2, "Loi");
                        }
                        else {
                            bool chatluongcao = 0;
                            if (strcmp(CLC, "1") == 0) chatluongcao = 1;
                            char n1[] = "      Xac nhan lai thong tin co ban";
                            char* tenhp = getHocPhan(mahocphan, dshp, size_dshp).gettenhocphan();
                            string xnhp = "Ten hoc phan : " + string(tenhp);
                            char* tengiangvien = getGV("GiangVien.txt", magv).gethoten();
                            string xngv = "Ten giang vien : " + string(tengiangvien);
                            string xngr = "Ma nhom: " + string(manhom);
                            int gd = DETECT, gm;
                            char ok[] = "OK";
                            char cancel[] = "CANCEL";
                            initwindow(800, 160, "Xac nhan lai thong tin"); // graphics.h
                            setbkcolor(WHITE);
                            setfillstyle(SOLID_FILL, WHITE);
                            bar(0, 0, getmaxx(), getmaxy());
                            setcolor(RED);
                            rectangle(150, 110, 250, 140);
                            rectangle(350, 110, 460, 140);
                            setcolor(BLACK);
                            settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
                            outtextxy(5, 5, n1);
                            outtextxy(5, 30, const_cast<char*>(xnhp.c_str()));
                            outtextxy(5, 55, const_cast<char*>(xngv.c_str()));
                            outtextxy(5, 80, const_cast<char*>(xngr.c_str()));
                            outtextxy(180, 115, ok);
                            outtextxy(360, 115, cancel);
                            while (1) {
                                if (ismouseclick(WM_LBUTTONDOWN)) {
                                    int x, y;
                                    getmouseclick(WM_LBUTTONDOWN, x, y);
                                    if (x > 150 && x < 250 && y > 110 && y < 140) {
                                        AD.updatelophocphan("LopHocPhan.txt", mahocphan,lhp.getmalophocphan() , manhom, magv, 0, int(charArrayToDouble(soluongmo)), int(charArrayToDouble(tuanbatdau)), int(charArrayToDouble(tuanketthuc)), thu, int(charArrayToDouble(tietbatdau)), int(charArrayToDouble(tietketthuc)), phonghoc, 0, 0, 0, chatluongcao);
                                        Demo_LopHocPhan();
                                    }
                                    else if (x > 350 && x < 450 && y > 110 && y < 140) {
                                        closegraph();
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 160 && x < 270 && y < 210) {
                        QuanliDkytc();
                    }
                    if (x > 0 && y > 210 && x < 270 && y < 260) {
                        strcpy_s(Seo_magv, "");
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 260 && x < 270 && y < 310) {
                        strcpy_s(Seo_masv, "");
                        Demo_SinhVien();
                    }
                    if (x > 0 && y > 310 && x < 270 && y < 360) {
                        strcpy_s(Seo_mahp, "");
                        Demo_HocPhan();
                    }
                    if (x > 0 && y > 360 && x < 270 && y < 410) {
                        Demo_LopHocPhan();
                    }
                    if (x > 0 && y > 410 && x < 270 && y < 460) {
                        Demo_Nhom();
                    }
                    if (x > 0 && y > 460 && x < 270 && y < 510) {
                        DoiMatKhau();
                    }
                    if (x > 0 && y > 510 && x < 270 && y < 560) {
                        Help();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void Thietlapthoigian() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    SELECT_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor_W);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 560, 270, 110, screen);
    BG_HopThoai(280, 160, 970, 490, screen);
    SDL_Flip(screen);
    Text(380, 200, "THAY DOI THOI GIAN DANG KY", screen, font_h2, textColor);
    HopThoai(780, 510, 220, 25, screen);
    Text(700, 510, "Hoac la : ", screen, font_h3, textColor);
    Text(785, 510, "Tat he thong dang ky tin chi ", screen, font_h3, textColor_RED);
    HopThoai(650, 270, 400, 50, screen);
    HopThoai(650, 350, 400, 50, screen);
    HopThoai(700, 450, 300, 50, screen);
    Text(330, 270, "Thoi gian bat dau : ", screen, font_h1, textColor);
    Text(330, 350, "Thoi gian ket thuc : ", screen, font_h1, textColor);
    Text(750, 450, "Xac nhan ", screen, font, textColor_RED);
    Text(330, 410, "Nhap thoi gian theo dinh dang dd/mm/YYYY HH:MM. Vi du : 1/1/2024 12:30",screen , font_h3 , textColor_RED);
    SDL_Flip(screen);
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        DangNhapAdmin();
                    }
                    if (x > 0 && y > 160 && x < 270 && y < 210) {
                        QuanliDkytc();
                    }
                    if (x > 0 && y > 210 && x < 270 && y < 260) {
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 260 && x < 270 && y < 310) {
                        Demo_SinhVien();
                    }
                    if (x > 0 && y > 310 && x < 270 && y < 360) {
                        Demo_HocPhan();
                    }
                    if (x > 0 && y > 360 && x < 270 && y < 410) {
                        Demo_LopHocPhan();
                    }
                    if (x > 0 && y > 410 && x < 270 && y < 460) {
                        Demo_Nhom();
                    }
                    if (x > 0 && y > 460 && x < 270 && y < 510) {
                        DoiMatKhau();
                    }
                    if (x > 0 && y > 510 && x < 270 && y < 560) {
                        Help();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void ThemGV() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    //
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    SELECT_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor_W);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    BG_HopThoai(280, 160, 970, 490, screen);
    GiangVien* dsgv = getfromfileGiangVien("GiangVien.txt");
    // xác định mã giảng viên phù hợp
    int IDGV = 1;
    char magv[100] = "";
    while (true) {
        string size_gv = "magv" + to_string(IDGV);
        for (int i = 0; i < size_gv.length(); i++) {
            magv[i] = char(size_gv[i]);
        }
        magv[size_gv.length()] = '\0';
        int check = 1;
        for (int i = 1; i <= size_dsgv; i++) {
            if (strcmp(magv, dsgv[i].getmagiangvien()) == 0) {
                check = 0;
                break;
            }
        }
        if (check == 1) {
            break;
        }
        IDGV++;
    }
    char hoten[] = "";
    char email[] = "";
    char sdt[] = "";
    bool gioitinh = 0;
    char GT[] = "";
    string title = "Thong tin Giang Vien " + string(magv) + " can them :";
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    Text(290, 170, title_ctr, screen, font_h1, textColor);
    HopThoai(550, 210, 400, 50, screen);
    HopThoai(550, 265, 400, 50, screen);
    HopThoai(550, 320, 400, 50, screen);
    HopThoai(550, 375, 400, 50, screen);
    HopThoai(700, 430, 150, 50, screen);
    Text(720, 435, "Xac nhan", screen, font_h1, textColor_RED);
    Text(290, 220, " - Ten Giang Vien : ", screen, font_h1, textColor);
    Text(290, 275, " - Email Giang Vien : ", screen, font_h1, textColor);
    Text(290, 330, " - SDT Giang Vien : ", screen, font_h1, textColor);
    Text(290, 385, " - GT Giang Vien : ", screen, font_h1, textColor);
    // cập nhật nội dung cửa sổ
    SDL_Flip(screen);
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 550 && y > 210 && x < 950 && y < 260) {
                        strcpy(hoten, "");
                        HopThoai(550, 210, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(hoten);
                                        if (length > 0) {
                                            hoten[length - 1] = '\0';
                                        }
                                        HopThoai(550, 210, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if (hoten[strlen(hoten) - 1] == ' ' || strlen(hoten) == 0) {
                                            keyPressed -= 32;
                                        }
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(hoten, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(hoten, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(hoten);
                                            if (length > 0) {
                                                hoten[length - 1] = '\0';
                                            }
                                            HopThoai(550, 210, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 215;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, hoten, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 265 && x < 950 && y < 315) {
                        strcpy(email, "");
                        HopThoai(550, 265, 400, 50, screen);
                        SDL_Flip(screen);
                        int press2 = 0;
                        int press1 = 0; // nhan shift
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(email);
                                        if (length > 0) {
                                            email[length - 1] = '\0';
                                        }
                                        HopThoai(550, 265, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_RSHIFT || event.key.keysym.sym == SDLK_LSHIFT) {
                                        press1 = 1;
                                    }
                                    else if (press1 == 1 && event.key.keysym.sym == SDLK_2) {
                                        strncat(email, "@", 1);
                                        press1 = 0;
                                    }
                                    else if (press1 == 1 && event.key.keysym.sym != SDLK_2) {
                                        press1 = 0;
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(email, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(email, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(email, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(email);
                                            if (length > 0) {
                                                email[length - 1] = '\0';
                                            }
                                            HopThoai(550, 265, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 265;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, email, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 320 && x < 950 && y < 370) {
                        strcpy(sdt, "");
                        HopThoai(550, 320, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(sdt);
                                        if (length > 0) {
                                            sdt[length - 1] = '\0';
                                        }
                                        HopThoai(550, 320, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(sdt, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(sdt, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(hoten);
                                            if (length > 0) {
                                                sdt[length - 1] = '\0';
                                            }
                                            HopThoai(550, 320, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 325;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, sdt, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 375 && x < 950 && y < 435) {
                        strcpy(GT, "");
                        HopThoai(550, 375, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(GT);
                                        if (length > 0) {
                                            GT[length - 1] = '\0';
                                        }
                                        HopThoai(550, 375, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym - 32;
                                        if ((keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(GT, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(GT, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(hoten);
                                            if (length > 0) {
                                                GT[length - 1] = '\0';
                                            }
                                            HopThoai(550, 375, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 380;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, GT, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 700 && x < 850 && y > 430 && y < 480) {
                        if (strcmp(GT, "NU") == 0) gioitinh = false;
                        else gioitinh = true;
                        char n1[] = "Vui long nhap day du thong tin";
                        char n2[] = "";
                        if (strcmp(hoten, "") == 0 || strcmp(email, "") == 0 || strcmp(sdt, "") == 0 || strcmp(GT, "") == 0) Alert(n1, n2, "Vui long nhap day du thong tin");
                        else {
                            AD.nhapGiangVien("GiangVien.txt", magv, hoten, email, sdt, gioitinh);
                            Demo_GiangVien();
                        }
                    }
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 160 && x < 270 && y < 210) {
                        QuanliDkytc();
                    }
                    if (x > 0 && y > 210 && x < 270 && y < 260) {
                        strcpy_s(Seo_magv, "");
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 260 && x < 270 && y < 310) {
                        strcpy_s(Seo_masv, "");
                        Demo_SinhVien();
                    }
                    if (x > 0 && y > 310 && x < 270 && y < 360) {
                        strcpy_s(Seo_mahp, "");
                        Demo_HocPhan();
                    }
                    if (x > 0 && y > 360 && x < 270 && y < 410) {
                        Demo_LopHocPhan();
                    }
                    if (x > 0 && y > 410 && x < 270 && y < 460) {
                        Demo_Nhom();
                    }
                    if (x > 0 && y > 460 && x < 270 && y < 510) {
                        DoiMatKhau();
                    }
                    if (x > 0 && y > 510 && x < 270 && y < 560) {
                        Help();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void ThemSV() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    //
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    SELECT_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor_W);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    BG_HopThoai(280, 160, 970, 490, screen);
    SinhVien* dssv = getfromfileSinhVien("SinhVien.txt");
    // xác định mã giảng viên phù hợp
    int IDSV = 1;
    char masv[10] = "10222";
    while (true) {
        int sl_0 = 4 - DemSoChuSo(IDSV);
        for (int i = 5; i < 5 + sl_0; i++) {
            masv[i] = '0';
        }
        char* IDSV_ctr = intToCharArray(IDSV);
        int j = 0;
        for (int i = 5 + sl_0; i < 9; i++) {
            masv[i] = IDSV_ctr[j];
            j++;
        }
        masv[strlen(masv)] = '\0';
        int check = 1;
        for (int i = 1; i <= size_dssv; i++) {
            if (strcmp(masv, dssv[i].getMSSV()) == 0) {
                check = 0;
                break;
            }
        }
        if (check == 1) {
            break;
        }
        IDSV++;
    }
    char hoten[] = "";
    char email[] = "";
    char sdt[] = "";
    bool gioitinh = 0;
    char lopsh[] = "";
    unsigned int sotcmax = 0;
    char STM[] = "";
    char GT[] = "";
    string title = "Thong tin Sinh Vien " + string(masv) + " can them :";
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    Text(290, 170, title_ctr, screen, font_h1, textColor);
    HopThoai(550, 210, 400, 50, screen);
    HopThoai(550, 265, 400, 50, screen);
    HopThoai(550, 320, 400, 50, screen);
    HopThoai(550, 375, 400, 50, screen);
    HopThoai(550, 430, 400, 50, screen);
    HopThoai(550, 485, 400, 50, screen);
    HopThoai(700, 540, 150, 50, screen);
    Text(720, 550, "Xac nhan", screen, font_h1, textColor_RED);
    Text(290, 220, " - Ten Sinh Vien : ", screen, font_h1, textColor);
    Text(290, 275, " - Email Sinh Vien : ", screen, font_h1, textColor);
    Text(290, 330, " - SDT Sinh Vien : ", screen, font_h1, textColor);
    Text(290, 385, " - GT Sinh Vien : ", screen, font_h1, textColor);
    Text(290, 440, " - Lop sinh hoat : ", screen, font_h1, textColor);
    Text(290, 495, " - So tin chi toi da : ", screen, font_h1, textColor);
    // cập nhật nội dung cửa sổ
    SDL_Flip(screen);
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 550 && y > 210 && x < 950 && y < 260) {
                        strcpy(hoten, "");
                        HopThoai(550, 210, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(hoten);
                                        if (length > 0) {
                                            hoten[length - 1] = '\0';
                                        }
                                        HopThoai(550, 210, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if (hoten[strlen(hoten) - 1] == ' ' || strlen(hoten) == 0) {
                                            keyPressed -= 32;
                                        }
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(hoten, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(hoten, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(hoten);
                                            if (length > 0) {
                                                hoten[length - 1] = '\0';
                                            }
                                            HopThoai(550, 210, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 215;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, hoten, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 265 && x < 950 && y < 315) {
                        strcpy(email, "");
                        HopThoai(550, 265, 400, 50, screen);
                        SDL_Flip(screen);
                        int press2 = 0;
                        int press1 = 0; // nhan shift
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(email);
                                        if (length > 0) {
                                            email[length - 1] = '\0';
                                        }
                                        HopThoai(550, 265, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_RSHIFT || event.key.keysym.sym == SDLK_LSHIFT) {
                                        press1 = 1;
                                    }
                                    else if (press1 == 1 && event.key.keysym.sym == SDLK_2) {
                                        strncat(email, "@", 1);
                                        press1 = 0;
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(email, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(email, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(email, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(email);
                                            if (length > 0) {
                                                email[length - 1] = '\0';
                                            }
                                            HopThoai(550, 265, 400, 50, screen);
                                        }
                                    }
                                    if (press1 == 1 && event.key.keysym.sym != SDLK_2 && event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT) {
                                        press1 = 0;
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 270;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, email, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 320 && x < 950 && y < 370) {
                        strcpy(sdt, "");
                        HopThoai(550, 320, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(sdt);
                                        if (length > 0) {
                                            sdt[length - 1] = '\0';
                                        }
                                        HopThoai(550, 320, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(sdt, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(sdt, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(sdt);
                                            if (length > 0) {
                                                sdt[length - 1] = '\0';
                                            }
                                            HopThoai(550, 320, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 325;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, sdt, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 375 && x < 950 && y < 425) {
                        strcpy(GT, "");
                        HopThoai(550, 375, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(GT);
                                        if (length > 0) {
                                            GT[length - 1] = '\0';
                                        }
                                        HopThoai(550, 375, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym - 32;
                                        if ((keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(GT, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(GT, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(GT);
                                            if (length > 0) {
                                                GT[length - 1] = '\0';
                                            }
                                            HopThoai(550, 375, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 380;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, GT, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 430 && x < 950 && y < 480) {
                        strcpy(lopsh, "");
                        HopThoai(550, 430, 400, 50, screen);
                        SDL_Flip(screen);
                        int press1 = 0; // nhan shift
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(lopsh);
                                        if (length > 0) {
                                            lopsh[length - 1] = '\0';
                                        }
                                        HopThoai(550, 430, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_RSHIFT || event.key.keysym.sym == SDLK_LSHIFT) {
                                        press1 = 1;
                                    }
                                    else if (press1 == 1 && event.key.keysym.sym == SDLK_MINUS) {
                                        strncat(lopsh, "_", 1);
                                        press1 = 0;
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(lopsh, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9') ) {
                                            strncat(lopsh, &keyPressed, 1);
                                        }
                                        if ((keyPressed >= 'a' && keyPressed <= 'z')) {
                                            keyPressed = (char)event.key.keysym.sym  - 32;
                                            strncat(lopsh, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(lopsh);
                                            if (length > 0) {
                                                lopsh[length - 1] = '\0';
                                            }
                                            HopThoai(550, 430, 400, 50, screen);
                                        }
                                    }
                                    if (press1 == 1 && event.key.keysym.sym != SDLK_2 && event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT) {
                                        press1 = 0;
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 435;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, lopsh, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 485 && x < 950 && y < 535) {
                        strcpy(STM, "");
                        HopThoai(550, 485, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(STM);
                                        if (length > 0) {
                                            STM[length - 1] = '\0';
                                        }
                                        HopThoai(550, 485, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(STM, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(STM, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(STM);
                                            if (length > 0) {
                                                STM[length - 1] = '\0';
                                            }
                                            HopThoai(550, 485, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 490;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, STM, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 700 && x < 850 && y > 540 && y < 590) {
                        if (strcmp(GT, "NU") == 0) gioitinh = false;
                        else gioitinh = true;
                        if(strcmp(STM , "") != 0 )  sotcmax = (unsigned int)std::stoi(STM);
                        char n1[] = "Vui long nhap day du thong tin";
                        char n2[] = "";
                        if (strcmp(hoten, "") == 0 || strcmp(email, "") == 0 || strcmp(sdt, "") == 0 || strcmp(GT, "") == 0 || strcmp(STM, "") == 0 || strcmp(lopsh, "") == 0) Alert(n1, n2, "Vui long nhap day du thong tin");
                        else {
                            AD.nhapSinhVien("SinhVien.txt", "Users.txt", hoten, email, sdt, gioitinh, masv, lopsh , sotcmax);
                            Demo_SinhVien();
                        }
                    }
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 160 && x < 270 && y < 210) {
                        QuanliDkytc();
                    }
                    if (x > 0 && y > 210 && x < 270 && y < 260) {
                        strcpy_s(Seo_magv, "");
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 260 && x < 270 && y < 310) {
                        strcpy_s(Seo_masv, "");
                        Demo_SinhVien();
                    }
                    if (x > 0 && y > 310 && x < 270 && y < 360) {
                        strcpy_s(Seo_mahp, "");
                        Demo_HocPhan();
                    }
                    if (x > 0 && y > 360 && x < 270 && y < 410) {
                        Demo_LopHocPhan();
                    }
                    if (x > 0 && y > 410 && x < 270 && y < 460) {
                        Demo_Nhom();
                    }
                    if (x > 0 && y > 460 && x < 270 && y < 510) {
                        DoiMatKhau();
                    }
                    if (x > 0 && y > 510 && x < 270 && y < 560) {
                        Help();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void ThemHP() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    //
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    SELECT_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor_W);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    BG_HopThoai(280, 160, 970, 490, screen);
    HocPhan* dshp = getfromfileHocPhan("HocPhan.txt");
    // xác định mã giảng viên phù hợp
    int IDHP = 1;
    char mahp[100] = "";
    while (true) {
        string size_hp= "mahp" + to_string(IDHP);
        for (int i = 0; i < size_hp.length(); i++) {
            mahp[i] = char(size_hp[i]);
        }
        mahp[size_hp.length()] = '\0';
        int check = 1;
        for (int i = 1; i <= size_dshp; i++) {
            if (strcmp(mahp, dshp[i].getmahocphan()) == 0) {
                check = 0;
                break;
            }
        }
        if (check == 1) {
            break;
        }
        IDHP++;
    }
    char tenhocphan[] = "";
    double tinchi = 0.0;
    char TC[] = "";
    string title = "Thong tin Hoc Phan " + string(mahp) + " can them :";
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    Text(290, 170, title_ctr, screen, font_h1, textColor);
    HopThoai(550, 210, 400, 50, screen);
    HopThoai(550, 265, 400, 50, screen);
    HopThoai(700, 325, 150, 50, screen);
    Text(720, 330, "Xac nhan", screen, font_h1, textColor_RED);
    Text(290, 220, " - Ten Hoc Phan : ", screen, font_h1, textColor);
    Text(290, 275, " - So tin chi : ", screen, font_h1, textColor);
    // cập nhật nội dung cửa sổ
    SDL_Flip(screen);
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 550 && y > 210 && x < 950 && y < 260) {
                        strcpy(tenhocphan, "");
                        HopThoai(550, 210, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(tenhocphan);
                                        if (length > 0) {
                                            tenhocphan[length - 1] = '\0';
                                        }
                                        HopThoai(550, 210, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if (tenhocphan[strlen(tenhocphan) - 1] == ' ' || strlen(tenhocphan) == 0) {
                                            keyPressed -= 32;
                                        }
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(tenhocphan, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(tenhocphan, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(tenhocphan);
                                            if (length > 0) {
                                                tenhocphan[length - 1] = '\0';
                                            }
                                            HopThoai(550, 210, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 215;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, tenhocphan, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 265 && x < 950 && y < 315) {
                        strcpy(TC, "");
                        HopThoai(550, 265, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(TC);
                                        if (length > 0) {
                                            TC[length - 1] = '\0';
                                        }
                                        HopThoai(550, 265, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(TC, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if (keyPressed >= '0' && keyPressed <= '9') {
                                            strncat(TC, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(TC);
                                            if (length > 0) {
                                                TC[length - 1] = '\0';
                                            }
                                            HopThoai(550, 265, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 265;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, TC, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 700 && x < 850 && y > 325 && y < 375) {
                        if (strcmp(TC, "") != 0) tinchi = charArrayToDouble(TC);
                        char n1[] = "Vui long nhap day du thong tin";
                        char n2[] = "";
                        if (strcmp(tenhocphan, "") == 0 || strcmp(TC, "") == 0) Alert(n1, n2, "Vui long nhap day du thong tin");
                        else {
                            AD.nhapHocPhan("HocPhan.txt", mahp, tenhocphan, tinchi);
                            Demo_HocPhan();
                        }
                    }
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 160 && x < 270 && y < 210) {
                        QuanliDkytc();
                    }
                    if (x > 0 && y > 210 && x < 270 && y < 260) {
                        strcpy_s(Seo_magv, "");
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 260 && x < 270 && y < 310) {
                        strcpy_s(Seo_masv, "");
                        Demo_SinhVien();
                    }
                    if (x > 0 && y > 310 && x < 270 && y < 360) {
                        strcpy_s(Seo_mahp, "");
                        Demo_HocPhan();
                    }
                    if (x > 0 && y > 360 && x < 270 && y < 410) {
                        Demo_LopHocPhan();
                    }
                    if (x > 0 && y > 410 && x < 270 && y < 460) {
                        Demo_Nhom();
                    }
                    if (x > 0 && y > 460 && x < 270 && y < 510) {
                        DoiMatKhau();
                    }
                    if (x > 0 && y > 510 && x < 270 && y < 560) {
                        Help();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void ThongtinGV(GiangVien v ,SDL_Surface* screen , int index_y) {
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Color textColor = { 0,0,0 }; // đen
    BG_HopThoai(911, 210, 330, 400, screen);
    Uint32 Color = SDL_MapRGB(screen->format, 58, 189, 72);
    SDL_Rect textBox;
    textBox.x = 911;
    textBox.y = index_y;
    textBox.w = 330;
    textBox.h = 200;
    SDL_FillRect(screen, &textBox, Color);
    char* hoten = v.gethoten();
    char* email = v.getemail();
    char* magv = v.getmagiangvien();
    char* sdt = v.getsdt();
    bool gioitinh = v.getgioitinh();
    const char* GT_c = getGT(gioitinh);
    char GT[4] = "";
    for (int i = 0; i < strlen(GT_c); i++) {
        GT[i] = GT_c[i];
    }
    GT[strlen(GT_c)] = '\0';
    string title = "Thong tin giang vien " + string(v.getmagiangvien()) + " :";
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    Text(921, index_y + 10 , " - Ten Giang Vien : ", screen, font_h1, textColor);
    Text(921, index_y + 40, " - Ma Giang Vien : ", screen, font_h1, textColor);
    Text(921, index_y + 70, " - Email Giang Vien : ", screen, font_h1, textColor);
    Text(921, index_y + 130, " - SDT Giang Vien : ", screen, font_h1, textColor);
    Text(921, index_y + 160, " - Gioi tinh Giang Vien : ", screen, font_h1, textColor);
    Text(1060, index_y + 10, hoten, screen, font_h1, textColor);
    Text(1060, index_y + 40, magv, screen, font_h1, textColor);
    Text(933, index_y + 100, email, screen, font_h1, textColor);
    Text(1060, index_y + 130, sdt, screen, font_h1, textColor);
    Text(1100, index_y + 160, GT, screen, font_h1, textColor);
    SDL_Flip(screen);
}
void ThongtinUser(User u, SDL_Surface* screen, int index_y) {
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Color textColor = { 0,0,0 }; // đen
    BG_HopThoai(911, 210, 330, 420, screen);
    Uint32 Color = SDL_MapRGB(screen->format, 58, 189, 72);
    SDL_Rect textBox;
    textBox.x = 911;
    textBox.y = index_y;
    textBox.w = 330;
    textBox.h = 70;
    SDL_FillRect(screen, &textBox, Color);
    char* mssv = u.getMSSV();
    char* mk = u.getmk();
    Text(921, index_y + 10, " - Ma Sinh Vien : ", screen, font_h1, textColor);
    Text(921, index_y + 40, " - Mat Khau : ", screen, font_h1, textColor);
    Text(1060, index_y + 10, mssv, screen, font_h1, textColor);
    Text(1060, index_y + 40, mk, screen, font_h1, textColor);
    SDL_Flip(screen);
}
void ThongtinSV(SinhVien v, SDL_Surface* screen, int index_y) {
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Color textColor = { 0,0,0 }; // đen
    BG_HopThoai(911, 210, 330, 420, screen);
    Uint32 Color = SDL_MapRGB(screen->format, 58, 189, 72);
    SDL_Rect textBox;
    textBox.x = 911;
    textBox.y = index_y;
    textBox.w = 330;
    textBox.h = 260;
    SDL_FillRect(screen, &textBox, Color);
    char* hoten = v.gethoten();
    char* email = v.getemail();
    char* magv = v.getMSSV();
    char* sdt = v.getsdt();
    bool gioitinh = v.getgioitinh();
    char* lopsh = v.getlopsh();
    int sotcmax = v.getsotcmax();
    char* STM = intToCharArray(sotcmax);
    const char* GT_c = getGT(gioitinh);
    char GT[4] = "";
    for (int i = 0; i < strlen(GT_c); i++) {
        GT[i] = GT_c[i];
    }
    GT[strlen(GT_c)] = '\0';
    string title = "Thong tin Sinh vien " + string(v.getMSSV()) + " :";
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    Text(921, index_y + 10, " - Ten Sinh Vien : ", screen, font_h1, textColor);
    Text(921, index_y + 40, " - Ma Sinh Vien : ", screen, font_h1, textColor);
    Text(921, index_y + 70, " - Email Sinh Vien : ", screen, font_h1, textColor);
    Text(921, index_y + 130, " - SDT Sinh Vien : ", screen, font_h1, textColor);
    Text(921, index_y + 160, " - Gioi tinh Sinh Vien : ", screen, font_h1, textColor);
    Text(921, index_y + 190, " - Lop sinh hoat : ", screen, font_h1, textColor);
    Text(921, index_y + 220, " - So tinh chi toi da: ", screen, font_h1, textColor);
    Text(1060, index_y + 10, hoten, screen, font_h1, textColor);
    Text(1060, index_y + 40, magv, screen, font_h1, textColor);
    Text(933, index_y + 100, email, screen, font_h1, textColor);
    Text(1060, index_y + 130, sdt, screen, font_h1, textColor);
    Text(1090, index_y + 160, GT, screen, font_h1, textColor);
    Text(1060, index_y + 190, lopsh, screen, font_h1, textColor);
    Text(1080, index_y + 220, STM, screen, font_h1, textColor);
    SDL_Flip(screen);
}
void ThongtinHocPhan(HocPhan p, SDL_Surface* screen, int index_y) {
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Color textColor = { 0,0,0 }; // đen
    BG_HopThoai(911, 210, 330, 400, screen);
    Uint32 Color = SDL_MapRGB(screen->format, 58, 189, 72);
    SDL_Rect textBox;
    textBox.x = 911;
    textBox.y = index_y;
    textBox.w = 330;
    textBox.h = 120;
    SDL_FillRect(screen, &textBox, Color);
    char* mahocphan= p.getmahocphan();
    char* tenhocphan = p.gettenhocphan();
    char TC[5];
    doubleToCharArray(p.gettchi(), TC, sizeof(TC));
    string title = "Thong tin Hoc Phan " + string(p.getmahocphan()) + " :";
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    Text(921, index_y + 10, " - Ten Hoc Phan : ", screen, font_h1, textColor);
    Text(921, index_y + 40, " - Ma Hoc Phan : ", screen, font_h1, textColor);
    Text(921, index_y + 70, " - Tin chi : ", screen, font_h1, textColor);
    Text(1060, index_y + 10, tenhocphan, screen, font_h1, textColor);
    Text(1060, index_y + 40, mahocphan, screen, font_h1, textColor);
    Text(1000, index_y + 70, TC, screen, font_h1, textColor);
    SDL_Flip(screen);
}
void ChinhSuaGV(GiangVien& v) {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    //
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    SELECT_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor_W);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    BG_HopThoai(280, 160, 970, 490, screen);
    //
    char* hoten = v.gethoten();
    char* email = v.getemail();
    char* sdt = v.getsdt();
    bool gioitinh = v.getgioitinh();
    const char* GT_c = getGT(gioitinh);
    char GT[4] = "";
    for (int i = 0; i < strlen(GT_c); i++) {
        GT[i] = GT_c[i];
    }
    GT[strlen(GT_c)] = '\0';
    string title = "Thong tin giang vien " + string(v.getmagiangvien()) + " :";
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    Text(290, 170, title_ctr, screen, font_h1, textColor);
    HopThoai(550, 210, 400, 50, screen);
    HopThoai(550, 265, 400, 50, screen);
    HopThoai(550, 320, 400, 50, screen);
    HopThoai(550, 375, 400, 50, screen);
    HopThoai(700, 430, 150, 50, screen);
    Text(720, 435, "Xac nhan", screen, font_h1, textColor_RED);
    Text(560, 215, hoten, screen, font_h1, textColor);
    Text(560, 270, email, screen, font_h1, textColor);
    Text(560, 325, sdt, screen, font_h1, textColor);
    Text(560, 380, GT, screen, font_h1, textColor);
    Text(290, 220, " - Ten Giang Vien : ", screen, font_h1, textColor);
    Text(290, 275, " - Email Giang Vien : ", screen, font_h1, textColor);
    Text(290, 330, " - SDT Giang Vien : ", screen, font_h1, textColor);
    Text(290, 385, " - GT Giang Vien : ", screen, font_h1, textColor);
    // cập nhật nội dung cửa sổ
    SDL_Flip(screen);
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 550 && y > 210 && x < 950 && y < 260) {
                        strcpy(hoten, "");
                        HopThoai(550, 210, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(hoten);
                                        if (length > 0) {
                                            hoten[length - 1] = '\0';
                                        }
                                        HopThoai(550, 210, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if (hoten[strlen(hoten) - 1] == ' ' || strlen(hoten) == 0) {
                                            keyPressed -= 32;
                                        }
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(hoten, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(hoten, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(hoten);
                                            if (length > 0) {
                                                hoten[length - 1] = '\0';
                                            }
                                            HopThoai(550, 210, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 215;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, hoten, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 265 && x < 950 && y < 315) {
                        strcpy(email, "");
                        HopThoai(550, 265, 400, 50, screen);
                        SDL_Flip(screen);
                        int press2 = 0;
                        int press1 = 0; // nhan shift
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(email);
                                        if (length > 0) {
                                            email[length - 1] = '\0';
                                        }
                                        HopThoai(550, 265, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_RSHIFT || event.key.keysym.sym == SDLK_LSHIFT) {
                                        press1 = 1;
                                    }
                                    else if (press1 == 1 && event.key.keysym.sym == SDLK_2) {
                                        strncat(email, "@", 1);
                                        press1 = 0;
                                    }
                                    else if (press1 == 1 && event.key.keysym.sym != SDLK_2) {
                                        press1 = 0;
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(email, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(email, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(email, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(email);
                                            if (length > 0) {
                                                email[length - 1] = '\0';
                                            }
                                            HopThoai(550, 265, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 265;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, email, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 320 && x < 950 && y < 370) {
                        strcpy(sdt, "");
                        HopThoai(550, 320, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(sdt);
                                        if (length > 0) {
                                            sdt[length - 1] = '\0';
                                        }
                                        HopThoai(550, 320, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(sdt, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(sdt, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(hoten);
                                            if (length > 0) {
                                                sdt[length - 1] = '\0';
                                            }
                                            HopThoai(550, 320, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 325;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, sdt, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 375 && x < 950 && y < 435) {
                        strcpy(GT, "");
                        HopThoai(550, 375, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(GT);
                                        if (length > 0) {
                                            GT[length - 1] = '\0';
                                        }
                                        HopThoai(550, 375, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym - 32;
                                        if ((keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(GT, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(GT, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(hoten);
                                            if (length > 0) {
                                                GT[length - 1] = '\0';
                                            }
                                            HopThoai(550, 375, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 380;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, GT, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 700 && x < 850 && y > 430 && y < 480) {
                        if (strcmp(GT, "NU") == 0) gioitinh = false;
                        else gioitinh = true;
                        char n1[] = "Vui long nhap day du thong tin";
                        char n2[] = "";
                        if (strcmp(hoten , "") == 0 || strcmp(email, "") == 0 || strcmp(sdt, "") == 0 || strcmp(GT, "") == 0) Alert(n1, n2, "Vui long nhap day du thong tin");
                        else {
                            AD.updategiangvien("GiangVien.txt", v.getmagiangvien(), hoten, email, sdt, gioitinh);
                            Demo_GiangVien();
                        }
                    }
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 160 && x < 270 && y < 210) {
                        QuanliDkytc();
                    }
                    if (x > 0 && y > 210 && x < 270 && y < 260) {
                        strcpy_s(Seo_magv, "");
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 260 && x < 270 && y < 310) {
                        strcpy_s(Seo_masv, "");
                        Demo_SinhVien();
                    }
                    if (x > 0 && y > 310 && x < 270 && y < 360) {
                        strcpy_s(Seo_mahp, "");
                        Demo_HocPhan();
                    }
                    if (x > 0 && y > 360 && x < 270 && y < 410) {
                        Demo_LopHocPhan();
                    }
                    if (x > 0 && y > 410 && x < 270 && y < 460) {
                        Demo_Nhom();
                    }
                    if (x > 0 && y > 460 && x < 270 && y < 510) {
                        DoiMatKhau();
                    }
                    if (x > 0 && y > 510 && x < 270 && y < 560) {
                        Help();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void ChinhSuaSV(SinhVien& v) {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    //
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    SELECT_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor_W);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    BG_HopThoai(280, 160, 970, 490, screen);
    //
    char* hoten = v.gethoten();
    char* email = v.getemail();
    char* sdt = v.getsdt();
    bool gioitinh = v.getgioitinh();
    const char* GT_c = getGT(gioitinh);
    char* lopsh = v.getlopsh();
    int sotcmax = v.getsotcmax();
    char* STM = intToCharArray(sotcmax);
    char GT[4] = "";
    for (int i = 0; i < strlen(GT_c); i++) {
        GT[i] = GT_c[i];
    }
    GT[strlen(GT_c)] = '\0';
    string title = "Thong tin Sinh vien " + string(v.getMSSV()) + " :";
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    Text(290, 170, title_ctr, screen, font_h1, textColor);
    HopThoai(550, 210, 400, 50, screen);
    HopThoai(550, 265, 400, 50, screen);
    HopThoai(550, 320, 400, 50, screen);
    HopThoai(550, 375, 400, 50, screen);
    HopThoai(550, 430, 400, 50, screen);
    HopThoai(550, 485, 400, 50, screen);
    HopThoai(700, 540, 150, 50, screen);
    Text(720, 550, "Xac nhan", screen, font_h1, textColor_RED);
    Text(560, 215, hoten, screen, font_h1, textColor);
    Text(560, 270, email, screen, font_h1, textColor);
    Text(560, 325, sdt, screen, font_h1, textColor);
    Text(560, 380, GT, screen, font_h1, textColor);
    Text(560, 435, lopsh, screen, font_h1, textColor);
    Text(560, 490, STM, screen, font_h1, textColor);
    Text(290, 220, " - Ten Sinh Vien : ", screen, font_h1, textColor);
    Text(290, 275, " - Email Sinh Vien : ", screen, font_h1, textColor);
    Text(290, 330, " - SDT Sinh Vien : ", screen, font_h1, textColor);
    Text(290, 385, " - GT Sinh Vien : ", screen, font_h1, textColor);
    Text(290, 440, " - Lop sinh hoat : ", screen, font_h1, textColor);
    Text(290, 495, " - So tin chi toi da : ", screen, font_h1, textColor);
    // cập nhật nội dung cửa sổ
    SDL_Flip(screen);
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 550 && y > 210 && x < 950 && y < 260) {
                        strcpy(hoten, "");
                        HopThoai(550, 210, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(hoten);
                                        if (length > 0) {
                                            hoten[length - 1] = '\0';
                                        }
                                        HopThoai(550, 210, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if (hoten[strlen(hoten) - 1] == ' ' || strlen(hoten) == 0) {
                                            keyPressed -= 32;
                                        }
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(hoten, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(hoten, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(hoten);
                                            if (length > 0) {
                                                hoten[length - 1] = '\0';
                                            }
                                            HopThoai(550, 210, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 215;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, hoten, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 265 && x < 950 && y < 315) {
                        strcpy(email, "");
                        HopThoai(550, 265, 400, 50, screen);
                        SDL_Flip(screen);
                        int press2 = 0;
                        int press1 = 0; // nhan shift
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(email);
                                        if (length > 0) {
                                            email[length - 1] = '\0';
                                        }
                                        HopThoai(550, 265, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_RSHIFT || event.key.keysym.sym == SDLK_LSHIFT) {
                                        press1 = 1;
                                    }
                                    else if (press1 == 1 && event.key.keysym.sym == SDLK_2) {
                                        strncat(email, "@", 1);
                                        press1 = 0;
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(email, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(email, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(email, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(email);
                                            if (length > 0) {
                                                email[length - 1] = '\0';
                                            }
                                            HopThoai(550, 265, 400, 50, screen);
                                        }
                                    }
                                    if (press1 == 1 && event.key.keysym.sym != SDLK_2 && event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT) {
                                        press1 = 0;
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 270;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, email, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 320 && x < 950 && y < 370) {
                        strcpy(sdt, "");
                        HopThoai(550, 320, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(sdt);
                                        if (length > 0) {
                                            sdt[length - 1] = '\0';
                                        }
                                        HopThoai(550, 320, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(sdt, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(sdt, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(sdt);
                                            if (length > 0) {
                                                sdt[length - 1] = '\0';
                                            }
                                            HopThoai(550, 320, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 325;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, sdt, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 375 && x < 950 && y < 425) {
                        strcpy(GT, "");
                        HopThoai(550, 375, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(GT);
                                        if (length > 0) {
                                            GT[length - 1] = '\0';
                                        }
                                        HopThoai(550, 375, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym - 32;
                                        if ((keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(GT, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(GT, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(GT);
                                            if (length > 0) {
                                                GT[length - 1] = '\0';
                                            }
                                            HopThoai(550, 375, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 380;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, GT, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 430 && x < 950 && y < 480) {
                        strcpy(lopsh, "");
                        HopThoai(550, 430, 400, 50, screen);
                        SDL_Flip(screen);
                        int press1 = 0; // nhan shift
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(lopsh);
                                        if (length > 0) {
                                            lopsh[length - 1] = '\0';
                                        }
                                        HopThoai(550, 430, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_RSHIFT || event.key.keysym.sym == SDLK_LSHIFT) {
                                        press1 = 1;
                                    }
                                    else if (press1 == 1 && event.key.keysym.sym == SDLK_MINUS) {
                                        strncat(lopsh, "_", 1);
                                        press1 = 0;
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(lopsh, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(lopsh, &keyPressed, 1);
                                        }
                                        if ((keyPressed >= 'a' && keyPressed <= 'z')) {
                                            keyPressed = (char)event.key.keysym.sym - 32;
                                            strncat(lopsh, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(lopsh);
                                            if (length > 0) {
                                                lopsh[length - 1] = '\0';
                                            }
                                            HopThoai(550, 430, 400, 50, screen);
                                        }
                                    }
                                    if (press1 == 1 && event.key.keysym.sym != SDLK_2 && event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT) {
                                        press1 = 0;
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 435;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, lopsh, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 485 && x < 950 && y < 535) {
                        strcpy(STM, "");
                        HopThoai(550, 485, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(STM);
                                        if (length > 0) {
                                            STM[length - 1] = '\0';
                                        }
                                        HopThoai(550, 485, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if ((keyPressed >= '0' && keyPressed <= '9')) {
                                            strncat(STM, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(STM, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(STM);
                                            if (length > 0) {
                                                STM[length - 1] = '\0';
                                            }
                                            HopThoai(550, 485, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 490;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, STM, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 700 && x < 850 && y > 540 && y < 590) {
                        if (strcmp(GT, "NU") == 0) gioitinh = false;
                        else gioitinh = true;
                        if (strcmp(STM, "") != 0)  sotcmax = (unsigned int)std::stoi(STM);
                        char n1[] = "Vui long nhap day du thong tin";
                        char n2[] = "";
                        if (strcmp(hoten, "") == 0 || strcmp(email, "") == 0 || strcmp(sdt, "") == 0 || strcmp(GT, "") == 0 || strcmp(STM, "") == 0 || strcmp(lopsh, "") == 0) Alert(n1, n2, "Vui long nhap day du thong tin");
                        else {
                            AD.updateSinhVien("SinhVien.txt", v.getMSSV(), hoten, email, sdt, gioitinh, lopsh, sotcmax);
                            Demo_SinhVien();
                        }
                    }
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 160 && x < 270 && y < 210) {
                        QuanliDkytc();
                    }
                    if(x > 0 && y > 210 && x < 270 && y < 260) {
                        strcpy_s(Seo_magv, "");
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 260 && x < 270 && y < 310) {
                        strcpy_s(Seo_masv, "");
                        Demo_SinhVien();
                    }
                    if (x > 0 && y > 310 && x < 270 && y < 360) {
                        strcpy_s(Seo_mahp, "");
                        Demo_HocPhan();
                    }
                    if (x > 0 && y > 360 && x < 270 && y < 410) {
                        Demo_LopHocPhan();
                    }
                    if (x > 0 && y > 410 && x < 270 && y < 460) {
                        Demo_Nhom();
                    }
                    if (x > 0 && y > 460 && x < 270 && y < 510) {
                        DoiMatKhau();
                    }
                    if (x > 0 && y > 510 && x < 270 && y < 560) {
                        Help();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void ChinhSuaHP(HocPhan& p) {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    //
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    SELECT_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor_W);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    BG_HopThoai(280, 160, 970, 490, screen);
    //
    char* tenhocphan = p.gettenhocphan();
    double tinchi = p.gettchi();
    char TC[5];
    doubleToCharArray(p.gettchi(), TC, sizeof(TC));
    string title = "Thong tin Hoc Phan " + string(p.getmahocphan()) + " :";
    char title_ctr[100] = "";
    for (int i = 0; i < title.length(); i++) {
        title_ctr[i] = char(title[i]);
    }
    title_ctr[title.length()] = '\0';
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    Text(290, 170, title_ctr, screen, font_h1, textColor);
    HopThoai(550, 210, 400, 50, screen);
    HopThoai(550, 265, 400, 50, screen);
    HopThoai(700, 325, 150, 50, screen);
    Text(560, 215, tenhocphan, screen, font_h1, textColor);
    Text(560, 270, TC, screen, font_h1, textColor);
    Text(720, 330, "Xac nhan", screen, font_h1, textColor_RED);
    Text(290, 220, " - Ten Hoc Phan : ", screen, font_h1, textColor);
    Text(290, 275, " - So tin chi : ", screen, font_h1, textColor);
    // cập nhật nội dung cửa sổ
    SDL_Flip(screen);
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 550 && y > 210 && x < 950 && y < 260) {
                        strcpy(tenhocphan, "");
                        HopThoai(550, 210, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(tenhocphan);
                                        if (length > 0) {
                                            tenhocphan[length - 1] = '\0';
                                        }
                                        HopThoai(550, 210, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if (tenhocphan[strlen(tenhocphan) - 1] == ' ' || strlen(tenhocphan) == 0) {
                                            keyPressed -= 32;
                                        }
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) {
                                            strncat(tenhocphan, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_SPACE) {
                                            strncat(tenhocphan, " ", 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(tenhocphan);
                                            if (length > 0) {
                                                tenhocphan[length - 1] = '\0';
                                            }
                                            HopThoai(550, 210, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 215;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, tenhocphan, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 550 && y > 265 && x < 950 && y < 315) {
                        strcpy(TC, "");
                        HopThoai(550, 265, 400, 50, screen);
                        SDL_Flip(screen);
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(TC);
                                        if (length > 0) {
                                            TC[length - 1] = '\0';
                                        }
                                        HopThoai(550, 265, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym == SDLK_PERIOD) {
                                        strncat(TC, ".", 1);
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;

                                        if (keyPressed >= '0' && keyPressed <= '9') {
                                            strncat(TC, &keyPressed, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(TC);
                                            if (length > 0) {
                                                TC[length - 1] = '\0';
                                            }
                                            HopThoai(550, 265, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 560;
                                textRect.y = 265;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font_h1, TC, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 700 && x < 850 && y > 325 && y < 375) {
                        if (strcmp(TC, "") != 0) tinchi = charArrayToDouble(TC);
                        char n1[] = "Vui long nhap day du thong tin";
                        char n2[] = "";
                        if (strcmp(tenhocphan, "") == 0 || strcmp(TC, "") == 0) Alert(n1, n2, "Vui long nhap day du thong tin");
                        else {
                            AD.updatehocphan("HocPhan.txt", p.getmahocphan(), tenhocphan, tinchi);
                            Demo_HocPhan();
                        }
                    }
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 160 && x < 270 && y < 210) {
                        QuanliDkytc();
                    }
                    if (x > 0 && y > 210 && x < 270 && y < 260) {
                        strcpy_s(Seo_magv, "");
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 260 && x < 270 && y < 310) {
                        strcpy_s(Seo_masv, "");
                        Demo_SinhVien();
                    }
                    if (x > 0 && y > 310 && x < 270 && y < 360) {
                        strcpy_s(Seo_mahp, "");
                        Demo_HocPhan();
                    }
                    if (x > 0 && y > 360 && x < 270 && y < 410) {
                        Demo_LopHocPhan();
                    }
                    if (x > 0 && y > 410 && x < 270 && y < 460) {
                        Demo_Nhom();
                    }
                    if (x > 0 && y > 460 && x < 270 && y < 510) {
                        DoiMatKhau();
                    }
                    if (x > 0 && y > 510 && x < 270 && y < 560) {
                        Help();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void Demo_GiangVien() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    SELECT_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor_W);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    //
cancel_seo:
    SDL_Surface* seo = IMG_Load("seo.png");
    BG_HopThoai(280, 160, 970, 490, screen);
    GiangVien* dsgv = getfromfileGiangVien("GiangVien.txt");
    Text(290, 190, "Danh sach Giang vien :", screen, font_h3, textColor);
    HopThoai(780, 190, 130, 25, screen);
    Text(785, 190, "Them giang vien", screen, font_h3, textColor);
    HopThoai(600, 190, 130, 25, screen);
    Image(605, 195, seo, screen);
    if (strcmp(Seo_magv, "") == 0) Text(630, 192, "Tim kiem", screen, font_h3, textColor);
    else Text(630, 192, Seo_magv, screen, font_h3, textColor);
    int index_seo = 0;
    int array[1000];
    // tìm index thõa mãn điều kiện tìm kiếm
    for (int i = 1; i <= size_dsgv; i++) {
        bool seo = true;
        for (int j = 0; j < strlen(Seo_magv); j++) {
            if (Seo_magv[j] != dsgv[i].getmagiangvien()[j]) {
                seo = false;
                break;
            }
        }
        if (seo) {
            index_seo++;
            array[index_seo] = i;
        }
    }
    if (index_seo == 0) {
        Text(600, 300, "Danh sach trong", screen, font_h1, textColor);
        SDL_Flip(screen);
        SDL_Event event;
        SDL_Flip(screen);
        bool quit = false;
        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
                else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                    int x = event.button.x;
                    int y = event.button.y;
                    int index_y;
                    int position_y = (y - 260) / 30 + 1;
                    if (position_y > 6) {
                        index_y = ((y - 260) / 30) * 30 + 260 - 170;
                    }
                    else index_y = ((y - 260) / 30) * 30 + 260;
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (x > 600 && y > 190 && x < 730 && y < 215) {
                            SDL_Surface* seo = IMG_Load("seo.png");
                            HopThoai(600, 190, 130, 25, screen);
                            Image(605, 195, seo, screen);
                            SDL_Flip(screen);
                            while (!quit) {
                                while (SDL_PollEvent(&event)) {
                                    if (event.type == SDL_KEYDOWN) {
                                        if (event.key.keysym.sym == SDLK_ESCAPE) {
                                            quit = true;
                                        }
                                        else if (event.key.keysym.sym == SDLK_RETURN) {
                                            goto cancel_seo;
                                        }
                                        else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(Seo_magv);
                                            if (length > 0) {
                                                Seo_magv[length - 1] = '\0';
                                            }
                                            SDL_Surface* seo = IMG_Load("seo.png");
                                            HopThoai(600, 190, 130, 25, screen);
                                            Image(605, 195, seo, screen); // set lại hộp thoại
                                        }
                                        else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                            char keyPressed = (char)event.key.keysym.sym;
                                            if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                strncat(Seo_magv, &keyPressed, 1);
                                            }
                                            if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_magv);
                                                if (length > 0) {
                                                    Seo_magv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen);
                                            }
                                        }
                                    }
                                }
                                if (font != NULL) {
                                    SDL_Rect textRect;
                                    textRect.x = 630;
                                    textRect.y = 192;
                                    SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_magv, textColor);
                                    SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                }
                                SDL_Flip(screen); // Cập nhật cửa sổ
                            }
                        }
                        if (x > 20 && x < 100 && y > 55 && y < 95) {
                            DangNhapAdmin();
                        }
                        if (x > 0 && y > 160 && x < 270 && y < 210) {
                            QuanliDkytc();
                        }
                        if (x > 0 && y > 210 && x < 270 && y < 260) {
                            strcpy_s(Seo_magv, "");
                            Demo_GiangVien();
                        }
                        if (x > 0 && y > 260 && x < 270 && y < 310) {
                            strcpy_s(Seo_masv, "");
                            Demo_SinhVien();
                        }
                        if (x > 0 && y > 310 && x < 270 && y < 360) {
                            strcpy_s(Seo_mahp, "");
                            Demo_HocPhan();
                        }
                        if (x > 0 && y > 360 && x < 270 && y < 410) {
                            Demo_LopHocPhan();
                        }
                        if (x > 0 && y > 410 && x < 270 && y < 460) {
                            Demo_Nhom();
                        }
                        if (x > 0 && y > 460 && x < 270 && y < 510) {
                            DoiMatKhau();
                        }
                        if (x > 0 && y > 510 && x < 270 && y < 560) {
                            Help();
                        }
                        if (x > 780 && x < 910 && y > 190 && y < 215) {
                            ThemGV();
                        }
                    }
                }
            }
        }
    }
    else {
        HopThoai(290, 230, 620, 30, screen);
        Text(295, 235, "TT", screen, font_h3, textColor_RED);
        DrawLine(screen, 340, 230, 340, 260, redColor);
        Text(345, 235, "Ten Giang Vien", screen, font_h3, textColor_RED);
        DrawLine(screen, 550, 230, 550, 260, redColor);
        Text(555, 235, "Ma Giang Vien", screen, font_h3, textColor_RED);
        DrawLine(screen, 670, 230, 670, 260, redColor);
        Text(675, 235, "Gioi tinh", screen, font_h3, textColor_RED);
        DrawLine(screen, 750, 230, 750, 260, redColor);
        DrawLine(screen, 830, 230, 830, 260, redColor);
        DrawLine(screen, 880, 230, 880, 260, redColor);
        int size = 0;
        int size_gv = index_seo;
        int time = 0;
    cancel_gv:
        int y_o = 260;
        int index = 10 * time + 1;
        if (size_gv > 10)  size = time * 10 + 10;
        else  size = time * 10 + size_gv;
        while (index <= size && index <= index_seo) {
            SDL_Surface* detail = IMG_Load("file.png");
            DrawLine(screen, 290, y_o, 290, y_o + 30, redColor);
            Text(295, y_o + 3, to_string(array[index]).c_str(), screen, font_h3, textColor);
            DrawLine(screen, 340, y_o, 340, y_o + 30, redColor);
            Text(345, y_o + 3, dsgv[array[index]].gethoten(), screen, font_h3, textColor);
            DrawLine(screen, 550, y_o, 550, y_o + 30, redColor);
            Text(555, y_o + 3, dsgv[array[index]].getmagiangvien(), screen, font_h3, textColor);
            DrawLine(screen, 670, y_o, 670, y_o + 30, redColor);
            Text(695, y_o + 3, (dsgv[array[index]].getgioitinh() ? "X" : ""), screen, font_h3, textColor);
            DrawLine(screen, 750, y_o, 750, y_o + 30, redColor);
            Text(755, y_o + 3, "Chinh sua", screen, font_h3, textColor_RED);
            DrawLine(screen, 830, y_o, 830, y_o + 30, redColor);
            Text(835, y_o + 3, "Xoa", screen, font_h3, textColor_RED);
            DrawLine(screen, 880, y_o, 880, y_o + 30, redColor);
            Image(885, y_o + 5, detail, screen);
            DrawLine(screen, 910, y_o, 910, y_o + 30, redColor);
            index++;
            y_o += 30;
            DrawLine(screen, 290, y_o, 910, y_o, redColor);
            SDL_Flip(screen);
        }
        if (size_gv > 10 && time > 0) {
            Text(830, y_o + 10, "Xem them", screen, font_h3, textColor_RED);
            Text(290, y_o + 10, "Trang truoc", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 6) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinGV(dsgv[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_magv);
                                                if (length > 0) {
                                                    Seo_magv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_magv, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_magv);
                                                    if (length > 0) {
                                                        Seo_magv[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_magv, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 290 && x < 400 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time--;
                                size_gv += 10;
                                goto cancel_gv;
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaGV(dsgv[array[position]]);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanXoaGV(dsgv[array[position]]);
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinGV(dsgv[array[position]], screen, index_y);
                            }
                            if (x > 830 && x < 910 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time++;
                                size_gv -= 10;
                                goto cancel_gv;
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemGV();
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                        }
                    }
                }
            }
        }
        if (size_gv > 10 && time == 0) {
            Text(830, y_o + 10, "Xem them", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 6) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinGV(dsgv[array[position]], screen, index_y);
                        }
                        else {
                            SDL_Surface* seo = IMG_Load("seo.png");
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_magv);
                                                if (length > 0) {
                                                    Seo_magv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_magv, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_magv);
                                                    if (length > 0) {
                                                        Seo_magv[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_magv, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 830 && x < 910 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time++;
                                size_gv -= 10;
                                goto cancel_gv;
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaGV(dsgv[array[position]]);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                std::cout << position << endl;
                                XacNhanXoaGV(dsgv[array[position]]);
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinGV(dsgv[array[position]], screen, index_y);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if(x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemGV();
                            }
                        }
                    }
                }
            }
        }
        if (size_gv <= 10 && time == 0) {
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 6) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_magv);
                                                if (length > 0) {
                                                    Seo_magv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_magv, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_magv);
                                                    if (length > 0) {
                                                        Seo_magv[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_magv, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaGV(dsgv[array[position]]);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanXoaGV(dsgv[array[position]]);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinGV(dsgv[array[position]], screen, index_y);
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if(x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemGV();
                            }
                        }
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinGV(dsgv[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                    }
                }
            }
        }
        if (size_gv <= 10 && time > 0) {
            Text(290, y_o + 10, "Trang truoc", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 6) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_magv);
                                                if (length > 0) {
                                                    Seo_magv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_magv, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_magv);
                                                    if (length > 0) {
                                                        Seo_magv[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_magv, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 290 && x < 400 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time--;
                                size_gv += 10;
                                goto cancel_gv;
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaGV(dsgv[array[position]]);
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinGV(dsgv[array[position]], screen, index_y);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                std::cout << position << endl;
                                XacNhanXoaGV(dsgv[array[position]]);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemGV();
                            }
                        }
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinGV(dsgv[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                    }
                }
            }
        }
    }
    SDL_Flip(screen);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void Demo_SinhVien() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    SELECT_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor_W);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    //
cancel_seo:
    SDL_Surface* seo = IMG_Load("seo.png");
    BG_HopThoai(280, 160, 970, 490, screen);
    SinhVien* dssv = getfromfileSinhVien("SinhVien.txt");
    Text(290, 190, "Danh sach Sinh vien :", screen, font_h3, textColor);
    HopThoai(780, 190, 130, 25, screen);
    Text(785, 190, "Them Sinh vien", screen, font_h3, textColor);
    HopThoai(600, 190, 130, 25, screen);
    Image(605, 195, seo, screen);
    if (strcmp(Seo_masv, "") == 0) Text(630, 192, "Tim kiem", screen, font_h3, textColor);
    else Text(630, 192, Seo_masv, screen, font_h3, textColor);
    int index_seo = 0;
    int array[1000];
    // tìm index thõa mãn điều kiện tìm kiếm
    for (int i = 1; i <= size_dssv; i++) {
        bool seo = true;
        for (int j = 0; j < strlen(Seo_masv); j++) {
            if (Seo_masv[j] != dssv[i].getMSSV()[j]) {
                seo = false;
                break;
            }
        }
        if (seo) {
            index_seo++;
            array[index_seo] = i;
        }
    }
    if (index_seo == 0) {
        Text(600, 300, "Danh sach trong", screen, font_h1, textColor);
        SDL_Flip(screen);
        SDL_Event event;
        SDL_Flip(screen);
        bool quit = false;
        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
                else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                    int x = event.button.x;
                    int y = event.button.y;
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (x > 600 && y > 190 && x < 730 && y < 215) {
                            SDL_Surface* seo = IMG_Load("seo.png");
                            HopThoai(600, 190, 130, 25, screen);
                            Image(605, 195, seo, screen);
                            SDL_Flip(screen);
                            while (!quit) {
                                while (SDL_PollEvent(&event)) {
                                    if (event.type == SDL_KEYDOWN) {
                                        if (event.key.keysym.sym == SDLK_ESCAPE) {
                                            quit = true;
                                        }
                                        else if (event.key.keysym.sym == SDLK_RETURN) {
                                            goto cancel_seo;
                                        }
                                        else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(Seo_masv);
                                            if (length > 0) {
                                                Seo_masv[length - 1] = '\0';
                                            }
                                            SDL_Surface* seo = IMG_Load("seo.png");
                                            HopThoai(600, 190, 130, 25, screen);
                                            Image(605, 195, seo, screen); // set lại hộp thoại
                                        }
                                        else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                            char keyPressed = (char)event.key.keysym.sym;
                                            if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                strncat(Seo_masv, &keyPressed, 1);
                                            }
                                            if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_masv);
                                                if (length > 0) {
                                                    Seo_masv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen);
                                            }
                                        }
                                    }
                                }
                                if (font != NULL) {
                                    SDL_Rect textRect;
                                    textRect.x = 630;
                                    textRect.y = 192;
                                    SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_masv, textColor);
                                    SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                }
                                SDL_Flip(screen); // Cập nhật cửa sổ
                            }
                        }
                        if (x > 20 && x < 100 && y > 55 && y < 95) {
                            DangNhapAdmin();
                        }
                        if (x > 0 && y > 160 && x < 270 && y < 210) {
                            QuanliDkytc();
                        }
                        if (x > 0 && y > 210 && x < 270 && y < 260) {
                            strcpy_s(Seo_magv, "");
                            Demo_GiangVien();
                        }
                        if (x > 0 && y > 260 && x < 270 && y < 310) {
                            strcpy_s(Seo_masv, "");
                            Demo_SinhVien();
                        }
                        if (x > 0 && y > 310 && x < 270 && y < 360) {
                            strcpy_s(Seo_mahp, "");
                            Demo_HocPhan();
                        }
                        if (x > 0 && y > 360 && x < 270 && y < 410) {
                            Demo_LopHocPhan();
                        }
                        if (x > 0 && y > 410 && x < 270 && y < 460) {
                            Demo_Nhom();
                        }
                        if (x > 0 && y > 460 && x < 270 && y < 510) {
                            DoiMatKhau();
                        }
                        if (x > 0 && y > 510 && x < 270 && y < 560) {
                            Help();
                        }
                        if (x > 780 && x < 910 && y > 190 && y < 215) {
                            ThemSV();
                        }
                    }
                }
            }
        }
    }
    else {
        HopThoai(290, 230, 620, 30, screen);
        Text(295, 235, "TT", screen, font_h3, textColor_RED);
        DrawLine(screen, 340, 230, 340, 260, redColor);
        Text(345, 235, "Ten Sinh Vien", screen, font_h3, textColor_RED);
        DrawLine(screen, 550, 230, 550, 260, redColor);
        Text(555, 235, "MS Sinh Vien", screen, font_h3, textColor_RED);
        DrawLine(screen, 670, 230, 670, 260, redColor);
        Text(675, 235, "Gioi tinh", screen, font_h3, textColor_RED);
        DrawLine(screen, 750, 230, 750, 260, redColor);
        DrawLine(screen, 830, 230, 830, 260, redColor);
        DrawLine(screen, 880, 230, 880, 260, redColor);
        int size = 0;
        int size_sv = index_seo;
        int time = 0;
    cancel_sv:
        int y_o = 260;
        int index = 10 * time + 1;
        if (size_sv > 10)  size = time * 10 + 10;
        else  size = time * 10 + size_sv;
        while (index <= size && index <= index_seo) {
            SDL_Surface* detail = IMG_Load("file.png");
            DrawLine(screen, 290, y_o, 290, y_o + 30, redColor);
            Text(295, y_o + 3, to_string(array[index]).c_str(), screen, font_h3, textColor);
            DrawLine(screen, 340, y_o, 340, y_o + 30, redColor);
            Text(345, y_o + 3, dssv[array[index]].gethoten(), screen, font_h3, textColor);
            DrawLine(screen, 550, y_o, 550, y_o + 30, redColor);
            Text(555, y_o + 3, dssv[array[index]].getMSSV(), screen, font_h3, textColor);
            DrawLine(screen, 670, y_o, 670, y_o + 30, redColor);
            Text(695, y_o + 3, (dssv[array[index]].getgioitinh() ? "X" : ""), screen, font_h3, textColor);
            DrawLine(screen, 750, y_o, 750, y_o + 30, redColor);
            Text(755, y_o + 3, "Chinh sua", screen, font_h3, textColor_RED);
            DrawLine(screen, 830, y_o, 830, y_o + 30, redColor);
            Text(835, y_o + 3, "Xoa", screen, font_h3, textColor_RED);
            DrawLine(screen, 880, y_o, 880, y_o + 30, redColor);
            Image(885, y_o + 5, detail, screen);
            DrawLine(screen, 910, y_o, 910, y_o + 30, redColor);
            index++;
            y_o += 30;
            DrawLine(screen, 290, y_o, 910, y_o, redColor);
            SDL_Flip(screen);
        }
        if (size_sv > 10 && time > 0) {
            Text(830, y_o + 10, "Xem them", screen, font_h3, textColor_RED);
            Text(290, y_o + 10, "Trang truoc", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 4) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinSV(dssv[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_masv);
                                                if (length > 0) {
                                                    Seo_masv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_masv, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_masv);
                                                    if (length > 0) {
                                                        Seo_masv[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_masv, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 290 && x < 400 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time--;
                                size_sv += 10;
                                goto cancel_sv;
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaSV(dssv[array[position]]);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanXoaSV(dssv[array[position]]);
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinSV(dssv[array[position]], screen, index_y);
                            }
                            if (x > 830 && x < 910 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time++;
                                size_sv -= 10;
                                goto cancel_sv;
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemSV();
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                        }
                    }
                }
            }
        }
        if (size_sv > 10 && time == 0) {
            Text(830, y_o + 10, "Xem them", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 4) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinSV(dssv[array[position]], screen, index_y);
                        }
                        else {
                            SDL_Surface* seo = IMG_Load("seo.png");
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_masv);
                                                if (length > 0) {
                                                    Seo_masv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_masv, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_masv);
                                                    if (length > 0) {
                                                        Seo_masv[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_masv, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 830 && x < 910 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time++;
                                size_sv -= 10;
                                goto cancel_sv;
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaSV(dssv[array[position]]);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                std::cout << position << endl;
                                XacNhanXoaSV(dssv[array[position]]);
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinSV(dssv[array[position]], screen, index_y);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemSV();
                            }
                        }
                    }
                }
            }
        }
        if (size_sv <= 10 && time == 0) {
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 4) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_masv);
                                                if (length > 0) {
                                                    Seo_masv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_masv, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_masv);
                                                    if (length > 0) {
                                                        Seo_masv[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_masv, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaSV(dssv[array[position]]);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanXoaSV(dssv[array[position]]);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinSV(dssv[array[position]], screen, index_y);
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemSV();
                            }
                        }
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinSV(dssv[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                    }
                }
            }
        }
        if (size_sv <= 10 && time > 0) {
            Text(290, y_o + 10, "Trang truoc", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 4) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_masv);
                                                if (length > 0) {
                                                    Seo_masv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_masv, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_masv);
                                                    if (length > 0) {
                                                        Seo_masv[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_masv, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 290 && x < 400 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time--;
                                size_sv += 10;
                                goto cancel_sv;
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaSV(dssv[array[position]]);
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinSV(dssv[array[position]], screen, index_y);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                std::cout << position << endl;
                                XacNhanXoaSV(dssv[array[position]]);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemSV();
                            }
                        }
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinSV(dssv[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                    }
                }
            }
        }
    }
    SDL_Flip(screen);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void Demo_HocPhan() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    SELECT_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor_W);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    //
cancel_seo:
    SDL_Surface* seo = IMG_Load("seo.png");
    BG_HopThoai(280, 160, 970, 490, screen);
    HocPhan* dshp = getfromfileHocPhan("HocPhan.txt");
    Text(290, 190, "Danh sach Hoc Phan :", screen, font_h3, textColor);
    HopThoai(780, 190, 130, 25, screen);
    Text(785, 190, "Them Hoc Phan", screen, font_h3, textColor);
    HopThoai(600, 190, 130, 25, screen);
    Image(605, 195, seo, screen);
    if (strcmp(Seo_mahp, "") == 0) Text(630, 192, "Tim kiem", screen, font_h3, textColor);
    else Text(630, 192, Seo_mahp, screen, font_h3, textColor);
    int index_seo = 0;
    int array[1000];
    // tìm index thõa mãn điều kiện tìm kiếm
    for (int i = 1; i <= size_dshp; i++) {
        bool seo = true;
        for (int j = 0; j < strlen(Seo_mahp); j++) {
            if (Seo_mahp[j] != dshp[i].getmahocphan()[j]) {
                seo = false;
                break;
            }
        }
        if (seo) {
            index_seo++;
            array[index_seo] = i;
        }
    }
    if (index_seo == 0) {
        Text(600, 300, "Danh sach trong", screen, font_h1, textColor);
        SDL_Flip(screen);
        SDL_Event event;
        SDL_Flip(screen);
        bool quit = false;
        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
                else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                    int x = event.button.x;
                    int y = event.button.y;
                    int index_y;
                    int position_y = (y - 260) / 30 + 1;
                    if (position_y > 6) {
                        index_y = ((y - 260) / 30) * 30 + 260 - 120;
                    }
                    else index_y = ((y - 260) / 30) * 30 + 260;
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (x > 600 && y > 190 && x < 730 && y < 215) {
                            SDL_Surface* seo = IMG_Load("seo.png");
                            HopThoai(600, 190, 130, 25, screen);
                            Image(605, 195, seo, screen);
                            SDL_Flip(screen);
                            while (!quit) {
                                while (SDL_PollEvent(&event)) {
                                    if (event.type == SDL_KEYDOWN) {
                                        if (event.key.keysym.sym == SDLK_ESCAPE) {
                                            quit = true;
                                        }
                                        else if (event.key.keysym.sym == SDLK_RETURN) {
                                            goto cancel_seo;
                                        }
                                        else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(Seo_mahp);
                                            if (length > 0) {
                                                Seo_mahp[length - 1] = '\0';
                                            }
                                            SDL_Surface* seo = IMG_Load("seo.png");
                                            HopThoai(600, 190, 130, 25, screen);
                                            Image(605, 195, seo, screen); // set lại hộp thoại
                                        }
                                        else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                            char keyPressed = (char)event.key.keysym.sym;
                                            if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                strncat(Seo_mahp, &keyPressed, 1);
                                            }
                                            if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_mahp);
                                                if (length > 0) {
                                                    Seo_mahp[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen);
                                            }
                                        }
                                    }
                                }
                                if (font != NULL) {
                                    SDL_Rect textRect;
                                    textRect.x = 630;
                                    textRect.y = 192;
                                    SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_mahp, textColor);
                                    SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                }
                                SDL_Flip(screen); // Cập nhật cửa sổ
                            }
                        }
                        if (x > 20 && x < 100 && y > 55 && y < 95) {
                            DangNhapAdmin();
                        }
                        if (x > 0 && y > 160 && x < 270 && y < 210) {
                            QuanliDkytc();
                        }
                        if (x > 0 && y > 210 && x < 270 && y < 260) {
                            strcpy_s(Seo_magv, "");
                            Demo_GiangVien();
                        }
                        if (x > 0 && y > 260 && x < 270 && y < 310) {
                            strcpy_s(Seo_masv, "");
                            Demo_SinhVien();
                        }
                        if (x > 0 && y > 310 && x < 270 && y < 360) {
                            strcpy_s(Seo_mahp, "");
                            Demo_HocPhan();
                        }
                        if (x > 0 && y > 360 && x < 270 && y < 410) {
                            Demo_LopHocPhan();
                        }
                        if (x > 0 && y > 410 && x < 270 && y < 460) {
                            Demo_Nhom();
                        }
                        if (x > 0 && y > 460 && x < 270 && y < 510) {
                            DoiMatKhau();
                        }
                        if (x > 0 && y > 510 && x < 270 && y < 560) {
                            Help();
                        }
                        if (x > 780 && x < 910 && y > 190 && y < 215) {
                            ThemHP();
                        }
                    }
                }
            }
        }
    }
    else {
        HopThoai(290, 230, 620, 30, screen);
        Text(295, 235, "TT", screen, font_h3, textColor_RED);
        DrawLine(screen, 340, 230, 340, 260, redColor);
        Text(345, 235, "Ten Hoc Phan", screen, font_h3, textColor_RED);
        DrawLine(screen, 550, 230, 550, 260, redColor);
        Text(555, 235, "Ma Hoc Phan", screen, font_h3, textColor_RED);
        DrawLine(screen, 670, 230, 670, 260, redColor);
        Text(675, 235, "Tin chi", screen, font_h3, textColor_RED);
        DrawLine(screen, 750, 230, 750, 260, redColor);
        DrawLine(screen, 830, 230, 830, 260, redColor);
        DrawLine(screen, 880, 230, 880, 260, redColor);
        int size = 0;
        int size_gv = index_seo;
        int time = 0;
    cancel_gv:
        int y_o = 260;
        int index = 10 * time + 1;
        if (size_gv > 10)  size = time * 10 + 10;
        else  size = time * 10 + size_gv;
        while (index <= size && index <= index_seo) {
            SDL_Surface* detail = IMG_Load("file.png");
            DrawLine(screen, 290, y_o, 290, y_o + 30, redColor);
            Text(295, y_o + 3, to_string(array[index]).c_str(), screen, font_h3, textColor);
            DrawLine(screen, 340, y_o, 340, y_o + 30, redColor);
            Text(345, y_o + 3, dshp[array[index]].gettenhocphan(), screen, font_h3, textColor);
            DrawLine(screen, 550, y_o, 550, y_o + 30, redColor);
            Text(555, y_o + 3, dshp[array[index]].getmahocphan(), screen, font_h3, textColor);
            DrawLine(screen, 670, y_o, 670, y_o + 30, redColor);
            char TC[5];
            doubleToCharArray(dshp[array[index]].gettchi(), TC, sizeof(TC));
            Text(695, y_o + 3, TC, screen, font_h3, textColor);
            DrawLine(screen, 750, y_o, 750, y_o + 30, redColor);
            Text(755, y_o + 3, "Chinh sua", screen, font_h3, textColor_RED);
            DrawLine(screen, 830, y_o, 830, y_o + 30, redColor);
            Text(835, y_o + 3, "Xoa", screen, font_h3, textColor_RED);
            DrawLine(screen, 880, y_o, 880, y_o + 30, redColor);
            Image(885, y_o + 5, detail, screen);
            DrawLine(screen, 910, y_o, 910, y_o + 30, redColor);
            index++;
            y_o += 30;
            DrawLine(screen, 290, y_o, 910, y_o, redColor);
            SDL_Flip(screen);
        }
        if (size_gv > 10 && time > 0) {
            Text(830, y_o + 10, "Xem them", screen, font_h3, textColor_RED);
            Text(290, y_o + 10, "Trang truoc", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 6) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 90;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinHocPhan(dshp[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_mahp);
                                                if (length > 0) {
                                                    Seo_mahp[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_mahp, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_mahp);
                                                    if (length > 0) {
                                                        Seo_mahp[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_mahp, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 290 && x < 400 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time--;
                                size_gv += 10;
                                goto cancel_gv;
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaHP(dshp[array[position]]);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanXoaHocPhan(dshp[array[position]]);
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinHocPhan(dshp[array[position]], screen, index_y);
                            }
                            if (x > 830 && x < 910 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time++;
                                size_gv -= 10;
                                goto cancel_gv;
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemHP();
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                        }
                    }
                }
            }
        }
        if (size_gv > 10 && time == 0) {
            Text(830, y_o + 10, "Xem them", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 6) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 90;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinHocPhan(dshp[array[position]], screen, index_y);
                        }
                        else {
                            SDL_Surface* seo = IMG_Load("seo.png");
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_mahp);
                                                if (length > 0) {
                                                    Seo_mahp[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_mahp, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_mahp);
                                                    if (length > 0) {
                                                        Seo_mahp[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_mahp, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 830 && x < 910 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time++;
                                size_gv -= 10;
                                goto cancel_gv;
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaHP(dshp[array[position]]);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                std::cout << position << endl;
                                XacNhanXoaHocPhan(dshp[array[position]]);
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinHocPhan(dshp[array[position]], screen, index_y);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemHP();
                            }
                        }
                    }
                }
            }
        }
        if (size_gv <= 10 && time == 0) {
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 6) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 90;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_mahp);
                                                if (length > 0) {
                                                    Seo_mahp[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_mahp, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_mahp);
                                                    if (length > 0) {
                                                        Seo_mahp[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_mahp, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaHP(dshp[array[position]]);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanXoaHocPhan(dshp[array[position]]);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinHocPhan(dshp[array[position]], screen, index_y);
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if(x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemHP();
                            }
                        }
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinHocPhan(dshp[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                    }
                }
            }
        }
        if (size_gv <= 10 && time > 0) {
            Text(290, y_o + 10, "Trang truoc", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 6) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 90;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_mahp);
                                                if (length > 0) {
                                                    Seo_mahp[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_mahp, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_mahp);
                                                    if (length > 0) {
                                                        Seo_mahp[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_mahp, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 290 && x < 400 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time--;
                                size_gv += 10;
                                goto cancel_gv;
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaHP(dshp[array[position]]);
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinHocPhan(dshp[array[position]], screen, index_y);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                std::cout << position << endl;
                                XacNhanXoaHocPhan(dshp[array[position]]);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemHP();
                            }
                        }
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinHocPhan(dshp[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                    }
                }
            }
        }
    }
    SDL_Flip(screen);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void Demo_LopHocPhan() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    SELECT_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor_W);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    BG_HopThoai(280, 160, 970, 490, screen);
    SDL_Flip(screen);
cancel_seo:
    SDL_Surface* seo = IMG_Load("seo.png");
    BG_HopThoai(280, 160, 970, 490, screen);
    LopHocPhan* dslhp = getfromfileLopHocPhan("LopHocPhan.txt");
    HocPhan* dshp = getfromfileHocPhan("HocPhan.txt");
    Text(290, 190, "Danh sach Lop hoc phan :", screen, font_h3, textColor);
    HopThoai(780, 190, 130, 25, screen);
    Text(785, 190, "Them Lop HP", screen, font_h3, textColor);
    HopThoai(600, 190, 130, 25, screen);
    Image(605, 195, seo, screen);
    if (strcmp(Seo_malhp, "") == 0) Text(630, 192, "Tim kiem", screen, font_h3, textColor);
    else Text(630, 192, Seo_malhp, screen, font_h3, textColor);
    int index_seo = 0;
    int array[1000];
    // tìm index thõa mãn điều kiện tìm kiếm
    for (int i = 1; i <= size_dslhp; i++) {
        bool seo = true;
        for (int j = 0; j < strlen(Seo_malhp); j++) {
            if (Seo_malhp[j] != dslhp[i].getmalophocphan()[j]) {
                seo = false;
                break;
            }
        }
        if (seo) {
            index_seo++;
            array[index_seo] = i;
        }
    }
    if (index_seo == 0) {
        Text(600, 300, "Danh sach trong", screen, font_h1, textColor);
        SDL_Flip(screen);
        SDL_Event event;
        SDL_Flip(screen);
        bool quit = false;
        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
                else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                    int x = event.button.x;
                    int y = event.button.y;
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (x > 600 && y > 190 && x < 730 && y < 215) {
                            SDL_Surface* seo = IMG_Load("seo.png");
                            HopThoai(600, 190, 130, 25, screen);
                            Image(605, 195, seo, screen);
                            SDL_Flip(screen);
                            while (!quit) {
                                while (SDL_PollEvent(&event)) {
                                    if (event.type == SDL_KEYDOWN) {
                                        if (event.key.keysym.sym == SDLK_ESCAPE) {
                                            quit = true;
                                        }
                                        else if (event.key.keysym.sym == SDLK_RETURN) {
                                            goto cancel_seo;
                                        }
                                        else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(Seo_malhp);
                                            if (length > 0) {
                                                Seo_malhp[length - 1] = '\0';
                                            }
                                            SDL_Surface* seo = IMG_Load("seo.png");
                                            HopThoai(600, 190, 130, 25, screen);
                                            Image(605, 195, seo, screen); // set lại hộp thoại
                                        }
                                        else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                            char keyPressed = (char)event.key.keysym.sym;
                                            if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                strncat(Seo_malhp, &keyPressed, 1);
                                            }
                                            if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_malhp);
                                                if (length > 0) {
                                                    Seo_malhp[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen);
                                            }
                                        }
                                    }
                                }
                                if (font != NULL) {
                                    SDL_Rect textRect;
                                    textRect.x = 630;
                                    textRect.y = 192;
                                    SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_malhp, textColor);
                                    SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                }
                                SDL_Flip(screen); // Cập nhật cửa sổ
                            }
                        }
                        if (x > 20 && x < 100 && y > 55 && y < 95) {
                            DangNhapAdmin();
                        }
                        if (x > 0 && y > 160 && x < 270 && y < 210) {
                            QuanliDkytc();
                        }
                        if (x > 0 && y > 210 && x < 270 && y < 260) {
                            strcpy_s(Seo_magv, "");
                            Demo_GiangVien();
                        }
                        if (x > 0 && y > 260 && x < 270 && y < 310) {
                            strcpy_s(Seo_masv, "");
                            Demo_SinhVien();
                        }
                        if (x > 0 && y > 310 && x < 270 && y < 360) {
                            strcpy_s(Seo_mahp, "");
                            Demo_HocPhan();
                        }
                        if (x > 0 && y > 360 && x < 270 && y < 410) {
                            strcpy_s(Seo_malhp, "");
                            Demo_LopHocPhan();
                        }
                        if (x > 0 && y > 410 && x < 270 && y < 460) {
                            strcpy_s(Seo_magr, "");
                            Demo_Nhom();
                        }
                        if (x > 0 && y > 460 && x < 270 && y < 510) {
                            DoiMatKhau();
                        }
                        if (x > 0 && y > 510 && x < 270 && y < 560) {
                            Help();
                        }
                        if (x > 780 && x < 910 && y > 190 && y < 215) {
                            ThemSV();
                        }
                    }
                }
            }
        }
    }
    else {
        HopThoai(290, 230, 620, 30, screen);
        Text(295, 235, "TT", screen, font_h3, textColor_RED);
        DrawLine(screen, 340, 230, 340, 260, redColor);
        Text(345, 235, "Ten Hoc Phan", screen, font_h3, textColor_RED);
        DrawLine(screen, 550, 230, 550, 260, redColor);
        Text(555, 235, "Ma Lop HP", screen, font_h3, textColor_RED);
        DrawLine(screen, 670, 230, 670, 260, redColor);
        Text(685, 235, "CLC", screen, font_h3, textColor_RED);
        DrawLine(screen, 750, 230, 750, 260, redColor);
        DrawLine(screen, 830, 230, 830, 260, redColor);
        DrawLine(screen, 880, 230, 880, 260, redColor);
        int size = 0;
        int size_lhp = index_seo;
        int time = 0;
    cancel_lhp:
        int y_o = 260;
        int index = 10 * time + 1;
        if (size_lhp > 10)  size = time * 10 + 10;
        else  size = time * 10 + size_lhp;
        while (index <= size && index <= index_seo) {
            SDL_Surface* detail = IMG_Load("file.png");
            DrawLine(screen, 290, y_o, 290, y_o + 30, redColor);
            Text(295, y_o + 3, to_string(array[index]).c_str(), screen, font_h3, textColor);
            DrawLine(screen, 340, y_o, 340, y_o + 30, redColor);
            Text(345, y_o + 3, getHocPhan(dslhp[array[index]].getmahocphan() , dshp , size_dshp ).gettenhocphan(), screen, font_h3, textColor);
            DrawLine(screen, 550, y_o, 550, y_o + 30, redColor);
            Text(555, y_o + 3, dslhp[array[index]].getmalophocphan(), screen, font_h3, textColor);
            DrawLine(screen, 670, y_o, 670, y_o + 30, redColor);
            Text(695, y_o + 3, (dslhp[array[index]].getCLC() ? "X" : ""), screen, font_h3, textColor);
            DrawLine(screen, 750, y_o, 750, y_o + 30, redColor);
            Text(755, y_o + 3, "Chinh sua", screen, font_h3, textColor_RED);
            DrawLine(screen, 830, y_o, 830, y_o + 30, redColor);
            Text(835, y_o + 3, "Xoa", screen, font_h3, textColor_RED);
            DrawLine(screen, 880, y_o, 880, y_o + 30, redColor);
            Image(885, y_o + 5, detail, screen);
            DrawLine(screen, 910, y_o, 910, y_o + 30, redColor);
            index++;
            y_o += 30;
            DrawLine(screen, 290, y_o, 910, y_o, redColor);
            SDL_Flip(screen);
        }
        if (size_lhp > 10 && time > 0) {
            Text(830, y_o + 10, "Xem them", screen, font_h3, textColor_RED);
            Text(290, y_o + 10, "Trang truoc", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 4) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinLHP(dslhp[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_malhp);
                                                if (length > 0) {
                                                    Seo_malhp[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_malhp, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_malhp);
                                                    if (length > 0) {
                                                        Seo_malhp[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_malhp, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 290 && x < 400 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time--;
                                size_lhp += 10;
                                goto cancel_lhp;
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaLHP(dslhp[array[position]]);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanXoaLHP(dslhp[array[position]]);
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinLHP(dslhp[array[position]], screen, index_y);
                            }
                            if (x > 830 && x < 910 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time++;
                                size_lhp -= 10;
                                goto cancel_lhp;
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemLHP();
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                strcpy_s(Seo_malhp, "");
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                strcpy_s(Seo_magr, "");
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                        }
                    }
                }
            }
        }
        if (size_lhp > 10 && time == 0) {
            Text(830, y_o + 10, "Xem them", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 4) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinLHP(dslhp[array[position]], screen, index_y);
                        }
                        else {
                            SDL_Surface* seo = IMG_Load("seo.png");
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_malhp);
                                                if (length > 0) {
                                                    Seo_malhp[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_malhp, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_malhp);
                                                    if (length > 0) {
                                                        Seo_malhp[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_malhp, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 830 && x < 910 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time++;
                                size_lhp -= 10;
                                goto cancel_lhp;
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaLHP(dslhp[array[position]]);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanXoaLHP(dslhp[array[position]]);
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinLHP(dslhp[array[position]], screen, index_y);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                strcpy_s(Seo_malhp, "");
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                strcpy_s(Seo_magr, "");
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemLHP();
                            }
                        }
                    }
                }
            }
        }
        if (size_lhp <= 10 && time == 0) {
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 4) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_malhp);
                                                if (length > 0) {
                                                    Seo_malhp[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_malhp, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_malhp);
                                                    if (length > 0) {
                                                        Seo_malhp[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_malhp, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaLHP(dslhp[array[position]]);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanXoaLHP(dslhp[array[position]]);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinLHP(dslhp[array[position]], screen, index_y);
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                strcpy_s(Seo_malhp, "");
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                strcpy_s(Seo_magr, "");
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemLHP();
                            }
                        }
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinLHP(dslhp[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                    }
                }
            }
        }
        if (size_lhp <= 10 && time > 0) {
            Text(290, y_o + 10, "Trang truoc", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 4) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 600 && y > 190 && x < 730 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(600, 190, 130, 25, screen);
                                Image(605, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_malhp);
                                                if (length > 0) {
                                                    Seo_malhp[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen); // set lại hộp thoại
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_malhp, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_malhp);
                                                    if (length > 0) {
                                                        Seo_malhp[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(600, 190, 130, 25, screen);
                                                    Image(605, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 630;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_malhp, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 290 && x < 400 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time--;
                                size_lhp += 10;
                                goto cancel_lhp;
                            }
                            if (x > 750 && x < 830 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ChinhSuaLHP(dslhp[array[position]]);
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinLHP(dslhp[array[position]], screen, index_y);
                            }
                            if (x > 830 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanXoaLHP(dslhp[array[position]]);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                strcpy_s(Seo_malhp, "");
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                strcpy_s(Seo_magr, "");
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                            if (x > 780 && x < 910 && y > 190 && y < 215) {
                                ThemLHP();
                            }
                        }
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinLHP(dslhp[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                    }
                }
            }
        }
    }
    SDL_Flip(screen);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void Demo_Nhom() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    SELECT_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor_W);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    BG_HopThoai(280, 160, 970, 490, screen);
    SDL_Flip(screen);
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        DangNhapAdmin();
                    }
                    if (x > 0 && y > 160 && x < 270 && y < 210) {
                        QuanliDkytc();
                    }
                    if (x > 0 && y > 210 && x < 270 && y < 260) {
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 260 && x < 270 && y < 310) {
                        Demo_SinhVien();
                    }
                    if (x > 0 && y > 310 && x < 270 && y < 360) {
                        Demo_HocPhan();
                    }
                    if (x > 0 && y > 360 && x < 270 && y < 410) {
                        Demo_LopHocPhan();
                    }
                    if (x > 0 && y > 410 && x < 270 && y < 460) {
                        Demo_Nhom();
                    }
                    if (x > 0 && y > 460 && x < 270 && y < 510) {
                        DoiMatKhau();
                    }
                    if (x > 0 && y > 510 && x < 270 && y < 560) {
                        Help();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void Help() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    SELECT_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor_W);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    //
cancel_seo:
    SDL_Surface* seo = IMG_Load("seo.png");
    BG_HopThoai(280, 160, 970, 490, screen);
    SinhVien* dssv = getfromfileSinhVien("SinhVien.txt");
    User* dsur = getfromfileUsers("Users.txt");
    Text(290, 190, "Ho tro doi mat khau cho Sinh Vien :", screen, font_h3, textColor);
    HopThoai(750, 190, 130, 25, screen);
    Image(755, 195, seo, screen);
    if (strcmp(Seo_masv, "") == 0) Text(780, 192, "Tim kiem", screen, font_h3, textColor);
    else Text(780, 192, Seo_masv, screen, font_h3, textColor);
    int index_seo = 0;
    int array[1000];
    // tìm index thõa mãn điều kiện tìm kiếm
    for (int i = 1; i <= size_dssv; i++) {
        bool seo = true;
        for (int j = 0; j < strlen(Seo_masv); j++) {
            if (Seo_masv[j] != dssv[i].getMSSV()[j]) {
                seo = false;
                break;
            }
        }
        if (seo) {
            index_seo++;
            array[index_seo] = i;
        }
    }
    if (index_seo == 0) {
        Text(600, 300, "Danh sach trong", screen, font_h1, textColor);
        SDL_Flip(screen);
        SDL_Event event;
        SDL_Flip(screen);
        bool quit = false;
        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
                else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                    int x = event.button.x;
                    int y = event.button.y;
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (x > 600 && y > 190 && x < 730 && y < 215) {
                            SDL_Surface* seo = IMG_Load("seo.png");
                            HopThoai(600, 190, 130, 25, screen);
                            Image(605, 195, seo, screen);
                            SDL_Flip(screen);
                            while (!quit) {
                                while (SDL_PollEvent(&event)) {
                                    if (event.type == SDL_KEYDOWN) {
                                        if (event.key.keysym.sym == SDLK_ESCAPE) {
                                            quit = true;
                                        }
                                        else if (event.key.keysym.sym == SDLK_RETURN) {
                                            goto cancel_seo;
                                        }
                                        else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(Seo_masv);
                                            if (length > 0) {
                                                Seo_masv[length - 1] = '\0';
                                            }
                                            SDL_Surface* seo = IMG_Load("seo.png");
                                            HopThoai(600, 190, 130, 25, screen);
                                            Image(605, 195, seo, screen); // set lại hộp thoại
                                        }
                                        else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                            char keyPressed = (char)event.key.keysym.sym;
                                            if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                strncat(Seo_masv, &keyPressed, 1);
                                            }
                                            if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_masv);
                                                if (length > 0) {
                                                    Seo_masv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(600, 190, 130, 25, screen);
                                                Image(605, 195, seo, screen);
                                            }
                                        }
                                    }
                                }
                                if (font != NULL) {
                                    SDL_Rect textRect;
                                    textRect.x = 630;
                                    textRect.y = 192;
                                    SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_masv, textColor);
                                    SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                }
                                SDL_Flip(screen); // Cập nhật cửa sổ
                            }
                        }
                        if (x > 20 && x < 100 && y > 55 && y < 95) {
                            DangNhapAdmin();
                        }
                        if (x > 0 && y > 160 && x < 270 && y < 210) {
                            QuanliDkytc();
                        }
                        if (x > 0 && y > 210 && x < 270 && y < 260) {
                            strcpy_s(Seo_magv, "");
                            Demo_GiangVien();
                        }
                        if (x > 0 && y > 260 && x < 270 && y < 310) {
                            strcpy_s(Seo_masv, "");
                            Demo_SinhVien();
                        }
                        if (x > 0 && y > 310 && x < 270 && y < 360) {
                            strcpy_s(Seo_mahp, "");
                            Demo_HocPhan();
                        }
                        if (x > 0 && y > 360 && x < 270 && y < 410) {
                            Demo_LopHocPhan();
                        }
                        if (x > 0 && y > 410 && x < 270 && y < 460) {
                            Demo_Nhom();
                        }
                        if (x > 0 && y > 460 && x < 270 && y < 510) {
                            DoiMatKhau();
                        }
                        if (x > 0 && y > 510 && x < 270 && y < 560) {
                            Help();
                        }
                    }
                }
            }
        }
    }
    else {
        HopThoai(290, 230, 620, 30, screen);
        Text(295, 235, "TT", screen, font_h3, textColor_RED);
        DrawLine(screen, 340, 230, 340, 260, redColor);
        Text(345, 235, "Ten Sinh Vien", screen, font_h3, textColor_RED);
        DrawLine(screen, 550, 230, 550, 260, redColor);
        Text(555, 235, "MS Sinh Vien", screen, font_h3, textColor_RED);
        DrawLine(screen, 670, 230, 670, 260, redColor);
        Text(675, 235, "Gioi tinh", screen, font_h3, textColor_RED);
        DrawLine(screen, 750, 230, 750, 260, redColor);
        DrawLine(screen, 880, 230, 880, 260, redColor);
        int size = 0;
        int size_sv = index_seo;
        int time = 0;
    cancel_sv:
        int y_o = 260;
        int index = 10 * time + 1;
        if (size_sv > 10)  size = time * 10 + 10;
        else  size = time * 10 + size_sv;
        while (index <= size && index <= index_seo) {
            SDL_Surface* detail = IMG_Load("file.png");
            DrawLine(screen, 290, y_o, 290, y_o + 30, redColor);
            Text(295, y_o + 3, to_string(array[index]).c_str(), screen, font_h3, textColor);
            DrawLine(screen, 340, y_o, 340, y_o + 30, redColor);
            Text(345, y_o + 3, dssv[array[index]].gethoten(), screen, font_h3, textColor);
            DrawLine(screen, 550, y_o, 550, y_o + 30, redColor);
            Text(555, y_o + 3, dssv[array[index]].getMSSV(), screen, font_h3, textColor);
            DrawLine(screen, 670, y_o, 670, y_o + 30, redColor);
            Text(695, y_o + 3, (dssv[array[index]].getgioitinh() ? "X" : ""), screen, font_h3, textColor);
            DrawLine(screen, 750, y_o, 750, y_o + 30, redColor);
            Text(755, y_o + 3, "Reset Password", screen, font_h3, textColor_RED);
            DrawLine(screen, 880, y_o, 880, y_o + 30, redColor);
            Image(885, y_o + 5, detail, screen);
            DrawLine(screen, 910, y_o, 910, y_o + 30, redColor);
            index++;
            y_o += 30;
            DrawLine(screen, 290, y_o, 910, y_o, redColor);
            SDL_Flip(screen);
        }
        if (size_sv > 10 && time > 0) {
            Text(830, y_o + 10, "Xem them", screen, font_h3, textColor_RED);
            Text(290, y_o + 10, "Trang truoc", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 4) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinUser(dsur[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 750 && y > 190 && x < 880 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(750, 190, 130, 25, screen);
                                Image(755, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_masv);
                                                if (length > 0) {
                                                    Seo_masv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(750, 190, 130, 25, screen);
                                                Image(755, 195, seo, screen);
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_masv, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_masv);
                                                    if (length > 0) {
                                                        Seo_masv[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(750, 190, 130, 25, screen);
                                                    Image(755, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 780;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_masv, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 290 && x < 400 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time--;
                                size_sv += 10;
                                goto cancel_sv;
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinUser(dsur[array[position]], screen, index_y);
                            }
                            if (x > 750 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanResetPW(dssv[array[position]]);
                            }
                            if (x > 830 && x < 910 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time++;
                                size_sv -= 10;
                                goto cancel_sv;
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                        }
                    }
                }
            }
        }
        if (size_sv > 10 && time == 0) {
            Text(830, y_o + 10, "Xem them", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 4) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinUser(dsur[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 750 && y > 190 && x < 880 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(750, 190, 130, 25, screen);
                                Image(755, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_masv);
                                                if (length > 0) {
                                                    Seo_masv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(750, 190, 130, 25, screen);
                                                Image(755, 195, seo, screen);
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_masv, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_masv);
                                                    if (length > 0) {
                                                        Seo_masv[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(750, 190, 130, 25, screen);
                                                    Image(755, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 780;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_masv, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 830 && x < 910 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time++;
                                size_sv -= 10;
                                goto cancel_sv;
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinUser(dsur[array[position]], screen, index_y);
                            }
                            if (x > 750 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanResetPW(dssv[array[position]]);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                        }
                    }
                }
            }
        }
        if (size_sv <= 10 && time == 0) {
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 4) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 750 && y > 190 && x < 880 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(750, 190, 130, 25, screen);
                                Image(755, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_masv);
                                                if (length > 0) {
                                                    Seo_masv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(750, 190, 130, 25, screen);
                                                Image(755, 195, seo, screen);
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_masv, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_masv);
                                                    if (length > 0) {
                                                        Seo_masv[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(750, 190, 130, 25, screen);
                                                    Image(755, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 780;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_masv, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinUser(dsur[array[position]], screen, index_y);
                            }
                            if (x > 750 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanResetPW(dssv[array[position]]);
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                        }
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinUser(dsur[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                    }
                }
            }
        }
        if (size_sv <= 10 && time > 0) {
            Text(290, y_o + 10, "Trang truoc", screen, font_h3, textColor_RED);
            SDL_Event event;
            SDL_Flip(screen);
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
                        int x = event.button.x;
                        int y = event.button.y;
                        int index_y;
                        int position_y = (y - 260) / 30 + 1;
                        if (position_y > 4) {
                            index_y = ((y - 260) / 30) * 30 + 260 - 170;
                        }
                        else index_y = ((y - 260) / 30) * 30 + 260;
                        if (event.button.button == SDL_BUTTON_LEFT) {
                            if (x > 750 && y > 190 && x < 880 && y < 215) {
                                SDL_Surface* seo = IMG_Load("seo.png");
                                HopThoai(750, 190, 130, 25, screen);
                                Image(755, 195, seo, screen);
                                SDL_Flip(screen);
                                while (!quit) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_KEYDOWN) {
                                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                                quit = true;
                                            }
                                            else if (event.key.keysym.sym == SDLK_RETURN) {
                                                goto cancel_seo;
                                            }
                                            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                int length = strlen(Seo_masv);
                                                if (length > 0) {
                                                    Seo_masv[length - 1] = '\0';
                                                }
                                                SDL_Surface* seo = IMG_Load("seo.png");
                                                HopThoai(750, 190, 130, 25, screen);
                                                Image(755, 195, seo, screen);
                                            }
                                            else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                                char keyPressed = (char)event.key.keysym.sym;
                                                if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                                    strncat(Seo_masv, &keyPressed, 1);
                                                }
                                                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                                    int length = strlen(Seo_masv);
                                                    if (length > 0) {
                                                        Seo_masv[length - 1] = '\0';
                                                    }
                                                    SDL_Surface* seo = IMG_Load("seo.png");
                                                    HopThoai(750, 190, 130, 25, screen);
                                                    Image(755, 195, seo, screen);
                                                }
                                            }
                                        }
                                    }
                                    if (font != NULL) {
                                        SDL_Rect textRect;
                                        textRect.x = 780;
                                        textRect.y = 192;
                                        SDL_Surface* textSurface = TTF_RenderText_Solid(font_h3, Seo_masv, textColor);
                                        SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                                    }
                                    SDL_Flip(screen); // Cập nhật cửa sổ
                                }
                            }
                            if (x > 290 && x < 400 && y > y_o + 10 && y < y_o + 30) {
                                BG_HopThoai(280, 261, 970, 490, screen);
                                time--;
                                size_sv += 10;
                                goto cancel_sv;
                            }
                            if (x > 880 && x < 910 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                ThongtinUser(dsur[array[position]], screen, index_y);
                            }
                            if (x > 750 && x < 880 && y > 260 && y < y_o) {
                                int position = (y - 260) / 30 + 1 + time * 10;
                                XacNhanResetPW(dssv[array[position]]);
                            }
                            if (x > 20 && x < 100 && y > 55 && y < 95) {
                                DangNhapAdmin();
                            }
                            if (x > 0 && y > 160 && x < 270 && y < 210) {
                                QuanliDkytc();
                            }
                            if (x > 0 && y > 210 && x < 270 && y < 260) {
                                strcpy_s(Seo_magv, "");
                                Demo_GiangVien();
                            }
                            if (x > 0 && y > 260 && x < 270 && y < 310) {
                                strcpy_s(Seo_masv, "");
                                Demo_SinhVien();
                            }
                            if (x > 0 && y > 310 && x < 270 && y < 360) {
                                strcpy_s(Seo_mahp, "");
                                Demo_HocPhan();
                            }
                            if (x > 0 && y > 360 && x < 270 && y < 410) {
                                Demo_LopHocPhan();
                            }
                            if (x > 0 && y > 410 && x < 270 && y < 460) {
                                Demo_Nhom();
                            }
                            if (x > 0 && y > 460 && x < 270 && y < 510) {
                                DoiMatKhau();
                            }
                            if (x > 0 && y > 510 && x < 270 && y < 560) {
                                Help();
                            }
                        }
                        if (x > 880 && x < 910 && y > 260 && y < y_o) {
                            int position = (y - 260) / 30 + 1 + time * 10;
                            ThongtinUser(dsur[array[position]], screen, index_y);
                        }
                        else {
                            BG_HopThoai(911, 210, 330, 400, screen);
                            SDL_Flip(screen);
                        }
                    }
                }
            }
        }
    }
    SDL_Flip(screen);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void DoiMatKhau() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    Admin* dsAd = getfromfileAdmin("Admin.txt");
    Admin AD = getad(IDAdmin, dsAd, size_admin);
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    BG_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    SELECT_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor_W);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 550, 270, 110, screen);
    BG_HopThoai(280, 160, 970, 490, screen);
    //
    Text(580, 200, "DOI MAT KHAU", screen, font_h2, textColor);
    HopThoai(650, 270, 400, 50, screen);
    HopThoai(650, 350, 400, 50, screen);
    HopThoai(650, 430, 400, 50, screen);
    HopThoai(700, 500, 300, 50, screen);
    Text(330, 270, "Nhap mat khau cu : ", screen, font_h1, textColor);
    Text(330, 350, "Nhap mat khau moi : ", screen, font_h1, textColor);
    Text(330, 430, "Xac nhan mat khau moi : ", screen, font_h1, textColor);
    Text(750, 500, "Xac nhan ", screen, font, textColor_RED);
    SDL_Flip(screen);
    char mk_cu[20] = "";
    char hide_mk_cu[20] = "";
    char mk_moi[20] = "";
    char hide_mk_moi[20] = "";
    char xmk_moi[20] = "";
    char xhide_mk_moi[20] = "";
    char hide = '*';
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 650 && y > 270 && x < 1050 && y < 320) {
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(mk_cu);
                                        if (length > 0) {
                                            mk_cu[length - 1] = '\0';
                                            hide_mk_cu[length - 1] = '\0';
                                        }
                                        HopThoai(650, 270, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                            strncat(mk_cu, &keyPressed, 1);
                                            strncat(hide_mk_cu, &hide, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(mk_cu);
                                            if (length > 0) {
                                                mk_cu[length - 1] = '\0';
                                                hide_mk_cu[length - 1] = '\0';
                                            }
                                            HopThoai(650, 270, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 660;
                                textRect.y = 275;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font, hide_mk_cu, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 650 && y > 350 && x < 1050 && y < 400) {
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(mk_moi);
                                        if (length > 0) {
                                            mk_moi[length - 1] = '\0';
                                            hide_mk_moi[length - 1] = '\0';
                                        }
                                        HopThoai(650, 350, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                            strncat(mk_moi, &keyPressed, 1);
                                            strncat(hide_mk_moi, &hide, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(mk_moi);
                                            if (length > 0) {
                                                mk_moi[length - 1] = '\0';
                                                hide_mk_moi[length - 1] = '\0';
                                            }
                                            HopThoai(650, 350, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 660;
                                textRect.y = 355;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font, hide_mk_moi, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 650 && y > 430 && x < 1050 && y < 480) {
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(xmk_moi);
                                        if (length > 0) {
                                            xmk_moi[length - 1] = '\0';
                                            xhide_mk_moi[length - 1] = '\0';
                                        }
                                        HopThoai(650, 430, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                            strncat(xmk_moi, &keyPressed, 1);
                                            strncat(xhide_mk_moi, &hide, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(xmk_moi);
                                            if (length > 0) {
                                                xmk_moi[length - 1] = '\0';
                                                xhide_mk_moi[length - 1] = '\0';
                                            }
                                            HopThoai(650, 430, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 660;
                                textRect.y = 435;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font, xhide_mk_moi, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 700 && y > 500 && x < 1000 && y < 550) {
                        char title1[] = "            Sai mat khau cu";
                        char title3[] = "         Doi mat khau thanh cong";
                        char title2[] = "";
                        char title4[] = "    Mat khau xac nhan khong giong nhau";
                        char title5[] = "          Khong duoc de trong";
                        if (strcmp(mk_cu, "") == 0 || strcmp(mk_moi, "") == 0|| strcmp(xmk_moi, "") == 0) Alert(title5, title2, "Khong duoc de trong");
                        else if (strcmp(mk_cu, AD.getmk()) != 0) Alert(title1, title2, "Sai mat khau");
                        else if(strcmp(mk_moi, xmk_moi) != 0)  Alert(title4, title2, "Sai mat khau");
                        else {
                            ofstream o;
                            o.open("Admin.txt", ios::trunc);
                            for (int i = 0; i < size_admin; i++) {
                                if (strcmp(dsAd[i].getIdAdmin(), IDAdmin) == 0)
                                {
                                    o << IDAdmin << endl;
                                    o << mk_moi << endl;
                                }
                                else {
                                    o << dsAd[i].getIdAdmin() << endl;
                                    o << dsAd[i].getmk() << endl;
                                }
                            }
                            o.close();
                            Alert(title3, title2, "Doi mat khau thanh cong");
                            DoiMatKhau();
                        }
                    }
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        DangNhapAdmin();
                    }
                    if (x > 0 && y > 160 && x < 270 && y < 210) {
                        QuanliDkytc();
                    }
                    if (x > 0 && y > 210 && x < 270 && y < 260) {
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 260 && x < 270 && y < 310) {
                        Demo_SinhVien();
                    }
                    if (x > 0 && y > 310 && x < 270 && y < 360) {
                        Demo_HocPhan();
                    }
                    if (x > 0 && y > 360 && x < 270 && y < 410) {
                        Demo_LopHocPhan();
                    }
                    if (x > 0 && y > 410 && x < 270 && y < 460) {
                        Demo_Nhom();
                    }
                    if (x > 0 && y > 460 && x < 270 && y < 510) {
                        DoiMatKhau();
                    }
                    if (x > 0 && y > 510 && x < 270 && y < 560) {
                        Help();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void DoiMatKhauSV() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 255, 255, 255);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    User* dsur = getfromfileUsers("Users.txt");
    User us = getUR("Users.txt", MSSV);
    // ve ki tu
    Text(150, 20, "He thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    SDL_Surface* image = IMG_Load("student.png");
    Tron_HopThoai(900, 20, 320, 90, screen);
    Image(900, 20, image, screen);
    Text(1000, 40, "SINH VIEN", screen, font, textColor);
    HopThoai(650, 270, 400, 50, screen);
    HopThoai(650, 350, 400, 50, screen);
    HopThoai(650, 430, 400, 50, screen);
    HopThoai(700, 500, 300, 50, screen);
    Text(580, 180, "DOI MAT KHAU", screen, font_h2, textColor);
    Text(330, 270, "Nhap mat khau cu : ", screen, font_h1, textColor);
    Text(330, 350, "Nhap mat khau moi : ", screen, font_h1, textColor);
    Text(330, 430, "Xac nhan mat khau moi : ", screen, font_h1, textColor);
    Text(750, 500, "Xac nhan ", screen, font, textColor_RED);
    SDL_Flip(screen);
    char mk_cu[20] = "";
    char hide_mk_cu[20] = "";
    char mk_moi[20] = "";
    char hide_mk_moi[20] = "";
    char xmk_moi[20] = "";
    char xhide_mk_moi[20] = "";
    char hide = '*';
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 650 && y > 270 && x < 1050 && y < 320) {
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(mk_cu);
                                        if (length > 0) {
                                            mk_cu[length - 1] = '\0';
                                            hide_mk_cu[length - 1] = '\0';
                                        }
                                        HopThoai(650, 270, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                            strncat(mk_cu, &keyPressed, 1);
                                            strncat(hide_mk_cu, &hide, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(mk_cu);
                                            if (length > 0) {
                                                mk_cu[length - 1] = '\0';
                                                hide_mk_cu[length - 1] = '\0';
                                            }
                                            HopThoai(650, 270, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 660;
                                textRect.y = 275;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font, hide_mk_cu, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 650 && y > 350 && x < 1050 && y < 400) {
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(mk_moi);
                                        if (length > 0) {
                                            mk_moi[length - 1] = '\0';
                                            hide_mk_moi[length - 1] = '\0';
                                        }
                                        HopThoai(650, 350, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                            strncat(mk_moi, &keyPressed, 1);
                                            strncat(hide_mk_moi, &hide, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(mk_moi);
                                            if (length > 0) {
                                                mk_moi[length - 1] = '\0';
                                                hide_mk_moi[length - 1] = '\0';
                                            }
                                            HopThoai(650, 350, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 660;
                                textRect.y = 355;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font, hide_mk_moi, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 650 && y > 430 && x < 1050 && y < 480) {
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(xmk_moi);
                                        if (length > 0) {
                                            xmk_moi[length - 1] = '\0';
                                            xhide_mk_moi[length - 1] = '\0';
                                        }
                                        HopThoai(650, 430, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                            strncat(xmk_moi, &keyPressed, 1);
                                            strncat(xhide_mk_moi, &hide, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(xmk_moi);
                                            if (length > 0) {
                                                xmk_moi[length - 1] = '\0';
                                                xhide_mk_moi[length - 1] = '\0';
                                            }
                                            HopThoai(650, 430, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 660;
                                textRect.y = 435;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font, xhide_mk_moi, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 700 && y > 500 && x < 1000 && y < 550) {
                        char title1[] = "            Sai mat khau cu";
                        char title3[] = "         Doi mat khau thanh cong";
                        char title2[] = "";
                        char title4[] = "    Mat khau xac nhan khong giong nhau";
                        char title5[] = "          Khong duoc de trong";
                        cout << us.getmk() << endl;
                        if (strcmp(mk_cu, "") == 0 || strcmp(mk_moi, "") == 0 || strcmp(xmk_moi, "") == 0) Alert(title5, title2, "Khong duoc de trong");
                        else if (strcmp(mk_cu, us.getmk()) != 0) Alert(title1, title2, "Sai mat khau");
                        else if (strcmp(mk_moi, xmk_moi) != 0)  Alert(title4, title2, "Sai mat khau");
                        else {
                            ofstream o;
                            o.open("Users.txt", ios::trunc);
                            for (int i = 1; i < size_user; i++) {
                                if (strcmp(dsur[i].getMSSV(), MSSV) == 0)
                                {
                                    o << MSSV << endl;
                                    o << mk_moi << endl;
                                }
                                else {
                                    o << dsur[i].getMSSV() << endl;
                                    o << dsur[i].getmk() << endl;
                                }
                            }
                            o.close();
                            Alert(title3, title2, "Doi mat khau thanh cong");
                            DoiMatKhauSV();
                        }
                    }
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        Dangkitinchi();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void QuanliDkytc() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Quan li he thong dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 209, 216, 227);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    BG_HopThoai(0, 0, 1260, 150, screen);
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 25);
    TTF_Font* font_h2 = TTF_OpenFont("Mali-Light.ttf", 40);
    TTF_Font* font_h3 = TTF_OpenFont("Mali-Light.ttf", 15);
    SDL_Surface* image = IMG_Load("admin.png");
    SDL_Surface* home = IMG_Load("home.png");
    SDL_Surface* help = IMG_Load("help-desk.png");
    SDL_Surface* pass = IMG_Load("reset-password.png");
    SDL_Surface* clas = IMG_Load("online-learning.png");
    SDL_Surface* term = IMG_Load("contact.png");
    SDL_Surface* student = IMG_Load("graduated.png");
    SDL_Surface* teacher = IMG_Load("female.png");
    SDL_Surface* group = IMG_Load("meeting.png");
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_W = { 255,255,255 }; // trắng
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "Quan ly he thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Tron_HopThoai(900, 20, 280, 90, screen);
    Image(900, 20, image, screen);
    Text(1030, 40, "ADMIN", screen, font_h2, textColor);
    // button
    // ve hop thoai     
    SELECT_HopThoai(0, 160, 270, 50, screen);
    Text(60, 170, "Trang Chu", screen, font_h1, textColor_W);
    Image(20, 175, home, screen);
    BG_HopThoai(0, 210, 270, 50, screen);
    Text(60, 220, "Giang Vien", screen, font_h1, textColor);
    Image(20, 225, teacher, screen);
    BG_HopThoai(0, 260, 270, 50, screen);
    Text(60, 270, "Sinh Vien", screen, font_h1, textColor);
    Image(20, 275, student, screen);
    BG_HopThoai(0, 310, 270, 50, screen);
    Text(60, 320, "Hoc Phan", screen, font_h1, textColor);
    Image(20, 325, term, screen);
    BG_HopThoai(0, 360, 270, 50, screen);
    Text(60, 370, "Lop Hoc Phan", screen, font_h1, textColor);
    Image(20, 375, clas, screen);
    BG_HopThoai(0, 410, 270, 50, screen);
    Text(60, 420, "Nhom", screen, font_h1, textColor);
    Image(20, 425, group, screen);
    BG_HopThoai(0, 460, 270, 50, screen);
    Text(60, 470, "Doi mat khau", screen, font_h1, textColor);
    Image(20, 475, pass, screen);
    BG_HopThoai(0, 510, 270, 50, screen);
    Text(60, 520, "Ho tro", screen, font_h1, textColor);
    Image(20, 525, help, screen);
    BG_HopThoai(0, 560, 270, 110, screen);
    BG_HopThoai(280, 160, 970, 490, screen);
    SDL_Flip(screen);
    Text(290, 190, "Lich su thay doi gan day:", screen, font_h3, textColor_RED);
    HopThoai(760, 190, 100, 25, screen);
    Text(770, 190, "Xoa lich su", screen, font_h3, textColor);
    HopThoai(900, 190, 270, 25, screen);
    Text(905, 190, "Chinh sua thoi gian dang ky tin chi", screen, font_h3, textColor);
    ifstream file("LichSuThayDoi.txt");
    string history_cloud[100];
    int i = 0;
    int indexy = 190;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            history_cloud[i] = line;
            i++;
        }
        file.close();
        ofstream o;
        o.open("LichSuThayDoi.txt", ios::trunc);
        for (int j = i - 1 ; j > i - 14; j--) {
            Text(350, indexy + 30, history_cloud[j].c_str(), screen, font_h3, textColor);
            indexy += 30;
            o << history_cloud[2*i - j - 14] << endl;
        }
        o.close();
    }
    else {
        cout << "Không thể mở file." << endl;
    }
    SDL_Flip(screen);
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        DangNhapAdmin();
                    }
                    if (x > 0 && y > 160 && x < 270 && y < 210) {
                        QuanliDkytc();
                    }
                    if (x > 0 && y > 210 && x < 270 && y < 260) {
                        Demo_GiangVien();
                    }
                    if (x > 0 && y > 260 && x < 270 && y < 310) {
                        Demo_SinhVien();
                    }
                    if (x > 0 && y > 310 && x < 270 && y < 360) {
                        Demo_HocPhan();
                    }
                    if (x > 0 && y > 360 && x < 270 && y < 410) {
                        Demo_LopHocPhan();
                    }
                    if (x > 0 && y > 410 && x < 270 && y < 460) {
                        Demo_Nhom();
                    }
                    if (x > 0 && y > 460 && x < 270 && y < 510) {
                        DoiMatKhau();
                    }
                    if (x > 0 && y > 510 && x < 270 && y < 560) {
                        Help();
                    }
                    if (x > 900 && x < 1170 && y > 190 && y < 215) {
                            Thietlapthoigian();
                    }
                    if (x > 760 && x < 860 && y > 190 && y < 215) {
                        ofstream o;
                        o.open("LichSuThayDoi.txt", ios::trunc);
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o << " " << endl;
                        o.close();
                        QuanliDkytc();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void DanhsachHP(HocPhan hp_sv_chdky) {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Dang danh lop hoc phan co the dang ky them ", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 255, 255, 255);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 15);
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    string preText = "Cac lop hoc phan cua mon " + string(hp_sv_chdky.gettenhocphan()) + " :";
    const char* preText_c = preText.c_str();
    // ve ki tu
    Text(150, 20, "He thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    SDL_Surface* image = IMG_Load("student.png");
    Tron_HopThoai(900, 20, 320, 90, screen);
    Image(900, 20, image, screen);
    Text(1000, 40, "SINH VIEN", screen, font, textColor);
    Back(screen, 20, 75);
    Text(20, 150, preText_c, screen, font_h1, textColor);
    // lớp học phần đã đăng kí
    HocPhan* hp = getfromfileHocPhan("HocPhan.txt");
    LopHocPhan* lhp = getfromfileLopHocPhan("LopHocPhan.txt");
    GiangVien* gv = getfromfileGiangVien("GiangVien.txt");
    SinhVien* dssv = getfromfileSinhVien("SinhVien.txt");
    SinhVien sv = getsv(MSSV, dssv, size_dssv);
    LopHocPhan *dslhp_dadk = sv.getfromfilelhpdadk("LopHocPhan_SinhVien.txt", lhp, size_dslhp, hp, size_dshp);
    ThoiKhoaBieu* tkb_sv = sv.getTKB_SVdadk(dslhp_dadk);
    // lop hoc phan cua hoc phan
    LopHocPhan* lhpdk_sv = getdslhpcuahp(hp_sv_chdky.getmahocphan(), lhp , tkb_sv , sv.getsohpdadk());
    HopThoai(20, 200, 1220, 30, screen);
    Text(25, 203, "TT", screen, font_h1, textColor_RED);
    DrawLine(screen, 55, 200, 55, 230, redColor);
    Text(60, 203, "Ma lop hoc phan", screen, font_h1, textColor_RED);
    DrawLine(screen, 235, 200, 235, 230, redColor);
    Text(240, 203, "Ten lop hoc phan", screen, font_h1, textColor_RED);
    DrawLine(screen, 485, 200, 485, 230, redColor);
    Text(490, 203, "T.chi", screen, font_h1, textColor_RED);
    DrawLine(screen, 530, 200, 530, 230, redColor);
    Text(535, 203, "Giang vien", screen, font_h1, textColor_RED);
    DrawLine(screen, 750, 200, 750, 230, redColor);
    Text(755, 203, "Thoi khoa bieu", screen, font_h1, textColor_RED);
    DrawLine(screen, 920, 200, 920, 230, redColor);
    Text(925, 203, "Tuan hoc", screen, font_h1, textColor_RED);
    DrawLine(screen, 1020, 200, 1020, 230, redColor);
    Text(1025, 203, "CLC", screen, font_h1, textColor_RED);
    DrawLine(screen, 1060, 200, 1060, 230, redColor);
    Text(1065, 203, "T", screen, font_h1, textColor_RED);
    DrawLine(screen, 1100, 200, 1100, 230, redColor);
    Text(1105, 203, "D.ky", screen, font_h1, textColor_RED);
    DrawLine(screen, 1160, 200, 1160, 230, redColor);

    int index = 1;
    int y_o = 230;
    int SL = getsllhpcuahp(hp_sv_chdky.getmahocphan(), lhp);
    // chua co so luong lhp (4)
    while (index <= SL) {
        ThoiKhoaBieu tkb = lhpdk_sv[index].gettkb();
        string tkb_s = TKBinchar(tkb);
        const char* tkb_c = tkb_s.c_str();
        string tuanhoc = TuanHocinchar(lhpdk_sv[index].gettuanhoc());
        const char* tuanhoc_c = tuanhoc.c_str();
        string dky = DKy(lhpdk_sv[index]);
        const char* dky_c = dky.c_str();
        // chuyển double sang char[]
        double tchi = hp_sv_chdky.gettchi();
        std::string myString = std::to_string(tchi);
        const char* a = myString.c_str();
        char myCharArray[4] = "";
        for (int i = 0; i <= 2; i++) {
            myCharArray[i] = a[i];
        }
        myCharArray[3] = '\0';
        GiangVien v = getGV("GiangVien.txt", lhpdk_sv[index].getmagv());
        DrawLine(screen, 20, y_o, 20, y_o + 30, redColor);
        Text(25, y_o + 3, std::to_string(index).c_str(), screen, font_h1, textColor);
        DrawLine(screen, 55, y_o, 55, y_o + 30, redColor);
        Text(60, y_o + 3, lhpdk_sv[index].getmalophocphan(), screen, font_h1, textColor);
        DrawLine(screen, 235, y_o, 235, y_o + 30, redColor);
        Text(240, y_o + 3, hp_sv_chdky.gettenhocphan(), screen, font_h1, textColor);
        DrawLine(screen, 485, y_o, 485, y_o + 30, redColor);
        Text(490, y_o + 3, myCharArray, screen, font_h1, textColor);
        DrawLine(screen, 530, y_o, 530, y_o + 30, redColor);
        Text(535, y_o + 3, v.gethoten(), screen, font_h1, textColor);
        DrawLine(screen, 750, y_o, 750, y_o + 30, redColor);
        Text(755, y_o + 3, tkb_c, screen, font_h1, textColor);
        DrawLine(screen, 920, y_o, 920, y_o + 30, redColor);
        Text(925, y_o + 3, tuanhoc_c, screen, font_h1, textColor);
        DrawLine(screen, 1020, y_o, 1020, y_o + 30, redColor);
        Text(1030, y_o + 3, (lhpdk_sv[index].getCLC() ? "X" : ""), screen, font_h1, textColor);
        DrawLine(screen, 1060, y_o, 1060, y_o + 30, redColor);
        Text(1070, y_o + 3, (lhpdk_sv[index].getT() ? "X" : ""), screen, font_h1, textColor);
        DrawLine(screen, 1100, y_o, 1100, y_o + 30, redColor);
        Text(1105, y_o + 3, dky_c, screen, font_h1, textColor);
        DrawLine(screen, 1160, y_o, 1160, y_o + 30, redColor);
        Text(1165, y_o + 3, "Dang ky", screen, font_h1, textColor_RED);
        DrawLine(screen, 1240, y_o, 1240, y_o + 30, redColor);
        index++;
        y_o += 30;
        DrawLine(screen, 20, y_o, 1240, y_o, redColor);
    }
    DrawLine(screen, 20, y_o, 1240, y_o, redColor);
    // cập nhật nội dung cửa sổ
    SDL_Flip(screen);
    // giải phóng dữ liệu 
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        Dangkithemtc();
                    }
                    if (x > 1160 && x < 1240 && y > 230 && y < y_o) {
                        int position = (y - 230) / 30 + 1;
                        if (lhpdk_sv[position].getT() == true) {
                            char n1[] = "Lop hoc phan vua chon thoi khoa bieu khong phu hop";
                            char n2[] = "     Vui long chon lop hoc phan khac";
                            Alert(n1, n2, "Trung thoi khoa bieu");
                        }
                        else XacNhanDkytc(lhpdk_sv, position, sv);
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void Dangkithemtc() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 255, 255, 255);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 15);
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "He thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Text(20, 150, "Cac hoc phan co the dang ki them :", screen, font_h1, textColor);
    // lớp học phần đã đăng kí
    SDL_Surface* image = IMG_Load("student.png");
    Tron_HopThoai(900, 20, 320, 90, screen);
    Image(900, 20, image, screen);
    Text(1000, 40, "SINH VIEN", screen, font, textColor);
    HocPhan* hp = getfromfileHocPhan("HocPhan.txt");
    LopHocPhan* lhp = getfromfileLopHocPhan("LopHocPhan.txt");
    GiangVien* gv = getfromfileGiangVien("GiangVien.txt");
    SinhVien* dssv = getfromfileSinhVien("SinhVien.txt");
    SinhVien sv = getsv(MSSV, dssv, size_dssv);
    LopHocPhan* lhpdk_sv = sv.getfromfilelhpdadk("LopHocPhan_SinhVien.txt", lhp, size_dslhp, hp, size_dshp);
    HocPhan* hp_sv_chdky = sv.gethp_svchuadk("HocPhan.txt", lhpdk_sv);
    HopThoai(20, 200, 580, 30, screen);
    Text(25, 203, "TT", screen, font_h1, textColor_RED);
    DrawLine(screen, 55, 200, 55, 230, redColor);
    Text(60, 203, "Ma hoc phan", screen, font_h1, textColor_RED);
    DrawLine(screen, 235, 200, 235, 230, redColor);
    Text(240, 203, "Ten hoc phan", screen, font_h1, textColor_RED);
    DrawLine(screen, 485, 200, 485, 230, redColor);
    Text(490, 203, "T.chi", screen, font_h1, textColor_RED);
    DrawLine(screen, 530, 200, 530, 230, redColor);
    int size_hpchuadki = size_dshp - sv.getsohpdadk();
    //
    int size = 0;
    int size_hp = size_hpchuadki;
    int time = 0;
cancel_gv:
    int y_o = 230;
    int index = 10 * time + 1;
    if (size_hp > 10)  size = time * 10 + 10;
    else  size = time * 10 + size_hp;
    while (index <= size && index <= size_hpchuadki) {
        double tchi = hp_sv_chdky[index].gettchi();
        std::string myString = std::to_string(tchi);
        const char* a = myString.c_str();
        char myCharArray[4] = "";
        for (int i = 0; i <= 2; i++) {
            myCharArray[i] = a[i];
        }
        myCharArray[3] = '\0';
        DrawLine(screen, 20, y_o, 20, y_o + 30, redColor);
        Text(25, y_o + 3, std::to_string(index).c_str(), screen, font_h1, textColor);
        DrawLine(screen, 55, y_o, 55, y_o + 30, redColor);
        Text(60, y_o + 3, hp_sv_chdky[index].getmahocphan(), screen, font_h1, textColor);
        DrawLine(screen, 235, y_o, 235, y_o + 30, redColor);
        Text(240, y_o + 3, hp_sv_chdky[index].gettenhocphan(), screen, font_h1, textColor);
        DrawLine(screen, 485, y_o, 485, y_o + 30, redColor);
        Text(490, y_o + 3, myCharArray, screen, font_h1, textColor);
        DrawLine(screen, 530, y_o, 530, y_o + 30, redColor);
        Text(535, y_o + 3, "Dang ky", screen, font_h1, textColor_RED);
        DrawLine(screen, 600, y_o, 600, y_o + 30, redColor);
        index++;
        y_o += 30;
        DrawLine(screen, 20, y_o, 600, y_o, redColor);
    }
    if (size_hp > 10 && time > 0) {
        Text(20, y_o + 10, "Xem them", screen, font_h1, textColor_RED);
        Text(20, y_o + 10, "Trang truoc", screen, font_h1, textColor_RED);
        SDL_Event event;
        SDL_Flip(screen);
        bool quit = false;
        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
                else if (event.type == SDL_MOUSEBUTTONDOWN) {
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        int x = event.button.x;
                        int y = event.button.y;
                        if (x > 20 && x < 100 && y > 55 && y < 95) {
                            Dangkitinchi();
                        }
                        if (x > 530 && x < 600 && y > 230 && y < y_o) {
                            int position = (y - 230) / 30 + 1 + time * 10;
                            DanhsachHP(hp_sv_chdky[position]);
                        }
                        if (x > 20 && x < 130 && y > y_o + 10 && y < y_o + 30) {
                            BG_HopThoai(0, 230, 970, 490, screen);
                            time--;
                            size_hp += 10;
                            goto cancel_gv;
                        }
                        if (x > 530 && x < 600 && y > y_o + 10 && y < y_o + 30) {
                            BG_HopThoai(0, 230, 970, 490, screen);
                            time++;
                            size_hp -= 10;
                            goto cancel_gv;
                        }
                    }
                }
            }
        }
    }
    else if (size_hp > 10 && time == 0) {
        Text(530, y_o + 10, "Xem them", screen, font_h1, textColor_RED);
        SDL_Event event;
        SDL_Flip(screen);
        bool quit = false;
        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
                else if (event.type == SDL_MOUSEBUTTONDOWN) {
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        int x = event.button.x;
                        int y = event.button.y;
                        if (x > 20 && x < 100 && y > 55 && y < 95) {
                            Dangkitinchi();
                        }
                        if (x > 530 && x < 600 && y > 230 && y < y_o) {
                            int position = (y - 230) / 30 + 1 + time * 10;
                            DanhsachHP(hp_sv_chdky[position]);
                        }
                        if (x > 530 && x < 610 && y > y_o + 10 && y < y_o + 30) {
                            BG_HopThoai(0, 230, 970, 490, screen);
                            time++;
                            size_hp -= 10;
                            goto cancel_gv;
                        }
                    }
                }
            }
        }
    }
    else if (size_hp <= 10 && time == 0) {
        SDL_Event event;
        SDL_Flip(screen);
        bool quit = false;
        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
                else if (event.type == SDL_MOUSEBUTTONDOWN) {
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        int x = event.button.x;
                        int y = event.button.y;
                        if (x > 20 && x < 100 && y > 55 && y < 95) {
                            Dangkitinchi();
                        }
                        if (x > 530 && x < 600 && y > 230 && y < y_o) {
                            int position = (y - 230) / 30 + 1 + time * 10;
                            DanhsachHP(hp_sv_chdky[position]);
                        }
                    }
                }
            }
        }
    }
    else if (size_hp <= 10 && time > 0) {
        Text(20, y_o + 10, "Trang truoc", screen, font_h1, textColor_RED);
        SDL_Event event;
        SDL_Flip(screen);
        bool quit = false;
        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
                else if (event.type == SDL_MOUSEBUTTONDOWN) {
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        int x = event.button.x;
                        int y = event.button.y;
                        if (x > 20 && x < 100 && y > 55 && y < 95) {
                            Dangkitinchi();
                        }
                        if (x > 530 && x < 600 && y > 230 && y < y_o) {
                            int position = (y - 230) / 30 + 1 + time * 10;
                            DanhsachHP(hp_sv_chdky[position]);
                        }
                        if (x > 20 && x < 130 && y > y_o + 10 && y < y_o + 30) {
                            BG_HopThoai(0, 230, 970, 490, screen);
                            time--;
                            size_hp += 10;
                            goto cancel_gv;
                        }
                    }
                }
            }
        }
    }
}
void Huytc() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 255, 255, 255);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 15);
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "He thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Text(20, 150, "Lop da chon , danh ky :", screen, font_h1, textColor);
    SDL_Surface* image = IMG_Load("student.png");
    Tron_HopThoai(900, 20, 320, 90, screen);
    Image(900, 20, image, screen);
    Text(1000, 40, "SINH VIEN", screen, font, textColor);
    // lớp học phần đã đăng kí
    HocPhan* hp = getfromfileHocPhan("HocPhan.txt");
    LopHocPhan* lhp = getfromfileLopHocPhan("LopHocPhan.txt");
    GiangVien* gv = getfromfileGiangVien("GiangVien.txt");
    SinhVien* dssv = getfromfileSinhVien("SinhVien.txt");
    SinhVien sv = getsv(MSSV, dssv, size_dssv);
    LopHocPhan* lhpdk_sv = sv.getfromfilelhpdadk("LopHocPhan_SinhVien.txt", lhp, size_dslhp, hp, size_dshp);
    HopThoai(20, 200, 580, 30, screen);
    Text(25, 203, "TT", screen, font_h1, textColor_RED);
    DrawLine(screen, 55, 200, 55, 230, redColor);
    Text(60, 203, "Ma hoc phan", screen, font_h1, textColor_RED);
    DrawLine(screen, 235, 200, 235, 230, redColor);
    Text(240, 203, "Ten hoc phan", screen, font_h1, textColor_RED);
    DrawLine(screen, 485, 200, 485, 230, redColor);
    Text(490, 203, "T.chi", screen, font_h1, textColor_RED);
    DrawLine(screen, 530, 200, 530, 230, redColor);
    int index = 1;
    int y_o = 230;
    while (index <= sv.getsohpdadk()) {
        HocPhan h = getHocPhan(lhpdk_sv[index].getmahocphan(), hp, size_dshp);
        ThoiKhoaBieu tkb = lhpdk_sv[index].gettkb();
        string tkb_s = TKBinchar(tkb);
        const char* tkb_c = tkb_s.c_str();
        string tuanhoc = TuanHocinchar(lhpdk_sv[index].gettuanhoc());
        const char* tuanhoc_c = tuanhoc.c_str();
        string dky = DKy(lhpdk_sv[index]);
        const char* dky_c = dky.c_str();
        // chuyển double sang char[]
        double tchi = h.gettchi();
        std::string myString = std::to_string(tchi);
        const char* a = myString.c_str();
        char myCharArray[4] = "";
        for (int i = 0; i <= 2; i++) {
            myCharArray[i] = a[i];
        }
        myCharArray[3] = '\0';
        GiangVien v = getGV("GiangVien.txt", lhpdk_sv[index].getmagv());
        DrawLine(screen, 20, y_o, 20, y_o + 30, redColor);
        Text(25, y_o + 3, std::to_string(index).c_str(), screen, font_h1, textColor);
        DrawLine(screen, 55, y_o, 55, y_o + 30, redColor);
        Text(60, y_o + 3, lhpdk_sv[index].getmalophocphan(), screen, font_h1, textColor);
        DrawLine(screen, 235, y_o, 235, y_o + 30, redColor);
        Text(240, y_o + 3, h.gettenhocphan(), screen, font_h1, textColor);
        DrawLine(screen, 485, y_o, 485, y_o + 30, redColor);
        Text(490, y_o + 3, myCharArray, screen, font_h1, textColor);
        DrawLine(screen, 530, y_o, 530, y_o + 30, redColor);
        Text(555, y_o + 3, "Huy", screen, font_h1, textColor_RED);
        DrawLine(screen, 600, y_o, 600, y_o + 30, redColor);
        index++;
        y_o += 30;
        DrawLine(screen, 20, y_o, 600, y_o, redColor);
    }
    // cập nhật nội dung cửa sổ
    SDL_Flip(screen);
    // giải phóng dữ liệu 
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        Dangkitinchi();
                    }
                    if (x > 530 && x < 600 && y > 230 && y < y_o) {
                        int position = (y - 230) / 30 + 1;
                        XacNhanHuytc(lhpdk_sv, position, sv);
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void Dangkitinchi() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Dang ki tin chi", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 255, 255, 255);
    Uint32 redColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 15);
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    // ve ki tu
    Text(150, 20, "He thong dang ki tin chi ", screen, font, textColor);
    Text(150, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    Back(screen, 20, 75);
    Text(20, 150, "Lop da chon , danh ky :", screen, font_h1, textColor);
    // button
    SDL_Surface* image = IMG_Load("student.png");
    Tron_HopThoai(900, 20, 320, 90, screen);
    Image(900, 20, image, screen);
    Text(1000, 40, "SINH VIEN", screen, font, textColor);
    HopThoai(950, 160, 170, 25, screen);
    Text(955, 160, "Dang ki them tin chi", screen, font_h1, textColor);
    HopThoai(800, 160, 110, 25, screen);
    Text(805, 160, "Doi mat khau", screen, font_h1, textColor);
    HopThoai(1140, 160, 100, 25, screen);
    Text(1145, 160, "Huy tin chi", screen, font_h1, textColor);
    // lớp học phần đã đăng kí
    HocPhan* hp = getfromfileHocPhan("HocPhan.txt");
    LopHocPhan* lhp = getfromfileLopHocPhan("LopHocPhan.txt");
    GiangVien* gv = getfromfileGiangVien("GiangVien.txt");
    SinhVien* dssv = getfromfileSinhVien("SinhVien.txt");
    SinhVien sv = getsv(MSSV, dssv, size_dssv);
    LopHocPhan* lhpdk_sv = sv.getfromfilelhpdadk("LopHocPhan_SinhVien.txt", lhp, size_dslhp, hp, size_dshp);
    HopThoai(20, 200, 1220, 30, screen);
    Text(25, 203, "TT", screen, font_h1, textColor_RED);
    DrawLine(screen, 55, 200, 55, 230, redColor);
    Text(60, 203, "Ma lop hoc phan", screen, font_h1, textColor_RED);
    DrawLine(screen, 235, 200, 235, 230, redColor);
    Text(240, 203, "Ten lop hoc phan", screen, font_h1, textColor_RED);
    DrawLine(screen, 485, 200, 485, 230, redColor);
    Text(490, 203, "T.chi", screen, font_h1, textColor_RED);
    DrawLine(screen, 530, 200, 530, 230, redColor);
    Text(535, 203, "Giang vien", screen, font_h1, textColor_RED);
    DrawLine(screen, 750, 200, 750, 230, redColor);
    Text(755, 203, "Thoi khoa bieu", screen, font_h1, textColor_RED);
    DrawLine(screen, 920, 200, 920, 230, redColor);
    Text(925, 203, "Tuan hoc", screen, font_h1, textColor_RED);
    DrawLine(screen, 1020, 200, 1020, 230, redColor);
    Text(1025, 203, "K", screen, font_h1, textColor_RED);
    DrawLine(screen, 1060, 200, 1060, 230, redColor);
    Text(1065, 203, "T", screen, font_h1, textColor_RED);
    DrawLine(screen, 1100, 200, 1100, 230, redColor);
    Text(1105, 203, "G", screen, font_h1, textColor_RED);
    DrawLine(screen, 1140, 200, 1140, 230, redColor);
    Text(1145, 203, "CLC", screen, font_h1, textColor_RED);
    DrawLine(screen, 1180, 200, 1180, 230, redColor);
    Text(1185, 203, "D.ky", screen, font_h1, textColor_RED);
    double tchi = sv.getsotcmax();
    string myString = to_string(tchi);
    char myCharArray[5] = "";
    for (int i = 0; i <= 3; i++) {
        if( i < myString.length())   myCharArray[i] = char(myString[i]);
    }
    myCharArray[4] = '\0';
    string tc = "Tong so tin chi toi da cho phep : " + string(myCharArray);
    const char* tc_c = tc.c_str();
    Text(450,160, tc_c, screen, font_h1, textColor_RED);
    int index = 1;
    int y_o = 230;
    if (sv.getsohpdadk() <= 0) {
        Text(325, 300, "Sinh vien chua dang ky hoc phan nao", screen, font_h1, textColor_RED);
    }
    else {
        while (index <= sv.getsohpdadk()) {
            HocPhan h = getHocPhan(lhpdk_sv[index].getmahocphan(), hp, size_dshp);
            ThoiKhoaBieu tkb = lhpdk_sv[index].gettkb();
            string tkb_s = TKBinchar(tkb);
            const char* tkb_c = tkb_s.c_str();
            string tuanhoc = TuanHocinchar(lhpdk_sv[index].gettuanhoc());
            const char* tuanhoc_c = tuanhoc.c_str();
            string dky = DKy(lhpdk_sv[index]);
            const char* dky_c = dky.c_str();
            // chuyển double sang char[]
            double tchi = h.gettchi();
            string myString = to_string(tchi);
            const char* a = myString.c_str();
            char myCharArray[4] = "";
            for (int i = 0; i <= 2; i++) {
                myCharArray[i] = a[i];
            }
            myCharArray[3] = '\0';
            GiangVien v = getGV("GiangVien.txt", lhpdk_sv[index].getmagv());
            DrawLine(screen, 20, y_o, 20, y_o + 30, redColor);
            Text(25, y_o + 3, std::to_string(index).c_str(), screen, font_h1, textColor);
            DrawLine(screen, 55, y_o, 55, y_o + 30, redColor);
            Text(60, y_o + 3, lhpdk_sv[index].getmalophocphan(), screen, font_h1, textColor);
            DrawLine(screen, 235, y_o, 235, y_o + 30, redColor);
            Text(240, y_o + 3, h.gettenhocphan(), screen, font_h1, textColor);
            DrawLine(screen, 485, y_o, 485, y_o + 30, redColor);
            Text(490, y_o + 3, myCharArray, screen, font_h1, textColor);
            DrawLine(screen, 530, y_o, 530, y_o + 30, redColor);
            Text(535, y_o + 3, v.gethoten(), screen, font_h1, textColor);
            DrawLine(screen, 750, y_o, 750, y_o + 30, redColor);
            Text(755, y_o + 3, tkb_c, screen, font_h1, textColor);
            DrawLine(screen, 920, y_o, 920, y_o + 30, redColor);
            Text(925, y_o + 3, tuanhoc_c, screen, font_h1, textColor);
            DrawLine(screen, 1020, y_o, 1020, y_o + 30, redColor);
            Text(1025, y_o + 3, (lhpdk_sv[index].getK() ? "X" : ""), screen, font_h1, textColor);
            DrawLine(screen, 1060, y_o, 1060, y_o + 30, redColor);
            Text(1065, y_o + 3, (lhpdk_sv[index].getT() ? "X" : ""), screen, font_h1, textColor);
            DrawLine(screen, 1100, y_o, 1100, y_o + 30, redColor);
            Text(1105, y_o + 3, (lhpdk_sv[index].getG() ? "X" : ""), screen, font_h1, textColor);
            DrawLine(screen, 1140, y_o, 1140, y_o + 30, redColor);
            Text(1145, y_o + 3, (lhpdk_sv[index].getCLC() ? "X" : ""), screen, font_h1, textColor);
            DrawLine(screen, 1180, y_o, 1180, y_o + 30, redColor);
            Text(1185, y_o + 3, dky_c, screen, font_h1, textColor);
            DrawLine(screen, 1240, y_o, 1240, y_o + 30, redColor);
            index++;
            y_o += 30;
        }
        DrawLine(screen, 20, y_o, 1240, y_o, redColor);
        double tchi = sv.getsotcdadk();
        string myString = to_string(tchi);
        char myCharArray[5] = "";
        for (int i = 0; i <= 3; i++) {
            if (i < myString.length())   myCharArray[i] = char(myString[i]);
        }
        myCharArray[4] = '\0';
        string tc = "Ban da dang ky cac lop hoc phan trong bang tren . Tong so tin chi la : " + string(myCharArray);
        const char* tc_ch = tc.c_str();
        Text(20, y_o + 5, tc_ch, screen, font_h1, textColor);
    }
    // cập nhật nội dung cửa sổ
    SDL_Flip(screen);
    // giải phóng dữ liệu 
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 20 && x < 100 && y > 55 && y < 95) {
                        DangNhapSV();
                    }
                    if (x > 950 && x < 1120 && y > 160 && y < 185) {
                        Dangkithemtc();
                    }
                    if (x > 1140 && x < 1240 && y > 160 && y < 185) {
                        Huytc();
                    }
                    if (x > 800 && y > 160 && x < 910 && y < 185) {
                        DoiMatKhauSV();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void DangNhapSV() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Dang nhap voi tu cach sinh vien", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 255, 255, 255);
    Uint32 borderColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    Back(screen, 20, 45);
    // tạo nền trắng 
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_er = TTF_OpenFont("Nguyen.ttf", 20);
    TTF_Font* font_h0 = TTF_OpenFont("Nguyen.ttf", 50);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 50);
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    Text(200, 20, "He thong dang ki tin chi - BKDN", screen, font_h1, textColor);
    HopThoai(200, 170, 680, 390, screen);
    DrawLine(screen, 200, 235, 880, 235, borderColor);
    HopThoai(460, 270, 400, 50, screen);
    HopThoai(460, 350, 400, 50, screen);
    HopThoai(460, 470, 400, 50, screen);
    Text(230, 270, "MSSV : ", screen, font, textColor);
    Text(230, 350, "Mat khau : ", screen, font, textColor);
    Text(460, 400, "Quen mat khau ? ", screen, font, textColor);
    Text(550, 470, "Dang Nhap ", screen, font, textColor_RED);
    Text(100, 580, "Luu y : MSSV chi gom so 0 den 9 , mat khau chi gom chu so 0 - 9 , a - z , MSSV toi da 10 ki tu , mat khau toi da 15 ki tu", screen, font_er, textColor_RED);
    Text(250, 170, "Sinh Vien Dang Nhap", screen, font_h0, textColor);
    // cập nhật nội dung cửa sổ
    SDL_Flip(screen);
    // giải phóng dữ liệu 
    bool quit = false;
    SDL_Event event;
    strcpy(MSSV, "");
    char mk[20] = "";
    char hide_mk[20] = "";
    char hide = '*';
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 460 && y > 270 && x < 860 && y < 320) {
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(MSSV);
                                        if (length > 0) {
                                            MSSV[length - 1] = '\0';
                                        }
                                        HopThoai(460, 270, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if (keyPressed >= 48 && keyPressed <= 57) strncat(MSSV, &keyPressed, 1);
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(MSSV);
                                            if (length > 0) {
                                                MSSV[length - 1] = '\0';
                                            }
                                            HopThoai(460, 270, 400, 50, screen); // set lại hộp thoại
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 470;
                                textRect.y = 270;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font, MSSV, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 460 && y > 350 && x < 860 && y < 400) {
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(mk);
                                        if (length > 0) {
                                            mk[length - 1] = '\0';
                                            hide_mk[length - 1] = '\0';
                                        }
                                        HopThoai(460, 350, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                            strncat(mk, &keyPressed, 1);
                                            strncat(hide_mk, &hide, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(mk);
                                            if (length > 0) {
                                                mk[length - 1] = '\0';
                                                hide_mk[length - 1] = '\0';
                                            }
                                            HopThoai(460, 350, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 470;
                                textRect.y = 350;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font, hide_mk, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 20 && x < 100 && y > 25 && y < 65) {
                        TrangChu();
                    }
                    if (x > 460 && y > 400 && x < 760 && y < 460) {
                        char title[] = "Lien he voi nha truong de lay lai mat khau";
                        char alert[] = "";
                        Alert(title, alert, "Quen mat khau");
                    }
                    if (x > 460 && y > 470 && x < 860 && y < 520) {
                        int key = 0;
                        User* u = new User[1000];
                        u = getfromfileUsers("Users.txt");
                        for (int i = 0; i < size_user; i++) {
                            if (strcmp(MSSV, u[i].getMSSV()) == 0) {
                                if (strcmp(mk, u[i].getmk()) == 0) {
                                    key = 1;
                                    Dangkitinchi();
                                }
                            }
                        }
                        if (key == 0) {
                            char title[] = "Sai MSSV hoac mat khau !";
                            char alert[] = "";
                            Alert(title, alert, "Sai thong tin dang nhap");
                        }
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void DangNhapAdmin() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Dang nhap voi tu cach Admin", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 255, 255, 255);
    Uint32 borderColor = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, whiteColor);
    Back(screen, 20, 45);
    // tạo nền trắng 
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_er = TTF_OpenFont("Nguyen.ttf", 20);
    TTF_Font* font_h0 = TTF_OpenFont("Nguyen.ttf", 50);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 50);
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    Text(200, 20, "Quan li he thong dang ki tin chi - BKDN", screen, font_h1, textColor);
    HopThoai(200, 170, 680, 390, screen);
    DrawLine(screen, 200, 235, 880, 235, borderColor);
    HopThoai(460, 270, 400, 50, screen);
    HopThoai(460, 350, 400, 50, screen);
    HopThoai(460, 470, 400, 50, screen);
    Text(230, 270, "ID : ", screen, font, textColor);
    Text(230, 350, "Mat khau : ", screen, font, textColor);
    Text(460, 400, "Quen mat khau ? ", screen, font, textColor);
    Text(550, 470, "Dang Nhap ", screen, font, textColor_RED);
    Text(100, 580, "Luu y : ID chi gom so 0 den 9 , mat khau chi gom chu so 0 - 9 , a - z , ID toi da 10 ki tu , mat khau toi da 15 ki tu", screen, font_er, textColor_RED);
    Text(280, 170, "Admin Dang Nhap", screen, font_h0, textColor);
    // cập nhật nội dung cửa sổ
    SDL_Flip(screen);
    // giải phóng dữ liệu 
    bool quit = false;
    SDL_Event event;
    strcpy(IDAdmin, "");
    char mk[20] = "";
    char hide_mk[20] = "";
    char hide = '*';
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    std::cout << x << " " << y << endl;
                    if (x > 460 && y > 270 && x < 860 && y < 320) {
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(IDAdmin);
                                        if (length > 0) {
                                            IDAdmin[length - 1] = '\0';
                                        }
                                        HopThoai(460, 270, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if (keyPressed >= 48 && keyPressed <= 57) strncat(IDAdmin, &keyPressed, 1);
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(IDAdmin);
                                            if (length > 0) {
                                                IDAdmin[length - 1] = '\0';
                                            }
                                            HopThoai(460, 270, 400, 50, screen); // set lại hộp thoại
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 470;
                                textRect.y = 270;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font, IDAdmin, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 460 && y > 350 && x < 860 && y < 400) {
                        while (!quit) {
                            int br = 0;
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        quit = true;
                                    }
                                    else if (event.key.keysym.sym == SDLK_RETURN) {
                                        br = 1;
                                    }
                                    else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                        int length = strlen(mk);
                                        if (length > 0) {
                                            mk[length - 1] = '\0';
                                            hide_mk[length - 1] = '\0';
                                        }
                                        HopThoai(460, 350, 400, 50, screen); // set lại hộp thoại
                                    }
                                    else if (event.key.keysym.sym != SDLK_RSHIFT && event.key.keysym.sym != SDLK_LSHIFT && event.key.keysym.sym != SDLK_CAPSLOCK && event.key.keysym.sym != SDLK_LCTRL && event.key.keysym.sym != SDLK_RCTRL && event.key.keysym.sym != SDLK_LALT && event.key.keysym.sym != SDLK_RALT && event.key.keysym.sym != SDLK_UP && event.key.keysym.sym != SDLK_DOWN && event.key.keysym.sym != SDLK_LEFT && event.key.keysym.sym != SDLK_RIGHT) {
                                        char keyPressed = (char)event.key.keysym.sym;
                                        if ((keyPressed >= '0' && keyPressed <= '9') || (keyPressed >= 'a' && keyPressed <= 'z')) {
                                            strncat(mk, &keyPressed, 1);
                                            strncat(hide_mk, &hide, 1);
                                        }
                                        if (event.key.keysym.sym == SDLK_BACKSPACE) {
                                            int length = strlen(mk);
                                            if (length > 0) {
                                                mk[length - 1] = '\0';
                                                hide_mk[length - 1] = '\0';
                                            }
                                            HopThoai(460, 350, 400, 50, screen);
                                        }
                                    }
                                }
                            }
                            if (font != NULL) {
                                SDL_Rect textRect;
                                textRect.x = 470;
                                textRect.y = 350;
                                SDL_Surface* textSurface = TTF_RenderText_Solid(font, hide_mk, textColor);
                                SDL_BlitSurface(textSurface, NULL, screen, &textRect);
                            }
                            SDL_Flip(screen); // Cập nhật cửa sổ
                            if (br == 1) break;
                        }
                    }
                    if (x > 20 && x < 100 && y > 25 && y < 65) {
                        TrangChu();
                    }
                    if (x > 460 && y > 400 && x < 760 && y < 460) {
                        char title[] = "Lien he voi nha truong de lay lai mat khau";
                        char alert[] = "";
                        Alert(title, alert, "Quen mat khau");
                    }
                    if (x > 460 && y > 470 && x < 860 && y < 520) {
                        int key = 0;
                        Admin* u = new Admin[1000];
                        u = getfromfileAdmin("Admin.txt");
                        for (int i = 0; i < size_admin; i++) {
                            if (strcmp(IDAdmin, u[i].getIdAdmin()) == 0) {
                                if (strcmp(mk, u[i].getmk()) == 0) {
                                    key = 1;
                                    std::cout << "Dang nhap thanh cong" << endl;
                                    QuanliDkytc();
                                }
                            }
                        }
                        if (key == 0) {
                            char title[] = "Sai ID hoac mat khau !";
                            char alert[] = "";
                            Alert(title, alert, "Sai thong tin dang nhap");
                        }
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
void TrangChu() {
    SDL_Surface* screen = SDL_SetVideoMode(1260, 660, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Không thể tạo cửa sổ: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_WM_SetCaption("Trang Chu", NULL);
    // khởi tạo màn hình
    Uint32 whiteColor = SDL_MapRGB(screen->format, 255, 255, 255);
    SDL_FillRect(screen, NULL, whiteColor);
    // tạo nền trắng 
    TTF_Font* font = TTF_OpenFont("Nguyen.ttf", 40);
    TTF_Font* font_h1 = TTF_OpenFont("Mali-Light.ttf", 30);
    SDL_Surface* image = IMG_Load("image002.jpg");
    if (font == NULL || font_h1 == NULL) {
        fprintf(stderr, "Không thể mở font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
    SDL_Color textColor = { 0,0,0 }; // đen
    SDL_Color textColor_RED = { 255 , 0 , 0 }; // đỏ
    SDL_Color textColor_w = { 0,0,255 }; // white
    // nap hinh anh
    Image(50, 150, image, screen);
    // ve hop thoai
    HopThoai(600, 250, 600, 70, screen);
    HopThoai(600, 350, 600, 70, screen);
    Text(630, 260, "Dang nhap voi tu cach Admin ", screen, font_h1, textColor);
    Text(610, 360, "Dang nhap voi tu cach Sinh Vien ", screen, font_h1, textColor);
    // ve ki tu
    Text(50, 25, "He thong dang ki tin chi ", screen, font, textColor);
    Text(50, 80, "Dai hoc Bach Khoa - Dai hoc Da Nang ", screen, font, textColor);
    // cập nhật nội dung cửa sổ
    SDL_Flip(screen);
    // giải phóng dữ liệu 
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    if (x > 600 && y > 250 && x < 1200 && y < 320) {
                        DangNhapAdmin();
                    }
                    if (x > 600 && y > 350 && x < 1200 && y < 420) {
                        DangNhapSV();
                    }
                }
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Không thể khởi tạo SDL: %s\n", SDL_GetError());
        return 1;
    }
    if (TTF_Init() < 0) {
        fprintf(stderr, "Không thể khởi tạo SDL_ttf: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Không thể khởi tạo SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }
    // kiểm ra thư viện
    Demo_LopHocPhan();
    return 0;
}