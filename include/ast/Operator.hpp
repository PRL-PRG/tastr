#ifndef TASTR_AST_OPERATOR_HPP
#define TASTR_AST_OPERATOR_HPP

#include <string>

namespace tastr::ast {

class Operator {
  public:
    explicit Operator(const std::string& value): value_(value) {
    }

    ~Operator() = default;

    Operator(const Operator& op): value_(op.value_) {
    }

    Operator(Operator&& op): value_(std::move(op.value_)) {
    }

    Operator& operator=(const Operator& op) {
        if (&op == this) {
            return *this;
        }
        value_ = op.value_;
        return *this;
    }

    Operator& operator=(Operator&& op) {
        value_ = std::move(op.value_);
        return *this;
    }

    const std::string& get_value() const {
        return value_;
    }

    std::string value_;
};

} // namespace tastr::ast

#endif /* TASTR_AST_OPERATOR_HPP */
