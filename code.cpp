#include<iostream>
using namespace std;
int main() {

	const int NUM_YEARS = 51; 
	int population[NUM_YEARS];


	for (int i = 0; i < NUM_YEARS; ++i) {
		cout << "Nhap so luong nguoi sinh cua nam " << 1920 + i << ": " << endl;
		cin >> population[i];
	}
	int count_same_population = 0;
	for (int i = 0; i < NUM_YEARS - 1; ++i) {
		for (int j = i + 1; j < NUM_YEARS; ++j) {
			if (population[i] == population[j]) {
				count_same_population++;
			}
		}
	}

	int max_population = population[0], min_population = population[0];
	int max_year = 1920, min_year = 1920;
	for (int i = 1; i < NUM_YEARS; ++i) {
		if (population[i] > max_population) {
			max_population = population[i];
			max_year = 1920 + i;
		}
		if (population[i] < min_population) {
			min_population = population[i];
			min_year = 1920 + i;
		}
	}

	cout << "So nam co cung so luong nguoi sinh: " << count_same_population << endl;
	cout << "Nam co luong nguoi sinh lon nhat: " << max_year << " (" << max_population << ")" << endl;
	cout << "Nam co luong nguoi sinh nho nhat: " << min_year << " (" << min_population << ")" << endl;



	return 0;

}
