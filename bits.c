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

/*
Todo numero diferente de 0 é visto como true e o 0 sempre é false, sempre que usamos operadores lógicos essa lógica é aplicada.
O primeiro NOT torna o retorno falso e o segundo NOT o torna true.Logo qualquer numero que seja diferente de 0 será false depois true.
e quando for 0 retornará retornará false, true e false.
 */
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

/* 
 O & checa se os bits são iguais, então vejo onde os bits são iguais com XOR. Caso o bit comparado em X seja igual em Y, XOR me retorna 0, 
 caso diferentes XOR retorna 1. Agora temos um binario setado em 0 os bits que queremos salvar. Precisamos do maior número que podemos ter entre X e Y
 de bits ligados para cortar com os 1's no nosso binario alvo, já que os numeros que queremos são so os bits 0. Para obter esse binario para fazer esse 
 eliminação de 1's que queremos basta fazer X | Y, assim todo bits ligado será capturado. Agora basta fazer :
 ( Nosso binario alvo com os 0 que queremos salvar) ^ (Nosso binario feito com X | Y para cortar os 1's que não queremos).
 Dessa forma todo 0 ou 1 que seriam salvos por X & Y será salvo.
 */
int32_t bitwiseAnd(int32_t x, int32_t y) {
    return ((x ^ y) ^ (x | y));
}

/* 
Apenas checa bit a bit se os numeros são iguais, se bits simultaneos forem iguais, o XOR irá retornar 0, caso diferentes 1. Se o X todo,
comparado ao Y for igual, todo retorno do XOR irá ser 0, resultado em false mas X  = Y, portanto precisamos do NOT.
Caso algum bit de X seja diferente do correspondente em Y XOR retornará 1 e isso é true, mas como X != Y precisamos do NOT para retornar false
 */
int32_t ehIgual(int32_t x, int32_t y) {
    return !(x ^ y);
}

/*
Imaginando que a multiplicação seja a ideia de quantas vezes eu gostaria que um valor x fosse somado a ele mesmo.
entao, se multiplico x por 7 eu estou somando 7 vezes o valor de x a ele mesmo.
Assim, eu sei que << multiplica por 2^n, onde n é a quantidade de vezes que eu definir pro shift
fazendo, << 3 eu estaria fazendo 2^3 que daria 8.
Então, se eu fizer x << 2^3 -> x << 8 -> x * 8. Logo, eu estaria somando o valor de x a ele mesmo 8 vezes.
Mas eu gostaria de somar o valor de X a ele mesmo somente 7 vezes, como somei 1 x a mais, eu irei subtrair dele
Dessa forma, x << 3 - x -> x * 2^3 - x -> x * 8 -x -> 8x - x -> 7x! assim estarei somando x a ele mesmo 7 vezes
em outras palavras multiplicando x por 7.
 */
int32_t mult7(int32_t x) {
    return (x << 3) - x;
}

/*
 Tomando como exemplo 8 = (1000) e p = 3, logo nos queremos sabe o valor do quarto bit. Basta nos fazermos 8 >> 3 que teremos 0001.Para pegar somente
 o valor que nos interessa devemos fazer (8 >> 3) & 1, assim comparamos somente o bit de interesse. 
 */
int32_t bitEmP(int32_t x, uint8_t p) {
    return ((x >> p) & 1 ) ;
}

/*
  parecido com o bitEmP, vou tomar como exemplo 0xF5FEAC32, p = 0 e a mascara 0xFF. Assim, quero saber o valor do primeiro conjunto de 2Bytes ou 8 bits.
  logo, 0xF5FEAC32 -> 0x32. Seguindo essa ideia e sabendo que o valor de p = {0,1,2}. Vou seguir o seguinte raciocionio:
  p = 0 -> 0 Bytes -> 0 bits
  p = 1 -> 2 Bytes -> 8 bits
  p = 2 -> 4 Bytes -> 16 bits
  p = 3 -> 6 Bytes -> 24 bits
  como eu sei que o conjunto de dados que eu quero mostrar tem tamanho 2 Bytes ou 8 bits e sabendo das propriedades do & vou usar a mascara 0xFF
  como 0xFF representa 000...11111111 em binario.
  Assim, (x >> (p<<3)) & 0XFF, seguindo a seguinte tabela:
  p = 0 -> 0 Bytes -> 0  bits => (0xF5FEAC32 >> (0 << 3)) & 0XFF => (0xF5FEAC32 >> 0 * 2^3) => 0xF5FEAC32 >> 0  & 0xFF => 0xF5FEAC32 & 0xFF -> 32
  p = 1 -> 2 Bytes -> 8  bits => (0xF5FEAC32 >> (1 << 3)) & 0XFF => (0xF5FEAC32 >> 1 * 2^3) => 0xF5FEAC32 >> 8  & 0xFF => 0x00F5FEAC & 0xFF -> AC
  p = 2 -> 4 Bytes -> 16 bits => (0xF5FEAC32 >> (2 << 3)) & 0XFF => (0xF5FEAC32 >> 2 * 2^3) => 0xF5FEAC32 >> 16 & 0xFF => 0x0000F5FE & 0xFF -> FE
  p = 3 -> 6 Bytes -> 24 bits => (0xF5FEAC32 >> (3 << 3)) & 0XFF => (0xF5FEAC32 >> 3 * 2^3) => 0xF5FEAC32 >> 24 & 0xFF => 0x000000F5 & 0xFF -> F5
  */
int32_t byteEmP(int32_t x, uint8_t p) {
    return (x >> (p << 3) ) & 0xFF;
}

/*
Fazendo OR de X com seu complemento a 2 e depois somando 1 elimina todas as possibilidades de um numero que não seja 0 retornar 1. Pois quando se inverte
os bits de 0 e soma 1 todo os bits voltam a ser 0 e quando fazemos o shift pra direita só resta um 0 que temos que somar a 1 para o retorno ser true.
Essa volta toda só para o 0 retornar 1. Os outros numeros quando se fizer o complemento sempre terão um bit mais a esquerda setado como 1 então no final
somando este 1 com 1 sempre  irão retornar 0
 */
 
int32_t negacaoLogica(int32_t x) {
    return ((x | (~x + 1)) >> 31) + 1;
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