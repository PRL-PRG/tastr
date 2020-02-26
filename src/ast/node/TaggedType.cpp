#include "ast/node/TaggedType.h"
#include "ast/visitor/Visitor.h"

void rtype::ast::node::TaggedType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
