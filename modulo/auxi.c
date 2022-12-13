#include "definitions.h"
#include "carta.h"
#include "estrategia.h"
#include "mao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void retornaFrase(){ //retorna frases 35% das vezes em que é chamada
  const char *listaFrases[] = {"Poxa vida!", 
                               "Que nervoso...",
                               "UNO!! Brincadeira...",
                               "Alguem ta querendo umas cartas emprestadas?",
                               "TRUCO! Eh mentira...",
                               "Aff...queria estar vendo a copa"};

  int indice = rand()%6;
  int chance = rand()%100;

  if(chance<=35){
    printf("SAY %s\n", listaFrases[indice]);
  }
}

void recebeCartas(int qtdCartas, Jogador *bot){ //recebe as cartas enviadas pelo gerenciador após açao BUY
    char cartas[qtdCartas][MAX_LINE];
    Carta c;

    for(int i=0; i<qtdCartas; i++){
        scanf(" %s\n", cartas[i]);
        c = gerarCarta(cartas[i]);
        adicionaCarta(bot, c);
    }
}

Carta acaoDescarta(Jogador *bot, int indice, char *auxNaipe){ //envia a acao DISCARD para o gerenciador e atualiza a mao do bot
  char naipe[MAX_LINE];
  Carta c = bot->maoDoJogador.cartasDoJogador[indice];
  strcpy(auxNaipe, c.valorNaipe);

  if(strcmp(c.valorCarta, "A") == 0 || strcmp(c.valorCarta, "C") == 0){ //se carta descartada for C ou A, envia outro complemento 
      strcpy(naipe, naipeFrequente(bot));
      naipe[strlen(naipe)] = '\0';
      printf("DISCARD %s%s %s\n", c.valorCarta, c.valorNaipe, naipe);
      strcpy(auxNaipe, naipe);
    }else{
      printf("DISCARD %s%s\n", c.valorCarta, c.valorNaipe);
    }
    auxNaipe[strlen(auxNaipe)] = '\0';

    retiraCarta(bot, indice); //retira a carta da mao do jogador
    return c;
}

void acaoCompra(int qtdCartas, Jogador *bot,Carta totalDeCartas[108]){ //envia acao BUY para o gerenciador e atualiza a mao do jogador com as cartas compradas
  char cartas[qtdCartas][MAX_LINE];
  Carta c;

  printf("BUY %d\n", qtdCartas);

  for(int i=0; i<qtdCartas; i++){ //recebe cartas do gerenciador e add na mao
    scanf(" %s\n", cartas[i]);
    c = gerarCarta(cartas[i]);
    //Acompanha total de cartas
    acompanhaTotal(totalDeCartas, c);
    adicionaCarta(bot, c);
  }
}