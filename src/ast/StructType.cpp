#include "ast/StructType.h"

#include "visitor/Visitor.h"

void tastr::ast::StructType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
