/* *************************************************************************************************************** */
/*   Serializer.hpp                                                                                                */
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

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include <cstring>

# define RED	"\e[1;91m"
# define GREEN	"\e[1;92m"
# define YELLOW	"\e[1;93m"
# define PURPLE	"\e[1;95m"
# define CYAN	"\e[1;96m"
# define WHITE	"\e[1;97m"
# define RESET	"\e[0m"

struct Data
{
	int					Grade_;
	const int 			Id_;
	const std::string	Name_;

	Data	( int Grade, int Id, std::string Name );
};


class Serializer
{

public:

	static uintptr_t	serialize ( Data * data );
	static Data *		deserialize ( uintptr_t raw );


private:

	Serializer ( void );
	Serializer ( Serializer const & src );
	~Serializer ( void );

	Serializer & operator= ( Serializer const & src );
};


std::ostream &	operator<< ( std::ostream & out, Data & src );

#endif 