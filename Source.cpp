#include <iostream>
#define mod 2147483647
using namespace std;

long long evklidplus(long long a, long long b, long long& alfa, long long& beta) {
	long long  alfa1, beta1,res;
	if (a == 0) {
		alfa = 0; beta = 1;
		return b;
	}
	 res = evklidplus(b % a, a, alfa1, beta1);
	alfa = beta1 - (b / a) * alfa1;
	beta = alfa1;
	return res;
}



int main() {

	long long a, b;
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	if (a == 0)
		cout << 0;
	else if (a >=b && a%b==0)
		cout << a / b;
	else
	{
		long long first, second,gcd,answer;
		gcd=evklidplus(b, mod, first, second);
		if (first < 0) {
			first += mod;
		}
		
		answer = (a * first) % mod;
		
		if (answer < 0)
			cout << mod + answer;
		else cout << answer;
	}

	return 0;
}