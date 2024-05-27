#include <iostream>
#include <vector>
#include <string>

// ... (Định nghĩa cấu trúc dữ liệu Học sinh, Môn học)
struct NgaySinh{
    int date;
    int month;
    int year;
};
struct HocSinh{
    char ID[15];
    char hoten[100];
    struct NgaySinh ngaysinh;
    char lop [10]
};
struct Diem{
    char ID[];
    int mamon;
    float diemDGTX; //x1 theo hệ số
    float diemKTGK; //x2 theo hệ số
    float diemKTCK; //x3 theo hệ số
    float diemTB;
}
struct Monhoc{
    int mamon;
    char tenmon[30];
    char hocKy;
};
void MenuChucNang() {
    printf("Hệ thống quản lý học sinh:\n");
    printf("0. Thoát chương trình\n");
    printf("1. Quản lý học sinh\n");
    printf("2. Quản lý môn học\n");
    printf("3. Quản lý điểm\n");
}
void MenuQLHS(){
    printf("Quản lý học sinh:\n");
    printf("0. Thoát chương trình\n");
    printf("1. Hiển thị danh sách học sinh\n");
    printf("2. Thêm học sinh\n");
    printf("3. Xoá học sinh\n");
    printf("4. Sắp xếp học sinh theo tên\n");
    printf("5. Hiển thị  học sinh theo lớp\n");
    printf("6. Tìm kiếm học sinh theo tên\n");
}
void HienThiDanhSachHS(struct HocSinh ArrHocSinh[], int SoLuongHocSinh){
    printf("STT học sinh\t Họ tên\t Ngày sinh\t Lớp\n");
    for (int i=0; i<SoLuongHocSinh; i++){
        printf("%s \t %s \t %d/%d/%d \t %s \n", ArrHocSinh[i].ID, ArrHocSinh[i].hoten, ArrHocSinh[i].ngaysinh.date, ArrHocSinh[i].ngaysinh.month, ArrHocSinh[i].ngaysinh.year, ArrHocSinh[i].lop);
    }
}
void HienThiDanhSachHSTheoLop(struct HocSinh ArrHocSinh[], int SoLuongHocSinh, char lop[30]){
    printf("STT học sinh\t Họ tên\t Ngày sinh\t Lớp\n");
    for (int i=0; i<SoLuongHocSinh; i++){
        if( strcmp(lop, ArrHocSinh[i].lop)==0){
        printf("%s \t %s \t %d/%d/%d \t %s \n", ArrHocSinh[i].ID, ArrHocSinh[i].hoten, ArrHocSinh[i].ngaysinh.date, ArrHocSinh[i].ngaysinh.month, ArrHocSinh[i].ngaysinh.year, ArrHocSinh[i].lop);
    }
    }
}
void NhapHS( struct HocSinh ArrHocSinh[], int SoLuongHocSinh){
    printf("Nhập thông tin cho học sinh thứ %d\n", SoLuongHocSinh +1 );
    printf("Nhập vào ID học sinh: "); scanf("%d", ArrHocSinh[SoLuongHocSinh].ID);
    printf("Nhập vào ")
}
int main() {
    int chon = 0;
    struct HocSinh ArrHocSinh[1000];
    int SoLuongHocSinh;
    do{
        MenuChucNang();
        printf("Nhập vào lựa chọn của bạn: ")
        scanf("%d", &chon);
        switch (chon)
        {
        case 0:{
            printf("Thoát") // nhập 0 --> thoát
            break;
        }
        case 1:{    //học sinh
            int chonQLHS;
            do{
                MenuQLHS();
                printf("Nhập vào lựa chọn của bạn: ")
                scanf("%d", &chonQLHS);
                switch (chonQLHS)
                {
                case 0:{
                    printf("Thoát") // nhập 0 --> thoát ra qlht
                    break;
                }
                case 1:{
                    HienThiDanhSachHS(ArrHocSinh, SoLuongHocSinh)
                    break;
                }
                case 2:{    //Nhập sinh viên
                    break;
                }
                case 3:{
                    break;
                }
                case 4:{
                    break;
                }
                case 5:{    // Hiển thị sinh viên theo lớp
                    char lop[30];
                    printf("Chọn lớp: ")
                    gets(lop);
                    HienThiDanhSachHSTheoLop(ArrHocSinh, SoLuongHocSinh, lop);
                    break;
                }
                case 6:{
                    break;
                }
                default:{
                    break;
                }
                }
            } while (chonQLHS !=0);
            break;
        }
        case 2:{    // môn
            break;
        }
        case 3:{    // điểm
            break;
        }
        default:{
            printf("Nhập sai\n") // nhập sai --> nhập lại
        }
        }
    } while (chon !=0);
    return 0;
}
