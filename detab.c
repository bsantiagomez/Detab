#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABESC '\t'
#define SPACE ' '
#define TABSDEFAULT 8


int main(int argc, const char* argv[]){
    int c, spcs = 0, tabs = 0, tab_per_spc = 0;
    tab_per_spc = argc == 4 ? atoi(argv[3]) : TABSDEFAULT;  
    if(argc != 3 && argc != 4){
        fprintf(stderr, "Incorrect Input usage: ./entab.c input.txt outfile.txt numberOfSpaces(optional, default is 8)\n");
        exit(1);
    }

    FILE* infile = fopen(argv[1], "r");
    FILE* outfile = fopen(argv[2],"w");

    while((c = fgetc(infile)) != EOF){
        if(c == SPACE)
            if(spcs++ == 0)     { continue;}
        else if( c != SPACE){
            tabs = spcs / tab_per_spc;
            spcs = spcs % tab_per_spc;
            while(tabs > 0)     {   fputc('\t', outfile);}
            while(spcs > 0)     {   fputcs(' ', outfile);}
            fputc(c,outfile);
        }
        
    }
    return 0;
}
