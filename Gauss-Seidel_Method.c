#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{

    //2x + 3y + 0z = 15  x = (15 - 3y) / 2
    //x + 0y + 2z = 11   z = (11 - x) / 2
    //x + 2y + z = 13    y = (13 - x - z) / 2

    //[x y z] = [2 2 2] e <= 0.01
    double x = 2, y = 2, z = 2;
    double dx = 0, dy = 0, dz = 0;
    double fx(double y)
    {
        return (15 - 3 * y) / 2;
    }

    double fy(double x, double z)
    {
        return (13 - x - z) / 2;
    }

    double fz(double x)
    {
        return (11 - x) / 2;
    }
    double hata(double old, double new)
    {
        return fabs((new - old) / new);
    }

    printf("\ni x        z        y        Ex       Ez       Ey");
    printf("\n0 %f %f %f %f %f %f", x, z, y, dx, dz, dy);
    for (int i = 1; i < 11; i++)
    {
        dx = hata(x, fx(y));
        x = fx(y);
        printf("\n%d %f ", i, x);

        dz = hata(z, fz(x));
        z = fz(x);
        printf("%f ", z);

        dy = hata(y, fy(x, z));
        y = fy(x, z);
        printf("%f %f %f %f", y, dx, dz, dy);
        if(dx <= 0.01 && dy <= 0.01 && dz <= 0.01) break;
    }
}