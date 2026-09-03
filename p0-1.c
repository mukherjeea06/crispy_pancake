#include <stdio.h>
#include <ctype.h> //to convert from lower to upper

typedef struct {
    char letter;
    int count;
} Letter; //we can do struct nameofstruc{} or do typedef struct{}nameofstruct;


void count_chars(Letter arr[], char ch){
    /*idea: check what character is entered and match it against the keys in TheAlphabet.
    If it matches, then increment the count of that character(arr[i].character) ("key")
*/
    ch = tolower(ch); //so that it will check upper and lower case as the same --increment regardless
    for (int i = 0; i<26 ; i++){
        if (ch == arr[i].letter){ //check if it matches the "letter"
            //then increment count
            arr[i].count++;
        }
    }
}


int main() {
    char ch;
    
    Letter TheAlphabet[26]; //create an array of 26 letters
    //initialize and set the letters of the alphabet and the count to 0
    for (int i =0; i<26 ; i++){
        TheAlphabet[i].letter = 'a' + i; //a+26 = 'b'...
        TheAlphabet[i].count = 0;
    } 

    while (!feof(stdin)){
        scanf("%c", &ch); //reading a single character from stdin
        //printf("%c", ch); //print the character
        count_chars(TheAlphabet, ch);
    }

    //print the results --> going through the array (TheAlphabet) and prints each letter, count pair
    for (int i = 0; i<26; i++){
        printf("%c %d\n", TheAlphabet[i].letter, TheAlphabet[i].count);
    }
    return 0;
}
