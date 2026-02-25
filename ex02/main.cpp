/* *************************************************************************************************************** */
/*   main.cpp                                                                                                      */
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

#include "includes.h"

static Base *   generate ( void )
{
	int base = std::rand() % 3;

	Base *  ret;

	switch (base) {
		case 0: 
			ret = new A;
			std::cout << CYAN << "generate : Generating an A class\n";
			return (ret);
		case 1:
			ret = new B;
			std::cout << CYAN << "generate : Generating an B class\n";
			return (ret);
		default:
			ret = new C;
			std::cout << CYAN << "generate : Generating an C class\n";
			return (ret);
	}
}

static void identify ( Base * p )
{
	if (dynamic_cast<A *>(p)) {
		std::cout << WHITE << "identify (pointer) : A class detected !" << RESET << std::endl;
	}
	else if (dynamic_cast<B *>(p)) {
		std::cout << WHITE << "identify (pointer) : B class detected !" << RESET << std::endl;
	}
	else if (dynamic_cast<C *>(p)) {
		std::cout << WHITE << "identify (pointer) : C class detected !" << RESET << std::endl;
	}
}

static void identify ( Base & p )
{
	try {
		dynamic_cast<A&>(p);
		(void)p;
		std::cout << WHITE << "identify (reference) : A class detected !" << RESET << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try {
		dynamic_cast<B&>(p);
		(void)p;
		std::cout << WHITE << "identify (reference) : B class detected !" << RESET << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try {
		dynamic_cast<C&>(p);
		(void)p;
		std::cout << WHITE << "identify (reference) : C class detected !" << RESET << std::endl;
		return ;
	}
	catch (std::exception &e) {}
}

int main ( void )
{
	std::srand(time(NULL));

	Base *  base1 = generate();
	identify(base1);

	Base *  base2 = generate();
	identify(base2);
	
	Base *  base3 = generate();
	identify(*base3);

	Base *  base4 = generate();
	identify(*base4);
}