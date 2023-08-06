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
    /**
    * p = 113
    * q = 281
    * n = 31753 (Em binário: 111 1100 0000 1001 - 15 bits)
    * phi = (113-1)*(281-1) = 31360
    * e = 19
    * f = 28059
    */
    int n = 31753;
    int e = 19;
    int f = 28059;

    int m, m_linha, c;

    printf("Digite a mensagem: ");
    scanf("%d", &m);

    c = modulo_de_potencia(m, e, n); /*!< CODIFICA: c = m^e (mod n) */
    m_linha = modulo_de_potencia(c, f, n); /*!< DECODIFICA: m = c^f (mod n) */
    
    printf("Mensagem codificada: %d\n", c);
    printf("Mensagem decodifica: %d\n", m_linha);

    return 0;
}
