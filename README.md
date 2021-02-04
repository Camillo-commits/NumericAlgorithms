# NumericAlgorithms
## Bisekcja.hpp
Method for finding x, where f(x) = 0. In each iteration it divides given section in half. Value of the fuction in starting points needs to be in opposite signs. 
## styczne.hpp 
Method for finding x, where f(x) = 0. Based uppon function f(x) and it's derivative.
## sieczne.hpp
Method for finding x, where f(x) = 0. Based uppon function f(x) and approximation of it's derivative.
## MN_Newton_Raphson.hpp
Algorithm used for solving nonlinear system of equations, based on multivariable functions and their derivatives.
## calkowanieGeometryczne.hpp
Algorithms for geometrical approximation of integrals.
## MonteCarlo.hpp & Simpson.hpp & kwadratury_gaussa-legendrea.h
Different approach to approximation of integrals.  
* Simpson - each iteration creates parable that is used to calculate surface beneath function.
* Monte Carlo - uses random points to calculate the integral.
* Gauss-Legendre - uses specially set up points and their significance to approximate integral.
## metoda_eulera.h & Rungego-Kutty.hpp
Numeric method for calculating function value in given point, in Cauchy problem. It gives as only information about derivative of the function and one f(x) = y value.
