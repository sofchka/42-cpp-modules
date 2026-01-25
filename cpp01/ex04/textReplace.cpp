#include "textReplace.hpp"

std::string textReplace(std::ifstream& infile, const std::string& s1, const std::string& s2)
{
    std::string out;
    std::string line;

    // if s1 is empty, find("") will ALWAYS succeed at the same place -> infinite loop.
    if (s1.empty())
        return out;

    // - Here we use streams + getline(infile, line)
    while (std::getline(infile, line))
    {
        size_t pos = 0;       // "Where we are" in the current line
        size_t found;         // Index where s1 is found in the line

        found = line.find(s1, pos); // found = index of first occurrence of s1 in line, starting from pos
        // While we still find s1 in the line
        while (found != std::string::npos)
        {
            out.append(line, pos, found - pos); // Append the part BEFORE s1, from pos to found (not including found)
            out += s2;
            pos = found + s1.length();
            found = line.find(s1, pos);
        }
        out.append(line, pos, line.length() - pos);
        out += '\n';
    }
    return out;
}