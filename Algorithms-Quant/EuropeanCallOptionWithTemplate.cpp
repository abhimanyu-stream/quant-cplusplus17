#include <iostream>
#include <cmath>
#include <iomanip>

// Template function for the cumulative distribution function of the standard normal distribution
template <typename T>
T normalCDF(T x) {
    return static_cast<T>(0.5) * std::erfc(-x * std::sqrt(static_cast<T>(0.5)));
}

// Template function for Black-Scholes Call Option Pricing
template <typename T>
T blackScholesCallPrice(T S, T K, T r, T sigma, T T_expiry) {
    T d1 = (std::log(S / K) + (r + static_cast<T>(0.5) * sigma * sigma) * T_expiry) / 
           (sigma * std::sqrt(T_expiry));
    T d2 = d1 - sigma * std::sqrt(T_expiry);

    return S * normalCDF(d1) - K * std::exp(-r * T_expiry) * normalCDF(d2);
}

// Main function
int main() {
    // Input parameters (using double as the default type)
    double S = 100.0;    // Current stock price
    double K = 100.0;    // Strike price
    double r = 0.05;     // Risk-free interest rate
    double sigma = 0.2;  // Volatility
    double T_expiry = 1.0; // Time to maturity

    // Calculate the call price using double
    double callPriceDouble = blackScholesCallPrice(S, K, r, sigma, T_expiry);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Call Option Price (double): $" << callPriceDouble << std::endl;

    // Calculate the call price using float
    float callPriceFloat = blackScholesCallPrice<float>(S, K, r, sigma, T_expiry);
    std::cout << "Call Option Price (float): $" << callPriceFloat << std::endl;

    // Calculate the call price using long double
    long double callPriceLongDouble = blackScholesCallPrice<long double>(S, K, r, sigma, T_expiry);
    std::cout << "Call Option Price (long double): $" << callPriceLongDouble << std::endl;

    return 0;
}
