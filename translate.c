#include <stdio.h>
#include <string.h>

#define C 255
#define R 3
#define STATE(s) s
#define tonos 39
#define dialutika 34
#define n 237
#define m 236
#define t 244
#define p 240
#define d 100
#define b 98
#define gama 227
#define k 234
#define g 103
#define N 205
#define T 212
#define D 68
#define M 204
#define P 208
#define B 66
#define GAMA 195
#define K 202
#define G 71


typedef int (*ACTIONS)(int c,char cMap[C][R],int lastToken);

void cMapCreation(char cMap[C][R]){
  int j=225,q=193,i,y;
  char mikra[]={"avgdezh8iklmnksoprstyfxpsw"};
  char kefalaia[] = {"AVGDEZH8IKLMNKSOPRSTYFXPSW"};
    
  for(i=0;i<26;++i){
	  if (j == 242) {/*The Greek letter s creates some problems. */
		  cMap[j][0] = mikra[i];
		  ++j;
		  --i;
		  continue;
	  }
	  if ((i == 13) || (i==23)){
		  cMap[j][0] = mikra[i];
		  ++i;
		  cMap[j][1] = mikra[i];
		  cMap[j][2] = '\0';
		  ++j;
		  continue;
	}
	cMap[j][0]= mikra[i];
	cMap[j][1] = '\0';
	cMap[j][2] = '\0';
    ++j;
  }

  for (y = 0; y<27; ++y) {
	  if (q == 210) {
		  ++q;
		  --y;
		  continue;
	  }
	  if ((y == 13) || (y == 23)) {
		  cMap[q][0] = kefalaia[y];
		  ++y;
		  cMap[q][1] = kefalaia[y];
		  cMap[q][2] = '\0';
		  ++q;
		  continue;
	  }
	  cMap[q][0] = kefalaia[y];
	  cMap[q][1] = '\0';
	  cMap[q][2] = '\0';
	  ++q;
  }

  /**UPPER CASE LETTERS WITH GREEK TONS*/
  cMap[182][0] = tonos;
  cMap[182][1] = 'A';
  cMap[184][0] = tonos;
  cMap[184][1] = 'E';
  cMap[185][0] = tonos;
  cMap[185][1] = 'H';
  cMap[186][0] = tonos;
  cMap[186][1] = 'I';
  cMap[188][0] = tonos;
  cMap[188][1] = 'O';
  cMap[190][0] = tonos;
  cMap[190][1] = 'Y';
  cMap[191][0] = tonos;
  cMap[191][1] = 'W';

  /*LOWER CASE LETTERS WITH GREEK TONS*/
  cMap[220][0] = 'a';
  cMap[220][1] = tonos;
  cMap[221][0] = 'e';
  cMap[221][1] = tonos;
  cMap[222][0] = 'h';
  cMap[222][1] = tonos;
  cMap[223][0] = 'i';
  cMap[223][1] = tonos;
  cMap[252][0] = 'o';
  cMap[252][1] = tonos;
  cMap[253][0] = 'y';
  cMap[253][1] = tonos;
  cMap[254][0] = 'w';
  cMap[254][1] = tonos;

  /*UPPER CASE LETTERS WITH DIAERESIS*/
  cMap[218][0] = 'I';
  cMap[218][1] = '"';
  cMap[219][0] = 'Y';
  cMap[219][0] = '"';

  /*LOWER CASE LETTERS WITH DIAERESIS*/
  cMap[250][0] = 'i';
  cMap[250][1] = '"';
  cMap[251][0] = 'y';
  cMap[251][1] = '"';

  cMap[192][0] = 'i';
  cMap[192][1] = tonos;
  cMap[192][2] = dialutika;
  cMap[224][0] = 'y';
  cMap[224][1] = tonos;
  cMap[224][2] = dialutika;
}

/*FUNCTION FOR PRINTING THE CHARACTERS*/
void printChar(char cMap[C][R],int c) {
	putchar(cMap[c][0]);
	if (cMap[c][1] != '\0') {
		putchar(cMap[c][1]);
	}
	if (cMap[c][2] != '\0') {
		putchar(cMap[c][2]);
	}

}

/*ALL THE CHARATERS STATES*/
int state0_ANY(int c,char cMap[C][R],int lastToken) {
	if (c == n) {
		return STATE(1);
	}
	else if (c == m) {
		return STATE(2);
	}
	else if (c == gama) {
		return STATE(3);
	}
	else if(c == N){
		return STATE(4);
    }
	else if (c == M) {
		return STATE(5);
	}
	else if (c == GAMA) {
		return STATE(6);
	}
	else if (c == '\n') {
		putchar('\n');
		return STATE(0);
	}
	else{
		printChar(cMap,c);
		return STATE(0);
	}
}

/*n-CHARACTER STATE*/
int state1_n(int c,char cMap[C][R],int lastToken) {
	if ((c == t) || (c==T)) {
		c = d;
		putchar(c);
		return STATE(0);
	}
	else {
		printChar(cMap,lastToken);
		printChar(cMap, c);
		return STATE(0);
	}
}

/*m-CHARACTER STATE*/
int state2_m(int c, char cMap[C][R], int lastToken) {
	if ((c == p) || (c==P)) {
		c = b;
		putchar(c);
		return STATE(0);
	}else {
	    printChar(cMap, lastToken);
	    printChar(cMap, c);
	    return STATE(0);
	}
}

/*gama-CHARACTER STATE*/
int state3_gama(int c, char cMap[C][R], int lastToken) {
	if ((c == k) || (c==K)) {
		c = g;
		putchar(c);
		return STATE(0);
	}
	else {
		printChar(cMap, lastToken);
		printChar(cMap, c);
		return STATE(0);
	}
}

/*N-CHARACTER STATE*/
int state4_N(int c, char cMap[C][R], int lastToken) {
	if ((c == T) || (c==t)) {
		c = D;
		putchar(c);
		return STATE(0);
	}
	else {
		printChar(cMap, lastToken);
		printChar(cMap, c);
		return STATE(0);
	}
}

/*M-CHARACTER STATE*/
int state5_M(int c, char cMap[C][R], int lastToken) {
	if ((c == P) || (c==p)) {
		c = B;
		putchar(c);
		return STATE(0);
	}
	else {
		printChar(cMap, lastToken);
		printChar(cMap, c);
		return STATE(0);
	}
}

/*GAMA-CHARACTER STATE*/
int state6_GAMA(int c, char cMap[C][R], int lastToken) {
	if ((c == K) || (c==k)) {
		c = G;
		putchar(c);
		return STATE(0);
	}
	else {
		printChar(cMap, lastToken);
		printChar(cMap, c);
		return STATE(0);
	}
}

/*MAIN FUNCTION*/
int main()
{
  int c;
  char cMap[C][R];
  int state = 0;
  int lastToken;
  ACTIONS actions[] = { &state0_ANY,&state1_n,&state2_m ,&state3_gama,&state4_N,&state5_M,&state6_GAMA};
  cMapCreation(cMap);
  
  while((c=getchar())!= EOF){
	  state = (*actions[state])(c,cMap,lastToken);
	  lastToken = c;
  }

}
