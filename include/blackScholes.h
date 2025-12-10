#pragma once
class BlackScholes{

public:

    BlackScholes( 
                double spot_price, double strike_price, double rate, 
                double volatility, double time);

    double d1() const;
    double d2() const;

    double callPrice() const;
    double putPrice() const;

    double callDelta() const;
    double putDelta() const;
    double gamma() const;
    double vega() const;
    double callTheta() const;
    double putTheta() const;
    double callRho() const;
    double putRho() const;

    void printInfo() const;


private:

    double spot_price;
    double strike_price;
    double rate;
    double volatility;
    double time;

};
