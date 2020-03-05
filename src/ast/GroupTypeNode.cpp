#include "ast/GroupTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::GroupTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::GroupTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
