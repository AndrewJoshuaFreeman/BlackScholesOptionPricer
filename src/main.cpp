#include "blackScholes.h"
#include "stats.h"
#include <iostream>
#include <iomanip>


void testOption(const BlackScholes& bs, const std::string& name) {
    std::cout << "\n===== TEST: " << name << " =====\n";
    std::cout << std::fixed << std::setprecision(6);

    double d1 = bs.d1();
    double d2 = bs.d2();

    std::cout << "d1:       " << d1 << "\n";
    std::cout << "d2:       " << d2 << "\n";

    std::cout << "Call:     " << bs.callPrice() << "\n";
    std::cout << "Put:      " << bs.putPrice() << "\n";

    std::cout << "Call Δ:   " << bs.callDelta() << "\n";
    std::cout << "Put Δ:    " << bs.putDelta()  << "\n";
    std::cout << "Gamma:    " << bs.gamma()     << "\n";
    std::cout << "Vega:     " << bs.vega()      << "\n";
    std::cout << "Call Θ:   " << bs.callTheta() << "\n";
    std::cout << "Put Θ:    " << bs.putTheta()  << "\n";
    std::cout << "Call ρ:   " << bs.callRho()   << "\n";
    std::cout << "Put ρ:    " << bs.putRho()    << "\n";
}

int main(){

    std::cout << std::fixed << std::setprecision(6);

    // TEST 1: Basic textbook case
    // ----------------------------
    BlackScholes bs1(100, 100, 0.05, 0.20, 1.0);
    testOption(bs1, "S=100, K=100, r=0.05, sigma=0.20, T=1");

    // Expected:
    // Call ≈ 10.4506
    // Put  ≈ 5.5735
    // d1 ≈ 0.350
    // d2 ≈ 0.150

    // TEST 2: High volatility
    // ----------------------------
    BlackScholes bs2(100, 100, 0.05, 0.50, 1.0);
    testOption(bs2, "High volatility test (sigma=0.50)");

    // TEST 3: Deep in-the-money call
    // ----------------------------
    BlackScholes bs3(200, 100, 0.05, 0.20, 1.0);
    testOption(bs3, "Deep ITM call (S=200, K=100)");

    // TEST 4: Deep out-of-the-money call
    // ----------------------------
    BlackScholes bs4(50, 100, 0.05, 0.20, 1.0);
    testOption(bs4, "Deep OTM call (S=50, K=100)");

    // TEST 5: Short maturity
    // ----------------------------
    BlackScholes bs5(100, 100, 0.05, 0.20, 0.01);
    testOption(bs5, "Very short maturity (T=0.01)");

    // TEST 6: Zero interest rate
    // ----------------------------
    BlackScholes bs6(100, 100, 0.00, 0.20, 1.0);
    testOption(bs6, "Zero interest rate");

    // TEST 7: Test stats namespace directly
    // ----------------------------
    std::cout << "\n===== TEST: stats PDF & CDF =====\n";
    std::cout << "phi(0)  = " << stats::normalPDF(0.0)  << " (expected ~0.398942)\n";
    std::cout << "Phi(0)  = " << stats::normalCDF(0.0)  << " (expected 0.5)\n";
    std::cout << "Phi(1)  = " << stats::normalCDF(1.0)  << " (expected ~0.841344)\n";
    std::cout << "Phi(-1) = " << stats::normalCDF(-1.0) << " (expected ~0.158656)\n";
    std::cout << "\n\nAll tests completed.\n";

return 0;
}
