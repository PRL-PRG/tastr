#include "ast/node/RawType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::RawType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
