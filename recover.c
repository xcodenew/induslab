#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
int jpegg;
typedef uint8_t BYTE;
bool isJpg(BYTE buffer[])
{
      if((buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && buffer[3] == 224)||
    (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe1))
    {
        return true;
    }
    return false;
}

bool isbmp(BYTE buffer[])
{
      if(buffer[0] == 0x42 && buffer[1] == 0x4d)
    {
        return true;
    }
    return false;
}

bool ismp3(BYTE buffer[])
{
      if(buffer[0] == 0x49 && buffer[1] == 0x44 )
    {
        return true;
    }
    return false;
}


FILE *start_bmp(int g)
{
        char fname[60];
        sprintf(fname, "Desktop/RECOVERED/0%i.bmp",g);
        FILE *out = fopen(fname, "w");
        if(out == NULL)
        {
            printf("sorry,Could not open %s for writing", fname);
            return NULL;
        }
        return out;
}

FILE *start_mp3(int g)
{
        char fname[60];
        sprintf(fname, "Desktop/RECOVERED/0%i.mp3",g);
        FILE *out = fopen(fname, "w");
        if(out == NULL)
        {
            printf("Sorry,Could not open %s for writing", fname);
            return NULL;
        }
        return out;
}


FILE *start_jpg(int g)
{
        char fname[60];
       sprintf(fname, "Desktop/RECOVERED/0%i.jpg",g);
        FILE *out = fopen(fname, "w");
        if(out == NULL)
        {
            printf("Could not open %s for writing", fname);
            return NULL;
        }
        return out;
}


int main ( int argc, char *argv[] )
{

system("clear");
system("echo Enter the name of pendrive or memory_card :: ");
system("mkdir -p Desktop/RECOVERED");
system("read a;c=$(mount | grep -i $a|cut -c 1-12);diskutil unmount /Volumes/$a;echo $c > Desktop/RECOVERED/f.txt;");
system("");
int reply=0;


char ch[32];
FILE *cdi=fopen("Desktop/RECOVERED/f.txt","r");
fgets(ch,13,cdi);

if(strlen(ch)<3){
printf("\nPLEASE ENTER YOUR USB\n");
exit(0);
}   

fclose(cdi);
for(reply=0;reply<333;reply++){}
FILE *fp = fopen(ch, "r");
    if(fp == NULL)
    {
        printf("CODE FAILED::Could not open file.\n");
        return 1;
    }

    
    int g = 0;

    
    BYTE buffer[512];
printf("\n\n what you want to recover::   \n press 1 for jpg image \n press 2 for bmp images \n press 3 for mp3 songs \n\n");
scanf("%d",&reply);
switch(reply){
case 1:    
system("echo ");
system("echo FOLDER NAMED RECOVERD HAS BEEN CREATED ON DESKTOP : CHECK YOUR RECOVERED DATA THERE");
system("echo ");
system("echo RECOVERY PROCESS HAS STARTED  :  TO STOP RECOVERING AT ANY POINT PRESS CTRL+C" );
jpegg=fread(buffer, sizeof(BYTE), 512, fp);

    
    while(jpegg != 0)
    {
        while(isJpg(buffer))
        {
             
            FILE *outfile = start_jpg(g);
		 fwrite(buffer, sizeof(BYTE), 512, outfile);
            
            
            if(fread(buffer, sizeof(BYTE), 512, fp) == 0)
                break;
            
            
            while(!isJpg(buffer))
            {
                fwrite(buffer, sizeof(BYTE), 512, outfile);
                if(fread(buffer, sizeof(BYTE), 512, fp) == 0)
                    break;
            }

            
            fclose(outfile);
            g++;
        }
	jpegg=fread(buffer, sizeof(BYTE), 512, fp);
        
    }
     
    fclose(fp);
    return EXIT_SUCCESS;
break;

case 2:
system("echo ");
system("echo FOLDER NAMED RECOVERD HAS BEEN CREATED ON DESKTOP : CHECK YOUR RECOVERED DATA THERE");
system("echo ");
system("echo RECOVERY PROCESS HAS STARTED  :  TO STOP RECOVERING AT ANY POINT PRESS CTRL+C" );

while(fread(buffer, sizeof(BYTE), 512, fp) != 0)
    {
        while(isbmp(buffer))
        {
            
            FILE *outfile = start_bmp(g);
                 fwrite(buffer, sizeof(BYTE), 512, outfile);

            
            if(fread(buffer, sizeof(BYTE), 512, fp) == 0)
                break;

            
            while(!isbmp(buffer))
            {
                fwrite(buffer, sizeof(BYTE), 512, outfile);
                if(fread(buffer, sizeof(BYTE), 512, fp) == 0)
                    break;
            }

            
            fclose(outfile);
            g++;
        }

    }
    
    fclose(fp);
    return EXIT_SUCCESS;


break;

case 3:
system("echo ");
system("echo FOLDER NAMED RECOVERD HAS BEEN CREATED ON DESKTOP : CHECK YOUR RECOVERED DATA THERE");
system("echo ");
system("echo RECOVERY PROCESS HAS STARTED  :  TO STOP RECOVERING AT ANY POINT PRESS CTRL+C" );

while(fread(buffer, sizeof(BYTE), 512, fp) != 0)
    {
        while(ismp3(buffer))
        {
           
            FILE *outfile = start_mp3(g);
                 fwrite(buffer, sizeof(BYTE), 512, outfile);

            
            if(fread(buffer, sizeof(BYTE), 512, fp) == 0)
                break;

            
            while(!ismp3(buffer))
            {
                fwrite(buffer, sizeof(BYTE), 512, outfile);
                if(fread(buffer, sizeof(BYTE), 512, fp) == 0)
                    break;
            }

            
            fclose(outfile);
            g++;
        }

    }
   
    fclose(fp);
    return EXIT_SUCCESS;


break;

default:

printf("\n INCORRECT CHOICE \n\n");

break;
}

}                       


