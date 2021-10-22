#include<iostream.h>
#include<conio.h>

class FLOAT
{
    float no;
    public:
    FLOAT(){}
    void getdata()
    {
        cout<<"\n ENTER AN FLOATING NUMBER :";
        cin>>no;
     }
     void putdata()
     {
        cout<<"\n\nANSWER IS                   :"<<no;
     }
     FLOAT operator+(FLOAT);
     FLOAT operator*(FLOAT);
     FLOAT operator-(FLOAT);
     FLOAT operator/(FLOAT);
};
FLOAT FLOAT::operator+(FLOAT a)
{
    FLOAT temp;
    temp.no=no+a.no;
    return temp;
}
FLOAT FLOAT::operator*(FLOAT b)
{
    FLOAT temp;
    temp.no=no*b.no;
    return temp;
}
FLOAT FLOAT::operator-(FLOAT b)
{
    FLOAT temp;
    temp.no=no-b.no;
    return temp;
}
FLOAT FLOAT::operator/(FLOAT b)
{
    FLOAT temp;
    temp.no=no/b.no;
    return temp;
}


main()
{
  clrscr();
  FLOAT a,b,c;
  a.getdata();
  b.getdata();

  c=a+b;
  cout<<"\n\nAFTER ADDITION OF TWO OBJECTS";
  c.putdata();
  cout<<"\n\nAFTER MULTIPLICATION OF TWO OBJECTS";
  c=a*b;
  c.putdata();
  cout<<"\n\nAFTER SUBSTRACTION OF TWO OBJECTS";
  c=a-b;
  c.putdata();
  cout<<"\n\nAFTER DIVISION OF TWO OBJECTS";
  c=a/b;
  c.putdata();
  getch();
}
