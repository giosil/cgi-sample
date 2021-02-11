#include <iostream>
#include <string>

#include "cgi-lib.h"

using namespace std;

void sendResult(string title, string text);
void sendMessage(string title, string text);

int main(int args, char* argv)
{
	char *name;
	LIST* params;

	params = cgi_input_parse();

	cout << "Content-type: text/html\n\n";

	if (!params)
	{
		sendMessage("Hello", "cgi-sample running. Append ?name=XXX parameter.");
		return 0;
	}

	name = find_val(params, (char*) "name");

	if (!name)
	{
		sendMessage("Error", "Invalid name parameter.");
		return 0;
	}

	sendResult("Hello", name);

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
	cout << "<p>Hello " + text + ".</p>" << endl;
	cout << "</body>" << endl;
	cout << "</html>" << endl;
}

void sendMessage(string title, string text)
{
	cout << "<html>" << endl;
	cout << "<head>" << endl;
	cout << "<title>" + title + "</title>" << endl;
	cout << "</head>" << endl;
	cout << "<body style=\"background-color: #ffffdd\">" << endl;
	cout << "<h2>" + title + "</h2>" << endl;
	cout << "<p> " + text + "</p>" << endl;
	cout << "</body>" << endl;
	cout << "</html>" << endl;
}
