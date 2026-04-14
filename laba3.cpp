#include <iostream>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    vector<int> v1 = {1, 2, 3, 4, 5};
    int sum = accumulate(v1.begin(), v1.end(), 0);
    cout << "1. Сумма элементов: " << sum << endl;

    vector<int> v2;
    for (int x : v1)
        v2.push_back(x * x - 1);
    cout << "2. Новый вектор (x^2 - 1): ";
    for (int x : v2) cout << x << " ";
    cout << endl;

    vector<int> v3 = {10, 20, 30, 40};
    v3.insert(v3.begin(), 5);
    v3.push_back(50);
    v3.erase(v3.begin() + 1);
    cout << "3. После вставок и удаления: ";
    for (int x : v3) cout << x << " ";
    cout << endl;

    vector<int> v4;
    if (v4.empty()) {
        v4.push_back(7);
        v4.push_back(8);
        v4.push_back(9);
    } else {
        v4.assign(10, 0);
    }
    cout << "4. Вектор после проверки на пустоту: ";
    for (int x : v4) cout << x << " ";
    cout << endl;

    vector<char> v5 = {'H', 'e', 'l', 'l', 'o'};
    string str(v5.begin(), v5.end());
    cout << "5. Строка из вектора символов: " << str << endl;

    string s = "World";
    vector<char> v6(s.begin(), s.end());
    cout << "6. Вектор из строки: ";
    for (char c : v6) cout << c << ' ';
    cout << endl;

    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6};
    vector<int> sumVec;
    for (size_t i = 0; i < a.size(); ++i)
        sumVec.push_back(a[i] + b[i]);
    cout << "7. Сумма векторов: ";
    for (int x : sumVec) cout << x << " ";
    cout << endl;

    vector<int> diffVec;
    for (size_t i = 0; i < a.size(); ++i)
        diffVec.push_back(a[i] - b[i]);
    cout << "8. Разность векторов: ";
    for (int x : diffVec) cout << x << " ";
    cout << endl;

    return 0;
}