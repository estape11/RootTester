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
  T rootSecant(const std::function<T(T)>& funct,T xi,T xii,const T eps=sqrt(std::numeric_limits<T>::epsilon())) {
      const int max = std::numeric_limits<T>::digits;
      T n = T(0);
      T xm = T(0);
      T x0 = T(0);
      T c = T(0);
      if (funct(xi) * funct(xii) < 0) {
          do {
              x0 = (xi * funct(xii) - xii * funct(xi)) / (funct(xii) - funct(xi));
              c = funct(xi) * funct(x0);
              xi = xii;
              xii = x0;
              n++;
              if (c == 0)
                  break;
              xm = (xi * funct(xii) - xii * funct(xi)) / (funct(xii) - funct(xi));
          } while (fabs(xm - x0) >= eps);
          return x0;
      }else
          // Return NaN if no root was found
          return std::numeric_limits<T>::quiet_NaN();
  }

}
  
#endif

