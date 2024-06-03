#include <bits/stdc++.h>
using namespace std;

struct SinhVien{
    string ten;
    string lop;
    double gpa;
};

void nhapThongtin (SinhVien &x) {
    
    cout << "Nhập tên sinh viên: ";
    
    getline (cin,x.ten);
    cout << "Nhập lớp sinh viên :";
    getline (cin,x.lop);
    cout << "Nhap gpa: " ;
    cin >> x.gpa;
    cin.ignore();
    
}
void hienThithongtin ( const SinhVien &x) {
    cout << "Tên: "<<x.ten<<endl;
    cout << "Lớp: "<< x.lop <<endl;
    cout <<" Gpa: "<< x.gpa <<endl;
}