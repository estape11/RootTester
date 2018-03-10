/**
 * Copyright (C) 2018
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * This file is part of the numerical analysis lecture CE3102 at TEC
 *
 * @Author: Pablo Alvarado
 * @Date  : 10.02.2018
 */

#include <cmath>
#include <limits>
#include <functional>

#include "Exception.hpp"

#ifndef ANPI_ROOT_SECANT_HPP
#define ANPI_ROOT_SECANT_HPP

namespace anpi {

    /**
     * Find a root of the function funct looking for it starting at xi
     * by means of the secant method.
     *
     * @param funct a functor of the form "T funct(T x)"
     * @param xi initial position
     * @param xii second initial position
     *
     * @return root found, or NaN if no root could be found
     */
    template<typename T>
    T rootSecant(const std::function<T(T)> &funct, T xi, T xii, const T eps = sqrt(std::numeric_limits<T>::epsilon())) {
        const int max = std::numeric_limits<T>::digits;
        T x2 = T(0);
        int n=0;
        do {
            n++;
            T fii = funct(xii);
            T fi = funct(xi);
            x2 = xii - (xi - xii) * (fii) / (fi - fii);
            if (std::abs(x2 - xii) < eps) {
                return x2;
            } else {
                xi = xii;
                xii = x2;
            }
        } while (n < max);
        // Return NaN if no root was found
        return std::numeric_limits<T>::quiet_NaN();
    }


}

#endif

