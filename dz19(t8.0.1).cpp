#include <iostream>
#include <ctime>
using namespace std;


int GreatestCommonDivisor(int a, int b)
{
    if (b == 0) {return a;}
    return GreatestCommonDivisor(b, a % b);
}

class Rational
{
private:
    int nominator;
    int denominator;

    void Decrease()
    {
        nominator   /= GreatestCommonDivisor(nominator, denominator);
        denominator /= GreatestCommonDivisor(nominator, denominator);
    }


public:
    Rational()
    {
        nominator = 1;
        denominator = 1;
    }

    Rational(const char mode)
    {   
        if (mode == 'c')
        {
            int nom, den;
            cin >> nom >> den;
            if (den != 0)
            {
                nominator = nom;
                denominator = den;
            }
            else
            {
                cout << "Wrong denominator" << endl;
            }
        }
        else if(mode == 'r')
        {
            nominator = rand() % 100000;
            denominator = rand() % 1000000;
        }
        
    }

    Rational(int nom, int den)
    {
        if (den != 0)
        {
            nominator = nom;
            denominator = den;
        }
        else
        {
            cout << "Wrong denominator" << endl;
        }
        
    }

    int GetNominator()
    {
        return nominator;
    }

    int GetDenominator()
    {
        return denominator;
    }

    void SetNominator(int val)
    {
        nominator = val;
    }

    void SetDenominator(int val)
    {
        if(val != 0)
        {
            denominator = val;
        }
        else
        {
            cout << "Wrong denominator" << endl;
        }
        
    }

    Rational operator + (Rational &rat)
    {
        Rational temp(1,1);
        temp.nominator = (this->nominator * rat.GetDenominator()) + (rat.GetNominator() * this->GetDenominator());
        temp.denominator = this->denominator * rat.denominator;

        return temp;
    }

    Rational operator *(Rational &rat)
    {
        Rational temp(1,1);
        temp.SetNominator(this->nominator * rat.GetNominator());
        temp.SetDenominator(this->denominator * rat.GetDenominator());
        
        return temp;
    }
};


int main()
{
    Rational a, b;

    Rational res = a + b;
    cout << res.GetNominator() << "/" << res.GetDenominator() << endl;
    Rational res2 = a * b;
    cout << res2.GetNominator() << "/" << res2.GetDenominator();
}