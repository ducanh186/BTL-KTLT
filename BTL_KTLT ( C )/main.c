#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

struct HoTen {
    char ho[6];
    char ten_dem[12];
    char ten[6];
};
typedef struct HoTen HoTen;

float S_Aver(float Arr[],int n){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=Arr[i];
    }
    return sum/n;
}
float Aver(float mini[4],float test45[2], float mid, float end){
    float sum=0;
    for(int i=0;i<4;i++){
        sum+=mini[i];
    }
    for(int i=0;i<2;i++){
        sum+=test45[i];
    }
    sum+=mid;
    sum+=end;
    return sum/13;
}
struct Score {
    float test_mini[4];
    float test_45mins[2];
    float mid_term_score;
    float end_term_score;
};
typedef struct Score Score;

// viết hàm tính điểm trung bình các môn

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
    HoTen hoten;
    char class[20];
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


void baomat(){
    char a[20] = "phuhuy12";
    char b[20] = "phuhuy12";
    printf("LOG IN(Use the English keyboard to type)\n");
    while(1){
        printf("User name:");
        char tk[20];
        scanf("%s", tk);
        if(strcmp(a, tk)!= 0){
            printf("Wrong account, please enter again.\n");
            continue;
        }
        else{
            printf("Password:");
            char mk[20];
            scanf("%s", mk);
            if(strcmp(mk, b)!= 0){
                printf("Wrong password, please re-enter.\n");
                continue;
            }
            else{
                break;
            }
        }
    }
}
int GetMode(char* input_prompt, char* confirm_message) {
    int option = 0;
    do {
        printf("\n%s: ", input_prompt);
        scanf("%d", &option); // Read the selected mode from the user
        while (getchar() != '\n'); // Clear the input buffer. Input buffer always end with Enter ('\n')
        printf("\n%s: %d\n",confirm_message, option);
        printf("\n") ;// Display the confirmed mode to the user
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

Student Hoc_sinh[MAX_SI_SO];
int numStudents;
int Si_so_lop(){
    return numStudents;
}
void Tao_data_lop_6A1(){
  
     Hoc_sinh[0]=(Student){
        .hoten = {"Nguyen", "Van", "A"},
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
        .hoten = {"Tran", "Thi", "B"},
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
        .hoten = {"Le", "Van", "C"},
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
        .hoten = {"Pham", "Thi", "D"},
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
        .hoten = {"Nguyen", "Thi", "E"},
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
        .hoten = {"Nguyen", "Van", "Binh"},
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
//parameter= tham so => dat ten la para_x :para_Si_so_lop 
void Hien_thi_ds_Hoc_sinh_Theo_lop(int para_Si_so_lop ){
        printf("|STT");
        char name[] = "Ho va Ten";
        printf("|%-26s", name);
        char lop[] ="Lop";
        printf("|%-5s", lop);
        char gender[] = "Gioi Tinh";
        printf("|%-6s",gender);
        char date[] = "Ngay Sinh";
        printf("|%-13s",date);
        for (int i = 0; i < 12; i++) {
        printf("|%-4s", subjectNameToString(i + 1)); // Chuyển đổi Subject_name thành chuỗi
    }
        printf("\n");
    for(int i=0;i<para_Si_so_lop;i++){
        printf("|%-3d",i+1);
        printf("|%-7s%-13s%-6s",Hoc_sinh[i].hoten.ho, Hoc_sinh[i].hoten.ten_dem, Hoc_sinh[i].hoten.ten);// can le tu ben trai sang phai fill 25 ki tu
                // Ten nguoi thuong ko dai qua 25 ki tu
        printf("|%-5s",Hoc_sinh[i].class);
        printf("|%-9s",Hoc_sinh[i].gender==1?"Nam":"Nu");
        printf("| %-2d",Hoc_sinh[i].birthday.day);
        printf("/%-2d",Hoc_sinh[i].birthday.month);
        printf("/%-5d ",Hoc_sinh[i].birthday.year);
        for (int j=0; j<12; j++){
        printf("|%-4.1f", Aver(Hoc_sinh[i].subject[j].score.test_mini,Hoc_sinh[i].subject[j].score.test_45mins,
                                Hoc_sinh[i].subject[j].score.mid_term_score,Hoc_sinh[i].subject[j].score.end_term_score ));
    }
    printf("\n");
}
}

void Sap_xep_hoc_sinh_theo_ten_AZ(Student* ds, int para_Si_so_lop){
    int i,j;
    for (i = 0; i < para_Si_so_lop - 1; i++){
        for (j = para_Si_so_lop - 1; j > i; j--){
            if( strcmp(ds[j].hoten.ten, ds[j-1].hoten.ten) < 0){
                Student sv = ds[j];
                ds[j] = ds[j-1];
                ds[j-1] = sv;
            }
    }
}
}





void Hien_thi_ds_ten_Hoc_sinh(int para_Si_so_lop){
        printf("|STT");
        char name[] = "Ho va Ten";
        printf("|%-20s", name);
}


int main(){
     Tao_data_lop_6A1();   
   

    while(1){
    system("cls");// xoa moi thu tren man hinh
    Main_Menu_Display();// goi ra main menu  
    int option=GetMode("Select mode [0-4]", "Mode selected") ; 
     int backToMainMenu = 0;
        if (option == 1) {
            while (!backToMainMenu) { // Vòng lặp menu con
            printf("\n-----Hien thi danh sach diem trung binh----\n");
            Menu_1_Display();
                int sub_Option = GetMode("Select mode [0-4]", "Mode selected");

                if (sub_Option == 1) {
                    // 1. Theo mac dinh
                    Sap_xep_hoc_sinh_theo_ten_AZ(Hoc_sinh, numStudents);
                    Hien_thi_ds_Hoc_sinh_Theo_lop(numStudents);
                } else if (sub_Option == 2) {
                    // Xử lý sắp xếp điểm trung bình
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
      //.....  
    }
    else if(option==3){
        ///
    }
    else if(option==4){
        ///
    }

    else if(option==0){// Exiting the program
        printf("\nExit program!");
        exit(0);
    }



    }// het vong while to
}// het ham main