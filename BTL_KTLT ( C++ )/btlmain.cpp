
#include "general_header.h"

int main() {
    Loi_chao();
    Student student; // Tạo đối tượng student
    student.Tao_data_lop_6A1();

    int backToMainMenu = 0;
    while (true) {
        system("cls"); // Hoặc "clear" nếu bạn dùng Linux/macOS
        Main_Menu_Display();
        int option = GetMode("Chon chuc nang [0-4]", "Ban da chon", 4);

        if (option == 1) {
            while (!backToMainMenu) {
                cout << "\n-----HIEN THI DANH SACH HOC SINH----" << endl;
                Menu_1_Display();
                int sub_Option = GetMode("Chon chuc nang [0-4]", "Ban da chon", 4);

                if (sub_Option == 1) {
                    system("cls");
                    Hien_thi_ds_Hoc_sinh_DiemTB_mon(numStudents);
                } else if (sub_Option == 2) {
                    system("cls");
                    Hien_thi_ds_Hoc_sinh_anpha(numStudents);
                } else if (sub_Option == 3) {
                    system("cls");
                    Hien_thi_ds_Hoc_sinh_theo_DTK(numStudents);
                } else if (sub_Option == 0) {
                    backToMainMenu = 1;
                } else {
                    cout << "Lua chon khong hop le!" << endl;
                }

                if (backToMainMenu) {
                    break; 
                }
            }
            backToMainMenu = 0; // Reset lại cờ backToMainMenu
        } 
        // Hết option 1

        else if (option == 2) {
            while (!backToMainMenu) { 
                cout << "\n-----CHINH SUA DIEM HOC SINH----" << endl;
                Menu_2_Display();
                int sub_Option = GetMode("Chon chuc nang [0-2]", "Ban da chon", 2);

                if (sub_Option == 1) { 
                    Menu_2_1_Display();
                    student.tim_ten_de_sua_diem(Hoc_sinh, numStudents); // Sử dụng phương thức của student
                } else if (sub_Option == 2) {
                    student.tim_hoten_de_sua_diem(Hoc_sinh, numStudents); // Sử dụng phương thức của student
                } else if (sub_Option == 0) {
                    backToMainMenu = 1;
                } else {
                    cout << "Lua chon khong hop le!" << endl;
                }

                if (backToMainMenu) {
                    break;
                }
            }
            backToMainMenu = 0; 
        } 
        // Hết option 2

        else if (option == 3) {
            while (true) {
                system("cls");
                cout << "\n-----HIEN THI DANH SACH HOC SINH----\n";
                hienThiDanhSachHocSinhCoBan(Hoc_sinh, numStudents);

                cout << "\nNhap STT hoc sinh de xem diem chi tiet (0 de quay lai): ";
                int studentIndex;
                cin >> studentIndex;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm '\n'

                if (studentIndex == 0) {
                    break; // Quay lại menu chính
                } else if (studentIndex >= 1 && studentIndex <= numStudents) {
                    inPhieuDiemCaNhan(Hoc_sinh[studentIndex - 1],ketQuaHocSinh[studentIndex - 1], studentIndex);
                    cout << "\nNhan Enter de tiep tuc...";
                    cin.get(); // Chờ người dùng nhấn Enter
                } else {
                    cout << "STT khong hop le!" << endl;
                }
            }
        } 
        // Hết option 3
        else if (option == 4) {
            // Hiển thị danh sách điểm theo từng môn học
            while (!backToMainMenu) {
                cout << "\n-----HIEN THI DANH SACH DIEM MON HOC----\n";
                cout << "Chon mon muon xem diem:\n";
                cout << "0. Thoat\n";
                for (int i = 0; i < 12; i++) {
                    cout << "| " << i + 1 << ". " << subjectNameToString(Hoc_sinh->getSubject(i).subject_name) << endl; // Sử dụng con trỏ và toán tử -> để truy cập thành viên
                }

                int subjectOption = GetMode("Nhap lua chon [0-12]", "Lua chon", 12);
                if (subjectOption > 0 && subjectOption <= 12) {
                    Menu_4_Display();
                    int sub_Option = GetMode("Nhap lua chon [0-4]", "Lua chon", 4);
                    if (sub_Option == 1) {
                        system("cls");
                        Hien_thi_ds_Diem_mon(numStudents, subjectOption - 1);
                    } else if (sub_Option == 2) {
                        system("cls");
                        Hien_thi_ds_Diem_mon_alpha(numStudents, subjectOption - 1);
                    } else if (sub_Option == 3) {
                        system("cls");
                        Hien_thi_ds_Diem_mon_trung_binh(numStudents, subjectOption - 1);
                    } else if (sub_Option == 0) {
                        backToMainMenu = 1;
                    }
                } else if (subjectOption == 0) {
                    backToMainMenu = 1;
                } else {
                    cout << "Lua chon khong hop le!" << endl;
                }

                if (backToMainMenu) {
                    break; // Thoát khỏi vòng lặp menu chính
                }
            }
            backToMainMenu = 0;
        }
        // Hết option 4

        else if (option == 0) {
            cout << "\nThoat chuong trinh!" << endl;
            return 0;
        }
    }
}
