/*
 * Circle.h
 *
 *  Created on: Nov 8, 2016
 *      Author: matenemeth
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle {
  public:
    Circle (double rad_in);
    double get_circumference();
    double get_area();
  private:
    double radius;
};

#endif /* CIRCLE_H_ */
