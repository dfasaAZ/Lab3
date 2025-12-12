#ifndef SORTLAB_QUICKSORT_H
#define SORTLAB_QUICKSORT_H
#include <bits/shared_ptr_base.h>
///Кол-во элементов для смены сортировки
const int THRESHOLD = 4;

/// Функция сравнивания
/// @tparam T
/// @param a первый элемент
/// @param b второй элемент
/// @return Да, если первый меньше второго
template<typename T>
bool compar(const T &a, const T &b) {
    return a < b;
}

/// Функция для сортировки вставками
/// @tparam T
/// @tparam Compare
/// @param first Начало коллекции
/// @param last Конец коллекции
/// @param comp чем сравниваем
template<typename T, typename Compare>
void insertionSort(T* first, T* last, Compare comp = compar) {
    for (T* i = first + 1; i < last; ++i) {
        T value = std::move(*i);
        T* j = i;
        while (j > first && comp(value, *(j - 1))) {
            *j = std::move(*(j - 1));
            --j;
        }
        *j = std::move(value);
    }
}

/// Основная функция сортировки
/// @tparam T
/// @tparam Compare
/// @param first Начало коллекции
/// @param last Конец коллекции
/// @param comp чем сравниваем
template<typename T, typename Compare>
void sort(T *first, T *last, Compare comp) {
    auto n = last - first;
    if (n < 1) return;
    if (n <= THRESHOLD) {
        insertionSort(first, last, comp);
        return;
    }
    //Медиана
    T* pivot = first + (n / 2);
    if (comp(*pivot, *first)) {
        std::swap(*first, *pivot);
    }
    if (comp(*(last-1), *first)) {
        std::swap(*first, *(last-1));
    }
    if (comp(*(last-1), *pivot)){
        std::swap(*pivot, *(last-1));
    }

    // Меняем местами элементы
    T* left = first;
    T* right = last-1;
    while (true) {
        while (comp(*left, *pivot))  ++left;
        while (comp(*pivot, *right)) --right;

        if (left >= right) break;
        std::swap(*left, *right);
        ++left;
        --right;
    }
    //Выбор какой кусок в какую сортировку
    if (pivot - first < last - (pivot+1)) {
        sort(first, pivot, comp);
        insertionSort(pivot+1, last, comp);
    } else {
        sort(pivot+1, last, comp);
        insertionSort(first,pivot, comp);
    }
}


#endif
