#ifndef TASTR_AST_NODE_H
#define TASTR_AST_NODE_H

#include <memory>

namespace tastr::visitor {
class Visitor;
}

namespace tastr::ast {

class Node {
  public:
    Node() {
    }

    virtual ~Node() {
    }

    virtual void accept(tastr::visitor::Visitor& visitor) const = 0;
};

using NodePtr = Node*;
using NodeUPtr = std::unique_ptr<Node>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_H */
