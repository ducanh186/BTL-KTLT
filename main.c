#include <stdio.h>
#include <string.h>
struct NgaySinh{
    int date;
    int month;
    int year;
};
struct HocSinh{
    int ID;
    char hoten[100];
    struct NgaySinh ngaysinh;
    char lop [10];
};
struct Diem{
    int ID;
    int mamon;
    float diemTBDGTX; //x1 theo hệ số
    float diemKTGK; //x2 theo hệ số
    float diemKTCK; //x3 theo hệ số
};
struct Monhoc{
    int mamon;
    char tenmon[30];
    int hocki;
};

void MenuChucNang() {
    printf("He thong quan ly hoc sinh: \n");
    printf("0. Thoat chuong trinh\n");
    printf("1. Quan ly hoc sinh\n");
    printf("2. Quan ly mon hoc\n");
    printf("3. Quan ly diem\n");
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
        printf("%d\t %s\t %d / %d / %d\t %s\n", ArrHocSinh[i].ID, ArrHocSinh[i].hoten, ArrHocSinh[i].ngaysinh.date, ArrHocSinh[i].ngaysinh.month, ArrHocSinh[i].ngaysinh.year, ArrHocSinh[i].lop);
    }
}
void HienThiDanhSachHSTheoLop(struct HocSinh ArrHocSinh[], int SoLuongHocSinh, char lop[30]){
    printf("STT học sinh\t Họ tên\t Ngày sinh\t Lớp\n");
    for (int i=0; i<SoLuongHocSinh; i++){
        if( strcmp(lop, ArrHocSinh[i].lop)==0){
        printf("%d \t %s \t %d/%d/%d \t %s \n", ArrHocSinh[i].ID, ArrHocSinh[i].hoten, ArrHocSinh[i].ngaysinh.date, ArrHocSinh[i].ngaysinh.month, ArrHocSinh[i].ngaysinh.year, ArrHocSinh[i].lop);
    }
    }
}
void NhapHS( struct HocSinh ArrHocSinh[], int SoLuongHocSinh){
    printf("Nhập thông tin cho học sinh thứ %d\n", SoLuongHocSinh +1 );
    printf("Nhập vào ID học sinh: "); scanf("%d", &ArrHocSinh[SoLuongHocSinh].ID);
    printf("Nhập vào họ và tên học sinh "); fflush(stdin); fflush(stdin); fgets(ArrHocSinh[SoLuongHocSinh].hoten,100,stdin);
    printf("Nhập vào ngày/tháng/năm sinh: ");
    scanf("%d", &ArrHocSinh[SoLuongHocSinh].ngaysinh.date);
    scanf("%d", &ArrHocSinh[SoLuongHocSinh].ngaysinh.month);
    scanf("%d", &ArrHocSinh[SoLuongHocSinh].ngaysinh.year);
    printf("Nhập lớp học sinh: ");
    fflush(stdin);
    fgets(ArrHocSinh[SoLuongHocSinh].lop,10,stdin);
    SoLuongHocSinh++;
}
void XoaHS(struct HocSinh ArrHocSinh[], int SoLuongHocSinh, int ma){
    
    for(int i=0; i< SoLuongHocSinh; i++){
        if(ArrHocSinh[i].ID == ma){
            for(int j=i+1; j< SoLuongHocSinh; j++){
                ArrHocSinh[j]=ArrHocSinh[j+1];
            }
            SoLuongHocSinh-- ;
            break;
        }
    }
}
void SapXepHocSinhTheoTen(struct HocSinh ArrHocSinh[], int SoLuongHocSinh){

    for(int i=0; i<SoLuongHocSinh-1; i++){
        for(int j=i+1; j<SoLuongHocSinh; j++){
            if(strcmp(ArrHocSinh[i].hoten, ArrHocSinh[j].hoten) > 0){
                struct HocSinh temp = ArrHocSinh[i];
                ArrHocSinh[i] = ArrHocSinh[j];
                ArrHocSinh[j] = temp;
            }
        }
    }
}
void TimKiemHocSinhTheoTen(struct HocSinh ArrHocSinh[], int SoLuongHocSinh, char hoten[30]){
    int check = 0;
    for(int i=0; i<SoLuongHocSinh; i++){
        if(strcmp(ArrHocSinh[i].hoten, hoten) == 0){
            printf("Tên: %s\n", hoten);
            printf("ID: %d\n", ArrHocSinh[i].ID);
            printf("Ngày sinh: %d/%d/%d\n", ArrHocSinh[i].ngaysinh.date, ArrHocSinh[i].ngaysinh.month, ArrHocSinh[i].ngaysinh.year);
            printf("Lop: %s\n", ArrHocSinh[i].lop);
            check++ ;
        }
    }
    if(check == 0){
        printf("Khong tim thay hoc sinh co ten %s\n", hoten);
    }
}

void MenuQLMH(){
    printf("Quan ly mon hoc:\n");
    printf("0. Thoat chuong trinh\n");
    printf("1. Hien thi danh sach mon hoc\n");
    printf("2. Them mon hoc\n");
    printf("3. Xoa mon hoc\n");
    printf("4. Sua thong tin mon hoc\n");
}

void MenuQLD(){
    printf("Quan ly diem:\n");
    printf("0. Thoat chuong trinh\n");
    printf("1. Hien thi danh sach diem\n");
    printf("2. Dieu chinh diem\n");
    printf("3. Xoa diem\n");
    printf("4. Hien thi diem cua hoc sinh\n");
    printf("5. Hien thi diem theo mon hoc\n");
}
void HienThiDanhSachDiem(struct HocSinh ArrHocSinh[], int SoLuongHocSinh, struct Diem ArrDiem[]){
    printf("STT\t Ho va ten\t DTBDGTX\t DKTGK\t DKTCK\t DTB\n");
    for(int i=0; i<SoLuongHocSinh; i++){
        printf("%d\t %s\t %f\t %f\t %f\t %f\n", ArrHocSinh[i].ID,ArrHocSinh[i].hoten, ArrDiem[i].diemTBDGTX, ArrDiem[i].diemKTGK, ArrDiem[i].diemKTCK, (ArrDiem[i].diemTBDGTX+2*ArrDiem[i].diemKTGK+3*ArrDiem[i].diemKTCK)/6);
    }
}
void DieuChinhDiem(struct HocSinh ArrHocSinh[], int SoLuongHocSinh, struct Diem ArrDiem[], char hoten[30]){
    int check = 0;
    int j=0;
    for( int i=0; i<SoLuongHocSinh; i++){
        if(strcmp(ArrHocSinh[i].hoten, hoten) == 0){
            check++ ;
            j=i;
            break;
        }
    }
    if(check == 0){
        printf("Khong tim thay hoc sinh co ten %s\n", hoten);
    }
    else{
        int type;
        do{
        printf("Nhap diem: \n");
        printf("0. Quay lai\n");
        printf("1. Trung binh diem danh gia thuong xuyen\n");
        printf("2. Diem giua ki\n");
        printf("3. Diem cuoi ki\n");
        scanf("%d", &type);
        switch(type){
            case 0:{
                printf("Thoat"); // nhập 0 --> thoát
                break;
        }
            case 1:{
                printf("Trung binh diem danh gia thuong xuyen");
                scanf("%f", &ArrDiem[j].diemTBDGTX);
                break;
            }
            case 2:{
                printf("Diem giua ki");
                scanf("%f", &ArrDiem[j].diemKTGK);
                break;
            }
            case 3:{
                printf("Diem cuoi ki");
                scanf("%f", &ArrDiem[j].diemKTCK);
                break;
            }
            default:{
                printf("Lua chon sai, vui long nhap lai");
                break;
            }
        }
} while (type != 0);
}
}
void XoaDiem(struct HocSinh ArrHocSinh[], int SoLuongHocSinh, struct Diem ArrDiem[], char hoten[30]){
    int check = 0;
    int j=0;
    for( int i=0; i<SoLuongHocSinh; i++){
        if(strcmp(ArrHocSinh[i].hoten, hoten) == 0){
            check++ ;
            j=i;
            break;
        }
    }
    if(check == 0){
        printf("Khong tim thay hoc sinh co ten %s\n", hoten);
    }
    else{
        int type;
        do{
        printf("Xoa diem: \n");
        printf("0. Quay lai\n");
        printf("1. Trung binh diem danh gia thuong xuyen\n");
        printf("2. Diem giua ki\n");
        printf("3. Diem cuoi ki\n");
        scanf("%d", &type);
        switch(type){
            case 0:{
                printf("Thoat"); // nhập 0 --> thoát
                break;
        }
            case 1:{
                printf("Trung binh diem danh gia thuong xuyen:\n");
                printf("%f --> 0", ArrDiem[j].diemTBDGTX);
                ArrDiem[j].diemTBDGTX = 0;
                break;
            }
            case 2:{
                printf("Diem kiem tra giua ki:\n");
                printf("%f --> 0", ArrDiem[j].diemKTGK);
                ArrDiem[j].diemKTGK = 0;
                break;
            }
            case 3:{
                printf("Diem kiem tra cuoi ki:\n");
                printf("%f --> 0", ArrDiem[j].diemKTCK);
                ArrDiem[j].diemKTCK = 0;
                break;
            }
            default:{
                printf("Lua chon sai, vui long nhap lai");
                break;
            }
        }
} while (type != 0);
}
}
void HienThiDiemHocSinh(struct HocSinh ArrHocSinh[], int SoLuongHocSinh, struct Diem ArrDiem[], char hoten[30]){
    int check = 0;
    int j=0;
    for( int i=0; i<SoLuongHocSinh; i++){
        if(strcmp(ArrHocSinh[i].hoten, hoten) == 0){
            check++ ;
            j=i;
            break;
        }
    }
    if(check == 0){
        printf("Khong tim thay hoc sinh co ten %s\n", hoten);
    }
    else{
    printf("STT\t Ho va ten\t DTBDGTX\t DKTGK\t DKTCK\t DTB\n");

    printf("%d\t %s\t %f\t %f\t %f\t %f\n", ArrHocSinh[j].ID,ArrHocSinh[j].hoten, ArrDiem[j].diemTBDGTX, ArrDiem[j].diemKTGK, ArrDiem[j].diemKTCK, (ArrDiem[j].diemTBDGTX+2*ArrDiem[j].diemKTGK+3*ArrDiem[j].diemKTCK)/6);
    }
}



int main() {
    int chon = 0;
    struct HocSinh ArrHocSinh[1000];
    struct Monhoc ArrMonHoc[1000];
    struct Diem ArrDiem[1000];
    int SoLuongHocSinh=1;
    int SoLuongMonHoc=1;
    int SoLuongHocKi=1;
    do{
        MenuChucNang();                 
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 0:{    //  thoát
            printf("Ket thuc chuong trinh"); 
            break;
        }
        case 1:{    //  học sinh
            int chonQLHS;
            printf("Đang ở quản lý học sinh");
            do{
                MenuQLHS();
                printf("Nhập vào lựa chọn của bạn: ");
                scanf("%d", &chonQLHS);
                switch (chonQLHS)
                {
                case 0:{    //Thoát
                    printf("Thoát"); // nhập 0 --> thoát ra qlht
                    break;
                }
                case 1:{    //Hiển thị sinh viên
                    HienThiDanhSachHS(ArrHocSinh, SoLuongHocSinh);
                    break;
                }
                case 2:{    //Nhập sinh viên
                    NhapHS(ArrHocSinh, SoLuongHocSinh);
                    break;
                }
                case 3:{    //Xoá học sinh
                    int ma;
                    printf("Nhập ID học sinh cần xoá: ");
                    scanf("%d", &ma);
                    XoaHS(ArrHocSinh, SoLuongHocSinh, ma);
                    break;
                }
                case 4:{    //Sắp học sinh theo tên
                    SapXepHocSinhTheoTen(ArrHocSinh, SoLuongHocSinh);
                    HienThiDanhSachHS(ArrHocSinh, SoLuongHocSinh);
                    break;
                }
                case 5:{    // Hiển thị sinh viên theo lớp
                    char lop[30];
                    printf("Chọn lớp: ");
                    fgets(lop,30,stdin);
                    HienThiDanhSachHSTheoLop(ArrHocSinh, SoLuongHocSinh, lop);
                    break;
                }
                case 6:{    //Tìm kiếm học sinh theo tên
                    char hoten[100];
                    printf("Nhap vao ten cua hoc sinh can tim kiem: ");
                    scanf("%s", hoten);
                    TimKiemHocSinhTheoTen(ArrHocSinh, SoLuongHocSinh, hoten);
                    break;
                }
                default:{
                    printf("Lựa chọn sai, vui lòng nhập lại");
                    break;
                }
                }
            } while (chonQLHS !=0);
            break;
        }
        case 2:{    //  môn
            int chonQLMH;
            printf("Dang o quan ly mon hoc");
            do{
                MenuQLMH();
                printf("Nhap vao lua chon: ");
                scanf("%d", &chonQLMH);
                switch (chonQLMH){
                case 0:{    //Thoát
                    printf("Thoát"); // nhập 0 --> thoát ra qlht
                    break;
                }
                case 1:{    //Hiển Thị Môn Học
                    
                    break;
                }    
                case 2:{    
                    break;
                }
                case 3:{   
                    break;
                }
                case 4:{   
                    break;
                }
                default:{
                    printf("Lua chon sai, vui long nhap lai");
                    break;
                }
                }
                
            } while (chonQLMH !=0);
            break;
        }
        case 3:{    //  điểm
            int chonQLD;
            printf("Dang o quan ly diem");
            do{
                MenuQLD();
                printf("Nhap vao lua chon: ");
                scanf("%d", &chonQLD);
                switch (chonQLD)
                {
                case 0:{    //Thoát
                    printf("Thoát"); // nhập 0 --> thoát ra qlht
                    break;
                }
                case 1:{ //Hiển thị điểm theo danh sách
                    HienThiDanhSachDiem(ArrHocSinh, SoLuongHocSinh, ArrDiem);
                    break;
                }    
                case 2:{    //Dieu chinh diem
                    char hoten[30];
                    printf("Nhap diem cho hoc sinh: ");
                    scanf("%s", hoten);
                    DieuChinhDiem(ArrHocSinh, SoLuongHocSinh, ArrDiem, hoten);
                    break;
                }
                case 3:{    //Xoá điểm
                    char hoten[100];
                    printf("Nhap diem cho hoc sinh: ");
                    scanf("%s", hoten);
                    XoaDiem(ArrHocSinh, SoLuongHocSinh, ArrDiem, hoten);
                    break;
                }
                case 4:{    //Hien thi danh sach diem theo ten hoc sinh
                    char hoten[30];
                    printf("Chon hoc sinh: ");
                    scanf("%s", hoten);
                    HienThiDiemHocSinh(ArrHocSinh, SoLuongHocSinh, ArrDiem, hoten);
                    break;
                }
                
                
                default:{
                    printf("Lua chon sai, vui long nhap lai");
                    break;
                }
                }
            } while (chonQLD !=0);
            break;
        }
        default:{
            printf("Nhap lai\n");// nhập sai --> nhập lại
        }
        }
    } while (chon !=0);
    return 0;
}

