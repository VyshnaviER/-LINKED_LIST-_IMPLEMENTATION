#include <stdio.h>
#include <stdlib.h>

//Function to create a new file or overwrite if it already exists
void createFile(const char *filename) {
    FILE *fp = fopen(filename, "w"); //open in write mode
    if (fp == NULL) {
        printf("Oops Couldn't create the file.\n");
        return;
    }
    printf("File '%s' has been created successfully.\n", filename);
    fclose(fp); //close the file after creating
}

//Function to write initial content to the file
void writeToFile(const char *filename) {
    FILE *fp = fopen(filename, "w"); //open in write mode again
    if (fp == NULL) {
        printf("Oops! Couldn't open the file for writing.\n");
        return;
    }

    //Writing a few lines to the file
    fprintf(fp, "Hey there! This is some sample content.\n");
    fprintf(fp, "File created and edited by Vyshnavi.\n");
    printf("Successfully wrote content to '%s'\n", filename);
    fclose(fp);
}

//Function to add more lines to the existing file
void appendToFile(const char *filename) {
    FILE *fp = fopen(filename, "a"); //open in append mode
    if (fp == NULL) {
        printf("Error in opening file for appending.\n");
        return;
    }

    //Appending another line
    fprintf(fp, "This is an extra lin added later.\n");
    printf("New line added to  '%s'\n", filename);
    fclose(fp);
}

//Function to read content from the file and print it
void readFromFile(const char *filename) {
    FILE *fp = fopen(filename, "r"); //open in read mode
    char buffer[1000]; //buffer to store file content
    
    if (fp == NULL) {
        printf("Error! File can't be opened for reading.\n");
        return;
    }

    printf("Reading from '%s':\n", filename);

    //Read and print file line by line
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }

    fclose(fp); //close after reading
}

//main function to control the flow
int main() {
    const char *filename = "codtech_file.txt"; //file to be used

    createFile(filename);      // Creates the file
    writeToFile(filename);     // Writes data
    appendToFile(filename);    // Appends data
    readFromFile(filename);    // Reads and displays data

    return 0;
}
