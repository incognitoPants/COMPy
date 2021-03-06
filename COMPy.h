//#ifndef COMPYH_H
//#define COMPYH_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

class COMPy {
public:
	COMPy();
	void capture(std::string p_input);
	void addSimpleVar(std::string p_input);
	void addListVar(std::string p_input);
	void dictionary(std::string p_input, std::string varName);
	void removeUnnecessarySpaces(std::string & str);
	void displayList();
	void eraseListKey();
	void resetMembers();
	std::string findVarName(std::string p_input);
	std::string COMPy::displayAnIndex(std::string p_input);
private:
	std::string varName = "";
	std::string listmem = "";
	std::vector<std::string> rvec;
	std::map<std::string, std::vector<std::string> > m_list; //for simple variables and lists
	std::map<std::string, std::map<std::string, std::string>> m_list2;
	std::map<std::string, std::vector<std::string> >::iterator list_it;
};


//#endif
