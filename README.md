Black–Scholes Option Pricer (C++)

This is a small C++ project where I implement the Black–Scholes model from scratch for European call and put options. The goal was twofold:

1. Refresh the math (PDE to closed-form, Greeks, normal PDF/CDF)
2. Get practical C++ experience with a clean, header/implementation split

The project currently runs a series of tests in main.cpp and prints out prices and Greeks for different scenarios (ATM, ITM, OTM, high volatility, short maturity, etc.).

------------------------------------------------------------
Features
------------------------------------------------------------

- Black–Scholes pricing for:
  - European call options
  - European put options

- Computation of:
  - d1 and d2
  - Delta (call and put)
  - Gamma
  - Vega
  - Theta (call and put)
  - Rho (call and put)

- stats namespace providing:
  - Standard normal PDF
  - Standard normal CDF (via std::erfc)

- Organized project structure:
  include/ for headers
  src/ for source files

------------------------------------------------------------
Project Structure
------------------------------------------------------------


├── include/
│   ├── blackScholes.h
│   └── stats.h
├── src/
│   ├── main.cpp
│   ├── blackScholes.cpp
│   └── stats.cpp
├── Makefile
└── README.txt

stats.* contains the normal PDF/CDF utilities.
blackScholes.* contains the Black–Scholes model and Greeks.
main.cpp runs a test suite and prints results.

------------------------------------------------------------
Build and Run
------------------------------------------------------------

Requires:
- g++ with C++17 support
- make

To build:
    make

To run:
    make run

To clean:
    make clean

The executable produced is named "exe".

------------------------------------------------------------
Sample Output
------------------------------------------------------------

Example from a typical run (shortened):

===== TEST: S=100, K=100, r=0.05, sigma=0.20, T=1 =====
d1:       0.350000
d2:       0.150000
Call:     10.450584
Put:      5.573526
Call Δ:   0.636831
Put Δ:    -0.363169
Gamma:    0.003752
Vega:     0.375240
Call Θ:   -2.736672
Put Θ:    2.019475
Call ρ:   53.232482
Put ρ:    -41.890461

These values match standard Black–Scholes calculators and textbook results.

------------------------------------------------------------
Implementation Notes
------------------------------------------------------------

- The normal CDF is implemented using std::erf and the identity:
  normalCDF(z) = 0.5 * (1 + erfc(x / sqrt(2)))

- The model implements the closed-form Black–Scholes formulas for 
  non-dividend-paying European options.

- Option parameters (Spot Price, Strike Price, Rate, Volatility, Time) are stored in the BlackScholes class,
  which exposes price and Greek methods.

------------------------------------------------------------
Possible Extensions
------------------------------------------------------------

Ideas for expanding the project:

- Implied volatility solver using Newton’s method
- Support for continuous dividend yield
- Command-line user input mode
- Binomial tree pricer for comparison
- Unit tests using a framework like Catch2 or GoogleTest

The project is intentionally simple and focused so it can be read easily.


