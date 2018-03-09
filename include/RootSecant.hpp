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
    const int max=std::numeric_limits<T>::digits;
      T rs = T(0);
      T xl = T(0);
      T temp = T(0);
      T fl= funct(xi);
      T f = funct (xii);
      T dx=T(0);
      if(fabs(fl)<fabs(f)){
          rs = xi;
          xi=xii;
          temp = fl;
          fl = f;
          f = temp;
      }else {
          xl=xi;
          rs = xii;
      }
      for(int j=1; j <= max; j++){
          dx = (xl - rs) * f/(f - fl);
          xl = rs;
          fl = f;
          rs += dx;
          f = funct(rs);
          if(fabs(dx)<eps || f == 0.0)
              return rs;
      }
      // Return NaN if no root was found
      return std::numeric_limits<T>::quiet_NaN();
  }

}
  
#endif

