#include <iostream>
#include <vector>
#include "MergeSort.h"

/**
 * @brief Pomocnicza funkcja wyswietlajaca zawartosc tablicy w konsoli.
 * @tparam T Typ elementow w tablicy.
 * @param arr Wektor do wypisania.
 */
template <typename T>
void wyswietlTablice(const std::vector<T>& arr) {
    for (const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

int main() {
    // 1. Instancja dla liczb calkowitych (int)
    MergeSort<int> sorterInt;
    std::vector<int> tablicaInt = { 42, -7, 15, 0, 8, -23, 4 };

    std::cout << "Tablica int przed sortowaniem: ";
    wyswietlTablice(tablicaInt);

    sorterInt.sort(tablicaInt);

    std::cout << "Tablica int po sortowaniu:    ";
    wyswietlTablice(tablicaInt);
    std::cout << "------------------------------------------\n";

    // 2. Instancja dla liczb zmiennoprzecinkowych (double)
    MergeSort<double> sorterDouble;
    std::vector<double> tablicaDouble = { 5.25, -1.1, 3.14, 0.0, -8.9, 2.71 };

    std::cout << "Tablica double przed sortowaniem: ";
    wyswietlTablice(tablicaDouble);

    sorterDouble.sort(tablicaDouble);

    std::cout << "Tablica double po sortowaniu:    ";
    wyswietlTablice(tablicaDouble);

    return 0;
}