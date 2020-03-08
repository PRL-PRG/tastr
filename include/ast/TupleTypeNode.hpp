#ifndef TASTR_AST_TUPLE_TYPE_NODE_HPP
#define TASTR_AST_TUPLE_TYPE_NODE_HPP

#include "ast/Bracket.hpp"
#include "ast/TypeNode.hpp"
#include "ast/TypeNodeSequenceNode.hpp"

namespace tastr::ast {

class TupleTypeNode final
    : public TypeNode
    , public Bracketed {
  public:
    explicit TupleTypeNode(const std::string& opening_bracket,
                           const std::string& closing_bracket,
                           TypeNodeSequenceNodeUPtr element_types)
        : TypeNode()
        , Bracketed(opening_bracket, closing_bracket)
        , element_types_(std::move(element_types)) {
    }

    ~TupleTypeNode() = default;

    TupleTypeNode(const TupleTypeNode& node)
        : TypeNode(node)
        , Bracketed(node)
        , element_types_(node.element_types_->clone()) {
    }

    TupleTypeNode(TupleTypeNode&& node)
        : TypeNode(std::move(node))
        , Bracketed(std::move(node))
        , element_types_(std::move(node.element_types_)) {
    }

    TupleTypeNode& operator=(const TupleTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Bracketed::operator=(node);
        element_types_ = node.element_types_->clone();
        return *this;
    }

    TupleTypeNode& operator=(TupleTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Bracketed::operator=(std::move(node));
        element_types_ = std::move(node.element_types_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<TupleTypeNode> clone() const {
        return std::unique_ptr<TupleTypeNode>(this->clone_impl());
    }

    bool is_tuple_type_node() const override final {
        return true;
    }

    TypeNodeSequenceNode& get_element_types() const {
        return *element_types_.get();
    }

  private:
    virtual TupleTypeNode* clone_impl() const override final {
        return new TupleTypeNode(*this);
    };

    TypeNodeSequenceNodeUPtr element_types_;
};

using TupleTypeNodePtr = TupleTypeNode*;
using TupleTypeNodeUPtr = std::unique_ptr<TupleTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TUPLE_TYPE_NODE_HPP */
