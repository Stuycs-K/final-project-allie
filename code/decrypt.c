#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char rep = 'J';
//char message[] = "Hello my world, good to meet YOU";
//char key[] = "KAYDE";

void print(char** poly) {
  for (int i = 0; i < 25; i++) {
    printf("%c", poly[i/5][i%5]);
    if (i % 5 == 4){
      printf("\n");
    }
  }
  printf("\n");
}
int in(char c, char** poly) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (poly[i][j] == NULL) return 0;
      if (poly[i][j] == c) return 1;
    }
  }
  return 0;
}
char** polybius(char* key) {
  int base = 65;
  int len = strlen(key);
  char** poly = malloc(5 * sizeof(char*));
  for (int i = 0; i < 5; i++) {
    poly[i] = malloc(5);
  }
  int acc = 0;
  for (int i = 0; i < strlen(key); i++) {
    if (in(key[acc], poly) == 0) {
      poly[i/5][i%5] = key[acc];
    } else {
      len--;
      i--;
    }
    acc++;
  }

  //65  90
  for (int i = len/5; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i == len/5 && j == 0) j = len%5;
      if (strchr(key, i*5+j+base-len) != NULL || i*5+j+base-len == rep){
        base++; j--;
      } else{
        poly[i][j] = (char) (i * 5 + j + base-len);
      }
    }
  }

  return poly;
}

int* find(char** poly, char c) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (poly[i][j] == c) {
        int toret[] = {i, j};

        return &toret;
      }
    }
  }
  return NULL;
}
char* decrypt(char* key, char* mess) {
  for (int i = 0; i < strlen(key); i++) {
    key[i] = toupper(key[i]);
  }
  char* san_mess = calloc(strlen(mess) + 1, sizeof(char));
  int cur = 0;

  for (int i = 0; i < strlen(mess); i++) {
    if (isalpha(mess[i])) {
      san_mess[cur] = toupper(mess[i]);
      if (san_mess[cur] == rep) san_mess[cur] = 'I';
      cur++;
    }
    if (i == strlen(mess) - 1) san_mess[cur] = '\0';
  }
  char** poly = polybius(key);
  int* cint = calloc(strlen(san_mess) * 2, sizeof(int));

  print(poly);

//  printf("%s\n", san_mess);
int plc = 0;
  for (int i = 0; i < strlen(san_mess) * 2; i+=2) {
    int* cords = find(poly, san_mess[plc]);
    cint[i] = cords[0];
    cint[i + 1] = cords[1];
    plc++;
    //printf("%d %d \n", cords[0], cords[1]);
  }
  char* cipher = malloc(strlen(san_mess) + 1);

  for (int i = 0; i < strlen(san_mess); i++) {
    cipher[i] = poly[cint[i]][cint[i+strlen(san_mess)]];
  }
  cipher[strlen(san_mess)] = '\0';

  return cipher;
}



int main(int num, char* args[]) {
  char* message = args[1];
  char* key = args[2];
  char* cipher = decrypt(key, message);
  printf("%s", cipher);

}
