    #include<cstdio>  
    #include<cstdlib>  
    #include<iostream>  
    #define MIN(a,b) (((a)<(b))?(a):(b))    
    #define MAX(a,b) (((a)>(b))?(a):(b))    
    int A[101],B[101],L,R;  
    long  a[101],b[101];  
    long  dp[101][101];  
    using namespace std;  
      
    long rec(long x,long y,int i,int j){  
       long sol1=0,sol2=0;  
       //cout<<"hello\n";  
       if((i==0)||(j==0)) return 0;  
       //cout<<x<<" "<<y<<" "<<i<<" "<<j<<"\n";  
       sol2=MIN(x,y)+dp[i-1][j-1];  
       if(x<y){  
       long   ty=y-x;  
       //if(j-1==0) sol1=ty;  
        bool found=false;  
        int k=i-1;  
          while((k>0)&&(found==false)){  
               if(B[j]==A[k]){  
                  sol1=x+rec(a[k],ty,k,j);found=true;}  
              k--;  
         }  
      }  
     else if(x==y) sol1=MIN(x,y)+dp[i-1][j-1];  
     else{  
       long tx=x-y;  
       //if(i-1==0) sol1=tx;  
        
     int  k=j-1;  
       bool found=false;  
       while((k>0)&&(found==false)){  
          if(A[i]==B[k]){  
            sol1=y+rec(tx,b[k],i,k);found=true;}  
         k--;  
       }  
    }  
    return MAX(sol1,sol2);  
    }  
                
      
    int main(){  
         cin>>L>>R;  
       for(int i=1;i<=L;i++){  
           cin>>a[i]>>A[i];}  
       for(int j=1;j<=R;j++){  
           cin>>b[j]>>B[j];  
           }  
       for(int i=0;i<=L;i++){  
         for(int j=0;j<=R;j++)dp[i][j]=0;}  
       for(int i=1;i<=L;i++){  
         for(int j=1;j<=R;j++){  
            if(A[i]!=B[j])   
               dp[i][j]=MAX(dp[i-1][j],dp[i][j-1]);  
            else  
               dp[i][j]= rec(a[i],b[j],i,j);  
                 
        }  
      }  
          cout<<dp[L][R]<<"\n";  
    return 0;  
    }  
