#include "ast/TaggedType.h"
#include "visitor/Visitor.h"

void tastr::ast::TaggedType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
