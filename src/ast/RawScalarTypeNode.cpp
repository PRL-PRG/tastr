#include "ast/RawScalarTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::RawScalarTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
