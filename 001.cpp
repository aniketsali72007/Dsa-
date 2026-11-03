#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Student {
int id;
string name;
float cgpa;
};
// 1. Bubble Sort by Name
void sortByName(Student arr[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (arr[j].name > arr[j + 1].name) {
swap(arr[j], arr[j + 1]);
}
}
}
}
// 2. Selection Sort by CGPA (Descending)
void sortByCGPA(Student arr[], int n) {
for (int i = 0; i < n - 1; i++) {
int maxIdx = i;
for (int j = i + 1; j < n; j++) {
if (arr[j].cgpa > arr[maxIdx].cgpa) maxIdx = j;
}
swap(arr[i], arr[maxIdx]);
}
}
// 3. Linear Search
int linearSearch(Student arr[], int n, int targetId) {
for (int i = 0; i < n; i++) {
if (arr[i].id == targetId) return i;
}
return -1;
}
int main() {
int n = 3;
// Using an array of size 3 for simple demonstration
Student db[3] = {
{103, "Alice", 3.8},
{101, "Charlie", 3.5},
{102, "Bob", 3.9}
};
cout << "--- Initial Database ---\n";
for(int i=0; i<n; i++) cout << db[i].id << " | " << db[i].name << " | " << db[i].cgpa << "\n";
// Sort and Display by Name
sortByName(db, n);
cout << "\n--- Sorted Alphabetically by Name ---\n";
for(int i=0; i<n; i++) cout << db[i].name << " (ID: " << db[i].id << ")\n";
// Sort and Display by CGPA
sortByCGPA(db, n);
cout << "\n--- Sorted by Highest CGPA ---\n";
for(int i=0; i<n; i++) cout << db[i].name << " : " << db[i].cgpa << "\n";
// Search Demonstration
int target = 102;
int index = linearSearch(db, n, target);
cout << "\n--- Search Result for ID " << target << " ---\n";
if(index != -1) cout << "Found! Name: " << db[index].name << ", CGPA: " << db[index].cgpa << "\n";
else cout << "Not Found\n";
return 0;
}