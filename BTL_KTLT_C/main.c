#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SI_SO 100
enum Gender {
    Male=1,
    Female
};
typedef enum Gender Gender;
 struct Date { 
    int day;
    int month;
    int year;
};
typedef struct Date Date; 

struct Score {
    float test_mini[4];
    float test_45mins[2];
    float mid_term_score;
    float end_term_score;
};
typedef struct Score Score;

enum Subject_name {
    Maths=0,
    Physics,
    Chemistry,
    Biology,
    Informatics,
    Literatures,
    History,
    Geography,
    Language,
    Moral_Education,
    Technical,
    PE
};
typedef enum Subject_name Subject_name;

struct Subject {
    Subject_name subject_name;
    Score score;   
};
typedef struct Subject Subject;
 
 struct Student {
    char hoten[30];
    char class[10];
    Gender gender;
    Date birthday;
    Subject subject[12];
};
typedef struct Student Student;

struct Semester {
    int semester_code;
    Date date;
    Student student;
};
typedef struct Semester Semester;

struct Diem {
    float diemTongKet;
    float diemTrungBinhMonHoc[12];
};
typedef struct Diem Diem;
// Mảng chứa điểm của tất cả học sinh
Student Hoc_sinh[MAX_SI_SO];
// Mảng chứa các điểm tổng kết, trung bình môn
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
//hàm tính điểm truung bình minitest và test 45
float S_Aver(float Arr[],int n){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=Arr[i];
    }
    return sum/n;
}
// hàm tính điểm trình bình môn học
float Aver(float mini[4],float test45[2], float mid, float end){
    float sum=0;
    sum+=S_Aver(mini,4);// minitest hệ số 1
    sum+=S_Aver(test45,2)*2;// test 45 hệ số 2
    sum+=mid*2; //midterm test hệ số 2
    sum+=end*3;// finalterm test hệ số 3
    return sum/8;
}
int compareByDiemTongKet(const void* a, const void* b) {
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
// hàm Login tài khoản để dùng hệ thống
void Login(){
    char a[20] = "A+KTLT";
    char b[20] = "A+KTLT";
    printf("\n\t!Dang nhap tai khoan!\n");
    while(1){
        printf("Tai khoan:");
        char tk[20];
        scanf("%s", tk);
        if(strcmp(a, tk)!= 0){
            printf("-(X)-!!Tai khoan nhap sai, vui long nhap lai!!\n");
            continue;
        }
        else{
            printf("Mat khau:");
            char mk[20];
            scanf("%s", mk);
            if(strcmp(mk, b)!= 0){
                printf("-(X)-!!Sai mat khau, vui long nhap lai!!\n");
                continue;
            }
            else{
                break;
            }
        }
    }
}
// hàm nhập lựa chọn
int GetMode(char* input_prompt, char* confirm_message, int max_op) {
    int option = 0;// 0 để exit 
    do {
        printf("\n%s: ", input_prompt);
        scanf("%d", &option); // Read the selected mode from the user
        while (getchar() != '\n'); // Clear the input buffer. Input buffer always end with Enter ('\n')
        printf("\n%s: %d\n",confirm_message, option);
     // Display the confirmed mode to the user
    } while(!(option >= 0 && option <= max_op)); // Repeat until a valid mode is selected

    return  option;
}

void Main_Menu_Display(){
    printf("\t\tCHAO MUNG DEN VOI\n");
    printf("\tHe thong quan ly dao tao truong THCS\n");
    printf("   ~~~Phan he nhap diem cac mon hoc cho hoc sinh~~~\n");
    printf("Nhan \"0\" de thoat trong moi chuc nang\n");
    printf("Chon chuc nang: \n");
    printf("0. Thoat\n");
    printf("1. Hien thi danh sach diem trung binh \n");
    printf("2. Chinh sua diem\n"); 
    printf("3. Hien thi danh sach theo tung hoc sinh\n");
    printf("4. Hien thi danh sach theo tung mon hoc\n"); 
    printf("5. Them 1 hoc sinh\n");
    printf("6. Xuat Du lieu thanh file .txt\n");

}
void Menu_1_Display(){
    printf("Chon chuc nang hien thi: \n");
    printf("0. Quay lai Main Menu\n");
    printf("1. Theo Lop \n");
    printf("2. Theo ten alphabet\n");
    printf("3. Theo diem tong ket\n");

}
void Menu_2_Display(){
    printf("\nCHON CHUC NANG TIM KIEM DE SUA DIEM :\n");
    printf("0. Quay lai Main Menu\n");
    printf("1. Theo ten (Last Name)\n");
    printf("2. Theo Ho va ten (Full Name)\n");
}
void Menu_2_1_Display(){
    printf("Vui long nhap ten (Last Name) hoc sinh can sua diem!!\n");
    printf("Vui long nhap ten khong dau\n");
}
void Menu_4_Display(){
    printf("Chon chuc nang hien thi: \n");
    printf("0. Quay lai Main Menu\n");
    printf("1. Theo Lop \n");
    printf("2. Theo ten alphabet\n");
    printf("3. Theo diem trung binh\n");
}
int numStudents;
void Tao_data_lop_6A1(){
  
     Hoc_sinh[0]=(Student){
        .hoten = "Nguyen Van An",
        .class = "6A1",
        .gender = Male,
        .birthday = { .day = 20, .month = 5, .year = 2013 },
        .subject = {
            { .subject_name = Maths, .score = { {4.0, 5.5, 7.0, 7.5}, {6.5, 8.0}, 7.8, 9.5 } },
            { .subject_name = Physics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 7.7 } },
            { .subject_name = Chemistry, .score = { {5.5, 5.0, 7.5, 7.7}, {3.3, 8.0}, 4.9, 6.7 } },
            { .subject_name = Biology, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 7.7 } },
            { .subject_name = Informatics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 8.9, 6.0 } },
            { .subject_name = Literatures, .score = { {7.5, 6.0, 6.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = History, .score = { {7.5, 7.0, 5.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Geography, .score = { {7.5, 8.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Language, .score = { {3.5, 7.0, 3.5, 5.7}, {7.3, 8.0}, 6.9, 8.7 } },
            { .subject_name = Moral_Education, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 5.7 } },
            { .subject_name = Technical, .score = { {7.5, 4.3, 8.5, 7.7}, {7.3, 8.0}, 8.9, 8.7 } },
            { .subject_name = PE, .score = { {9.5, 7.0, 5.5, 7.7}, {7.3, 8.0}, 5.9, 8.7 } },
        }
    };
    Hoc_sinh[1]=(Student){
        .hoten = "Tran Thi Bao",
        .class = "6A1",
        .gender = Female,
        .birthday = { .day = 15, .month = 4, .year = 2013 },
        .subject = {
            { .subject_name = Maths, .score = { {8.0, 6.5, 6.0, 7.5}, {8.5, 4.0}, 8.8, 8.5 } },
            { .subject_name = Physics, .score = { {7.5, 7.0, 9.5, 7.7}, {7.0, 8.0}, 9.0, 8.7 } },
            { .subject_name = Chemistry, .score = { {7.5, 7.0, 4.5, 7.7}, {7.3, 8.0}, 7.9, 4.7 } },
            { .subject_name = Biology, .score = { {7.5, 7.0, 7.5, 7.7}, {7.3, 8.0}, 8.0, 8.7 } },
            { .subject_name = Informatics, .score = { {7.5, 7.0, 3.5, 7.7}, {7.3, 3.4}, 7.9, 8.7 } },
            { .subject_name = Literatures, .score = { {7.5, 7.0, 7.5, 7.7}, {7.3, 8.0}, 9.9, 8.7 } },
            { .subject_name = History, .score = { {7.5, 7.0, 5.5, 7.7}, {7.3, 8.0}, 5.9, 4.7 } },
            { .subject_name = Geography, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 10.0 } },
            { .subject_name = Language, .score = { {7.5, 7.0, 7.5, 7.7}, {7.3, 8.0}, 7.9, 4.7 } },
            { .subject_name = Moral_Education, .score = { {7.5, 7.0, 8.5, 7.7}, {6.0, 8.0}, 7.9, 7.7 } },
            { .subject_name = Technical, .score = { {7.5, 7.0, 8.5, 7.7}, {7.5, 8.0}, 7.3, 5.7 } },
            { .subject_name = PE, .score = { {7.5, 7.0, 8.5, 7.7}, {6.5, 8.0}, 2.9, 0.7 } },
            
        }
    };
    Hoc_sinh[2]=(Student){
        .hoten = "Le Van Canh",
        .class = "6A1",
        .gender = Male,
        .birthday = { .day = 10, .month = 8, .year = 2013 },
        .subject = {
            { .subject_name = Maths, .score = { {8.0, 1.5, 7.0, 7.5}, {7.5, 8.0}, 7.8, 8.5 } },
            { .subject_name = Physics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 3.5 } },
            { .subject_name = Chemistry, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 3.5 } },
            { .subject_name = Biology, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 3.5 } },
            { .subject_name = Informatics, .score = { {7.5, 7.0, 1.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Literatures, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 9.7 } },
            { .subject_name = History, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 4.7 } },
            { .subject_name = Geography, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 7.7 } },
            { .subject_name = Language, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 7.5 } },
            { .subject_name = Moral_Education, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 4.5 } },
            { .subject_name = Technical, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 3.5 } },
            { .subject_name = PE, .score = { {4.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 5.8 } },
        }
    };

    Hoc_sinh[3]=(Student){
        .hoten = "Pham Thi Dao",
        .class = "6A1",
        .gender = Female,
        .birthday = { .day = 25, .month = 12, .year = 2013 },
        .subject = {
            { .subject_name = Maths, .score = { {8.0, 8.5, 7.0, 8.0}, {1.5, 8.0}, 7.8, 8.5 } },
            { .subject_name = Physics, .score = { {8.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 5.8 } },
            { .subject_name = Chemistry, .score = { {5.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 4.6 } },
            { .subject_name = Biology, .score = { {5.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 6.6 } },
            { .subject_name = Informatics, .score = { {8.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.6 } },
            { .subject_name = Literatures, .score = { {9.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 5.6 } },
            { .subject_name = History, .score = { {7.5, 5.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 9.6 } },
            { .subject_name = Geography, .score = { {1.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 7.6 } },
            { .subject_name = Language, .score = { {9.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Moral_Education, .score = { {8.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 7.9} },
            { .subject_name = Technical, .score = { {4.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 10.0 } },
            { .subject_name = PE, .score = { {6.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
        }
    };
    Hoc_sinh[4]=(Student){
        .hoten = "Nguyen Thi Emass",
        .class = "6A1",
        .gender = Female,
        .birthday = { .day = 20, .month = 5, .year = 2013 },
        .subject = {
            { .subject_name = Maths, .score = { {8.0,9.5, 7.0, 9.5}, {7.5, 8.0}, 7.8, 8.5 } },
            { .subject_name = Physics, .score = { {6.5, 7.0, 6.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Chemistry, .score = { {7.5, 7.0, 9.5, 2.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Biology, .score = { {3.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Informatics, .score = { {4.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Literatures, .score = { {5.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = History, .score = { {6.5, 7.0, 6.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Geography, .score = { {7.5, 7.0, 8.5, 7.7}, {9.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Language, .score = { {7.5, 7.0, 5.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Moral_Education, .score = { {9.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 0.9, 2.7 } },
            { .subject_name = Technical, .score = { {7.5, 7.0, 9.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = PE, .score = { {10.0, 7.0, 6.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
        }
    };
    Hoc_sinh[5]=(Student){
        .hoten = "Nguyen Van Anh",
        .class = "6A1",
        .gender = Male,
        .birthday = { .day = 20, .month = 5, .year = 2013 },
        .subject = {
            { .subject_name = Maths, .score = { {8.0, 10.0, 7.0, 2.0}, {4.8, 8.0}, 7.8, 4.5 } },
            { .subject_name = Physics, .score = { {6.8, 7.0, 4.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Chemistry, .score = { {7.5, 7.0, 8.5, 2.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Biology, .score = { {7.5, 7.0, 6.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Informatics, .score = { {4.6, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Literatures, .score = { {3.4, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = History, .score = { {7.5, 7.0, 5.0, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Geography, .score = { {7.5, 7.0, 8.5, 7.7}, {9.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Language, .score = { {7.5, 7.0, 7.0, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Moral_Education, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 0.9, 2.7 } },
            { .subject_name = Technical, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = PE, .score = { {7.5, 7.0, 7.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
        }
    };
    Hoc_sinh[6]=(Student){
        .hoten = "Le Khanh Duy",
        .class = "6A1",
        .gender = Male,
        .birthday = { .day = 12, .month = 7, .year = 2013 },
        .subject = {
            { .subject_name = Maths, .score = {{8.5, 6, 8.5, 7}, {7.5, 8.0}, 7.8, 8.5}},
            { .subject_name = Physics, .score = {{9.0, 6.0, 7.5, 7.5}, {7.0, 7.5}, 9.0, 6.0}},
            { .subject_name = Chemistry, .score = {{8.0, 7.0, 7.0, 7.5}, {6.0, 6.5}, 8.0, 8.5}},
            { .subject_name = Biology, .score ={{8.0, 8.0, 6.5, 6.5}, {7.3, 8.0}, 7.9, 8.7}},
            { .subject_name = Informatics, .score ={{8.0, 7.0, 7.0, 7.5}, {9.0, 8.5}, 7.5, 6.0}},
            { .subject_name = Literatures, .score ={{8.5, 6.0, 8.5, 8.5}, {6.0, 6.5}, 7.0, 8.5}},
            { .subject_name = History, .score ={{6.0, 7.5, 9.0, 6.0}, {9.0, 7.5}, 7.9, 8.7}},
            { .subject_name = Geography, .score ={{7.5, 7.0, 8.5, 7.7}, {9.3, 8.0}, 7.9, 8.7}},
            { .subject_name = Language, .score ={{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7}},
            { .subject_name = Moral_Education, .score ={{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 0.9, 2.7}},
            { .subject_name = Technical, .score ={{7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7}},
            { .subject_name = PE, .score ={{9.0, 8.0, 9.0, 8.0}, {6.0, 7.5}, 7.5, 6.0}},
        }
    }; 
    numStudents=7;
}
//Tính điểm tổng kết và trung bình môn của toàn bộ học sinh
void tinhDiem(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        ketQuaHocSinh[i].diemTongKet = 0;
        for (int j = 0; j < 12; j++) {
            ketQuaHocSinh[i].diemTrungBinhMonHoc[j] = Aver(students[i].subject[j].score.test_mini,
                                                      students[i].subject[j].score.test_45mins,
                                                      students[i].subject[j].score.mid_term_score,
                                                      students[i].subject[j].score.end_term_score);
            ketQuaHocSinh[i].diemTongKet += ketQuaHocSinh[i].diemTrungBinhMonHoc[j];
            
        }
        ketQuaHocSinh[i].diemTongKet/=12;
    }
}
// Hàm hiện thị cho chức năng 1.1
void Hien_thi_ds_Hoc_sinh_DiemTB_mon(int para_Si_so_lop ){// Hiện thị mặc định theo thứ tự của mảng có sẵn
        tinhDiem(Hoc_sinh,numStudents);
        printf("\n");
        char tieude[]="~~~---DANH SACH HOC SINH---~~~";
        printf("%70s\n",tieude);
        int length = 126;
        for (int i = 0; i < length; i++) {
        printf("_");
        }
        printf("\n");
        printf("|STT");
        char name[] = "Ho va Ten";
        printf("|%-25s", name);
        char lop[] ="Lop";
        printf("|%-5s", lop);
        char gender[] = "Gioi Tinh";
        printf("|%-6s",gender);
        char date[] = "Ngay Sinh";
        printf("|%-13s",date);
        for (int i = 0; i < 12; i++) {//In ten cac mon hoc
        printf("|%-4s", subjectNameToString(i)); 
        }
        printf("|T.K |\n");
    for(int i=0;i<para_Si_so_lop;i++){
        printf("|%-3d",i+1);
        printf("|%-25s",Hoc_sinh[i].hoten);// can le tu ben trai sang phai fill 25 ki tu
                // Ten nguoi thuong ko dai qua 25 ki tu
        printf("|%-5s",Hoc_sinh[i].class);
        printf("|%-9s",Hoc_sinh[i].gender==1?"Nam":"Nu");
        printf("| %-2d",Hoc_sinh[i].birthday.day);
        printf("/%-2d",Hoc_sinh[i].birthday.month);
        printf("/%-5d ",Hoc_sinh[i].birthday.year);
        for (int j=0; j<12; j++){
        printf("|%-4.1f", Aver(Hoc_sinh[i].subject[j].score.test_mini,
                                Hoc_sinh[i].subject[j].score.test_45mins,
                                Hoc_sinh[i].subject[j].score.mid_term_score,
                                Hoc_sinh[i].subject[j].score.end_term_score ));
                }
        printf("|%-4.1f", ketQuaHocSinh[i].diemTongKet);
        printf("|\n");
    }
        printf("$");
        int length_1 = 124;
    for (int i = 0; i < length_1; i++) {
        printf("~");
        }
        printf("$");
}
//Ham tách từng thành phần trong tên
void splitName(char* fullName, char** firstName, char** middleName, char** lastName) {
    char* tokens[10];  // Mảng chứa các từ trong tên
    int tokenCount = 0;
    // Tách tên thành các từ
    char* token = strtok(fullName, " ");
    while (token != NULL) {
        tokens[tokenCount++] = token;
        token = strtok(NULL, " ");
    }
    // Xử lý các phần của tên
    if (tokenCount >= 3) {
        *firstName = tokens[0];  // Họ
        *middleName = tokens[1];  // Tên đệm (trường hợp này chỉ lấy 1 từ đầu tiên của tên đệm)
        *lastName = tokens[tokenCount - 1];  // Tên
    } else if (tokenCount == 2) {
        *firstName = tokens[0];
        *middleName = "";
        *lastName = tokens[1];
    } else {
        *firstName = "";
        *middleName = "";
        *lastName = tokens[0];
    }
}
//So sánh tên theo từng phần 1 để cho vào hàm qsort
int compareNames(const void* a, const void* b) {//hàm so sánh Họ và tên để sắp xếp
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;

    char nameCopy1[50], nameCopy2[50];
    char *firstName1, *middleName1, *lastName1;
    char *firstName2, *middleName2, *lastName2;

    strcpy(nameCopy1, studentA->hoten);
    strcpy(nameCopy2, studentB->hoten);

    splitName(nameCopy1, &firstName1, &middleName1, &lastName1);
    splitName(nameCopy2, &firstName2, &middleName2, &lastName2);

    int cmpLastName = strcmp(lastName1, lastName2);// So sánh tên trước 
    if (cmpLastName != 0) return cmpLastName;// nếu khác nhau thì dừng

    int cmpFirstName = strcmp(firstName1, firstName2);// sau dó so sánh họ
    if (cmpFirstName != 0) return cmpFirstName;

    return strcmp(middleName1, middleName2);
}
int compareNamesByIndex(const void* a, const void* b) {// hàm để sắp xếp theo index của mảng
    int indexA = *(int*)a;
    int indexB = *(int*)b;
    return compareNames(&Hoc_sinh[indexA], &Hoc_sinh[indexB]);
}
// Hiện thị theo thứ tự các alphabet(chức năng 1.2)
void Hien_thi_ds_Hoc_sinh_anpha(int para_Si_so_lop ){
        int indices[MAX_SI_SO];//Tạo mảng tạm để ko làm thay đổi dữ liệu gốc của mảng
        for (int i = 0; i < numStudents; i++) {
         indices[i] = i;
        }
        qsort(indices, numStudents, sizeof(int), compareNamesByIndex);
        
        char tieude[]="~~~---DANH SACH HOC SINH---~~~";
        printf("\n%70s\n",tieude);
        int length = 121;//in ra dòng kẻ
        for (int i = 0; i < length; i++) {
        printf("_");
        }
        printf("\n|STT");
        char name[] = "Ho va Ten";
        printf("|%-25s", name);
        char lop[] ="Lop";
        printf("|%-5s", lop);
        char gender[] = "Gioi Tinh";
        printf("|%-6s",gender);
        char date[] = "Ngay Sinh";
        printf("|%-13s",date);
        for (int i = 0; i < 12; i++) {//In ten cac mon hoc
        printf("|%-4s", subjectNameToString(i)); 
        }
        printf("|\n");
    for(int i=0;i<para_Si_so_lop;i++){
        printf("|%-3d",i+1);
        printf("|%-25s",Hoc_sinh[indices[i]].hoten);// can le tu ben trai sang phai fill 25 ki tu
                // Ten nguoi thuong ko dai qua 25 ki tu
        printf("|%-5s",Hoc_sinh[indices[i]].class);
        printf("|%-9s",Hoc_sinh[indices[i]].gender==1?"Nam":"Nu");
        printf("| %-2d",Hoc_sinh[indices[i]].birthday.day);
        printf("/%-2d",Hoc_sinh[indices[i]].birthday.month);
        printf("/%-5d ",Hoc_sinh[indices[i]].birthday.year);
        for (int j=0; j<12; j++){
        printf("|%-4.1f", Aver(Hoc_sinh[indices[i]].subject[j].score.test_mini,
                                Hoc_sinh[indices[i]].subject[j].score.test_45mins,
                                Hoc_sinh[indices[i]].subject[j].score.mid_term_score,
                                Hoc_sinh[indices[i]].subject[j].score.end_term_score ));
                }
        printf("|\n");
    }
        printf("$");
        int length_1 = 119;
    for (int i = 0; i < length_1; i++) {
        printf("~");
        }
        printf("$");
}
//hết xếp hs theo tên
void Hien_thi_ds_Diem_mon(int para_Si_so_lop, int ten_mon ){
    tinhDiem(Hoc_sinh,numStudents);
        printf("\n");
        printf("~~~---Danh Sach Diem Hoc Sinh Mon %s---~~~\n",subjectNameToString(Hoc_sinh->subject[ten_mon].subject_name));
        int length = 126;
        for (int i = 0; i < length; i++) {
        printf("_");
        }
        printf("\n");
        printf("|STT");
        char name[] = "Ho va Ten";
        printf("|%-25s", name);
        char lop[] ="Lop";
        printf("|%-5s", lop);
        char gender[] = "Gioi Tinh";
        printf("|%-6s",gender);
        printf("|   Diem mini test  ");
        printf("|Diem 45 phut ");
        printf("|Diem giua ki");
        printf("|Diem cuoi ki");
        printf("|Trung Binh|\n");
        for (int i=0;i<para_Si_so_lop;i++){
        printf("|%-3d",i+1);
        printf("|%-25s",Hoc_sinh[i].hoten);// can le tu ben trai sang phai fill 25 ki tu
                // Ten nguoi thuong ko dai qua 25 ki tu
        printf("|%-5s",Hoc_sinh[i].class);
        printf("|%-9s",Hoc_sinh[i].gender==1?"Nam":"Nu");
        for(int j=0; j<4; j++){
            printf("|%-4.1f", Hoc_sinh[i].subject[ten_mon].score.test_mini[j]);
        }
        for(int j=0; j<2; j++){
            printf("|  %-4.1f", Hoc_sinh[i].subject[ten_mon].score.test_45mins[j]);
        }

        printf("|     %-7.1f", Hoc_sinh[i].subject[ten_mon].score.mid_term_score);
        printf("|     %-7.1f", Hoc_sinh[i].subject[ten_mon].score.end_term_score);
        printf("|    %-6.1f", ketQuaHocSinh[i].diemTongKet);
        printf("|\n");
    }
        printf("$");
        int length_1 = 124;
    for (int i = 0; i < length_1; i++) {
        printf("~");
        }
        printf("$");
}
void Hien_thi_ds_Diem_mon_trung_binh(int para_Si_so_lop, int ten_mon ){
    tinhDiem(Hoc_sinh,numStudents);
    int indices[MAX_SI_SO];
        for (int i = 0; i < numStudents; i++) {
         indices[i] = i;
        }
        qsort(indices, numStudents, sizeof(int), compareByDiemTongKet);
        printf("\n");
        printf("~~~---Danh Sach Diem Hoc Sinh Mon %s---~~~\n",subjectNameToString(Hoc_sinh->subject[ten_mon].subject_name));
        int length = 126;
        for (int i = 0; i < length; i++) {
        printf("_");
        }
        printf("\n");
        printf("|STT");
        char name[] = "Ho va Ten";
        printf("|%-25s", name);
        char lop[] ="Lop";
        printf("|%-5s", lop);
        char gender[] = "Gioi Tinh";
        printf("|%-6s",gender);
        printf("|   Diem mini test  ");
        printf("|Diem 45 phut ");
        printf("|Diem giua ki");
        printf("|Diem cuoi ki");
        printf("|Trung Binh|\n");
        for (int i=0;i<para_Si_so_lop;i++){
        printf("|%-3d",i+1);
        printf("|%-25s",Hoc_sinh[indices[i]].hoten);// can le tu ben trai sang phai fill 25 ki tu
                // Ten nguoi thuong ko dai qua 25 ki tu
        printf("|%-5s",Hoc_sinh[indices[i]].class);
        printf("|%-9s",Hoc_sinh[indices[i]].gender==1?"Nam":"Nu");
        for(int j=0; j<4; j++){
            printf("|%-4.1f", Hoc_sinh[indices[i]].subject[ten_mon].score.test_mini[j]);
        }
        for(int j=0; j<2; j++){
            printf("|  %-4.1f", Hoc_sinh[indices[i]].subject[ten_mon].score.test_45mins[j]);
        }

        printf("|     %-7.1f", Hoc_sinh[indices[i]].subject[ten_mon].score.mid_term_score);
        printf("|     %-7.1f", Hoc_sinh[indices[i]].subject[ten_mon].score.end_term_score);
        printf("|    %-6.1f", ketQuaHocSinh[indices[i]].diemTongKet);
        printf("|\n");
    }
        printf("$");
        int length_1 = 124;
    for (int i = 0; i < length_1; i++) {
        printf("~");
        }
        printf("$");
}
void Hien_thi_ds_Hoc_sinh_theo_DTK(int para_Si_so_lop) {
    tinhDiem(Hoc_sinh,numStudents);
    int indices[MAX_SI_SO];
    for (int i = 0; i < numStudents; i++) {
        indices[i] = i;
    }

    // Sắp xếp mảng chỉ mục theo điểm tổng kết
    qsort(indices, numStudents, sizeof(int), compareByDiemTongKet);
        printf("\n");
        char tieude[]="~~~---DANH SACH HOC SINH---~~~";
        printf("%70s\n",tieude);
        int length = 126;
        for (int i = 0; i < length; i++) {
        printf("_");
        }
        printf("\n");
        printf("|STT");
        char name[] = "Ho va Ten";
        printf("|%-25s", name);
        char lop[] ="Lop";
        printf("|%-5s", lop);
        char gender[] = "Gioi Tinh";
        printf("|%-6s",gender);
        char date[] = "Ngay Sinh";
        printf("|%-13s",date);
        for (int i = 0; i < 12; i++) {//In ten cac mon hoc
        printf("|%-4s", subjectNameToString(i)); 
        }
        printf("|T.K |\n");
    for(int i=0;i<para_Si_so_lop;i++){
        printf("|%-3d",i+1);
        printf("|%-25s",Hoc_sinh[indices[i]].hoten);// can le tu ben trai sang phai fill 25 ki tu
                // Ten nguoi thuong ko dai qua 25 ki tu
        printf("|%-5s",Hoc_sinh[indices[i]].class);
        printf("|%-9s",Hoc_sinh[indices[i]].gender==1?"Nam":"Nu");
        printf("| %-2d",Hoc_sinh[indices[i]].birthday.day);
        printf("/%-2d",Hoc_sinh[indices[i]].birthday.month);
        printf("/%-5d ",Hoc_sinh[indices[i]].birthday.year);
        for (int j=0; j<12; j++){
        printf("|%-4.1f", Aver(Hoc_sinh[indices[i]].subject[j].score.test_mini,
                                Hoc_sinh[indices[i]].subject[j].score.test_45mins,
                                Hoc_sinh[indices[i]].subject[j].score.mid_term_score,
                                Hoc_sinh[indices[i]].subject[j].score.end_term_score ));
                }
        printf("|%-4.1f", ketQuaHocSinh[indices[i]].diemTongKet);
        printf("|\n");
    }
        printf("$");
        int length_1 = 124;
    for (int i = 0; i < length_1; i++) {
        printf("~");
        }
        printf("$");
}
void Hien_thi_ds_Diem_mon_alpha(int para_Si_so_lop, int ten_mon ){
    tinhDiem(Hoc_sinh,numStudents);
    int indices[MAX_SI_SO];
        for (int i = 0; i < numStudents; i++) {
         indices[i] = i;
        }
        qsort(indices, numStudents, sizeof(int), compareNamesByIndex);
        printf("\n");
        printf("~~~---Danh Sach Diem Hoc Sinh Mon %s---~~~\n",subjectNameToString(Hoc_sinh->subject[ten_mon].subject_name));
        int length = 126;
        for (int i = 0; i < length; i++) {
        printf("_");
        }
        printf("\n");
        printf("|STT");
        char name[] = "Ho va Ten";
        printf("|%-25s", name);
        char lop[] ="Lop";
        printf("|%-5s", lop);
        char gender[] = "Gioi Tinh";
        printf("|%-6s",gender);
        printf("|   Diem mini test  ");
        printf("|Diem 45 phut ");
        printf("|Diem giua ki");
        printf("|Diem cuoi ki");
        printf("|Trung Binh|\n");
        for (int i=0;i<para_Si_so_lop;i++){
        printf("|%-3d",i+1);
        printf("|%-25s",Hoc_sinh[indices[i]].hoten);// can le tu ben trai sang phai fill 25 ki tu
                // Ten nguoi thuong ko dai qua 25 ki tu
        printf("|%-5s",Hoc_sinh[indices[i]].class);
        printf("|%-9s",Hoc_sinh[indices[i]].gender==1?"Nam":"Nu");
        for(int j=0; j<4; j++){
            printf("|%-4.1f", Hoc_sinh[indices[i]].subject[ten_mon].score.test_mini[j]);
        }
        for(int j=0; j<2; j++){
            printf("|  %-4.1f", Hoc_sinh[indices[i]].subject[ten_mon].score.test_45mins[j]);
        }

        printf("|     %-7.1f", Hoc_sinh[indices[i]].subject[ten_mon].score.mid_term_score);
        printf("|     %-7.1f", Hoc_sinh[indices[i]].subject[ten_mon].score.end_term_score);
        printf("|    %-6.1f", ketQuaHocSinh[indices[i]].diemTongKet);
        printf("|\n");
    }
        printf("$");
        int length_1 = 124;
    for (int i = 0; i < length_1; i++) {
        printf("~");
        }
        printf("$");
}
//Chuc nang 2,
//Hàm này chuẩn hóa từng từ : liNH => Linh
char* chuanHoaTu(char *s){
    s[0] = toupper(s[0]);
    for(int i = 1; i < (int)strlen(s); i++){
        s[i] = tolower(s[i]);
    }
    return s;
}
char *chuanHoaTen(char *s, char *res){
    char *token = strtok(s, " ");
    while(token != NULL){
        //nối từ vào chuỗi kết quả res
        strcat(res, chuanHoaTu(token));
        token = strtok(NULL, " ");
        //Nếu chưa phải từ cuối thì nối thêm dấu cách
        if(token != NULL){
            strcat(res, " ");
        }
    }
    return res;
}
int searchByLastName(Student* danh_Sach, int numStudents, char* searchName) {
    char nameCopy[50];
    
    for (int i = 0; i < numStudents; i++) {
        strcpy(nameCopy,danh_Sach[i].hoten);
        char *firstName, *middleName, *lastName;
        splitName(nameCopy, &firstName, &middleName, &lastName);
        if (strcmp(lastName, searchName) == 0) {
            return i; // Trả về chỉ số của học sinh nếu tìm thấy
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}
// Tìm kiếm học sinh theo Họ và tên (FullName)
int searchByFullName(Student* danhSach, int numStudents, char* searchName) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(danhSach[i].hoten, searchName) == 0) {
            return i; // Trả về chỉ số của học sinh nếu tìm thấy
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

void editScoreBySubject_end_term_score(Student *student, Subject_name subject, float newScore) {
    for (int i = 0; i < 12; i++) {
        if (student->subject[i].subject_name == subject) {
            // Tìm thấy môn học cần sửa điểm
            student->subject[i].score.end_term_score = newScore;
            
        }
    }
}
void editScoreBySubject_mid_score(Student *student, Subject_name subject, float newScore) {
    for (int i = 0; i < 12; i++) {
        if (student->subject[i].subject_name == subject) {
            // Tìm thấy môn học cần sửa điểm
            student->subject[i].score.mid_term_score = newScore;
         
        }
    }
}
void editScoreBySubject_mini_test(Student *student, Subject_name subject, float newScore, int a) {
    for (int i = 0; i < 12; i++) {
        if (student->subject[i].subject_name == subject) {
            // Tìm thấy môn học cần sửa điểm
            student->subject[i].score.test_mini[a] = newScore;
         
        }
    }
}
void editScoreBySubject_test_45mins(Student *student, Subject_name subject, float newScore, int a) {
    for (int i = 0; i < 12; i++) {
        if (student->subject[i].subject_name == subject) {
            // Tìm thấy môn học cần sửa điểm
            student->subject[i].score.test_45mins[a] = newScore;
         
        }
    }
}
void in_diem_hien_tai_cua_1HS(int subjectOption,int index){
    
    printf("\nDiem mon %s hien tai cua %s la:\n",subjectNameToString(Hoc_sinh[index].subject[subjectOption].subject_name)
                                                ,Hoc_sinh[index].hoten);
    printf("Diem mini test(4 diem): ");
    for (int i = 0; i < 4; i++)
    {
        printf("%.1f",Hoc_sinh[index].subject[subjectOption].score.test_mini[i]);
        if(i<3) printf(" ,");
    }
    printf("\nDiem kiem tra 45p (2 diem): ");
    for (int i = 0; i < 2; i++)
    {
        printf("%.1f",Hoc_sinh[index].subject[subjectOption].score.test_45mins[i]);
        if (i<1)
        {
            printf(" ,");
        }
    
    }
     printf("\n") ; 
    printf("Diem kiem tra giua ky: %.1f\n",Hoc_sinh[index].subject[subjectOption].score.mid_term_score);
    printf("Diem kiem tra cuoi ky: %.1f\n",Hoc_sinh[index].subject[subjectOption].score.end_term_score);
    //in diem mini
     
    }
    
void chon_mon_va_fix_diem(int index){//Sau khi tim thay 
    printf("Chon mon hoc can chinh sua diem:\n");
        for (int i = 0; i < 12; i++) {
            printf("| %d.%s  ", i + 1, subjectNameToString(Hoc_sinh[index].subject[i].subject_name));
        }
    int subjectOption;
        subjectOption = GetMode("Nhap lua chon[1-12]", "Lua chon",12);
    in_diem_hien_tai_cua_1HS(subjectOption-1,index);
    printf("\nChon Diem muon sua:\n");
    printf("0. Thoat\n");
    printf("1. Diem mini test\n");
    printf("2. Diem 45 phut\n");
    printf("3. Diem giua ki\n");
    printf("4. Diem cuoi ki\n");
    int scoreOption;
    scoreOption = GetMode("Nhap lua chon[1-4]", "Lua chon",4);
// Chỉnh sửa điểm của môn học đã chọn
    float newScore;
    if (scoreOption==1){
        printf("\nChon diem mini test muon sua:\n ");
        for (int i = 0; i < 4; i++){
            printf("|%d. %-3.1f ",i+1,Hoc_sinh[index].subject[subjectOption-1].score.test_mini[i]);
        }
        int miniTestOption;
        miniTestOption = GetMode("Nhap lua chon[1-4]", "Lua chon",4);
        printf("\nNhap diem mini test moi: ");
        scanf("%f", &newScore);
        printf("\n-------Sua diem thanh cong------\n");
        printf("Diem mini test da duoc sua: %.1f ==> %.1f\n",
                    Hoc_sinh[index].subject[subjectOption-1].score.test_mini[miniTestOption-1],
                    newScore);
        editScoreBySubject_mini_test(&Hoc_sinh[index], subjectOption-1, newScore,miniTestOption-1);
        in_diem_hien_tai_cua_1HS(subjectOption-1,index);
    }
    else if (scoreOption==2){
        printf("\nChon diem 45 phut muon sua:\n ");
        for (int i = 0; i < 2; i++){
            printf("|%d. %-3.1f ",i+1,Hoc_sinh[index].subject[subjectOption].score.test_45mins[i]);
        }
        int BigTestOption;
        BigTestOption = GetMode("Nhap lua chon[1-2]", "Lua chon",2);
        printf("\nNhap diem 45 phut moi: ");
        scanf("%f", &newScore);
        printf("\n-------Sua diem thanh cong------\n");
        printf("Diem mini test da duoc sua: %.1f ==> %.1f\n",
                    Hoc_sinh[index].subject[subjectOption].score.test_45mins[BigTestOption-1],
                    newScore);
        editScoreBySubject_test_45mins(&Hoc_sinh[index], subjectOption, newScore, BigTestOption-1);
        in_diem_hien_tai_cua_1HS(subjectOption,index);
    }
    else if (scoreOption==3){
        printf("\nNhap diem giua ki moi: ");
        scanf("%f", &newScore);
        printf("\n-------Sua diem thanh cong------\n");
        printf("Diem giua ki da duoc sua: %.1f ==> %.1f\n",
                    Hoc_sinh[index].subject[subjectOption-1].score.mid_term_score,
                    newScore);

        editScoreBySubject_mid_score(&Hoc_sinh[index], subjectOption-1, newScore);
        in_diem_hien_tai_cua_1HS(subjectOption-1,index);
    }
    else if (scoreOption == 4) {    
    printf("\nNhap diem cuoi ki moi: ");
    scanf("%f", &newScore);
    printf("\n-------Sua diem thanh cong------\n");
    printf("\nDiem cuoi ki da duoc sua: %.1f ==> %.1f\n",
                    Hoc_sinh[index].subject[subjectOption-1].score.end_term_score,
                    newScore);
    editScoreBySubject_end_term_score(&Hoc_sinh[index], subjectOption-1, newScore);
    in_diem_hien_tai_cua_1HS(subjectOption-1,index);

    } 
    else{
        printf("Khong co lua chon nay. Vui long nhap lai.\n");
    }
}
void tim_ten_de_sua_diem(Student* list_name, int numStudents){
    printf("Luu y: \n+ He thong se tu dong chuan hoa ho va ten (VD: liNH-> Linh)\n");
    char search_Last_name[10];
    printf("Ten can tim: ");
    fgets(search_Last_name, sizeof(search_Last_name), stdin);
    search_Last_name[strcspn(search_Last_name, "\n")] = '\0';
    chuanHoaTu(search_Last_name);
    //ket thuc phan nhap 
    int index = searchByLastName(list_name, numStudents, search_Last_name);

    if (index != -1) {
        printf("\nDa tim thay hoc sinh \"%s !!\"\n",list_name[index].hoten);
        printf("\n");
        chon_mon_va_fix_diem(index);
    } else {
        printf("Khong tim thay hoc sinh co ho ten %s.\n", search_Last_name);
    }
}
void tim_hoten_de_sua_diem(Student* list_name, int numStudents){
    printf("Luu y: \n+ He thong se tu dong chuan hoa ho va ten (VD:ngUYEN liNH-> Nguyen Linh)\n");
    char search_name[30];
    printf("Ten can tim: ");
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = '\0';
    char res[100] = "";
    char *name=chuanHoaTen(search_name,res);
    int index = searchByFullName(list_name, numStudents, name);

    if (index != -1) {
        printf("\nDa tim thay hoc sinh \"%s !!\"\n",list_name[index].hoten);
        printf("\n");
        chon_mon_va_fix_diem(index);
    } else {
        printf("Khong tim thay hoc sinh co ho ten %s.\n", name);
    }
}
// Hàm in ra phiếu điểm cá nhân của học sinh
void hienThiDanhSachHocSinhCoBan(Student list[], int numStudents) {
    printf("\n");
    char tieuDe[] = "~~~---DANH SACH HOC SINH---~~~";
    printf("%40s\n", tieuDe);
    printf("|STT");
    char name[] = "Ho va Ten";
    printf("|%-25s", name);
    char lop[] = "Lop";
    printf("|%-5s", lop);


    char date[] = "  Ngay Sinh";
    printf("|%-12s|\n", date);

    for (int i = 0; i < numStudents; i++) {
        printf("|%-3d", i + 1);
        printf("|%-25s", list[i].hoten);
        printf("|%-5s", list[i].class);
        printf("| %-2d/%-2d/%-5d|\n", list[i].birthday.day, list[i].birthday.month, list[i].birthday.year);
    }
}

void inPhieuDiemCaNhan(Student student, Diem diem, int STT) {
    printf("\n");
    // Tiêu đề phiếu báo điểm
    printf("\t\tPHIEU BAO DIEM\n");
    printf("\t\t\tHoc ky X - Nam hoc 20XX - 20XX\n\n");

    // Thông tin cá nhân (in ngày sinh từ student.birthday)
    printf("Ho va ten: %-25s\tNgay sinh: %-2d/%-2d/%-5d\t\nLop: %s\n", 
           student.hoten, student.birthday.day, student.birthday.month, student.birthday.year, student.class);
    // Header bảng điểm (with table formatting)
    for(int j=1;j<65;j++){
        printf("_");
    }
    printf("\n");
    printf("|STT|Mon hoc|");
    printf("   Diem mini_test(4)  |");
    printf(" Diem 45p(2)|"); // Thêm tiêu đề cho cột điểm 45 phút
    printf(" GK | CK | TB |\n");  
  // In điểm từng môn học và tính điểm trung bình 
    float tongDiemTB = 0.0; 
    for (int i = 0; i < 12; i++) {
        // Tính điểm trung bình môn học bằng hàm Aver
        diem.diemTrungBinhMonHoc[i] = Aver(student.subject[i].score.test_mini,
                                           student.subject[i].score.test_45mins,
                                           student.subject[i].score.mid_term_score,
                                           student.subject[i].score.end_term_score);

        tongDiemTB += diem.diemTrungBinhMonHoc[i];  // Cộng dồn điểm trung bình

        // In điểm từng môn học (sửa đổi)
        printf("|%-3d| %-6s|", i + 1, subjectNameToString(student.subject[i].subject_name));
        for (int j = 0; j < 4; j++) {
            printf("%4.1f", student.subject[i].score.test_mini[j]); 
            if(j!=3) printf(", ");
            if(j==3) printf("|");
        }
        // Thêm phần in điểm 45 phút
        for (int j = 0; j < 2; j++) {  // Vòng lặp để in 2 điểm 45 phút
            printf(" %4.1f", student.subject[i].score.test_45mins[j]);
            if(j!=1) printf(", ");
            if(j==1) printf("|");
        }

        printf("%4.1f|%4.1f|%4.1f|\n", student.subject[i].score.mid_term_score, 
                                        student.subject[i].score.end_term_score, 
                                        diem.diemTrungBinhMonHoc[i]);
    }

    // Tính TBC (trung bình cộng các điểm TB môn học) bằng hàm S_Aver
    float TBC = S_Aver(diem.diemTrungBinhMonHoc, 12);

    // Xác định HL và DH dựa trên TBC (giữ nguyên)
    char HL[15];
    char DH[15];
    if (TBC >= 8.0) {
        strcpy(HL, "Gioi");
        strcpy(DH, "HSG");
    } else if (TBC >= 6.5) {
        strcpy(HL, "Kha");
        strcpy(DH, "HSK");
    } else if (TBC >= 5.0) {
        strcpy(HL, "Trung binh");
        strcpy(DH, ""); // Để trống DH
    } else {
        strcpy(HL, "Yeu");
        strcpy(DH, "");
    }
    for(int j=1;j<65;j++){
        printf("~");
    }
    printf("\n");
    printf("\n");
    // Kết quả học kỳ
    printf("Tong ket HK I:\nTBC: %.1f\tHoc luc: %s\tHanh kiem: Tot\n", TBC, HL);
}
void ThemHocSinh() {
    if (numStudents >= MAX_SI_SO) {
        printf("Danh sach hoc sinh da day!\n");
        return;
    }
    
    printf("\nNHAP THONG TIN HOC SINH MOI:\n");
    printf("Ho va ten: ");
    char name[30];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; 
    char res[100] = "";
    strcpy(Hoc_sinh[numStudents].hoten,chuanHoaTen(name,res));// Chuẩn hóa tên đầu vào 
    printf("Lop: ");
    scanf("%s", Hoc_sinh[numStudents].class);
    while (getchar() != '\n'); // Xóa bộ đệm sau khi nhập lớp

    printf("Gioi tinh (1: Nam, 2: Nu): ");
    scanf("%d", &(Hoc_sinh[numStudents].gender));
    while (getchar() != '\n'); // Xóa bộ đệm sau khi nhập giới tính

    printf("Ngay sinh (dd mm yyyy): ");
    scanf("%d %d %d", &Hoc_sinh[numStudents].birthday.day, 
          &Hoc_sinh[numStudents].birthday.month, &Hoc_sinh[numStudents].birthday.year);
    while (getchar() != '\n'); // Xóa bộ đệm sau khi nhập ngày sinh

    // Khởi tạo điểm mặc định là 0
    for (int i = 0; i < 12; i++) {
        Hoc_sinh[numStudents].subject[i].subject_name = i;
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
    printf("Ban co muon nhap diem cho hoc sinh nay khong? (y/n): ");
    char nhapDiem;
    scanf("%c", &nhapDiem);
    while (getchar() != '\n'); // Xóa bộ đệm

    if (tolower(nhapDiem) == 'y') { // Chuyển về chữ thường để so sánh
        while (1) {
            printf("Chon mon hoc de nhap diem (0 de thoat):\n");
            for (int i = 0; i < 12; i++) {
                printf("%d. %s\n", i + 1, subjectNameToString(i));
            }

            int monHoc=GetMode("Lua chon Mon Hoc muon nhap diem: ","Mon hoc ban chon la: ",12);
            while (getchar() != '\n'); // Xóa bộ đệm

            if (monHoc == 0) {
                break;
            } else if (monHoc >= 1 && monHoc <= 12) {
                printf("\nNhap diem cho mon %s:\n", subjectNameToString(monHoc - 1));
                for (int j = 0; j < 4; j++) {
                    printf("Diem mini test %d: ", j + 1);
                    scanf("%f", &Hoc_sinh[numStudents].subject[monHoc - 1].score.test_mini[j]);
                }
                for (int j = 0; j < 2; j++) {
                    printf("Diem 45 phut %d: ", j + 1);
                    scanf("%f", &Hoc_sinh[numStudents].subject[monHoc - 1].score.test_45mins[j]);
                }
                printf("Diem giua ky: ");
                scanf("%f", &Hoc_sinh[numStudents].subject[monHoc - 1].score.mid_term_score);
                printf("Diem cuoi ky: ");
                scanf("%f", &Hoc_sinh[numStudents].subject[monHoc - 1].score.end_term_score);
            } else {
                printf("Lua chon khong hop le!\n");
            }
        }
    }
    numStudents++;
    printf("Da them hoc sinh moi thanh cong!\n");
}
void GhiDuLieuCoBan(const char *tenTep) {
    FILE *f = fopen(tenTep, "w");
    if (f == NULL) {
        printf("Khong the mo tep %s de ghi!\n", tenTep);
        return;
    }
    fprintf(f, "STT\tHo va ten\t\tLop\tGioi tinh\tNgay sinh\n");
    for (int i = 0; i < numStudents; i++) {
        fprintf(f, "%d\t%-25s\t%-5s\t%-9s\t%d/%d/%d\n", 
                i + 1, Hoc_sinh[i].hoten, Hoc_sinh[i].class, 
                (Hoc_sinh[i].gender == Male) ? "Nam" : "Nu",
                Hoc_sinh[i].birthday.day, Hoc_sinh[i].birthday.month, Hoc_sinh[i].birthday.year);
    }
    
    printf("Da ghi thong tin co ban cua hoc sinh vao tep %s\n", tenTep);
    fclose(f);
}
void GhiDiem_TB(const char *tenTep) {
    FILE *f = fopen(tenTep, "w");
    if (f == NULL) {
        printf("Khong the mo tep %s de ghi!\n", tenTep);
        return;
    }
    tinhDiem(Hoc_sinh,numStudents);
    fprintf(f, "STT\tHo va ten\t\t");
    for (int i = 0; i < 12; i++) {
        fprintf(f, "%s\t", subjectNameToString(i));
    }
    fprintf(f, "Tong ket\n");

    for (int i = 0; i < numStudents; i++) {
        fprintf(f, "%d\t%-25s\t", i + 1, Hoc_sinh[i].hoten);
        for (int j = 0; j < 12; j++) {
            float diemTB = Aver(Hoc_sinh[i].subject[j].score.test_mini,
                                Hoc_sinh[i].subject[j].score.test_45mins,
                                Hoc_sinh[i].subject[j].score.mid_term_score,
                                Hoc_sinh[i].subject[j].score.end_term_score);
            fprintf(f, "%.1f\t", diemTB);
        }
        fprintf(f, "%.1f\n", ketQuaHocSinh[i].diemTongKet); 
    }
    
    printf("Da ghi diem TB cac mon cua hoc sinh vao tep %s\n", tenTep);
    fclose(f);
}
void InPhieuDiemVaoTep(Student student, Diem diem, int STT ) {
    char tenTep[50]; // Tạo một mảng để chứa tên tệp

    // Tạo tên tệp dựa trên họ tên và lớp của học sinh (có gạch dưới ngăn cách)
    sprintf(tenTep, "%s_%s.txt", student.hoten, student.class);
    // Thay thế khoảng trắng bằng dấu gạch dưới
    for (char *p = tenTep; *p; p++) {
        if (*p == ' ') *p = '_';
    }
    FILE *f = fopen(tenTep, "w");
    if (f == NULL) {
        printf("Khong the mo tep %s de ghi!\n", tenTep);
        return;
    }

    fprintf(f, "\t\tPHIEU BAO DIEM\n");
    fprintf(f, "\t\t\tHoc ky X - Nam hoc 20XX - 20XX\n\n");

    fprintf(f, "Ho va ten: %-25s\tNgay sinh: %-2d/%-2d/%-5d\t\nLop: %s\n", 
            student.hoten, student.birthday.day, student.birthday.month, student.birthday.year, student.class);

    for (int j = 1; j < 65; j++) {
        fprintf(f, "_");
    }
    fprintf(f, "\n");
    fprintf(f, "|STT|Mon hoc|   Diem mini_test(4)  | Diem 45p(2)| GK | CK | TB |\n");

    float tongDiemTB = 0.0;
    for (int i = 0; i < 12; i++) {
        diem.diemTrungBinhMonHoc[i] = Aver(student.subject[i].score.test_mini,
                                          student.subject[i].score.test_45mins,
                                          student.subject[i].score.mid_term_score,
                                          student.subject[i].score.end_term_score);
        tongDiemTB += diem.diemTrungBinhMonHoc[i];

        fprintf(f, "|%-3d| %-6s|", i + 1, subjectNameToString(student.subject[i].subject_name));
        for (int j = 0; j < 4; j++) {
            fprintf(f, "%4.1f", student.subject[i].score.test_mini[j]);
            if (j != 3) fprintf(f, ", ");
            if (j == 3) fprintf(f, "|");
        }
        for (int j = 0; j < 2; j++) {
            fprintf(f, " %4.1f", student.subject[i].score.test_45mins[j]);
            if (j != 1) fprintf(f, ", ");
            if (j == 1) fprintf(f, "|");
        }
        fprintf(f, "%4.1f|%4.1f|%4.1f|\n", student.subject[i].score.mid_term_score,
                student.subject[i].score.end_term_score, diem.diemTrungBinhMonHoc[i]);
    }

    float TBC = S_Aver(diem.diemTrungBinhMonHoc, 12);

    char HL[15];
    char DH[15];
    if (TBC >= 8.0) {
        strcpy(HL, "Gioi");
        strcpy(DH, "HSG");
    } else if (TBC >= 6.5) {
        strcpy(HL, "Kha");
        strcpy(DH, "HSK");
    } else if (TBC >= 5.0) {
        strcpy(HL, "Trung binh");
        strcpy(DH, "");
    } else {
        strcpy(HL, "Yeu");
        strcpy(DH, "");
    }

    for (int j = 1; j < 65; j++) {
        fprintf(f, "~");
    }
    fprintf(f, "\n\n");
    fprintf(f, "Tong ket HK I:\nTBC: %.1f\tHoc luc: %s\tHanh kiem: Tot\n", TBC, HL);

    fclose(f);
    printf("Da in phieu diem vao tep %s\n", tenTep);
    printf("Nhan Enter de tiep tuc!....\n");
}

int main(){
    Login();
    Tao_data_lop_6A1();      
    while(1){
    system("cls");// xoa moi thu tren man hinh
    Main_Menu_Display();// goi ra main menu  
    int option=GetMode("Select mode [0-6]", "Mode selected",6) ; 
     int backToMainMenu = 0;
        if (option == 1) {
            while (!backToMainMenu) { // Vòng lặp menu con
            printf("\n-----HIEN THI DANH SACH HOC SINH----\n");
            Menu_1_Display();
                int sub_Option = GetMode("Select mode [0-3]", "Mode selected",3);                              
                if (sub_Option == 1) {
                    system("cls");
                    // 1. Theo lop    
                    // Hien tai chi co 1 lop              
                    Hien_thi_ds_Hoc_sinh_DiemTB_mon(numStudents);
                } else if (sub_Option == 2) {
                    // 2. Theo Ten
                    system("cls");                   
                    Hien_thi_ds_Hoc_sinh_anpha(numStudents);
                } else if(sub_Option==3){               
                    Hien_thi_ds_Hoc_sinh_theo_DTK(numStudents);
                } else if (sub_Option == 0) {
                    backToMainMenu = 1; // Đặt cờ để thoát cả menu con và menu chính
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                if (backToMainMenu) {
                        break; // Thoát khỏi vòng lặp menu chính
                        }
            }
        }//het op=1
    else if(option==2){
       while (!backToMainMenu) { // Vòng lặp menu con
            printf("\n-----CHINH SUA DIEM HOC SINH----\n");
            Menu_2_Display();
            int sub_Option = GetMode("Select mode [0-2]", "Mode selected",2);              
                if (sub_Option == 1) {  //tim theo ten
                Menu_2_1_Display();  
                tim_ten_de_sua_diem (Hoc_sinh, numStudents);
                } else if (sub_Option == 2) {
                tim_hoten_de_sua_diem (Hoc_sinh, numStudents);
                } else if (sub_Option == 0) {
                    backToMainMenu = 1; // Đặt cờ để thoát cả menu con và menu chính
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                if (backToMainMenu) {
                        break; // Thoát khỏi vòng lặp menu chính
                        }
            }
    }
    else if(option==3){
         while (1) {
                system("cls");
                printf("\n-----HIEN THI DANH SACH HOC SINH----\n");
                hienThiDanhSachHocSinhCoBan(Hoc_sinh, numStudents); 

                // Nhập STT học sinh để xem điểm chi tiết
                printf("\nNhap STT hoc sinh de xem diem chi tiet (0 de quay lai): ");
                int studentIndex;
                scanf("%d", &studentIndex);
                while (getchar() != '\n'); // clear input buffer

                if (studentIndex == 0) {
                    break; // Quay lại menu chính
                } else if (studentIndex >= 1 && studentIndex <= numStudents) {
                    inPhieuDiemCaNhan(Hoc_sinh[studentIndex - 1], ketQuaHocSinh[studentIndex - 1], studentIndex);
                    printf("\nBan co muon in phieu diem ra tep khong? (y/n): ");
                    char inRaTep;
                    scanf("%c", &inRaTep);
                    while (getchar() != '\n'); // clear input buffer

                    if (tolower(inRaTep) == 'y') {
                    
                    InPhieuDiemVaoTep(Hoc_sinh[studentIndex - 1], 
                    ketQuaHocSinh[studentIndex - 1], studentIndex);
                    }
                    getchar();
                    printf("\nNhan Enter de tiep tuc...");
                    
                } else {
                    printf("STT khong hop le!\n");
                }
            
        } 
    }
    else if(option==4){
        //Hiển thị danh sách điểm theo từng môn học
        while (!backToMainMenu) { // Vòng lặp menu con
            printf("\n-----HIEN THI DANH SACH DIEM MON HOC----\n");
            printf("Chon mon muon xem diem:\n");
            printf("0. Thoat\n");
            for (int i = 0; i < 12; i++) {
            printf("| %d.%s\n", i + 1, subjectNameToString(Hoc_sinh->subject[i].subject_name));
        }
        int subjectOption = GetMode("Nhap lua chon[0-12]", "Lua chon",12) ;
        if (subjectOption > 0 && subjectOption <=12) {
            Menu_4_Display();
            int sub_Option = GetMode("Nhap lua chon[0-4]", "Lua chon",4);
            if (sub_Option == 1) {
                system("cls");
                Hien_thi_ds_Diem_mon(numStudents, subjectOption-1);
            }
            else if (sub_Option == 2) {
                system("cls");
                 Hien_thi_ds_Diem_mon_alpha(numStudents, subjectOption-1);
            }
            else if (sub_Option == 3) {
                system("cls");
                Hien_thi_ds_Diem_mon_trung_binh(numStudents, subjectOption-1);
            }
            else if (sub_Option ==0) {
                backToMainMenu = 1; 
            }

        }
        else if (subjectOption == 0) {
            backToMainMenu = 1;
        }
         else {
            printf("Lua chon khong hop le!\n");
        }
        if (backToMainMenu) {
                break; // Thoát khởi vòng lặp menu chính
                }       
    }
    }else if (option == 5) {
    printf("Luu y: \n+ He thong se tu dong chuan hoa ho va ten (VD: liNH-> Linh)\n");
    printf("+ Khi khong nhap diem hoc sinh, diem mac dinh se la 0");
    ThemHocSinh();
    }else if (option == 6) {
    GhiDuLieuCoBan("du_lieu_co_ban.txt");
    GhiDiem_TB("diem_hoc_sinh.txt");
    printf("Nhan Enter de tiep tuc!!");
    getchar();
    }else if(option==0){// Exiting the program
        printf("\nExit program!");
        getchar();
        exit(0);
    } 
   }
}
