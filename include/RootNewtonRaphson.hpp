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

#ifndef ANPI_NEWTON_RAPHSON_HPP
#define ANPI_NEWTON_RAPHSON_HPP

namespace anpi {

    /**
     * Find the roots of the function funct looking by means of the
     * Newton-Raphson method
     *
     * @param funct a functor of the form "T funct(T x)"
     * @param xi initial root guess
     *
     * @return root found, or NaN if none could be found.
     *
     * @throws anpi::Exception if inteval is reversed or both extremes
     *         have same sign.
     */
    template<typename T>
    T rootNewtonRaphson(const std::function<T(T)> &funct, T xi, const T eps = sqrt(std::numeric_limits<T>::epsilon())) {
        const int maxi = std::numeric_limits<T>::digits * 1000;
        T h = 0.000000001;
        T xnext = 0;
        T dxi = 0;

        for (int i = maxi; i > 0; i--) {
            dxi = (funct(xi + h) - funct(xi)) / h;

            xnext = xi - (funct(xi) / dxi);
            if (std::abs((xnext - xi) / xnext) * T(100) < eps || funct(xnext) == 0) return xnext;
            xi = xnext;
        }

        // Return NaN if no root was found
        return std::numeric_limits<T>::quiet_NaN();
    }

}

#endif
