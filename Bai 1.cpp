#include <iostream>
#include <string>
#include <ctime>
#include <filesystem>

using namespace std;
using namespace std::filesystem;

struct Node {
    string tenFile;
    string duongDan;
    long long kichThuoc;
    time_t thoiGianTao;
    Node* next;
};

class DanhSachLienKet {
public:
    Node* head;

    DanhSachLienKet() {
        head = nullptr;
    }
    void themNode(const string& tenFile, const string& duongDan, long long kichThuoc, time_t thoiGianTao) {
        Node* newNode = new Node;
        newNode->tenFile = tenFile;
        newNode->duongDan = duongDan;
        newNode->kichThuoc = kichThuoc;
        newNode->thoiGianTao = thoiGianTao;
        newNode->next = nullptr;

        if (head == nullptr || newNode->thoiGianTao < head->thoiGianTao) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->thoiGianTao < newNode->thoiGianTao) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    long long tinhTongKichThuoc() {
        long long tong = 0;
        Node* current = head;
        while (current != nullptr) {
            tong += current->kichThuoc;
            current = current->next;
        }
        return tong;
    }

    void xoaNodeNhoNhat() {
        if (head == nullptr) {
            return; 
        }

        Node* current = head;
        Node* prev = nullptr;
        Node* minNode = head;

        while (current != nullptr) {
            if (current->kichThuoc < minNode->kichThuoc) {
                minNode = current;
                prev = current;
            }
            current = current->next;
        }

        if (minNode == head) {
            head = head->next;
        } else {
            prev->next = minNode->next;
        }

        delete minNode;
    }
    void inDanhSach() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->tenFile << " - " << current->kichThuoc << " bytes" << endl;
            current = current->next;
        }
    }
};


