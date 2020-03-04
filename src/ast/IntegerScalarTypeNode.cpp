#include "ast/IntegerScalarTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::IntegerScalarTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
