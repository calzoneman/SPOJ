#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Lookup table for incrementing a digit (with wraparound to '0')
char digittable[10] = {'1','2','3','4','5','6','7','8','9','0'};

// Handle the edge case of 1-2 digit numbers
char *next_small(char *k) {
    int len = strlen(k);
    char *next;
    // 1 digit
    if(len == 1) {
        // Increment digit
        char d = digittable[k[0]-48];
        // Edge case!
        // Original digit was 9, so the next palindrome is 11
        if(d == '0') {
            next = calloc(3, sizeof(char));
            next[0] = '1';
            next[1] = '1';
            return next;
        }
        // Next palindrome is next digit
        else {
            next = calloc(2, sizeof(char));
            next[0] = d;
            return next;
        }
    }
    // 2 digits
    else {
        // Same digit twice => increment them both
        if(k[0] == k[1]) {
            // Edge case!  99 => 101
            if(k[0] == '9') {
                next = calloc(4, sizeof(char));
                next[0] = '1';
                next[1] = '0';
                next[2] = '1';
                return next;
            }
            else {
                next = calloc(3, sizeof(char));
                next[0] = k[0]+1;
                next[1] = k[1]+1;
                return next;
            }
        }
        else {
            // First digit < second digit => inc first digit and
            // assign to both digits
            // (e.g. 16 => 22)
            if(k[0] < k[1]) {
                next = calloc(3, sizeof(char));
                next[0] = k[0]+1;
                next[1] = next[0];
                return next;
            }
            // First digit > second digit (== case already covered)
            // Set second digit = first
            // (e.g. 52 => 55)
            else {
                next = calloc(3, sizeof(char));
                next[0] = k[0];
                next[1] = k[0];
                return next;
            }
        }
    }
}

// h4x
char *fix_zero(char *k) {
    int len = strlen(k);
    int i;
    // Check if any digits are not 0
    // If so, no fixing needed
    for(i = 0; i < len; i++) {
        if(k[i] != '0')
            return k;
    }

    // Copy the string and add a '1' to each end
    // (e.g. 0000 => 10001)
    char *next = calloc(len+2, sizeof(char));
    strcpy(next+1, k);
    next[0] = '1';
    next[len] = '1';
    return next;
}

char *next_odd(char *k) {
    int len = strlen(k);
    int mid = len/2;
    // Whether or not the middle digit needs to be incremented
    // in order to preserve the condition next palindrome > current
    bool inc_mid = true;
    char *next = calloc(len + 1, sizeof(char));
    strcpy(next, k);
    int i;
    // For each digit from left to middle, swap it with the digit on the
    // right.  Assign inc_mid accordingly.
    // (e.g. 12345 => 12321, inc_mid=true
    for(i = 0; i < mid; i++) {
        if(k[len-i-1] < k[i])
            inc_mid = false;
        else if(k[len-i-1] > k[i])
            inc_mid = true;
        next[len-i-1] = k[i];
    }
    if(inc_mid) {
        // Find next digit
        char d = digittable[k[mid]-'0'];
        next[mid] = d;
        // Edge case!  Digit wrapped back around to 0, have to increment
        // the previous one (repeat as necessary)
        int j = 1;
        while(d == '0') {
            d = digittable[k[mid-j]-'0'];
            next[mid-j] = d;
            j++;
        }
        // Re-swap the digits in case they changed
        for(i = 0; i < mid; i++) {
            next[len-i-1] = next[i];
        }
    }
    return fix_zero(next);
}

char *next_even(char *k) {
    int len = strlen(k);
    int mid = len/2-1;
    // Whether or not the middle digit needs to be incremented
    // in order to preserve the condition next palindrome > current
    bool inc_mid = true;
    char *next = calloc(len + 1, sizeof(char));
    strcpy(next, k);
    int i;
    // For each digit from left to middle, swap it with the digit on the
    // right.  Assign inc_mid accordingly.
    // (e.g. 123456 => 123421, inc_mid=true
    for(i = 0; i < mid; i++) {
        if(k[len-i-1] < k[i])
            inc_mid = false;
        else if(k[len-i-1] > k[i])
            inc_mid = true;
        next[len-i-1] = k[i];
    }
    if(inc_mid) {
        // Digits are the same, increment them both
        // (e.g. 33 => 44)
        if(next[mid] == next[mid+1]) {
            // Edge case!
            // Wraparound from 99 to 00
            if(next[mid] == '9') {
                next[mid] = '0';
                next[mid+1] = '0';
            }
            else {
                next[mid]++;
                next[mid+1]++;
            }
        }
        else {
            // First digit < second digit => increment first,
            // assign to both
            // (e.g. 16 => 22)
            if(next[mid] < next[mid+1]) {
                next[mid]++;
                next[mid+1] = next[mid];
            }
            // First digit > second digit => set second = first
            // (e.g. 63 => 66)
            else {
                next[mid+1] = next[mid];
            }
        }
        // Edge case!
        // Incrementing wrapped around to 00
        int j = 1;
        while(next[mid-j+1] == '0') {
            next[mid-j] = digittable[next[mid-j]-'0'];
            j++;
        }
        // Re-swap digits in case they changed
        for(i = 0; i < mid; i++) {
            next[len-i-1] = next[i];
        }
    }
    return fix_zero(next);
}

int main() {
    int t;
    scanf("%d", &t);
    int i;
    for(i = 0; i < t; i++) {
        char k[1000000];
        scanf("%s", k);
        int len = strlen(k);
        if(len <= 2)
            printf("%s\n", next_small(k));
        else if(len % 2 == 0)
            printf("%s\n", next_even(k));
        else
            printf("%s\n", next_odd(k));
    }
    return 0;
}
