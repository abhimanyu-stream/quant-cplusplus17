#include <iostream>
#include <cmath>
#include <iomanip>

// Cumulative distribution function for the standard normal distribution
double normalCDF(double x) {
    return 0.5 * std::erfc(-x * std::sqrt(0.5));
}

// Black-Scholes European Call Option Pricing Function
double blackScholesCallPrice(double S, double K, double r, double sigma, double T) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    return S * normalCDF(d1) - K * std::exp(-r * T) * normalCDF(d2);
}

int main() {
    // Input Parameters
    double S = 100.0;    // Current stock price
    double K = 100.0;    // Strike price
    double r = 0.05;     // Risk-free interest rate (annualized)
    double sigma = 0.2;  // Volatility (annualized)
    double T = 1.0;      // Time to maturity (in years)

    // Calculate the option price
    double callPrice = blackScholesCallPrice(S, K, r, sigma, T);

    // Output the result
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Black-Scholes Call Option Price: $" << callPrice << std::endl;

    return 0;
}

//g++ -std=c++17 -o3 -o EuropeanCallOption .\EuropeanCallOptionWithTemplate.cpp -lm