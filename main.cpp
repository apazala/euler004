#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

int rebmun(int number){
	int rev = 0;
	int d;
	while(number >= 10){
		d = number%10;
		number /=10;
		rev = rev*10+d;
	}
	rev = rev*10+number;
	
	return rev;
}

int64_t compute(int ndig)
{
	int minNDig = 1;
	for(int i = 1; i < ndig; i++){
		minNDig *= 10;		
	}
	
	// if ndig = 3 --> minNDig = 100, multip = 1000, maxNDig = 999
	int maxNDig = minNDig*10;
	int multip = maxNDig; 
	maxNDig--; 
	
	int res = -1;
	//Iterate palindromes descending order: first found is max
	for(int nup = maxNDig; nup >= minNDig && res == -1; nup--){
		int palindrome = multip*nup + rebmun(nup);
		
		int factora = maxNDig;
		int factorb = palindrome/factora;
		
		while(factora >= factorb && res == -1){
			if(palindrome%factora == 0){
				//Found palindrome!			
				res = palindrome;
			}else{
				factora--;
				factorb = palindrome/factora;
			}
		}
	}
	
	
	return res;
}

int main(int argc, char **argv)
{
	int64_t res = compute(3);
	
	cout << res << endl;
	
    return 0;
}
