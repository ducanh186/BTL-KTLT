#ifndef GENERAL_HEADER_H
#define GENERAL_HEADER_H

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>

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
     Student() {
        hoten[0] = '\0'; 
        lop[0] = '\0';   
        gender = Male;  
        birthday = {0, 0, 0}; 
    }
     Student(initializer_list<Subject> subjects) {
        // Xử lý danh sách khởi tạo subjects ở đây
        int i = 0;
        for (const auto& subject : subjects) {
            this->subject[i++] = subject;
        }
    }
    Student(const char* name, const char* cls, Gender gen, Date birth, Subject subjs[12]) {
        strncpy(hoten, name, 30);
        strncpy(lop, cls, 10);
        gender = gen;
        birthday = birth;
        for (int i = 0; i < 12; ++i) {
            subject[i] = subjs[i];
        }
    }
    friend void tinhDiem(); 
    //
    void Tao_data_lop_6A1(); 
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

    int compareByDiemTongKet(const void* a, const void* b);
    
    friend void tinhDiem(); // Khai báo tinhDiem là hàm bạn của Diem
};

Diem ketQuaHocSinh[MAX_SI_SO];



// Chuyển đổi Subject_name thành chuỗi
const char* subjectNameToString(Subject_name subject) {
    switch (subject) { 
        case Maths:          return "Toan";
        case Physics:        return "Ly";
        case Chemistry:      return "Hoa";
        case Biology:        return "Sinh";
        case Informatics:    return "Tin";
        case Literatures:    return "Van";
        case History:        return "Su";
        case Geography:      return "Dia";
        case Language:       return "Anh";
        case Moral_Education:return "GDCD";
        case Technical:      return "CN";
        case PE:             return "TD";
        default:             return "Unknown";
    }
}

// Lấy từ struct Score, lấy từ hàm S_Aver
float S_Aver(float Arr[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += Arr[i];
    }
    return sum / n;
}

float Aver(float mini[4], float test45[2], float mid, float end) {
    float sum = 0;
    sum += S_Aver(mini, 4);
    sum += S_Aver(test45, 2) * 2;
    sum += mid * 2;
    sum += end * 3;
    return sum / 8;
}

int Diem::compareByDiemTongKet(const void* a, const void* b) {
    int indexA = *(int*)a;
    int indexB = *(int*)b;

    float diemTongKetA = ketQuaHocSinh[indexA].diemTongKet;
    float diemTongKetB = ketQuaHocSinh[indexB].diemTongKet;

    // Sắp xếp giảm dần
    if (diemTongKetA < diemTongKetB) {
        return 1; 
    } else if (diemTongKetA > diemTongKetB) {
        return -1;
    } else {
        return 0;
    }
}

//khai báo hàm baomat
void baomat() ;
//Lời chào
void Loi_chao() {
    cout << "------------------CHAO MUNG BAN DEN VOI HE THONG QUAN LY DAO TAO------------------\n";
    cout << "----------------------------------------------------------------------------------\n";
    cout << "\nChuc nang chinh: Phan he nhap diem\n";
    cout << "\n!!Vui long dang nhap de su dung!!\n";
    baomat();
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
// hàm nhập lựa chọn
int GetMode(const string& input_prompt, const string& confirm_message, int max_op) {
    int option = 0; // 0 để exit 
    do {
        cout << "\n" << input_prompt << ": ";
        cin >> option; // Đọc mode được chọn từ người dùng
        while (cin.fail()) { // Kiểm tra xem nhập có hợp lệ không
            cin.clear(); // Xóa cờ lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa input buffer
            cout << "Invalid input. Please enter a number.\n";
            cout << "\n" << input_prompt << ": ";
            cin >> option;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa input buffer
        cout << "\n" << confirm_message << ": " << option << "\n"; // Hiển thị mode đã xác nhận cho người dùng
    } while (!(option >= 0 && option <= max_op)); // Lặp lại cho đến khi chọn một mode hợp lệ

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

void Menu_4_Display(){
    printf("Chon chuc nang hien thi: \n");
    printf("0. Quay lai Main Menu\n");
    printf("1. Theo Lop \n");
    printf("2. Theo ten alphabet\n");
    printf("3. Theo diem trung binh\n");
}
Student Hoc_sinh[7]; // Giả sử có tối đa 7 học sinh
int numStudents = 0;

void Student::Tao_data_lop_6A1() {
    Hoc_sinh[numStudents].hoten[0] = '\0'; // Xóa dữ liệu cũ (nếu có)
strncpy(Hoc_sinh[numStudents].hoten, "Nguyen Van An", 29); 
strncpy(Hoc_sinh[numStudents].lop, "6A1", 9);  
Hoc_sinh[numStudents].gender = Male;
Hoc_sinh[numStudents].birthday = {20, 5, 2013}; 
Hoc_sinh[numStudents].subject[0] = {Maths, {{4.0, 5.5, 7.0, 7.5}, {6.5, 8.0}, 7.8, 9.5 } }; 
Hoc_sinh[numStudents].subject[1] = {Physics, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 7.7 } };
Hoc_sinh[numStudents].subject[2] = {Chemistry, {{5.5, 5.0, 7.5, 7.7}, {3.3, 8.0}, 4.9, 6.7 } };
Hoc_sinh[numStudents].subject[3] = {Biology, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 7.7 } };
Hoc_sinh[numStudents].subject[4] = {Informatics, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 8.9, 6.0 } };
Hoc_sinh[numStudents].subject[5] = {Literatures, {{7.5, 6.0, 6.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[6] = {History, {{7.5, 7.0, 5.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[7] = {Geography, {{7.5, 8.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[8] = {Language, {{3.5, 7.0, 3.5, 5.7}, {7.3, 8.0}, 6.9, 8.7 } };
Hoc_sinh[numStudents].subject[9] = {Moral_Education, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 5.7 } };
Hoc_sinh[numStudents].subject[10] = {Technical, {{7.5, 4.3, 8.5, 7.7}, {7.3, 8.0}, 8.9, 8.7 } };
Hoc_sinh[numStudents].subject[11] = {PE, {{9.5, 7.0, 5.5, 7.7}, {7.3, 8.0}, 5.9, 8.7 } };
numStudents++;

// Học sinh thứ hai: Trần Thị Bảo
    Hoc_sinh[numStudents].hoten[0] = '\0';  // Xóa dữ liệu cũ (nếu có)
    strncpy(Hoc_sinh[numStudents].hoten, "Tran Thi Bao", 29); 
    strncpy(Hoc_sinh[numStudents].lop, "6A1", 9);  
    Hoc_sinh[numStudents].gender = Female;
    Hoc_sinh[numStudents].birthday = {15, 4, 2013}; 
    Hoc_sinh[numStudents].subject[0] = {Maths, {{8.0, 6.5, 6.0, 7.5}, {8.5, 4.0}, 8.8, 8.5 } }; 
    Hoc_sinh[numStudents].subject[1] = {Physics, {{7.5, 7.0, 9.5, 7.7}, {7.0, 8.0}, 9.0, 8.7 } };
    Hoc_sinh[numStudents].subject[2] = {Chemistry, {{7.5, 7.0, 4.5, 7.7}, {7.3, 8.0}, 7.9, 4.7 } };
    Hoc_sinh[numStudents].subject[3] = {Biology, {{7.5, 7.0, 7.5, 7.7}, {7.3, 8.0}, 8.0, 8.7 } };
    Hoc_sinh[numStudents].subject[4] = {Informatics, {{7.5, 7.0, 3.5, 7.7}, {7.3, 3.4}, 7.9, 8.7 } };
    Hoc_sinh[numStudents].subject[5] = {Literatures, {{7.5, 7.0, 7.5, 7.7}, {7.3, 8.0}, 9.9, 8.7 } };
    Hoc_sinh[numStudents].subject[6] = {History, {{7.5, 7.0, 5.5, 7.7}, {7.3, 8.0}, 5.9, 4.7 } };
    Hoc_sinh[numStudents].subject[7] = {Geography, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 10.0 } };
    Hoc_sinh[numStudents].subject[8] = {Language, {{7.5, 7.0, 7.5, 7.7}, {7.3, 8.0}, 7.9, 4.7 } };
    Hoc_sinh[numStudents].subject[9] = {Moral_Education, {{7.5, 7.0, 8.5, 7.7}, {6.0, 8.0}, 7.9, 7.7 } };
    Hoc_sinh[numStudents].subject[10] = {Technical, {{7.5, 7.0, 8.5, 7.7}, {7.5, 8.0}, 7.3, 5.7 } };
    Hoc_sinh[numStudents].subject[11] = {PE, {{7.5, 7.0, 8.5, 7.7}, {6.5, 8.0}, 2.9, 0.7 } };
    numStudents++;


// Học sinh thứ ba: Lê Văn Canh
Hoc_sinh[numStudents].hoten[0] = '\0'; // Xóa dữ liệu cũ (nếu có)
strncpy(Hoc_sinh[numStudents].hoten, "Le Van Canh", 29); 
strncpy(Hoc_sinh[numStudents].lop, "6A1", 9);  
Hoc_sinh[numStudents].gender = Male;
Hoc_sinh[numStudents].birthday = {10, 8, 2013}; 
Hoc_sinh[numStudents].subject[0] = {Maths, {{8.0, 1.5, 7.0, 7.5}, {7.5, 8.0}, 7.8, 8.5 } }; 
Hoc_sinh[numStudents].subject[1] = {Physics, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 3.5 } };
Hoc_sinh[numStudents].subject[2] = {Chemistry, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 3.5 } };
Hoc_sinh[numStudents].subject[3] = {Biology, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 3.5 } };
Hoc_sinh[numStudents].subject[4] = {Informatics, {{7.5, 7.0, 1.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[5] = {Literatures, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 9.7 } };
Hoc_sinh[numStudents].subject[6] = {History, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 4.7 } };
Hoc_sinh[numStudents].subject[7] = {Geography, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 7.7 } };
Hoc_sinh[numStudents].subject[8] = {Language, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 7.5 } };
Hoc_sinh[numStudents].subject[9] = {Moral_Education, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 4.5 } };
Hoc_sinh[numStudents].subject[10] = {Technical, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 3.5 } };
Hoc_sinh[numStudents].subject[11] = {PE, {{4.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 5.8 } };
numStudents++; 

// Học sinh thứ tư: Phạm Thị Đào
Hoc_sinh[numStudents].hoten[0] = '\0'; // Xóa dữ liệu cũ (nếu có)
strncpy(Hoc_sinh[numStudents].hoten, "Pham Thi Dao", 29); 
strncpy(Hoc_sinh[numStudents].lop, "6A1", 9);  
Hoc_sinh[numStudents].gender = Female;
Hoc_sinh[numStudents].birthday = {25, 12, 2013}; 
Hoc_sinh[numStudents].subject[0] = {Maths, {{8.0, 8.5, 7.0, 8.0}, {1.5, 8.0}, 7.8, 8.5 } }; 
Hoc_sinh[numStudents].subject[1] = {Physics, {{8.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 5.8 } };
Hoc_sinh[numStudents].subject[2] = {Chemistry, {{5.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 4.6 } };
Hoc_sinh[numStudents].subject[3] = {Biology, {{5.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 6.6 } };
Hoc_sinh[numStudents].subject[4] = {Informatics, {{8.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.6 } };
Hoc_sinh[numStudents].subject[5] = {Literatures, {{9.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 5.6 } };
Hoc_sinh[numStudents].subject[6] = {History, {{7.5, 5.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 9.6 } };
Hoc_sinh[numStudents].subject[7] = {Geography, {{1.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 7.6 } };
Hoc_sinh[numStudents].subject[8] = {Language, {{9.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[9] = {Moral_Education, {{8.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 7.9} };
Hoc_sinh[numStudents].subject[10] = {Technical, {{4.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 10.0 } };
Hoc_sinh[numStudents].subject[11] = {PE, {{6.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
numStudents++; 

// Học sinh thứ năm: Nguyễn Thị Emass
Hoc_sinh[numStudents].hoten[0] = '\0'; // Xóa dữ liệu cũ (nếu có)
strncpy(Hoc_sinh[numStudents].hoten, "Nguyen Thi Emass", 29); 
strncpy(Hoc_sinh[numStudents].lop, "6A1", 9);  
Hoc_sinh[numStudents].gender = Female;
Hoc_sinh[numStudents].birthday = {20, 5, 2013}; 
Hoc_sinh[numStudents].subject[0] = {Maths, {{8.0, 9.5, 7.0, 9.5}, {7.5, 8.0}, 7.8, 8.5 } }; 
Hoc_sinh[numStudents].subject[1] = {Physics, {{6.5, 7.0, 6.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[2] = {Chemistry, {{7.5, 7.0, 9.5, 2.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[3] = {Biology, {{3.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[4] = {Informatics, {{4.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[5] = {Literatures, {{5.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[6] = {History, {{6.5, 7.0, 6.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[7] = {Geography, {{7.5, 7.0, 8.5, 7.7}, {9.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[8] = {Language, {{7.5, 7.0, 5.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[9] = {Moral_Education, {{9.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 0.9, 2.7 } };
Hoc_sinh[numStudents].subject[10] = {Technical, {{7.5, 7.0, 9.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[11] = {PE, {{10.0, 7.0, 6.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
numStudents++; 

// Học sinh thứ sáu: Nguyễn Văn Anh 
Hoc_sinh[numStudents].hoten[0] = '\0'; // Xóa dữ liệu cũ (nếu có)
strncpy(Hoc_sinh[numStudents].hoten, "Nguyen Van Anh", 29); 
strncpy(Hoc_sinh[numStudents].lop, "6A1", 9);  
Hoc_sinh[numStudents].gender = Male;
Hoc_sinh[numStudents].birthday = {20, 5, 2013}; 
Hoc_sinh[numStudents].subject[0] = {Maths, {{8.0, 10.0, 7.0, 2.0}, {4.8, 8.0}, 7.8, 4.5 } }; 
Hoc_sinh[numStudents].subject[1] = {Physics, {{6.8, 7.0, 4.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[2] = {Chemistry, {{7.5, 7.0, 8.5, 2.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[3] = {Biology, {{7.5, 7.0, 6.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[4] = {Informatics, {{4.6, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[5] = {Literatures, {{3.4, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[6] = {History, {{7.5, 7.0, 5.0, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[7] = {Geography, {{7.5, 7.0, 8.5, 7.7}, {9.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[8] = {Language, {{7.5, 7.0, 7.0, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[9] = {Moral_Education, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 0.9, 2.7 } };
Hoc_sinh[numStudents].subject[10] = {Technical, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
Hoc_sinh[numStudents].subject[11] = {PE, {{7.5, 7.0, 7.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } };
numStudents++; 

// Học sinh thứ bảy: Lê Khánh Duy
Hoc_sinh[numStudents].hoten[0] = '\0'; // Xóa dữ liệu cũ (nếu có)
strncpy(Hoc_sinh[numStudents].hoten, "Le Khanh Duy", 29); 
strncpy(Hoc_sinh[numStudents].lop, "6A1", 9);  
Hoc_sinh[numStudents].gender = Male;
Hoc_sinh[numStudents].birthday = {12, 7, 2013}; 
Hoc_sinh[numStudents].subject[0] = {Maths, {{8.5, 6.0, 8.5, 7.0}, {7.5, 8.0}, 7.8, 8.5}};
Hoc_sinh[numStudents].subject[1] = {Physics, {{9.0, 6.0, 7.5, 7.5}, {7.0, 7.5}, 9.0, 6.0}};
Hoc_sinh[numStudents].subject[2] = {Chemistry, {{8.0, 7.0, 7.0, 7.5}, {6.0, 6.5}, 8.0, 8.5}};
Hoc_sinh[numStudents].subject[3] = {Biology, {{8.0, 8.0, 6.5, 6.5}, {7.3, 8.0}, 7.9, 8.7}};
Hoc_sinh[numStudents].subject[4] = {Informatics, {{8.0, 7.0, 7.0, 7.5}, {9.0, 8.5}, 7.5, 6.0}};
Hoc_sinh[numStudents].subject[5] = {Literatures, {{8.5, 6.0, 8.5, 8.5}, {6.0, 6.5}, 7.0, 8.5}};
Hoc_sinh[numStudents].subject[6] = {History, {{6.0, 7.5, 9.0, 6.0}, {9.0, 7.5}, 7.9, 8.7}};
Hoc_sinh[numStudents].subject[7] = {Geography, {{7.5, 7.0, 8.5, 7.7}, {9.3, 8.0}, 7.9, 8.7}};
Hoc_sinh[numStudents].subject[8] = {Language, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7}};
Hoc_sinh[numStudents].subject[9] = {Moral_Education, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 0.9, 2.7}};
Hoc_sinh[numStudents].subject[10] = {Technical, {{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7}};
Hoc_sinh[numStudents].subject[11] = {PE, {{9.0, 8.0, 9.0, 8.0}, {6.0, 7.5}, 7.5, 6.0}};
numStudents++; 
    
}

// Hàm bạn (friend function) có thể truy cập thành viên private của Student và Diem
void tinhDiem() { 
    for (int i = 0; i < numStudents; i++) {
        Diem diemHienTai; // Tạo một đối tượng Diem tạm thời

        for (int j = 0; j < 12; j++) {
            float diemTBMon = Aver(
                Hoc_sinh[i].subject[j].score.test_mini,
                Hoc_sinh[i].subject[j].score.test_45mins,
                Hoc_sinh[i].subject[j].score.mid_term_score,
                Hoc_sinh[i].subject[j].score.end_term_score
            );

            // Sử dụng phương thức của lớp Diem
            diemHienTai.capNhatDiem(j, diemTBMon); 
        }

        // Sao chép đối tượng Diem tạm thời vào mảng ketQuaHocSinh
        ketQuaHocSinh[i] = diemHienTai; 
    }
}
#endif 
