/*Coarse grain Table potential for tabular interactionns*/
#include <stdio.h>
#include <math.h>
#include <time.h>  


int main( ) 
{
  
   int  i,j,k,kk,m,nn;
   FILE *cfPtr;
   FILE *lec,*lec2;
   char AAA;
   double  pi;
   int n=10000,f,N,M;
   double a,b,c,h;
   double xlo,xho;
   double  Uo,K; 
   double  x0[n],x[n],F[n],dF[n];  
   double a2,u,u2,u6,u12;   
   int A, B; 
  
xlo=0.5;
xho=5;
N=1000;

K=1;
Uo=5;

h=(xho-xlo)/N;

for(i=0;i<N;i++)
{
x[i]=xlo+h*i;
}

for(i=0;i<N;i++)
{
u=x[i];
u2=u*u;
u6=u2*u2*u2;
u12=u6*u6;
F[i]= 4*( (1.0/u12)-(1.0/u6) )+Uo*exp(-K*(u-0.7)*(u-0.7));
dF[i]=4*( (48.0)/(u12*u)-(24.0)/(u6*u )) +2*K*Uo*exp(-K*(u-0.7)*(u-0.7))*(u-0.7);  
}


if((cfPtr= fopen("CG.table","w"))==NULL)
    printf("File could not be opened.\n");
else
{
fprintf(cfPtr,"#Tabulated potential\n\n\n"); 
fprintf(cfPtr,"C-C\n"); 
fprintf(cfPtr,"N %d\n\n", N); 

for(j=0;j<N;j++)
{
fprintf(cfPtr,"%d % 10.39e % 10.39e % 10.39e  \n ",j,x[j],F[j],dF[j]);
}

fclose(cfPtr);
}

}  

/*Fin del codigo*/






















































