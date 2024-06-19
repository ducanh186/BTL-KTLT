#ifndef GENERAL_HEADER_H
#define GENERAL_HEADER_H

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <bits/stdc++.h>

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
    const char* getHoTen() const {
        return hoten;
    }
    const char* getLop() const {
        return lop;
    }
    Gender getGender() const {
        return gender;
    }
    const Date& getBirthday() const {
        return birthday;
    }
    const Subject& getSubject(int index) const { // Getter cho subject
        if (index >= 0 && index < 12) {
            return subject[index];
        } else {
            throw std::out_of_range("Invalid subject index");
        }
    }
    void editScoreBySubject_end_term_score(Student *student, Subject_name subject, float newScore);
    void editScoreBySubject_mid_score(Student *student, Subject_name subject, float newScore);
    void editScoreBySubject_mini_test(Student *student, Subject_name subject, float newScore, int a);
    void editScoreBySubject_test_45mins(Student *student, Subject_name subject, float newScore, int a);
    void chon_mon_va_fix_diem(int index);
    void tim_ten_de_sua_diem(Student* list_name, int numStudents);
    void tim_hoten_de_sua_diem(Student* list_name, int numStudents);
    void ThemHocSinh();

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

    float getDiemTongKet() const {
        return diemTongKet;
    }

    float getDiemTrungBinhMonHoc(int monHoc) const {
        if (monHoc >= 0 && monHoc < 12) {
            return diemTrungBinhMonHoc[monHoc];
        } else {
            cout << "Loi: Chi so mon hoc khong hop le!" << endl;
            return -1.0; // Trả về giá trị lỗi
        }
    }
    
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
float S_Aver(const float Arr[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += Arr[i];
    }
    return sum / n;
}

float Aver(const float mini[4],const float test45[2],const float mid,const float end) {
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
    cout << "\t\tCHAO MUNG DEN VOI\n";
    cout << "\tHe thong quan ly dao tao truong THCS\n";
    cout << "   ~~~Phan he nhap diem cac mon hoc cho hoc sinh~~~\n";
    cout << "Chon chuc nang: \n";
    cout << "0. Thoat\n";
    cout << "1. Hien thi danh sach diem trung binh \n";
    cout << "2. Chinh sua diem\n";
    cout << "3. Hien thi danh sach theo tung hoc sinh\n";
    cout << "4. Hien thi danh sach theo tung mon hoc\n";
    cout << "5. Them 1 hoc sinh\n";
    cout << "6. Xuat Du lieu thanh file .txt\n";
}
// Các menu phụ
void Menu_1_Display() {
    cout << "Chon chuc nang hien thi: \n";
    cout << "0. Quay lai Main Menu\n";
    cout << "1. Theo Lop \n";
    cout << "2. Theo ten alphabet\n";
    cout << "3. Theo diem tong ket\n";
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


// Hàm hiện thị cho chức năng 1.1
void Hien_thi_ds_Hoc_sinh_DiemTB_mon(int para_Si_so_lop = numStudents) {
    tinhDiem(); // Gọi hàm tinhDiem để tính toán điểm trước khi hiển thị

    cout << endl;
    cout << "~~~---DANH SACH HOC SINH---~~~" << endl;

    // Vẽ đường kẻ ngang
    cout << string(126, '_') << endl;

    cout << "|STT|Ho va Ten               |Lop |Gioi Tinh|Ngay Sinh    ";

    // In tên các môn học (sử dụng vòng lặp for và cout thay vì printf)
    for (int i = 0; i < 12; i++) {
        cout << "|" << left << setw(4) << subjectNameToString(static_cast<Subject_name>(i+1)); 
    }

    cout << "|T.K |" << endl;

    for (int i = 0; i < para_Si_so_lop; i++) {
        cout << "|" << setw(3) << i + 1 
             << "|" << left << setw(25) << Hoc_sinh[i].getHoTen()
             << "|" << setw(5) << Hoc_sinh[i].getLop()
             << "|" << setw(9) << (Hoc_sinh[i].getGender() == Male ? "Nam" : "Nu")  // Sử dụng getter
             << "| ";

        // Hiển thị ngày sinh (sử dụng getter)
        const Date& birth = Hoc_sinh[i].getBirthday();
        cout << setw(2) << birth.day << "/"
             << setw(2) << birth.month << "/"
             << setw(5) << birth.year << " ";

        // In điểm trung bình các môn (sử dụng getter của Diem)
        for (int j = 0; j < 12; j++) {
            cout << "|" << setw(4) << setprecision(1) << fixed 
                 << ketQuaHocSinh[i].getDiemTrungBinhMonHoc(j);
        }
        cout << "|" << setw(4) << setprecision(1) << fixed
             << ketQuaHocSinh[i].getDiemTongKet() << "|" << endl;
    }

    // Vẽ đường kẻ ngang đặc biệt ở cuối
    cout << "$" << string(124, '~') << "$" << endl;
}

// Hàm tách từng thành phần trong tên (C++)
void splitName(const string& fullName, string* firstName, string* middleName, string* lastName) {
    vector<string> tokens; // Sử dụng vector để lưu trữ các từ trong tên
    string currentToken;

    // Duyệt qua từng ký tự trong fullName
    for (char c : fullName) {
        if (c == ' ') {
            if (!currentToken.empty()) {
                tokens.push_back(currentToken); // Thêm từ vào vector
                currentToken.clear();
            }
        } else {
            currentToken += c; // Xây dựng từ hiện tại
        }
    }

    // Thêm từ cuối cùng (nếu có)
    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }

    // Xử lý các phần của tên
    if (tokens.size() >= 3) {
        *firstName = tokens[0];
        *middleName = tokens[1];
        *lastName = tokens.back(); // Lấy từ cuối cùng trong vector
    } else if (tokens.size() == 2) {
        *firstName = tokens[0];
        *middleName = "";
        *lastName = tokens[1];
    } else {
        *firstName = "";
        *middleName = "";
        *lastName = tokens.empty() ? "" : tokens[0]; // Nếu vector rỗng thì gán ""
    }
}

// So sánh tên theo từng phần (C++)
int compareNames(const void* a, const void* b) {
    const Student* studentA = static_cast<const Student*>(a);
    const Student* studentB = static_cast<const Student*>(b);

    string firstName1, middleName1, lastName1;
    string firstName2, middleName2, lastName2;

    // Tách tên học sinh A và B
    splitName(studentA->getHoTen(), &firstName1, &middleName1, &lastName1);
    splitName(studentB->getHoTen(), &firstName2, &middleName2, &lastName2);

    // So sánh tên (lastName) trước
    if (lastName1 != lastName2) {
        return lastName1.compare(lastName2); // Sử dụng phương thức compare của std::string
    }

    // Nếu tên giống nhau, so sánh họ (firstName)
    if (firstName1 != firstName2) {
        return firstName1.compare(firstName2);
    }

    // Nếu cả họ và tên đều giống nhau, so sánh tên đệm (middleName)
    return middleName1.compare(middleName2);
}

int compareNamesByIndex(const void* a, const void* b) {
    int indexA = *(static_cast<const int*>(a)); // Ép kiểu an toàn hơn
    int indexB = *(static_cast<const int*>(b));

    return compareNames(&Hoc_sinh[indexA], &Hoc_sinh[indexB]);
}

// Hiển thị theo thứ tự bảng chữ cái (chức năng 1.2)
void Hien_thi_ds_Hoc_sinh_anpha(int para_Si_so_lop = numStudents) {
    vector<int> indices(numStudents);  // Sử dụng vector thay vì mảng C
    iota(indices.begin(), indices.end(), 0); // Điền số từ 0 đến numStudents-1

    // Sắp xếp vector indices dựa trên tên học sinh
    sort(indices.begin(), indices.end(), 
         [&](int i, int j) { return compareNames(&Hoc_sinh[i], &Hoc_sinh[j]) < 0; }
    );

    cout << "\n~~~---DANH SACH HOC SINH---~~~" << endl;

    // Vẽ đường kẻ ngang
    cout << string(121, '_') << endl;

    cout << "|STT|Ho va Ten               |Lop |Gioi Tinh|Ngay Sinh    ";
    for (int i = 0; i < 12; i++) {
        cout << "|" << left << setw(4) << subjectNameToString(static_cast<Subject_name>(i+1)); 
    }
    cout << "|\n"; 

    // Hiển thị thông tin học sinh theo thứ tự alphabet
    for (int i = 0; i < para_Si_so_lop; i++) {
        int currentIndex = indices[i]; // Lấy index từ vector đã sắp xếp

        cout << "|" << setw(3) << i + 1
             << "|" << left << setw(25) << Hoc_sinh[currentIndex].getHoTen()
             << "|" << setw(5) << Hoc_sinh[currentIndex].getLop()
             << "|" << setw(9) << (Hoc_sinh[currentIndex].getGender() == Male ? "Nam" : "Nu")
             << "| ";

        const Date& birth = Hoc_sinh[currentIndex].getBirthday();
        cout << setw(2) << birth.day << "/"
             << setw(2) << birth.month << "/"
             << setw(5) << birth.year << " ";

        for (int j = 0; j < 12; j++) {
            cout << "|" << setw(4) << setprecision(1) << fixed
                 << Aver(Hoc_sinh[currentIndex].getSubject(j).score.test_mini,
                        Hoc_sinh[currentIndex].getSubject(j).score.test_45mins,
                        Hoc_sinh[currentIndex].getSubject(j).score.mid_term_score,
                        Hoc_sinh[currentIndex].getSubject(j).score.end_term_score);
        }
        cout << "|\n"; // Kết thúc hàng của 1 học sinh
    }

    // Vẽ đường kẻ ngang đặc biệt ở cuối
    cout << "$" << string(119, '~') << "$" << endl;
}

// Hàm hiện thị danh sách điểm của học sinh theo môn học
void Hien_thi_ds_Diem_mon(int para_Si_so_lop = numStudents, int ten_mon = 0) {
    tinhDiem(); // Gọi hàm tinhDiem để cập nhật điểm trước khi hiển thị

    cout << endl;
    cout << "~~~---Danh Sach Diem Hoc Sinh Mon " 
         << subjectNameToString(Hoc_sinh[0].getSubject(ten_mon).subject_name) // Sử dụng getter
         << "---~~~" << endl;

    // Vẽ đường kẻ ngang
    cout << string(126, '_') << endl;

    cout << "|STT|Ho va Ten               |Lop |Gioi Tinh|   Diem mini test   |Diem 45 phut |Diem giua ki|Diem cuoi ki|Trung Binh|" << endl;

    for (int i = 0; i < para_Si_so_lop; i++) {
        cout << "|" << setw(3) << i + 1 
             << "|" << left << setw(25) << Hoc_sinh[i].getHoTen() // Sử dụng getter
             << "|" << setw(5) << Hoc_sinh[i].getLop()           // Sử dụng getter
             << "|" << setw(9) << (Hoc_sinh[i].getGender() == Male ? "Nam" : "Nu")  // Sử dụng getter
             << "|";

        // In điểm các bài kiểm tra nhỏ (sử dụng getter)
        for (int j = 0; j < 4; j++) {
            cout << setw(5) << fixed << setprecision(1) 
                 << Hoc_sinh[i].getSubject(ten_mon).score.test_mini[j] << " "; // Sử dụng getter
        }

        // In điểm các bài kiểm tra 45 phút (sử dụng getter)
        for (int j = 0; j < 2; j++) {
            cout << "|" << setw(10) << fixed << setprecision(1) 
                 << Hoc_sinh[i].getSubject(ten_mon).score.test_45mins[j] << " "; // Sử dụng getter
        }

        // In điểm giữa kỳ và cuối kỳ (sử dụng getter)
        cout << "|" << setw(10) << fixed << setprecision(1) 
             << Hoc_sinh[i].getSubject(ten_mon).score.mid_term_score << "   " // Sử dụng getter
             << "|" << setw(10) << fixed << setprecision(1) 
             << Hoc_sinh[i].getSubject(ten_mon).score.end_term_score << "   " // Sử dụng getter
             << "|" << setw(8) << fixed << setprecision(1)
             << ketQuaHocSinh[i].getDiemTrungBinhMonHoc(ten_mon) // Sử dụng getter
             << "|" << endl;
    }

    // Vẽ đường kẻ ngang đặc biệt ở cuối
    cout << "$" << string(124, '~') << "$" << endl;
}
// Hàm hiện thị danh sách điểm của học sinh theo môn, sắp xếp theo điểm trung bình
void Hien_thi_ds_Diem_mon_trung_binh(int para_Si_so_lop = numStudents, int ten_mon = 0) {
    tinhDiem(); // Gọi hàm tinhDiem để cập nhật điểm trước khi hiển thị

    vector<int> indices(numStudents);
    iota(indices.begin(), indices.end(), 0);

    // Sắp xếp vector indices dựa trên điểm trung bình của môn học
    sort(indices.begin(), indices.end(),
        [&](int i, int j) {
            return ketQuaHocSinh[i].getDiemTrungBinhMonHoc(ten_mon) >
                   ketQuaHocSinh[j].getDiemTrungBinhMonHoc(ten_mon);
        });

    cout << endl;
    cout << "~~~---Danh Sach Diem Hoc Sinh Mon "
         << subjectNameToString(Hoc_sinh[0].getSubject(ten_mon).subject_name)
         << "---~~~" << endl;

    // Vẽ đường kẻ ngang
    cout << string(126, '_') << endl;

    cout << "|STT|Ho va Ten               |Lop |Gioi Tinh|   Diem mini test   |Diem 45 phut |Diem giua ki|Diem cuoi ki|Trung Binh|" << endl;

    for (int i = 0; i < para_Si_so_lop; i++) {
        int currentIndex = indices[i]; // Lấy index từ vector đã sắp xếp

        // Khai báo diemTBMon ở đây
        float diemTBMon = 0.0; 

        cout << "|" << setw(3) << i + 1 
             << "|" << left << setw(25) << Hoc_sinh[currentIndex].getHoTen()
             << "|" << setw(5) << Hoc_sinh[currentIndex].getLop()
             << "|" << setw(9) << (Hoc_sinh[currentIndex].getGender() == Male ? "Nam" : "Nu")
             << "|";

        // In điểm các bài kiểm tra nhỏ (sử dụng getter)
        for (int j = 0; j < 4; j++) {
            cout << setw(5) << fixed << setprecision(1) 
                 << Hoc_sinh[currentIndex].getSubject(ten_mon).score.test_mini[j] << " ";
        }

        // In điểm các bài kiểm tra 45 phút (sử dụng getter)
        for (int j = 0; j < 2; j++) {
            cout << "|" << setw(10) << fixed << setprecision(1) 
                 << Hoc_sinh[currentIndex].getSubject(ten_mon).score.test_45mins[j] << " ";
        }
        
        // Tính điểm trung bình môn học (diemTBMon)
        diemTBMon = Aver(
            Hoc_sinh[currentIndex].getSubject(ten_mon).score.test_mini,
            Hoc_sinh[currentIndex].getSubject(ten_mon).score.test_45mins,
            Hoc_sinh[currentIndex].getSubject(ten_mon).score.mid_term_score,
            Hoc_sinh[currentIndex].getSubject(ten_mon).score.end_term_score
        );
        
        // In điểm giữa kỳ và cuối kỳ (sử dụng getter)
        cout << "|" << setw(10) << fixed << setprecision(1) 
             << Hoc_sinh[currentIndex].getSubject(ten_mon).score.mid_term_score << "   "
             << "|" << setw(10) << fixed << setprecision(1) 
             << Hoc_sinh[currentIndex].getSubject(ten_mon).score.end_term_score << "   "
             << "|" << setw(8) << fixed << setprecision(1)
             << diemTBMon // In điểm trung bình môn học (diemTBMon)
             << "|" << endl;
    }

    // Vẽ đường kẻ ngang đặc biệt ở cuối
    cout << "$" << string(124, '~') << "$" << endl;
}
// Hàm hiện thị danh sách học sinh theo điểm tổng kết (DTK)
void Hien_thi_ds_Hoc_sinh_theo_DTK(int para_Si_so_lop = numStudents) {
    tinhDiem(); // Gọi hàm tinhDiem để cập nhật điểm trước khi hiển thị

    vector<int> indices(numStudents);
    iota(indices.begin(), indices.end(), 0);

    // Sắp xếp vector indices theo điểm tổng kết (giảm dần)
    sort(indices.begin(), indices.end(), 
        [](int i, int j) { 
            return ketQuaHocSinh[i].getDiemTongKet() > ketQuaHocSinh[j].getDiemTongKet(); // So sánh điểm tổng kết
        });

    cout << endl;
    cout << "~~~---DANH SACH HOC SINH---~~~" << endl;

    // Vẽ đường kẻ ngang
    cout << string(126, '_') << endl;

    cout << "|STT|Ho va Ten               |Lop |Gioi Tinh|Ngay Sinh    ";
    for (int i = 0; i < 12; i++) { // In tên các môn học
        cout << "|" << left << setw(4) << subjectNameToString(static_cast<Subject_name>(i+1));
    }
    cout << "|T.K |" << endl;

    for (int i = 0; i < para_Si_so_lop; i++) {
        int currentIndex = indices[i]; // Lấy chỉ số từ vector đã sắp xếp
        
        cout << "|" << setw(3) << i + 1
             << "|" << left << setw(25) << Hoc_sinh[currentIndex].getHoTen() // Sử dụng getter
             << "|" << setw(5) << Hoc_sinh[currentIndex].getLop()           // Sử dụng getter
             << "|" << setw(9) << (Hoc_sinh[currentIndex].getGender() == Male ? "Nam" : "Nu")  // Sử dụng getter
             << "| ";

        const Date& birth = Hoc_sinh[currentIndex].getBirthday(); // Sử dụng getter
        cout << setw(2) << birth.day << "/"
             << setw(2) << birth.month << "/"
             << setw(5) << birth.year << " ";

        for (int j = 0; j < 12; j++) {
            // Tính diemTBMon ở đây, ngay trước khi in ra
            float diemTBMon = Aver(
                Hoc_sinh[currentIndex].getSubject(j).score.test_mini,
                Hoc_sinh[currentIndex].getSubject(j).score.test_45mins,
                Hoc_sinh[currentIndex].getSubject(j).score.mid_term_score,
                Hoc_sinh[currentIndex].getSubject(j).score.end_term_score
            );

            cout << "|" << setw(4) << fixed << setprecision(1) 
                 << diemTBMon; // In điểm trung bình môn học vừa tính
        }
        cout << "|" << setw(4) << fixed << setprecision(1) 
             << ketQuaHocSinh[currentIndex].getDiemTongKet()  // Sử dụng getter
             << "|" << endl;
    }

    cout << "$" << string(124, '~') << "$" << endl;
}

// Hàm hiển thị danh sách điểm của học sinh theo môn học, sắp xếp theo alphabet
void Hien_thi_ds_Diem_mon_alpha(int para_Si_so_lop = numStudents, int ten_mon = 0) {
    tinhDiem(); // Gọi hàm tinhDiem để cập nhật điểm trước khi hiển thị

    vector<int> indices(numStudents);
    iota(indices.begin(), indices.end(), 0);

    // Sắp xếp vector indices theo tên học sinh (alphabet)
    sort(indices.begin(), indices.end(),
        [&](int i, int j) {
            return compareNames(&Hoc_sinh[i], &Hoc_sinh[j]) < 0; 
        });

    cout << endl;
    cout << "~~~---Danh Sach Diem Hoc Sinh Mon "
         << subjectNameToString(Hoc_sinh[0].getSubject(ten_mon).subject_name)
         << "---~~~" << endl;

    // Vẽ đường kẻ ngang
    cout << string(126, '_') << endl;

    cout << "|STT|Ho va Ten               |Lop |Gioi Tinh|   Diem mini test   |Diem 45 phut |Diem giua ki|Diem cuoi ki|Trung Binh|" << endl;

    for (int i = 0; i < para_Si_so_lop; i++) {
        int currentIndex = indices[i]; // Lấy index từ vector đã sắp xếp

        cout << "|" << setw(3) << i + 1
             << "|" << left << setw(25) << Hoc_sinh[currentIndex].getHoTen()
             << "|" << setw(5) << Hoc_sinh[currentIndex].getLop()
             << "|" << setw(9) << (Hoc_sinh[currentIndex].getGender() == Male ? "Nam" : "Nu")
             << "|";

        // In điểm các bài kiểm tra nhỏ (sử dụng getter)
        for (int j = 0; j < 4; j++) {
            cout << setw(5) << fixed << setprecision(1) 
                 << Hoc_sinh[currentIndex].getSubject(ten_mon).score.test_mini[j] << " ";
        }

        // In điểm các bài kiểm tra 45 phút (sử dụng getter)
        for (int j = 0; j < 2; j++) {
            cout << "|" << setw(10) << fixed << setprecision(1) 
                 << Hoc_sinh[currentIndex].getSubject(ten_mon).score.test_45mins[j] << " ";
        }

        // In điểm giữa kỳ và cuối kỳ (sử dụng getter)
        cout << "|" << setw(10) << fixed << setprecision(1) 
             << Hoc_sinh[currentIndex].getSubject(ten_mon).score.mid_term_score << "   "
             << "|" << setw(10) << fixed << setprecision(1) 
             << Hoc_sinh[currentIndex].getSubject(ten_mon).score.end_term_score << "   "
             << "|" << setw(8) << fixed << setprecision(1)
             << ketQuaHocSinh[currentIndex].getDiemTrungBinhMonHoc(ten_mon) 
             << "|" << endl;
    }

    // Vẽ đường kẻ ngang đặc biệt ở cuối
    cout << "$" << string(124, '~') << "$" << endl;
}

// Chuẩn hóa từng từ (C++)
string chuanHoaTu(const string& s) {
    string result = s; // Tạo bản sao của chuỗi
    result[0] = toupper(result[0]); // Viết hoa ký tự đầu tiên

    // Viết thường các ký tự còn lại
    for (size_t i = 1; i < result.length(); i++) { 
        result[i] = tolower(result[i]);
    }
    return result;
}

// Chuẩn hóa tên (C++)
string chuanHoaTen(const string& s) {
    stringstream ss(s);
    string token, result;

    // Tách và chuẩn hóa từng từ
    while (ss >> token) {
        result += chuanHoaTu(token) + " ";
    }

    // Loại bỏ dấu cách thừa cuối cùng
    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

// Tìm kiếm học sinh theo tên (lastName)
int searchByLastName(const Student* danhSach, int numStudents, const string& searchName) {
    for (int i = 0; i < numStudents; i++) {
        string firstName, middleName, lastName;

        // Tách tên học sinh
        splitName(danhSach[i].getHoTen(), &firstName, &middleName, &lastName); // Sử dụng getter
        if (lastName == searchName) {
            return i;
        }
    }
    return -1;
}

// Tìm kiếm học sinh theo họ và tên (fullName)
int searchByFullName(const Student* danhSach, int numStudents, const string& searchName) {
    string normalizedSearchName = chuanHoaTen(searchName);

    for (int i = 0; i < numStudents; i++) {
        string normalizedFullName = chuanHoaTen(danhSach[i].getHoTen()); // Sử dụng getter
        if (normalizedFullName == normalizedSearchName) {
            return i;
        }
    }
    return -1;
}

void Student :: editScoreBySubject_end_term_score(Student *student, Subject_name subject, float newScore) {
    for (int i = 0; i < 12; i++) {
        if (student->subject[i].subject_name == subject) {
            // Tìm thấy môn học cần sửa điểm
            student->subject[i].score.end_term_score = newScore;
            
        }
    }
  
    // Không tìm thấy môn học trong danh sách
    printf("Khong tim thay mon hoc co ten %s.\n", subjectNameToString(subject));
}

void Student::editScoreBySubject_mid_score(Student *student, Subject_name subject, float newScore) {
    for (int i = 0; i < 12; i++) {
        if (student->subject[i].subject_name == subject) {
            // Tìm thấy môn học cần sửa điểm
            student->subject[i].score.mid_term_score = newScore;
         
        }
    }
}

void Student::editScoreBySubject_mini_test(Student *student, Subject_name subject, float newScore, int a) {
    for (int i = 0; i < 12; i++) {
        if (student->subject[i].subject_name == subject) {
            // Tìm thấy môn học cần sửa điểm
            student->subject[i].score.test_mini[a] = newScore;
         
        }
    }
}

void Student :: editScoreBySubject_test_45mins(Student *student, Subject_name subject, float newScore, int a) {
    for (int i = 0; i < 12; i++) {
        if (student->subject[i].subject_name == subject) {
            // Tìm thấy môn học cần sửa điểm
            student->subject[i].score.test_45mins[a] = newScore;
         
        }
    }
}

void in_diem_hien_tai_cua_1HS(int subjectOption, int index) {
    cout << "\nDiem mon " 
         << subjectNameToString(Hoc_sinh[index].getSubject(subjectOption).subject_name) // Sử dụng getter
         << " hien tai cua " << Hoc_sinh[index].getHoTen() // Sử dụng getter
         << " la:\n";

    cout << "Diem mini test (4 diem): ";
    for (int i = 0; i < 4; i++) {
        cout << fixed << setprecision(1) << Hoc_sinh[index].getSubject(subjectOption).score.test_mini[i]; // Sử dụng getter
        if (i < 3) {
            cout << " , ";
        }
    }

    cout << "\nDiem kiem tra 45p (2 diem): ";
    for (int i = 0; i < 2; i++) {
        cout << fixed << setprecision(1) << Hoc_sinh[index].getSubject(subjectOption).score.test_45mins[i]; // Sử dụng getter
        if (i < 1) {
            cout << " , ";
        }
    }

    cout << "\n";
    cout << "Diem kiem tra giua ky: " << fixed << setprecision(1) 
         << Hoc_sinh[index].getSubject(subjectOption).score.mid_term_score << endl; // Sử dụng getter
    cout << "Diem kiem tra cuoi ky: " << fixed << setprecision(1) 
         << Hoc_sinh[index].getSubject(subjectOption).score.end_term_score << endl; // Sử dụng getter
}

void Student :: chon_mon_va_fix_diem(int index) {
    cout << "Chon mon hoc can chinh sua diem:\n";
    for (int i = 0; i < 12; i++) {
        cout << "| " << i + 1 << ". " << subjectNameToString(Hoc_sinh[index].getSubject(i).subject_name) << "   "; // Sử dụng getter
    }
    cout << endl;

    int subjectOption = GetMode("Nhap lua chon [1-12]", "Lua chon", 12);
    in_diem_hien_tai_cua_1HS(subjectOption - 1, index);

    cout << "\nChon Diem muon sua:\n";
    cout << "0. Thoat\n";
    cout << "1. Diem mini test\n";
    cout << "2. Diem 45 phut\n";
    cout << "3. Diem giua ki\n";
    cout << "4. Diem cuoi ki\n";

    int scoreOption = GetMode("Nhap lua chon [1-4]", "Lua chon", 4);

    // Chỉnh sửa điểm của môn học đã chọn
    float newScore;

    if (scoreOption == 1) {
        cout << "\nChon diem mini test muon sua:\n";
        for (int i = 0; i < 4; i++) {
            cout << "| " << i + 1 << ". " << fixed << setprecision(1) 
                 << Hoc_sinh[index].getSubject(subjectOption - 1).score.test_mini[i] << " "; // Sử dụng getter
        }
        cout << endl;

        int miniTestOption = GetMode("Nhap lua chon [1-4]", "Lua chon", 4);

        cout << "\nNhap diem mini test moi: ";
        cin >> newScore;
        while (cin.fail() || newScore < 0 || newScore > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Diem khong hop le. Nhap lai diem mini test moi (0-10): ";
            cin >> newScore;
        }

        cout << "\n-------Sua diem thanh cong------\n";
        cout << "Diem mini test da duoc sua: " << fixed << setprecision(1)
             << Hoc_sinh[index].getSubject(subjectOption - 1).score.test_mini[miniTestOption - 1] << " ==> "
             << newScore << endl;
        editScoreBySubject_mini_test(&Hoc_sinh[index], static_cast<Subject_name>(subjectOption - 1), newScore, miniTestOption - 1);
        in_diem_hien_tai_cua_1HS(subjectOption - 1, index);
    } else if (scoreOption == 2) {
        // ... (Tương tự cho các lựa chọn khác 2, 3, 4, bạn có thể tự hoàn thiện)
    } else {
        cout << "Khong co lua chon nay. Vui long nhap lai." << endl;
    }
}

void Student :: tim_ten_de_sua_diem(Student* list_name, int numStudents) {
    string searchLastName;

    cout << "Ten can tim: ";
    getline(cin, searchLastName); // Đọc cả dòng để tránh lỗi bỏ sót ký tự
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm '\n' còn sót lại
    searchLastName = chuanHoaTu(searchLastName);

    int index = searchByLastName(list_name, numStudents, searchLastName);

    if (index != -1) {
        cout << "\nDa tim thay hoc sinh \"" << list_name[index].getHoTen() << "!!\"" << endl;
        cout << endl;
        chon_mon_va_fix_diem(index);
    } else {
        cout << "Khong tim thay hoc sinh co ho ten " << searchLastName << "." << endl;
    }
}

void Student :: tim_hoten_de_sua_diem(Student* list_name, int numStudents) {
    string searchName;

    cout << "Ten can tim: ";
    getline(cin, searchName); // Đọc cả dòng, bao gồm cả dấu cách
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa ký tự newline '\n' còn lại trong bộ đệm nhập
    
    int index = searchByFullName(list_name, numStudents, searchName); // Tìm kiếm theo họ tên đã chuẩn hóa
    
    if (index != -1) {
        cout << "\nDa tim thay hoc sinh \"" << list_name[index].getHoTen() << "!!\"" << endl;
        cout << endl;
        chon_mon_va_fix_diem(index);
    } else {
        cout << "Khong tim thay hoc sinh co ho ten " << searchName << "." << endl;
    }
}

// Hàm hiển thị danh sách học sinh cơ bản (C++)
void hienThiDanhSachHocSinhCoBan(const Student list[], int numStudents) {
    cout << endl;
    cout << "~~~---DANH SACH HOC SINH---~~~" << endl;
    
    // Đảm bảo căn chỉnh bằng cách sử dụng std::setw
    cout << "| " << left << setw(3) << "STT" 
         << "| " << setw(25) << "Ho va Ten"
         << "| " << setw(5) << "Lop"
         << "| " << setw(12) << "Ngay Sinh" << " |" << endl;

    for (int i = 0; i < numStudents; i++) {
        cout << "| " << setw(3) << i + 1 
             << "| " << setw(25) << list[i].getHoTen()  // Sử dụng getter
             << "| " << setw(5) << list[i].getLop()    // Sử dụng getter
             << "| ";

        const Date& birth = list[i].getBirthday();   // Sử dụng getter
        cout << setw(2) << birth.day << "/"
             << setw(2) << birth.month << "/"
             << setw(5) << birth.year << " |" << endl;
    }
}

// In phiếu điểm cá nhân của học sinh
void inPhieuDiemCaNhan(const Student& student) {
    cout << endl;
    cout << "\t\t\t\t\tPHIEU BAO DIEM\n";
    cout << "\t\t\t\tHoc ky X - Nam hoc XXXX - XXXX\n\n";

    // Thông tin cá nhân
    const Date& birthday = student.getBirthday();
    cout << "Ho va ten: " << left << setw(25) << student.getHoTen() 
         << "Ngay sinh: " << setw(2) << birthday.day << "/" << setw(2) << birthday.month << "/" << setw(5) << birthday.year
         << "Lop: " << student.getLop() << endl;

    // Header bảng điểm
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "|STT |" << left << setw(12) << "Mon hoc" << "|"; // Tăng độ rộng cột "Môn học" lên 12
    for (int j = 1; j <= 4; j++) {
        cout << "Diem " << j << setw(4) << "|";
    }
    cout << "45p 1 |45p 2 |DDGK |DDCK |TB   |" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;

    float tongDiemTB = 0.0;
    for (int i = 0; i < 12; i++) {
        // Tính điểm trung bình môn học
        float diemTBMon = Aver(
            student.getSubject(i).score.test_mini, 
            student.getSubject(i).score.test_45mins,
            student.getSubject(i).score.mid_term_score,
            student.getSubject(i).score.end_term_score
        );
        tongDiemTB += diemTBMon;

        // In điểm từng môn học
        cout << "|" << setw(4) << i + 1 << " |"
             << setw(12) << subjectNameToString(student.getSubject(i).subject_name) << "|"; // Căn lề trái cho tên môn học

        for (int j = 0; j < 4; j++) {
            cout << setw(6) << fixed << setprecision(1) << student.getSubject(i).score.test_mini[j] << "|"; // Căn lề phải cho điểm
        }
        for (int j = 0; j < 2; j++) {
            cout << setw(6) << fixed << setprecision(1) << student.getSubject(i).score.test_45mins[j] << "|";
        }
        cout << setw(5) << fixed << setprecision(1) << student.getSubject(i).score.mid_term_score << "|"
             << setw(5) << fixed << setprecision(1) << student.getSubject(i).score.end_term_score << "|"
             << setw(6) << fixed << setprecision(1) << diemTBMon << " |" << endl; // Căn lề phải cho điểm
    }

    // Tính TBC và xác định học lực, danh hiệu
    float TBC = tongDiemTB / 12;
    string HL, DH;
    if (TBC >= 8.0) {
        HL = "Gioi";
        DH = "HSG";
    } else if (TBC >= 6.5) {
        HL = "Kha";
        DH = "HSK";
    } else if (TBC >= 5.0) {
        HL = "Trung binh";
        DH = "";
    } else {
        HL = "Yeu";
        DH = "";
    }

    cout << "------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Tong ket HK I\t\t\tTBC: " << fixed << setprecision(1) << TBC 
         << "\tHoc luc: " << HL << "\tHanh kiem: Tot" << endl;
}


void Student ::ThemHocSinh() {
    if (numStudents >= MAX_SI_SO) {
        cout << "Danh sach hoc sinh da day!" << endl;
        return;
    }

    cout << "\nNHAP THONG TIN HOC SINH MOI:\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm

    cout << "Ho va ten: ";
    string name;
    getline(cin, name);
    Hoc_sinh[numStudents].hoten[0] = '\0'; // Xóa dữ liệu cũ (nếu có)
    strcpy(Hoc_sinh[numStudents].hoten, chuanHoaTen(name).c_str()); 
    // hoặc strncpy(Hoc_sinh[numStudents].hoten, chuanHoaTen(name).c_str(), 29);

    cout << "Lop: ";
    cin.getline(Hoc_sinh[numStudents].lop, sizeof(Hoc_sinh[numStudents].lop));
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Xóa bộ đệm sau khi nhập lớp

    cout << "Gioi tinh (1: Nam, 2: Nu): ";
    int genderInput;
    cin >> genderInput;
    Hoc_sinh[numStudents].gender = static_cast<Gender>(genderInput);
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm sau khi nhập giới tính

    cout << "Ngay sinh (dd mm yyyy): ";
    cin >> Hoc_sinh[numStudents].birthday.day 
        >> Hoc_sinh[numStudents].birthday.month
        >> Hoc_sinh[numStudents].birthday.year;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm sau khi nhập ngày sinh

    // Khởi tạo điểm mặc định là 0
    for (int i = 0; i < 12; i++) {
        Hoc_sinh[numStudents].subject[i].subject_name = static_cast<Subject_name>(i + 1); // Gán trực tiếp
        for (int j = 0; j < 4; j++) {
            Hoc_sinh[numStudents].subject[i].score.test_mini[j] = 0;
        }
        for (int j = 0; j < 2; j++) {
            Hoc_sinh[numStudents].subject[i].score.test_45mins[j] = 0;
        }
        Hoc_sinh[numStudents].subject[i].score.mid_term_score = 0;
        Hoc_sinh[numStudents].subject[i].score.end_term_score = 0;
    }

    // Hỏi xem có muốn nhập điểm không
    cout << "Ban co muon nhap diem cho hoc sinh nay khong? (y/n): ";
    char nhapDiem;
    cin >> nhapDiem;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm

    if (tolower(nhapDiem) == 'y') { // Chuyển về chữ thường để so sánh
        while (true) {
            cout << "Chon mon hoc de nhap diem (0 de thoat):\n";
            for (int i = 0; i < 12; i++) {
                cout << i + 1 << ". " << subjectNameToString(static_cast<Subject_name>(i+1)) << endl;
            }
            int monHoc = GetMode("Lua chon Mon Hoc muon nhap diem: ","Mon hoc ban chon la: ",12);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (monHoc == 0) {
                break; // Thoát khỏi vòng lặp nhập điểm
            } else if (monHoc >= 1 && monHoc <= 12) {
                cout << "\nNhap diem cho mon " << subjectNameToString(static_cast<Subject_name>(monHoc)) << ":\n";
                for (int j = 0; j < 4; j++) {
                    cout << "Diem mini test " << j + 1 << ": ";
                    cin >> Hoc_sinh[numStudents].subject[monHoc - 1].score.test_mini[j];
                }
                for (int j = 0; j < 2; j++) {
                    cout << "Diem 45 phut " << j + 1 << ": ";
                    cin >> Hoc_sinh[numStudents].subject[monHoc - 1].score.test_45mins[j];
                }
                cout << "Diem giua ky: ";
                cin >> Hoc_sinh[numStudents].subject[monHoc - 1].score.mid_term_score;
                cout << "Diem cuoi ky: ";
                cin >> Hoc_sinh[numStudents].subject[monHoc - 1].score.end_term_score;
            } else {
                cout << "Lua chon khong hop le!" << endl;
            }
        }
    }
    numStudents++;
    cout << "Da them hoc sinh moi thanh cong!\n";
}
// Hàm ghi dữ liệu cơ bản của học sinh vào file (C++)
void GhiDuLieuCoBan(const string& tenTep) {
    ofstream file(tenTep); // Sử dụng ofstream để ghi file

    if (!file.is_open()) { // Kiểm tra xem file có mở được không
        cerr << "Khong the mo tep " << tenTep << " de ghi!" << endl;
        return;
    }

    file << "STT\tHo va ten\t\tLop\tGioi tinh\tNgay sinh\n";
    for (int i = 0; i < numStudents; i++) {
        file << setw(3) << i + 1 << "\t" 
             << left << setw(25) << Hoc_sinh[i].getHoTen()  // Sử dụng getter
             << left << setw(8) << Hoc_sinh[i].getLop()     // Sử dụng getter
             << setw(9) << (Hoc_sinh[i].getGender() == Male ? "Nam" : "Nu") // Sử dụng getter
             << "\t";

        const Date& birth = Hoc_sinh[i].getBirthday();   // Sử dụng getter
        file << birth.day << "/" << birth.month << "/" << birth.year << endl;
    }

    cout << "Da ghi thong tin co ban cua hoc sinh vao tep " << tenTep << endl;
    file.close(); // Đóng file sau khi ghi
}

// Hàm ghi điểm trung bình của học sinh vào file (C++)
void GhiDiem_TB(const string& tenTep) {
    ofstream file(tenTep); // Sử dụng ofstream để ghi file

    if (!file.is_open()) { // Kiểm tra xem file có mở được không
        cerr << "Khong the mo tep " << tenTep << " de ghi!" << endl;
        return;
    }

    tinhDiem(); // Gọi hàm tinhDiem để cập nhật điểm trước khi ghi

    file << "STT\tHo va ten\t\t";
    for (int i = 0; i < 12; i++) {
        file << subjectNameToString(static_cast<Subject_name>(i+1)) << "\t";
    }
    file << "Tong ket" << endl;

    for (int i = 0; i < numStudents; i++) {
        file << setw(3) << i + 1 << "\t" 
             << left << setw(25) << Hoc_sinh[i].getHoTen() << "\t"; // Sử dụng getter
        
        for (int j = 0; j < 12; j++) {
            float diemTB = Aver(
                Hoc_sinh[i].getSubject(j).score.test_mini, 
                Hoc_sinh[i].getSubject(j).score.test_45mins,
                Hoc_sinh[i].getSubject(j).score.mid_term_score,
                Hoc_sinh[i].getSubject(j).score.end_term_score
            );
            file << fixed << setprecision(1) << diemTB << "\t";
        }

        file << fixed << setprecision(1) << ketQuaHocSinh[i].getDiemTongKet() << endl; // Sử dụng getter
    }

    cout << "Da ghi diem TB cac mon cua hoc sinh vao tep " << tenTep << endl;
    file.close(); // Đóng file sau khi ghi
}

void InPhieuDiemVaoTep(const Student& student) { 
    // Tạo tên file 
    string tenTep = chuanHoaTen(student.getHoTen()) + "_" + student.getLop() + ".txt";
    replace(tenTep.begin(), tenTep.end(), ' ', '_');

    ofstream file(tenTep); // Sử dụng ofstream
    
    if (!file.is_open()) { // Kiểm tra mở file thành công
        cerr << "Khong the mo tep " << tenTep << " de ghi!" << endl;
        return;
    }
    
    // Ghi nội dung phiếu điểm vào file
    file << "\t\tPHIEU BAO DIEM\n";
    file << "\t\t\tHoc ky X - Nam hoc 20XX - 20XX\n\n";

    file << "Ho va ten: " << left << setw(25) << student.getHoTen() << "\t";
    file << "Ngay sinh: " << setw(2) << student.getBirthday().day << "/" 
                       << setw(2) << student.getBirthday().month << "/"
                       << setw(5) << student.getBirthday().year << "\t\n"; 
    file << "Lop: " << student.getLop() << endl; 
    
    file << string(65, '_') << endl;
    file << "|STT|Mon hoc|   Diem mini_test(4)   | Diem 45p(2)| GK | CK | TB |\n";

    float tongDiemTB = 0.0;
    for (int i = 0; i < 12; i++) {
        
        float diemTBMon = Aver(
            student.getSubject(i).score.test_mini, 
            student.getSubject(i).score.test_45mins,
            student.getSubject(i).score.mid_term_score,
            student.getSubject(i).score.end_term_score
        );
        tongDiemTB += diemTBMon;

        file << "|" << setw(3) << i + 1 << "|" 
             << setw(7) << subjectNameToString(student.getSubject(i).subject_name) << "|"; 

        for (int j = 0; j < 4; j++) {
            file << fixed << setprecision(1) << setw(5) << student.getSubject(i).score.test_mini[j]; 
            if (j != 3) file << ", ";
            if (j == 3) file << "|";
        }
        for (int j = 0; j < 2; j++) {
            file << fixed << setprecision(1) << setw(5) << student.getSubject(i).score.test_45mins[j]; 
            if (j != 1) file << ", ";
            if (j == 1) file << "|";
        }
        file << setw(4) << fixed << setprecision(1) << student.getSubject(i).score.mid_term_score << "|" 
             << setw(4) << fixed << setprecision(1) << student.getSubject(i).score.end_term_score << "|"
             << setw(4) << fixed << setprecision(1) << diemTBMon << "|" << endl; 
    }

    float TBC = tongDiemTB / 12;

    string HL, DH;
    if (TBC >= 8.0) {
        HL = "Gioi";
        DH = "HSG";
    } else if (TBC >= 6.5) {
        HL = "Kha";
        DH = "HSK";
    } else if (TBC >= 5.0) {
        HL = "Trung binh";
        DH = "";
    } else {
        HL = "Yeu";
        DH = "";
    }

    file << string(65, '~') << endl << endl;
    file << "Tong ket HK I:\nTBC: " << fixed << setprecision(1) << TBC 
         << "\tHoc luc: " << HL << "\tHanh kiem: Tot" << endl;

    file.close(); // Đóng file sau khi ghi
    cout << "Da in phieu diem vao tep " << tenTep << endl;
    cout << "Nhan Enter de tiep tuc!....\n";
}




#endif 
