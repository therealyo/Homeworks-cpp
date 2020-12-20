#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


class Polynom
{
private:
    vector<float> coefs;

public:
    Polynom() {
        coefs = {};
    }

    Polynom(const Polynom &poly) {}

    Polynom(vector<float> cfs)
    {
        coefs = cfs;
    }

    Polynom(const int size)
    {
        for(int i = 0; i < size; ++i)
        {
            float coef;
            cin >> coef;
            coefs.push_back(coef);
        }
    }

    vector<float> GetCoefs()
    {
        return this->coefs;
    }

    void SetCoefs(vector<float> vals)
    {
        this->coefs = vals;
    }

    void PrintPolynom()
    {
        cout << GetCoefs()[0] << " + ";
        for(int i = 1; i < GetCoefs().size() - 1; ++i)
        {
            cout << GetCoefs()[i] << "x^" << i << " + ";
        }
        cout << GetCoefs()[GetCoefs().size() - 1] << "x^" << GetCoefs().size() - 1;
        cout << endl;
    }

    float CalculateValue(float x)
    {
        float res = 0;
        
        for(int i = 0; i < GetCoefs().size(); ++i)
        {
            res += GetCoefs()[i] * pow(x, i);
        }

        return res;
    }

    Polynom FindDerivative(Polynom poly)
    {
        Polynom derivative;
        
        for(int i = 1; i < poly.GetCoefs().size(); ++i)
        {
            derivative.GetCoefs().push_back(poly.GetCoefs()[i] * i);
        }

        return derivative;
    }

    Polynom operator+(Polynom &poly)
    {
        Polynom res(this->GetCoefs());


        if (coefs.size() < poly.GetCoefs().size())
        {
            for(int i = coefs.size(); i < poly.GetCoefs().size(); ++i)
            {
                res.GetCoefs().push_back(poly.GetCoefs()[i]);
            }
        }
        else
        {
            for(int i = 0; i < coefs.size(); ++i)
            {
                res.GetCoefs()[i] = res.GetCoefs()[i] + poly.GetCoefs()[i];
            }
        }
        
        this->SetCoefs(res.GetCoefs());

        return *this;
    }

    Polynom operator-(Polynom &poly)
    {
        Polynom res(this->GetCoefs());


        if (coefs.size() < poly.GetCoefs().size())
        {
            for(int i = coefs.size(); i < poly.GetCoefs().size(); ++i)
            {
                res.GetCoefs().push_back(-(poly.GetCoefs()[i]));
            }
        }
        else
        {
            for(int i = 0; i < coefs.size(); ++i)
            {
                res.GetCoefs()[i] = res.GetCoefs()[i] - poly.GetCoefs()[i];
            }
        }

        this->SetCoefs(res.GetCoefs());
        return *this;
    }

    Polynom operator * (Polynom &poly)
    {
        Polynom res;

        for(int i = 0; i < this->GetCoefs().size() + poly.GetCoefs().size(); i++)
        {
            res.GetCoefs().push_back(0);
        }
        
        for(int i = 0; i <= res.GetCoefs().size(); ++i)
        {
            for(int j = 0; j <= poly.GetCoefs().size();j++)
                {
                    res.GetCoefs()[i+j] += this->GetCoefs()[i] * poly.GetCoefs()[j];
                }
        }

        this->SetCoefs(res.GetCoefs());
        return *this;
    }

};


int main()
{
    Polynom poly1(3), poly2(3);

    poly1.PrintPolynom();
    poly2.PrintPolynom();

    Polynom res = poly1  - poly2;

    res.PrintPolynom();

}