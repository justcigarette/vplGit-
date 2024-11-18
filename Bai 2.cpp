#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct Node {
    string tu;
    int soLanXuatHien;
    Node* next;
};

class DanhSachTu {
public:
    Node* head;

    DanhSachTu() {
        head = nullptr;
    }

    void themTu(const string& tu) {
        Node* newNode = new Node;
        newNode->tu = tu;
        newNode->soLanXuatHien = 1;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current != nullptr) {
                if (current->tu == tu) {
                    current->soLanXuatHien++;
                    delete newNode; 
                    return;
                }
                current = current->next;
            }
            current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    string timTuXuatHienNhieuNhat() {
        if (head == nullptr) {
            return "";
        }

        Node* current = head;
        Node* maxNode = head;

        while (current != nullptr) {
            if (current->soLanXuatHien > maxNode->soLanXuatHien) {
                maxNode = current;
            }
            current = current->next;
        }
        return maxNode->tu;
    }

    void loaiBoTuLay() {
        if (head == nullptr || head->next == nullptr) {
            return; 
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current->next != nullptr) {
            if (current->tu == current->next->tu) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }

    int demSoTu() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

vector<string> tachCauThanhTu(const string& cau) {
    vector<string> tu;
    string word;
    for (char c : cau) {
        if (isalpha(c)) {
            word += tolower(c);
        } else if (!word.empty()) {
            tu.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        tu.push_back(word);
    }
    return tu;
}

int main() {
    string cau;
    cout << "Nhap cau: ";
    getline(cin, cau);

    DanhSachTu danhSachTu;

    vector<string> cacTu = tachCauThanhTu(cau);
    for (const string& tu : cacTu) {
        danhSachTu.themTu(tu);
    }

    string tuXuatHienNhieuNhat = danhSachTu.timTuXuatHienNhieuNhat();
    cout << "Tu xuat hien nhieu nhat: " << tuXuatHienNhieuNhat << endl;

    danhSachTu.loaiBoTuLay();

    int soTu = danhSachTu.demSoTu();
    cout << "So tu trong cau: " << soTu << endl;

    return 0;
}
