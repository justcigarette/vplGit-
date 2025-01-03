#include <iostream>
#include <fstream>
using namespace std;
int main (){
	ofstream outfile ("population.data");
	if(!outfile.is_open()){
		cout << "Khong the mo file" << endl;
		return 1;
	}
	int year, births;
	int n=0;
	cout << "Nhap nam va so nguoi sinh ra (nhap -1 de dung): " << endl;
	while(true){
		cin >> year;
		if (year==-1){
			break;
		}
		cin >> births;
		outfile << year << "   " << births << endl;
		n++;
	}
	
	outfile.close();
	ifstream infile("population.data");
    if (!infile.is_open()) {
        cout << "Khong the mo file" << endl;
        return 1;
    }
    int minYear, maxYear;
    int minBirths = INT_MAX; 
    int maxBirths = INT_MIN; 

    while (infile >> year >> births) {
        if (births < minBirths) {
            minBirths = births;
            minYear = year; 
        }
        if (births > maxBirths) {
            maxBirths = births;
            maxYear = year; 
        }
    }
    infile.close(); 

    cout << "Nam co so nguoi sinh ra lon nhat: " << maxYear << endl;
	cout << "Nam co so nguoi sinh ra nho nhat: " << minYear << endl;

    return 0;
}
