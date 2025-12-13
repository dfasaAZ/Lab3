#include <iostream>
#include "src/QuickSort.h"
#include <windows.h>
#include <vector>
#include <random>
#include <algorithm>
int main() {
    system("chcp 65001");
    std::cout << "Вылисление скорости выполнения для порога " <<THRESHOLD<< std::endl;
    const int NUM_RUNS = 100;
    double total_ms = 0.0;
    // структура для 64-битных целых чисел
    LARGE_INTEGER start_time, end_time, frequency;
    double elapsed_ms;

    // Получаем частоту счетчика производительности
    QueryPerformanceFrequency(&frequency);

    // Начало отсчета времени
    QueryPerformanceCounter(&start_time);

    std::vector<int> v(100000);
    std::mt19937 gen(451);
    std::uniform_int_distribution<> dis(-10000, 10000);
    for (int run = 1; run <= NUM_RUNS; ++run) {
        for (auto& x : v) x = dis(gen);
        LARGE_INTEGER start, end;
        QueryPerformanceCounter(&start);
        sort(v.data(), v.data() + v.size(), [](int a, int b) { return a < b; });
        QueryPerformanceCounter(&end);
        double elapsed_ms = (double)(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
        total_ms += elapsed_ms;
        printf("Замер %2d: %.3f мс\n", run, elapsed_ms);
    }

    double average_ms = total_ms / NUM_RUNS;

    printf("\n");
    printf("═══════════════════════════════════\n");
    printf("Среднее время за %d замеров: %.3f мс\n", NUM_RUNS, average_ms);
    printf("═══════════════════════════════════\n");

    return 0;
}