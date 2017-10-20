/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/\r/\r/g 

#include <string>
using std::string;

#include <iostream>

namespace libs_R_us {
    extern void print(int) 
		{ std::cout << "libs_R_us::print(int)" << std::endl; }
    extern void print(double) 
		{ std::cout << "libs_R_us::print(double)" << std::endl; }
}

// ordinary declaration
void print(const std::string &)
{
	std::cout << "print(const std::string &)" << std::endl;
}

// this using directive adds names to the candidate set for calls to print:
using namespace libs_R_us;  

// the candidates for calls to print at this point in the program are:
//     print(int) from libs_R_us
//     print(double) from libs_R_us
//     print(const std::string &) declared explicitly

int main()
{
	int ival = 42;
    print("Value: "); // calls global print(const string &)
    print(ival);      // calls libs_R_us::print(int)

	return 0;
}
