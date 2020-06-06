#ifndef _MATRIX_H_
#define _MATRIX_H
#include <ostream>

template <typename T, int columns, int rows> class Matrix
{
    public:
        // Constructor resets all values inside matrix to 0
        Matrix() 
        {
            reset(0);
        }
        // Empty destructor
        ~Matrix() {}
        
        // Const version of at for reading, returns reference to element of 2D array according to template parameters 
        template <int atColumn, int atRow> const T& at() const;
        // Non-const version of at for writing, returns reference to element of 2D array according to template parameters 
        template <int atColumn, int atRow> T& at();
        
        // This method sets all cells of this matrix to resetValue
        void reset(T resetValue);
        // Adds cells of matrix added to the cells of this matrix, regardless of type, as long as dimensions are the same
        void add(const Matrix<int, columns, rows>& added);
        
        T m[columns][rows];
};

template <typename T, int columns, int rows>
template <int atColumn, int atRow>
const T& Matrix<T, columns, rows>::at() const
{
    return m[atColumn][atRow];
}

template <typename T, int columns, int rows>
template <int atColumn, int atRow>
T& Matrix<T, columns, rows>::at()
{
    return m[atColumn][atRow];
}

template <typename T, int columns, int rows>
void Matrix<T, columns, rows>::reset(T resetValue)
{
    int indexVert = 0;
    int indexHor = 0;
    
    while(indexVert < rows)
    {    
        while(indexHor < columns)
        {
            m[indexHor][indexVert] = resetValue; 
            indexHor++;
        }
        indexHor = 0;
        indexVert++;
    }
        
}

template <typename T, int columns, int rows>
void Matrix<T, columns, rows>::add(const Matrix<int, columns, rows>& added)
{
    int indexVert = 0;
    int indexHor = 0;
    
    while(indexVert < rows)
    {    
        while(indexHor < columns)
        {
            m[indexHor][indexVert] += added.m[indexHor][indexVert]; 
            indexHor++;
        }
        indexHor = 0;
        indexVert++;
    }
}

// Operator<< overload printing the whole matrix in grid formation
template  <typename T, int columns, int rows>
std::ostream &operator<<(std::ostream &out, const Matrix<T, columns, rows> &matrix)
{
    int indexVert = 0;
    int indexHor = 0;
    
    while(indexVert < rows)
    {    
        while(indexHor < columns)
        {
            out << matrix.m[indexHor][indexVert] << ' '; 
            indexHor++;
        }
        out << '\n';
        indexHor = 0;
        indexVert++;
    }
  return out;
}

#endif