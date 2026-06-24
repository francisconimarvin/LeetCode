#include <stdio.h>

// Sliding window approach (can also use set)
int lengthOfLongestSubstring(char* s) {
    // ASCII conversion (it may be 256)
    int charMap[128] = {0}; // Hashmap simulation
    int left = 0;
    int maxLength = 0;
    
    for (int right = 0; s[right] != '\0'; right++) {
        char currChar = s[right];
        charMap[currChar]++;
        
        // Update window if found the same character
        while (charMap[currChar] > 1) {
            char leftChar = s[left];
            charMap[leftChar]--; 
            left++;
        }
        
        // Current length
        int currLength = right - left + 1;
        
        // Compare maxLength to currLength
        if (currLength > maxLength) {
            maxLength = currLength;
        }
    }
    return maxLength;
}