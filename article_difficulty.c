#include <stdio.h>
#include <stdlib.h>

/**
* Owen Ganzer
* 10/1/2020
* This program will read in filesname from the command line
* and calculate the averate word length of each document
* Finally printing out the document with the highest avg
* (Most difficult) and the document with the lowest avg
* (Least difficult).
 */

int main(int argc, char *argv[]){
        
        char ch;
        FILE *file;
        int charcount = 0, wordcount = 0;
        double difAvg = 0.0;
        int hard = 0, easy = 0;
        double hardc = 0.0, easyc = 99999.99;

        if(argc == 2){
                printf("Most difficult document: %s\n", argv[1]);
                printf("Least difficult document: %s\n", argv[1]);
        }else{
                for(int i = 1; i < argc; i++){
                        charcount = 0;
                        wordcount = 0;
                        file = fopen(argv[i], "r");
                        while((ch = getc(file)) != EOF){
                                if(ch != ' ' && ch != '\n'){
                                        ++charcount;
                                }
                                if(ch == ' ' || ch == '\n'){
                                        ++wordcount;
                                }
                        }
                        difAvg = (float)charcount / (float)wordcount;
                        if(difAvg > hardc){
                                hard = i;
                                hardc = difAvg;
                        }
                        if(difAvg < easyc){
                                easy = i;
                                easyc = difAvg;
                        }
                        fclose(file);
                }
                printf("Most difficult document: %s\n", argv[hard]);
                printf("Least difficult document: %s\n", argv[easy]);
                
        }
               
        return 0;
}


