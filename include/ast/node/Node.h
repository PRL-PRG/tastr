#ifndef TASTR_AST_NODE_NODE_H
#define TASTR_AST_NODE_NODE_H

#include <memory>

namespace tastr::ast::visitor {
class Visitor;
}

namespace tastr::ast::node {

class Node {
  public:
    Node() {
    }

    virtual ~Node() {
    }

    virtual void accept(tastr::ast::visitor::Visitor& visitor) const = 0;
};

using NodePtr = Node*;
using NodeUPtr = std::unique_ptr<Node>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_TYPE_H */
