#include <string>
#include <typeinfo>

namespace num
{
    // Template of a function returning an average of all elements in passed array arr[],
    // size of arr is passed as arrSize.
    template <typename T> double srednia(const T arr[], const int arrSize)
    {
        double sum = 0;
        
        for(int i = 0; i < arrSize; i++)
        {
            sum += arr[i];
        }
        
        sum /= arrSize;
        return sum;
    }
    
    // Template of a function returning an average of all elements in passed array arr[],
    // size of arr is picked depending on the type.
    template <typename T> double srednia(const T arr[])
    {
        int arrSize = (typeid(T) == typeid(int)) ? 6 : 5;
        double sum = 0;
        
        for(int i = 0; i < arrSize; i++)
        {
            sum += arr[i];
        }
        
        sum /= arrSize;
        return sum;
    }

    // Template of a function checking whether the elements in range [index_1, index_2) of arr[] are primes,
    // and returning true/false accordingly.
    template <int index_1, int index_2> bool czyWszystkiePierwszwe(const int arr[])
    {
        int half = 0;

        for(int i = index_1; i < index_2; i++)
        {
            half = arr[i]/2;
            
            for(int j = 2; j <= half; j++)
                if(arr[i] % j == 0)  return false;
        }
        return true;
    }
    
    // Function converting a bool to a string.
    std::string text(const bool b)
    {
        return (b == true) ? "TRUE" : "FALSE";
    }
}