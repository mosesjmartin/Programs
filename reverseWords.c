/* Reverse words in a sentence */

#include<stdio.h>
#include<string.h>
#include<malloc.h>

int isAlphabet(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    } else {
        return 0;
    }
}

char* reverseString(char *str, int start, int end) {
    int i, j;
    char temp;
    j = (end - start)/2;
    for(i = 0; i <= j; i++) {
        temp = str[start + i];
        str[start + i] = str[end - i];
        str[end - i] = temp;
    }
    return str;
}

char* reverseSentence(char *str) {
    int i, length, j;
    length = strlen(str);
    i = 0;
    while(i < length) {
        if(!isAlphabet(str[i])) {
            i++;
            continue;
        }
        j = i + 1;
        while(j < length && isAlphabet(str[j])) {
            j++;
        }
        str = reverseString(str, i, j - 1);
        i = j + 1;
    }
    return str;
}

int main() {
    char *str;
    str = (char *)malloc(10000);
    scanf("%[^\n]s",str);
    printf("Reversed Sentence: %s\n",reverseSentence(str));
    return 1;
}