#include <bits/stdc++.h>
using namespace std;
long long int dp[90];
clock_t t1;

long long fib(long long int n){
	if(dp[n] != -1) return dp[n];
	if(n == 0) return dp[n]= 0;
	if(n <= 2) return dp[n]= 1;
	return dp[n]= fib(n-1)+fib(n-2);
}

long long fib_int(long long int n){
    if(n == 0) return 0;
    if(n <= 2) return 1;
    return fib_int(n-1)+fib_int(n-2);
}

int main(){
	memset(dp,-1,sizeof(dp));
	cout << "Calculando o 10º número da sequencia fib com PD\n";
	t1= clock();
    cout << "Fib(10) = " << fib(10) << endl;
	t1= clock() - t1;
	cout << "Tempo gasto para calcular o 10º número da sequencia fib com PD: " << (float)t1/CLOCKS_PER_SEC << " segundos.\n\n";

	cout << "Calculando o 10º número da sequencia fib sem PD\n";
	t1= clock();
    cout << "Fib(10) = " << fib_int(10) << endl;
	t1= clock() - t1;
	cout << "Tempo gasto para calcular o 10º número da sequencia fib sem PD:  "<< (float)t1/CLOCKS_PER_SEC << " segundos.\n\n";

	cout << "Calculando o 89º número da sequencia fib com PD (90+ estoura o valor de long long int).\n";
	t1= clock();
    cout << "Fib(89) = " << fib(89) << endl;
	t1= clock() - t1;
	cout << "Tempo gasto para calcular o 50º número da sequencia fib com PD: "<< (float)t1/CLOCKS_PER_SEC << " segundos.\n\n";

	cout << "Calculando o 50º número da sequencia fib sem PD (Acima disso demorará muito tempo).\n";
	t1= clock();
    cout << "Fib(50) = " << fib_int(50) << endl;
	t1= clock() - t1;
	cout << "Tempo gasto para calcular o 50º número da sequencia fib sem PD:  "<< (float)t1/CLOCKS_PER_SEC << " segundos.\n\n";

	cout << "A complexidade de se calcular a sequencia fib usando um algoritmo de PD sera O(N).\n";
	cout << "A complexidade de se calcular a sequencia fib usando um algoritmo interativo sera O(2eN).";
}
