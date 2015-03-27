#include <iostream>
#include <cmath> ///@todo only needed for example formula, maybe remove later

#include "CalculatorBase.h"
#include "OptSimulatedAnnealing.h"

class MyCalculator : public CalculatorBase
{
public:
    MyCalculator()
    {

    }

    void calculate(OptValue &optValue) const ///@todo make static for easier usage
    {
#ifdef DEBUG
        std::cout << "DEBUG: in MyCalculator" << std::endl;
        optValue.result = pow(optValue.get_parameter("X"),2);
#endif
    }
};

using namespace std;

int main()
{
    std::vector<OptBoundary> optBoundaries;
    unsigned int maxCalculations = 100;
    OptTarget optTarget = MINIMIZE;
    T coolingFactor = 0.9;
    T startChance = 0.25;
    OptBoundary optBoundary(-3.0, 10.0, "X");
    optBoundaries.push_back(optBoundary);
    MyCalculator myCalculator;

    OptSimulatedAnnealing opt(optBoundaries, maxCalculations, &myCalculator, optTarget, coolingFactor, startChance);

    OptBase::run_optimisations(1);

    return 0;
}

