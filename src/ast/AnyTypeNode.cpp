#include "ast/AnyTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::AnyTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::AnyTypeNode::accept(tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
