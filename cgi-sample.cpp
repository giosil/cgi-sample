#include <iostream>
#include <string>

#include "cgi-lib.h"

using namespace std;

void sendResult(string title, string text);
string hello(string name);

int main(int argc, char* argv[])
{
	char *name;
	LIST* params;

	params = cgi_input_parse();

	cout << "Content-type: text/html\n\n";

	if (!params)
	{
		sendResult("Hello", "cgi-sample running. Append ?name=XXX parameter.");
		list_clear(params);
		return 0;
	}

	name = find_val(params, (char*) "name");

	if (!name)
	{
		sendResult("Error", "Unspecified name parameter.");
		list_clear(params);
		return 0;
	}

	sendResult("Hello", hello(name));

	list_clear(params);

	return 0;
}

void sendResult(string title, string text)
{
	cout << "<html>" << endl;
	cout << "<head>" << endl;
	cout << "<title>" + title + "</title>" << endl;
	cout << "</head>" << endl;
	cout << "<body>" << endl;
	cout << "<h2>" + title + "</h2>" << endl;
	cout << "<p>" + text + "</p>" << endl;
	cout << "</body>" << endl;
	cout << "</html>" << endl;
}

string hello(string name)
{
	return "Hello " + name + ".";
}
