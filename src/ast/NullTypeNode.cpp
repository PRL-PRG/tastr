#include "ast/NullTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::NullTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::NullTypeNode::accept(tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
