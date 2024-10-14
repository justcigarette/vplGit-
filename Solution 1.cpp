#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sortColors(vector<string>& colors) {
    int low = 0;           
    int mid = 0;           
    int high = colors.size() - 1;  

    while (mid <= high) {
        if (colors[mid] == "do") {
            swap(colors[low], colors[mid]);
            low++;
            mid++;
        } else if (colors[mid] == "trang") {
            mid++;
        } else if (colors[mid] == "xanh") {
            swap(colors[mid], colors[high]);
            high--;  
        }
    }
}

int main() {

    vector<string> colors = {"xanh", "do", "xanh", "do", "do", "trang", "do", "xanh", "trang"};
    
    sortColors(colors);
    
    cout << "Ket qua sau khi sap xep: ";
    for (const string& color : colors) {
        cout << color << " ";
    }
    cout << endl;

    return 0;
}

