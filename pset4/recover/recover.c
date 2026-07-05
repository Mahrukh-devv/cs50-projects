#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Buffer for 512 bytes
    uint8_t buffer[512];

    // JPEG file pointer and counter
    FILE *img = NULL;
    int count = 0;
    char filename[8];

    // While there's still data left to read
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check if start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous JPEG if open
            if (img != NULL)
            {
                fclose(img);
            }

            // Create new JPEG file
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            count++;
        }

        // Write to JPEG if we've found one
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Close remaining files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);

    return 0;
}
