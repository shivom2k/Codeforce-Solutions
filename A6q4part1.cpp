#include <cstring> 
#include <iostream> 
#include <string.h> 
  
using namespace std; 
  class CompareString { 
  
public:  char str[25];
  CompareString(char str1[]) 
    { 
        
        strcpy(this->str, str1); 
    } 
  
   
    int operator==(CompareString s2) 
    { 
        if (strcmp(str, s2.str) == 0) 
            return 1; 
        else
            return 0; 
    }  
};
void testcase1() 
{ 
    
    char str1[] = "Geeks"; 
    char str2[] = "ForGeeks"; 
  
   
    CompareString s1(str1); 
    CompareString s2(str2); 
  
    cout << "Comparing \"" << s1.str << "\" and \""
         << s2.str << "\"" << endl; 
  
    compare(s1, s2); 
} 

int main(){
	testcase1();
	return 0;
}
  
