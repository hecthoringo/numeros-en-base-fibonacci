/**
 * @file NumerosEnBaseFibonacci.c
 * @author Hector Valencia (contacto@hecthoringo.com)
 * @website https://www.hecthoringo.com
 * @brief   La sucesión de Fibonacci comienza con F(1)=1, F(2)=2,  y continúa con F(n) = F(n-1) + F(n-2) para toda n >= 3. Todo número entero positivo se puede escribir como suma de elementos de la sucesión de Fibonacci, por ejemplo, el número 10 se puede escribir como F(4)+F(4), F(4)+F(3)+F(2) o F(5)+F(2). Sin embargo, existe una única forma de escribir cada entero positivo como sumas de elementos distintos de la sucesión de Fibonacci que no sean consecutivos, en nuestro caso 10 = F(5)+F(2) sería la única forma válida. Escribe un programa que dado un entero positivo n encuentre esta suma única.
 *          ENTRADA: Un número entero n. Puedes suponer que 1 <= n <= 1000000000.
 *          SALIDA: Un número entero k, la cantidad de sumandos, seguido de k números enteros a1,a2,...,ak tales que n = F(a1)+F(a2)+...+F(ak), a1 > a2 + 1 > ... > ak + 1 > 0.
 *          LIMITES: 1 < n < 100000000
 * @version 1.0
 * @date
 * @copyright hecthoringo
 * 
 */

#include<stdio.h>

/**
 * @brief Calculate fibonacci sequence
 * 
 * @param n 
 * @return long long int 
 */
long long int fibonacci_sequence(int n) {
	long long int n1=1, n2=1;
	for(int i = 1; i<n; i++){
		n2 = n1 + n2;
        n1 = n2 - n1;
    }
	return n2;
}

/**
 * @brief 
 * 
 * @return int 
 */

int main() {
	long long int i=2, k, m, n, count=1;
	scanf("%llu",&n);
	do {
		i++;
	}while(!(n > fibonacci_sequence(i) && n < fibonacci_sequence(i+1)));
	k=(i-1);
	m=fibonacci_sequence(i);	
	do {
		if(fibonacci_sequence(k)<=(n-m)) {
			m=m+fibonacci_sequence(k);
			count++;
		}
		k--;
	} while(k>=1);
	printf("%d\n",count);
	k=(i-1);
	m=fibonacci_sequence(i);	
	printf("%d ",i);
	do {
		if(fibonacci_sequence(k)<=(n-m)) {
			printf("%d ",k);
			m=m+fibonacci_sequence(k);
		}
		k--;
	} while(k>=1);
	
	return 0;
}
