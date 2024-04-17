//KENNEDY KAMAU KAMANDE 
//ENE212-0169/2021
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "Kennedy.txt";
    char userInput[256];

    // Create the file and write data to it
    file = fopen(filename, "w+");
    if (file == NULL) {
        printf("Error: Unable to create the file.\n");
        exit(1);
    }

    // Get user input and write it to the file
    printf("Enter the text to input into the file:(Max 256 characters)\n");
    fgets(userInput, sizeof(userInput), stdin);
    fprintf(file, "%s", userInput);

    // Move the file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);

    // Read data from the file
    fgets(userInput, sizeof(userInput), file);
    printf("Data read from the file:\n%s", userInput);

    // Close the file
    fclose(file);

    return 0;
}
