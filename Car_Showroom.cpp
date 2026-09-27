#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Car
{
protected:
string brand;
int model;
double price;
public:
Car(string b ,int m, double money):brand(b),model(m),price(money){}
virtual void display ()const{
cout << "brand=" <<brand<< endl;
cout << "model=" <<model<< endl;
cout << "price=" <<price<< endl;
}
virtual ~Car(){}
}; 
class carsale: public Car{
 private:
  int yearwarranty ;
  public:
  carsale(string b ,int m, double money,int y):Car(b,m,money),yearwarranty(y){}
  void display ()const override {
   Car::display();
   cout << "year warranty="<< yearwarranty<< endl;
   cout << "====================" << endl;
}
};

class carrent: public Car{
 private:
  int rentdays ;
  double daywage;
  public:
  carrent(string b ,int m, double money,int r, double d):Car(b,m,money),rentdays(r),daywage(d){}
   double totalcost ()const{
 return rentdays*daywage;
}
  void display ()const override{
   Car::display();
   cout << "rent days="<< rentdays<< endl;
   cout << "day wage="<< daywage<< endl;
   cout << "total cost="<<totalcost() << endl;
   cout << "====================" << endl;
}

};
class CarShowroom{
public:
vector<Car*>car;
void addcar(Car*c){
 car.push_back(c);
}
void printall(){
 for(size_t i=0;i<car.size();i++)
{
car[i]->display();
}
}

virtual~CarShowroom(){

for(size_t i=0;i<car.size();i++)
{
delete car[i];
}
car.clear();}
};


int main(){

CarShowroom c;
c.addcar(new carsale("bmw",2026,500000,2));
c.addcar(new carrent("bmw",2016,50000,2,500));
c.printall();


}
