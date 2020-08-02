/* To find the area of a triangle given 2 sides and the angle subtended between them . Also round off the answer to 2 decimals .
User input sides -- integers
Angle -- float
*/



#include<iostream>
#include<cmath>
#include <bits/stdc++.h>

using namespace std;

float round2(float area){
    float value;
    value = (int) ((area*100) + 0.5);
    value = (float)value/100;
    return value;
}

int main(){
    int a = 4,b = 5;
    float area,h,angle_mod,angle;
    cout << "Enter the length of side 1 : ";
    cin >> a;
    cout << "Enter the length of side 2 : ";
    cin >> b;
    cout << "Enter the angle between side 1 and 2 : ";
    cin >> angle;
    
    angle_mod = (3.141/180)*angle;
    h = sin(angle_mod)*b;
    area = 0.5*h*a;
    cout << "Area of Triangle : " << area << endl;
    cout << "Area of Triangle rounded to 2 decimal : " << round2(area) << endl;
    return 0;
}