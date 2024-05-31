#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    printf("1. Hien thi danh sach diem\n");
    /*extend
        1.0 theo mặc định :phú béo
        1.1 theo tên alphab & reverse:Đức Anh
        1.2 theo độ dốc các môn & reverse : Nghiêm
        1.3 theo điểm trung bình & reverse : Phú
    */ 
    printf("2. Sua diem\n"); // PHú
    /* lựa chọn sửa điểm
    2.1 diem mini test 
    2.2 diem 45p
    2.3 diem giua ki
    2.4 diem cuoi ki
    */ 
    printf("3. Hien thi danh sach theo hoc sinh\n"); // điền tên học sinh muốn tìm: Đức Anh
    printf("4. Hien thi danh sach theo mon hoc\n"); // điền tên môn học Nghiêm

}