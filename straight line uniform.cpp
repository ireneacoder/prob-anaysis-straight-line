#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <cmath>
#include <ctime>
#include<bits/stdc++.h>

using namespace std;


void swap(int* g, int* f) 
{ 
    int t = *g; 
    *g = *f; 
    *f = t; 
}

int partition (int valu[], int low, int high) 
{ 
    int pivot = valu[high];  
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
        
        if (valu[j] < pivot) 
        { 
            i++; 
            swap(&valu[i], &valu[j]); 
        } 
    } 
    swap(&valu[i + 1], &valu[high]); 
    return (i + 1); 
} 

void quickSort(int valu[], int low, int high) 
{ 
    if (low < high) 
    { 
        
        int pi = partition(valu, low, high); 
  
        
        quickSort(valu, low, pi - 1); 
        quickSort(valu, pi + 1, high); 
    } 
} 

float utilfn(vector<char> n)
{
    float num = 0;
    for (auto i = n.begin(); i != n.end(); ++i)
    {
        if (*i != '.')
        {
            int n = *i - 48;
            num = num * 10 + n;
        }
    }

    num /= 100;

    return num;
}

int lin_search(int arr[], int u_lim, int x)
{
    int flag = 1;
    for (int i = 0; i <= u_lim; i++)
    {
        if (arr[i] == x)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{

   srand(time(NULL));

   
//  for writing output to output.txt
   freopen("output1.txt", "w", stdout);


    ifstream infile;
    infile.open("data.txt");

    float arr[199][2];
    vector<char> n;
    int i = 0, j = 0;
    char ch;

    if (infile.is_open())
    {
        while (!infile.eof())
        {
            ch = infile.get();

            if (ch == '\t' || ch == ' ' || ch == '\n')
            {
                if (ch == '\n')
                {
                    arr[i][j] = utilfn(n);
                    i++;
                    j = 0;
                    n.clear();
                }

                else if (ch == ' ')
                {
                    arr[i][j] = utilfn(n);
                    j++;
                    n.clear();
                }
            }

            else
            {
                n.push_back(ch);
            }
        }
    }
    infile.close();


    int valu[30] = {0};

    int k = 30;
 
    while(k<200){
    for (int i = 0; i <= 30; i++)
    {
        int ran = rand() ;
        int maxr = RAND_MAX;
        float r = ran / float(maxr);
        double a, b;
        
        a = r * k;
        modf(a, &b);
        int u = 1 + b;

        if (lin_search(valu, i, u))
        {
            valu[i] = u;
        }

        else
            --i;
    }

    /*for (int m = 0; m < 199; m++)     // for printing the array that is inserted
    {
        cout << arr[m][0] << " " << arr[m][1] << endl;

    }*/
   
    int mu = sizeof(valu) / sizeof(valu[0]); 
    quickSort(valu, 0, mu - 1); 
  

    int counter = 0;
    
    

    for (int i = 0; i < 30; i++)
    {
        int flag = 1;
        for (int j = 0; j < 30; j++)
        {
            if (j == i)
                continue;

            if (valu[i] == valu[j])
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        counter++;
    }
    
  

    int s=0 ;
    double x[30] ;
    double y[30] ;
    

    for( int z = 0 ; z < 30 ; z++ )
    {
       
        s = valu[z]  ;
       
      y[z]=arr[s][0] ;
      x[z]=arr[s][1] ;
       


    }

   double sum_x=0, sum_y=0, sum_xx=0, sum_yy=0, sum_xy=0;
   double d=0, e=0, f=0 ;

   for ( int w = 0 ; w < 30 ; w ++)
   {
        sum_x+=x[w];
        sum_y+=y[w];
        sum_xx+=(x[w]*x[w]);
        sum_yy+=(y[w]*y[w]);
        sum_xy+=(x[w]*y[w]);
   }
    // printf("sum of x = %lf\n",sum_x) ;
    // printf("sum of y = %lf\n",sum_y) ;
    // printf("sum of x*x = %lf\n",sum_xx) ;
    // printf("sum of y*y = %lf\n",sum_yy) ;
    // printf("sum of x*y = %lf\n",sum_xy) ;
        
    // cout << "counter - " << counter << endl;
    cout<<k<<endl;
    double lambda ;
    lambda=((sum_xx*sum_y) - (sum_x*sum_xy))/((30*sum_xx)-(sum_x*sum_x)) ;
    cout/*<<"The value of constant is "*/<<lambda<<endl ;
    double gamma ;
    gamma=((30*sum_xy)-(sum_x*sum_y))/((30*sum_xx)-(sum_x*sum_x)) ;
    cout/*<<"The value of slope is "*/<<gamma<<endl ;

    float calculated_Y ;
    float sum_calculated_Y=0 ;
    
    for(int i = 0 ; i <30 ; i++){
        calculated_Y=gamma*x[i]+lambda; //y=mx+c where M=gamma, C=lambda 
        sum_calculated_Y+=calculated_Y ;
        // cout<</*"The value of x used is "<<*/x[i]<<endl ;
        // cout<</*"The calculated Y is "<<*/calculated_Y<<endl ;
        // cout<</*"Observed Y is"<<*/ y[i]<<endl ; 
    }
    // cout<<"The equation of line is "<<"Y = "<<gamma<<"X + "<<lambda<<endl;
    // int sum_calculated_Y2=sum_calculated_Y*sum_calculated_Y ;
    // int sum_observed_Y2=sum_y*sum_y ;
 //square rooting this removes the purpose of square 
    // printf("The error is =%f\n",sqrt(error)); 
    // double error_per ;
    // error_per=(sqrt(error)/sum_y)*100 ;
    // printf("error percentage is = %lf\n",error_per) ; 
    k+=30;
    }
    

       
    return 0;
}
