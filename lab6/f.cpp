#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct student{
    string name;
    string surname;
    double gpa;
};

bool operator<(const student &a, const student &b){
    if(a.gpa != b.gpa) return a.gpa < b.gpa;
    if(a.surname != b.surname) return a.surname < b.surname;
    else return a.name < b.name;
}

bool operator>(const student &a, const student &b){
    return b<a;
}

double grade_transfer(string grade){
    if(grade == "A+") return 4.00;
    if(grade == "A") return 3.75;
    if(grade == "B+") return 3.50;
    if(grade == "B") return 3.00;
    if(grade == "C+") return 2.50;
    if(grade == "C") return 2.00;
    if(grade == "D+") return 1.50;
    if(grade == "D") return 1.00;
    else return 0;
}

int partition(vector<student> &vec, int low, int high) {
    student pivot = vec[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (!(vec[j] > pivot)) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}
 
void quickSort(vector<student> &vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main(){
    int n;
    cin >> n;
    
    vector<student> gpa(n);
    for(int i=0; i<n; i++){
        int total_credit = 0;
        double total_points = 0;

        string name, surname;
        cin >> surname >> name;
        
        int subject_number;
        cin >> subject_number;

        for(int j=0; j<subject_number; j++){
            string grade1;
            int credit;
            cin >> grade1 >> credit;
            total_credit += credit;

            double grade2 = grade_transfer(grade1);
            total_points += grade2 * credit;
        }
        double gpa_score = total_points/(double)total_credit;

        gpa[i].name = name;
        gpa[i].surname = surname;
        gpa[i].gpa = gpa_score;
    }

    quickSort(gpa, 0, gpa.size() - 1);
    
    for(int i=0; i<n; i++){
        cout << fixed << setprecision(3);
        cout << gpa[i].surname << " " << gpa[i].name << " " << gpa[i].gpa << endl; 
    }
    return 0;
}