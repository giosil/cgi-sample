/**********************************************************************************************
 *  Author: Noel V Aguilar
 *  Version: 1.4
 *  Filename: html-lib.c
 *
 *  This C HTML library will facilitate the creation of CGI scripts using
 *  C.  In order to access the functions contained within this library
 *  please include the "html-lib.h" file in your source. This file will only assist in
 *  is using html references and will not do any data manipulation.
***********************************************************************************************/

#include "html-lib.h"

/*----------------------------------------------------------------------------------------*/


/*
	mime_header() -	This function will take any text passed to it and it will diplay it as
					the mime type.
*/
void __cdecl mime_header(char *mime)
{
	printf("Content-type: %s\n\n", mime);
}


/*----------------------------------------------------------------------------------------*/


/*
	html_begin() -	This function will diplay the top of the head of the html page all the
					way upto the body tag.  The title and body attributes may be passed, if
					for any of these fields are not desired, then pass NULL.
*/
void __cdecl html_begin(char *title, char *attributes)
{
	puts("<html>");
	puts("<head>");
	(title == NULL) ? puts("<title></title>") : printf("<title>%s</title>\n", title);
	puts("</head>");
	(attributes == NULL) ? puts("<body>") : printf("<body %s>\n", attributes);
}


/*----------------------------------------------------------------------------------------*/


/*
	h1() -	This function will diplay whatever text is given between the tags.
*/
void __cdecl h1(char *str)
{
	printf("<h1>%s</h1>\n", str);
}


/*----------------------------------------------------------------------------------------*/


/*
	h2() -	This function will diplay whatever text is given between the tags.
*/
void __cdecl h2(char *str)
{
	printf("<h2>%s</h2>\n", str);
}


/*----------------------------------------------------------------------------------------*/


/*
	h3() -	This function will diplay whatever text is given between the tags.
*/
void __cdecl h3(char *str)
{
	printf("<h3>%s</h3>\n", str);
}


/*----------------------------------------------------------------------------------------*/


/*
	h4() -	This function will diplay whatever text is given between the tags.
*/
void __cdecl h4(char *str)
{
	printf("<h4>%s</h4>\n", str);
}


/*----------------------------------------------------------------------------------------*/


/*
	h5() -	This function will diplay whatever text is given between the tags.
*/
void __cdecl h5(char *str)
{
	printf("<h5>%s</h5>\n", str);
}


/*----------------------------------------------------------------------------------------*/


/*
	h6() -	This function will diplay whatever text is given between the tags.
*/
void __cdecl h6(char *str)
{
	printf("<h6>%s</h6>\n", str);
}


/*----------------------------------------------------------------------------------------*/


/*
	hidden() -	This function will print out hidden fields to the html page.  The Name and
				value of the hidden field must be passed.
*/
void __cdecl hidden(char *name, char *value)
{
	printf("<input type=\"hidden\" name=\"%s\" value=\"%s\">\n", name, value);
}


/*----------------------------------------------------------------------------------------*/


/*
	html_end() -	This function will do nothing more than to just give the ending tags
					of the html page.
*/
void __cdecl html_end(void)
{
	puts("</body>");
	puts("</html>");
}


/*----------------------------------------------------------------------------------------*/


/*
	location() -	This function will redirect a browser to another URL.
*/
void __cdecl location(char *loc)
{
	printf("Location: %s\n\n", loc);
}
