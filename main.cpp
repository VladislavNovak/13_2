// Интересное: проверка на пустоту - assert(!arr.empty())
#include <iostream>
#include <vector>
#include <string>
#include <cassert> // assert

using std::cout;
using std::endl;
using std::vector;
using std::string;

// Информационный отчет
void printReport(vector<int> &arr, const string &title = "Report") {
    cout << "-----------\n" << title << ": ";

    for (auto &item: arr) cout << item << ((item == arr.back()) ? "" : ", ");

    cout << endl;
}

// Задача: заменить стандартный метод вектора push_back
vector<int> addToEndOfQueue(vector<int> &arr, int addedValue) {
    size_t newSize = (arr.size() + 1);
    vector<int> temp(newSize);

    for (int i = 0; i < (newSize - 1); ++i) (temp[i] = arr[i]);

    temp[newSize - 1] = addedValue;

    return temp;
}

// Задача: реализовать вставку в указанную позицию без библиотечной функции
vector<int> insertToQueue(vector<int> &arr, int addedValue, int position) {
    size_t newSize = (arr.size() + 1);
    vector<int> temp(newSize);

    if (position > 0) {
        for (int i = 0; i < position; ++i) (temp[i] = arr[i]);
    }

    temp[position] = addedValue;

    for (int i = position; i < (newSize - 1); ++i) (temp[i + 1] = arr[i]);

    return temp;
}

// при указанной позиции (от 0 >= ... < arr.size) вставляет значение. В ином случае - добавляет в конец вектора
vector<int> changeVector(vector<int> &arr, int addedValue, int position = -1) {
    bool isInsertionPosition = position >= 0 && position < arr.size();
    return (isInsertionPosition)
           ? insertToQueue(arr, addedValue, position)
           : addToEndOfQueue(arr, addedValue);
}

// Задание 1. Очередь из роботов + Задание 3. Роботы и коррупция
void expandRobotQueue() {
    int currentSize = 5;
    vector<int> mainQueue = {0, 1, 2, 3, 4};
    int uInput = 0;
    int position = 0;

    printReport(mainQueue, "Current queue");

    do {
        ++currentSize;
        vector<int> tempQueue(currentSize);
        cout << "Enter value (or -1 to exit):";
        std::cin >> uInput;

        if (uInput != -1) {
            cout << "Enter a position in the queue (or -1 to add to end of the queue):";
            std::cin >> position;
            mainQueue = changeVector(mainQueue, uInput, position);
        }
    } while (uInput != -1);

    printReport(mainQueue, "Result");
}

// Задание 2. Лечебница
// рассчитывает среднюю температуру
void calcAverageTemperature() {
    vector<int> arr;
    int uInput = 0;
    int sum = 0;

    do {
        cout << "Enter temperature (or -1 to exit):";
        std::cin >> uInput;
        if (uInput != -1) {
            arr = changeVector(arr, uInput);
        }
    } while (uInput != -1);

    for (int value: arr) (sum += value);

    printReport(arr);

    assert(!arr.empty());

    cout << "(log) Sum: " << sum << endl;
    cout << "(log) Average: " << (sum / arr.size()) << endl;
}

int main() {
    // Для задания 1 и 3:
    expandRobotQueue();

    // Для задания 2:
    //     calcAverageTemperature();
}