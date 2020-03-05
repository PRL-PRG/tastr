#include "ast/ListTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::ListTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::ListTypeNode::accept(tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
