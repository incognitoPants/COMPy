#include <iostream>
#include <vector>
#include <string>
//#include "COMPy.h"
using namespace std;

int main () {
  
  
//DISPLAY & INPUT REQUEST
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
              //Replace list_content with actual vector name. Insert allows addition to list to occur at the end
              
                COMPy::list[varName] = list_content.insert(list_content.end(), listmem); 
                listmem = ""; //reset listmem to empty string
              }
              else {
                listmem.append(input,i,1);  //Append character to existing string
              }
            }
      }
  }
  
  
  //Display function?
  //if no assignment operator is found, display matching variable name
  //1) Access Map
  map<string, vector<string>>::iterator list_it;
  
  list_it = COMPy::list.find("input");
  if (list_it != COMPy::list.end()) {
    //2)Iterate INSIDE the vector to show all contents
    cout << "[ ";
    for(int i = 0; i < list_it.second.size(); i ++) {
      cout << (*it).second[i];
    }
    cout << " ]";
  }
  
  //Create a variable name if no matching key
  if (list_it == list.end()) {
  for (int i = 0; i < input.length(); i++) {
    if(input.at(i) != ' ')
          varName.append(input,i,1);  //append each character to varName
  }
  
  }
  }
}
