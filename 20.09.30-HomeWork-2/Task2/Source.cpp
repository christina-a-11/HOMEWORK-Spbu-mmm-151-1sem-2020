#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;
void Menu() {
    cout << "0 - exit the program" << endl;
    cout << "1 - add n random numbers from a to b to the array" << endl;
    cout << "2 - to expand the array" << endl;
    cout << "3 - to change the array elements are swapped in pairs" << endl;
    cout << "4 - cyclic right shift by 1" << endl;
    cout << "5 - expand two halves of the array, n- in of the element separating the halves" << endl;
    cout << endl;
}
void Add_rand_number(std::vector<int>& vec, int a, int b, int n) {
    srand(8);
    for (int i = 0; i < n; i++) {
        vec.push_back(a + rand() % b + 1);
    }
}
void Deploy_array(std::vector<int>& vec) {
    for (int i = 0; i < vec.size() / 2; i++) {
        int temp;
        temp = vec[i];
        vec[i] = vec[vec.size() - 1 - i];
        vec[vec.size() - 1 - i] = temp;
    }
}
void Change_pair(std::vector<int>& vec) {
    for (int i = 0; i < (vec.size() / 2) * 2; i += 2) {
        int temp;
        temp = vec[i];
        vec[i] = vec[i + 1];
        vec[i + 1] = temp;
    }
}
void Shift_1(std::vector<int>& vec) {
    int temp = vec[0];
    for (int i = 0; i < vec.size() - 1; i++) {
        vec[i] = vec[i + 1];
    }
    vec[vec.size() - 1] = temp;

}
void Expand_half(std::vector<int>& vec, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp;
        temp = vec[i];
        vec[i] = vec[n - 1 - i];
        vec[n - 1 - i] = temp;
    }

    for (int i = 0; i < (vec.size() - n - 1) / 2; ++i)
    {
        int temp = vec[n + i + 1];
        vec[n + i + 1] = vec[vec.size() - i - 1];
        vec[vec.size() - i - 1] = temp;
    }
}
int main() {
    Menu();
    int num;
    vector <int> myVec;
    while (1) {
        cin >> num;
        if (num == 0) {
            return 0;
        }
        if (num == 1) {
            int a, b, n;
            cin >> n;
            cin >> a;
            cin >> b;
            Add_rand_number(myVec, a, b, n);
        }
        if (num == 2) {
            Deploy_array(myVec);
        }
        if (num == 3) {
            Change_pair(myVec);
        }
        if (num == 4) {
            Shift_1(myVec);
        }
        if (num == 5) {
            int n;
            cin >> n;
            Expand_half(myVec, n);
        }
        Menu();
    }
}
