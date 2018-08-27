//Vector3D, Stores Vectors in 3D space, Daniel Charua  31/08/2016
#include <iostream>
class Vector3D{
  private:
    double x;
    double y;
    double z;
  public:
    //Constructor
    Vector3D(double _x=0, double _y=0, double z=0);
    //Access method
    void setCoordinates(double _x=0, double _y=0, double z=0);
    Vector3D & operator= (const Vector3D & other);
    Vector3D & operator+= (const Vector3D & other);
    Vector3D & operator-= (const Vector3D & other);
    const Vector3D  operator+ (const Vector3D & other);
    const Vector3D  operator- (const Vector3D & other);
    bool operator== (const Vector3D & other);
    bool operator!= (const Vector3D & other);

    friend std::ostream & operator<<(std::ostream & stream, const Vector3D & vector);
};
