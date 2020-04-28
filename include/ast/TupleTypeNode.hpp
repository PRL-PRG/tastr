#ifndef TASTR_AST_TUPLE_TYPE_NODE_HPP
#define TASTR_AST_TUPLE_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/ParameterNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr {
namespace ast {

class TupleTypeNode final: public TypeNode {
  public:
    explicit TupleTypeNode(KeywordNodeUPtr keyword,
                           ParameterNodeUPtr parameters)
        : TypeNode()
        , keyword_(std::move(keyword))
        , parameters_(std::move(parameters)) {
    }

    ~TupleTypeNode() = default;

    TupleTypeNode(const TupleTypeNode& node)
        : TypeNode(node)
        , keyword_(node.keyword_->clone())
        , parameters_(node.parameters_->clone()) {
    }

    TupleTypeNode(TupleTypeNode&& node)
        : TypeNode(std::move(node))
        , keyword_(std::move(node.keyword_))
        , parameters_(std::move(node.parameters_)) {
    }

    TupleTypeNode& operator=(const TupleTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        parameters_ = node.parameters_->clone();
        return *this;
    }

    TupleTypeNode& operator=(TupleTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        parameters_ = std::move(node.parameters_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<TupleTypeNode> clone() const {
        return std::unique_ptr<TupleTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

    ParameterNode& get_parameters() const {
        return *parameters_.get();
    }

  private:
    virtual TupleTypeNode* clone_impl() const override final {
        return new TupleTypeNode(*this);
    };

    KeywordNodeUPtr keyword_;
    ParameterNodeUPtr parameters_;

    static const Kind kind_;
};

using TupleTypeNodePtr = TupleTypeNode*;
using TupleTypeNodeUPtr = std::unique_ptr<TupleTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_TUPLE_TYPE_NODE_HPP */
