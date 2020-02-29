#include "ast/node/TaggedType.h"
#include "ast/visitor/Visitor.h"

void tastr::ast::node::TaggedType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
