#include "Vector3D.h"

Vector3D::Vector3D(double _x, double _y, double z){
  setCoordinates(_x, _y, z);
}
void Vector3D::setCoordinates(double _x, double _y, double z){
  x= _x;
  y= _y;
  this->z= z;
}
Vector3D & Vector3D::operator= (const Vector3D & other){
  if(this != &other){
  x = other.x;
  y = other.y;
  z = other.z;
  }
  return *this;
}
Vector3D & Vector3D::operator+= (const Vector3D & other){
  x += other.x;
  y += other.y;
  z += other.z;
  return *this;
}
Vector3D & Vector3D::operator-= (const Vector3D & other){
  x -= other.x;
  y -= other.y;
  z -= other.z;
  return *this;
}

const Vector3D Vector3D::operator+ (const Vector3D & other){
      Vector3D result = *this;
      result += other;
      return result;
      //return Vector3D(*this) +=other;
}
const Vector3D  Vector3D::operator- (const Vector3D & other){
  return Vector3D(*this) -=other;
}
bool Vector3D::operator== (const Vector3D & other){
  return (x==other.x && y==other.y && z==other.z);
}
bool Vector3D::operator!= (const Vector3D & other){
  return !(*this ==other);
}
std::ostream & operator<<(std::ostream & stream, const Vector3D & vector){
    stream << "[" << vector.x<< ", "<< vector.y<< ", "<< vector.z<< "]";
    return stream;
}
