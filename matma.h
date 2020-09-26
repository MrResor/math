#pragma once
#include <iostream>
#include "math.h"

using namespace std;

class fraction
{
    private:
        int nominator, denominator;
        bool negative;
    public:
        fraction()
        {
            nominator = 1;
            denominator = 1;
            negative = false;
        }
        fraction(int nom, int denom)
        {
            nominator = nom;
            denominator = denom;
            if (nom < 0)
            {
                if(denom < 0)
                {
                    negative = false;
                }
                else
                {
                    negative = true;
                }
                
            }
            else
            {
                if(denom < 0)
                {
                    negative = true;
                }
                else
                {
                    negative = false;
                }
            } 
        }
        void simplify()
        {
            if(denominator == 0)
            {
                cout <<"There cannot be a 0 in denominator!\n\n";
            }
            else
            {          
                int *nominator_divisors,*denominator_divisors;
                int count = 0;
                for(int i = 2;i<=sqrt(nominator);i++)
                {
                    if(nominator%i == 0)
                    {
                        count++;
                    }
                }
                nominator_divisors = (int*)malloc((count+1)*sizeof(int));
                nominator_divisors[0] = 1;
                count = 1;
                double end_term;
                if(sqrt(nominator)<=denominator)
                {
                    end_term = sqrt(nominator);
                }
                else
                {
                    end_term = denominator;
                }
                for(int i = 2;i<=end_term;i++)
                {
                    if(nominator%i == 0)
                    {
                        nominator_divisors[count] = i;
                        count++;
                    }
                }
                nominator_divisors[count] = nominator;
                count = 0;
                if(sqrt(denominator)<=nominator)
                {
                    end_term = sqrt(denominator);
                }
                else
                {
                    end_term = nominator;
                }
                for(int i = 2;i<=end_term;i++)
                {
                    if(denominator%i == 0)
                    {
                        count++;
                    }
                }
                denominator_divisors = (int*)malloc((count+1)*sizeof(int));
                denominator_divisors[0] = 1;
                count = 1;
                for(int i = 2;i<=end_term;i++)
                {
                    if(denominator%i == 0)
                    {
                        denominator_divisors[count] = i;
                        count++;
                    }
                }
                denominator_divisors[count] = denominator;
                count = sizeof(nominator_divisors)/sizeof(nominator_divisors[0]);
                int size = sizeof(denominator_divisors)/sizeof(denominator_divisors[0]);
                int greatest_common_divisor;
                for(int i = 0; i <=count;i++)
                {
                    for(int j = 0; j<=size; j++)
                    {
                        if(nominator_divisors[i] == denominator_divisors[j])
                        {
                            greatest_common_divisor = nominator_divisors[i];
                        }
                    }
                }
                nominator /=greatest_common_divisor;
                denominator /= greatest_common_divisor;
                if(greatest_common_divisor == 1)
                {
                    cout <<"This already is simplified fraction\n\n";
                }
                else
                {
                    cout <<"Simplified fraction : "<< nominator << "/" << denominator << endl;
                }
            }
        }
        void expand(int a)
        {
            if(denominator == 0)
            {
                cout <<"There cannot be a 0 in denominator!\n\n";
            }
            else
            {
                nominator *= a;
                denominator *= a;
                cout <<"Expanded fraction : " << nominator << "/" << denominator << endl;
            }
        }
        fraction operator +(const fraction other)
        {
            fraction result;
            result.nominator = nominator*other.denominator + other.nominator*denominator;
            result.denominator = denominator*other.denominator;
            result.simplify();
            return result;
        }
        fraction operator -(const fraction other)
        {
            fraction result;
            result.nominator = nominator*other.denominator - other.nominator*denominator;
            result.denominator = denominator*other.denominator;
            result.simplify();
            return result;
        }
        fraction operator *(const fraction other)
        {
            fraction result;
            result.nominator = nominator*other.nominator;
            result.denominator = denominator*other.denominator;
            result.simplify();
            return result;
        }
        fraction operator /(const fraction other)
        {
            fraction result;
            result.nominator = nominator*other.denominator;
            result.denominator = denominator*other.nominator;
            result.simplify();
            return result;
        }
        friend ostream &operator<<(ostream &output, const fraction &fraction_temp)
        {
            output << fraction_temp.nominator << "/" << fraction_temp.denominator ;
            return output;
        }
        friend istream &operator>>(istream &input, fraction &fraction_temp)
        {
            cout << "Enter nominator of the fraction: ";
            input >> fraction_temp.nominator;
            while(cin.fail())
            {
                cout << "Invalid entry , please enter number"<< endl;
                input.clear();
                input.ignore(numeric_limits<streamsize>::max(), '\n');
                input >> fraction_temp.nominator;
            }
            cout << "Enter denominator of the fraction: ";
            input >> fraction_temp.denominator;
            while(cin.fail())
            {
                cout << "Invalid entry , please enter number"<< endl;
                input.clear();
                input.ignore(numeric_limits<streamsize>::max(), '\n');
                input >> fraction_temp.denominator;
            }
            getchar();
            return input;
        }
};

class matrix
{
    private:
        int m,n;
        double **array;
    public:
        matrix(int a, int b)
        {
            if ( a <= 0 || b <= 0)
            {
                cout << "this is incorrect matrix!\n\n";
            }
            else
            {
                m = a;
                n = b;
                array = new double* [m];
                for(int i = 0; i < m; ++i)
                {
                    array[i] = new double [n];
                }
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0 ;j < n; j++)
                    {
                        array[i][j] = 0;
                    }
                }
            }
        }
        void print()
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0 ;j < n; j++)
                {
                    cout << array[i][j] << " ";
                }
                cout << endl;
            }
        }
};

double root(double base_of_root,double degree_of_root)
{
    return pow(base_of_root,1/degree_of_root);
}