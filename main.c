#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void generate(){
    //tạo tầm 3 thằng
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

void MenuDisplay(){
    printf("Chon chuc nang: \n");
    printf("0. Thoat\n");
    printf("1. Hien thi danh sach diem trung binh: \n");
    /*extend
        1.1 theo tên alphab & reverse
        1.2 theo độ dốc các môn & reverse
        1.3 theo điểm trung bình & reverse
    */ 
    printf("2. Sua diem\n"); 
    /* lựa chọn sửa điểm
    2.1 diem mini test 
    2.2 diem 45p
    2.3 diem giua ki
    2.4 diem cuoi ki
    */ 
    printf("3. Hien thi danh sach theo hoc sinh\n"); // điền tên học sinh muốn tìm
    printf("4. Hien thi danh sach theo mon hoc\n"); // điền tên môn học

}

int main(){
    baomat();
}
