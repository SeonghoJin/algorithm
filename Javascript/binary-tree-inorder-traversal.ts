// @ts-ignore

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */
function inorderTraversal(root: TreeNode | null): number[] {
  const ret = [];

  const traverse = (node: TreeNode) => {
    if (node?.left) {
      traverse(node?.left);
    }
    if (node?.val !== null && node?.val !== undefined) {
      ret.push(node?.val);
    }
    if (node?.right) {
      traverse(node?.right);
    }
  };

  traverse(root);

  return ret;
}
