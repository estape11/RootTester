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
  T rootBrent(const std::function<T(T)>& funct,T xl,T xu,const T eps = sqrt(std::numeric_limits<T>::epsilon())) {
    T fl=funct(xl);
    T fu=funct(xu);
    if (stb::abs(fl)<std::abs(fu)){
      T xSwap=T(xl);
      xl=T(xu);
      xu=T(xSwap);
    }
    T c=T(xu);
    bool mflag=true;


    // Return NaN if no root was found
    return std::numeric_limits<T>::quiet_NaN();
  }
}
  
#endif

