#include <iostream>
#include <stdexcept>
#include <chrono>

// Recursive function to calculate Fibonacci number
long long fibonacciRecursive(int n)
{
    if (n < 0)
    {
        throw std::invalid_argument("Input must be a non-negative integer.");
    }

    if (n <= 1)
    {
        return n;
    }

    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Non-recursive (Iterative) function to calculate Fibonacci number
long long fibonacciNonRecursive(int n)
{
    if (n < 0)
    {
        throw std::invalid_argument("Input must be a non-negative integer.");
    }

    if (n <= 1)
    {
        return n;
    }

    long long fib1 = 0, fib2 = 1, fib;

    for (int i = 2; i <= n; ++i)
    {
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
    }

    return fib2;
}

int main()
{
    try
    {
        int n;
        std::cout << "Enter the number of Fibonacci numbers to generate: ";
        std::cin >> n;

        if (n < 0)
        {
            throw std::invalid_argument("Number of Fibonacci numbers must be non-negative.");
        }

        // Recursive approach
        std::cout << "Fibonacci sequence using recursive approach:" << std::endl;
        for (int i = 0; i < n; ++i)
        {
            std::cout << fibonacciRecursive(i) << " ";
        }
        std::cout << std::endl;

        // Non-recursive (iterative) approach
        std::cout << "Fibonacci sequence using iterative approach:" << std::endl;
        for (int i = 0; i < n; ++i)
        {
            std::cout << fibonacciNonRecursive(i) << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
