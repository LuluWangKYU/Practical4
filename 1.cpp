#include <iostream>
using namespace std;
#include <math.h>

//read coefficient from keyboard
double * read_poly(int &n){
  cout<< "max degree: ";
  cin>> n;
  double *c = new double [n+1];
  for (int i=0; i<=n ; i++){
    cout << "coefficient of degree " << i << ": ";
    cin >> c[i];
  }
  return c;
}

//print polynoiml
void print_poly(double *c, int n){
  int i;
  cout <<"the polynomial is : "<< c[0];
  if(n>0)
    cout << " + ";
  for(i=1;i<n;i++)
    cout << c[i] << "*x^" << i << " + ";
  if(n>0)
    cout << c[n] << "*x^" << i;
  cout << endl;
}

//calculte a real number x in a polynomial
void calculte_poli(double x ,double *c,int n){
  int i ;
  double resu=0 ;
  cout<<"the value of x is :";
  cin>> x;
  if(n>0)
  resu = c[0]+resu;
  for (i=1;i<=n;i++)
  resu = c[i] * pow(x,i)+resu;
  cout <<"the value of the polynomial is :" << resu <<endl;
}

// the sum of two polynomials
double * poli_sum (double * p1, int d1, double * p2, int d2, int & dr){
   
   int maxn= max(d1,d2);

   double d[maxn];
   double *ptr;
   ptr = d;
   
   int i =0;
   cout<< "the sum of the polynoiml is: ";

  while (ptr <= &d[maxn]) { 
    //progressively increase
    *ptr = *p1 + *p2;
    cout << *ptr << "*x^" << i << " + ";
    p1++ ;
    p2++ ;
    ptr++;
    i++;
  }
   cout << 0<<endl; 
   dr = *ptr;
   return 0; 
}

double * poli_pro (double * p1, int d1, double * p2, int d2, int & dr){
   
   int maxn= d1+d2;

   double d[maxn];
   double *ptr;
   ptr = d;
   
   int i = 0;
   int j = 0;
   cout<< "the product of the polynoiml is: ";
  
   while (j<=d2 ){
      
     while (i<=d1) { 
      *ptr = *p1**p2;
      cout << *ptr << "*x^" << i+j << " + ";
      p1++ ;
      ptr++;
      i++;
  }
   //p1 -> next;
   // I tried to reset the pointer here ,but I am not able to do it
   i = 0;
   j++;
   p2++ ;}
  
   
   cout << 0<<endl; 
   dr = *ptr;
   return 0; 
    
}
 

int main()
{
  double *p1;
  int d1;
  double *p2;
  int d2;
  int d;
  int ok;
  int fine;
  double x;

  p1=read_poly(d1);
  print_poly(p1,d1);

  calculte_poli(x,p1,d1);

  p2=read_poly(d2);
  print_poly(p2,d2);
  
  poli_sum(p1,d1,p2,d2,ok);
  poli_pro(p1,d1,p2,d2,fine);

  delete[] p1;
  delete [] p2;
  
  return 0;
}

