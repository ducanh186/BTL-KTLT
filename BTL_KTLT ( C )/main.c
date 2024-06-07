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
    Maths=1,
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
Diem ketQuaHocSinh[MAX_SI_SO]; 
const char* subjectNameToString(Subject_name subject) {
    switch (subject) { //// Chuyển đổi Subject_name thành chuỗi
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

float S_Aver(float Arr[],int n){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=Arr[i];
    }
    return sum/n;
}
float Aver(float mini[4],float test45[2], float mid, float end){
    float sum=0;
    sum+=S_Aver(mini,4);
    sum+=S_Aver(test45,2)*2;
    sum+=mid*2;
    sum+=end*3;
    return sum/8;
}
void baomat(){
    char a[20] = "phuhuy12";
    char b[20] = "phuhuy12";
    printf("\nLOG IN(Use the English keyboard to type)\n");
    while(1){
        printf("User name:");
        char tk[20];
        scanf("%s", tk);
        if(strcmp(a, tk)!= 0){
            printf("-(X)-!!Wrong account, please enter again!!\n");
            continue;
        }
        else{
            printf("Password:");
            char mk[20];
            scanf("%s", mk);
            if(strcmp(mk, b)!= 0){
                printf("-(X)-!!Wrong password, please re-enter!!\n");
                continue;
            }
            else{
                break;
            }
        }
    }
}
void Loi_chao(){
    printf("------------------CHAO MUNG BAN DEN VOI HE THONG QUAN LY DAO TAO------------------\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("\nChuc nang chinh: Phan he nhap diem\n");
    printf("\n!!Vui long dang nhap de su dung!!\n");
    baomat();
}
int GetMode(char* input_prompt, char* confirm_message) {
    int option = 0;
    do {
        printf("\n%s: ", input_prompt);
        scanf("%d", &option); // Read the selected mode from the user
        while (getchar() != '\n'); // Clear the input buffer. Input buffer always end with Enter ('\n')
        printf("\n%s: %d\n",confirm_message, option);
     // Display the confirmed mode to the user
    } while(!(option >= 0 && option <= 4)); // Repeat until a valid mode is selected

    return  option;
}
void Main_Menu_Display(){
    printf("Chon chuc nang: \n");
    printf("0. Thoat\n");
    printf("1. Hien thi danh sach diem trung binh \n");
    printf("2. Chinh sua diem\n"); 
    printf("3. Hien thi danh sach theo hoc sinh\n"); // điền tên học sinh muốn tìm
    printf("4. Hien thi danh sach theo mon hoc\n"); // điền tên môn học

}
void Menu_1_Display(){
    printf("Chon chuc nang hien thi: \n");
    printf("0. Quay lai Main Menu\n");
    printf("1. Theo Lop \n");
    printf("2. Theo ten alphabet\n");
    printf("3. Theo do doc cac mon\n");
    printf("4. Theo diem tong ket\n");

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

int numStudents;
int Si_so_lop(){
    return numStudents;
}
void Tao_data_lop_6A1(){
  
     Hoc_sinh[0]=(Student){
        .hoten = "Nguyen Van An",
        .class = "6A1",
        .gender = Male,
        .birthday = { .day = 20, .month = 5, .year = 2006 },
        .subject = {
            { .subject_name = Maths, .score = { {8.0, 8.5, 7.0, 7.5}, {7.5, 8.0}, 7.8, 8.5 } },
            { .subject_name = Physics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Chemistry, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Biology, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Informatics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Literatures, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = History, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Geography, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Language, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Moral_Education, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Technical, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = PE, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
        }
    };
    Hoc_sinh[1]=(Student){
        .hoten = "Tran Thi Bao",
        .class = "6A1",
        .gender = Female,
        .birthday = { .day = 20, .month = 5, .year = 2006 },
        .subject = {
            { .subject_name = Maths, .score = { {8.0, 8.5, 7.0, 7.5}, {7.5, 8.0}, 7.8, 8.5 } },
            { .subject_name = Physics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Chemistry, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Biology, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Informatics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Literatures, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = History, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Geography, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Language, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Moral_Education, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Technical, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = PE, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            
        }
    };
    Hoc_sinh[2]=(Student){
        .hoten = "Le Van Canh",
        .class = "6A1",
        .gender = Male,
        .birthday = { .day = 10, .month = 8, .year = 2006 },
        .subject = {
            { .subject_name = Maths, .score = { {8.0, 8.5, 7.0, 7.5}, {7.5, 8.0}, 7.8, 8.5 } },
            { .subject_name = Physics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Chemistry, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Biology, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Informatics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Literatures, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = History, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Geography, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Language, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Moral_Education, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Technical, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = PE, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
        }
    };

    Hoc_sinh[3]=(Student){
        .hoten = "Pham Thi Dao",
        .class = "6A1",
        .gender = Female,
        .birthday = { .day = 25, .month = 12, .year = 2006 },
        .subject = {
            { .subject_name = Maths, .score = { {8.0, 8.5, 7.0, 7.5}, {7.5, 8.0}, 7.8, 8.5 } },
            { .subject_name = Physics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Chemistry, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Biology, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Informatics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Literatures, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = History, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Geography, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Language, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Moral_Education, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Technical, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = PE, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
        }
    };
    Hoc_sinh[4]=(Student){
        .hoten = "Nguyen Thi Emass",
        .class = "6A1",
        .gender = Female,
        .birthday = { .day = 20, .month = 5, .year = 2006 },
        .subject = {
            { .subject_name = Maths, .score = { {8.0, 8.5, 7.0, 7.5}, {7.5, 8.0}, 7.8, 8.5 } },
            { .subject_name = Physics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Chemistry, .score = { {7.5, 7.0, 8.5, 2.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Biology, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Informatics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Literatures, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = History, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Geography, .score = { {7.5, 7.0, 8.5, 7.7}, {9.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Language, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Moral_Education, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 0.9, 2.7 } },
            { .subject_name = Technical, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = PE, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
        }
    };
    Hoc_sinh[5]=(Student){
        .hoten = "Nguyen Van Anh",
        .class = "6A1",
        .gender = Male,
        .birthday = { .day = 20, .month = 5, .year = 2006 },
        .subject = {
            { .subject_name = Maths, .score = { {8.0, 8.5, 7.0, 7.5}, {7.5, 8.0}, 7.8, 8.5 } },
            { .subject_name = Physics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Chemistry, .score = { {7.5, 7.0, 8.5, 2.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Biology, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Informatics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Literatures, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = History, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Geography, .score = { {7.5, 7.0, 8.5, 7.7}, {9.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Language, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = Moral_Education, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 0.9, 2.7 } },
            { .subject_name = Technical, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
            { .subject_name = PE, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
        }
    };
    numStudents=6;
}
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
void hienThiDiemTongKet(Student list[],int numStudents) {
    tinhDiem(list,numStudents);
    for (int i = 0; i < numStudents; i++) {
        printf("%-4.1f|\n", ketQuaHocSinh[i].diemTongKet);

    }
}
//parameter= tham so => dat ten la para_x :para_Si_so_lop 
void Hien_thi_ds_Hoc_sinh_DiemTB_mon(int para_Si_so_lop ){
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
        printf("|%-4s", subjectNameToString(i + 1)); 
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
int compareNames(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;

    char nameCopy1[50], nameCopy2[50];
    char *firstName1, *middleName1, *lastName1;
    char *firstName2, *middleName2, *lastName2;

    strcpy(nameCopy1, studentA->hoten);
    strcpy(nameCopy2, studentB->hoten);

    splitName(nameCopy1, &firstName1, &middleName1, &lastName1);
    splitName(nameCopy2, &firstName2, &middleName2, &lastName2);

    int cmpLastName = strcmp(lastName1, lastName2);
    if (cmpLastName != 0) return cmpLastName;

    int cmpFirstName = strcmp(firstName1, firstName2);
    if (cmpFirstName != 0) return cmpFirstName;

    return strcmp(middleName1, middleName2);
}
int compareNamesByIndex(const void* a, const void* b) {
    int indexA = *(int*)a;
    int indexB = *(int*)b;
    return compareNames(&Hoc_sinh[indexA], &Hoc_sinh[indexB]);
}

// gọi hàm qsort 
void sort_Students_Alphabetically(Student* list_name, int numStudents) {
    qsort(list_name, numStudents, sizeof(Student), compareNamesByIndex);
}
void Hien_thi_ds_Hoc_sinh_anpha(int para_Si_so_lop ){
        int indices[MAX_SI_SO];
        for (int i = 0; i < numStudents; i++) {
         indices[i] = i;
        }
        qsort(indices, numStudents, sizeof(int), compareNamesByIndex);
        printf("\n");
        char tieude[]="~~~---DANH SACH HOC SINH---~~~";
        printf("%70s\n",tieude);
        int length = 121;
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
        printf("|%-4s", subjectNameToString(i + 1)); 
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
  
    // Không tìm thấy môn học trong danh sách
    printf("Khong tim thay mon hoc co ten %s.\n", subjectNameToString(subject));
}
void editScoreBySubject_mid_score(Student *student, Subject_name subject, float newScore) {
    for (int i = 0; i < 12; i++) {
        if (student->subject[i].subject_name == subject) {
            // Tìm thấy môn học cần sửa điểm
            student->subject[i].score.mid_term_score = newScore;
         
        }
    }
}
void in_diem_hien_tai_cua_1HS(int subjectOption,int index){
    
    printf("\nDiem mon %s hien tai cua %s la:\n",subjectNameToString(Hoc_sinh[index].subject[subjectOption - 1].subject_name)
                                                ,Hoc_sinh[index].hoten);
                                                printf("Diem mini test(4 diem): ");
    for (int i = 0; i < 4; i++)
    {
        printf("%.1f",Hoc_sinh[index].subject->score.test_mini[i]);
        if(i<3) printf(" ,");
    }
    printf("\nDiem kiem tra 45p (2 diem): ");
    for (int i = 0; i < 2; i++)
    {
        printf("%.1f",Hoc_sinh[index].subject->score.test_45mins[i]);
        if (i<1)
        {
            printf(" ,");
        }
    
    }
     printf("\n") ; 
    printf("Diem kiem tra giua ky: %.1f\n",Hoc_sinh[index].subject->score.mid_term_score);
    printf("Diem kiem tra cuoi ky: %.1f\n",Hoc_sinh[index].subject->score.end_term_score);
    //in diem mini
     
    }
    
void chon_mon_va_fix_diem(int index){//Sau khi tim thay 
    printf("Chon mon hoc can chinh sua diem:\n");
        for (int i = 0; i < 12; i++) {
            printf("| %d.%s  ", i + 1, subjectNameToString(Hoc_sinh[index].subject[i].subject_name));
        }
    int subjectOption;
        subjectOption = GetMode("Nhap lua chon[1-12]", "Lua chon");
    in_diem_hien_tai_cua_1HS(subjectOption,index);
    printf("\nChon Diem uon sua:\n");
    printf("1. Diem giua ki\n");
    printf("2. Diem cuoi ki\n");
    int scoreOption;
    scoreOption = GetMode("Nhap lua chon[1-2]", "Lua chon");
// Chỉnh sửa điểm của môn học đã chọn
    float newScore;
    if (scoreOption == 2) {    
    printf("\nNhap diem cuoi ki moi: ");
    scanf("%f", &newScore);
    printf("\n-------Sua diem thanh cong------\n");
    printf("\nDiem cuoi ki da duoc sua: %.1f ==> %.1f\n",
                    Hoc_sinh[index].subject[subjectOption].score.end_term_score,
                    newScore);
    editScoreBySubject_end_term_score(&Hoc_sinh[index], subjectOption, newScore);
    in_diem_hien_tai_cua_1HS(subjectOption,index);

    }
    if (scoreOption==1){
        printf("\nNhap diem giua ki moi: ");
        scanf("%f", &newScore);
        printf("\n-------Sua diem thanh cong------\n");
        printf("Diem giua ki da duoc sua: %.1f ==> %.1f\n",
                    Hoc_sinh[index].subject[subjectOption].score.mid_term_score,
                    newScore);

        editScoreBySubject_mid_score(&Hoc_sinh[index], subjectOption, newScore);
        in_diem_hien_tai_cua_1HS(subjectOption,index);
    }
}
void tim_ten_de_sua_diem(Student* list_name, int numStudents){
    char search_Last_name[30];
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
    printf("SỞ GIÁO DỤC VÀ ĐÀO TẠO XXX\t\t\tCỘNG HÒA XÃ HỘI CHỦ NGHĨA VIỆT NAM\n");
    printf("TRƯỜNG THCS XXX XXXX XXXX\t\t\tĐộc lập - Tự do - Hạnh phúc\n");
    printf("\t\t\t\t\tPHIẾU BÁO ĐIỂM\n");
    printf("\t\t\t\tHọc kỳ X - Năm học XXXX - XXXX\n\n");

    // Thông tin cá nhân
    printf("Họ và tên: %-25s\tNgày sinh: %-10s\tLớp: %s\n", student.hoten, "18/06/2004", student.class);

    // Header bảng điểm (with table formatting)
    
    printf("|STT\t|Môn học\t|");
    for (int j = 1; j <= 4; j++) {
        printf("Điểm %d\t|", j);
    }
    printf("ĐDGK\t|ĐĐCK\t|TB   |\n");
    

    // In điểm từng môn học (with table formatting)
    for (int i = 0; i < 12; i++) {
        printf("|%-2d\t|%-10s\t|", i + 1, subjectNameToString(student.subject[i].subject_name));
        for (int j = 0; j < 4; j++) {
            printf("%.1f\t|", student.subject[i].score.test_mini[j]); 
        }
        printf("%.1f\t|%.1f\t|%.1f |\n", student.subject[i].score.mid_term_score, 
                                        student.subject[i].score.end_term_score, 
                                        diem.diemTrungBinhMonHoc[i]);
       
    }

    printf("\n");
    // Kết quả học kỳ
    printf("Tổng kết HK I\t\t\tTBC: %.1f\tHL: Giỏi\tHK: Tốt\tDH: HSG\tNghỉ CP: 0\tNghỉ KP: 0\n", diem.diemTongKet);
}


    int main(){
   //Loi_chao();
    Tao_data_lop_6A1();   
    while(1){
    system("cls");// xoa moi thu tren man hinh
    Main_Menu_Display();// goi ra main menu  
    int option=GetMode("Select mode [0-4]", "Mode selected") ; 
     int backToMainMenu = 0;
        if (option == 1) {
            while (!backToMainMenu) { // Vòng lặp menu con
            printf("\n-----HIEN THI DANH SACH HOC SINH----\n");
            Menu_1_Display();
                int sub_Option = GetMode("Select mode [0-4]", "Mode selected");
                //co 5 chuc nang
                
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
                    // 3. Theo ....do doc cac mon
                    hienThiDiemTongKet(Hoc_sinh,numStudents);
                } 
                else if (sub_Option == 0) {
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
            int sub_Option = GetMode("Select mode [0-2]", "Mode selected");              
                if (sub_Option == 1) {  //tim theo ten
                Menu_2_1_Display();  
                tim_ten_de_sua_diem (Hoc_sinh, numStudents);
                } else if (sub_Option == 2) {
                    // diem45p
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
                    printf("\nNhan Enter de tiep tuc...");
                    getchar();
                } else {
                    printf("STT khong hop le!\n");
                }
            
        } 
    }
    else if(option==4){
        ///
    }

    else if(option==0){// Exiting the program
        printf("\nExit program!");
        exit(0);
    }



    }// het vong while to
///
     Tao_data_lop_6A1();

    // Tính điểm cho tất cả học sinh
    tinhDiem(Hoc_sinh, numStudents);

    // In ra phiếu điểm từng học sinh
    for (int i = 0; i < numStudents; i++) {
        inPhieuDiemCaNhan(Hoc_sinh[i], ketQuaHocSinh[i], i + 1);
    }
}// het ham main
   


  
