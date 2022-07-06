#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(){
    int x_len=40, x_res=5, y_len=40, y_res=5,ac=50,speed=200;
    int x_reg=x_len/x_res;
    int y_reg= y_len/y_res;
    int x[x_reg+1];
    int y[y_reg+1];
	string xe[x_reg+1];
	string ye[y_reg+1];

    for (int m=0; m<=x_reg; m++){
        x[m]=x_res*m;
    }

    for (int n=0; n<=y_reg; n++){
        y[n]=y_res*n;
    }
    
    for (int b=0; b<=x_reg; b++){
        string strx = "ORDER ";
        strx += to_string(b+202)+=32;
        strx +=to_string(x[b])+=32;
        strx +=to_string(speed)+=32;
        strx +=to_string(ac)+=32;
        strx +=to_string(ac)+=32;
        strx +=to_string(0)+=32;
        strx +=to_string(0)+=32;
        strx +=to_string(3)+=32;
        strx +=to_string(203+b);
        xe[b]=strx;
        cout<<xe[b]<<endl;
    } 

    for (int a=0; a<=y_reg; a++){
        string stry = "ORDER ";
        stry += to_string(a+202)+=32;
        stry +=to_string(x[a])+=32;
        stry +=to_string(speed)+=32;
        stry +=to_string(ac)+=32;
        stry +=to_string(ac)+=32;
        stry +=to_string(0)+=32;
        stry +=to_string(0)+=32;
        stry +=to_string(3)+=32;
        stry +=to_string(203+a);
        ye[a]=stry;
        cout<<ye[a]<<endl;		                  
    }

    system("pause");
    return 0;
}