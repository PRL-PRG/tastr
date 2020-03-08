#ifndef TASTR_AST_BRACKETED_HPP
#define TASTR_AST_BRACKETED_HPP

#include <memory>
#include <string>

namespace tastr::ast {

class Bracketed {
  public:
    explicit Bracketed(const std::string& opening, const std::string& closing)
        : opening_(opening), closing_(closing) {
    }

    ~Bracketed() = default;

    Bracketed(const Bracketed& bracketed)
        : opening_(bracketed.opening_), closing_(bracketed.closing_) {
    }

    Bracketed(Bracketed&& bracketed)
        : opening_(std::move(bracketed.opening_))
        , closing_(std::move(bracketed.closing_)) {
    }

    Bracketed& operator=(const Bracketed& bracketed) {
        if (&bracketed == this) {
            return *this;
        }
        opening_ = bracketed.opening_;
        closing_ = bracketed.closing_;
        return *this;
    }

    Bracketed& operator=(Bracketed&& bracketed) {
        opening_ = std::move(bracketed.opening_);
        closing_ = std::move(bracketed.closing_);
        return *this;
    }

    std::unique_ptr<Bracketed> clone() const {
        return std::unique_ptr<Bracketed>(this->clone_impl());
    }

    const std::string& get_opening_bracket() const {
        return opening_;
    }

    const std::string& get_closing_bracket() const {
        return closing_;
    }

  private:
    virtual Bracketed* clone_impl() const {
        return new Bracketed(*this);
    }

    std::string opening_;
    std::string closing_;
};

using BracketedPtr = Bracketed*;
using BracketedUPtr = std::unique_ptr<Bracketed>;

} // namespace tastr::ast

#endif /* TASTR_AST_BRACKETED_HPP */
