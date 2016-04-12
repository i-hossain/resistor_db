#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <typeinfo>
using namespace std;

#define MIN_NODE_NUMBER 0
#define MAX_NODE_NUMBER 5000
#define MAX_INT_VALUE 2147483647
#define NUM_ARGS_INSERT 4
#define NUM_ARGS_MODIFY 2
#define NUM_ARGS_PRINT 1
#define NUM_ARGS_PRINTNODE 1
#define NUM_ARGS_DELETE 1
#define ALL "all"

#define TEST_FILE "test.txt"


bool check_command(string command) {
	if ((command != "insertR") && (command != "modifyR") && (command != "printR") && (command != "printNode") && (command != "deleteR"))
		return true;
	return false;
}

bool check_argument(string arg, string type) {
	int i;
	bool dot = false;

	if (arg.at(0) == '-')
		i = 1;
	else
		i = 0;

	if (type == "number/string") {
		for (; i < arg.length(); i++) {
			if (!dot && arg.at(i) == '.') {
				dot = true;
				continue;
			}
			if (!(arg.at(i) >= '0' && arg.at(i) <= '9'))
				return true;
		}
		return false;
	}
	else if (type == "int/double") {
		if (arg.find('.') <= MAX_INT_VALUE)
			return true;
		return false;
	}
}

bool check_resistance(int resistance) {
	if (resistance < 0)
		return true;
	return false;
}

bool check_node_value(int node) {
	if (node < MIN_NODE_NUMBER || node > MAX_NODE_NUMBER)
		return true;
	return false;
}

bool check_name(string name) {
	if (name == "all")
		return true;
	return false;
}

bool check_duplicate_node(int node1, int node2) {
	if (node1 == node2)
		return true;
	return false;
}



int main() {
	ifstream file(TEST_FILE);
	string line, command;
	string name, s_resistance, s_node1, s_node2, dummy;
	int node1, node2;
	// int args_count;
	double resistance;
	std::cout << std::fixed;

	// cout << "> ";
	//getline (cin, line); // Get a line from standard input
	while (getline (file, line)) {
		cout << "> ";
		cout << line << endl;
		stringstream lineStream (line);
		lineStream >> command;
		if (check_command(command))// First Error Check
			cout << "Error: invalid command" << endl; 
		else
		{
			// reset_args_count(&args_count);
			if (command == "insertR") {
			// parse an insertR command

				if (!(lineStream >> name)) {// Eighth Error Check - Too few args
					cout << "Too few arguments" << endl;
					continue;
				}

				if (!(lineStream >> s_resistance)) {// Eighth Error Check - Too few args
					cout << "Too few arguments" << endl;
					continue;
				}

				if (check_argument(s_resistance, "number/string")) {// Second Error Check
					cout << "Error: invalid argument" << endl; 
					continue;
				}
				stringstream convert_r(s_resistance);
				convert_r >> resistance;

				if (!(lineStream >> s_node1)) {// Eighth Error Check - Too few args
					cout << "Too few arguments" << endl;
					continue;
				}

				if (check_argument(s_node1, "number/string")) {// Second Error Check - number/string
					cout << "Error: invalid argument" << endl; 
					continue;
				}
				else if (check_argument(s_node1, "int/double")) {// Second Error Check - int/double 
					cout << "Error: invalid argument" << endl; 
					continue;
				}
				stringstream convert_n1(s_node1);
				convert_n1 >> node1;

				if (!(lineStream >> s_node2)) {// Eighth Error Check - Too few args
					cout << "Too few arguments" << endl;
					continue;
				}

				if (check_argument(s_node2, "number/string")) {// Second Error Check - number/string
					cout << "Error: invalid argument" <<  endl; 
					continue;
				}
				else {
					if (check_argument(s_node2, "int/double")) {// Second Error Check - int/double
						cout << "Error: invalid argument" << endl; 
						continue;
					}
				}
				stringstream convert_n2(s_node2);
				convert_n2 >> node2;

				if (check_resistance(resistance)) {// Third Error Check
					cout << "Error: negative reistance" << endl; 
					continue;
				}

				if (check_node_value(node1)) {// Fourth Error Check
					cout << "Error: node " << node1 << " is out of permitted range " << MIN_NODE_NUMBER << "-" << MAX_NODE_NUMBER << endl;
					continue;
				}

				if (check_node_value(node2)) {// Fourth Error Check
					cout << "Error: node " << node2 << " is out of permitted range " << MIN_NODE_NUMBER << "-" << MAX_NODE_NUMBER << endl;
					continue;
				}

				if (check_name(name)) {// Fifth Error Check - name = "all"
					cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
					continue;
				}

				if (check_duplicate_node(node1, node2)) {// Sixth Error Check - duplicate nodes
					cout << "Error: both terminals of resistor connect to node " << node1 << endl;
					continue;
				}

				if (lineStream >> dummy){// Seventh Error Check - Too many args
					cout << "Too many arguments" << endl;
					continue;
				}

				//Correct Output
				cout << "Inserted: " << name << " " << std::setprecision(2) << resistance << " Ohms " << node1 << " -> " << node2 << endl;
			}
			else if ( command == "modifyR" ) {
			// parse a modifyR command

				if (!(lineStream >> name)) {// Eighth Error Check - Too few args
					cout << "Too few arguments" << endl;
					continue;
				}
				
				if (!(lineStream >> s_resistance)) {// Eighth Error Check - Too few args
					cout << "Too few arguments" << endl;
					continue;
				}

				if (check_argument(s_resistance, "number/string")) {// Second Error Check
					cout << "Error: invalid argument" << endl; 
					continue;
				}
				stringstream convert_r(s_resistance);
				convert_r >> resistance;

				if (check_resistance(resistance)) {// Third Error Check
					cout << "Error: negative reistance" << endl; 
					continue;
				}

				if (check_name(name)) {// Fifth Error Check - name = "all"
					cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
					continue;
				}

				if (lineStream >> dummy) {// Seventh Error Check - Too many args
					cout << "Too many arguments" << endl;
					continue;
				}

				//Correct Output
				cout << "Modified: resistor " << name << " to " << std::setprecision(2) << resistance << " Ohms" << endl;
			}
			else if ( command == "printR" ) {
			// parse a printR command
				if (!(lineStream >> name)) {// Eighth Error Check - Too few args
					cout << "Too few arguments" << endl;
					continue;
				}

				if (lineStream >> dummy) {// Seventh Error Check - Too many args
					cout << "Too many arguments" << endl;
					continue;
				}

				if (name == ALL)
					cout << "Print: all resistors" << endl;
				else
					cout << "Print: resistor " << name << endl;
			}
			else if ( command == "printNode" ) {
			// parse a printNode command
				if (!(lineStream >> name)) {// Eighth Error Check - Too few args
					cout << "Too few arguments" << endl;
					continue;
				}

				if (name == ALL) {
					cout << "Print: all nodes" << endl;
					continue;
				}
				else {
					if (check_argument(name, "number/string")) {// Second Error Check - number/string
					cout << "Error: invalid argument" << endl; 
					continue;
					}
					else if (check_argument(name, "int/double")) {// Second Error Check - int/double 
						cout << "Error: invalid argument" << endl; 
						continue;
					}
					stringstream convert_n1(name);
					convert_n1 >> node1;

					if (check_node_value(node1)) {// Fourth Error Check
						cout << "Error: node " << node1 << " is out of permitted range " << MIN_NODE_NUMBER << "-" << MAX_NODE_NUMBER << endl;
						continue;
					}

					if (lineStream >> dummy) {// Seventh Error Check - Too many args
					cout << "Too many arguments" << endl;
					continue;
					}

					cout << "Print: node " << node1 << endl;
				}
			}
			else if ( command == "deleteR" ) {
			// parse a deleteR command
				if (!(lineStream >> name)) {// Eighth Error Check - Too few args
					cout << "Too few arguments" << endl;
					continue;
				}

				if (lineStream >> dummy) {// Seventh Error Check - Too many args
					cout << "Too many arguments" << endl;
					continue;
				}

				if (name == ALL)
					cout << "Deleted: all resistors" << endl;
				else
					cout << "Deleted: resistor " << name << endl;
			}
		}
		// cout << "> ";
		//getline (cin, line); // Get a line from standard input
	} // End input loop until EOF.
	return 0;
}

