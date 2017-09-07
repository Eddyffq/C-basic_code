#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car
{
     char maker[32];//制造商
     int price;//价格
};
struct Citizen
{
     char name[32];//名字
     int deposite;//存款
     Car* car;//NULL时表示没车
};
void buy(Citizen* owner)
{
     Car* car = (Car*)malloc(sizeof(Car));//创建对象
     strcpy(car.maker,"chevrolet");
     car.price = 10;
     //保存对象指针
     owner.car = car;//有车了
     owner.deposite -= car.price;//钱少了
}
void discard(Citizen* owner)
{
    free(owner.car);
    owner.car = NULL;
}
void sell(Citizen* owner,Citizen* other)
{
     Car* car = owner.car;
     car.price = 0.5;
     other.deposite -= car.price;
     other.car = car;
     
     owner.deposite += car.price;
     owner.car =NULL;
}

int main()
{
      while(1)
      {
           void* ptr = malloc(1024*512);
           if(!ptr)
           {
                printf("no money\n");
           }
      }
      return 0;
}
