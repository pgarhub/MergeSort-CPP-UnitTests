#pragma once
#include <vector>
#include <cstddef>

using namespace std;
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
    void sort(vector<T>& arr) {
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

    void mergeSort(vector<T>& arr, size_t left, size_t right) {
        if (left >= right) {
            return;
        }

        size_t mid = left + (right - left) / 2;

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
    void merge(vector<T>& arr, size_t left, size_t mid, size_t right) {
        size_t n1 = mid - left + 1;
        size_t n2 = right - mid;

        vector<T> leftArr(n1);
        vector<T> rightArr(n2);

        for (size_t i = 0; i < n1; ++i) {
            leftArr[i] = arr[left + i];
        }
        for (size_t j = 0; j < n2; ++j) {
            rightArr[j] = arr[mid + 1 + j];
        }

        size_t i = 0;
        size_t j = 0;
        size_t k = left;

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