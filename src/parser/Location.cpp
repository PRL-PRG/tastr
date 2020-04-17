#include "parser/Location.hpp"

#include <sstream>

std::ostream& operator<<(std::ostream& os, const tastr::parser::Location& loc) {
    tastr::parser::Location::counter_t end_col =
        0 < loc.end.column ? loc.end.column - 1 : 0;
    os << loc.begin;
    if (loc.end.filename &&
        (!loc.begin.filename || *loc.begin.filename != *loc.end.filename))
        os << '-' << loc.end.filename << ':' << loc.end.line << '.' << end_col;
    else if (loc.begin.line < loc.end.line)
        os << '-' << loc.end.line << '.' << end_col;
    else if (loc.begin.column < end_col)
        os << '-' << end_col;
    return os;
}

std::string to_string(const tastr::parser::Location& loc) {
    std::ostringstream output_stream;
    output_stream << loc;
    return output_stream.str();
}
