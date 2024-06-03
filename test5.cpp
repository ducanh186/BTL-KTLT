#include "test5.h"



int main () {
    int n;
    cout <<"Nhập số sinh viên: ";
    cin >> n;
    cin.ignore();
    vector <SinhVien> v(n);
    for (int i=0;i<n;i++){
        cout << "Nhập thông tin sinh viên thứ "<< i+1 << endl;
        nhapThongtin(v[i]);
    }
    for (int i=0;i<n;i++) {
        hienThithongtin(v[i]);
    }
    
    return 0;

}
