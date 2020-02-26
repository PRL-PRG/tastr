#include "ast/node/RawType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::RawType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
