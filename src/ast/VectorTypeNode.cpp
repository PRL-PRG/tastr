#include "ast/VectorTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::VectorTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
