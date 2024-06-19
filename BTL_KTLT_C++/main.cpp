
#include "general_header.h"

int main() {
    Loi_chao();   // Gọi hàm chào mừng và yêu cầu đăng nhập
    Student student;
    student.Tao_data_lop_6A1();

    int backToMainMenu = 0;
    while (true) {
        system("cls"); // Hoặc "clear" nếu bạn dùng Linux/macOS
        Main_Menu_Display();  
        int option = GetMode("Chon chuc nang [0-6]", "Ban da chon", 6); 

        if (option == 1) {
            // Hiển thị danh sách điểm trung bình
            while (!backToMainMenu) {
                cout << "\n-----HIEN THI DANH SACH HOC SINH----" << endl;
                Menu_1_Display();
                int sub_Option = GetMode("Chon chuc nang [0-3]", "Ban da chon", 3);
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
                    Hien_thi_ds_Hoc_sinh_theo_DTK(numStudents);
                } else if (sub_Option == 0) {
                    backToMainMenu = 1; // Đặt cờ để thoát cả menu con và menu chính
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                if (backToMainMenu) {
                        break; // Thoát khỏi vòng lặp menu chính
                        }
            }
            backToMainMenu = 0; 
        } 
        else if (option == 2) {
            // Chỉnh sửa điểm
            while (!backToMainMenu) {
                cout << "\n-----CHINH SUA DIEM HOC SINH----" << endl;
                Menu_2_Display();
                int sub_Option = GetMode("Chon chuc nang [0-2]", "Ban da chon", 2);

                if (sub_Option == 1) {  
                    Menu_2_1_Display();
                    student.tim_ten_de_sua_diem(Hoc_sinh, numStudents); 
                } else if (sub_Option == 2) {
                    student.tim_hoten_de_sua_diem(Hoc_sinh, numStudents);
                } else if (sub_Option == 0) {
                    backToMainMenu = 1; 
                } else {
                    cout << "Lua chon khong hop le!" << endl;
                }

                if (backToMainMenu) {
                    break; // Thoát khỏi vòng lặp menu chính
                }
            }
            backToMainMenu = 0; // Reset lại cờ backToMainMenu
        }
        else if (option == 3) {
            // Hiển thị danh sách học sinh và in phiếu điểm
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
                    inPhieuDiemCaNhan(Hoc_sinh[studentIndex - 1]); 
                    cout << "\nBan co muon in phieu diem ra tep khong? (y/n): ";
                    char inRaTep;
                    cin >> inRaTep;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    if (tolower(inRaTep) == 'y') {
                        InPhieuDiemVaoTep(Hoc_sinh[studentIndex - 1]);
                    }
                    cout << "\nNhan Enter de tiep tuc...";
                    cin.get(); // Chờ người dùng nhấn Enter
                } else {
                    cout << "STT khong hop le!" << endl;
                }

            }
        } 
        else if (option == 4) {
            // Hiển thị danh sách điểm theo từng môn học
                    while (!backToMainMenu) { // Vòng lặp menu con
            printf("\n-----HIEN THI DANH SACH DIEM MON HOC----\n");
            printf("Chon mon muon xem diem:\n");
            printf("0. Thoat\n");
            for (int i = 0; i < 12; i++) {
            printf("| %d.%s\n", i + 1, subjectNameToString(Hoc_sinh->getSubject(i).subject_name));
        }
        int subjectOption = GetMode("Nhap lua chon[0-12]", "Lua chon",12) ;
        if (subjectOption > 0 && subjectOption <=12) {
            Menu_4_Display();
            int sub_Option = GetMode("Nhap lua chon[0-4]", "Lua chon",4);
            if (sub_Option == 1) {
                system("cls");
                Hien_thi_ds_Diem_mon(numStudents, subjectOption-1);
            }
            else if (sub_Option == 2) {
                system("cls");
                 Hien_thi_ds_Diem_mon_alpha(numStudents, subjectOption-1);
            }
            else if (sub_Option == 3) {
                system("cls");
                Hien_thi_ds_Diem_mon_trung_binh(numStudents, subjectOption-1);
            }
            else if (sub_Option ==0) {
                backToMainMenu = 1; 
            }

        }
        else if (subjectOption == 0) {
            backToMainMenu = 1;
        }
         else {
            printf("Lua chon khong hop le!\n");
        }
        if (backToMainMenu) {
                break; // Thoát khởi vòng lặp menu chính
                }       
    }
     
        } else if (option == 5) {
            cout << "Luu y: \n+ He thong se tu dong chuan hoa ho va ten (VD: liNH-> Linh)\n";
            cout << "+ Khi khong nhap diem hoc sinh, diem mac dinh se la 0" << endl;
            student.ThemHocSinh();
        } else if (option == 6) {
            GhiDuLieuCoBan("du_lieu_co_ban.txt");
            GhiDiem_TB("diem_hoc_sinh.txt");
            cout << "Nhan Enter de tiep tuc!!";
            cin.get();
        } else if (option == 0) { // Exiting the program
            cout << "\nThoat chuong trinh!" << endl;
            cin.get();
            return 0;
        }
    }
}
