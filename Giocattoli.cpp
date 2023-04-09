#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GIOCATTOLI 100 // massimo numero di giocattoli posseduti da un bambino
#define MAX_BAMBINI 100 // massimo numero di bambini

// struttura per rappresentare un singolo giocattolo
typedef struct {
  char nome[50]; // nome del giocattolo
  float prezzo; // prezzo del giocattolo
} Giocattolo;

// struttura per rappresentare un singolo bambino
typedef struct {
  char nome[50]; // nome del bambino
  int num_giocattoli; // numero di giocattoli posseduti
  Giocattolo giocattoli[MAX_GIOCATTOLI]; // elenco dei giocattoli posseduti
} Bambino;

// vettore di bambini
Bambino bambini[MAX_BAMBINI];
int num_bambini = 0; // numero di bambini presenti nel vettore

// funzione per inserire i dati di un bambino
void inserisci_bambino() {
  // richiedi il nome del bambino
  printf("\nInserisci il nome del bambino: ");
  scanf("%s", bambini[num_bambini].nome);

  // richiedi il numero di giocattoli posseduti
  printf("Inserisci il numero di giocattoli posseduti: ");
  scanf("%d", &bambini[num_bambini].num_giocattoli);

  // richiedi i dati dei giocattoli posseduti
  for (int i = 0; i < bambini[num_bambini].num_giocattoli; i++) {
    printf("Inserisci il nome del giocattolo %d: ", i+1);
    scanf("%s", bambini[num_bambini].giocattoli[i].nome);
    printf("Inserisci il prezzo del giocattolo %d: ", i+1);
    scanf("%f", &bambini[num_bambini].giocattoli[i].prezzo);
  }

  num_bambini++; // aumenta il numero di bambini presenti nel vettore
}

// funzione per visualizzare i dati dei bambini
void visualizza_bambini() {
  for (int i = 0; i < num_bambini; i++) {
    printf("\nNome bambino: %s\n", bambini[i].nome);
    printf("Numero giocattoli: %d\n", bambini[i].num_giocattoli);
    printf("Giocattoli:\n");
    for (int j = 0; j < bambini[i].num_giocattoli; j++) {
      printf(" - %s (prezzo: %.2f)\n", bambini[i].giocattoli[j].nome, bambini[i].giocattoli[j].prezzo);
    }
  }
}

// funzione per cercare un bambino dato il suo nome e stampare i suoi giocattoli
void cerca_bambino(char* nome) {
  // cerca il bambino nel vettore
  for (int i = 0; i < num_bambini; i++) {
    if (strcmp(bambini[i].nome, nome) == 0) { // se il nome del bambino corrisponde
      printf("\nGiocattoli di %s:\n", bambini[i].nome);
      for (int j = 0; j < bambini[i].num_giocattoli; j++) {
        printf(" - %s (prezzo: %.2f)\n", bambini[i].giocattoli[j].nome, bambini[i].giocattoli[j].prezzo);
      }
      return; // esci dalla funzione
    }
  }
  printf("Bambino non trovato.\n");
}

int main() {
  int scelta;
  char nome[50]; // nome del bambino da cercare

  do {
    // mostra il menu di scelta
    printf("\nMenu:\n");
    printf("1) Inserisci bambino\n");
    printf("2) Visualizza bambini\n");
    printf("3) Cerca bambino\n");
    printf("4) Esci\n");
    printf("Scelta: ");
    scanf("%d", &scelta);

    switch (scelta) {
      case 1: // inserisci bambino
        inserisci_bambino();
        break;
      case 2: // visualizza bambini
        visualizza_bambini();
        break;
      case 3: // cerca bambino
        printf("\nInserisci il nome del bambino da cercare: ");
        scanf("%s", nome);
        cerca_bambino(nome);
        break;
      case 4: // esci
        break;
      default:
        printf("\nScelta non valida.\n");
        break;
    }
  } while (scelta != 4); // ripeti finché l'utente non sceglie di uscire

  return 0;
}
