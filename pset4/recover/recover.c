#include <stdio.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover file\n");
        return 1;
    }
    
    // remember filename
    char *infile = argv[1];
    
    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    // set buffer, jpg signature, counter & output file pointer
    unsigned char ch[512];
    int signature[3] = {0xff, 0xd8, 0xff};
    int counter = 0;
    FILE *outptr = NULL;

    // read through infile while not end of file
    while(fread(&ch, 512, 1, inptr) == 1)
    {
        // check for jpg signature
        if (ch[0] == signature[0] && ch[1] == signature[1] && ch[2] == signature[2] && ch[3] <= 0xef && ch[3] >= 0xe0)
        {
            // close output file if open
            if (outptr != NULL) 
            {
                fclose(outptr);    
            }
            
            // set output filename to counter
            char outname[8];
            sprintf(outname, "%03d.jpg", counter);
            
            // open output file
            outptr = fopen(outname, "w");
            if (outptr == NULL)
            {
                fprintf(stderr, "Could not create %s", outname);
            }
            // increase counter
            counter++;
        } 
        
        if (outptr != NULL)
        {
            fwrite(&ch, 512, 1, outptr);            
        }
    }
    
    // close input file
    fclose(inptr);
    fclose(outptr);
    
    // success
    return 0;
}

