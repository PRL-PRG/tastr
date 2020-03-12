#ifndef TASTR_AST_KEYWORD_HPP
#define TASTR_AST_KEYWORD_HPP

#include <string>

namespace tastr::ast {

class Keyword {
  public:
    explicit Keyword(const std::string& value): value_(value) {
    }

    ~Keyword() = default;

    Keyword(const Keyword& keyword): value_(keyword.value_) {
    }

    Keyword(Keyword&& keyword): value_(std::move(keyword.value_)) {
    }

    Keyword& operator=(const Keyword& keyword) {
        if (&keyword == this) {
            return *this;
        }
        value_ = keyword.value_;
        return *this;
    }

    Keyword& operator=(Keyword&& keyword) {
        value_ = std::move(keyword.value_);
        return *this;
    }

    const std::string& get_value() const {
        return value_;
    }

    std::string value_;
};

} // namespace tastr::ast

#endif /* TASTR_AST_KEYWORD_HPP */
