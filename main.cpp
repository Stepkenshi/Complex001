#include <iostream>
#include <sstream>
using namespace std;
struct complex_t
{
    float real;
    float imag;
        complex_t()
    {
        real = 0.0f;
        imag = 0.0f;
    }
    
    complex_t add( complex_t other ) const //Блок, отвечающий за сложение
    {
        complex_t result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }
    
    complex_t sub( complex_t other ) const // Блок, отвечающий за вычитание
    {
        complex_t result;
        result.real = real - other.real;
        result.imag = imag - other.imag;
        return result;
    }
    
    complex_t mult( complex_t other ) const // Блок, отвечающий за умножение
    {
        complex_t result;
        result.real = real * other.real - imag * other.imag;
        result.imag = real * other.imag - imag * other.real;
        return result;
    }
    
    complex_t div( complex_t other ) const // Блок, отвечающий за деление
    {
        complex_t result;
        result.real = (real * other.real + imag * other.imag)/(other.real * other.real - other.imag * other.imag);
        result.imag = (imag * other.real - real * other.imag)/(other.real * other.real - other.imag * other.imag);
        return result;
    }
    
    istream & read(istream & stream)
    {
        char op;
        return stream >> op >> real >> op >> imag >> op; 
    }
    
    ostream & write(ostream & stream ) const
    {
        return stream << "(" << real << "," << imag << ")";
    }
};

int main()
{
    complex_t x, y;
    char op;
    std::string line;
    std::getline( std::cin, line );
    std::istringstream stream( line );
    if (x.read(stream) && (stream >> op) && y.read(stream)) 
    {
        complex_t result;
        switch (op)
        {
            case '+':
            {
                result = x.add(y);
                result.write(cout);
                break;
            }
            case '-':
            {
                result = x.sub(y);
                result.write(cout);
                break;
            }
            case '*':
            {
                result = x.mult(y);
                result.write(cout);
                
                break;
            }
            case '/':
            {
                result = x.div(y);
                result.write(cout);
                break;
            }
            default: 
            {
                cout << "nAn error has occured while reading input data" << endl;
                break;
            }
        }
    }
    else{ cout << "nAn error has occured while reading input data"<<endl;
    } 
        std::cin.get();
}
