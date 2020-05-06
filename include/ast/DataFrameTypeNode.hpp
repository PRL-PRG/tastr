#ifndef TASTR_AST_DATA_FRAME_TYPE_NODE_HPP
#define TASTR_AST_DATA_FRAME_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr {
namespace ast {

class DataFrameTypeNode final: public TypeNode {
  public:
    explicit DataFrameTypeNode(KeywordNodeUPtr keyword)
        : TypeNode(), keyword_(std::move(keyword)) {
    }

    ~DataFrameTypeNode() = default;

    DataFrameTypeNode(const DataFrameTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_->clone()) {
    }

    DataFrameTypeNode(DataFrameTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    DataFrameTypeNode& operator=(const DataFrameTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        return *this;
    }

    DataFrameTypeNode& operator=(DataFrameTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<DataFrameTypeNode> clone() const {
        return std::unique_ptr<DataFrameTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

  private:
    virtual DataFrameTypeNode* clone_impl() const override final {
        return new DataFrameTypeNode(*this);
    };

    KeywordNodeUPtr keyword_;

    static const Kind kind_;
};

using DataFrameTypeNodePtr = DataFrameTypeNode*;
using DataFrameTypeNodeUPtr = std::unique_ptr<DataFrameTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_DATA_FRAME_TYPE_NODE_HPP */
