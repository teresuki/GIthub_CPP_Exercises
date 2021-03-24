#include <iostream>
#include <iomanip> // setprecision()
#include <math.h> // M_PI
#include <vector>
using namespace std;

class Point
{ private:
  double centerPointX;
  double centerPointY;
 public:
     //Constructor
     Point(){};

     //Get & Set
     double getX()
     {
         return centerPointX;
     }
     double getY()
     {
         return centerPointY;
     }
     void setX(double x)
     {
         this->centerPointX = x;
     }
     void setY(double y)
     {
         this->centerPointY = y;
     }


     void printCoordinate()
     {
         cout << "X: " << centerPointX << endl;
         cout << "Y: " << centerPointY << endl;
     }

     double computePointDistance(double x1, double y1)
     {
         double x, y;
         x = abs(centerPointX - x1);
         y = abs(centerPointY - y1);
         return sqrt(x*x + y*y);
     }

};

class Shape : public Point
{
public:
    Shape(){};
    virtual double computeCircumference() = 0;
    virtual double computeArea() = 0;
    virtual ~Shape(){};
};

class Circle: public Shape
{
private:
    double radius;
public:
    //Constructor:
    Circle(double radius, double pointX, double pointY){
      this->radius = radius;
      setX(pointX);
      setY(pointY);
    };

    //Get & Set
    double getX()
    {
        return Point::getX();
    }
    double getY()
    {
        return Point::getY();
    }

    double computeCircumference()
    {
        return 2* M_PI* radius;
    }
    double computeArea()
    {
        return M_PI* radius* radius;
    }
};

class Square: public Shape
{ private:
     double side;
public:
    // Constructor:
    Square(double side, double pointX, double pointY){
     this->side = side;
     setX(pointX);
     setY(pointY);
    };

    double computeCircumference()
    {
        return 4* side;
    }
    double computeArea()
    {
        return side* side;
    }
};

class Rectangle: public Shape
{
private:
   double width, height;
public:
    //Constructor
    Rectangle(double width, double height, double pointX, double pointY){
    this->width = width;
    this->height = height;
    setX(pointX);
    setY(pointY);
    };

    double computeCircumference()
    {
        return 2* (width+ height);
    }
    double computeArea()
    {
        return width* height;
    }
};

int main()
{
    Shape* myRec = new Rectangle(2, 3, 2, 0);
    Shape* myCir = new Circle(1, 0, 4);
    Shape* mySqr = new Square(3, 1, 1);

    cout << "Location of Rectangle:" << endl;
    myRec->printCoordinate();
    cout << "Location of Circle:" << endl;
    myCir->printCoordinate();
    cout << "Location of Square:" << endl;
    mySqr->printCoordinate();

    cout << "Distance of Rectangle and Circle: " << myRec->computePointDistance( myCir->getX(), myCir->getY() ) << endl;
    cout << "Distance of Circle and Square: " << myCir->computePointDistance( mySqr->getX(), mySqr->getY() ) << endl;
    cout << "Distance of Square and Rectangle: " << mySqr->computePointDistance( myRec->getX(), myRec->getY() ) << endl;

    return 0;
}

