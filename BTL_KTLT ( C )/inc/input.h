#ifndef INPUT_H 
#define INPUT_H
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
    double test_mini[4];
    double test_45mins[2];
    double mid_term_score;
    double end_term_score;
};
typedef struct Score Score;
// viết hàm tính điểm trung bình các môn :phú béo
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


void baomat();
void MenuDisplay();
#endif