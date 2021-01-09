/* 
 * Assinatura:
 *      Aluno: Robson Duarte dos Santos
 *      DRE: 114175915
 *      versão do GCC utilizada: 9.2.0 *
 */

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include <stdint.h>

// Todo numero diferente de 0 é visto como true e o 0 sempre é false, sempre que usamos operadores lógicos essa lógica é aplicada.
// O primeiro NOT torna o retorno falso e o segundo NOT o torna true.Logo qualquer numero que seja diferente de 0 será false depois true.
// e quando for 0 retornará retornará false, true e false.

int32_t naoEhZero(int32_t x) {    
    int32_t is_X_Different_From_0 = !!x;
    return is_X_Different_From_0;                 
}                

/*
Checa somente o primeiro bit mais a direita, se o numero terminar com 1, como 1001 é impar, logo 1 & 1 retorna true(1) , com o NOT fica false,x não é par.
Caso termine com 0 como 1000, 1 & 0 retorna false(0) com o NOT, retorna true.
*/
int32_t ehPar(int32_t x) {
    int32_t is_X_Par = !(x & 1);
    return is_X_Par;
}

/*
como 8 é 1000(binario) e x mod 8 é um numero  estritamente menor que 8 todo número que restar na divisão por 8 estará naqueles 3 bits 0 depois do 1.
Dai que sai a logica de fazer x & 0111 , que são exatamente os 3 a direita do 1 de 1000
*/
int32_t mod8(int32_t x) {
    return (x & 7);
}

/*
Apenas verifico se o bit mais significativo está ligado, concretizando um numero negativo.
*/

int32_t ehPositivo(int32_t x) {
    return !(x >> 31);
}
/*
Para por um numero em complemento a 2, que é sua representação negativa, basta inverter os bits e somar 1
*/
int32_t negativo(int32_t x) {    
    return (~x + 1);
}

/* Implementação do & usando bitwise
 *      Permitido:
 *          Operações: ~ ^ | ! << >>
 *
 *      Número máximo de operações: 7
 *      Monitor: 4
 *
 *      Retorna x & y
 *
 *      Exemplo:
 *          bitwiseAnd(1, 2) -> 0
 *              01 & 10 -> 00
 *          bitwiseAnd(3, 11) -> 3
 *              11 & 1011 -> 0011
 */
int32_t bitwiseAnd(int32_t x, int32_t y) {
    return -1;
}

/* Igual sem ==
 *      Permitido:
 *          Operações: ~ & ^ | << >> ! +
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x == y, 0 caso contrário
 *
 *      Exemplo:
 *          ehIgual(10, 10) -> 1
 *          ehIgual(16, 8) -> 0
 */

//Inicialmente, Percebemos que o xor dado sua tabela verdade se asemelha muito ao != (não igual). Pelo seguinte motivo:
//Se o bit da mesma posição de ambas as entradas forem iguais então ele retorna 0.
//Se o bit da mesma posição de ambas as entradas forem diferentes ele retorna 1.
//Então, se um numero for igual ele vai retornar 0 em todas as posições.
//Se o numero for diferente, as posições que tiverem o valor binario diferente vão ficar com 1 assim nunca retornando 0.
//Com isso pensamos, se o numero for igual ele vai retornar 0 e se o numero for diferente ele não vai retornar 0.
//Só que comumente usamos 1 para true e 0 para false. Ou seja ate esse momento o xor esta retornando false se o numero for igual. o que seria o not equal.
//Como queremos que retorne true, ou seja, 1 se as entradas forem iguais( os numeros forem iguais) usarei o operador ! ajeitar isso.
//Assim, negando a afirmação anterior, dado A e B se eu fizer o xor deles A ^ B ele vai retornar 0 caso não sejam iguais.
//Como quero que retorne 1(ou true) se forem iguais. Negarei a saida. Agora, !(A ^ B) ele me retorna 1 se forem iguais(true).

int32_t ehIgual(int32_t x, int32_t y) {
    return (x ^ y);
}

/*
 * Multiplicação por 7
 *      Permitido:
 *          Operações: << >> | ! & + -
 *
 *      Número máximo de operações: 4
 *      Monitor: 2
 *
 *      Retorna x multiplicado por 7
 *
 *      Exemplo:
 *          mult7(7) -> 49
 */
//Imaginando que a multiplicação seja a ideia de quantas vezes eu gostaria que um valor x fosse somado a ele mesmo.
//entao, se multiplico x por 7 eu estou somando 7 vezes o valor de x a ele mesmo.
//Assim, eu sei que << multiplica por 2^n, onde n é a quantidade de vezes que eu definir pro shift
//fazendo, << 3 eu estaria fazendo 2^3 que daria 8.
//Então, se eu fizer x << 2^3 -> x << 8 -> x * 8. Logo, eu estaria somando o valor de x a ele mesmo 8 vezes.
//Mas eu gostaria de somar o valor de X a ele mesmo somente 7 vezes, como somei 1 x a mais, eu irei subtrair dele
// Dessa forma, x << 3 - x -> x * 2^3 - x -> x * 8 -x -> 8x - x -> 7x! assim estarei somando x a ele mesmo 7 vezes
// em outras palavras multiplicando x por 7.
int32_t mult7(int32_t x) {
    return (x << 3) - x;
}

/*
 * Bit na posição p do inteiro x
 *      Permitido:
 *          Operações bitwise: << >> | & + -
 *
 *      Número máximo de operações: 6
 *      Monitor: 2
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser apenas 0 ou 1
 *
 *      p será um valor entre 0 e 31
 *
 *      Exemplo:
 *          23 em binário: 0   0 ... 0 1 0 1 1 1
 *               posições: 31 30 ... 5 4 3 2 1 0
 *
 *          bitEmP(23, 31) -> 0
 *          bitEmP(23, 5) -> 0
 *          bitEmP(23, 4) -> 1
 *          bitEmP(23, 3) -> 0
 *          bitEmP(23, 2) -> 1
 *          bitEmP(23, 1) -> 1
 *          bitEmP(23, 0) -> 1
 *
 */
int32_t bitEmP(int32_t x, uint8_t p) {
    return -1;
}

/*
 * Byte na posição p do inteiro x
 *      Permitido:
 *          Operações: << >> | ! &
 *
 *      Número máximo de operações: 6
 *      Monitor: 3
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser entre 0 e 0xFF
 *
 *      p será um valor entre 0 e 3
 *      0 retorna LSB
 *      3 retorna MSB
 *
 *      Exemplo:
 *          byteEmP(0x12345678, 0) -> 0x78
 *          byteEmP(0x12345678, 1) -> 0x56
 *          byteEmP(0x12345678, 2) -> 0x34
 *          byteEmP(0x12345678, 3) -> 0x12
 *
 */
int32_t byteEmP(int32_t x, uint8_t p) {
    return -1;
}

/*
 * Negação lógica sem !
 *      Permitido:
 *          Operações: << >> | ~ & +
 *
 *      Número máximo de operações: 15
 *      Monitor: 5
 *
 *      Retorna 1 se x == 0, retorna 0 caso contrário
 *
 *      Exemplo:
 *          negacaoLogica(0) -> 1
 *          negacaoLogica(37) -> 0
 *
 */
int32_t negacaoLogica(int32_t x) {
        return -1;
}

void teste(int32_t saida, int32_t esperado) {
    static uint8_t test_number = 0;
    test_number++;
    if(saida == esperado)
        printf(ANSI_COLOR_GREEN "PASSOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            saida, esperado);

    else
        printf(ANSI_COLOR_RED "%d: FALHOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            test_number, saida, esperado);
}

int main() {
    puts(ANSI_COLOR_BLUE "Primeiro lab - bits" ANSI_COLOR_RESET);
    puts("");

    puts("Teste: ehZero");
    teste(naoEhZero(0), 0);
    teste(naoEhZero(1), 1);
    teste(naoEhZero(1024), 1);
    teste(naoEhZero(-1), 1);
    teste(naoEhZero(-2), 1);
    teste(naoEhZero(-2147483648), 1);
    teste(naoEhZero(2147483647), 1);
    puts("");

    puts("Teste: ehPar");
    teste(ehPar(2), 1);
    teste(ehPar(1), 0);
    teste(ehPar(3), 0);
    teste(ehPar(13), 0);
    teste(ehPar(100), 1);
    teste(ehPar(125), 0);
    teste(ehPar(1024), 1);
    teste(ehPar(2019), 0);
    teste(ehPar(2020), 1);
    teste(ehPar(-1), 0);
    teste(ehPar(-27), 0);
    teste(ehPar(-1073741825), 0);
    teste(ehPar(1073741824), 1);
    teste(ehPar(2147483647), 0);
    teste(ehPar(-2147483648), 1);
    teste(ehPar(0), 1);
    puts("");

    puts("Teste: mod8");
    teste(mod8(0), 0);
    teste(mod8(4), 4);
    teste(mod8(7), 7);
    teste(mod8(8), 0);
    teste(mod8(-1), 7);
    teste(mod8(-8), 0);
    teste(mod8(2147483647), 7);
    teste(mod8(-2147483648), 0);
    puts("");

    puts("Teste: ehPositivo");
    teste(ehPositivo(-1), 0);
    teste(ehPositivo(1), 1);
    teste(ehPositivo(2037), 1);
    teste(ehPositivo(-2037), 0);
    teste(ehPositivo(-2147483648), 0);
    teste(ehPositivo(-2147483648/2), 0);
    teste(ehPositivo(2147483647), 1);
    puts("");

    puts("Teste: negativo");
    teste(negativo(0), 0);
    teste(negativo(1), -1);
    teste(negativo(-1), 1);
    teste(negativo(2147483647), -2147483647);
    teste(negativo(-2147483647), 2147483647);
    teste(negativo(-2147483648), 2147483648);
    puts("");

    puts("Teste: bitwiseAnd");
    teste(bitwiseAnd(1, 3), 1);
    teste(bitwiseAnd(-1, 0), 0);
    teste(bitwiseAnd(-1, 0x7FFFFFFF), 0x7FFFFFFF);
    teste(bitwiseAnd(0b0100, 0b1100), 0b0100);
    puts("");

    puts("Teste: ehIgual");
    teste(ehIgual(1,1), 1);
    teste(ehIgual(1,0), 0);
    teste(ehIgual(8,4), 0);
    teste(ehIgual(11,6),0);
    teste(ehIgual(0,1), 0);
    teste(ehIgual(-1,1), 0);
    teste(ehIgual(-1,-1), 1);
    teste(ehIgual(2147483647,-1), 0);
    teste(ehIgual(2147483647,-2147483647), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    puts("");

    puts("Teste: mult7");
    teste(mult7(1), 7);
    teste(mult7(7), 49);
    teste(mult7(3), 21);
    teste(mult7(-1), -7);
    teste(mult7(-306783378), -2147483646);
    teste(mult7(306783378), 2147483646);
    puts("");

    puts("Teste: bitEmP");
    teste(bitEmP(1, 0), 1);   //    b01 => retorna 1
    teste(bitEmP(1, 1), 0);   //    b01 => retorna 0
    teste(bitEmP(2, 0), 0);   //    b10 => retorna 0
    teste(bitEmP(2, 1), 1);   //    b10 => retorna 1
    teste(bitEmP(9, 2), 0);   //  b1001 => retorna 0
    teste(bitEmP(-4194305, 22), 0);
    teste(bitEmP(9, 3), 1);
    teste(bitEmP(16, 3), 0);
    teste(bitEmP(0x1 << 5, 4), 0);
    teste(bitEmP(0x1 << 31, 31), 1);
    teste(bitEmP(-1073741825, 30), 0);
    teste(bitEmP(-1073741825, 31), 1);
    puts("");

    puts("Teste: byteEmP");
    teste(byteEmP(0x766B, 1), 0x76);
    teste(byteEmP(0x766B, 0), 0x6B);
    teste(byteEmP(0x8420, 0), 0x20);
    teste(byteEmP(0x12345678, 3), 0x12);   // retorna 0x12
    teste(byteEmP(0x12345678, 2), 0x34);   // retorna 0x34
    teste(byteEmP(0x12345678, 1), 0x56);   // retorna 0x56
    teste(byteEmP(0x12345678, 0), 0x78);   // retorna 0x78
    teste(byteEmP(0x321, 1), 0x03);        // retorna 0x03
    teste(byteEmP(0x321, 0), 0x21);        // retorna 0x21
    puts("");

    puts("Teste: negacaoLogica");
    teste(negacaoLogica(0), 1);
    teste(negacaoLogica(1), 0);
    teste(negacaoLogica(-1), 0);
    teste(negacaoLogica(64), 0);
    teste(negacaoLogica(-64), 0);
    teste(negacaoLogica(2147483647), 0);
    teste(negacaoLogica(-2147483648), 0);
    puts("");
}