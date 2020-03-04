#include "ast/FunctionTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::FunctionTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
