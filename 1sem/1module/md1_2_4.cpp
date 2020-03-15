//В круг выстроено N человек, пронумерованных числами от 1 до N. Будем исключать каждого k-ого до тех пор,
//пока не уцелеет только один человек.
//Например, если N=10, k=3, то сначала умрет 3-й, потом 6-й, затем 9-й, затем 2-й, затем 7-й, потом 1-й, потом 8-й,
//за ним - 5-й, и потом 10-й. Таким образом, уцелеет 4-й.
//Необходимо определить номер уцелевшего.
//N, k ≤ 10000.
//Время работы O(n^2), Потребляемая память M(n);
#include <iostream>

void Counter(int *array, int n, int k) {
    int position, count;
    for(int i = 1; i < n; ++i) {
        array[i] = i;
    }
    array[0] = n;
    position = 1;                                         //переменная для счета
    count = n;                                            // Кол-во оставшихся человек
    for(int i = 1;i < n; ++i) {                           //исключаем ровно n-1 человек
        position = (position + k - 1) % count;            // выбираем k-го человека
        for(int j = position; j < count - 1; ++j) {       //сдвигая массив, исключаем k-го
            array[j] = array[j + 1];
        }
        --count;
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;
    int  *array = new int[n];
    Counter(array, n, k);
    std::cout << array[0];                                 // уцелевшим окажется человек с индексом 0
    delete[] array;
    return 0;
}