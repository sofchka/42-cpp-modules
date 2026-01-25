#ifndef TEXTREPLACE_HPP
#define TEXTREPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

std::string textReplace(std::ifstream& infile, const std::string& s1, const std::string& s2);

#endif