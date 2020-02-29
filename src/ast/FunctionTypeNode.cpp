#include "ast/FunctionTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::FunctionTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
