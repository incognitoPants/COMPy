#include <iostrea>
#include <vector>
#include <string>
//#include "COMPy.h"
using namespace std;

int main () {
  string input = " "; //Variable for capturing user input
  
  while (input.length() > 0) { //Continue loop as long as input is made
  //Capture User Input Here
    cout ">>>"; //Q: Is it possible to overload the INPUTSTREAM operator so it prints out >>> everytime it requires user input?
    getline(cin, input);
    
    //Break down user input to variables (keys) and list contents
    string varName = "";  //variable name or lhs
    string listmem = "";  //list member
    size_t stop = input.find('=');
    if(stop!=string::npos) { //if assignment operator is found
      for(int i = 0; i < stop; i++) { //capture variable name
        if(input.at(i) != ' ')
          varName.append(input,i,1);  //append each character to varName
      }
      //find index of beginning and end of list markers
      size_t lbeg = input.find('[');
      size_t lend = input.find(']');
      for(int i = lbeg+1; i < lend; i++) {  //capture list contents into a string
            if(input.at(i) != ' ') {
              if (input.at(i) == ',') { //if comma found, store current list member to vector
                list_content.insert(list_content.end(), listmem); //stores to existing vector. Replace list_content with actual vector name
                listmem = ""; //reset listmem to empty string
              }
              else {
                listmem.append(input,i,1);  //Append character to existing string
              }
            }
      }
  }
  
}
