#include <stdio.h>

/*!< Dada a base, expoente e modulo, retorna o resultado da operacao [base^expoente (mod modulo)] */
unsigned int modulo_de_potencia(unsigned int a, unsigned int e, unsigned int d) {
	unsigned int m = 1, b = a;

    /* 
    * Calcula o valor do modulo atraves da "Implementação da Potencia a Modulo" como explicado na aula 5 de Criptografia 
    * Neste caso, se utiliza do fato que m*m = m^2, m*m*m*m = m^2*m^2, m*m*m*m*m*m*m*m = m^4*m^4, ...
    */
	while (e > 0) {
		if (e % 2 == 1) 
            m = (m * b) % d;
        b = (b * b) % d; 
		e /= 2;
	}

	return m % d;
}

int main(void) {
    unsigned int a, e, d;
    printf("Seja (a)^(e) (mod d)\n");
    printf("Digite o valor de (a): ");
    scanf("%d", &a);
    printf("Digite o valor de (e): ");
    scanf("%d", &e);
    printf("Digite o valor de (d): ");
    scanf("%d", &d);

    /*!< Verificando se as entradas sao validas */
    if(a >= d || e >= 65536 || d >= 65536) {
        printf("Entrada invalida!\n");
        return 0;
    }

    /*!< Calculando o modulo */
    printf("O valor de (%d)^(%d) (mod %d) é %d\n", a, e, d, modulo_de_potencia(a, e, d));
    return 0;
}
