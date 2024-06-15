#ifndef GENERAL_HEADER_H
#define GENERAL_HEADER_H
#include <iostream>
#include <cstring>
#include <cctype> // Để sử dụng các hàm toupper(), tolower()
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define MAX_SI_SO 100

// Khai báo các kiểu dữ liệu liệt kê (enum) và cấu trúc (struct)
enum Gender { Male = 1, Female };
enum Subject_name {
    Maths = 1, Physics, Chemistry, Biology, Informatics, Literatures,
    History, Geography, Language, Moral_Education, Technical, PE
};

struct Date {
    int day, month, year;
};

struct Score {
    float test_mini[4];     // Điểm kiểm tra miệng
    float test_45mins[2];   // Điểm kiểm tra 45 phút
    float mid_term_score;   // Điểm kiểm tra giữa kỳ
    float end_term_score;   // Điểm kiểm tra cuối kỳ
};
// học kỳ


struct Subject {
    Subject_name subject_name; // Tên môn học
    Score score;               // Điểm của môn học
};


class Student {
private:
    char hoten[30];
    char lop[10];
    Gender gender;
    Date birthday;
    Subject subject[12];
public:
    Student(const char* name, const char* cls, Gender gen, Date birth, Subject subjs[]) {
        strncpy(hoten, name, 30);
        strncpy(lop, cls, 10);
        gender = gen;
        birthday = birth;
        for (int i = 0; i < 12; ++i) {
            subject[i] = subjs[i];
        }
    }
    
    // (Thêm các phương thức khác như tinhDiemTrungBinh(), xepLoaiHocLuc(), inPhieuDiem()...)
};

struct Semester {
    int semester_code;
    Date date;
    Student student;
};
class Diem {
private:
    float diemTongKet;
    float diemTrungBinhMonHoc[12];
public:
    Diem() : diemTongKet(0.0) {
        for (int i = 0; i < 12; i++) {
            diemTrungBinhMonHoc[i] = 0.0;
        }
    }
    // ... (Các hàm tạo, getters, setters khác)

    void capNhatDiem(int monHoc, float diemMoi) {
        if (monHoc >= 0 && monHoc < 12) {
            diemTrungBinhMonHoc[monHoc] = diemMoi;
            tinhDiemTongKet();
        } else {
            cout << "Loi: Chi so mon hoc khong hop le!" << endl;
        }
    }

    void tinhDiemTongKet() {
        diemTongKet = 0.0;
        for (int i = 0; i < 12; i++) {
            diemTongKet += diemTrungBinhMonHoc[i];
        }
        diemTongKet /= 12;
    }
    // ... (Các phương thức xepLoaiHocLuc(), hienThiDiem()...)
};

// Khởi tạo danh sách học sinh và kết quả học tập
vector<Student> Hoc_sinh;
Diem ketQuaHocSinh[MAX_SI_SO];
int numStudents = 0; // Lưu số lượng học sinh thực tế
int Si_so_lop(){
    return numStudents;
}


// Định nghĩa lớp ScoreManagementSystem
class ScoreManagementSystem {
public:
    void Tao_data_lop_6A1();
    // ... (Các phương thức khác)
};
// thuộc class ScoreManagementSytem
void ScoreManagementSystem::Tao_data_lop_6A1() {
    // Khởi tạo Subject subjects với giá trị mặc định (empty)
    Subject subjects[12];
    for (int i = 0; i < 12; i++) {
        subjects[i].subject_name = static_cast<Subject_name>(i + 1); // Khởi tạo tên môn học dựa trên enum
    }

    // Dữ liệu điểm cho từng môn học
    float diemToan[7][8] = {
        {6.7, 8.5, 7.7, 6.3, 4.2, 8.0, 7.8, 8.5},
        {6.8, 7.5, 7.4, 7.5, 7.5, 8.0, 7.8, 8.5},
        {9.0, 8.5, 7.9, 7.8, 8.9, 8.0, 7.8, 8.5},
        {8.5, 8.5, 5.5, 7.6, 6.7, 8.0, 7.8, 8.5},
        {8.7, 8.1, 3.4, 8.9, 6.5, 8.0, 7.8, 8.5},
        {8.3, 8.5, 7.2, 7.5, 7.5, 8.0, 7.8, 8.5},
        {7.5, 6.0, 5.1, 4.2, 7.3, 8.0, 7.8, 8.5}
    };

    // Gán điểm cho từng học sinh
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 12; j++) {
            for (int k = 0; k < 4; k++) {
                subjects[j].score.test_mini[k] = diemToan[i][k];
            }
            for (int k = 0; k < 2; k++) {
                subjects[j].score.test_45mins[k] = diemToan[i][k + 4];
            }
            subjects[j].score.mid_term_score = diemToan[i][6];
            subjects[j].score.end_term_score = diemToan[i][7];
        }

        // Tạo học sinh mới và thêm vào danh sách
        if (i == 0) {
            Hoc_sinh.push_back(Student("Nguyen Van An", "6A1", Male, {20, 5, 2006}, subjects));
        } else if (i == 1) {
            Hoc_sinh.push_back(Student("Tran Thi Bao", "6A1", Female, {15, 4, 2006}, subjects));
        } else if (i == 2) {
            Hoc_sinh.push_back(Student("Le Van Canh", "6A1", Male, {10, 8, 2006}, subjects));
        } else if (i == 3) {
            Hoc_sinh.push_back(Student("Pham Thi Dao", "6A1", Female, {25, 12, 2006}, subjects));
        } else if (i == 4) {
            Hoc_sinh.push_back(Student("Nguyen Thi Em", "6A1", Female, {20, 5, 2006}, subjects));
        } else if (i == 5) {
            Hoc_sinh.push_back(Student("Nguyen Van Anh", "6A1", Male, {20, 5, 2006}, subjects));
        } else if (i == 6) {
            Hoc_sinh.push_back(Student("Le Khanh Duy", "6A1", Male, {12, 7, 2006}, subjects));
        }
    }
}
// k thuộc class
float S_Aver(float Arr[],int n){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=Arr[i];
    }
    return sum/n;
}
// lấy từ struct Score,lấy từ hàm S_Aver
float Aver(float mini[4],float test45[2], float mid, float end){
    float sum=0;
    sum+=S_Aver(mini,4);
    sum+=S_Aver(test45,2)*2;
    sum+=mid*2;
    sum+=end*3;
    return sum/8;
}
// hàm bảo mật đăng nhập
void baomat() {
    char a[20] = "phuhuy12";
    char b[20] = "phuhuy12";
    cout << "\nLOG IN(Use the English keyboard to type)\n";
    while (1) {
        cout << "User name:";
        char tk[20];
        cin >> tk;
        if (strcmp(a, tk) != 0) {
            cout << "-(X)-!!Wrong account, please enter again!!\n";
            continue;
        } else {
            cout << "Password:";
            char mk[20];
            cin >> mk;
            if (strcmp(mk, b) != 0) {
                cout << "-(X)-!!Wrong password, please re-enter!!\n";
                continue;
            } else {
                break;
            }
        }
    }
}
//Lời chào
void Loi_chao() {
    cout << "------------------CHAO MUNG BAN DEN VOI HE THONG QUAN LY DAO TAO------------------\n";
    cout << "----------------------------------------------------------------------------------\n";
    cout << "\nChuc nang chinh: Phan he nhap diem\n";
    cout << "\n!!Vui long dang nhap de su dung!!\n";
    baomat();
}
// yêu cầu người dùng nhập một tùy chọn số nguyên trong một khoảng giá trị hợp lệ 
int GetMode(char* input_prompt, char* confirm_message) {
    int option = 0;
    do {
        cout << "\n" << input_prompt << ": ";
        cin >> option; // Đọc chế độ được chọn từ người dùng
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm đầu vào. Bộ đệm đầu vào luôn kết thúc bằng Enter ('\n')
        cout << "\n" << confirm_message << ": " << option << "\n"; // Hiển thị chế độ được xác nhận cho người dùng
    } while(!(option >= 0 && option <= 4)); // Lặp lại cho đến khi một chế độ hợp lệ được chọn

    return option;
}
// hiển thị menu chính
void Main_Menu_Display() {
    cout << "Chon chuc nang: \n";
    cout << "0. Thoat\n";
    cout << "1. Hien thi danh sach diem trung binh \n";
    cout << "2. Chinh sua diem\n"; 
    cout << "3. Hien thi danh sach theo hoc sinh\n"; // điền tên học sinh muốn tìm
    cout << "4. Hien thi danh sach theo mon hoc\n"; // điền tên môn học
}
// Các menu phụ
void Menu_1_Display() {
    cout << "Chon chuc nang hien thi: \n";
    cout << "0. Quay lai Main Menu\n";
    cout << "1. Theo Lop \n";
    cout << "2. Theo ten alphabet\n";
    cout << "3. Theo do doc cac mon\n";
    cout << "4. Theo diem tong ket\n";
}

void Menu_2_Display() {
    cout << "\nCHON CHUC NANG TIM KIEM DE SUA DIEM :\n";
    cout << "0. Quay lai Main Menu\n";
    cout << "1. Theo ten (Last Name)\n";
    cout << "2. Theo Ho va ten (Full Name)\n";
}

void Menu_2_1_Display() {
    cout << "Vui long nhap ten (Last Name) hoc sinh can sua diem!!\n";
    cout << "Vui long nhap ten khong dau\n";
}
#endif 
