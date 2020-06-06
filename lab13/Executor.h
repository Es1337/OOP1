#ifndef _EXECUTOR_H_
#define _EXECUTOR_H_
#include <string>
#include <stdexcept>

namespace Executor
{
    // Class wrapping the result of a function
    class Result 
    {
        public:
            bool valid;
            double value;
            std::string problem;
            
            // Method converting the class to a double if the result is valid, otherwise throws an exception
            operator double()
            {
                if(!valid)
                {
                    throw std::logic_error("Attempted the use of incorrect value");
                }
                return value;
            }
    };
    
    // Base class for mathematic functions
    class Function 
    {
        public:
            // Pure virtual function, in derived classes it returns the result of execution of a function for an argument given as the argument x
            // if the value lies inside it's domain, otherwise throws an exception
            virtual double operator()(double x) const =0;
    };
    
    // Function executing mathematical functions passed as an argument, for an argument given as the argument x, also taking care of exceptions
    // Returns an object of the Result class with calculated value, or with a description of a problem, the state of the result is determined by the valid variable
    Result secureRun(const Function& f, double x)
    {
        Result result;
        result.valid = true;
        
        try
        {
            result.value = f(x);
        }
        catch(std::domain_error er)
        {
            result.valid = false;
            result.problem = er.what();
        }
        
        return result;
    }
}

// If a problem with the result object exists, the << operator outputs it to the console
std::ostream& operator<<(std::ostream& out, const Executor::Result& result)
{
    out << "ERROR" << result.problem;
    return out;
}

#endif