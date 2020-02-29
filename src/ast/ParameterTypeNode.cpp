#include "ast/ParameterTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::ParameterTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
