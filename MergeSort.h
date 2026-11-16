#pragma once
#include <vector>
#include <cstddef>

/**
 * @brief Klasa szablonowa realizujaca algorytm sortowania przez scalanie (MergeSort).
 * @tparam T Typ danych przechowywanych w sortowanej tablicy (np. int, double, float, long int).
 */
template <typename T>
class MergeSort {
public:
    /**
     * @brief Glowna metoda uruchamiajaca sortowanie wektora rosnaco.
     * @param arr Referencja do sortowanego wektora.
     */
    void sort(std::vector<T>& arr) {
        if (arr.size() <= 1) {
            return;
        }
        mergeSort(arr, 0, arr.size() - 1);
    }

private:
    /**
     * @brief Rekurencyjnie dzieli tablice na dwie polowy.
     * @param arr Sortowany wektor.
     * @param left Indeks poczatkowy lewej czesci.
     * @param right Indeks koncowy prawej czesci.
     */
    void mergeSort(std::vector<T>& arr, std::size_t left, std::size_t right) {
        if (left >= right) {
            return;
        }

        std::size_t mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    /**
     * @brief Scala dwie posortowane podtablice w jedna posortowana calosc.
     * @param arr Sortowany wektor.
     * @param left Indeks poczatkowy pierwszej podtablicy.
     * @param mid Indeks koncowy pierwszej podtablicy.
     * @param right Indeks koncowy drugiej podtablicy.
     */
    void merge(std::vector<T>& arr, std::size_t left, std::size_t mid, std::size_t right) {
        std::size_t n1 = mid - left + 1;
        std::size_t n2 = right - mid;

        std::vector<T> leftArr(n1);
        std::vector<T> rightArr(n2);

        for (std::size_t i = 0; i < n1; ++i) {
            leftArr[i] = arr[left + i];
        }
        for (std::size_t j = 0; j < n2; ++j) {
            rightArr[j] = arr[mid + 1 + j];
        }

        std::size_t i = 0;
        std::size_t j = 0;
        std::size_t k = left;

        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                ++i;
            }
            else {
                arr[k] = rightArr[j];
                ++j;
            }
            ++k;
        }

        while (i < n1) {
            arr[k] = leftArr[i];
            ++i;
            ++k;
        }

        while (j < n2) {
            arr[k] = rightArr[j];
            ++j;
            ++k;
        }
    }
};