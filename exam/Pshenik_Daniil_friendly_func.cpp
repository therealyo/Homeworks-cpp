#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/*Дружній метод класу - це метод, який має доступ до приватних полів класу.
Для використання потрібно в оголошенні класу зазначити friend type method_name(variables);
Аналогічно задається означення дружнього класу. Для використання дружнього класу потрібно в оголошенні
класу зазначити friend class ClassName;
Дружні методи та класи не мають доступу до вказівника this, оскільки вони не є методами класу.
Оператори вводу та ввиводу повинні буди дружніми, оскільки повинні мати доступ до приватних полів класу. */

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
        int temp = nominator;
        nominator   /= GreatestCommonDivisor(nominator, denominator);
        denominator /= GreatestCommonDivisor(temp, denominator);
    }


public:
    Rational()
    {
        cout << "Enter rational number: ";
        int nom, den;
        cin >> nom >> den;
        if (den != 0)
        {
            nominator = nom;
            denominator = den;
            while (GreatestCommonDivisor(nominator, denominator) != 1)
            {
                this->Decrease();
            }
        }
        else
        {
                cout << "Wrong denominator" << endl;
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

    friend std::ostream& operator<<(std::ostream& os, const Rational& rat);
    friend std::ofstream& operator<<(std::ofstream& ofs, const Rational& rat);
};

std::ostream& operator<< (std::ostream& os, const Rational& rat)
{
    if (rat.denominator != 1)
    {
        os << rat.nominator << "/" << rat.denominator << endl;
        return os;
    }
    else
    {
        os << rat.nominator << endl;
        return os;
    }
    
}

std::ofstream& operator<<(std::ofstream& ofs, const Rational& rat)
{
    if (rat.denominator != 1)
    {
        ofs << rat.nominator << "/" << rat.denominator << endl;
        return ofs;
    }
    else
    {
        ofs << rat.nominator << endl;
        return ofs;
    }
}

int main()
{
    Rational rat1, rat2;
    cout << rat1 << rat2 << endl;
    ofstream output("result.txt");
    output << rat1 << rat2;
}
