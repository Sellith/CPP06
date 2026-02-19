/* *************************************************************************************************************** */
/*   ScalarConverter.cpp                                                                                           */
/*   By: lvan-bre                                                                   .,                             */
/*                                                                                 okxl                            */
/*                                                                                xkddo                            */
/*                                                                               kkxddo                            */
/*                                                                              lxxddol                            */
/*                                                                              xxdolol.                           */
/*                                                                             :kxdddddl                 .ox,      */
/*                                                                       ..,cdkOOkkkxdddd'      ;o.     ckkd,      */
/*                                                               .,:coxOOOkkkkkkkxxxxxddddo:...lxdl.   ckkxd.      */
/*                                                           ;oxOOOOkkxxkxxxxxxxxxxdddddodddxxxkkxxxdlckkxdd.      */
/*                                                        ,oOOOkkkkxxxdddxdddddddddddddoooooodooddddooooddooc      */
/*                                                      ;kkkkkxxxxxddoooooooooooooooooooooooooollooooooololll      */
/*                                                     oxodddddoooooolllllllolooooollloooollllolllllloooolccl;     */
/*                                                    'x:::cclccllllccccccccccclllclllllllllllllllll     .;;cl;    */
/*                                                    d;c::cc:cc:::;::c:c:cccccclccc:cccclllllll,         .:cl.    */
/*                                                      c;,;:;;::::;;::::c..,cccllcc:c;;:lloodk.                   */
/*                                                        'ooooooooodddxxkkkOOOkOOOOOOc:cclllloo'                  */
/*                                                           .XXXXXXXKKXXXXXXXXXXXXXXXkcccclcccllo                 */
/*                                                                 ,KKKKKXXXXXXXXXXXXK0.  .:ccllclll;.             */
/*                                                                                           .ccccccllc,.          */
/*                                                                                                 :::cl:          */
/*                                                                                                                 */
/* *************************************************************************************************************** */

#include "include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {}
ScalarConverter::ScalarConverter( ScalarConverter const & src ) {static_cast<void>(src);}
ScalarConverter::~ScalarConverter( void ) {}

static void convertFromChar ( std::string const src ) 
{
	int		ires = static_cast<int>(src.at(0));

	std::cout << "Char : " << src << "\n";
	std::cout << "Int : " << ires << "\n";
	std::cout << "Float : " << static_cast<float>(ires) << ".0f\n";
	std::cout << "Double : " << static_cast<double>(ires) << ".0" << std::endl;
}

static void convertFromInt( std::string const src ) 
{
	int		ires = static_cast<int>(src.at(0));

	std::cout << "Char : " << static_cast<char>(ires) << "\n";
	std::cout << "Int : " << ires << "\n";
	std::cout << "Float : " << static_cast<float>(ires) << ".0f\n";
	std::cout << "Double : " << static_cast<double>(ires) << ".0" << std::endl;
}

static void convertFromFD( std::string const src, bool exception ) 
{
	float	fres = strtof(src.c_str(), NULL);
	double	dres = strtod(src.c_str(), NULL);
	int		ires = static_cast<int>(fres);

	if (exception) {
		std::cout << "Char : conversion impossible"  << "\n";
		std::cout << "Int : conversion impossible" << "\n";
		std::cout << "Float : " << fres << "f\n";
		std::cout << "Double : " << dres << std::endl;
		return ;
	}

	if (ires > 176 || ires < ' ')
		std::cout << "Char : Non displayable\n";
	else
		std::cout << "Char : " << static_cast<char>(ires) << "\n";

	std::cout << "Int : " << ires << "\n";

	if (static_cast<double>(ires) == dres) {
		std::cout << "Float : " << fres << ".0f\n";
		std::cout << "Double : " << dres << ".0" << std::endl;
	}
	else {
		std::cout << "Float : " << fres << "f\n";
		std::cout << "Double : " << dres << std::endl;
	}

}


static bool checkArgs( std::string src ) 
{
	std::string::iterator	it = src.begin();

	if (*it != '-' && *it != '+' && !isdigit(*it++))
		return (false);

	while (it != src.end()) {
		if (*it == '.'){
			it++;
			if (!isdigit(*it))
				return (false);
		}
		if (*it == 'f'){
			it++;
			if (it != src.end())
				return (false);
			else
				return (true);
		}
		if (!isdigit(*it++))
			return (false);
	}
	return (true);
}

void ScalarConverter::convert ( std::string const src ) 
{

	std::string	type[6] = { "-inf", "+inf", "nan", "-inff", "+inff", "nanf"};
	bool		exception = false;

	for (int i = 0; i < 6; i++)
		if (src == type[i]) {
			exception = true;
			break ;
		}

	if (src.length() > 1 && !exception && !checkArgs(src)){
		std::cout << "incorrect input" << std::endl;
		return ;
	}

	if (!std::isdigit(src.at(0)))
	{
		if (src.length() == 1) {
			convertFromChar(src);
			return ;
		}
	}

	if (src.find(".") || exception)
		convertFromFD(src, exception);
	else
		convertFromInt(src);
}
