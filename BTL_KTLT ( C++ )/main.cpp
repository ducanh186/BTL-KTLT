#include <iostream>
#include <string>

using namespace std;

// Struct cho thông tin học sinh
struct HocSinh {
    string MaHS;         // Mã học sinh (ví dụ: HS001)
    string TenHocSinh;   // Tên đầy đủ của học sinh
    string NgaySinh;     // Ngày sinh (ví dụ: 2008-05-15)
    string GioiTinh;     // Giới tính (Nam/Nữ)
    string DiaChi;       // Địa chỉ
};

// Struct cho điểm số của học sinh
struct Diem {
    string MaDiem;       // Mã điểm (ví dụ: D001)
    string MaHocKy;      // Mã học kỳ (ví dụ: HK1)
    float DiemMieng;     // Điểm miệng
    float Diem15p;       // Điểm 15 phút
    float Diem1Tiet;     // Điểm 1 tiết
    float DiemHS2;       // Điểm hệ số 2
    float DiemHS3;       // Điểm hệ số 3
    float DiemTBMon;     // Điểm trung bình môn
    float DiemTBNam;     // Điểm trung bình năm
};

// Struct cho thông tin môn học
struct MonHoc {
    string MaMon;        // Mã môn học (ví dụ: MH01)
    string TenMon;       // Tên môn học (ví dụ: Toán)
};

// Struct cho thông tin lớp học
struct Lop {
    string MaLop;        // Mã lớp (ví dụ: L10A1)
    string TenLop;       // Tên lớp (ví dụ: 10A1)
};

// Struct cho thông tin giáo viên
struct GiaoVien {
    string MaGV;         // Mã giáo viên (ví dụ: GV01)
    string HoTenGV;      // Họ và tên giáo viên
    string Email;        // Địa chỉ email
    string NgaySinh;     // Ngày sinh
    string GioiTinh;     // Giới tính
    string SDT;          // Số điện thoại
};
int main(){
    std::cout<<"helo";
}