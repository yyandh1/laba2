#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//функции для 1
bool isPrime(int n) {
    if (n <= 1) return false;//проверка на простое число
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int task1(int n) {
    if (isPrime(n)) return n; // Если N уже простое число, возвращаем его
    int smaller = n - 1;
    int larger = n + 1;
    while (true) {
        if (isPrime(smaller)) return smaller;
        if (isPrime(larger)) return larger;
        smaller--;
        larger++;
    }
}
//функции для второго
int s11(string rings) {
    unordered_set<int> white, blue, red;
    int n = rings.length() / 2;

    for (int i = 0; i < n; ++i) {
        char color = rings[2 * i];
        int stick = rings[2 * i + 1] - '0'; // Convert char to int

        switch (color) {
        case 'W':
            white.insert(stick);
            break;
        case 'B':
            blue.insert(stick);
            break;
        case 'R':
            red.insert(stick);
            break;
        }
    }

    int count = 0;
    for (int i = 0; i < 10; ++i) {
        if (white.count(i) && blue.count(i) && red.count(i)) {
            ++count;
        }
    }

    return count;
}
//функции для третьего
//string reverseAndTrimLeadingZeros(int num) // Функция для переворачивания числа и удаления ведущих нулей
//{
//    string str = to_string(num);
//    reverse(str.begin(), str.end());
//    str.erase(0, min(str.find_first_not_of('0'), str.size() - 1));
//    return str;
//}
int reverseNumber(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}


int main() {

    // начало 1
    cout << "Input N:" << endl;
    int N;
    cin >> N;
    int Simple = task1(N);//находим ближайшее простое
    int N_Element = abs(N - Simple);
    cout << "The difference with the nearest simple number: " << N_Element << endl;
    // конец 1

    // начало 2
    cout << "Input the Rings:" << endl;
    string rings;
    cin >> rings;// вводим нашу строку, где есть первый цвет и второй номер стержня
    int result = s11(rings);
    cout << "Number of sticks with rings of all three colors: " << result << endl;
    //конец 2

    //начало 3
    //начало 3



    cout << "Input numbers: ";
    int n;
    cin >> n;
    int* numbers = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < n; i++) {
        int reversed = reverseNumber(numbers[i]);

        // Удаление ведущих нулей
        while (reversed % 10 == 0 && reversed != 0) {
            reversed /= 10;
        }

        cout << reversed;
        if (i < n - 1) {
            cout << " ";
        }
    }

    delete[] numbers;

    return 0;
    //конец 3

}
