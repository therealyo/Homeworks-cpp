#include <iostream>
#include <cmath>
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

        temp.Decrease();

        return temp;
    }

    Rational operator + (double val)
    {
        Rational temp;
        temp.nominator = this->nominator + val * this->denominator;

        temp.Decrease();

        return temp;
    }
    Rational operator -(Rational &rat)
    {
        Rational temp(1,1);
        temp.nominator = (this->nominator * rat.GetDenominator()) - (rat.GetNominator() * this->GetDenominator());
        temp.denominator = this->denominator * rat.denominator;

        temp.Decrease();

        return temp;
    }

    Rational operator *(Rational &rat)
    {
        Rational temp(1,1);
        temp.SetNominator(this->nominator * rat.GetNominator());
        temp.SetDenominator(this->denominator * rat.GetDenominator());

        temp.Decrease();
        
        return temp;
    }

    Rational operator *(double val)
    {
        Rational temp;
        temp.SetNominator(this->nominator * val);

        temp.Decrease();
        
        return temp;
    }

    Rational operator /(Rational &rat)
    {
        Rational temp(1,1);
        temp.SetNominator(this->nominator * rat.GetDenominator());
        temp.SetDenominator(this->denominator * rat.GetNominator());

        temp.Decrease();
        
        return temp;
    }

    Rational Abs()
    {
        if(nominator < 0)
        {
            nominator = -nominator;
            return *this;
        }
        else { return *this; }
    }

    void operator -()
    {
        nominator = -nominator;
    }

    bool operator > (Rational &rat)
    {
        if((*this - rat).nominator > 0) {return true;}
        else if ((*this - rat).nominator < 0){return false;}
        else
        {
            return (*this == rat);
        }
        
    }

    bool operator < (Rational &rat)
    {
        return !(*this > rat);
    }

    bool operator == (Rational &rat)
    {
        if((*this - rat).nominator == 0) {return true;}
        else {return false;}
    }


};


int main()
{
    Rational mass[5];

    for(int i = 0; i < 5; i++)
    {
        Rational rat('c');
        mass[i] = rat;
    }

    Rational maximum = mass[0].Abs();

    for(int i = 1; i < 5; i++)
    {
        if(mass[i].Abs() > maximum)
        {
            maximum = mass[i];
        }
    }

    cout << maximum.GetNominator() << "/" << maximum.GetDenominator() << endl;

    return 0;
}