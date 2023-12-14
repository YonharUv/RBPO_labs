#include <iostream>
#include <complex>
#define _SILENCE_NONFLOATING_COMPLEX_DEPRECATION_WARNING
import Math;
using namespace std;
int main()
{
    int choice;
    cout << "Enter 1 to input the modulus and argument of a complex number, or 2 to input the real and imaginary parts: ";
    cin >> choice;

    Complex userComplex;

    if (choice == 1) {
        double mod, arg;
        cout << "Enter the modulus: ";
        cin >> mod;
        cout << "Enter the argument: ";
        cin >> arg;

        userComplex = Complex::FromExponentialForm(mod, arg);
    }
    else if (choice == 2) {
        double re, im;
        cout << "Enter the real part: ";
        cin >> re;
        cout << "Enter the imaginary part: ";
        cin >> im;

        userComplex = Complex::FromAlgebraicForm(re, im);
    }
    else {
        cout << "Invalid choice." << endl;
        return 1;
    }

    cout << "Enter a rational number in the form nominator/denominator: ";
    int nominator, denominator;
    char separator;
    cin >> nominator >> separator >> denominator;

    Rational userRational(nominator, denominator);

    double userDouble;
    cout << "Enter a real number: ";
    cin >> userDouble;

    cout << "f(" << userComplex << ") = " << f(userComplex) << endl;
    cout << "f(" << userRational << ") = " << f(userRational) << endl;
    cout << "f(" << userDouble << ") = " << f(userDouble) << endl;

    return 0;
}
