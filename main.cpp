#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>

const int MAX = 700;

int main() 
{
    int A[MAX][MAX];
    int x[MAX];
    int y[MAX];
    
    for (int i = 0; i < MAX; i++)
    {
        x[i] = i + 1;
        y[i] = 0;
        for (int j = 0; j < MAX; j++)
            A[i][j] = rand() % 1000 + 1;
    }
    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            y[i] += A[i][j] * x[j];
            
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Tiempo algoritmo 1 = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    for (int i = 0; i < MAX; i++)
        y[i] = 0;

    std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();

        for (int j = 0; j < MAX; j++)
            for (int i = 0; i < MAX; i++)
                y[i] += A[i][j] * x[j];

    std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
    std::cout << "Tiempo algoritmo 2 = " << std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2).count() << "[µs]" << std::endl;

    return 0;
}