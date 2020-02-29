#ifndef TASTR_AST_NO_NA_TYPE_H
#define TASTR_AST_NO_NA_TYPE_H

#include "CompositeType.h"
#include "VectorType.h"

#include <memory>

namespace tastr::ast {

class NoNaType final: public CompositeType {
  public:
    NoNaType(std::unique_ptr<VectorType> inner_type)
        : CompositeType(), inner_type_(std::move(inner_type)) {
    }

    ~NoNaType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const tastr::ast::VectorType& get_inner_type() const {
        return *inner_type_.get();
    }

  private:
    std::unique_ptr<tastr::ast::VectorType> inner_type_;
};

using NoNaTypePtr = NoNaType*;
using NoNaTypeUPtr = std::unique_ptr<NoNaType>;

} // namespace tastr::ast

#endif /* TASTR_AST_NO_NA_TYPE_H */
