#include "ast/VectorType.h"

#include "visitor/Visitor.h"

void tastr::ast::VectorType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
