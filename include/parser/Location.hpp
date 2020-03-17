#ifndef TASTR_PARSER_LOCATION_HPP
#define TASTR_PARSER_LOCATION_HPP

#include "parser/Position.hpp"

#include <iostream>
#include <string>

namespace tastr::parser {

/// Two points in a source file.
class Location {
  public:
    /// Type for line and column numbers.
    typedef Position::counter_t counter_t;

    /// Construct a Location from \a b to \a e.
    Location(const Position& b, const Position& e): begin(b), end(e) {
    }

    /// Construct a 0-width location in \a p.
    explicit Location(const Position& p = Position()): begin(p), end(p) {
    }

    /// Construct a 0-width location in \a f, \a l, \a c.
    explicit Location(std::string* f, counter_t l = 1, counter_t c = 1)
        : begin(f, l, c), end(f, l, c) {
    }

    /// Initialization.
    void
    initialize(std::string* f = nullptr, counter_t l = 1, counter_t c = 1) {
        begin.initialize(f, l, c);
        end = begin;
    }

    /** \name Line and Column related manipulators
     ** \{ */
  public:
    /// Reset initial location to final Location.
    void step() {
        begin = end;
    }

    /// Extend the current location to the COUNT next columns.
    void columns(counter_t count = 1) {
        end += count;
    }

    /// Extend the current location to the COUNT next lines.
    void lines(counter_t count = 1) {
        end.lines(count);
    }
    /** \} */

    void set_token_prefix(const std::string& token_prefix) {
        token_prefix_ = token_prefix;
    }

    const std::string& get_token_prefix() const {
        return token_prefix_;
    }

  public:
    /// Beginning of the located region.
    Position begin;
    /// End of the located region.
    Position end;

    std::string token_prefix_;
};

/// Join two locations, in place.
inline Location& operator+=(Location& res, const Location& end) {
    res.end = end.end;
    return res;
}

/// Join two locations.
inline Location operator+(Location res, const Location& end) {
    return res += end;
}

/// Add \a width columns to the end position, in place.
inline Location& operator+=(Location& res, Location::counter_t width) {
    res.columns(width);
    return res;
}

/// Add \a width columns to the end position.
inline Location operator+(Location res, Location::counter_t width) {
    return res += width;
}

/// Subtract \a width columns to the end position, in place.
inline Location& operator-=(Location& res, Location::counter_t width) {
    return res += -width;
}

/// Subtract \a width columns to the end position.
inline Location operator-(Location res, Location::counter_t width) {
    return res -= width;
}

/// Compare two location objects.
inline bool operator==(const Location& loc1, const Location& loc2) {
    return loc1.begin == loc2.begin && loc1.end == loc2.end;
}

/// Compare two location objects.
inline bool operator!=(const Location& loc1, const Location& loc2) {
    return !(loc1 == loc2);
}

/** \brief Intercept output stream redirection.
 ** \param ostr the destination output stream
 ** \param loc a reference to the Location to redirect
 **
 ** Avoid duplicate information.
 */
template <typename YYChar>
std::basic_ostream<YYChar>& operator<<(std::basic_ostream<YYChar>& ostr,
                                       const Location& loc) {
    Location::counter_t end_col = 0 < loc.end.column ? loc.end.column - 1 : 0;
    ostr << loc.begin;
    if (loc.end.filename &&
        (!loc.begin.filename || *loc.begin.filename != *loc.end.filename))
        ostr << '-' << loc.end.filename << ':' << loc.end.line << '.'
             << end_col;
    else if (loc.begin.line < loc.end.line)
        ostr << '-' << loc.end.line << '.' << end_col;
    else if (loc.begin.column < end_col)
        ostr << '-' << end_col;
    return ostr;
}

} // namespace tastr::parser

#endif /* TASTR_PARSER_LOCATION_HPP */
