/**
 * Copyright (C) 2018
 * Área Académica de Ingeniería en Computadoras, TEC, Costa Rica
 *
 * This file is part of the CE3102 Numerical Analysis lecture at TEC
 *
 * @Author: 
 * @Date  : 24.02.2018
 */

#include <cstdlib>
#include <iostream>
#include <RootInterpolation.hpp>
#include <RootSecant.hpp>
#include "RootBisection.hpp"

double test(const double x) {
    static const double pi = 3.14159265358979323846264338327950288; 
    return 0.5*std::exp(-x)-5.0*std::cos(pi*x);
}


double t1(const double x) {
    return std::abs(x) - std::exp(-x);
}

int main() {

    // Put your main code in here

    std::cout << "Nothing done yet!" << std::endl; // REMOVE-ME!
    double xl = 0.0; // l ́ımite inferior del intervalo 
    double xu = 2.0; // l ́ımite superior del intervalo
    std::cout<<anpi::rootBisection<double>(t1,xl,xu)<<std::endl;
    std::cout<<"hola"<<std::endl;
    std::cout<<anpi::rootInterpolation<double>(t1,xl,xu)<<std::endl;
    std::cout<<"hola"<<std::endl;
    std::cout<<anpi::rootSecant<double>(t1,xl,xu)<<std::endl;
    return EXIT_FAILURE;
}

