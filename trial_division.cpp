#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <gmpxx.h>


using std::cin;
using std::cout;
using std::endl;

#define LINE 100




mpz_class trialDivision(mpz_class N,double t0);

int main()
{


    std::vector<mpz_class> factors[LINE];

    int count = 0;
    mpz_class N;
    while(cin >> N){

     int is_prime = mpz_probab_prime_p(N.get_mpz_t(), 10);
     if(is_prime>=1){
           factors[count].push_back(N);
           count++;
           continue;
       }

//
//   for(int jj=0;jj<3;jj++){
//
//
//      cin>>N;
       double t0 = clock();

      mpz_class a,b;

      while(true){

            int is_prime = mpz_probab_prime_p(N.get_mpz_t(), 10);
            if(is_prime>=1){
                   factors[count].push_back(N);
                   break;
            }
            a = trialDivision(N,t0);
            if(a == -1){
                factors[count].clear();
                break;
            }else{
                if(a!=0){
                    factors[count].push_back(a);
                    N = N/a;
                }else{
                    factors[count].push_back(N);
                    break;
                }
            }


        }



        count++;


    }




    for(int j=0;j<count;j++){
      if(factors[j].size() == 0){
        cout<<"fail"<<endl;
      }else{
        for(int k=0;k<factors[j].size();k++){
             cout<<factors[j][k]<<endl;
        }
      }

      cout<<endl;
    }



    return 0;
}


mpz_class trialDivision(mpz_class N, double t0){

    mpz_class a=0;
    if (N % 2 == 0) {
            return 2;
    }

    mpz_class sqr = sqrt(N);
    mpz_class rop = sqr - (sqr % 1);


    for(mpz_class s = 2; s<= rop;s++){



        if(((clock()-(float)t0)/CLOCKS_PER_SEC > 0.18) && (N> 10000000000000000)){


            return -1;
        }
        if(mpz_divisible_p(N.get_mpz_t(), s.get_mpz_t()) != 0){

            return s;
        }


    }

}
