#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

int main(){
    baomat();
     Student Hs1 = {
        .name = "Nguyen Van A",
        .class = "10A1",
        .gender = Male,
        .birthday = { .day = 15, .month = 3, .year = 2006 },
        .subject = {
            { .subject_name = Maths, .score = { {8.5, 9.0, 7.5, 8.0}, {7.0, 8.5}, 8.2, 9.0 } },
            { .subject_name = Physics, .score = { {7.0, 6.5, 8.0, 7.2}, {6.8, 7.5}, 7.6, 8.4 } },
        }
    };
    printf("Student's name: %s\n", Hs1.name); 
    getch() ;
    return 0;
}