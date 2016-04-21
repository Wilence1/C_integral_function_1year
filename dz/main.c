#include <stdio.h>
#include <math.h>
float f1(float x)
{
    return 1 + 4.0 / (x * x + 1);
}
float f2(float x)
{
    return pow(2, -x);
    //return x * x;
}
float f3(float x)
{
    return pow(x, 3);
   // return x * x;
}
float root(float(*f)(float), float(*g)(float), float a, float b, float eps1, float x)
{
    //первая производная и вторая производная. знаки
    float vala = f(a) - g(a);
    float valb = f(b) - g(b);
    float mid = (a + b) / 2.0;
    int sign1;
    int sign2;
    float valmid = f(mid) - g(mid);
      if(vala < valb)
        sign1 = 1;
    else
        sign1 = -1;
     if(valmid > (vala + valb) / 2.0)
        sign2 = -1;
    else
        sign2 = 1;
    
    float c;
    float valc;
    float valc_eps;
    if(sign1 * sign2 == 1)
    {
        c = a;
    }
    else
    {
        c = b;
        eps1 = -eps1;
    }
    do
    {
        //printf("%f ", c);
        if(sign1 * sign2 == 1)
        {
            a = c;
            vala = f(a) - g(a);
        }
        else
        {
            b = c;
            valb = f(b) - g(b);
        }
        c = (a * valb - b * vala) / (valb - vala);
        valc = f(c) - g(c);
        valc_eps = f(c + eps1) - g(c + eps1);
        
        
    }while(valc * valc_eps > 0);
    return c;
}
float integral(float(*f)(float), float a, float b, float eps2)
{
    int n = 10;
    float h = (b - a) / n;
    float ans1 = 0;
    for(int i = 0; i < n; i++)
    {
        float r = a + h * (i + 0.5);
        float valr = f(r);
        ans1 = ans1 + valr;
    }
    ans1 = ans1 * h;
    float ans2 = ans1;
    float check;
    do
    {
        ans1 = ans2;
        n = n * 2;
        h = (b - a) / n;
        ans2 = 0;
        for(int i = 0; i < n; i++)
        {
            float r = a + h * (i + 0.5);
            float valr = f(r);
            ans2 = ans2 + valr;
        }
        ans2 = ans2 * h;
        check = ans1 - ans2;
        if(check < 0)
            check = -check;
            
    }while(check >= 3 * eps2);
    return ans2;
}

int main()
{
    float x1 = root(f3, f2, 0.5, 1, 0.0001, 0);
    float x2 = root(f3, f1, 1, 1.8, 0.0001, 0);
    float x3 = root(f2, f1, -2, -1, 0.0001, 0);
    printf("%f %f %f \n", x1, x2, x3);
    float s1 = integral(f2, x3, x1, 0.0001);
    //float s1 = integral(f2, 0, 3, 0.0001);
    //printf("%f", s1);
    float s2 = integral(f1, x3, x2, 0.0001);
    float s3 = integral(f3, x1, x2, 0.0001);
    printf("%f", s2 - s1 - s3);
    return 0;
}