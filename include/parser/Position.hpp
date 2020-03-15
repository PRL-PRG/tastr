#ifndef TASTR_PARSER_POSITION_HPP
#define TASTR_PARSER_POSITION_HPP

#include <iostream>
#include <string>

namespace tastr::parser {

/// A point in a source file.
class Position {
  public:
    /// Type for line and column numbers.
    typedef int counter_t;

    /// Construct a Position.
    explicit Position(std::string* f = nullptr,
                      counter_t l = 1,
                      counter_t c = 1)
        : filename(f), line(l), column(c) {
    }

    /// Initialization.
    void
    initialize(std::string* fn = nullptr, counter_t l = 1, counter_t c = 1) {
        filename = fn;
        line = l;
        column = c;
    }

    /** \name Line and Column related manipulators
     ** \{ */
    /// (line related) Advance to the COUNT next lines.
    void lines(counter_t count = 1) {
        if (count) {
            column = 1;
            line = add_(line, count, 1);
        }
    }

    /// (column related) Advance to the COUNT next columns.
    void columns(counter_t count = 1) {
        column = add_(column, count, 1);
    }
    /** \} */

    /// File name to which this Position refers.
    std::string* filename;
    /// Current line number.
    counter_t line;
    /// Current column number.
    counter_t column;

  private:
    /// Compute max (min, lhs+rhs).
    static counter_t add_(counter_t lhs, counter_t rhs, counter_t min) {
        return lhs + rhs < min ? min : lhs + rhs;
    }
};

/// Add \a width columns, in place.
inline Position& operator+=(Position& res, Position::counter_t width) {
    res.columns(width);
    return res;
}

/// Add \a width columns.
inline Position operator+(Position res, Position::counter_t width) {
    return res += width;
}

/// Subtract \a width columns, in place.
inline Position& operator-=(Position& res, Position::counter_t width) {
    return res += -width;
}

/// Subtract \a width columns.
inline Position operator-(Position res, Position::counter_t width) {
    return res -= width;
}

/// Compare two Position objects.
inline bool operator==(const Position& pos1, const Position& pos2) {
    return (
        pos1.line == pos2.line && pos1.column == pos2.column &&
        (pos1.filename == pos2.filename ||
         (pos1.filename && pos2.filename && *pos1.filename == *pos2.filename)));
}

/// Compare two Position objects.
inline bool operator!=(const Position& pos1, const Position& pos2) {
    return !(pos1 == pos2);
}

/** \brief Intercept output stream redirection.
 ** \param ostr the destination output stream
 ** \param pos a reference to the Position to redirect
 */
template <typename YYChar>
std::basic_ostream<YYChar>& operator<<(std::basic_ostream<YYChar>& ostr,
                                       const Position& pos) {
    if (pos.filename)
        ostr << *pos.filename << ':';
    return ostr << pos.line << '.' << pos.column;
}

} // namespace tastr::parser

#endif /* TASTR_PARSER_POSITION_HPP */
