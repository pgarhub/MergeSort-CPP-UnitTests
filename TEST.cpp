#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include "MergeSort.h"

// 1. Zachowuje tablicê niezmienion¹, gdy jest ju¿ posortowana rosn¹co
TEST(MergeSortTest, AlreadySortedAscending) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    std::vector<int> expected = { 1, 2, 3, 4, 5, 6 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 2. Potrafi posortowaæ tablicê posortowan¹ w odwrotnej kolejnoœci
TEST(MergeSortTest, ReverseSorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 9, 7, 5, 3, 1, -2 };
    std::vector<int> expected = { -2, 1, 3, 5, 7, 9 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 3. Poprawnie sortuje losow¹ tablicê liczb
TEST(MergeSortTest, RandomArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 42, -7, 15, 0, 8, -23, 4 };
    std::vector<int> expected = { -23, -7, 0, 4, 8, 15, 42 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 4. Poprawnie sortuje tablice tylko z liczbami ujemnymi
TEST(MergeSortTest, OnlyNegativeNumbers) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -5, -100, -1, -42, -15 };
    std::vector<int> expected = { -100, -42, -15, -5, -1 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 5. Poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi
TEST(MergeSortTest, MixedNegativeAndPositiveNumbers) {
    MergeSort<double> sorter;
    std::vector<double> arr = { 3.5, -2.1, 0.0, -9.8, 1.2, 7.4 };
    std::vector<double> expected = { -9.8, -2.1, 0.0, 1.2, 3.5, 7.4 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 6. Obs³uguje pust¹ tablicê bez rzucania wyj¹tkiem
TEST(MergeSortTest, EmptyArrayDoesNotThrow) {
    MergeSort<int> sorter;
    std::vector<int> arr = {};
    EXPECT_NO_THROW(sorter.sort(arr));
    EXPECT_TRUE(arr.empty());
}

// 7. Nie zmienia tablicy, która zawiera tylko jeden element
TEST(MergeSortTest, SingleElementArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 99 };
    std::vector<int> expected = { 99 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 8. Poprawnie sortuje tablicê z duplikatami liczb
TEST(MergeSortTest, ArrayWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 5, 1, 3, 5, 2, 1, 5, 3 };
    std::vector<int> expected = { 1, 1, 2, 3, 3, 5, 5, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 9. Poprawnie sortuje tablice ujemn¹ z duplikatami
TEST(MergeSortTest, NegativeArrayWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -3, -1, -7, -3, -1, -10, -7 };
    std::vector<int> expected = { -10, -7, -7, -3, -3, -1, -1 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 10. Poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortTest, MixedNegativePositiveAndDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 0, -4, 7, 0, -4, 2, 7, -1 };
    std::vector<int> expected = { -4, -4, -1, 0, 0, 2, 7, 7 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 11. Poprawnie sortuje tablicê zawieraj¹c¹ tylko dwa elementy w kolejnoœci rosn¹cej
TEST(MergeSortTest, TwoElementsAscending) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 10, 20 };
    std::vector<int> expected = { 10, 20 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 12. Poprawnie sortuje du¿¹ tablicê (ponad 100 elementów)
TEST(MergeSortTest, LargeArrayOver100Elements) {
    MergeSort<int> sorter;
    std::vector<int> arr;
    for (int i = 150; i >= 1; --i) {
        arr.push_back(i);
    }
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 13. Poprawnie sortuje du¿¹ tablicê (ponad 100 elementów) z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortTest, LargeArrayMixedWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr;
    for (int i = -60; i <= 60; ++i) {
        arr.push_back(i);
        arr.push_back(-i); // celowe tworzenie duplikatow, ujemnych i dodatnich (242 elementy)
    }
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}