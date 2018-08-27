/*
  Daniel Charua

   Simple program to try out the 3DVector class
*/

#include <iostream>
#include "Vector3D.h"

using namespace std;

int main()
{
    Vector3D vec1 (3.6, 5.1, 2.4);
    Vector3D vec2 (2.8, 3.9, 6.7);
    Vector3D vec3;

    vec3 = vec1;
    vec3.operator=(vec1);
    vec3 = vec3;


    cout << "Vector 1: " << vec1 << endl;
    cout << "Vector 2: " << vec2 << endl;
    cout << "Vector 3: " << vec3 << endl;

    cout << "Addition: v3 = v1 + v2" << endl;
    vec3 = vec1 + vec2;
    cout << "Vector 3: " << vec3 << endl;

    cout << "Substraction: v2 = v3 - v1" << endl;
    vec2 = vec3 - vec1;
    cout << "Vector 2: " << vec2 << endl;

    cout << "Addition: v2 += v3" << endl;
    vec2 += vec3;
    cout << "Vector 2: " << vec2 << endl;


    // Compare vectors 1 and 2
    if (vec1 == vec2)
    //if (vec1.operator==(vec2))
        cout << "V1 == V2" << endl;
    else
        cout << "V1 != V2" << endl;

    vec3 = vec1;

    // Compare vectors 1 and 3
    if (vec1 == vec3)
        cout << "V1 == V3" << endl;
    else
        cout << "V1 != V3" << endl;


    return 0;
}
