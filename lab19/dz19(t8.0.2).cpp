#include <iostream>
using namespace std;


class Vector
{
private:
    int size;
    int *vector;

public:
    Vector(int size)
    {
        this->size = size;
        vector = new int[size];

        for(int i = 0; i < size; i++)
        {
            int temp = 0;
            cin >> temp;
            vector[i] = temp;
        }
    }

    Vector(const Vector& copy_vect)
    {
        vector = nullptr;
        
        if(copy_vect.vector != nullptr)
        {
            vector = copy_vect.vector;
        }

    }

    void SetVector()
    {
        for(int i = 0; i < size; i++)
        {
            int temp = 0;
            cin >> temp;
            vector[i] = temp;
        }
    }

    void SetElementConsole(int index)
    {
        int temp = 0;
        cin >> temp;
        vector[index] = temp;
    }

    void SetElement(int element, int index)
    {
        vector[index] = element;
    }

    int GetSize()
    {
        return size;
    }

    int* GetVector()
    {
        return this->vector;
    }

    ~Vector()
    {
        if(vector != nullptr)
        {
            delete[] vector;
        }
    }
};