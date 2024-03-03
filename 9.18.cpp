#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

// Функция F(x,y)
double f(double x, double y)
{
    return x - y ;
}

// Функция вычисление объёма
double V(int N)
{
    // координаты точек
    double x = 0;
    double y = 0;
    // число точек, попавших в область D
    double n = 0;
    // граница по х и у
    double xmin = 0;
    double xmax = 1;
    double ymin = -1;
    double ymax = 0;
    // площадь, объём и высота
    double S = 0;
    double H = 0;
    double V = 0;
    double r1 = (double)rand() * 1 / RAND_MAX;
    double r2 = (double)rand() * 1 / RAND_MAX;
    for (long int i = 0; i < N; i++)
    {
        r1 = (double)rand() * 1 / RAND_MAX;
        r2 = (double)rand() * 1 / RAND_MAX;
        x = xmin + r1 * (xmax - xmin);
        y = ymin + r2 * (ymax - ymin);
        if (x > 0 && y*y + x*x < 1 && y < 0)
        {
            n++;
            H = H + (f(x, y));
        }


    }

    // средняя высота
    H = H / n;
    // Вычисление площади
    S = (xmax - xmin) * (ymax - ymin) * (n / N);
    // объём
    V = H * S;
    return V;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int N = 0;
    cout << "Введите количество точек ";
    cin >> N;
    cout << "Объём фигуры = " << V(N) << endl;
}

