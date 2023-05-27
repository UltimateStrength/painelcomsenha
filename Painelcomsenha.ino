/* Programa: Painel de Senhas */
/* Carrega a biblioteca de controle do LCD */
// https://github.com/arduino-libraries/LiquidCrystal
#include <LiquidCrystal.h>
/* Define os pinos do Arduino para a comunicação com o display
*/
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/* Pinos dos botões */
int botao_DOWN = 6;
int botao_UP = 7;
/* Pino do buzzer */
int buzzer = 8;
/* Variável para armazenar a senha */
int senha = -1;
void setup() {
/* Define o número de colunas e linhas do LCD */
lcd.begin(16, 2);
/* Configura os pinos dos botões como entrada e ativa os
resistores internos */
pinMode(botao_UP, INPUT_PULLUP);
pinMode(botao_DOWN, INPUT_PULLUP);
/* Configura o pino do Buzzer como saída */
pinMode(buzzer, OUTPUT);
/* Inicia com a senha zero */
chamar(1);
}
void loop() {
/* Se pressionar o botão UP, chama a função “chamar”
incrementando a senha */
if (senha > -1 && digitalRead(botao_UP) == 0) {
 chamar(1);
}
/* Se pressionar o botão DOWN, chama a função “chamar”
decrementando a senha */
if (senha > 0 && digitalRead(botao_DOWN) == 0) {
 chamar(2);
}
}

/* Função responsável por imprimir a senha no display */
void chamar(int botao)
{
tone(buzzer, 262, 250);
delay(250);
tone(buzzer, 2093, 400);
delay(400);
if (botao == 1) {
 senha += 1;
}
if (botao == 2)
{
 senha -= 1;
}
lcd.clear();
lcd.setCursor(0, 0); /* Posiciona o cursor na coluna 0 e
linha 0 */
lcd.print("Painel de Senhas");
lcd.setCursor(0, 1); /* Posiciona o cursor na coluna 0 e
linha 1 */
lcd.print("Senha: " + String(senha));
}

