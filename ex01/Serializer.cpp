/* *************************************************************************************************************** */
/*   Serializer.cpp                                                                                                */
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

Data::Data ( int Grade, int Id, std::string Name ) :
	Grade_(Grade), Id_(Id), Name_(Name) {}

Serializer::Serializer ( void ) {}
Serializer::Serializer ( Serializer const & src ) {(void)src;}
Serializer::~Serializer ( void ) {}

Serializer & Serializer::operator= ( Serializer const & src ) {
	(void)src;
	return (*this);
}

uintptr_t	Serializer::serialize ( Data * data ) {
	return (reinterpret_cast<uintptr_t>(data));
}

Data *	Serializer::deserialize ( uintptr_t raw ) {
	return (reinterpret_cast<Data *>(raw));
}


std::ostream &	operator<< ( std::ostream & out, Data & src )
{
	out << "Name : " << src.Name_ << "\nId : " << src.Id_ << "\nGrade : " << src.Grade_;
	return (out);
}