#cppOpt
A C++ library which allows the numerical optimisation of any given problem or function or program or you-name-it

##optimise anything!
optimise any given problem by defining your very own Solver class:
```cpp
class MySolver : public SolverBase
{
public:
    void calculate(OptCalculation &optCalculation) const
    {
        optCalculation.result = YOUR_CODE_COMES_HERE;
    }
};
```
for optimising x^2 you could write:

```cpp
void calculate(OptCalculation &optCalculation) const
{
    //defined x^2 as function to be optimized
    optCalculation.result = pow(optCalculation.get_parameter("X"),2);
}
```

you can even run other programs:

```cpp
void calculate(OptCalculation &optCalculation) const
{
    std::string parameter1 = optCalculation.get_parameter("X");
    std::string parameter2 = optCalculation.get_parameter("Y");

    system(( "someExecuteable -p1 " + parameter1 + " -p2 " + parameter2).c_str() );
    optCalculation.result = parse_generated_output_file();
}
```

##define your parameters and boundaries
```cpp
OptBoundaries optBoundaries;
optBoundaries.add_boundary(-5.0, 5.0, "X");
optBoundaries.add_boundary(-50.0, 55.0, "Y");
optBoundaries.add_boundary(33.0, 3.0, "potatoe");
```

##minimize, maximize, approach or diverge
```cpp
OptTarget optTarget = MINIMIZE;
OptTarget optTarget = MAXIMIZE;
OptTarget optTarget = APPROACH;
OptTarget optTarget = DIVERGE;
```

##choose your algorithm
```cpp
OptSimulatedAnnealing opt1(optBoundaries,
                           maxCalculations,
                           &myCalculator,
                           optTarget,
                           targetValue,
                           coolingFactor,
                           startChance);

OptThresholdAccepting opt2(optBoundaries,
                           maxCalculations,
                           &myCalculator,
                           optTarget,
                           targetValue,
                           coolingFactor,
                           threshold,
                           thresholdFactor);
```

##multithreading
you can spawn any number of objects with different algorithms, boundaries, configurations or goals

##go!
```cpp
OptBase::run_optimisations(NUMBER_OF_WORKER_THREADS);
```

##logging / outputting results
you can enable thread-safe logging as simple as:
```cpp
OptBase::enable_logging("logfile.log", optBoundaries);
```
```
X RESULT
1.083865 1.174763
3.901791 15.223976
3.862659 14.920135
...
```
you can retrieve both the best values of all your optimisers or specific ones:
```cpp
OptCalculation best = opt1.get_best_calculation();
OptCalculation best = opt2.get_best_calculation();
OptCalculation best = OptBase::get_best_calculation(optTarget, targetValue);
```

##examples
check out `examples/` for more

#usage

##configuration
open up `inc/config.h` to enable/disable DEBUG output  
or to define the used floating point precision
```cpp
//#define T float
#define T double
//#define T long double
```

##building
`cmake`  
`make`

##linking
link your program with the library created in `lib/`  
(or feel free to directly link the source files and not use `make` at all)

##including
include the algorithms and header files you want to use  
I suggest looking at the examples in `examples/`
