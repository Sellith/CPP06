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

#include "Serializer.hpp"

int main ( void ) 
{
	Data *		data = new Data(1, 180712, "the boss");

	uintptr_t	rawPtr = Serializer::serialize(data);
	Data *		data2 = Serializer::deserialize(rawPtr);

	std::cout << CYAN << "Data :\n" << WHITE << *data << "\n";
	std::cout << CYAN << "Raw :\n" << WHITE << rawPtr << "\n";
	std::cout << CYAN << "Data Deserialized :\n" << WHITE << *data2 << RESET << std::endl;
	
	Data *		data3 = new Data(0, 0, "wfpwfbtdv.xc");
	
	uintptr_t	rawPtr2 = Serializer::serialize(data3);
	Data *		data4 = Serializer::deserialize(rawPtr2);
	
	std::cout << CYAN << "Data :\n" << WHITE << *data3 << "\n";
	std::cout << CYAN << "Raw :\n" << WHITE << rawPtr2 << "\n";
	std::cout << CYAN << "Data Deserialized :\n" << WHITE << *data4 << RESET << std::endl;
	
	delete data;
	delete data3;
}