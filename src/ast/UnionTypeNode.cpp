#include "ast/UnionTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::UnionTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::UnionTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
