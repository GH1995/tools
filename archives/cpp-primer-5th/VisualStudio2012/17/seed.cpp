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

#include <cstddef>
using std::size_t;

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;

#include <iostream>
using std::cerr; using std::cout; using std::endl;

#include <vector>
using std::vector;

int main()
{
	default_random_engine e1;             // uses the default seed
	default_random_engine e2(2147483646); // use the given seed value

	// e3 and e4 will generate the same sequence 
	// because they use the same seed
	default_random_engine e3;        // uses the default seed value
	e3.seed(32767);                  // call seed to set a new seed value
	default_random_engine e4(32767); // set the seed value to 32767
	for (size_t i = 0; i != 100; ++i) {
		if (e1() == e2())
			cout << "unseeded match at iteration: " << i << endl;
		if (e3() != e4())
			cout << "seeded differs at iteration: " << i << endl;
	}

	return 0;
}
