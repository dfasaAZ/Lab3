#ifndef SORTLAB_QUICKSORT_H
#define SORTLAB_QUICKSORT_H
#include <bits/shared_ptr_base.h>
///Кол-во элементов для смены сортировки
const int THRESHOLD = 10;

/// Функция сравнивания
/// @tparam T
/// @param a первый элемент
/// @param b второй элемент
/// @return Да, если первый меньше второго
template<typename T>
bool comp(const T &a, const T &b) {
    return a < b;
}

/// Функция для сортировки вставками
/// @tparam T
/// @tparam Compare
/// @param first Начало коллекции
/// @param last Конец коллекции
/// @param comp чем сравниваем
template<typename T, typename Compare>
void insertionSort(T* first, T* last, Compare comp) {
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
/// @param compare чем сравниваем
template<typename T, typename Compare>
void sort(T *first, T *last, Compare compare = comp) {
    T n = last - first;
    if (n < 2) return;
    if (n<THRESHOLD) {
        insertionSort(first, last);
    }

}


#endif
