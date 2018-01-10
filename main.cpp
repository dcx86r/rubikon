#include <iostream>
#include <random>
#include <string>

using namespace std;

int main() {
	random_device rd;
	uint_fast32_t seed = rd();
	typedef linear_congruential_engine<uint_fast32_t, 134775813, 1, 4294967296> lce;
	lce rng{seed};
	discrete_distribution<short> color {2,6,6,6,4,2};
	char ph[] = {'+', '@', '#', '$', '%', '&'};	//blue, yellow, green, orange, red, white
	vector<string> str;
	short i, j, k, l;

	for (i = 0; i < 9; ++i) {
		str.push_back(string(3, ph[color(rng)]));
	}

	cout << "/* XPM */\n"
	"static char * rubik_xpm[] = {\n"
	"\"15 15 8 1\",\n"
	"\" 	c None\",\n"
	"\".	c #000000\",\n"
	"\"+	c #0000FF\",\n"
	"\"@	c #FFFF00\",\n"
	"\"#	c #008000\",\n"
	"\"$	c #FFA500\",\n"
	"\"%	c #FF0000\",\n"
	"\"&	c #FFFFFF\",\n"
	"\"               \",\n";

	l = 0;

	for (j = 0; j < 3; ++j) {
		cout << "\" ............. \",\n";
		for (k = 0; k < 3; ++k) {
			cout << "\" ." << str[l] << "."
			<< str[l+1] << "."
			<< str[l+2] << ". \",\n";
		}
		l += 3;
	}
	cout << "\" ............. \",\n"
	"\"               \"};" << endl;

	return 0;
};
