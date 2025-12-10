#include "stats.h"
#include <cmath>

double stats::normalCDF( double z ){
    return .5 * std::erfc(-z / std::sqrt(2.0));
}

double stats::normalPDF( double z ){
    return std::exp(-.5 * std::pow(z, 2.0)) * (1.0 / (std::sqrt(2.0 * M_PI)));
}
