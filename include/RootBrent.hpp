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

#ifndef ANPI_ROOT_BRENT_HPP
#define ANPI_ROOT_BRENT_HPP

namespace anpi {

    /**
     * Find the roots of the function funct looking for it in the
     * interval [xl,xu], using the Brent's method.
     *
     * @param funct a std::function of the form "T funct(T x)"
     * @param xl lower interval limit
     * @param xu upper interval limit
     *
     * @return root found, or NaN if none could be found.
     *
     * @throws anpi::Exception if inteval is reversed or both extremes
     *         have same sign.
     */
    template<typename T>
    T rootBrent(const std::function<T(T)> &funct, T xl, T xu, const T eps = sqrt(std::numeric_limits<T>::epsilon())) {
        // xl=a xu=b
        T fl = funct(xl);
        T fu = funct(xu);
        if (stb::abs(fl) < std::abs(fu)) {
            T xSwap = T(xl);
            xl = T(xu);
            xu = T(xSwap);
            fl = funct(xl);
            fu = funct(xu);
        }
        T c = T(xl);
        T fc = funct(c);
        T xs = T(0);
        bool mflag = true;
        for (int i = maxi; i > 0; i--) {
            if (fl != fc && fu != fc) {
                xs = (xl * fu * fc) / ((fl - fu) * (fl - fc)) + (xu * fl * fc) / ((fu - fl) * (fu - fc)) +
                     (c * fl * fc) / ((fc - fl) * (fc - fu));
            } else {
                xs = b - fu * (xu - xl) / (fu - fl);
            }
            if (!((3 * xl + b) / 4 < xs < xu) ||
                    (mflag && std::abd(xs-xu)>=std::abs(b-c)/2)){

            }
        }

        // Return NaN if no root was found
        return std::numeric_limits<T>::quiet_NaN();
    }
}

#endif

