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
    if(a.gpa!=b.gpa){
        return a.gpa < b.gpa;
    }
    if(a.surname != b.surname){
        return a.surname < b.surname;
    }
    return a.name < b.name;
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

void merge(vector<student> &vec, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<student> L(n1), R(n2);

    for(int i=0; i<n1; i++) L[i] = vec[left + i];
    for(int i=0; i<n2; i++) R[i] = vec[mid + i + 1];

    int i=0, j=0, k = left;

    while(i < n1 && j < n2){
        if(!(L[i] > R[j])){
            vec[k] = L[i];
            i++;
        }
        else{
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        vec[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        vec[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<student> &vec, int left, int right){
    if(left >= right){
        return;
    }
    int mid = left + (right - left)/2;
    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);
    merge(vec, left, mid, right);
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

    merge_sort(gpa, 0, n - 1);
    
    for(int i=0; i<n; i++){
        cout << fixed << setprecision(3);
        cout << gpa[i].surname << " " << gpa[i].name << " " << gpa[i].gpa << endl; 
    }
    return 0;
}