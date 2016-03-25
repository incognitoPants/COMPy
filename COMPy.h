//#ifndef COMPYH_H
//#define COMPYH_H
#include <sstream>
#include <map>
#include <vector>
#include <string>
class COMPy {
public:
	COMPy();
	void capture(std::string p_input);
	void addToMember(std::string p_add);
	void editList(std::string p_key, std::vector<std::string> p_list);	
	void addNew(std::string p_key);
	void displayList(std::string p_key);
	void resetMember();
	std::map<std::string, std::vector<std::string> > m_list;
	std::map<std::string, std::vector<std::string> >::iterator it;
	std::map<std::string, std::string> m_list2; //
	std::vector<std::string> data;
private:
	std::string varName;
	std::string listmem;
};

//#endif
