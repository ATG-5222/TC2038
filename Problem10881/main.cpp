// Internal Rate of return
// Aldo Tena García - A01275222
// Renato Sebastían Ramirez Calva - A01275401
// Marco Antonio Camalich Pérez - A01351725

#include <bits/stdc++.h>
using namespace std;

int cashFlow[100];
int main(){
    int test;
    while(1){
        scanf("%d", &test);
        if(test==0){
            break;
        }
        for(int i=0; i<=test; i++){
            scanf("%d", &cashFlow[i]);
        }
        double result,low=-1,high=10000;
        for(int j=1;j<=107;j++){
            result=(low+high)/2;
            double sum=0;
            for(int k=0;k<=test;k++){
                sum += (double(cashFlow[k]))/pow(1.0+result,k);
            }
            if(sum>0){
                low=result;
            }
            else{
                high=result;
            }
        }
    printf("%0.2lf\n",result);
    }
}