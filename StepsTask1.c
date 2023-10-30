#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

FITNESS_DATA information[20000];
FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("An error occured, please fix it!");
        exit(1);
    }
    return file;
}

// Complete the main function
int main() {

    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");

    int buffer_size = 256;
    char line_buffer[buffer_size];
    int count = 0;

    while (fgets(line_buffer, buffer_size, file) != NULL) {
        char date[11];
        char time[6];
        char steps[10];

        tokeniseRecord(line_buffer, ",", date, time, steps);

        strcpy(information[count].date, date);
        strcpy(information[count].time, time);
        information[count].steps = atoi(steps);
        count++;
    }

    fclose(file);

    printf("Number of records in file: %d\n", count);

    for (int i = 0; i <3; i++) {
        printf("%s/%s/%d\n", information[i].date, information[i].time, information[i].steps);
    }

    return 0;
}