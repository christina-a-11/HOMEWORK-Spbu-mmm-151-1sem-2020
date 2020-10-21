#include <iostream>
#include <vector>
#include <stack>

using namespace std;
void Menu() {
    cout << "0 - exit the program" << endl;
    cout << "1 - add number to array" << endl;
    cout << "2 - output an array" << endl;
    cout << "3 - find the number of the max element of on array" << endl;
    cout << "4 - find the number of the min element of on array" << endl;
    cout << "5 - alculate the sun of yhe elements" << endl;
    cout << "6 - print the array in reverse order" << endl;
    cout << endl;
}
void Push_number(int n, std::vector<int>& vec) {
    vec.push_back(n);
}
void Output_array(std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int Find_max(std::vector<int>& vec) {
    int number_max = 0;
    int elem_max = vec[0];
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > elem_max) {
            elem_max = vec[i];
            number_max = i;
        }
    }
    return number_max;
}
int Find_min(std::vector<int>& vec) {
    int elem_min = vec[0];
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < elem_min) {
            elem_min = vec[i];
        }
    }
    return elem_min;
}
int Sum_elements(std::vector<int>& vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    return sum;
}
void Output_array_back(std::vector<int>& vec) {
    for (int i = vec.size(); i > -1; i--) {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int main()
{
    Menu();
    int num;
    vector <int> myVec;
    while (1) {
        cin >> num;
        if (num == 0) {
            return 0;
        }
        if (num == 1) {
            int temp;
            cin >> temp;
            Push_number(temp, myVec);
        }
        if (num == 2) {
            Output_array(myVec);
        }
        if (num == 3) {
            cout << Find_max(myVec) << endl;
        }
        if (num == 4) {
            cout << Find_min(myVec) << endl;
        }
        if (num == 5) {
            cout << Sum_elements(myVec) << endl;
        }
        if (num == 6) {
            Output_array_back(myVec);
        }
        Menu();
    }
}
