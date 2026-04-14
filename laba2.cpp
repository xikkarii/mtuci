#include <iostream>
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите количество элементов списка: ";
    std::cin >> n;
    std::vector<int> list(n);
    std::cout << "Введите " << n << " целых чисел:\n";
    for (int i = 0; i < n; ++i) std::cin >> list[i];

    double avg = std::accumulate(list.begin(), list.end(), 0.0) / n;
    std::cout << "\n1. Среднее арифметическое: " << avg << std::endl;

    int min = *std::min_element(list.begin(), list.end());
    std::cout << "2. Минимальный элемент: " << min << std::endl;

    int max = *std::max_element(list.begin(), list.end());
    std::cout << "3. Максимальный элемент: " << max << std::endl;

    std::stack<int> st;
    for (int x : list) st.push(x);
    std::cout << "4. Стек создан (элементы в обратном порядке): ";
    std::stack<int> st_copy = st;
    while (!st_copy.empty()) {
        std::cout << st_copy.top() << " ";
        st_copy.pop();
    }
    std::cout << std::endl;

    std::queue<int> q;
    for (int x : list) q.push(x);
    std::cout << "5. Очередь создана (элементы в прямом порядке): ";
    std::queue<int> q_copy = q;
    while (!q_copy.empty()) {
        std::cout << q_copy.front() << " ";
        q_copy.pop();
    }
    std::cout << std::endl;

    int sumEven = 0, sumOdd = 0, sumPos = 0, sumNeg = 0;
    std::vector<int> newList;
    for (int x : list) {
        if (x % 2 == 0) sumEven += x;
        else sumOdd += x;
        if (x > 0) sumPos += x;
        else if (x < 0) sumNeg += x;
        newList.push_back(x * x - 1);
    }
    std::cout << "6. Сумма чётных элементов: " << sumEven << std::endl;
    std::cout << "7. Сумма нечётных элементов: " << sumOdd << std::endl;
    std::cout << "8. Новый список (x^2 - 1): ";
    for (int x : newList) std::cout << x << " ";
    std::cout << std::endl;
    std::cout << "9. Сумма положительных элементов: " << sumPos << std::endl;
    std::cout << "10. Сумма отрицательных элементов: " << sumNeg << std::endl;

    return 0;
}