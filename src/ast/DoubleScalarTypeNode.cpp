#include "ast/DoubleScalarTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::DoubleScalarTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
