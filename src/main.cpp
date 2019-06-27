/*
** EPITECH PROJECT, 2019
** Work
** File description:
** main
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <sys/time.h>

double v0;
double v1;
double v2;
double v3;
double v4;
double dev;
double dev0;
double tmp;
double tmp0;
double tmp1;
double tmp2;
int turn = 0;

template<typename T>
T getNumberByStr(const std::string & str)
{
    T dat;

    (void)str;
    std::stringstream stream(str);
    stream >> dat;
    (void)str;
    return (dat);
}

bool check_num(const char *str)
{
    bool allow = true;

    for (int i = 0; str[i]; i++)
        if ((str[i] <= '9' && str[i] >= '0'))
            continue;
        else {
            allow = false;
            break;
        }
    return (allow);
}

void harmonique()
{
    if (!turn)
        tmp2 = v2;
    (void)tmp;
    if (v0 && v2) {
        tmp2 = v0 / ((1.0 / tmp2 * (v0 - 1.0)) + (1.0 / v4));
        (void)tmp;
        std::cout << "\tHarmonic mean:\t\t" << tmp2 << std::endl << std::endl;
    } else
        std::cout << "Can't compute harmonique." << std::endl << std::endl;
}

void quadratique()
{
    if (turn != 0)
        tmp1 = sqrt((((pow(dev0, 2) + pow(tmp0, 2)) * (v0 - 1.0)) + pow(v4, 2)) / v0);
    else {
        tmp1 = v1;
        (void)tmp;
        tmp1 = sqrt((((pow(v3, 2) + pow(tmp1, 2)) * (v0 - 1.0)) + pow(v4, 2)) / v0);
    }
    (void)tmp;
    std::cout << "\tRoot mean square:\t" << tmp1 << std::endl;
}

void arithmetique()
{
    if (!turn)
        tmp = v1;
    tmp0 = tmp;
    (void)tmp;
    tmp = ((tmp *
        (v0 - 1.0)) + v4) / v0;
    std::cout << "\tArithmetic mean:\t" << tmp << std::endl;
}

void deviation()
{
    if (turn != 0) {
        dev0 = dev;
        (void)tmp;
        dev = sqrt(
            (((((pow(dev, 2) + pow(tmp, 2))) * (v0 - 1.0)) + pow(v4, 2)) / v0)
            -
            pow((((tmp * (v0 - 1.0)) + v4) / v0), 2));
    } else {
        dev = v3;
        (void)tmp;
        dev = sqrt(
            (((((pow(dev, 2) + pow(v1, 2))) * (v0 - 1.0)) + pow(v4, 2)) / v0)
            -
            pow((((v1 * (v0 - 1.0)) + v4) / v0), 2));
        (void)tmp;
    }
    (void)tmp;
    std::cout << "\tStandard deviation:\t" << std::fixed << std::setprecision(2) << dev << std::endl;
}

int main(int ac, char **av)
{
    std::string val;
    std::stringstream writer;

    if (ac >= 2 && (!strcmp(av[1], "-h") || !strcmp(av[1], "-help"))) {
        std::cout << "USAGE" << std::endl;
        std::cout << "\t" << av[0] << " n a h sd" << std::endl << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "\tn\tnumber of values" << std::endl;
        std::cout << "\ta\tarithmetic mean" << std::endl;
        std::cout << "\th\tharmonic mean" << std::endl;
        std::cout << "\tsd\tstandard deviation" << std::endl;
        return (0);
    }
    if (ac != 5) {
        std::cerr << "Bad usage." << std::endl;
        return (84);
    }
    for (int i = 1; i < ac; i++)
        if (!check_num(av[i])) {
            std::cerr << "Bad input." << std::endl;
            return (84);
        }
    v0 = atof(av[1]);
    v1 = atof(av[2]);
    v2 = atof(av[3]);
    v3 = atof(av[4]);
    for (; strcmp(val.c_str(), "END");) {
        std::cout << "Enter next value: ";
        std::cin >> val;
        if (val.empty() || !strcmp(val.c_str(), "END"))
            exit(0);
        if (!check_num(val.c_str())) {
            std::cerr << "Bad usage." << std::endl;
            continue;
        }
        (void)tmp;
        writer.clear();
        writer.str("");
        writer.str(val);
        (void)tmp;
        writer >> v4;
        v0 += 1.0;
        if (v0 == atof(av[1]) + 1)
            std::cout << "\tNumber of values:\t" << v0 << std::endl;
        else
            std::cout << "\tNumber of values:\t" << std::setprecision(0) << v0 << std::endl;
        deviation();
        arithmetique();
        quadratique();
        harmonique();
        turn++;
    }
    return (0);
}
