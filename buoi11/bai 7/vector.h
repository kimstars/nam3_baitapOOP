#include <bits/stdc++.h>

using namespace std;

class Vector
{
private:
    int n;
    double *vec;

public:
    Vector();
    Vector(int size);
    Vector(Vector &v);
    Vector(double a[], int n);
    ~Vector(){};

    friend ostream &operator<<(ostream &, Vector &);
    friend istream &operator>>(istream &, Vector &);

    double operator[](int i) const //  index  operator  -  toan  tu  chi  so
    {
        if (i >= 0 && i <= n)
            return vec[i];
        return 0.0f;
    }
    void operator=(const Vector &f);
    bool operator==(const Vector &f);
    Vector operator+(const Vector &);
    Vector operator-(const Vector &);
    Vector operator*(const Vector &);
    Vector operator*(double);
    double operator()(double x) const
    {
        return evalue(x);
    }
    double evalue(double x) const;
    
};
Vector::Vector()
{
    n = 0;
}
Vector::Vector(int size)
{
    this->n = size;
    vec = new double[size + 1];
}
Vector::Vector(Vector &a)
{
    n = a.n;
    vec = new double[n];
    for (int i = 0; i < n; i++)
        vec[i] = a.vec[i];
}

Vector::Vector(double a[], int n1)
{
    n = n1;
    vec = new double[n + 1];
    int i;
    for (i = 0; i <= n; ++i)
        vec[i] = a[i];
}

void Vector::operator=(const Vector &a)
{
    n = a.n;
    vec = new double[n];
    for (int i = 0; i < n; i++)
        vec[i] = a.vec[i];
}

ostream &operator<<(ostream &os, Vector &a)
{
    os << "\nn = " << a.n << endl;
    for (int i = 0; i < a.n; i++)
    {
        os << a.vec[i] << " ";
    }
    os << endl;
    return os;
}

istream &operator>>(istream &is, Vector &a)
{
    cout << "Nhap so luong phan tu : ";
    is >> a.n;
    a.vec = new double[a.n];
    cout << "Nhap " << a.n << " phan tu: ";
    for (int i = 0; i < a.n; i++)
    {
        is >> a.vec[i];
    }
    return is;
}
bool Vector::operator==(const Vector &a)
{
    if (this->n != a.n)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (vec[i] != a.vec[i])
                return 0;
            /* code */
        }
        return 1;
    }
}

Vector Vector::operator+(const Vector &a)
{

    if (n == a.n)
    {
        Vector c(n);
        for (int i = 0; i < a.n; i++)
            c.vec[i] = a.vec[i] + vec[i];
        return c;
    }
    else
    {
        cout << "Khong the cong hai vector khong cung do dai\n";
    }
}

Vector Vector::operator-(const Vector &a)
{

    if (n == a.n)
    {
        Vector c(n);
        for (int i = 0; i < a.n; i++)
            c.vec[i] = vec[i] - a.vec[i];
        return c;
    }
    else
    {
        cout << "Khong the tru hai vector khong cung do dai\n";
    }
}

Vector Vector::operator*(double d){

        double *vec1;
        vec1 = new double[n];
        for (int i = 0; i <= n; ++i)
            vec1[i] = (Vector(*this))[i] * d;
        return Vector(vec1, n);
}


