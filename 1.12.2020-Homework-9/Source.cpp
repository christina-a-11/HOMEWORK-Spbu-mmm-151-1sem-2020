#include<iostream>
#include <string>
using namespace std;

void resolveError(int errorCode)
{
    string error11 = "sorry this is not a number"; 
    string error12 = "the number must not contain other characters";
    string error13 = "please, enter a number like 12345";
    string error21 = "cannot handle such a large number";
    string error22 = "you number is too big!";
    string error23 = "please, enter a number more than -9223372036854775809 and less than 9223372036854775809";
    string error31 = "double must contain .";
    string error32 = "please, enter double through .";
    string error33 = "please, enter a number like 12.345";

    string errors1[3] = { error11, error12, error13 };
    string errors2[3] = { error21, error22, error23 };
    string errors3[3] = { error31, error32, error33 };
    srand(8);
    if (errorCode == 1)
    {
        cout << errors1[rand() % 2] << endl;
    }
    if (errorCode == 2)
    {
        cout << errors2[rand() % 2] << endl;
    }
    if (errorCode == 3)
    {
        cout << errors3[rand() % 2] << endl;
    }
}

int readInt(long long& number) 
{
    string temp;
    getline(cin, temp);
    while (temp.size() == 0)
    {
        getline(cin, temp);
    }
    string str;
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        if (temp[i] >= '0' && temp[i] <= '9')
        {
            str.operator+=(temp[i]);
        }
    }
    if (str.size() == 0)
    {
        return 1;
    }
    else  if (str.size() > 19)
    {
        return 2;
    }
    else
    {
        long long step = 1;
        for (int i = 0; i < str.size(); i++)
        {
            long long t = (long long)(str[i] - '0');
            number += t * (step);
            step *= 10;
        }
        return -1;
    }
}
double readDouble(double& number)
{
    string temp;
    getline(cin, temp);
    while (temp.size() == 0)
    {
        getline(cin, temp);
    }
    string str;
    bool flag = false;
    int index = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == '.')
        {
            index = i;
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        return 3;
    }
    for (int i = 0; i < index; i++)
    {
        if (temp[i] >= '0' && temp[i] <= '9')
        {
            str.operator+=(temp[i]);
        }
    }
    if (str.size() == 0)
    {
        int observation = 0;
        for (int i = index + 1; i < temp.size(); i++)
        {
            while (observation <= 3)
            {
                if (temp[i] > '0' && temp[i] <= '9')
                {
                    str.operator+=(temp[i]);
                }
            }
        }
        int step = 1;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            int t = (long long)(str[i] - '0');
            number += (double)(t * (step));
            step *= 10;
        }
        number = number / 10;
        return -1;
    }
    else if (str.size() > 19)
    {
        return 2;
    }
    else
    {
        int step = 1;
        for (int i = 0; i <str.size(); i++)
        {
            int t = (long long)(str[i] - '0');
            number += t * (step);
            step *= 10;
        }
        string str2;
        double mant = 0;
        int observation = 0;
        for (int i = index + 1; i < temp.size(); i++)
        {
                if (temp[i] > '0' && temp[i] <= '9' && observation < 3)
                {
                    str2.operator+=(temp[i]);
                    observation++;
                }
        }
        step = 1;
        double number2 = 0;
        for (int i = str2.size() - 1; i >= 0; i--)
        {
            int t = (long long)(str2[i] - '0');
            number2 += (double)(t * (step));
            step *= 10;
        }
        step = 1;
        for (int i = 0; i < str2.size(); i++)
        {
            step *= 10;
        }
        number = number + number2 * ((double)1 / step);
    }
    return -1;
}
double sum(long long a, double b)
{
    return double(a) + b;
}

int main()
{
	long long number1 = 0;
	double number2 = 0;
    int error1 = 0;
    int error2 = 0;
    do
    {
        error1 = readInt(number1);
        error2 = readDouble(number2);
        if (error1 > -1)
        {
            resolveError(error1);
        }
        else if (error2 > -1)
        {
            resolveError(error2);
        }
        else
        {
            break;
        }
    } while (true);
   cout << sum(number1, number2);

	system("pause>nul");
	return 0;
}