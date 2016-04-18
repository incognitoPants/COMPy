#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include "COMPy.h"
using namespace std;

COMPy::COMPy() {}
void COMPy::capture(std::string p_input) {
	//Check if simple variable or a list
	int finder = p_input.find('[');
	if (finder != string::npos) {
		int equal = p_input.find('=');
		if (equal != string::npos)
			addSimpleVar(p_input);
		else {
			list_it = m_list.find(p_input);
			if (list_it != m_list.end())
				displayList();
			else
				addSimpleVar(p_input);
		}
	}

	//For Simple Variable
	int equal = p_input.find('=');
	if (equal != string::npos)
		addSimpleVar(p_input);
	else {
		list_it = m_list.find(p_input);
		if (list_it != m_list.end())
			displayList();
		else
			addSimpleVar(p_input);
	}
}
void COMPy::addSimpleVar(string p_input) {
	int equal = p_input.find('=');
	if (equal != string::npos) { //if assignment operator is found
		varName = p_input.substr(0, equal);
		varName.erase(remove_if(varName.begin(), varName.end(), isspace), varName.end());
		listmem = p_input.substr(equal+1, string::npos);
		if (listmem.at(0) != '\"' && listmem.at(listmem.size()-1) != '\"') //remove extra spaces if not a string
			listmem.erase(remove_if(listmem.begin(), listmem.end(), isspace), listmem.end());

		//Check if varName exists in map already
		list_it = m_list.find(varName);
		if (list_it != m_list.end())
			eraseListKey();

		rvec.push_back(listmem);
		m_list.insert(pair<string, vector<string>>(varName, rvec));
	}
	//If no assignment operator assign key to empty vector in map
	else {
		varName = p_input;
		varName.erase(remove_if(varName.begin(), varName.end(), isspace), varName.end());
		m_list.insert(pair<string, vector<string>>(varName, rvec));
	}

	resetMembers();
}
void COMPy::addListVar(std::string p_input) {
	//find assignment operator
	int equal = p_input.find('=');
	if (equal != string::npos) { //if assignment operator is found
		varName = p_input.substr(0, equal);
		//Remove extra spaces in left side
		varName.erase(remove_if(varName.begin(), varName.end(), isspace), varName.end());
		//Capture right hand side
		string rside = p_input.substr((p_input.find('[') + 1), (p_input.find_last_of(']') - (p_input.find('[') + 1))); //find_last_of makes sure the end bracket location is captured

		for (int i = 0; i < rside.length(); i++) {  //capture list contents into a std::string
			if (rside.at(i) == '"') { //check if a std::string or not a space
				int endQ = rside.find('"', i + 1);
				listmem.append(rside, i, endQ);
				i = endQ;
			}
			else if (rside.at(i) != ' ' && rside.at(i) != ',') {
				listmem.append(rside, i, 1);
			}
			else if (rside.at(i) == ',') { //if comma found, store current list member to vector
				rvec.push_back(listmem);
				listmem = "";
			}
			//if .at(i) is the last character of string, add to to vector
			if (i + 1 == rside.length())
				rvec.push_back(listmem);
		}
		list_it = m_list.find(varName);
		if (list_it != m_list.end())
			m_list.erase(list_it);

		m_list.insert(pair<string, vector<string>>(varName, rvec));
	}
	else {
		varName = p_input;
		varName.erase(remove_if(varName.begin(), varName.end(), isspace), varName.end());
		m_list.insert(pair<string, vector<string>>(varName, rvec));
	}
	resetMembers();
}
void COMPy::displayList() {
	cout << list_it->first << " = ";

	//for simple variables
	if (list_it->second.size() == 1) {
	for (int i = 0; i < list_it->second.size(); i++)
		cout << list_it->second[i] << " ";
	cout << endl;
	}
	//for lists
	else {
		if (list_it != m_list.end()) {
			cout << "[ ";
			for (int i = 0; i < list_it->second.size(); i++)
				cout << list_it->second[i] << " ";
			cout << "]" << endl;
		}
	}
}
void COMPy::eraseListKey() {
	m_list.erase(list_it);
}
void COMPy::addListItem(string p_input) {}
void COMPy::resetMembers() {
	rvec.clear();
	varName = "";
	listmem = "";
}
