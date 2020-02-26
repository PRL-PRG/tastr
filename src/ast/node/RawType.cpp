#include "ast/node/RawType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::RawType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
