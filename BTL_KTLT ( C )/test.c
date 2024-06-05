#include <stdio.h>
#include <string.h>

// Cấu trúc lưu trữ thông tin của mỗi học sinh
struct Student {
    char fullName[100];
    float diem;
};

// Tách họ tên thành các phần riêng biệt
void splitName(char* fullName, char** firstName, char** middleName, char** lastName) {
    char tempFullName[100];
    strcpy(tempFullName, fullName);  // Sao chép họ tên vào chuỗi tạm

    char* tokens[10];  
    int tokenCount = 0;

    char* token = strtok(tempFullName, " ");
    while (token != NULL) {
        tokens[tokenCount++] = token;
        token = strtok(NULL, " ");
    }

    if (tokenCount >= 3) {
        *firstName = tokens[0];  
        *middleName = tokens[1];  
        *lastName = tokens[tokenCount - 1];  
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

// Tìm kiếm học sinh theo tên (LastName)
int searchByLastName(struct Student danhSach[], int soNguoi, char* searchName) {
    for (int i = 0; i < soNguoi; i++) {
        char *firstName, *middleName, *lastName;
        splitName(danhSach[i].fullName, &firstName, &middleName, &lastName);
        if (strcmp(lastName, searchName) == 0) {
            return i; // Trả về chỉ số của học sinh nếu tìm thấy
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

// Tìm kiếm học sinh theo Họ và tên (FullName)
int searchByFullName(struct Student danhSach[], int soNguoi, char* searchName) {
    for (int i = 0; i < soNguoi; i++) {
        if (strcmp(danhSach[i].fullName, searchName) == 0) {
            return i; // Trả về chỉ số của học sinh nếu tìm thấy
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

// Chỉnh sửa điểm của học sinh
void editDiem(struct Student danhSach[], int index, float newDiem) {
    danhSach[index].diem = newDiem;
}

// In ra màn hình danh sách điểm của học sinh
void printDiem(struct Student danhSach[], int soNguoi) {
    printf("Danh sach diem cua hoc sinh:\n");
    for (int i = 0; i < soNguoi; i++) {
        printf("%s: %.2f\n", danhSach[i].fullName, danhSach[i].diem);
    }
}

int main() {
    // Khởi tạo danh sách học sinh
    struct Student danhSach[] = {
        {"Nguyen Van A", 8.5},
        {"Tran Thi B", 7.8},
        {"Le Hoang C", 9.2}
    };
    int soNguoi = sizeof(danhSach) / sizeof(danhSach[0]);

    // Nhập tên học sinh cần tìm
    char searchName[100];
    printf("Nhap ten hoc sinh can tim: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Loại bỏ ký tự newline

    // Tìm kiếm và chỉnh sửa điểm của học sinh
    int index = searchByLastName(danhSach, soNguoi, searchName);
    if (index != -1) {
        editDiem(danhSach, index, 8.0);
    } else {
        printf("Khong tim thay hoc sinh co ho ten %s.\n", searchName);
    }

    // In ra màn hình danh sách điểm sau khi chỉnh sửa
    printDiem(danhSach, soNguoi);

    return 0;
}
