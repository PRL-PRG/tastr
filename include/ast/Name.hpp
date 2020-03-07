#ifndef TASTR_AST_NAME_HPP
#define TASTR_AST_NAME_HPP

#include <memory>
#include <string>

namespace tastr::ast {

class Name {
  public:
    explicit Name(const std::string& name): name_(name) {
    }

    ~Name() = default;

    Name(const Name& name): name_(name.name_) {
    }

    Name(Name&& name): name_(std::move(name.name_)) {
    }

    Name& operator=(const Name& name) {
        if (&name == this) {
            return *this;
        }
        name_ = name.name_;
        return *this;
    }

    Name& operator=(Name&& name) {
        name_ = std::move(name.name_);
        return *this;
    }

    std::unique_ptr<Name> clone() const {
        return std::unique_ptr<Name>(this->clone_impl());
    }

    const std::string& get_name() const {
        return name_;
    }

  private:
    virtual Name* clone_impl() const {
        return new Name(*this);
    }

    std::string name_;
};

using NamePtr = Name*;
using NameUPtr = std::unique_ptr<Name>;

} // namespace tastr::ast

#endif /* TASTR_AST_NAME_HPP */
