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
    float test_mini; //tạo sau
    float test_45mins;// tạo sau
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
    Gender Gender;
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



void MenuDisplay(){
    printf("Chon chuc nang: \n");
    printf("0. Thoat\n");
    printf("1. Hien thi danh sach diem: \n");
    printf("2. Them diem\n");
    printf("3. Xoa diem\n");
    printf("4. Sua diem\n");
    printf("5. \n");
    printf("6. Tim kiem mon hoc\n");
}

int main(){

    Student nihonjin;
    nihonjin.subject[0].subject_name = Maths;
    nihonjin.subject[0].score.test_mini = 0;
    nihonjin.subject[0].score.test_45mins = 0;
    nihonjin.subject[0].score.mid_term_score = 0;
    nihonjin.subject[0].score.end_term_score = 0;
    printf("%d ",nihonjin.subject[0].subject_name);
}
