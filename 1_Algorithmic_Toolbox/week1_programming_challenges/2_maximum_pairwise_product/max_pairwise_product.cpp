/* 

Problem: Maximum Pairwise Product Programming Challenge.
Given a sequence of n non-negative integers, find the maximum pairwise product. 

Input: 
First Line (n): Number of input values. 
Second Line (numbers): sequence of n non-negative integer values seperated by space. 

Output: Maximum Pairwise Product. 

*/

#include <iostream>
#include <vector>
#include <algorithm>

/*

MaxPairwiseProduct: This is a naive solution to find maximum pairwise product.
It finds maximum product by comparing product of each possible combination. 

*/

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long)numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

/*

MaxPairwiseProductFast: This is faster solution compared MaxPairwiseProduct. 
It scans through the input vector twice to find the maximum value and second maximum value. 
Returns the product of maximum value and second maximum value. 

*/

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    int second_max_index = -1; 
    int first_max_index = -1; 
    for (int i = 0; i < n; ++i) {
        if (numbers[i] > numbers[first_max_index]) {
            first_max_index = i;
        }
    }
    for (int j = 0; j < n; ++j) {
        if (numbers[j] > numbers[second_max_index] && j != first_max_index) {
            second_max_index = j;
        }
    }
    max_product = (long long)numbers[first_max_index] * numbers[second_max_index];

    return max_product;
}

int main() {

    /* Stress Testing: This block of code is for Stress Testing to find possible failures. 
    It compares result between naive implementation and faster implementation. */
    /*
    while(true) {
        int n = rand()%10 + 2;
        std::cout << n << "\n";
        std::vector<int> a;
        for (int i=0; i < n; ++i) {
            a.push_back(rand()%100000);
        }
        for (int i=0; i < n; ++i) {
            std::cout << a[i] << " ";
        }
        long long result1 = MaxPairwiseProduct(a);
        long long result2 = MaxPairwiseProductFast(a);
        if (result1 != result2) {
            std::cout << "Wrong Answer " << result1 << " " << result2 << "\n";
            break;
        }
        else{
            std::cout << "OK" << "\n"; 
        }
    } 
    */

    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
