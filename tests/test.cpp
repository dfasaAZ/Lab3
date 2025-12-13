//
// Created by Matvey on 13.12.2025.
//
#include <gtest/gtest.h>
#include "../src/QuickSort.h"
#include <vector>
#include <random>
#include <algorithm>

auto sortFunc = [](int a, int b) { return a < b; };
TEST(QuickSortTest, Ints) {
    std::vector<int> v(100000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-10000, 10000);
    for (auto &x: v) x = dis(gen);

    sort(v.data(), v.data() + v.size(), [](int a, int b) { return a < b; });

    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(QuickSortTest, Strings) {
    std::vector<std::string> v = {"zxvcb", "asdf", "cvbn", "bnm,.", "erty"};
    sort(v.data(), v.data() + v.size(),
         [](const std::string &a, const std::string &b) { return a < b; });

    std::vector<std::string> expected = {"asdf", "bnm,.", "cvbn", "erty", "zxvcb"};
    EXPECT_EQ(v, expected);
}

TEST(QuickSortTest, Duplicates) {
    int arr[] = {5, 1, 5, 5, 2, 5, 3, 5};
    sort(arr, arr + 8, [](int a, int b) { return a < b; });
    EXPECT_TRUE(std::is_sorted(arr, arr + 8));
}
TEST(QuickSortTest, EmptyArray) {
    std::vector<int> v;
    sort(v.data(), v.data() + v.size(), sortFunc);
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(QuickSortTest, SingleElement) {
    std::vector<int> v = {500};
    sort(v.data(), v.data() + v.size(), sortFunc);
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(QuickSortTest, AlreadySorted) {
    std::vector<int> v = {-10, -5, 0, 1, 5, 10, 100};
    sort(v.data(), v.data() + v.size(), sortFunc);
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(QuickSortTest, ReverseSorted) {
    std::vector<int> v = {100, 50, 10, 5, 0, -5, -100};
    sort(v.data(), v.data() + v.size(), sortFunc);
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(QuickSortTest, Identical) {
    std::vector<int> v(1000, 42);  // 1000 одинаковых элементов
    sort(v.data(), v.data() + v.size(), sortFunc);
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}
TEST(QuickSortTest, FloatingPointNumbers) {
    std::vector<double> v = {3.14, -2.5, 0.0, 7.89, -1.1, 5.5, 2.718, -0.001};
    sort(v.data(), v.data() + v.size(), [](double a, double b) { return a < b; });

    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}