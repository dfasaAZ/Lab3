#ifndef SORTLAB_QUICKSORT_H
#define SORTLAB_QUICKSORT_H
#include <bits/shared_ptr_base.h>
///Кол-во элементов для смены сортировки
const int THRESHOLD = 24;

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
void insertionSort(T *first, T *last, Compare comp = compar) {
    for (T *i = first + 1; i < last; ++i) {
        T value = std::move(*i);
        T *j = i;
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
    while (true) {
        auto n = last - first;
        if (n < 2) return;
        if (n <= THRESHOLD) {
            insertionSort(first, last, comp);
            return;
        }

        // Ищем медиану
        T *mid = first + (n / 2);
        if (comp(*mid, *first)) std::swap(*mid, *first);
        if (comp(*(last - 1), *first)) std::swap(*(last - 1), *first);
        if (comp(*(last - 1), *mid)) std::swap(*(last - 1), *mid);
        T *pivot = last - 1;
        T *left = first;
        T *right = last - 2;

        //меняем элементы
        while (left <= right) {
            while (comp(*left, *pivot)) ++left;
            while (comp(*pivot, *right)) --right;

            if (left >= right) break;

            std::swap(*left, *right);
            ++left;
            --right;
        }


        std::swap(*left, *pivot);
        T *pivot_pos = left;

        //меньшее в рекурсию
        if (pivot_pos - first < last - (pivot_pos + 1)) {
            sort(first, pivot_pos, comp);
            first = pivot_pos + 1;
        } else {
            sort(pivot_pos + 1, last, comp);
            last = pivot_pos;
        }
    }
}
#endif