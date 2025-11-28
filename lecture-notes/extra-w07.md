MIT License
Copyright (c) 2025 Emir Baha Yıldırım
Please see the LICENSE file for more details.

-------------------------------------------------------------------------------

# Types of Balance in Trees

A balanced tree strictly maintains a rule to limit the maximum difference in
height between the left and right subtrees of *every* node. This difference is
often called the **balance factor**. Our goal is to keep the height
proportional to $`\log{n}`$

## Perfectly Balanced

The difference in height between the left and right subtrees of *any* node is
**zero**.

## Strictly Balanced (AVL)

The height difference is limited to a maximum of **one**, i.e., balance factor
is $`-1`$, $`0`$, or $`1`$.

When an insertion or deletion operation threatens to violate this balance rule,
the tree performs a corrective measure, usually a set of simple operations
called **rotations**, to re-balance itself.
