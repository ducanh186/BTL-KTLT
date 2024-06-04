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
    Languege,
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
    char name[20];
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
        printf("\n%s: %d\n",confirm_message, option); // Display the confirmed mode to the user
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
    printf("1. Theo mac dinh\n");
    printf("2. Theo ten alphabet\n");
    printf("3. Theo do doc cac mon\n");
    printf("4. Theo diem tong ket\n");

}

Student Hoc_sinh[MAX_SI_SO];
int numStudents;
int Si_so_lop(){
    return numStudents;
}
void Tao_data(){

        strcpy(Hoc_sinh[0].name , "Nguyen Van A");
        strcpy(Hoc_sinh[0].class , "10A1");
        Hoc_sinh[0].gender = Male;
        
    Student Hs2 = {
    .name = "Tran Thi B",
    .class = "10A2",
    .gender = Female,
    .birthday = { .day = 20, .month = 5, .year = 2006 },
    .subject = {
        { .subject_name = Maths, .score = { {8.0, 8.5, 7.0, 7.5}, {7.5, 8.0}, 7.8, 8.5 } },
        { .subject_name = Physics, .score = { {7.5, 7.0, 8.5, 7.7}, {7.3, 8.0}, 7.9, 8.7 } },
    }
};

Student Hs3 = {
    .name = "Le Van C",
    .class = "10A3",
    .gender = Male,
    .birthday = { .day = 10, .month = 8, .year = 2006 },
    .subject = {
        { .subject_name = Maths, .score = { {9.0, 8.5, 7.5, 8.0}, {8.0, 8.5}, 8.3, 9.1 } },
        { .subject_name = Physics, .score = { {8.0, 7.5, 8.5, 8.2}, {7.8, 8.5}, 8.1, 9.0 } },
    }
};

Student Hs4 = {
    .name = "Pham Thi An",
    .class = "10A4",
    .gender = Female,
    .birthday = { .day = 25, .month = 12, .year = 2006 },
    .subject = {
        { .subject_name = Maths, .score = { {8.5, 9.0, 8.0, 8.5}, {8.0, 9.0}, 8.5, 9.2 } },
        { .subject_name = Physics, .score = { {8.0, 7.5, 8.5, 8.7}, {7.8, 8.5}, 8.2, 9.1 } },
    }
};

}

int main(){
     Tao_data();   
   

    while(1){
    system("cls");// xoa moi thu tren man hinh
    Main_Menu_Display();// goi ra main menu  
    int option=GetMode("Select mode [0-4]", "Mode selected") ; 
     int backToMainMenu = 0;
        if (option == 1) {
            while (!backToMainMenu) { // Vòng lặp menu con
            printf("-----Hien thi danh sach diem trung binh----\n");
            Menu_1_Display();
                int sub_Option = GetMode("Select mode [0-4]", "Mode selected");

                if (sub_Option == 1) {
                    // 
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