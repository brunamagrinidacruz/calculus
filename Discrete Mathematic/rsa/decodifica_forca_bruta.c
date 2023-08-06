#include <stdio.h>

/*!< Dada a base, expoente e modulo, retorna o resto da operacao [base^expoente (mod modulo)] */
unsigned int modulo_de_potencia(unsigned int base, unsigned int expoente, unsigned int modulo) {
	unsigned int m = 1, a = base;

	while (expoente > 0) {
		if (expoente % 2 == 1) 
            m = (m * a) % modulo;
        a = (a * a) % modulo; 
		expoente /= 2;
	}

	return m % modulo;
}

int main(void) {
    unsigned int n = 1247;
    unsigned int e = 17; 
    unsigned int f = 761;
    
    unsigned int c = 430;

    unsigned int m = modulo_de_potencia(c, f, n); /*!< Decodifica */

    unsigned int c_linha = modulo_de_potencia(m, e, n); /*!< Codifica a mensagem novamente para chegar se é igual a mensagem inicial */

    printf("(%d)^(%d) (mod %d) = %d. Mensagem final: %d.\n", c, f, n, m, m);
    printf("Realizando verificacao: (%d)^(%d) (mod %d) = %d. %d == %d?\n", m, e, n, c_linha, c_linha, c);

    return 0;
}
