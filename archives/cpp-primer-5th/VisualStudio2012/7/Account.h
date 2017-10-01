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

#include "Version_test.h"

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
#if defined(DEFAULT_FCNS) && defined(IN_CLASS_INITS)
	Account() = default;
#else
	Account(): amount(0.0) { }
#endif
	Account(const std::string &s, double amt):
		owner(s), amount(amt) { }

    void calculate() { amount += amount * interestRate; }
    double balance() { return amount; }
public:
    static double rate() { return interestRate; }
    static void rate(double);   
private:
    std::string owner; 
#ifdef IN_CLASS_INITS
    double amount = 0.0; 
#else
	double amount;
#endif
    static double interestRate; 
    static double initRate() { return .0225; }
    static const std::string accountType;
#ifdef CONSTEXPR_VARS
    static constexpr int period = 30;// period is a constant expression
#else
	static const int period = 30;// period is a constant expression
#endif
    double daily_tbl[period];
};
#endif
