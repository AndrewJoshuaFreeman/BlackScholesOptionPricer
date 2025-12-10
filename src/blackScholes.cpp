#include "blackScholes.h"
#include "stats.h"
#include <iostream>

BlackScholes::BlackScholes(
        double spot_price, double strike_price, double rate,
        double volatility, double time)
        :
        spot_price{spot_price},
        strike_price{strike_price},
        rate{rate},
        volatility{volatility},
        time{time}
{}

void BlackScholes::printInfo() const{
    std::cout << "[ spot, strike, rate, volatility, time ]: " << std::endl;
    
    std::cout << "[ " << spot_price
              << ", " << strike_price
              << ", " << rate
              << ", " << volatility
              << ", " << time
              << " ]" << std::endl;
}

double BlackScholes::d1() const{
    return (std::log( (spot_price / strike_price) ) 
          + time * ( rate + (volatility * volatility * .5)))
          / ( volatility * std::sqrt(time));
}

double BlackScholes::d2() const{
    return d1() - ( volatility * sqrt(time) ); 
}

double BlackScholes::callPrice() const{
    return  spot_price * stats::normalCDF(d1()) 
          - strike_price * std::exp(-rate * time) * stats::normalCDF(d2());
}

double BlackScholes::putPrice() const{
    return strike_price * std::exp(-rate * time) * stats::normalCDF(-d2())
          -spot_price * stats::normalCDF(-d1());
}

double BlackScholes::callDelta() const{
    return stats::normalCDF(d1());
}

double BlackScholes::putDelta() const{
    return callDelta() - 1;
}

double BlackScholes::gamma() const{
    return stats::normalPDF(d1()) * (1 / (strike_price * std::sqrt(time)) );
}

double BlackScholes::vega() const{
    return stats::normalPDF(d1()) * std::sqrt(time);
}

double BlackScholes::callRho() const{
    return strike_price * time * std::exp(-rate * time) 
         * stats::normalCDF(d2());
}

double BlackScholes::putRho() const{
    return -strike_price * time * std::exp(-rate * time)
          * stats::normalCDF(-d2());
}

double BlackScholes::callTheta() const{
    return ( -vega() * volatility ) - ( rate * callRho() / time );
}

double BlackScholes::putTheta() const{
    return ( -vega() * volatility ) + ( rate * ( -putRho() / time ) );
}
