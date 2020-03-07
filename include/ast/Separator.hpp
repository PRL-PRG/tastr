#ifndef TASTR_AST_SEPARATOR_HPP
#define TASTR_AST_SEPARATOR_HPP

#include <memory>
#include <string>

namespace tastr::ast {

class Separator {
  public:
    explicit Separator(const std::string& separator): separator_(separator) {
    }

    ~Separator() = default;

    Separator(const Separator& separator): separator_(separator.separator_) {
    }

    Separator(Separator&& separator)
        : separator_(std::move(separator.separator_)) {
    }

    Separator& operator=(const Separator& separator) {
        if (&separator == this) {
            return *this;
        }
        separator_ = separator.separator_;
        return *this;
    }

    Separator& operator=(Separator&& separator) {
        separator_ = std::move(separator.separator_);
        return *this;
    }

    std::unique_ptr<Separator> clone() const {
        return std::unique_ptr<Separator>(this->clone_impl());
    }

    const std::string& get_separator() const {
        return separator_;
    }

  private:
    virtual Separator* clone_impl() const {
        return new Separator(*this);
    }

    std::string separator_;
};

using SeparatorPtr = Separator*;
using SeparatorUPtr = std::unique_ptr<Separator>;

} // namespace tastr::ast

#endif /* TASTR_AST_SEPARATOR_HPP */
