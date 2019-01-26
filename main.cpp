#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"
/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[])
{
    
    double a = 0;//used for saving numbers
    int c = 1;
    int p = 0;
    int nums = 0;//used for counting the amount of numbers
    bool xyCordChecker = true;//used to check which coordinate array the current value of a should be set in
    double sum = 0;
    int dotcount = 0;//amount of dots
    int tempX, tempY = 0;
    
    std::ifstream myReadFile;
    
    myReadFile.open(argv[1]);
    
    while (myReadFile >> a)
    {
        sum += a;
        nums++;
    }
    myReadFile.close();

    if (nums % 2) {
        std::cout<<"nums are odd";
        throw;
    }
    
    dotcount = nums / 2;
    
    Point* pntArr = new Point[dotcount];
    Point temp;

    myReadFile.open(argv[1]);//re-opens the file to save the numbers in the dynamic array
    while (myReadFile >> a)
    {
        if(c % 2){
            //Adds to Y
            temp.setY(a);
            pntArr[p] = temp;
            p++;
        }else{
            //Adds to X
            temp = Point(a,0);
        }
        c++;
    }

    myReadFile.close();
    
    Polygon basicShape(pntArr, dotcount);
    
    std::cout << "Area: " << basicShape.area() << std::endl;
    std::cout << "Shape type: " << basicShape.getType() << std::endl;
    std::cout << "Area size: " << basicShape.area() << std::endl;
    std::cout << "Circumference: " << basicShape.circumreference() << std::endl;
    std::cout << "Center point: " << basicShape.position().getX() << ", " << basicShape.position().getY() << std::endl;
    if (basicShape.isConvex() == true){
        std::cout << "The shape is convex" << std::endl;
    }
    else if (basicShape.isConvex() == false){
        std::cout << "The shape isn't convex" << std::endl;
    }
    

    return 0;
}