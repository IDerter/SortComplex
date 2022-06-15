#include <iostream>
#include "Complex.h"
std::ostream& operator<<(std::ostream& os, const Complex& complex) //возвращает ссылку на объект типа ostream
{
    os << complex.re << ' ' << complex.im;
    return os;
}
void Sort(int size, vector <Complex>& mascom, vector <float>& mas)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < (size - i - 1); j++)
        {
            if (mascom[j].mod() > mascom[j + 1].mod())
            {
                std::swap(mascom[j], mascom[j + 1]);
                std::swap(mas[j], mas[j + 1]);
            }
        }
    }
}
void Print(int size, vector <Complex>& mascom, vector <float>& mas)
{
    cout << "Отсортированный вариант "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Модуль: " << mas[i] << " Число: " << mascom[i] << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    fstream s1;
    int n = 0;
    float re = 0;
    float im = 0;
    string str;
    s1.open("D:\\complex.txt");
    s1 >> n;
    cout << n << endl;
    vector <Complex> v1;
    double max = 0;
    for (int i = 0; i < n; i++)
    {
        s1 >> re;
        s1 >> im;
        Complex x{ re, im };
        v1.push_back(x);
    }
    Complex a1{ 0,0 };
    vector <float> modvec;
    for (int i = 0; i < v1.size(); i++) {
        a1 = { v1[i].re, v1[i].im };
        float modcom = 0;
        modcom = v1[i].mod();
        modvec.push_back(modcom);
    }
    for (int i = 0; i < v1.size(); i++) 
    {
        cout << "Модуль: "<<modvec[i] << " Число: " << v1[i] << endl;
    }
    Sort(n, v1,modvec); //вызов функции сортировки
    Print(n, v1, modvec);
}
