#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std; 

void counter(const vector<int>& arr, int index, int n);

int main() {
    int num;
    string holder;
    bool valid = false;

    while (!valid) {
        cout << "Enter the number of elements in the array: ";
        cin >> holder;

        if (holder.empty() || !all_of(holder.begin(), holder.end(), ::isdigit)) {
            cout << "Please enter an integer only.\n" << endl;
            valid = false;
        }
        else
            valid = true;
    }

    num = stoi(holder);

    system("CLS");
    cout << "Enter the number of elements in the array: " << num << endl;

    vector<int> arr(num);

    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < num; ++i) {
        cin >> arr[i];
    }

    cout << endl;
    counter(arr, 0, num);
  
    return 0;
}

void counter(const vector<int>& arr, int index, int n) {
    if (index >= n) {
        return;
    }

    int count = 1;
    while (index + 1 < n && arr[index] == arr[index + 1]) {
        count++;
        index++;
    }

    cout << arr[index] << " appears " << count << " time(s).\n"; 

    counter(arr, index + 1, n);
}