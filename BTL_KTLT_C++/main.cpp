#include <iostream>
using namespace std;
enum status
	{
		nam_nhat=1,nam_hai,nam_ba,nam_bon,nam_nam,nam_sau,nam_bay
	};
struct Date
	{
		int ngay;
		int thang;
		int nam;
	};
struct sinh_vien
	{
	long mssv;
	char ho_va_ten[100];
	float GPA;
	Date ngay_sinh;
	status trangThai;
	};
int main(){
	// a)Khai báo một sinh viên với dữ liệu gán sẵn
	struct sinh_vien sv1={20224403,"Le Duc Anh",3.15,{18,6,2004},nam_hai};
	//in du lieu sv1 ra man hinh(de e do nham:))
	cout << "Thong tin sinh vien sv1:" << endl;
	cout << "MSSV: " << sv1.mssv << endl;
	cout << "Ho ten: " << sv1.ho_va_ten << endl;
	cout << "Ngay sinh: " << sv1.ngay_sinh.ngay << "/" << sv1.ngay_sinh.thang << "/" << sv1.ngay_sinh.nam << endl;
	cout << "Diem GPA: " << sv1.GPA << endl;
	cout << "Trang thai: ";
	switch (sv1.trangThai) 
	{
  			case nam_nhat:
    			cout << "Nam nhat";
    			break;
  			case nam_hai:
			   	cout << "Nam 2";
			    break;
		  	case nam_ba:
			    cout << "Nam 3";
			    break;
		  	case nam_bon:
			    cout << "Nam 4";
			    break;
		    case nam_nam:
			    cout << "Nam 5";
			    break;
		    case nam_sau:
			    cout << "Nam 6";
			    break;
		    case nam_bay:
			    cout << "Nam 7";
			    break;
	}
	cout <<"\n"<<endl;

	//b)Khai báo một sinh viên, dữ liệu nhập từ bàn phím.
	struct sinh_vien sv2;
	cout<<"Nhap thong tin cua sv2: "<<endl;
	cout << "MSSV: " ;
	cin>>sv2.mssv;
	cout << "Ho ten: ";
	cin.ignore();
	gets(sv2.ho_va_ten);	
	cout << "Diem GPA: ";
	cin>>sv2.GPA;
	cout << "Ngay sinh:(dd/mm/yyyy):";
	cin>>sv2.ngay_sinh.ngay>>sv2.ngay_sinh.thang>>sv2.ngay_sinh.nam;
	cout<<"Trang thai(sv nam nhat nhap 1,nam 2 nhap 2,....):";
	int nam_thu;
	cin>>nam_thu;//nam nhat-1, nam hai-2,...
	sv2.trangThai=status(nam_thu);		
	//c)Khai báo một mảng gồm N sinh viên, N nhập từ bàn phím.
	int n;
	cout<<"\nNhap n:";
	cin>>n;
	sinh_vien sv[n];
	//d)Nhập dữ liệu cho mảng sv[n]
	for(int i=0;i<n;i++)
		{
		//nhap du lieu cua sinh vien thu i+1
		cout << "Nhap thong tin sinh vien sv thu "<<i+1<<":\n";
		cout << "MSSV: " ;
		cin>>sv[i].mssv;
		cout << "Ho ten: ";
		cin.ignore();
		gets(sv[i].ho_va_ten);
		cout << "Diem GPA: ";
		cin>>sv[i].GPA;
		cout << "Ngay sinh:(dd/mm/yyyy):";
		cin>>sv[i].ngay_sinh.ngay>>sv[i].ngay_sinh.thang>>sv[i].ngay_sinh.nam;
		cout<<"Trang thai(sv nam nhat nhap 1,nam 2 nhap 2,....):";
		int nam_thu;
		cin>>nam_thu;//nam nhat-1, nam hai-2,...
		sv[i].trangThai=status(nam_thu);
		}
	//e)Xuat du lieu n sinh vien ra man hinh
	cout<<"Danh sach sinh vien:"<<endl;
	//xuat ra tung sv mot
	for(int i=0;i<n;i++)
	{
	cout << "\nThong tin sinh vien sv thu "<<i+1<<":\n" << endl;
	cout << "MSSV: " << sv[i].mssv << endl;
	cout << "Ho ten: " << sv[i].ho_va_ten << endl;
	cout << "Ngay sinh: " << sv[i].ngay_sinh.ngay << "/" << sv[i].ngay_sinh.thang << "/" << sv[i].ngay_sinh.nam << endl;
	cout << "Diem GPA: " << sv[i].GPA << endl;
	cout << "Trang thai: ";
	switch (sv[i].trangThai) 
	{
  			case nam_nhat:
    			cout << "Nam nhat";
    			break;
  			case nam_hai:
			   	cout << "Nam 2";
			    break;
		  	case nam_ba:
			    cout << "Nam 3";
			    break;
		  	case nam_bon:
			    cout << "Nam 4";
			    break;
		    case nam_nam:
			    cout << "Nam 5";
			    break;
		    case nam_sau:
			    cout << "Nam 6";
			    break;
		    case nam_bay:
			    cout << "Nam 7";
			    break;
	}
	cout <<"\n"<<endl;		
	}
	//f)Hiển thị điểm GPA trung bình của tất cả SV ra màn hình.
	float tongGPA=0.0;
	for(int i=0;i<n;i++){
		tongGPA+=sv[i].GPA;
	}
	float diemGPA_TB=tongGPA/n;
	cout<<"Diem GPA trung binh cua tat ca sinh vien la: "<<diemGPA_TB<<endl;
}