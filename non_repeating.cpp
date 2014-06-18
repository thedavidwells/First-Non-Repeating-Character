//
//  David Wells
//  Find the first non-repeating character in a string:("DEFD" -> E )
//

#include <iostream>
#include <unordered_map>
using namespace std;

//  For readibility set the unordered multimap type name to hash_table
typedef unordered_multimap<int, char> hash_table;

//  Function declarations:
bool unit_test(char expected_result, char actual_result);
char firstNonRepeating(string inputString);



int main(int argc, const char * argv[]) {
    
    string input = "DEFD";
    char expected_result = 'E';
    cout << "First non-repeated character is: " << firstNonRepeating(input) << endl;
    
    
    //Run Unit Test
    if ( unit_test(expected_result, firstNonRepeating(input)) ) {
        cout << "Passed unit test"<< endl;
    }
    else cout << "Failed unit test" << endl;
    
    return 0;
}


//  Function definitions:
char firstNonRepeating(string inputString){
    
    int charArray[256] = {0};
    int length = (int)inputString.length();
    
    for (int i = 0; i < length; i++) {
        
        charArray[ inputString[i] ]++;
    }
    
    for (int i = 0; i < length; i++) {
        if (charArray[ inputString[i] ] == 1) {
            return inputString[i];
        }
    }
    
    return NULL;
}




bool unit_test(char expected_result, char actual_result) {
    
    
    string testString1 = "HellOHe";
    string testString2 = "happyh";
    string testString3 = "";
    
    char expected1 = 'o';
    char expected2 = 'a';
    char expected3 = NULL;
    
    char result1 = firstNonRepeating(testString1);
    cout << "Result1: " << result1 << endl;
    result1 = tolower(result1);
    char result2 = firstNonRepeating(testString2);
    cout << "Result2: " << result2 << endl;
    result2 = tolower(result2);
    char result3 = firstNonRepeating(testString3);
    cout << "Result3: " << result3 << endl;
    result3 = tolower(result3);
    
    if (actual_result == expected_result && expected1 == result1 && expected2 == result2 && expected3 == result3) {
        return true;
    }
    else return false;
    
}
