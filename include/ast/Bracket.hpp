#ifndef TASTR_AST_BRACKETED_HPP
#define TASTR_AST_BRACKETED_HPP

#include "ast/OperatorNode.hpp"

#include <memory>

namespace tastr {
namespace ast {

class Bracketed {
  public:
    explicit Bracketed(OperatorNodeUPtr opening_bracket,
                       OperatorNodeUPtr closing_bracket)
        : opening_bracket_(std::move(opening_bracket))
        , closing_bracket_(std::move(closing_bracket)) {
    }

    ~Bracketed() = default;

    Bracketed(const Bracketed& bracketed)
        : opening_bracket_(bracketed.opening_bracket_->clone())
        , closing_bracket_(bracketed.closing_bracket_->clone()) {
    }

    Bracketed(Bracketed&& bracketed)
        : opening_bracket_(std::move(bracketed.opening_bracket_))
        , closing_bracket_(std::move(bracketed.closing_bracket_)) {
    }

    Bracketed& operator=(const Bracketed& bracketed) {
        if (&bracketed == this) {
            return *this;
        }
        opening_bracket_ = bracketed.opening_bracket_->clone();
        closing_bracket_ = bracketed.closing_bracket_->clone();
        return *this;
    }

    Bracketed& operator=(Bracketed&& bracketed) {
        opening_bracket_ = std::move(bracketed.opening_bracket_);
        closing_bracket_ = std::move(bracketed.closing_bracket_);
        return *this;
    }

    std::unique_ptr<Bracketed> clone() const {
        return std::unique_ptr<Bracketed>(this->clone_impl());
    }

    const OperatorNode& get_opening_bracket() const {
        return *opening_bracket_.get();
    }

    const OperatorNode& get_closing_bracket() const {
        return *closing_bracket_.get();
    }

  private:
    virtual Bracketed* clone_impl() const {
        return new Bracketed(*this);
    }

    OperatorNodeUPtr opening_bracket_;
    OperatorNodeUPtr closing_bracket_;
};

using BracketedPtr = Bracketed*;
using BracketedUPtr = std::unique_ptr<Bracketed>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_BRACKETED_HPP */
