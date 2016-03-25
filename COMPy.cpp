#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include "COMPy.h"
COMPy::COMPy() { }

void COMPy::capture(std::string p_input) {
	int stop = p_input.find('=');
	//if assignment operator is found, capture variable name and find list members
	if (stop != std::string::npos) {
		for (int i = 0; i < stop; i++) { //capture variable name
			if (p_input.at(i) != ' ')
				varName.append(p_input, i, 1);  //append each character to varName
		}
		size_t lbeg = p_input.find('[');
		size_t lend = p_input.find(']');
		if (lbeg != std::string::npos && lend != std::string::npos) {
			for (int i = lbeg + 1; i < lend; i++) {  //capture list contents into a std::string
				if (p_input.at(i) == ' ' && listmem.at(0) == '"') //check if a std::string or not a space
					listmem.append(p_input, i, 1);
				else if (p_input.at(i) != ' ') {
					if (p_input.at(i) == ',') { //if comma found, store current list member to vector
						addToMember(listmem); //Insert allows addition to list to occur at the end
						listmem = ""; //reset listmem to empty std::string
					}
				}
			}
		}
		COMPy::it = m_list.find(varName);
		if (it != m_list.end() && data.size() > 0) { //if existing match is found, edit existing function
			editList(varName, data);
			resetMember();
		}
		else if (it != m_list.end()) { //if found display
			displayList(varName);
		}
		else {	//create a new key in map
			addNew(varName);
			resetMember();
		}
	}
	else { //capture variable name and save in map
		for (int i = 0; i < p_input.length(); i++) {
			if (p_input.at(i) != ' ')
				varName.append(p_input, i, 1);  //append each character to varName
		}
		addNew(varName);
		resetMember();
	}
}

//add item to vector
void COMPy::addToMember(std::string p_add) {
	data.insert(data.end(), p_add);
}
//edits an existing key's member
void COMPy::editList(std::string p_key, std::vector<std::string> p_list) { 
	it = m_list.find(p_key);
	//if key exists, erase contents to overwrite it
	if(it != m_list.end())
		m_list.erase(it);

	//add key with new list
	m_list.insert(m_list.end(), std::pair<std::string, std::vector<std::string> >(p_key, p_list));
}
//adds a new key / variable
void COMPy::addNew(std::string p_key) { 
	m_list[p_key] = data;
}
void COMPy::displayList(std::string p_key) {
	auto list_it = m_list.find(p_key);
	if (it != m_list.end()) {
		std::cout << "[ ";
		for (int i = 0; i < it->second.size(); i++)
			std::cout << (*list_it).second[i];
		std::cout << " ]";
	}
	else {
		std::cout << '\n';
	}
}
//Destroys all vector members and resets size to 0, reset varName
void COMPy::resetMember() { 
	varName = "";
	data.clear();
}
